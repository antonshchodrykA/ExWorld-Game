// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UnrealWidget.h"
#include "PivotToolUtil.generated.h"

struct FKAggregateGeom;
struct FRawMesh;
class AActor;

UENUM()
enum class EPivotPreset : uint8
{
	BoundingBoxCenter UMETA(DisplayName = "C"),

	BoundingBoxCenterTop UMETA(DisplayName = "CT"),
	BoundingBoxCenterBottom UMETA(DisplayName = "CB"),
	BoundingBoxCenterLeft UMETA(DisplayName = "CL"),
	BoundingBoxCenterRight UMETA(DisplayName = "CR"),
	BoundingBoxCenterFront UMETA(DisplayName = "CF"),
	BoundingBoxCenterBack UMETA(DisplayName = "CB"),

	/*******************
	   2 _________ 3
	    /        /
	   /        /
	1 /________/ 4

	******************/
	BoundingBoxCornerTop1 UMETA(DisplayName = "TC1"),
	BoundingBoxCornerTop2 UMETA(DisplayName = "TC2"),
	BoundingBoxCornerTop3 UMETA(DisplayName = "TC3"),
	BoundingBoxCornerTop4 UMETA(DisplayName = "TC4"),
	BoundingBoxCornerBottom1 UMETA(DisplayName = "BC1"),
	BoundingBoxCornerBottom2 UMETA(DisplayName = "BC2"),
	BoundingBoxCornerBottom3 UMETA(DisplayName = "BC3"),
	BoundingBoxCornerBottom4 UMETA(DisplayName = "BC4"),

	/*******************
	    ___ 2____
	   /        /
	  1        3
	 /___ 4 __/ 

	******************/
	BoundingBoxEdgeTop1 UMETA(DisplayName = "TE1"),
	BoundingBoxEdgeTop2 UMETA(DisplayName = "TE2"),
	BoundingBoxEdgeTop3 UMETA(DisplayName = "TE3"),
	BoundingBoxEdgeTop4 UMETA(DisplayName = "TE4"),
	BoundingBoxEdgeMid1 UMETA(DisplayName = "ME1"),
	BoundingBoxEdgeMid2 UMETA(DisplayName = "ME2"),
	BoundingBoxEdgeMid3 UMETA(DisplayName = "ME3"),
	BoundingBoxEdgeMid4 UMETA(DisplayName = "ME4"),
	BoundingBoxEdgeBottom1 UMETA(DisplayName = "BE1"),
	BoundingBoxEdgeBottom2 UMETA(DisplayName = "BE2"),
	BoundingBoxEdgeBottom3 UMETA(DisplayName = "BE3"),
	BoundingBoxEdgeBottom4 UMETA(DisplayName = "BE4"),

	MAX,
};

struct FPivotToolOptions
{
	bool bAutoSave = false;
	bool bGroupMode = false;
	bool bLastSelectedMode = false;
	bool bVertexMode = false;
	bool bChildrenMode = false;

	bool bFreezeRotation = false;
};

struct FPivotToolUtil
{
	static void CopyActorPivotOffset(bool bWorldSpace);
	static void PasteActorPivotOffset(bool bWorldSpace);
	
	static void OffsetSelectedActorsPivotOffset(const FVector& NewPivotOffset, bool bWorldSpace = false);
	static void SnapSelectedActorsPivotToVertex();

	static void UpdateSelectedActorsPivotOffset(const FVector& NewPivotOffset, bool bWorldSpace = false);
	static void UpdateSelectedActorsPivotOffset(EPivotPreset InPivotPrest, const FPivotToolOptions& InOptions);
	static void GetPreviewPivotsOfSelectedActors(EPivotPreset InPivotPrest, const FPivotToolOptions& InOptions, TArray<FTransform>& OutWorldPivots);

	static bool BakeStaticMeshActorsPivotOffsetToRawMesh(class AStaticMeshActor* InStaticMeshActor, const FPivotToolOptions& InOptions, bool bDuplicate = false, bool bSilentMode = false);

	static void NotifyMessage(const FText& Message, float InDuration);

	static bool HasPivotOffsetCopied() { return bPivotOffsetCopied; }

	static bool UpdateActorPivotOffset(AActor* InActor, const FVector& NewPivotOffset, bool bWorldSpace = false);
	
	static void AlignSelectionPivots(ECoordSystem InCoordSystem, EAxis::Type Axis);// , bool bNegative = false, bool bEnableUndo = true, bool bNotify = true);
	static void AlignToLastSelectedActorsWithPivotOffset(ECoordSystem InCoordSystem, EAxis::Type Axis, bool bMirrored = false);
	static void AlignSelectedActorsWithPivotOffset(ECoordSystem InCoordSystem, EAxis::Type Axis, bool bMirrored = false);
	static void AlignSelectionRotation(EAxis::Type Axis);

private:

	static void TransformRawMeshVertexData(const FTransform& InTransform, FRawMesh& OutRawMesh, const FVector& InBuildScale3D);
	static void TransformPhysicsGemotry(const FTransform& InTransform, FKAggregateGeom& AggGeom);

	static FVector GetActorPivot(AActor* InActor, EPivotPreset InPreset, bool bVertexMode, bool bChildrenMode, bool bLocalSpace = true);
	static bool GetActorVertexPostion(AActor* InActor, EPivotPreset InPreset, FVector& OutPosition);
	static FVector GetActorBoundingBoxPoint(AActor* InActor, EPivotPreset InPreset, bool bChildrenMode, bool bLocalSpace = true);
	static FBoxSphereBounds GetSelectionBounds(bool bChildrenMode = false);
	static FVector GetBoundingBoxPoint(const FBox& InBoundingBox, EPivotPreset InPreset);

	static FBox GetAllComponentsBoundingBox(AActor* InActor, bool bRecursive);

	static FVector CopiedPivotOffset;
	static bool bPivotOffsetCopied;
};
