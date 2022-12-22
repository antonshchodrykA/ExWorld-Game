// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "PivotToolUtil.h"

#include "Input/Reply.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SWrapBox.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Styling/SlateTypes.h"

#include "SPivotPreset.generated.h"

UENUM()
enum EPivotToolPresetType
{
	PresetType_BoundCenter UMETA(DisplayName = "Boudnig Box Center"),
	PresetType_Center UMETA(DisplayName="Center"),
	PresetType_Corner UMETA(DisplayName="Corner"),
	PresetType_Edge UMETA(DisplayName="Edge"),
};

UENUM()
enum EPivotToolPresetUIOrientation
{
	Horizontal,
	Vertical,
};

DECLARE_DELEGATE_RetVal_OneParam(FReply, FOnSelected, EPivotPreset)
DECLARE_DELEGATE_OneParam(FOnHovered, EPivotPreset)
DECLARE_DELEGATE_OneParam(FOnUnhovered, EPivotPreset)

class SPivotPreset : public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SPivotPreset)
		:_OnSelected()
		,_OnHovered()
		,_OnUnhovered()
	{}
	SLATE_EVENT(FOnSelected, OnSelected)
	SLATE_EVENT(FOnHovered, OnHovered)
	SLATE_EVENT(FOnUnhovered, OnUnhovered)
	SLATE_END_ARGS()

	SPivotPreset();

public:
	void Construct(const FArguments& InArgs);

	//~ Begin SWidget Interface
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
 	virtual FReply OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//~ End SWidget Interface

	TSharedRef<SWidget> CreatePresetButtons(EPivotToolPresetType InPresetType, bool bCreateTextButtons);

	ECheckBoxState IsOptionsDisplayed() const;

	ECheckBoxState IsAutoSave() const;
	ECheckBoxState IsGroupMode() const;
	ECheckBoxState IsLastSelectedMode() const;
	ECheckBoxState IsVertexMode() const;
	ECheckBoxState IsChildrenMode() const;
	ECheckBoxState IsTextMode() const;
	ECheckBoxState IsSinglePresetMode() const;

protected:

	FText GetOptionDisplayText() const;
	EVisibility GetOptionsVisibility() const;

	float GetUserSpecifiedScale() const;

	void OnOptionsDisplayedCheckStateChanged(ECheckBoxState NewCHeckedState);
	void OnAutoSaveCheckStateChanged(ECheckBoxState NewCHeckedState);
	void OnGroupModeCheckStateChanged(ECheckBoxState NewCHeckedState);
	void OnLastSelectedModeCheckStateChanged(ECheckBoxState NewCHeckedState);
	void OnVertexModeCheckStateChanged(ECheckBoxState NewCHeckedState);
	void OnChildrenModeCheckStateChanged(ECheckBoxState NewCHeckedState);
	void OnTextModeCheckStateChanged(ECheckBoxState NewCHeckedState);
	void OnSinglePresetModeCheckStateChanged(ECheckBoxState NewCHeckedState);

	FText GetAutoSaveText() const;
	FText GetGroupModeText() const;
	FText GetLastSelectedModeText() const;
	FText GetVertexModeText() const;
	FText GetChildrenModeText() const;
	FText GetTextModeText() const;
	FText GetSinglePresetModeText() const;

	FOnSelected OnSelected;
	FOnHovered OnHovered;
	FOnUnhovered OnUnhovered;

private:
	EVisibility GetPresetWidgetVisibility(EPivotToolPresetType InPresetType) const;
	FReply OnClickPresetButton(EPivotPreset InPivotPreset);
	void OnHoverPresetButton(EPivotPreset InPivotPreset);
	void OnUnhoverPresetButton(EPivotPreset InPivotPreset);

	TSharedRef<SWidget> CreatePresetUI();
	TSharedRef<SWidget> CreatePresetTextUI();
	TSharedRef<SWidget> CreatePresetGraphicUI();
	TSharedRef<SWidget> CreatePresetOverlay(EPivotToolPresetType InPresetType);

	const FSlateBrush* GetPivotPresetBackgroundBrush(EPivotToolPresetType InPresetType) const;
	const FButtonStyle*  GetPivotPresetButtonStyle(EPivotToolPresetType InPresetType, EPivotPreset InPreset = EPivotPreset::MAX) const;
	FVector2D GetPivotPresetButtonSize(EPivotToolPresetType InPresetType, EPivotPreset InPreset = EPivotPreset::MAX) const;
	FText  GetPivotPresetAlphaButtonTexture(EPivotToolPresetType InPresetType, EPivotPreset InPreset = EPivotPreset::MAX) const;
	FText GetPivotPresetTooltip(EPivotPreset InPreset) const;

	void SaveUISetting();
	void LoadUISetting();

	static TArray<FVector2D> PivotPoints;

	bool bOptionsDisplayed;
	
	bool bAutoSave;
	bool bGroupMode;
	bool bLastSelectedMode;
	bool bVertexMode;
	bool bChildrenMode;
	bool bTextMode;
	bool bSinglePresetUI;
	int32 SinglePresetIndex;

	float UserSpecifiedScale;
	float OldUserSpecifiedScale;

	float WidthLastFrame = 0.f;

	TSharedPtr<SWidget> TextUI;
	TSharedPtr<SWidget> GraphicUI;

	TSharedPtr<SWrapBox> TextUIWrapBox;
	TSharedPtr<SWrapBox> PresetOptionsWrapBox; 
	TSharedPtr<SWrapBox> PresetWrapBox;

	TSharedPtr<SWrapBox> PresetSubWrapBox1;
	TSharedPtr<SWrapBox> PresetSubWrapBox2;
};
