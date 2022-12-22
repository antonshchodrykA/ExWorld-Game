// Copyright 2017-2019 marynate. All Rights Reserved.

#include "PivotToolEdMode.h"
#include "PivotToolEdModeToolkit.h"
#include "PivotToolUISetting.h"
#include "PivotToolUtil.h"

#include "Toolkits/ToolkitManager.h"
#include "SnappingUtils.h"
#include "ScopedTransaction.h"

#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Framework/Notifications/NotificationManager.h"

#include "DrawDebugHelpers.h"
#include "Framework/Commands/GenericCommands.h"
#include "EditorModeManager.h"
#include "EditorViewportClient.h"

#define LOCTEXT_NAMESPACE "PivotToolEdMode"

const FEditorModeID FPivotToolEdMode::EM_PivotToolEdModeId = TEXT("EM_PivotToolEdMode");

namespace PivotToolUtilities
{
	void RunGC()
	{
		::CollectGarbage(GARBAGE_COLLECTION_KEEPFLAGS);
	}
}

////////////////////////////////////////////////////////////////////////////////////
// FPivotToolEdMode

FPivotToolEdMode::FPivotToolEdMode()
	: FEdMode()
{
	UICommandList = MakeShareable(new FUICommandList);

	UISetting = NewObject<UPivotToolUISetting>(GetTransientPackage());
	UISetting->ClearFlags(RF_Transactional);
	UISetting->SetParent(this);
}

FPivotToolEdMode::~FPivotToolEdMode()
{
}

void FPivotToolEdMode::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdMode::AddReferencedObjects(Collector);
	Collector.AddReferencedObject(UISetting);
}

void FPivotToolEdMode::Enter()
{
	FEdMode::Enter();

	UISetting->Load();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FPivotToolEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}

	BindCommands();
}

void FPivotToolEdMode::Exit()
{
	GEditor->OnObjectsReplaced().RemoveAll(this);

	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	UISetting->Save();
	UISetting->Reset();

//	PivotToolUtilities::RunGC();
	
	FEdMode::Exit();
}

void FPivotToolEdMode::ActorSelectionChangeNotify()
{
	if (OnSelectionChangedDelegate.IsBound())
	{
		OnSelectionChangedDelegate.Execute();
	}
}

EAxisList::Type FPivotToolEdMode::GetWidgetAxisToDraw(FWidget::EWidgetMode InWidgetMode) const
{
	switch (InWidgetMode)
	{
	case FWidget::WM_Translate:
		return EAxisList::All;
	case FWidget::WM_Rotate:
	case FWidget::WM_Scale:
	default:
		return EAxisList::None;
	}
}

bool FPivotToolEdMode::StartTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport)
{
	return FEdMode::StartTracking(InViewportClient, InViewport);
}

bool FPivotToolEdMode::EndTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport)
{
	if (GEditor->GetSelectedComponentCount() <= 0 && GEditor->GetSelectedActorCount() > 0)
	{
		FEditorModeTools* ModeTools = GetModeManager();
		FPivotToolUtil::UpdateSelectedActorsPivotOffset(ModeTools->PivotLocation, /*bWorldSpace=*/ true);
	}
	
	return FEdMode::EndTracking(InViewportClient, InViewport);
}

bool FPivotToolEdMode::InputDelta(FEditorViewportClient* InViewportClient, FViewport* InViewport, FVector& InDrag, FRotator& InRot, FVector& InScale)
{
	if (InViewportClient->GetCurrentWidgetAxis() != EAxisList::None)
	{
		if (GEditor->GetSelectedComponentCount() <= 0 && GEditor->GetSelectedActorCount() > 0)
		{
			FEditorModeTools* EditorModeTools = GetModeManager();
			FVector Drag(InDrag);
			FSnappingUtils::SnapDragLocationToNearestVertex(EditorModeTools->PivotLocation, Drag, GCurrentLevelEditingViewportClient);
			EditorModeTools->PivotLocation += (Drag - InDrag);
			return true;
		}
	}
	
	return FEdMode::InputDelta(InViewportClient, InViewport, InDrag, InRot, InScale);
}

bool FPivotToolEdMode::InputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event)
{
	bool bHandled = false;
	if (!bHandled)
	{
	}

	return bHandled;
}

bool FPivotToolEdMode::HandleClick(FEditorViewportClient* InViewportClient, HHitProxy *HitProxy, const FViewportClick &Click)
{
	return FEdMode::HandleClick(InViewportClient, HitProxy, Click);
}

bool FPivotToolEdMode::UsesToolkits() const
{
	return true;
}

void FPivotToolEdMode::SetOnSelectionChangedDelegate(FOnSelectionChanged InOnSelectionChangedDelegate)
{
	OnSelectionChangedDelegate = InOnSelectionChangedDelegate;
}

void FPivotToolEdMode::BindCommands()
{
	const TSharedRef<FUICommandList>& ToolkitCommands = Toolkit->GetToolkitCommands();
}

#undef LOCTEXT_NAMESPACE
