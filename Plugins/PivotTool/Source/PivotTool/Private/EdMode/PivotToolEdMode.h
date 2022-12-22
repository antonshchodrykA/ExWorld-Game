// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "Editor.h"
#include "EdMode.h"

class FUICommandList;

namespace PivotToolUtilities
{
	void RunGC();
}

DECLARE_DELEGATE(FOnSelectionChanged);

class FPivotToolEdMode : public FEdMode
{
public:
	const static FEditorModeID EM_PivotToolEdModeId;

public:
	FPivotToolEdMode();
	virtual ~FPivotToolEdMode();

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	//------------------------------------------------------------------------------
	// FEdMode interface

	virtual void Enter() override;
	virtual void Exit() override;
	//virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
	//virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	//virtual bool Select(AActor* InActor, bool bInSelected) override;
	//virtual bool IsSelectionAllowed(AActor* InActor, bool bInSelection) const override;
	virtual void ActorSelectionChangeNotify() override;
	//virtual bool UsesPropertyWidgets() const override;
	//virtual FVector GetWidgetLocation() const override;
	//virtual bool AllowWidgetMove() override;
	//virtual bool ShouldDrawWidget() const override;
	//virtual bool UsesTransformWidget() const override;
	virtual EAxisList::Type GetWidgetAxisToDraw(FWidget::EWidgetMode InWidgetMode) const override;
// 	virtual bool GetCustomDrawingCoordinateSystem(FMatrix& InMatrix, void* InData) override;
// 	virtual bool GetCustomInputCoordinateSystem(FMatrix& InMatrix, void* InData) override;

	//virtual bool CapturedMouseMove(FEditorViewportClient* InViewportClient, FViewport* InViewport, int32 InMouseX, int32 InMouseY) override;
	//virtual bool MouseMove(FEditorViewportClient* ViewportClient, FViewport* Viewport, int32 x, int32 y) override;
	virtual bool StartTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport) override;
	virtual bool EndTracking(FEditorViewportClient* InViewportClient, FViewport* InViewport) override;
	virtual bool InputDelta(FEditorViewportClient* InViewportClient, FViewport* InViewport, FVector& InDrag, FRotator& InRot, FVector& InScale) override;
	virtual bool InputKey(FEditorViewportClient* InViewportClient, FViewport* InViewport, FKey InKey, EInputEvent InEvent) override;
	bool HandleClick(FEditorViewportClient* InViewportClient, HHitProxy *HitProxy, const FViewportClick &Click) override;

// 	virtual EEditAction::Type GetActionEditDelete() override;
// 	virtual bool ProcessEditDelete() override;
// 	virtual EEditAction::Type GetActionEditDuplicate() override;
// 	virtual bool ProcessEditDuplicate() override;

	//virtual void ActorsDuplicatedNotify(TArray<AActor*>& PreDuplicateSelection, TArray<AActor*>& PostDuplicateSelection, bool bOffsetLocations) override;

	bool UsesToolkits() const override;

	// End of FEdMode interface
	//------------------------------------------------------------------------------

	void SetOnSelectionChangedDelegate(FOnSelectionChanged InOnSelectionChangedDelegate);

	class UPivotToolUISetting* UISetting;

protected:
	TSharedPtr<FUICommandList> UICommandList;

private:
	void BindCommands();

	FOnSelectionChanged OnSelectionChangedDelegate;
};

