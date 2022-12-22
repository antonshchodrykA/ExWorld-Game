// Copyright 2017-2019 marynate. All Rights Reserved.

#include "SPivotPreset.h"
#include "PivotToolUtil.h"
#include "PivotToolStyle.h"
#include "SAlphaButton.h"
#include "PivotTool.h"

#include "LevelEditorActions.h"
#include "EditorModeManager.h"
#include "StaticMeshResources.h"
#include "RawMesh.h"
#include "EditorSupportDelegates.h"
#include "Misc/ConfigCacheIni.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Images/SImage.h"

#define LOCTEXT_NAMESPACE "SPivotToolWidget"

// 160x160
TArray<FVector2D> SPivotPreset::PivotPoints = { {82, 74},
// Center
{82, 36}, { 83, 113 }, { 45, 72 }, { 121, 82 },{ 98, 63 },{ 65, 88 },
//Corner
{ 27, 46 },{ 63, 21 },{ 135, 28 },{ 105, 55 },{ 27, 123 },{ 62, 92 },{ 136, 103 },{ 104, 137 },
//Edge
{44, 37}, {96, 29}, {117, 43}, {64, 53}, {27, 84}, {62, 59}, {129, 67}, {100, 95}, {44, 106}, {96, 97}, {117, 118}, {64, 127},
};

namespace PivotPresetConstants
{
	const float TigherModeThreshold = 560.f;
	const float MinPresetScale = 0.3f;
	const float MaxPresetScale = 1.f;
}

SPivotPreset::SPivotPreset()
	: bOptionsDisplayed(false)

	, bAutoSave(true)
	, bGroupMode(false)
	, bVertexMode(false)
	, bChildrenMode(false)
	, bTextMode(false)
	, bSinglePresetUI(false)
	, SinglePresetIndex(0)

	, UserSpecifiedScale(1.f)
{
}

void SPivotPreset::Construct(const FArguments& InArgs)
{
	LoadUISetting();

	WidthLastFrame = 0.f;

	OnSelected = InArgs._OnSelected;
	OnHovered = InArgs._OnHovered;
	OnUnhovered = InArgs._OnUnhovered;

	const FMargin OptionMargin = FMargin(5.0f, 0.0f);

	ChildSlot
	[
		SNew(SVerticalBox)

		// Options
		+SVerticalBox::Slot()
		.Padding(0, 0)
		.AutoHeight()
		.HAlign(HAlign_Fill)
		[
#if PIVOTTOOL_FOLD
			// Display Options
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().Padding(0, 0).AutoWidth()
			[
				SNew(SCheckBox)
				.Padding(FMargin(0, 0))
				.Style(&FPivotToolStyle::Get().GetWidgetStyle<FCheckBoxStyle>("PivotTool.ToggleButtonCheckbox"))
				.OnCheckStateChanged(this, &SPivotPreset::OnOptionsDisplayedCheckStateChanged)
				.IsChecked(this, &SPivotPreset::IsOptionsDisplayed)
				.ToolTipText(LOCTEXT("OptionsTip", "Display options"))
				.Content()
				[
					SNew(SBox).VAlign(VAlign_Center).HAlign(HAlign_Center).Padding(FMargin(0, 0))
					[
						SNew(STextBlock)
						.Text(this, &SPivotPreset::GetOptionDisplayText)
						.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
					]
				]
			]

			+ SHorizontalBox::Slot().Padding(2, 0).AutoWidth()
			[
				// Options Checkboxes
				SAssignNew(PresetOptionsWrapBox, SWrapBox)

				+ SWrapBox::Slot().Padding(2, 2)
				[
					SNew(SCheckBox)
					.Style(&FPivotToolStyle::Get().GetWidgetStyle<FCheckBoxStyle>("PivotTool.ToggleButtonCheckbox"))
					.OnCheckStateChanged(this, &SPivotPreset::OnAutoSaveCheckStateChanged)
					.IsChecked(this, &SPivotPreset::IsAutoSave)
					.Visibility(this, &SPivotPreset::GetOptionsVisibility)
					.ToolTipText(LOCTEXT("AutoSaveToolTip", "Toggles whether auto save pivot offset"))
					.Padding(OptionMargin)
					.Content()
					[
						SNew(SBox).VAlign(VAlign_Center).HAlign(HAlign_Center).Padding(FMargin(0, 0))
						[
							SNew(STextBlock)
							.Text(this, &SPivotPreset::GetAutoSaveText)
							.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
						]
					]
				]

				+ SWrapBox::Slot().Padding(2, 2)
				[
					SNew(SCheckBox)
					.Style(&FPivotToolStyle::Get().GetWidgetStyle<FCheckBoxStyle>("PivotTool.ToggleButtonCheckbox"))
					.OnCheckStateChanged(this, &SPivotPreset::OnGroupModeCheckStateChanged)
					.IsChecked(this, &SPivotPreset::IsGroupMode)
					.Visibility(this, &SPivotPreset::GetOptionsVisibility)
					.ToolTipText(LOCTEXT("GroupModeToolTip", "Toggles whether treat selected actors as one group"))
					.Padding(OptionMargin)
					.Content()
					[
						SNew(SBox).VAlign(VAlign_Center).HAlign(HAlign_Center).Padding(FMargin(0, 0))
						[
							SNew(STextBlock)
							.Text(this, &SPivotPreset::GetGroupModeText)
							.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
						]
					]
				]

				+ SWrapBox::Slot().Padding(2, 2)
				[
					SNew(SCheckBox)
					.Style(&FPivotToolStyle::Get().GetWidgetStyle<FCheckBoxStyle>("PivotTool.ToggleButtonCheckbox"))
					.OnCheckStateChanged(this, &SPivotPreset::OnLastSelectedModeCheckStateChanged)
					.IsChecked(this, &SPivotPreset::IsLastSelectedMode)
					.Visibility(this, &SPivotPreset::GetOptionsVisibility)
					.ToolTipText(LOCTEXT("LastSelectedModeToolTip", "Apply pivot preset to last selected actor and align other selected actors to it"))
					.Padding(OptionMargin)
					.Content()
					[
						SNew(SBox).VAlign(VAlign_Center).HAlign(HAlign_Center).Padding(FMargin(0, 0))
						[
							SNew(STextBlock)
							.Text(this, &SPivotPreset::GetLastSelectedModeText)
							.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
						]
					]
				]

				+ SWrapBox::Slot().Padding(2, 2)
				[
					SNew(SCheckBox)
					.Style(&FPivotToolStyle::Get().GetWidgetStyle<FCheckBoxStyle>("PivotTool.ToggleButtonCheckbox"))
					.OnCheckStateChanged(this, &SPivotPreset::OnVertexModeCheckStateChanged)
					.IsChecked(this, &SPivotPreset::IsVertexMode)
					.Visibility(this, &SPivotPreset::GetOptionsVisibility)
					.ToolTipText(LOCTEXT("VertexModeToolTip", "Toggles wheter set pivot to vertex instead of bounding box"))
					.Padding(OptionMargin)
					.Content()
					[
						SNew(SBox).VAlign(VAlign_Center).HAlign(HAlign_Center).Padding(FMargin(0, 0))
						[
							SNew(STextBlock)
							.Text(this, &SPivotPreset::GetVertexModeText)
							.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
						]
					]
				] //end of Vertex Mode Checkbox

				+ SWrapBox::Slot().Padding(2, 2)
				[
					SNew(SCheckBox)
					.Padding(OptionMargin)
					.Style(&FPivotToolStyle::Get().GetWidgetStyle<FCheckBoxStyle>("PivotTool.ToggleButtonCheckbox"))
					.OnCheckStateChanged(this, &SPivotPreset::OnChildrenModeCheckStateChanged)
					.IsChecked(this, &SPivotPreset::IsChildrenMode)
					.Visibility(this, &SPivotPreset::GetOptionsVisibility)
					.ToolTipText(LOCTEXT("ChildrenModeToolTip", "Toggles whether use children actors to calculate bounding box"))
					.Content()
					[
						SNew(SBox).VAlign(VAlign_Center).HAlign(HAlign_Center).Padding(FMargin(0, 0))
						[
							SNew(STextBlock)
							.Text(this, &SPivotPreset::GetChildrenModeText)
							.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
						]
					]
				] //end of Children Mode Checkbox

				+ SWrapBox::Slot().Padding(2, 2)
				[
					SNew(SCheckBox)
					.Padding(OptionMargin)
					.Style(&FPivotToolStyle::Get().GetWidgetStyle<FCheckBoxStyle>("PivotTool.ToggleButtonCheckbox"))
					.OnCheckStateChanged(this, &SPivotPreset::OnTextModeCheckStateChanged)
					.IsChecked(this, &SPivotPreset::IsTextMode)
					.Visibility(this, &SPivotPreset::GetOptionsVisibility)
					.ToolTipText(LOCTEXT("TextModeToolTip", "Toggles whether display preset widget as text buttons"))
					.Content()
					[
						SNew(SBox).VAlign(VAlign_Center).HAlign(HAlign_Center).Padding(FMargin(0, 0))
						[
							SNew(STextBlock)
							.Text(this, &SPivotPreset::GetTextModeText)
							.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
						]
					]
				] //end of Text Mode Checkbox

				+ SWrapBox::Slot().Padding(2, 2)
				[
					SNew(SCheckBox)
					.Padding(OptionMargin)
					.Style(&FPivotToolStyle::Get().GetWidgetStyle<FCheckBoxStyle>("PivotTool.ToggleButtonCheckbox"))
					.OnCheckStateChanged(this, &SPivotPreset::OnSinglePresetModeCheckStateChanged)
					.IsChecked(this, &SPivotPreset::IsSinglePresetMode)
					.Visibility(this, &SPivotPreset::GetOptionsVisibility)
					.ToolTipText(LOCTEXT("SinglePresetModeToolTip", "Toggles whether display only one preset widget\n (Use mouse wheel to change preset)"))
					.Content()
					[
						SNew(SBox).VAlign(VAlign_Center).HAlign(HAlign_Center).Padding(FMargin(0, 0))
						[
							SNew(STextBlock)
							.Text(this, &SPivotPreset::GetSinglePresetModeText)
							.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
						]
					]
				] //end of Text Mode Checkbox
			]
#endif
		] // end of SVertecalBox::Slot() Options

		// Presets
		+ SVerticalBox::Slot()
		.Padding(0, 0)
		.AutoHeight()
		.HAlign(HAlign_Center)
		[
			CreatePresetUI()
		]
	];
}

void SPivotPreset::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	if (WidthLastFrame != AllottedGeometry.Size.X)
	{
		WidthLastFrame = AllottedGeometry.Size.X;

		TextUIWrapBox->SetWrapWidth(WidthLastFrame);
		PresetOptionsWrapBox->SetWrapWidth(WidthLastFrame);
		PresetWrapBox->SetWrapWidth(WidthLastFrame);
		PresetSubWrapBox1->SetWrapWidth(WidthLastFrame);
		PresetSubWrapBox2->SetWrapWidth(WidthLastFrame);
	}
	if (!FMath::IsNearlyEqual(OldUserSpecifiedScale, UserSpecifiedScale))
	{
		SaveUISetting();
		OldUserSpecifiedScale = UserSpecifiedScale;
	}
}

FReply SPivotPreset::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.IsControlDown())
	{
		const float ZoomLevelDelta = MouseEvent.GetWheelDelta() / 10.f;
		const float Scale = UserSpecifiedScale + ZoomLevelDelta;
		UserSpecifiedScale = FMath::Clamp(Scale, PivotPresetConstants::MinPresetScale, PivotPresetConstants::MaxPresetScale);
	}
	else
	{
		if (bSinglePresetUI)
		{
			const int32 Delta = FMath::TruncToInt(FMath::RoundFromZero(MouseEvent.GetWheelDelta()));
			SinglePresetIndex += Delta;
			if (SinglePresetIndex > 3)
			{
				SinglePresetIndex = 0;
			}
			else if (SinglePresetIndex < 0)
			{
				SinglePresetIndex = 3;
			}
		}
	}
	return FReply::Handled();
}

ECheckBoxState SPivotPreset::IsOptionsDisplayed() const
{
	return bOptionsDisplayed ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

ECheckBoxState SPivotPreset::IsAutoSave() const
{
	return bAutoSave ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

ECheckBoxState SPivotPreset::IsGroupMode() const
{
	return bGroupMode ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

ECheckBoxState SPivotPreset::IsLastSelectedMode() const
{
	return bLastSelectedMode ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

ECheckBoxState SPivotPreset::IsVertexMode() const
{
	return bVertexMode ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

ECheckBoxState SPivotPreset::IsChildrenMode() const
{
	return bChildrenMode ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

ECheckBoxState SPivotPreset::IsTextMode() const
{
	return bTextMode ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

ECheckBoxState SPivotPreset::IsSinglePresetMode() const
{
	return bSinglePresetUI ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

FText SPivotPreset::GetOptionDisplayText() const
{
	return bOptionsDisplayed ? LOCTEXT(" < ", " < ") : LOCTEXT(" > ", " > ");
}

EVisibility SPivotPreset::GetOptionsVisibility() const
{
	return bOptionsDisplayed ? EVisibility::Visible : EVisibility::Collapsed;
}

float SPivotPreset::GetUserSpecifiedScale() const
{
	return UserSpecifiedScale;
}

void SPivotPreset::OnOptionsDisplayedCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bOptionsDisplayed = NewCHeckedState == ECheckBoxState::Checked;
	SaveUISetting();
}

void SPivotPreset::OnAutoSaveCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bAutoSave = NewCHeckedState == ECheckBoxState::Checked;
	SaveUISetting();
}

void SPivotPreset::OnGroupModeCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bGroupMode = NewCHeckedState == ECheckBoxState::Checked;
	if (bGroupMode)
	{
		bVertexMode = false;
		bChildrenMode = false;
		bLastSelectedMode = false;
	}
	SaveUISetting();
}

void SPivotPreset::OnLastSelectedModeCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bLastSelectedMode = NewCHeckedState == ECheckBoxState::Checked;
	if (bLastSelectedMode)
	{
		bGroupMode = false;
	}
	SaveUISetting();
}

void SPivotPreset::OnVertexModeCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bVertexMode = NewCHeckedState == ECheckBoxState::Checked;
	if (bVertexMode)
	{
		bGroupMode = false;
		bChildrenMode = false;
	}
	SaveUISetting();
}

void SPivotPreset::OnChildrenModeCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bChildrenMode = NewCHeckedState == ECheckBoxState::Checked;
	if (bChildrenMode)
	{
		bVertexMode = false;
		bGroupMode = false;
	}
	SaveUISetting();
}

void SPivotPreset::OnTextModeCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bTextMode = NewCHeckedState == ECheckBoxState::Checked;
	SaveUISetting();

	TextUI->SetVisibility(bTextMode ? EVisibility::Visible : EVisibility::Collapsed);
	GraphicUI->SetVisibility(!bTextMode ? EVisibility::Visible : EVisibility::Collapsed);
}

void SPivotPreset::OnSinglePresetModeCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bSinglePresetUI = NewCHeckedState == ECheckBoxState::Checked;
	if (bTextMode && bSinglePresetUI)
	{
		OnTextModeCheckStateChanged(ECheckBoxState::Unchecked);
	}
	SaveUISetting();
}

FText SPivotPreset::GetAutoSaveText() const
{
	if (WidthLastFrame > PivotPresetConstants::TigherModeThreshold)
		return  LOCTEXT("AutoSave", "Auto Save");
	else
		return LOCTEXT("AutoSave.Tight", "AutoSave");
}

FText SPivotPreset::GetGroupModeText() const
{
	if (WidthLastFrame > PivotPresetConstants::TigherModeThreshold)
		return LOCTEXT("GroupMode", "Group Mode");
	else
		return LOCTEXT("GroupMode.Tight", "Group");
}

FText SPivotPreset::GetLastSelectedModeText() const
{
	if (WidthLastFrame > PivotPresetConstants::TigherModeThreshold)
		return LOCTEXT("LastSelected", "Last Selected Mode");
	else
		return LOCTEXT("LastSelected.Tight", "LastSelected");
}

FText SPivotPreset::GetVertexModeText() const
{
	if (WidthLastFrame > PivotPresetConstants::TigherModeThreshold)
		return LOCTEXT("VertexMode", "Vertex Mode");
	else
		return LOCTEXT("VertexMode.Tight", "Vertex");
}

FText SPivotPreset::GetChildrenModeText() const
{
	if (WidthLastFrame > PivotPresetConstants::TigherModeThreshold)
		return LOCTEXT("ChildrenMode", "Children Mode");
	else
		return LOCTEXT("ChildrenMode.Tight", "Children");
}

FText SPivotPreset::GetTextModeText() const
{
	if (WidthLastFrame > PivotPresetConstants::TigherModeThreshold)
		return LOCTEXT("TextUI", "Text UI");
	else
		return LOCTEXT("TextUI.Tight", "Text");
}

FText SPivotPreset::GetSinglePresetModeText() const
{
	if (WidthLastFrame > PivotPresetConstants::TigherModeThreshold)
		return LOCTEXT("SinglePresetI", "Single Mode");
	else
		return LOCTEXT("SinglePresetUI.Tight", "Single");
}

EVisibility SPivotPreset::GetPresetWidgetVisibility(EPivotToolPresetType InPresetType) const
{
	if (!bSinglePresetUI)
	{
		return EVisibility::Visible;
	}

	return (InPresetType == (EPivotToolPresetType)SinglePresetIndex) ? EVisibility::Visible : EVisibility::Collapsed;
}

FReply SPivotPreset::OnClickPresetButton(EPivotPreset InPivotPreset)
{
	PIVOTTOOL_LOG(Display, TEXT("SPivotPreset::OnClickPresetButton: %d"), (int32)InPivotPreset);

	if (OnSelected.IsBound())
	{
		OnSelected.Execute(InPivotPreset);
	}

	return FReply::Handled();
}

void SPivotPreset::OnHoverPresetButton(EPivotPreset InPivotPreset)
{
	PIVOTTOOL_LOG(Display, TEXT("SPivotPreset::OnHoverPresetButton: %d"), (int32)InPivotPreset);

	if (OnHovered.IsBound())
	{
		OnHovered.Execute(InPivotPreset);
	}
}

void SPivotPreset::OnUnhoverPresetButton(EPivotPreset InPivotPreset)
{
	PIVOTTOOL_LOG(Display, TEXT("SPivotPreset::OnUnhoverPresetButton: %d"), (int32)InPivotPreset);

	if (OnUnhovered.IsBound())
	{
		OnUnhovered.Execute(InPivotPreset);
	}
}

TSharedRef<SWidget> SPivotPreset::CreatePresetUI()
{
	TextUI = CreatePresetTextUI();
	GraphicUI = CreatePresetGraphicUI();

	TextUI->SetVisibility(bTextMode ? EVisibility::Visible : EVisibility::Collapsed);
	GraphicUI->SetVisibility(!bTextMode ? EVisibility::Visible : EVisibility::Collapsed);

	return SNew(SHorizontalBox)
		+ SHorizontalBox::Slot().FillWidth(1.f)
		[
			TextUI.ToSharedRef()
		]
		+ SHorizontalBox::Slot().FillWidth(1.f)
		[
			GraphicUI.ToSharedRef()
		];
}

TSharedRef<SWidget> SPivotPreset::CreatePresetTextUI()
{
	const FMargin TextButtonPadding(2, 4, 2, 0);

	return SAssignNew(TextUIWrapBox, SWrapBox)

		+ SWrapBox::Slot()
		[
			SNew(SHorizontalBox)
			// Bonding Box Center
			+ SHorizontalBox::Slot().AutoWidth().Padding(TextButtonPadding)
			[
				CreatePresetButtons(EPivotToolPresetType::PresetType_BoundCenter, /*bCreateTextButtons*/ true)
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(TextButtonPadding)[SNew(SImage).Image(FPivotToolStyle::Get().GetBrush("PivotTool.DividingLine"))]

			// Center
			+ SHorizontalBox::Slot().AutoWidth().Padding(TextButtonPadding)
			[
				CreatePresetButtons(EPivotToolPresetType::PresetType_Center, /*bCreateTextButtons*/ true)
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(TextButtonPadding)[SNew(SImage).Image(FPivotToolStyle::Get().GetBrush("PivotTool.DividingLine"))]
		]

		+ SWrapBox::Slot()
		[
			SNew(SHorizontalBox)
			// Corner
			+ SHorizontalBox::Slot().AutoWidth().Padding(TextButtonPadding)
			[
				CreatePresetButtons(EPivotToolPresetType::PresetType_Corner, /*bCreateTextButtons*/ true)
			]
			+ SHorizontalBox::Slot().AutoWidth().Padding(TextButtonPadding)[SNew(SImage).Image(FPivotToolStyle::Get().GetBrush("PivotTool.DividingLine"))]
		]

		+ SWrapBox::Slot()
		[
			SNew(SHorizontalBox)
			// Edge
			+ SHorizontalBox::Slot().AutoWidth().Padding(TextButtonPadding)
			[
				CreatePresetButtons(EPivotToolPresetType::PresetType_Edge, /*bCreateTextButtons*/ true)
			]
		];
}

TSharedRef<SWidget> SPivotPreset::CreatePresetGraphicUI()
{
	return SAssignNew(PresetWrapBox, SWrapBox)

	+ SWrapBox::Slot()
	[
		SAssignNew(PresetSubWrapBox1, SWrapBox)
		// Box Center
		+ SWrapBox::Slot()
		[
			CreatePresetOverlay(EPivotToolPresetType::PresetType_BoundCenter)
		]

		// Center
		+ SWrapBox::Slot()
		[
			CreatePresetOverlay(EPivotToolPresetType::PresetType_Center)
		]
	]

	+ SWrapBox::Slot()
	[
		SAssignNew(PresetSubWrapBox2, SWrapBox)
		// Corner
		+ SWrapBox::Slot()
		[
			CreatePresetOverlay(EPivotToolPresetType::PresetType_Corner)
		]

		// Edge
		+ SWrapBox::Slot()
		[
			CreatePresetOverlay(EPivotToolPresetType::PresetType_Edge)
		]
	];
}

TSharedRef<SWidget> SPivotPreset::CreatePresetOverlay(EPivotToolPresetType InPresetType)
{
	return SNew(SScaleBox)
 	.Stretch(EStretch::UserSpecified)
	.UserSpecifiedScale(this, &SPivotPreset::GetUserSpecifiedScale)
	.Visibility(this, &SPivotPreset::GetPresetWidgetVisibility, InPresetType)
	[
		SNew(SOverlay)

		// Background
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(GetPivotPresetBackgroundBrush(InPresetType))
		]

		// Widgets
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			CreatePresetButtons(InPresetType, /*bCreateTextButtons*/ false)
		]
	];
}

const FSlateBrush* SPivotPreset::GetPivotPresetBackgroundBrush(EPivotToolPresetType InPresetType) const
{
	switch (InPresetType)
	{
	case EPivotToolPresetType::PresetType_Corner:
		return FPivotToolStyle::Get().GetBrush("PivotTool.PivotPresetBackground.Corner");
	case EPivotToolPresetType::PresetType_Edge:
		return FPivotToolStyle::Get().GetBrush("PivotTool.PivotPresetBackground.Edge");
	case EPivotToolPresetType::PresetType_Center:
		return FPivotToolStyle::Get().GetBrush("PivotTool.PivotPresetBackground.Center");
	case EPivotToolPresetType::PresetType_BoundCenter:
	default:
		return FPivotToolStyle::Get().GetBrush("PivotTool.PivotPresetBackground.BoundCenter");
	}
}

const FButtonStyle*  SPivotPreset::GetPivotPresetButtonStyle(EPivotToolPresetType InPresetType, EPivotPreset InPreset) const
{
	switch (InPresetType)
	{
	case EPivotToolPresetType::PresetType_Corner:
		return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotCorner");
	case EPivotToolPresetType::PresetType_Edge:
		if (InPreset == EPivotPreset::BoundingBoxEdgeTop1)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Top1");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeTop2)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Top2");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeTop3)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Top3");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeTop4)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Top4");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeMid1)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Mid1");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeMid2)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Mid2");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeMid3)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Mid3");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeMid4)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Mid4");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeBottom1)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Bottom1");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeBottom2)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Bottom2");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeBottom3)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Bottom3");
		}
		if (InPreset == EPivotPreset::BoundingBoxEdgeBottom4)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotEdge.Bottom4");
		}
		break;
	case EPivotToolPresetType::PresetType_Center:
		if (InPreset == EPivotPreset::BoundingBoxCenterTop)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotCenterTop");
		}
		if (InPreset == EPivotPreset::BoundingBoxCenterBottom)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotCenterBottom");
		}
		if (InPreset == EPivotPreset::BoundingBoxCenterLeft)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotCenterLeft");
		}
		if (InPreset == EPivotPreset::BoundingBoxCenterRight)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotCenterRight");
		}
		if (InPreset == EPivotPreset::BoundingBoxCenterFront)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotCenterFront");
		}
		if (InPreset == EPivotPreset::BoundingBoxCenterBack)
		{
			return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotCenterBack");
		}
		break;
	case EPivotToolPresetType::PresetType_BoundCenter:
	default:
		return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotBoundCenter");
	}
	return &FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.PivotBoundCenter");
}

FVector2D SPivotPreset::GetPivotPresetButtonSize(EPivotToolPresetType InPresetType, EPivotPreset InPreset /*= EPivotPreset::MAX*/) const
{
	switch (InPresetType)
	{
	case EPivotToolPresetType::PresetType_Edge:
		return GetPivotPresetButtonStyle(InPresetType, InPreset)->Normal.ImageSize;
	case EPivotToolPresetType::PresetType_Corner:
	case EPivotToolPresetType::PresetType_Center:
	case EPivotToolPresetType::PresetType_BoundCenter:
	default:
		return FVector2D(30.f, 30.f);
	}
}

FText SPivotPreset::GetPivotPresetAlphaButtonTexture(EPivotToolPresetType InPresetType, EPivotPreset InPreset /*= EPivotPreset::MAX*/) const
{
	if (InPresetType == EPivotToolPresetType::PresetType_Edge)
	{
		switch (InPreset)
		{
		case EPivotPreset::BoundingBoxEdgeTop1:
			return FText::FromString(TEXT("button_pivot_edge_top1"));
		case EPivotPreset::BoundingBoxEdgeTop2:
			return FText::FromString(TEXT("button_pivot_edge_top2"));
		case EPivotPreset::BoundingBoxEdgeTop3:
			return FText::FromString(TEXT("button_pivot_edge_top3"));
		case EPivotPreset::BoundingBoxEdgeTop4:
			return FText::FromString(TEXT("button_pivot_edge_top4"));
		case EPivotPreset::BoundingBoxEdgeMid1:
			return FText::FromString(TEXT("button_pivot_edge_mid1"));
		case EPivotPreset::BoundingBoxEdgeMid2:
			return FText::FromString(TEXT("button_pivot_edge_mid2"));
		case EPivotPreset::BoundingBoxEdgeMid3:
			return FText::FromString(TEXT("button_pivot_edge_mid3"));
		case EPivotPreset::BoundingBoxEdgeMid4:
			return FText::FromString(TEXT("button_pivot_edge_mid4"));
		case EPivotPreset::BoundingBoxEdgeBottom1:
			return FText::FromString(TEXT("button_pivot_edge_bottom1"));
		case EPivotPreset::BoundingBoxEdgeBottom2:
			return FText::FromString(TEXT("button_pivot_edge_bottom2"));
		case EPivotPreset::BoundingBoxEdgeBottom3:
			return FText::FromString(TEXT("button_pivot_edge_bottom3"));
		case EPivotPreset::BoundingBoxEdgeBottom4:
			return FText::FromString(TEXT("button_pivot_edge_bottom4"));
		}
	}
	return FText::GetEmpty();
}

FText SPivotPreset::GetPivotPresetTooltip(EPivotPreset InPreset) const
{
	switch (InPreset)
	{
	case EPivotPreset::BoundingBoxCenter:
		return LOCTEXT("BoundingBoxCenter", "Bounding Box Center");

	case EPivotPreset::BoundingBoxCenterTop:
		return LOCTEXT("BoundingBoxCenterTop", "Center Top");
	case EPivotPreset::BoundingBoxCenterBottom:
		return LOCTEXT("BoundingBoxCenterBottom", "Center Bottom");
	case EPivotPreset::BoundingBoxCenterLeft:
		return LOCTEXT("BoundingBoxCenterLeft", "Center Left");
	case EPivotPreset::BoundingBoxCenterRight:
		return LOCTEXT("BoundingBoxCenterRight", "Center Right");
	case EPivotPreset::BoundingBoxCenterFront:
		return LOCTEXT("BoundingBoxCenterFront", "Center Front");
	case EPivotPreset::BoundingBoxCenterBack:
		return LOCTEXT("BoundingBoxCenterBack", "Center Back");

	case EPivotPreset::BoundingBoxCornerTop1:
		return LOCTEXT("BoundingBoxCornerTop1", "Top Corner 1");
	case EPivotPreset::BoundingBoxCornerTop2:
		return LOCTEXT("BoundingBoxCornerTop2", "Top Corner 2");
	case EPivotPreset::BoundingBoxCornerTop3:
		return LOCTEXT("BoundingBoxCornerTop3", "Top Corner 3");
	case EPivotPreset::BoundingBoxCornerTop4:
		return LOCTEXT("BoundingBoxCornerTop4", "Top Corner 4");
	case EPivotPreset::BoundingBoxCornerBottom1:
		return LOCTEXT("BoundingBoxCornerBottom1", "Bottom Corner 1");
	case EPivotPreset::BoundingBoxCornerBottom2:
		return LOCTEXT("BoundingBoxCornerBottom2", "Bottom Corner 3");
	case EPivotPreset::BoundingBoxCornerBottom3:
		return LOCTEXT("BoundingBoxCornerBottom3", "Bottom Corner 3");
	case EPivotPreset::BoundingBoxCornerBottom4:
		return LOCTEXT("BoundingBoxCornerBottom4", "Bottom Corner 4");

	case EPivotPreset::BoundingBoxEdgeTop1:
		return LOCTEXT("BoundingBoxEdgeTop1", "Top Edge 1");
	case EPivotPreset::BoundingBoxEdgeTop2:
		return LOCTEXT("BoundingBoxEdgeTop2", "Top Edge 2");
	case EPivotPreset::BoundingBoxEdgeTop3:
		return LOCTEXT("BoundingBoxEdgeTop3", "Top Edge 3");
	case EPivotPreset::BoundingBoxEdgeTop4:
		return LOCTEXT("BoundingBoxEdgeTop4", "Top Edge 4");
	case EPivotPreset::BoundingBoxEdgeMid1:
		return LOCTEXT("BoundingBoxEdgeMid1", "Middle Edge 1");
	case EPivotPreset::BoundingBoxEdgeMid2:
		return LOCTEXT("BoundingBoxEdgeMid2", "Middle Edge 2");
	case EPivotPreset::BoundingBoxEdgeMid3:
		return LOCTEXT("BoundingBoxEdgeMid3", "Middle Edge 3");
	case EPivotPreset::BoundingBoxEdgeMid4:
		return LOCTEXT("BoundingBoxEdgeMid4", "Middle Edge 4");
	case EPivotPreset::BoundingBoxEdgeBottom1:
		return LOCTEXT("BoundingBoxEdgeBottom1", "Bottom Edge 1");
	case EPivotPreset::BoundingBoxEdgeBottom2:
		return LOCTEXT("BoundingBoxEdgeBottom2", "Bottom Edge 2");
	case EPivotPreset::BoundingBoxEdgeBottom3:
		return LOCTEXT("BoundingBoxEdgeBottom3", "Bottom Edge 3");
	case EPivotPreset::BoundingBoxEdgeBottom4:
		return LOCTEXT("BoundingBoxEdgeBottom4", "Bottom Edge 4");
	default:
		return FText::GetEmpty();
	}
	return FText::GetEmpty();
}

void SPivotPreset::SaveUISetting()
{
	GConfig->SetBool(TEXT("PivotTool"), TEXT("bOptionsDisplayed"), bOptionsDisplayed, GEditorPerProjectIni);

	GConfig->SetBool(TEXT("PivotTool"), TEXT("bAutoSave"), bAutoSave, GEditorPerProjectIni);
	GConfig->SetBool(TEXT("PivotTool"), TEXT("bGroupMode"), bGroupMode, GEditorPerProjectIni);
	GConfig->SetBool(TEXT("PivotTool"), TEXT("bLastSelectedMode"), bLastSelectedMode, GEditorPerProjectIni);
	GConfig->SetBool(TEXT("PivotTool"), TEXT("bVertexMode"), bVertexMode, GEditorPerProjectIni);
	GConfig->SetBool(TEXT("PivotTool"), TEXT("bChildrenMode"), bChildrenMode, GEditorPerProjectIni);
	GConfig->SetBool(TEXT("PivotTool"), TEXT("bTextMode"), bTextMode, GEditorPerProjectIni);
	GConfig->SetBool(TEXT("PivotTool"), TEXT("bSinglePresetUI"), bSinglePresetUI, GEditorPerProjectIni);
	GConfig->SetInt(TEXT("PivotTool"), TEXT("SinglePresetIndex"), SinglePresetIndex, GEditorPerProjectIni);

	GConfig->SetFloat(TEXT("PivotTool"), TEXT("UserSpecifiedScale"), UserSpecifiedScale, GEditorPerProjectIni);
}

void SPivotPreset::LoadUISetting()
{
	GConfig->GetBool(TEXT("PivotTool"), TEXT("bOptionsDisplayed"), bOptionsDisplayed, GEditorPerProjectIni);

	GConfig->GetBool(TEXT("PivotTool"), TEXT("bAutoSave"), bAutoSave, GEditorPerProjectIni);
	GConfig->GetBool(TEXT("PivotTool"), TEXT("bGroupMode"), bGroupMode, GEditorPerProjectIni);
	GConfig->GetBool(TEXT("PivotTool"), TEXT("bLastSelectedMode"), bLastSelectedMode, GEditorPerProjectIni);
	GConfig->GetBool(TEXT("PivotTool"), TEXT("bVertexMode"), bVertexMode, GEditorPerProjectIni);
	GConfig->GetBool(TEXT("PivotTool"), TEXT("bChildrenMode"), bChildrenMode, GEditorPerProjectIni);
	GConfig->GetBool(TEXT("PivotTool"), TEXT("bTextMode"), bTextMode, GEditorPerProjectIni);
	GConfig->GetBool(TEXT("PivotTool"), TEXT("bSinglePresetUI"), bSinglePresetUI, GEditorPerProjectIni);
	GConfig->GetInt(TEXT("PivotTool"), TEXT("SinglePresetIndex"), SinglePresetIndex, GEditorPerProjectIni);

	SinglePresetIndex = FMath::Clamp(SinglePresetIndex, 0, 3);

	GConfig->GetFloat(TEXT("PivotTool"), TEXT("UserSpecifiedScale"), UserSpecifiedScale, GEditorPerProjectIni);
	UserSpecifiedScale = FMath::Clamp(UserSpecifiedScale, PivotPresetConstants::MinPresetScale, PivotPresetConstants::MaxPresetScale);
	OldUserSpecifiedScale = UserSpecifiedScale;
}

TSharedRef<SWidget> SPivotPreset::CreatePresetButtons(EPivotToolPresetType InPresetType, bool bCreateTextButtons)
{
	int32 Start = 0;
	int32 End = 0;

	TArray<EPivotPreset> EdgeReOrder({
		EPivotPreset::BoundingBoxEdgeBottom2,
		EPivotPreset::BoundingBoxEdgeBottom1,
		EPivotPreset::BoundingBoxEdgeMid2,
		EPivotPreset::BoundingBoxEdgeTop2,
		EPivotPreset::BoundingBoxEdgeMid3,
		EPivotPreset::BoundingBoxEdgeTop1,
		EPivotPreset::BoundingBoxEdgeTop3,
		EPivotPreset::BoundingBoxEdgeBottom3,
		EPivotPreset::BoundingBoxEdgeBottom4,
		EPivotPreset::BoundingBoxEdgeMid1,
		EPivotPreset::BoundingBoxEdgeMid4,
		EPivotPreset::BoundingBoxEdgeTop4,
	});

	switch (InPresetType)
	{
	case EPivotToolPresetType::PresetType_Center:
		Start = (int32)EPivotPreset::BoundingBoxCenterTop; 
		End = (int32)EPivotPreset::BoundingBoxCenterBack;
		break;
	case EPivotToolPresetType::PresetType_Corner:
		Start = (int32)EPivotPreset::BoundingBoxCornerTop1;
		End = (int32)EPivotPreset::BoundingBoxCornerBottom4;
		break;
	case EPivotToolPresetType::PresetType_Edge:
		Start = (int32)EPivotPreset::BoundingBoxEdgeTop1;
		End = (int32)EPivotPreset::BoundingBoxEdgeBottom4;
	case EPivotToolPresetType::PresetType_BoundCenter:
	default:
		break;
	}

	if (bCreateTextButtons)
	{
		TSharedRef<SHorizontalBox> ButtonsBox = SNew(SHorizontalBox);
		for (int32 EnumIndex = Start; EnumIndex <= End; ++EnumIndex)
		{
			ButtonsBox->AddSlot()
				.AutoWidth()
				.Padding(1, 0)
				[
					SNew(SButton)
					.ClickMethod(EButtonClickMethod::MouseDown)
					.ButtonStyle(FPivotToolStyle::Get(), "PivotTool.ButtonStyle.Normal")
					.OnClicked(this, &SPivotPreset::OnClickPresetButton, EPivotPreset(EnumIndex))
					.ToolTipText(this, &SPivotPreset::GetPivotPresetTooltip, EPivotPreset(EnumIndex))
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText.Black")
						.Text(UEnum::GetDisplayValueAsText(TEXT("PivotTool.EPivotPreset"), EPivotPreset(EnumIndex)))
						.Justification(ETextJustify::Center)
					]
				];
		}
		return ButtonsBox;
	}
	else
	{
		TSharedRef<SCanvas> Canvas = SNew(SCanvas);

		const float BGImgSize = 160.f;
		const float BGExpectedSize = 160.f;
		for (int32 EnumIndex = Start; EnumIndex <=End; ++EnumIndex)
		{
			if (InPresetType == EPivotToolPresetType::PresetType_Edge)
			{
				EPivotPreset ReOrderedPreset = EdgeReOrder[EnumIndex - Start]; 
				const FVector2D ButtonSize = GetPivotPresetButtonSize(InPresetType, ReOrderedPreset);

				Canvas->AddSlot()
					.Position((PivotPoints[(int32)ReOrderedPreset] - ButtonSize/2) * (BGImgSize / BGExpectedSize))
					.Size(ButtonSize)
					[
						SNew(SAlphaButton)
						.ClickMethod(EButtonClickMethod::MouseDown)
						.ButtonStyle(GetPivotPresetButtonStyle(InPresetType, ReOrderedPreset))
						.ToolTipText(this, &SPivotPreset::GetPivotPresetTooltip, EPivotPreset(EnumIndex))
						.OnClicked(this, &SPivotPreset::OnClickPresetButton, ReOrderedPreset)
						.OnHovered(this, &SPivotPreset::OnHoverPresetButton, ReOrderedPreset)
						.OnUnhovered(this, &SPivotPreset::OnUnhoverPresetButton, ReOrderedPreset)
					];
			}
			else
			{
				const FVector2D ButtonSize = GetPivotPresetButtonSize(InPresetType, EPivotPreset(EnumIndex));
				Canvas->AddSlot()
					.Position((PivotPoints[EnumIndex] - FVector2D(15, 15)) * (BGImgSize / BGExpectedSize))
					.Size(ButtonSize)
					[
						SNew(SButton)
						.ClickMethod(EButtonClickMethod::MouseDown)
						.ButtonStyle(GetPivotPresetButtonStyle(InPresetType, EPivotPreset(EnumIndex)))
						.ToolTipText(this, &SPivotPreset::GetPivotPresetTooltip, EPivotPreset(EnumIndex))
						.OnClicked(this, &SPivotPreset::OnClickPresetButton, EPivotPreset(EnumIndex))
						.OnHovered(this, &SPivotPreset::OnHoverPresetButton, EPivotPreset(EnumIndex))
						.OnUnhovered(this, &SPivotPreset::OnUnhoverPresetButton, EPivotPreset(EnumIndex))
					];
			}
		}

		return Canvas;
	}
}


#undef LOCTEXT_NAMESPACE
