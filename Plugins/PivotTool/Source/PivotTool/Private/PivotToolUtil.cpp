// Copyright 2017-2019 marynate. All Rights Reserved.

#include "PivotToolUtil.h"
#include "PivotTool.h"

#include "LevelEditorActions.h"
#include "EditorModeManager.h"
#include "StaticMeshResources.h"
#include "Rendering/SkeletalMeshRenderData.h"
#include "RawMesh.h"
#include "EditorSupportDelegates.h"
#include "PhysicsEngine/AggregateGeom.h"
#include "PhysicsEngine/BodySetup.h"
#include "ObjectTools.h"
#include "Components/BrushComponent.h"
#include "Components/SkinnedMeshComponent.h"
#include "Engine/Polys.h"
#include "Engine/Selection.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/StaticMeshSocket.h"
#include "Engine/StaticMeshActor.h"
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"
#include "SkeletalMeshTypes.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "PivotToolUtil"

//////////////////////////////////////////////////////////////
namespace PivotTool
{
	class FVertexIterator
	{
	public:
		virtual ~FVertexIterator() {}

		void operator++() 
		{
			Advance();
		}

		operator bool()
		{
			return HasMoreVertices();
		}

		// Vertex position in world space
		virtual FVector Position() = 0;

		// Vertex position in local space
		virtual FVector LocalPosition() = 0;

	protected:
		virtual void Advance() = 0;
		virtual bool HasMoreVertices() = 0;
	};

	class FStaticMeshVertexIterator : public FVertexIterator
	{
	public:
		FStaticMeshVertexIterator(UStaticMeshComponent* SMC)
			: ComponentToWorldIT(SMC->GetComponentTransform().ToInverseMatrixWithScale().GetTransposed())
			, StaticMeshComponent(SMC)
			, PositionBuffer(SMC->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer)
			, CurrentVertexIndex(0)
		{}

		virtual FVector Position() override
		{
			return StaticMeshComponent->GetComponentTransform().TransformPosition(PositionBuffer.VertexPosition(CurrentVertexIndex));
		}

		virtual FVector LocalPosition() override
		{
			return PositionBuffer.VertexPosition(CurrentVertexIndex);
		}

	protected:
		virtual void Advance() override
		{
			++CurrentVertexIndex;
		}

		virtual bool HasMoreVertices() override
		{
			return CurrentVertexIndex < PositionBuffer.GetNumVertices();
		}
	private:
		FMatrix ComponentToWorldIT;
		UStaticMeshComponent* StaticMeshComponent;
		FPositionVertexBuffer& PositionBuffer;
		uint32 CurrentVertexIndex;
	};

	class FBrushVertexIterator : public FVertexIterator
	{
	public:
		FBrushVertexIterator(UBrushComponent* InBrushComponent)
			: BrushComponent(InBrushComponent)
			, CurrentVertexIndex(0)
		{
			UModel* Model = BrushComponent->Brush;
			for (int32 PolyIndex = 0; PolyIndex < Model->Polys->Element.Num(); ++PolyIndex)
			{
				FPoly& Poly = Model->Polys->Element[PolyIndex];
				for (int32 VertexIndex = 0; VertexIndex < Poly.Vertices.Num(); ++VertexIndex)
				{
					Vertices.Add(Poly.Vertices[VertexIndex]);
				}
			}
		}

		virtual FVector Position() override
		{
			return BrushComponent->GetComponentTransform().TransformPosition(Vertices[CurrentVertexIndex]);
		}

		virtual FVector LocalPosition() override
		{
			return Vertices[CurrentVertexIndex];
		}

	protected:
		virtual void Advance() override
		{
			++CurrentVertexIndex;
		}

		virtual bool HasMoreVertices() override
		{
			return Vertices.IsValidIndex(CurrentVertexIndex);
		}
	private:
		UBrushComponent* BrushComponent;
		TArray<FVector> Vertices;
		uint32 CurrentVertexIndex;
		uint32 NumVertices;
	};

	class FSkeletalMeshVertexIterator : public FVertexIterator
	{
	public:
		FSkeletalMeshVertexIterator(USkinnedMeshComponent* InSkinnedMeshComp)
			: ComponentToWorldIT(InSkinnedMeshComp->GetComponentTransform().ToInverseMatrixWithScale().GetTransposed())
			, SkinnedMeshComponent(InSkinnedMeshComp)
			, LODData(InSkinnedMeshComp->GetSkeletalMeshRenderData()->LODRenderData[0])
			, VertexIndex(0)
		{}

		virtual FVector Position() override
		{
			const FVector VertPos = LODData.StaticVertexBuffers.PositionVertexBuffer.VertexPosition(VertexIndex);
			return SkinnedMeshComponent->GetComponentTransform().TransformPosition(VertPos);
		}

		virtual FVector LocalPosition() override
		{
			const FVector VertPos = LODData.StaticVertexBuffers.PositionVertexBuffer.VertexPosition(VertexIndex);
			return VertPos;
		}

	protected:
		virtual void Advance() override
		{
			VertexIndex++;
		}

		virtual bool HasMoreVertices() override
		{
			return VertexIndex < LODData.StaticVertexBuffers.PositionVertexBuffer.GetNumVertices();
		}

	private:
		FMatrix ComponentToWorldIT;
		USkinnedMeshComponent* SkinnedMeshComponent;
		FSkeletalMeshLODRenderData& LODData;
		uint32 VertexIndex;
	};

	static TSharedPtr<FVertexIterator> MakeVertexIterator(UPrimitiveComponent* Component)
	{
		UStaticMeshComponent* SMC = Cast<UStaticMeshComponent>(Component);
		if (SMC && SMC->GetStaticMesh())
		{
			return MakeShareable(new FStaticMeshVertexIterator(SMC));
		}

		UBrushComponent* BrushComponent = Cast<UBrushComponent>(Component);
		if (BrushComponent && BrushComponent->Brush)
		{
			return MakeShareable(new FBrushVertexIterator(BrushComponent));
		}

		USkinnedMeshComponent* SkinnedComponent = Cast<USkinnedMeshComponent>(Component);
		if (SkinnedComponent && SkinnedComponent->SkeletalMesh && SkinnedComponent->MeshObject)
		{
			return MakeShareable(new FSkeletalMeshVertexIterator(SkinnedComponent));
		}

		return NULL;
	}

	static void GetValidPrimitiveComponents(AActor* InActor, TArray<UPrimitiveComponent*>& InComponents)
	{
		if (InActor)
		{
			TArray<UPrimitiveComponent*> PrimitiveComponents;
			InActor->GetComponents<UPrimitiveComponent>(PrimitiveComponents);

			for (UPrimitiveComponent* Component : PrimitiveComponents)
			{
				bool bValid = false;

				if (!bValid)
				{
					UStaticMeshComponent* SMC = Cast<UStaticMeshComponent>(Component);
					bValid = SMC 
						&& SMC->GetStaticMesh() 
						&& SMC->GetStaticMesh()->RenderData
						&& SMC->GetStaticMesh()->RenderData->LODResources[0].VertexBuffers.PositionVertexBuffer.GetNumVertices() > 0;
				}

				if (!bValid)
				{
					UBrushComponent* BC = Cast<UBrushComponent>(Component);
					bValid = BC 
						&& BC->Brush 
						&& BC->Brush->Polys
						&& BC->Brush->Polys->Element.Num() > 0;
				}

				if (!bValid)
				{
					USkinnedMeshComponent* SkinMC = Cast<USkinnedMeshComponent>(Component);
					bValid = SkinMC 
						&& SkinMC->GetSkeletalMeshRenderData()
						&& SkinMC->GetSkeletalMeshRenderData()->LODRenderData[0].StaticVertexBuffers.PositionVertexBuffer.GetNumVertices() > 0;
				}

				if (bValid)
				{
					InComponents.Add(Component);
				}
			}
		}
	}

	static bool GetComponentLocalBound(UPrimitiveComponent* InComponent, FBox& OutBox)
	{
		bool bBound = false;
		
		if (InComponent)
		{	
			if (!bBound)
			{
				const UStaticMeshComponent* SMC = Cast<const UStaticMeshComponent>(InComponent);
				if (SMC != NULL && SMC->GetStaticMesh() != NULL)
				{
					OutBox = SMC->GetStaticMesh()->GetBoundingBox();
					bBound = true;
				}
			}

			if (!bBound)
			{
				const UBrushComponent* BC = Cast<const UBrushComponent>(InComponent);
				if (BC != NULL && BC->Brush != NULL)
				{
					OutBox = BC->Brush->Bounds.GetBox();
					bBound = true;
				}
			}

			if (!bBound)
			{
				const USkinnedMeshComponent* SkinMC = Cast<const USkinnedMeshComponent>(InComponent);
				if (SkinMC != NULL && SkinMC->SkeletalMesh != NULL)
				{
					OutBox = SkinMC->SkeletalMesh->GetImportedBounds().GetBox();
					bBound = true;
				}
			}
		}

		return bBound;
	}

	static UStaticMesh* DuplicateStaticMesh(UStaticMesh* StaticMesh)
	{
		if (StaticMesh)
		{
			TArray<UObject*> ObjectsToBeDuplicate = { StaticMesh };
			TArray<UObject*> NewObjects;
			ObjectTools::DuplicateObjects(ObjectsToBeDuplicate, TEXT(""), TEXT(""), /*bOpenDialog=*/false, &NewObjects);

			if (NewObjects.Num() > 0)
			{
				TArray<FAssetData> AssetsToSync;
				for (auto ObjIt = NewObjects.CreateConstIterator(); ObjIt; ++ObjIt)
				{
					new(AssetsToSync) FAssetData(*ObjIt);
				}

				return Cast<UStaticMesh>(NewObjects[0]);
			}
		}

		return nullptr;
	}
}

FVector FPivotToolUtil::CopiedPivotOffset = FVector::ZeroVector;
bool FPivotToolUtil::bPivotOffsetCopied = false;

void FPivotToolUtil::CopyActorPivotOffset(bool bWorldSpace)
{
	if (GEditor->GetSelectedActorCount() > 0)
	{
		AActor* LastSelectedActor = GEditor->GetSelectedActors()->GetBottom<AActor>();
		if (LastSelectedActor)
		{
			FVector LocalPivotOffset = LastSelectedActor->GetPivotOffset();
			CopiedPivotOffset = bWorldSpace ? LastSelectedActor->GetTransform().TransformVector(LocalPivotOffset) : LocalPivotOffset;
			bPivotOffsetCopied = true;
		}
	}
}

void FPivotToolUtil::PasteActorPivotOffset(bool bWorldSpace)
{
	if (bPivotOffsetCopied)
	{
		UpdateSelectedActorsPivotOffset(CopiedPivotOffset, bWorldSpace);
	}
	else
	{
		FPivotToolUtil::NotifyMessage(LOCTEXT("NoCopiedPivotOffset", "No Copied Pivot Offset"), 0.5f);
	}
}

void FPivotToolUtil::UpdateSelectedActorsPivotOffset(const FVector& NewPivotOffset, bool bWorldSpace)
{
	if (GEditor->GetSelectedActorCount() <= 0)
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("UpdateActorsPivotOffset", "Update Actors Pivot Offset"));

	FScopedLevelDirtied LevelDirtyCallback;
	FScopedActorPropertiesChange ActorPropertiesChangeCallback;
	
	bool bHasAnyUpdated = false;
	for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
	{
		AActor* Actor = static_cast<AActor*>(*It);
		bool bUpdated = UpdateActorPivotOffset(Actor, NewPivotOffset, bWorldSpace);
		if (bUpdated)
		{
			bHasAnyUpdated = true;
		}
	}

	GUnrealEd->NoteSelectionChange();

	if (bHasAnyUpdated)
	{
		// FPivotToolUtil::NotifyMessage(LOCTEXT("ActorsPivotOffsetUpdated", "Actors Pivot Offset Updated"), 0.5f);
	}
}

void FPivotToolUtil::UpdateSelectedActorsPivotOffset(EPivotPreset InPivotPrest, const FPivotToolOptions& InOptions)
{

	PIVOTTOOL_LOG(Display, TEXT("FPivotToolUtil::UpdateSelectedActorsPivotOffset: PivotPreset [%d], SelectedActorCount [%d]"), (int32)InPivotPrest, GEditor->GetSelectedActorCount());

	const bool bAutoSave = InOptions.bAutoSave;
	const bool bAsGroup = InOptions.bGroupMode;
	const bool bVertexMode = InOptions.bVertexMode;
	const bool bChildrenMode = InOptions.bChildrenMode;
	const bool bLastSelectedMode = InOptions.bLastSelectedMode;

	if (GEditor->GetSelectedActorCount() <= 0)
	{
		return;
	}

	bool bOnlyOneActorSelected = GEditor->GetSelectedActorCount() == 1;

	if (!bAutoSave)
	{	
		FVector PivotPoint;

		bool bUseLastSelectedActor = bOnlyOneActorSelected || bLastSelectedMode || !bAsGroup || (bAsGroup && bVertexMode);

		PivotPoint = bUseLastSelectedActor 
			? GetActorPivot(GEditor->GetSelectedActors()->GetBottom<AActor>(), InPivotPrest, bVertexMode, bChildrenMode)
			: GetBoundingBoxPoint(GetSelectionBounds(bChildrenMode).GetBox(), InPivotPrest);
		
		FEditorModeTools& EditorModeTools = GLevelEditorModeTools();
		GUnrealEd->SetPivotMovedIndependently(true);
		EditorModeTools.SetPivotLocation(PivotPoint, false);
		GEditor->RedrawLevelEditingViewports();
	}
	else 
	{
		const FScopedTransaction Transaction(LOCTEXT("UpdateActorsPivotOffset", "Update Actors Pivot Offset"));

		FScopedLevelDirtied LevelDirtyCallback;
		FScopedActorPropertiesChange ActorPropertiesChangeCallback;

		if (bAsGroup || bLastSelectedMode)
		{
			bool bUseLastSelectedActor = bOnlyOneActorSelected || bLastSelectedMode || bVertexMode;
			FVector PivotPoint = bUseLastSelectedActor
				? GetActorPivot(GEditor->GetSelectedActors()->GetBottom<AActor>(), InPivotPrest, bVertexMode, bChildrenMode)
				: GetBoundingBoxPoint(GetSelectionBounds(bChildrenMode).GetBox(), InPivotPrest);

			// Apply pivot offset preset to selected actors as a group
			for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
			{
				AActor* Actor = static_cast<AActor*>(*It);
				UpdateActorPivotOffset(Actor, PivotPoint, /*bWorldSpace = */ true);
			}
		}
		else
		{
			// Apply pivot offset preset to selected actors individually
			bool bHasAnyUpdated = false;
			for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
			{
				AActor* Actor = static_cast<AActor*>(*It);
				FVector PivotPoint = GetActorPivot(Actor, InPivotPrest, bVertexMode, bChildrenMode);
				if (UpdateActorPivotOffset(Actor, PivotPoint, /*bWorldSpace = */ true))
				{
					bHasAnyUpdated = true;
				}
			}
// 			if (bHasAnyUpdated)
// 			{
// 				FPivotToolUtil::NotifyMessage(LOCTEXT("ActorsPivotOffsetUpdated", "Actors Pivot Offset Updated"), 0.5f);
// 			}
		}

		GUnrealEd->NoteSelectionChange();
	}
}

void FPivotToolUtil::GetPreviewPivotsOfSelectedActors(EPivotPreset InPivotPrest, const FPivotToolOptions& InOptions, TArray<FTransform>& OutWorldPivots)
{

	PIVOTTOOL_LOG(Display, TEXT("FPivotToolUtil::GetPreviewPivotsOfSelectedActors: PivotPreset [%d], SelectedActorCount [%d]"), (int32)InPivotPrest, GEditor->GetSelectedActorCount());

	const bool bAutoSave = InOptions.bAutoSave;
	const bool bAsGroup = InOptions.bGroupMode;
	const bool bVertexMode = InOptions.bVertexMode;
	const bool bChildrenMode = InOptions.bChildrenMode;

	if (GEditor->GetSelectedActorCount() <= 0)
	{
		return;
	}

	OutWorldPivots.Empty();

	bool bOnlyOneActorSelected = GEditor->GetSelectedActorCount() == 1;

	if (!bAutoSave)
	{
		bool bUseLastSelectedActor = bOnlyOneActorSelected || !bAsGroup || (bAsGroup && bVertexMode);
		AActor* LastSelectedActor = GEditor->GetSelectedActors()->GetBottom<AActor>();
		FTransform ActorWorldTransforM = LastSelectedActor->GetActorTransform();

		FVector PivotPoint = bUseLastSelectedActor
			? GetActorPivot(LastSelectedActor, InPivotPrest, bVertexMode, bChildrenMode)
			: GetBoundingBoxPoint(GetSelectionBounds(bChildrenMode).GetBox(), InPivotPrest);

		ActorWorldTransforM.SetLocation(PivotPoint);
		OutWorldPivots.Add(ActorWorldTransforM);
	}
	else
	{
		if (bAsGroup)
		{
			bool bUseLastSelectedActor = bOnlyOneActorSelected || bVertexMode;
			AActor* LastSelectedActor = GEditor->GetSelectedActors()->GetBottom<AActor>();
			FTransform ActorWorldTransforM = LastSelectedActor->GetActorTransform();

			FVector PivotPoint = bUseLastSelectedActor
				? GetActorPivot(GEditor->GetSelectedActors()->GetBottom<AActor>(), InPivotPrest, bVertexMode, bChildrenMode)
				: GetBoundingBoxPoint(GetSelectionBounds(bChildrenMode).GetBox(), InPivotPrest);

			ActorWorldTransforM.SetLocation(PivotPoint);
			OutWorldPivots.Add(ActorWorldTransforM);
		}
		else
		{
			for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
			{
				AActor* Actor = static_cast<AActor*>(*It);
				FTransform ActorWorldTransforM = Actor->GetActorTransform();
				FVector PivotPoint = GetActorPivot(Actor, InPivotPrest, bVertexMode, bChildrenMode);
				ActorWorldTransforM.SetLocation(PivotPoint);
				OutWorldPivots.Add(ActorWorldTransforM);
			}
		}
		//GUnrealEd->NoteSelectionChange();
	}
}

bool FPivotToolUtil::BakeStaticMeshActorsPivotOffsetToRawMesh(AStaticMeshActor* InStaticMeshActor, const FPivotToolOptions& InOptions, bool bDuplicate, bool bSilentMode)
{
	const bool bBakeRotation = InOptions.bFreezeRotation;
	const bool bAutoSave = InOptions.bAutoSave;

	if (InStaticMeshActor)
	{
		TArray<UStaticMeshComponent*> StaticMeshComponents;
		InStaticMeshActor->GetComponents<UStaticMeshComponent>(StaticMeshComponents);
		if (StaticMeshComponents.Num() > 1)
		{
			if (!bSilentMode)
			{
				FPivotToolUtil::NotifyMessage(LOCTEXT("TooManyStaticMeshComponent", "More than one Static Mesh Components found, skip baking."), 0.5f);
			}
			return false;
		}

		UStaticMeshComponent* StaticMeshComponent = InStaticMeshActor->GetStaticMeshComponent();
		UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh();

		if (StaticMesh)
		{	
			if (!bAutoSave)
			{
				// Save temporary Actor Pivot Offset
				FEditorModeTools& EditorModeTools = GLevelEditorModeTools();
				FPivotToolUtil::UpdateSelectedActorsPivotOffset(EditorModeTools.PivotLocation, /*bWorldSpace=*/ true);
			}

			FVector PivotOffset = InStaticMeshActor->GetPivotOffset();
			FQuat ComponentRotation = StaticMeshComponent->GetComponentTransform().GetRotation();
			if ( (PivotOffset == FVector::ZeroVector)
				&& (bBakeRotation && ComponentRotation.IsIdentity()) )
			{
				if (!bSilentMode)
				{
					NotifyMessage(LOCTEXT("NothingToBake", "No change of pivot, nothing to bake"), 1.f);
				}				
				return false;
			}

			if (bDuplicate)
			{
				StaticMesh = PivotTool::DuplicateStaticMesh(StaticMesh);
				if (StaticMesh)
				{
					//StaticMeshComponent->SetStaticMesh(StaticMesh);
					TArray<FAssetData> AssetDatas;
					AssetDatas.Emplace(StaticMesh);
					GEditor->SyncBrowserToObjects(AssetDatas);
				}
				else
				{
					if (!bSilentMode)
					{
						NotifyMessage(LOCTEXT("FailedToDuplicate", "Failed to duplicate static mesh"), 1.f);
					}					
					return false;
				}
			}

			struct Local
			{
				static void TransformMesh(UStaticMesh* InMesh, const FTransform& InTransform, bool bWithRotation = false)
				{
					// Update Vertex Positions
					int32 NumLODs = InMesh->GetNumLODs();
					for (int32 LODIndex = 0; LODIndex < NumLODs; ++LODIndex)
					{
						FStaticMeshSourceModel& SrcModel = InMesh->GetSourceModel(LODIndex);
						FRawMesh RawMesh;
						SrcModel.LoadRawMesh(RawMesh);

						int32 NumVertices = RawMesh.VertexPositions.Num();
						// UE_LOG(LogPivotTool, Display, TEXT("Baking Actor: %s, LOD %d, Vertices: %d"), *InStaticMeshActor->GetActorLabel(), LODIndex, NumVertices);

						if (NumVertices)
						{
							const FVector BuildScale3D = SrcModel.BuildSettings.BuildScale3D;
							TransformRawMeshVertexData(InTransform, RawMesh, BuildScale3D);
							SrcModel.SaveRawMesh(RawMesh);
							InMesh->CommitMeshDescription(LODIndex);
						}
					}

					// Update Sockets
					int32 NumSockets = InMesh->Sockets.Num();
					for (int32 SocketIndex = 0; SocketIndex < NumSockets; ++SocketIndex)
					{
						UStaticMeshSocket* Socket = InMesh->Sockets[SocketIndex];
						FTransform SocketTransform(Socket->RelativeRotation, Socket->RelativeLocation, Socket->RelativeScale);

						//Socket->RelativeLocation -= PivotOffset;
						Socket->RelativeLocation = InTransform.TransformPosition(Socket->RelativeLocation);
						if (bWithRotation)
						{
							Socket->RelativeRotation += InTransform.GetRotation().Rotator();
						}
					}

					// Update Physic Gemotry
					if (InMesh->BodySetup)
					{
						FKAggregateGeom& AggGeom = InMesh->BodySetup->AggGeom;
						TransformPhysicsGemotry(InTransform, AggGeom);
					}
				}
		};

			const FScopedTransaction Transaction(LOCTEXT("BakeActorsPivotOffset", "Bake Actor Pivot Offset"));
			StaticMesh->Modify();

			// Pre-Save
#if 0
			{
				for (TObjectIterator<UStaticMeshComponent> It(RF_ClassDefaultObject, /*bIncludeDerivedClasses*/false, EInternalObjectFlags::PendingKill); It; ++It)
				{
					if (It->GetStaticMesh() == StaticMesh && It->GetOwner() && It->GetOwner()->GetWorld())
					{
						if (It->IsRenderStateCreated())
						{
							check(It->IsRegistered());
							It->UnregisterComponent();
						}
					}
				}
			}
#endif

			bool bGIsSilentBackup = GIsSilent;
			GIsSilent = true;

			StaticMesh->PreEditChange(NULL);

			FTransform PivotPositionTransform(-PivotOffset);
			Local::TransformMesh(StaticMesh, PivotPositionTransform);

			if (bBakeRotation)
			{
				FTransform PivotRotationTransform(ComponentRotation);
				Local::TransformMesh(StaticMesh, PivotRotationTransform, true);
			}

			StaticMesh->PostEditChange();

			if (bDuplicate)
			{
				StaticMeshComponent->SetStaticMesh(StaticMesh);
			}

			GIsSilent = bGIsSilentBackup;

			StaticMesh->MarkPackageDirty();

#if 0
			// Post-Save
			{
				for (TObjectIterator<UStaticMeshComponent> It(RF_ClassDefaultObject, false, EInternalObjectFlags::PendingKill); It; ++It)
				{
					if (It->GetStaticMesh() == StaticMesh && It->GetOwner() && It->GetOwner()->GetWorld())
					{
						if (!It->IsRenderStateCreated())
						{
							It->RegisterComponent();
						}
					}
				}
			}
#endif

			//UE_LOG(LogPivotTool, Display, TEXT("Baking Actor : %s to %s, done!"), *InStaticMeshActor->GetActorLabel(), *PivotOffset.ToString());
			//FEditorDelegates::OnAssetReimport.Broadcast(StaticMesh);
			GEditor->BroadcastObjectReimported(StaticMesh);


			InStaticMeshActor->Modify();
			InStaticMeshActor->SetActorLocation(InStaticMeshActor->GetTransform().TransformPosition(InStaticMeshActor->GetPivotOffset()));
			if (bBakeRotation)
			{
				InStaticMeshActor->SetActorRotation(FQuat::Identity);
			}
			InStaticMeshActor->SetPivotOffset(FVector::ZeroVector);
			GUnrealEd->SetPivotMovedIndependently(false);
			InStaticMeshActor->PostEditMove(/*bFinished=*/ true);

			FEditorSupportDelegates::RedrawAllViewports.Broadcast();
			GUnrealEd->NoteSelectionChange();

			if (!bSilentMode)
			{
				FPivotToolUtil::NotifyMessage(LOCTEXT("ActorsPivotOffsetBaked", "Actors Pivot Offset Baked"), 1.f);
			}
			return true;
		}
	}
	return false;
}

void FPivotToolUtil::NotifyMessage(const FText& Message, float InDuration)
{
	if (!Message.IsEmpty())
	{
		FNotificationInfo NotificationInfo(Message);
		NotificationInfo.ExpireDuration = InDuration;
		FSlateNotificationManager::Get().AddNotification(NotificationInfo);
	}
}

bool FPivotToolUtil::UpdateActorPivotOffset(AActor* InActor, const FVector& NewPivotOffset, bool bWorldSpace /*= false*/)
{
	if (InActor)
	{
		FVector PivotOffset = NewPivotOffset;
		if (bWorldSpace)
		{
			FVector Delta(NewPivotOffset - InActor->GetActorLocation());
			PivotOffset = InActor->GetTransform().InverseTransformVector(Delta);
		}

		if (InActor->GetPivotOffset() == PivotOffset)
		{
			return false;
		}
		else
		{
			InActor->Modify();
			InActor->SetPivotOffset(PivotOffset);
			GUnrealEd->SetPivotMovedIndependently(false);
			InActor->PostEditMove(/*bFinished=*/ true);
			return true;
		}
	}

	return false;
}

void FPivotToolUtil::AlignToLastSelectedActorsWithPivotOffset(ECoordSystem InCoordSystem, EAxis::Type Axis, bool bMirrored/* = false*/)//, bool bNegative /*= false*/, bool bEnableUndo /*= true*/, bool bNotify /*= true*/)
{
	if (GEditor->GetSelectedActorCount() < 2)
	{
		return;
	}

	TArray<AActor*> SelectedActors;
	GEditor->GetSelectedActors()->GetSelectedObjects<AActor>(SelectedActors);

	const bool bAlignToLastActor = true;
	AActor* TargetActor = bAlignToLastActor ? SelectedActors.Last() : SelectedActors[0];

	if (TargetActor && !TargetActor->IsPendingKill())
	{
		GEditor->BeginTransaction(LOCTEXT("AlignSelectedActorsPivot", "Align Pivots"));

		const bool bWorldCoord = InCoordSystem == COORD_World;
		const FTransform TargetTM = TargetActor->GetActorTransform();
		const FVector TargetLoc = TargetTM.TransformPosition(TargetActor->GetPivotOffset());

		for (AActor* Actor : SelectedActors)
		{
			if (Actor && Actor != TargetActor && !Actor->IsPendingKill())
			{
				const FTransform SourceTM = Actor->GetActorTransform();
				FVector SourceLoc = SourceTM.TransformPosition(Actor->GetPivotOffset());
				if (bMirrored)
				{
					SourceLoc *= -1;
				}

				FVector Offset = FVector::ZeroVector;
				if (bWorldCoord)
				{
					Offset = TargetLoc - SourceLoc;
					switch (Axis)
					{
					case EAxis::X: Offset.Y = Offset.Z = 0.f; break;
					case EAxis::Y: Offset.X = Offset.Z = 0.f; break;
					case EAxis::Z: Offset.X = Offset.Y = 0.f; break;
					case EAxis::None: // treated as all axies
					default: break;
					}
				}
				else
				{
					FVector SourceRelativeLoc = TargetTM.InverseTransformPosition(SourceLoc);
					switch (Axis)
					{
					case EAxis::X: SourceRelativeLoc.X = 0.f; break;
					case EAxis::Y: SourceRelativeLoc.Y = 0.f; break;
					case EAxis::Z: SourceRelativeLoc.Z = 0.f; break;
					case EAxis::None: // treated as all axies
					default: break;
					}
					Offset = TargetTM.TransformPosition(SourceRelativeLoc) - SourceLoc;
				}

				Actor->Modify();
				Actor->AddActorWorldOffset(Offset);
				Actor->PostEditMove(true);
			}
		}

		GEditor->EndTransaction();
	}
}

void FPivotToolUtil::AlignSelectedActorsWithPivotOffset(ECoordSystem InCoordSystem, EAxis::Type Axis, bool bNeg/* = false*/)//, bool bNegative /*= false*/, bool bEnableUndo /*= true*/, bool bNotify /*= true*/)
{
	if (GEditor->GetSelectedActorCount() < 2)
	{
		return;
	}

	TArray<AActor*> SelectedActors;
	GEditor->GetSelectedActors()->GetSelectedObjects<AActor>(SelectedActors);

	struct Local
	{
		static FVector GetTargetLoc(const TArray<AActor*> InActors, EAxis::Type InputAxis, bool bNeg)
		{
			FVector TargetLoc = FVector::ZeroVector;

			bool bFirst = true;
			for (AActor* Actor : InActors)
			{
				const FTransform TargetWorldTM = Actor->GetActorTransform();
				const FVector TargetLocWithOffset = TargetWorldTM.TransformPosition(Actor->GetPivotOffset());
				if (bFirst)
				{
					bFirst = false;
					TargetLoc = TargetLocWithOffset;
					continue;
				}

				TargetLoc = bNeg ? TargetLoc.ComponentMin(TargetLocWithOffset) : TargetLoc.ComponentMax(TargetLocWithOffset);
			}
			return TargetLoc;
		}
	};

	FVector TargetLocation = Local::GetTargetLoc(SelectedActors, Axis, bNeg);

	{
		GEditor->BeginTransaction(LOCTEXT("AlignSelectedActorsPivot", "Align Actors"));

		const bool bWorldCoord = true;
		for (AActor* Actor : SelectedActors)
		{
			if (Actor && !Actor->IsPendingKill())
			{
				const FTransform SourceTM = Actor->GetActorTransform();
				const FVector SourceLoc = SourceTM.TransformPosition(Actor->GetPivotOffset());

				FVector Offset = FVector::ZeroVector;
				if (bWorldCoord)
				{
					Offset = TargetLocation - SourceLoc;
					switch (Axis)
					{
					case EAxis::X: Offset.Y = Offset.Z = 0.f; break;
					case EAxis::Y: Offset.X = Offset.Z = 0.f; break;
					case EAxis::Z: Offset.X = Offset.Y = 0.f; break;
					case EAxis::None: // treated as all axies
					default: break;
					}
				}

				Actor->Modify();
				Actor->AddActorWorldOffset(Offset);
				Actor->PostEditMove(true);
			}
		}

		GEditor->EndTransaction();

		GEditor->NoteSelectionChange();
	}
}

void FPivotToolUtil::AlignSelectionRotation(EAxis::Type Axis)
{
	if (GEditor->GetSelectedActorCount() < 2)
	{
		return;
	}

	TArray<AActor*> SelectedActors;
	GEditor->GetSelectedActors()->GetSelectedObjects<AActor>(SelectedActors);

	const bool bAlignToLastActor = true;
	AActor* TargetActor = bAlignToLastActor ? SelectedActors.Last() : SelectedActors[0];

	if (TargetActor && !TargetActor->IsPendingKill())
	{
		GEditor->BeginTransaction(LOCTEXT("AlignSelectedActorsPivot", "Align Pivots"));

		const FTransform TargetTM = TargetActor->GetActorTransform();
		const FRotator TargetRot = TargetTM.Rotator();

		for (int32 Index = 0; Index < SelectedActors.Num() - 1; ++Index)
		{
			AActor* Actor = SelectedActors[Index];
			if (Actor && !Actor->IsPendingKill())
			{
				const FTransform SourceTM = Actor->GetActorTransform();
				const FRotator SourceRot = SourceTM.Rotator();

				FRotator ExpectedRotator = SourceRot;
				
				switch (Axis)
				{
				case EAxis::X: ExpectedRotator.Roll = TargetRot.Roll; break;
				case EAxis::Y: ExpectedRotator.Pitch = TargetRot.Pitch; break;
				case EAxis::Z: ExpectedRotator.Yaw = TargetRot.Yaw; break;
				case EAxis::None: // treated as all axies
				default: break;
				}

				Actor->Modify();
				Actor->SetActorRotation(ExpectedRotator);
				Actor->PostEditMove(true);
			}
		}

		GEditor->EndTransaction();
	}
}

void FPivotToolUtil::AlignSelectionPivots(ECoordSystem InCoordSystem, EAxis::Type Axis)
{
	if (GEditor->GetSelectedActorCount() < 2)
	{
		return;
	}

	TArray<AActor*> SelectedActors;
	GEditor->GetSelectedActors()->GetSelectedObjects<AActor>(SelectedActors);

	const bool bAlignToLastActor = true;
	AActor* TargetActor = bAlignToLastActor ? SelectedActors.Last() : SelectedActors[0];
	const FTransform TargetTM = SelectedActors.Last()->GetActorTransform();
	const FVector TargetLoc = TargetTM.TransformPosition(TargetActor->GetPivotOffset());

	UpdateSelectedActorsPivotOffset(TargetLoc, /*bWorldSpace*/true);
}

void FPivotToolUtil::OffsetSelectedActorsPivotOffset(const FVector& InDeltaPivotOffset, bool bWorldSpace /*= false*/)
{
	if (GEditor->GetSelectedActorCount() <= 0)
	{
		return;
	}

	if (InDeltaPivotOffset.IsNearlyZero())
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("UpdateActorsPivotOffset", "Update Actors Pivot Offset"));

	FScopedLevelDirtied LevelDirtyCallback;
	FScopedActorPropertiesChange ActorPropertiesChangeCallback;

	for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
	{
		AActor* Actor = static_cast<AActor*>(*It);
		if (Actor)
		{
			FVector DeltaOffset = InDeltaPivotOffset;
			if (bWorldSpace)
			{
				DeltaOffset = Actor->GetTransform().InverseTransformVector(InDeltaPivotOffset);
			}

			FVector OldPivotOffset = Actor->GetPivotOffset();
			FVector NewPivotOffset = OldPivotOffset + DeltaOffset;

			if (!NewPivotOffset.Equals(OldPivotOffset))
			{
				Actor->Modify();
				Actor->SetPivotOffset(NewPivotOffset);
				GUnrealEd->SetPivotMovedIndependently(false);
				Actor->PostEditMove(/*bFinished=*/ true);
			}
		}
	}

	GUnrealEd->NoteSelectionChange();
}

void FPivotToolUtil::SnapSelectedActorsPivotToVertex()
{
	if (GEditor->GetSelectedActorCount() <= 0)
	{
		return;
	}

	struct Local
	{
		static FVector GetClosetVertexLocalPostion(AActor* InputActor, const FVector& InputLocalPostion)
		{
			FVector InputWorldPostion = InputActor->GetActorTransform().TransformPosition(InputLocalPostion);
			FVector ClosestWorldVertPostion = InputWorldPostion;

			TArray<UPrimitiveComponent*> PrimitiveComponents;
			PivotTool::GetValidPrimitiveComponents(InputActor, PrimitiveComponents);

			FVector FinalPosition = FVector::ZeroVector;
			TArray<FVector> FoundPostions;
			int32 NumVertexs = 0;
			bool bHasPosition = false;
			bool bFirstPosition = true;
			float LastDistance = 0;

			for (UPrimitiveComponent* Component : PrimitiveComponents)
			{
				TSharedPtr<PivotTool::FVertexIterator> VertexGetter = PivotTool::MakeVertexIterator(Component);
				if (VertexGetter.IsValid())
				{
					bHasPosition = true;
					for (PivotTool::FVertexIterator& VertexGetterRef = *VertexGetter; VertexGetterRef; ++VertexGetterRef)
					{
						FVector CurrentWorldPosition = VertexGetterRef.Position();

						float CurrentDistance = FVector::DistSquared(InputWorldPostion, CurrentWorldPosition);
						if (bFirstPosition)
						{
							bFirstPosition = false;
							LastDistance = CurrentDistance;
							FoundPostions = { CurrentWorldPosition };
						}
						else if (FMath::IsNearlyEqual(CurrentDistance, LastDistance, KINDA_SMALL_NUMBER))
						{
							FoundPostions.Add(CurrentWorldPosition);
						}
						else if (CurrentDistance < LastDistance)
						{
							LastDistance = CurrentDistance;
							FoundPostions = { CurrentWorldPosition };
						}
					}
				}
			}

			if (bHasPosition)
			{
				if (FoundPostions.Num() > 0)
				{
					FVector ClosestPostion = FoundPostions[0];
					float Distance = FVector::DistSquared(InputWorldPostion, FoundPostions[0]);

					for (int32 Index = 1; Index < FoundPostions.Num(); ++Index)
					{
						float CurrentDistance = FVector::DistSquared(InputWorldPostion, FoundPostions[Index]);
						if (CurrentDistance < Distance)
						{
							ClosestPostion = FoundPostions[Index];
							Distance = CurrentDistance;
						}
					}

					ClosestWorldVertPostion = ClosestPostion; // closest
				}
			}

			return InputActor->GetActorTransform().InverseTransformPosition(ClosestWorldVertPostion);
		}
	};

	const FScopedTransaction Transaction(LOCTEXT("UpdateActorsPivotOffset", "Update Actors Pivot Offset"));

	FScopedLevelDirtied LevelDirtyCallback;
	FScopedActorPropertiesChange ActorPropertiesChangeCallback;

	for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
	{
		AActor* Actor = static_cast<AActor*>(*It);
		if (Actor)
		{
			FEditorModeTools& EditorModeTools = GLevelEditorModeTools();
			FVector OldPivotOffset = Actor->GetActorTransform().InverseTransformPosition(EditorModeTools.GetWidgetLocation()); //Actor->GetPivotOffset();
			FVector NewPivotOffset = Local::GetClosetVertexLocalPostion(Actor, OldPivotOffset);

			if (!NewPivotOffset.Equals(OldPivotOffset))
			{
				Actor->Modify();
				Actor->SetPivotOffset(NewPivotOffset);
				GUnrealEd->SetPivotMovedIndependently(false);
				Actor->PostEditMove(/*bFinished=*/ true);
			}
		}
	}

	GUnrealEd->NoteSelectionChange();
}

////////////////////////////////////////////////////////////
// Private

void FPivotToolUtil::TransformRawMeshVertexData(const FTransform& InTransform, FRawMesh& OutRawMesh, const FVector& InBuildScale3D)
{
	for (FVector& Vertex : OutRawMesh.VertexPositions)
	{
		Vertex *= InBuildScale3D;
		Vertex = InTransform.TransformPosition(Vertex);
		Vertex /= InBuildScale3D;
	}

	for (FVector& TangentX : OutRawMesh.WedgeTangentX)
	{
		TangentX = InTransform.TransformVectorNoScale(TangentX);
	}

	for (FVector& TangentY : OutRawMesh.WedgeTangentY)
	{
		TangentY = InTransform.TransformVectorNoScale(TangentY);
	}

	for (FVector& TangentZ : OutRawMesh.WedgeTangentZ)
	{
		TangentZ = InTransform.TransformVectorNoScale(TangentZ);
	}
}

void FPivotToolUtil::TransformPhysicsGemotry(const FTransform& InTransform, FKAggregateGeom& AggGeom)
{
	for (FKSphereElem& Elem : AggGeom.SphereElems)
	{
		FTransform ElemTM = Elem.GetTransform();
		Elem.SetTransform(ElemTM * InTransform);
	}

	for (FKBoxElem& Elem : AggGeom.BoxElems)
	{
		FTransform ElemTM = Elem.GetTransform();
		Elem.SetTransform(ElemTM * InTransform);
	}

	for (FKSphylElem& Elem : AggGeom.SphylElems)
	{
		FTransform ElemTM = Elem.GetTransform();
		Elem.SetTransform(ElemTM * InTransform);
	}

	for (FKConvexElem& Elem : AggGeom.ConvexElems)
	{
		FTransform ElemTM = Elem.GetTransform();
		Elem.SetTransform(ElemTM * InTransform);
	}
}

FVector FPivotToolUtil::GetActorPivot(AActor* InActor, EPivotPreset InPreset, bool bVertexMode, bool bChildrenMode, bool bLocalSpace /*= true*/)
{
	FVector PivotPoint(0);

	if (InActor)
	{
		PIVOTTOOL_LOG(Display, TEXT("FPivotToolUtil::GetActorPivot: Actor [%s]"), *InActor->GetActorLabel());

		if (bVertexMode && GetActorVertexPostion(InActor, InPreset, PivotPoint))
		{
		}
		else
		{
			PivotPoint = GetActorBoundingBoxPoint(InActor, InPreset, bChildrenMode, /*bLocalSPace=*/ true);
		}
	}

	return PivotPoint;
}

bool FPivotToolUtil::GetActorVertexPostion(AActor* InActor, EPivotPreset InPreset, FVector& OutPosition)
{
	TArray<UPrimitiveComponent*> PrimitiveComponents;
	PivotTool::GetValidPrimitiveComponents(InActor, PrimitiveComponents);
	
	FVector FinalPosition = FVector::ZeroVector;
	TArray<FVector> FoundPostions;
	int32 NumVertexs = 0;
	bool bHasPosition = false;
	bool bFirstPosition = true;
	float LastDistance = 0;

	int32 PresetIndex = (int32)InPreset;
	bool bUsePlane = PresetIndex > (int32)EPivotPreset::BoundingBoxCenter && PresetIndex <= (int32)EPivotPreset::BoundingBoxCenterBack;
	bool bUseCenter = InPreset == EPivotPreset::BoundingBoxCenter;
	
	FVector ActorBoundingBoxPoint = FVector::ZeroVector;
	FQuat ActorRotation = InActor->GetActorTransform().GetRotation();
	if (!bUseCenter)
	{
		ActorBoundingBoxPoint = GetActorBoundingBoxPoint(InActor, InPreset, /*bLocalSpace=*/ true);
	}

	for (UPrimitiveComponent* Component : PrimitiveComponents)
	{	
		FPlane ActorPlane(EForceInit::ForceInitToZero);
		if (bUsePlane)
		{
			switch (InPreset)
			{
			case EPivotPreset::BoundingBoxCenterTop:
				ActorPlane = FPlane(ActorBoundingBoxPoint, -1 * ActorRotation.GetUpVector());
				break;
			case EPivotPreset::BoundingBoxCenterBottom:
				ActorPlane = FPlane(ActorBoundingBoxPoint, ActorRotation.GetUpVector());
				break;
			case EPivotPreset::BoundingBoxCenterLeft:
				ActorPlane = FPlane(ActorBoundingBoxPoint, ActorRotation.GetRightVector());
				break;
			case EPivotPreset::BoundingBoxCenterRight:
				ActorPlane = FPlane(ActorBoundingBoxPoint, -1 * ActorRotation.GetRightVector());
				break;
			case EPivotPreset::BoundingBoxCenterFront:
				ActorPlane = FPlane(ActorBoundingBoxPoint, -1 * ActorRotation.GetForwardVector());
				break;
			case EPivotPreset::BoundingBoxCenterBack:
				ActorPlane = FPlane(ActorBoundingBoxPoint, ActorRotation.GetForwardVector());
				break;
			}

			//DrawDebugSolidPlane(InActor->GetWorld(), ActorPlane, ActorBoundingBoxPoint, 100.f, FColor::Green, true, 2.f);
		}

		TSharedPtr<PivotTool::FVertexIterator> VertexGetter = PivotTool::MakeVertexIterator(Component);
		if (VertexGetter.IsValid())
		{
			bHasPosition = true;
			for (PivotTool::FVertexIterator& VertexGetterRef = *VertexGetter; VertexGetterRef; ++VertexGetterRef)
			{
				FVector CurrentWorldPosition = VertexGetterRef.Position();

				if (bUseCenter)
				{
					FoundPostions.Add(CurrentWorldPosition);
					continue;
				}

				float CurrentDistance = bUsePlane ? FMath::Abs(ActorPlane.PlaneDot(CurrentWorldPosition)) : FVector::DistSquared(ActorBoundingBoxPoint, CurrentWorldPosition);
				// UE_LOG(LogPivotTool, Display, TEXT("CurrentDistance of Vertex: %f"), CurrentDistance);
				if (bFirstPosition)
				{
					bFirstPosition = false;
					LastDistance = CurrentDistance;
					FoundPostions = { CurrentWorldPosition };
				}
				else if (FMath::IsNearlyEqual(CurrentDistance, LastDistance, KINDA_SMALL_NUMBER))
				{
					FoundPostions.Add(CurrentWorldPosition);
				}
				else if (CurrentDistance < LastDistance)
				{
					LastDistance = CurrentDistance;
					FoundPostions = { CurrentWorldPosition };
				}
			}
		}
	}

	if (bHasPosition)
	{
		if (FoundPostions.Num() > 0)
		{
			FVector TotalPositions = FoundPostions[0];
			FVector ClosestPostion = FoundPostions[0];
			float Distance = FVector::DistSquared(ActorBoundingBoxPoint, FoundPostions[0]);

/*			DrawDebugSphere(InActor->GetWorld(), ActorBoundingBoxPoint, / *Radius* / 20.0f, 4, FColor::Red, false, 2.f, SDPG_World, / *Thickness* /2.f);*/

			for (int32 Index = 1; Index < FoundPostions.Num(); ++Index)
			{
// 				if (!bUseCenter)
// 				{
// 					DrawDebugSphere(InActor->GetWorld(), FoundPostions[Index], /*Radius*/ 10.0f, 4, FColor::Blue, false,4.f, SDPG_World, /*Thickness*/2.f);
// 				}

				float CurrentDistance = FVector::DistSquared(ActorBoundingBoxPoint, FoundPostions[Index]);
				if (CurrentDistance < Distance)
				{
					ClosestPostion = FoundPostions[Index];
					Distance = CurrentDistance;
				}

				TotalPositions += FoundPostions[Index];
			}

			//OutPosition = FoundPostions[FMath::RandRange(0, FoundPostions.Num() - 1)]; // random
			//OutPosition = FoundPostions[0]; // first
			if (bUseCenter)
			{
				OutPosition = TotalPositions / FoundPostions.Num(); // averge
			}
			else
			{
				OutPosition = ClosestPostion; // closest
			}
			
			return true;
		}
	}
	
	return false;
}

FVector FPivotToolUtil::GetActorBoundingBoxPoint(AActor* InActor, EPivotPreset InPreset, bool bChildrenMode, bool bLocalSpace /*=true*/)
{
	if (!bChildrenMode && FMath::IsNearlyZero(InActor->GetComponentsBoundingBox().GetVolume(), KINDA_SMALL_NUMBER))
	{
		return InActor->GetActorLocation();
	}

	TArray<AActor*> Children;
	InActor->GetAttachedActors(Children);
	bool bHasChild = Children.Num() > 0;

	bool bWorldSpaceOveride = !bLocalSpace || (bLocalSpace && bChildrenMode && bHasChild);

	if (!bWorldSpaceOveride)
	{
		FVector Point(0);
		const FTransform ActorTransform = InActor->GetActorTransform();

		TArray<UPrimitiveComponent*> ValidComponents;
		PivotTool::GetValidPrimitiveComponents(InActor, ValidComponents);

		FBox LocalBound(EForceInit::ForceInitToZero);
		if (ValidComponents.Num() == 1 && InActor->GetRootComponent() == ValidComponents[0] && PivotTool::GetComponentLocalBound(ValidComponents[0], LocalBound))
		{
			Point = ActorTransform.TransformPosition(GetBoundingBoxPoint(LocalBound, InPreset));
		}
		else
		{
			bool bActorHasRotation = !ActorTransform.GetRotation().IsIdentity(KINDA_SMALL_NUMBER);

			FTransform ActorTransformNoRotation(ActorTransform);
			ActorTransformNoRotation.SetRotation(FQuat::Identity);

			if (bActorHasRotation)
			{
				InActor->SetActorTransform(ActorTransformNoRotation);
			}

			Point = GetBoundingBoxPoint(InActor->GetComponentsBoundingBox(), InPreset);

			if (bActorHasRotation)
			{
				Point = ActorTransform.TransformPosition(ActorTransformNoRotation.InverseTransformPosition(Point));
				InActor->SetActorTransform(ActorTransform);
			}
		}

		return Point;
	}
	else
	{
		FBox ActorBound = GetAllComponentsBoundingBox(InActor, bChildrenMode);
		FVector Point = GetBoundingBoxPoint(ActorBound, InPreset);
		//DrawDebugBox(InActor->GetWorld(), ActorBound.GetCenter(), ActorBound.GetExtent(), FColor::Red, true, 2.f, SDPG_World, 8.f);
		return Point;
	}
}

FBoxSphereBounds FPivotToolUtil::GetSelectionBounds(bool bChildrenMode /*= false*/)
{
	bool bFirstItem = true;

	FBox ActorBox(EForceInit::ForceInitToZero);
	for (FSelectionIterator It(GEditor->GetSelectedActorIterator()); It; ++It)
	{
		if (AActor* Actor = Cast<AActor>(*It))
		{
			FBox Box = GetAllComponentsBoundingBox(Actor, bChildrenMode);

			if (!Box.IsValid)
			{
				Box = FBox(Actor->GetActorLocation(), Actor->GetActorLocation());
			}

			ActorBox = bFirstItem ? Box : ActorBox + Box;
			bFirstItem = false;
		}
	}

	return FBoxSphereBounds(ActorBox);
}

FVector FPivotToolUtil::GetBoundingBoxPoint(const FBox& InBoundingBox, EPivotPreset InPreset)
{
	FVector Result = FVector::ZeroVector;

	FVector Origin = InBoundingBox.GetCenter();
	FVector Extent = InBoundingBox.GetExtent();
	FVector Offset = FVector::ZeroVector;

	switch (InPreset)
	{
	case EPivotPreset::BoundingBoxCenter:			break;
	case EPivotPreset::BoundingBoxCenterTop:		Offset = FVector(0, 0, Extent.Z); break;
	case EPivotPreset::BoundingBoxCenterBottom:		Offset = FVector(0, 0, -Extent.Z);	break;
	case EPivotPreset::BoundingBoxCenterLeft:		Offset = FVector(0, -Extent.Y, 0); break;
	case EPivotPreset::BoundingBoxCenterRight:		Offset = FVector(0, Extent.Y, 0); break;
	case EPivotPreset::BoundingBoxCenterFront:		Offset = FVector(Extent.X, 0, 0); break;
	case EPivotPreset::BoundingBoxCenterBack:		Offset = FVector(-Extent.X, 0, 0); break;

	case EPivotPreset::BoundingBoxCornerTop1:		Offset = FVector(-Extent.X, -Extent.Y, Extent.Z); break;
	case EPivotPreset::BoundingBoxCornerTop2:		Offset = FVector(Extent.X, -Extent.Y, Extent.Z); break;
	case EPivotPreset::BoundingBoxCornerTop3:		Offset = FVector(Extent.X, Extent.Y, Extent.Z); break;
	case EPivotPreset::BoundingBoxCornerTop4:		Offset = FVector(-Extent.X, Extent.Y, Extent.Z); break;
	case EPivotPreset::BoundingBoxCornerBottom1:	Offset = FVector(-Extent.X, -Extent.Y, -Extent.Z); break;
	case EPivotPreset::BoundingBoxCornerBottom2:	Offset = FVector(Extent.X, -Extent.Y, -Extent.Z); break;
	case EPivotPreset::BoundingBoxCornerBottom3:	Offset = FVector(Extent.X, Extent.Y, -Extent.Z); break;
	case EPivotPreset::BoundingBoxCornerBottom4:	Offset = FVector(-Extent.X, Extent.Y, -Extent.Z); break;

	case EPivotPreset::BoundingBoxEdgeTop1:			Offset = FVector(0, -Extent.Y, Extent.Z); break;
	case EPivotPreset::BoundingBoxEdgeTop2:			Offset = FVector(Extent.X, 0, Extent.Z); break;
	case EPivotPreset::BoundingBoxEdgeTop3:			Offset = FVector(0, Extent.Y, Extent.Z); break;
	case EPivotPreset::BoundingBoxEdgeTop4:			Offset = FVector(-Extent.X, 0, Extent.Z); break;
	case EPivotPreset::BoundingBoxEdgeBottom1:		Offset = FVector(0, -Extent.Y, -Extent.Z); break;
	case EPivotPreset::BoundingBoxEdgeBottom2:		Offset = FVector(Extent.X, 0, -Extent.Z); break;
	case EPivotPreset::BoundingBoxEdgeBottom3:		Offset = FVector(0, Extent.Y, -Extent.Z); break;
	case EPivotPreset::BoundingBoxEdgeBottom4:		Offset = FVector(-Extent.X, 0, -Extent.Z); break;
	case EPivotPreset::BoundingBoxEdgeMid1:			Offset = FVector(-Extent.X, -Extent.Y, 0); break;
	case EPivotPreset::BoundingBoxEdgeMid2:			Offset = FVector(Extent.X, -Extent.Y, 0);  break;
	case EPivotPreset::BoundingBoxEdgeMid3:			Offset = FVector(Extent.X, Extent.Y, 0); break;
	case EPivotPreset::BoundingBoxEdgeMid4:			Offset = FVector(-Extent.X, Extent.Y, 0); break;
	default:
		break;
	}

	Result = Origin + Offset;

	return Result;
}

FBox FPivotToolUtil::GetAllComponentsBoundingBox(AActor* InActor, bool bChildrenMode)
{
	FBox ActorBound = InActor->GetComponentsBoundingBox();

	if (bChildrenMode)
	{
		TArray<AActor*> Children;
		InActor->GetAttachedActors(Children);
		for (AActor* Actor : Children)
		{
			if (Actor && !Actor->IsPendingKillPending())
			{
				FBox Box = GetAllComponentsBoundingBox(Actor, bChildrenMode);
				if (!FMath::IsNearlyZero(Box.GetVolume(), KINDA_SMALL_NUMBER))
				{
					ActorBound = FMath::IsNearlyZero(ActorBound.GetVolume()) ? Box : ActorBound + Box;
				}
			}
		}
	}

	return ActorBound;
}

#undef LOCTEXT_NAMESPACE
