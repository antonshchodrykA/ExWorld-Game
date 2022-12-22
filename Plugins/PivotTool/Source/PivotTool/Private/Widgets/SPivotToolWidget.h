// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "PivotToolUtil.h"
#include "SPivotPreset.h"
#include "SPivotAlign.h"

class SPivotToolWidget : public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SPivotToolWidget) {}
	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

	//~ Begin SWidget Interface
	virtual bool SupportsKeyboardFocus() const override;
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	//~ End SWidget Interface

	// Save/Load UIStting
	void SaveUISetting();
	void LoadUISetting();

private:
	FReply OnApplyOffsetClicked();
	bool IsApplyOffsetEnabled() const;
	FReply OnSnapToVertexClicked();
	bool IsSnapToVertexEnabled() const;

	FReply OnSaveClicked();

	FReply OnCopyClicked();
	FReply OnPasteClicked();
	bool IsPasteEnabled() const;

	FReply OnResetClicked();

	FReply OnBakeClicked();
	FReply OnDuplicateAndBakeClicked();
	bool IsBakeEnabled() const;

	ECheckBoxState IsFreezeRotation() const;
	void OnFreezeRotationCheckStateChanged(ECheckBoxState NewCHeckedState);
	FText GetFreezeRotationCheckboxText() const;

	ECheckBoxState IsPivotCopiedInWorldSpace() const;
	void OnPivotCopiedInWorldSpaceCheckStateChanged(ECheckBoxState NewCHeckedState);
	FText GetCopyInWorldSpaceCheckboxText() const;

	FReply OnPivotPresetSelected(EPivotPreset InPreset);
	void OnPivotPresetHovered(EPivotPreset InPreset);
	void OnPivotPresetUnhovered(EPivotPreset InPreset);

	TOptional<float> GetPivotOffsetInputX() const { return PivotOffsetInput.X; }
	TOptional<float> GetPivotOffsetInputY() const { return PivotOffsetInput.Y; }
	TOptional<float> GetPivotOffsetInputZ() const { return PivotOffsetInput.Z; }
	void OnSetPivotOffsetInput(float InValue, ETextCommit::Type CommitType, int32 InAxis);

	EVisibility GetPivotOffsetInputVisibility() const;

	void TickPreviewPivots();
	void TickUIWrapping();

	void UpdateOptions(FPivotToolOptions& Options);

private:

	bool bFreezeRotation;

	bool bCopyPivotInWorldSpace;

	bool bIsCtrlDown;
	bool bIsShiftDown;
	bool bIsAltDown;

	bool bAlternativeButtons;
	bool bCanToggleAlternativeButton;

	float WidthLastFrame = 0.f;

	FVector PivotOffsetInput;

	TSharedPtr<SPivotPreset> PivotPreset;
	TSharedPtr<SWrapBox> ApplyOffsetWrapBox;
	TSharedPtr<SWrapBox> MainToolboxWrapBox;
	TSharedPtr<SPivotAlign> AlignActorsWidget;

	TArray<FTransform> PreviewPivots;
};
