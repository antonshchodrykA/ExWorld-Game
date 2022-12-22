// Copyright 2017-2019 marynate. All Rights Reserved.

#include "SPivotAlign.h"
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
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/Images/SImage.h"

#define LOCTEXT_NAMESPACE "SPivotAlign"

namespace PivotAlignConstants
{
	const float HideAlignActorTextWidth = 270.f;
}

SPivotAlign::SPivotAlign()
	:WidthLastFrame(0.f)
{
}

void SPivotAlign::Construct(const FArguments& InArgs)
{
	WidthLastFrame = 0.f;

	const FMargin OptionMargin = FMargin(6, 2, 6, 0);
	const float ButtonContentPadding = 1.f;
	const float ButtonTextMinDesiredWidth = 20.f;
	const FName DefautlButtonStyle("PivotTool.ButtonStyle.Round.Black");
	const FName ColorXButtonStyle("PivotTool.ButtonStyle.Round.ColorX");
	const FName ColorYButtonStyle("PivotTool.ButtonStyle.Round.ColorY");
	const FName ColorZButtonStyle("PivotTool.ButtonStyle.Round.ColorZ");

	struct Local
	{
		static void AddButton(TSharedPtr<SHorizontalBox> HorizontalBox, const FText& ButtonName, const FName& ButtonStyle, const FText& ToolTip, const FOnClicked& OnClick, float ButtonContentPadding = 2.f, float ButtonTextMinDesiredWidth = 15.f)
		{
			HorizontalBox->AddSlot().Padding(2).FillWidth(1.f).HAlign(HAlign_Center)
			[
				SNew(SButton)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.ContentPadding(ButtonContentPadding)
				.ButtonStyle(&FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>(ButtonStyle))
				.OnClicked(OnClick)
				.ToolTipText(ToolTip)
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText")
					.Text(ButtonName)
					.MinDesiredWidth(ButtonTextMinDesiredWidth)
					.Justification(ETextJustify::Center)
				]
			];
		}
	};

	TSharedPtr<SHorizontalBox> ButtonBox1;
	TSharedPtr<SHorizontalBox> ButtonBox2;
	TSharedPtr<SHorizontalBox> ButtonBox3;
	TSharedPtr<SHorizontalBox> ButtonBox4;

	ChildSlot
	[
		SAssignNew(AlignBox, SWrapBox)
		.InnerSlotPadding({ 4.f, 2.f })
		+ SWrapBox::Slot().HAlign(HAlign_Center)[SAssignNew(ButtonBox1, SHorizontalBox)]
		+ SWrapBox::Slot().HAlign(HAlign_Center)[SAssignNew(ButtonBox2, SHorizontalBox)]
		+ SWrapBox::Slot().HAlign(HAlign_Center)[SAssignNew(ButtonBox3, SHorizontalBox)]
		+ SWrapBox::Slot().HAlign(HAlign_Center)[SAssignNew(ButtonBox4, SHorizontalBox)]
	];

	ButtonBox1->AddSlot().AutoWidth().Padding(2, 2, 2, 2).HAlign(HAlign_Center).VAlign(VAlign_Center)
	[
		SNew(STextBlock)
		.Text(this, &SPivotAlign::GetAlignActorsText)
		.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText.Gray")
		.Justification(ETextJustify::Center)
	];

	Local::AddButton(ButtonBox1,
		LOCTEXT("All", "All"),
		DefautlButtonStyle,
		LOCTEXT("AlignActorsButtonTooltip", "Align selected actors to last selected actor's location"),
		FOnClicked::CreateSP(this, &SPivotAlign::OnAlignSelectedActorsLocButtonClicked),
		ButtonContentPadding, ButtonTextMinDesiredWidth);

	Local::AddButton(ButtonBox2,
		LOCTEXT("X", "X"),
		ColorXButtonStyle,
		LOCTEXT("AlignActorsXButtonTooltip", "Align selected actors' max X location"),
		FOnClicked::CreateSP(this, &SPivotAlign::OnAlignSelectedActorsLocXButtonClicked),
		ButtonContentPadding, ButtonTextMinDesiredWidth);

	Local::AddButton(ButtonBox2,
		LOCTEXT("-X", "-X"),
		ColorXButtonStyle,
		LOCTEXT("AlignActorsMirrorXButtonTooltip", "Align selected actors' min X location"),
		FOnClicked::CreateSP(this, &SPivotAlign::OnAlignSelectedActorsLocMirrorXButtonClicked),
		ButtonContentPadding, ButtonTextMinDesiredWidth);

	Local::AddButton(ButtonBox3,
		LOCTEXT("Y", "Y"),
		ColorYButtonStyle,
		LOCTEXT("AlignActorsYButtonTooltip", "Align selected actors' max Y location"),
		FOnClicked::CreateSP(this, &SPivotAlign::OnAlignSelectedActorsLocYButtonClicked),
		ButtonContentPadding, ButtonTextMinDesiredWidth);
		
	Local::AddButton(ButtonBox3,
		LOCTEXT("-Y", "-Y"),
		ColorYButtonStyle,
		LOCTEXT("AlignActorsMirrorYButtonTooltip", "Align selected actors' min Y location"),
		FOnClicked::CreateSP(this, &SPivotAlign::OnAlignSelectedActorsLocMirrorYButtonClicked),
		ButtonContentPadding, ButtonTextMinDesiredWidth);

	Local::AddButton(ButtonBox4,
		LOCTEXT("Z", "Z"),
		ColorZButtonStyle,
		LOCTEXT("AlignActorsZButtonTooltip", "Align selected actors' max Z location"),
		FOnClicked::CreateSP(this, &SPivotAlign::OnAlignSelectedActorsLocZButtonClicked),
		ButtonContentPadding, ButtonTextMinDesiredWidth);

	Local::AddButton(ButtonBox4,
		LOCTEXT("-Z", "-Z"),
		ColorZButtonStyle,
		LOCTEXT("AlignActorsMirrorZButtonTooltip", "Align selected actors' min Z location"),
		FOnClicked::CreateSP(this, &SPivotAlign::OnAlignSelectedActorsLocMirrorZButtonClicked),
		ButtonContentPadding, ButtonTextMinDesiredWidth);
}

void SPivotAlign::SetWrapWidth(float InWrapWidth)
{
	AlignBox->SetWrapWidth(InWrapWidth);

	WidthLastFrame = InWrapWidth;
}

FText SPivotAlign::GetAlignActorsText() const
{
	const bool bHideAlignActorText = WidthLastFrame < PivotAlignConstants::HideAlignActorTextWidth ? true : false;
	return bHideAlignActorText ? LOCTEXT("AlignActors.Tight:", "Align:") : LOCTEXT("AlignActors:", "Align Actors:");
}

FReply SPivotAlign::OnAlignSelectedActorsLocButtonClicked()
{
	FPivotToolUtil::AlignToLastSelectedActorsWithPivotOffset(ECoordSystem::COORD_World, EAxis::None);
	return FReply::Handled();
}

FReply SPivotAlign::OnAlignSelectedActorsLocXButtonClicked()
{
	DoAlignSelectedActorsLoc(EAxis::X, /*bMirrored*/false);
	return FReply::Handled();
}

FReply SPivotAlign::OnAlignSelectedActorsLocYButtonClicked()
{
	DoAlignSelectedActorsLoc(EAxis::Y, /*bMirrored*/false);
	return FReply::Handled();
}

FReply SPivotAlign::OnAlignSelectedActorsLocZButtonClicked()
{
	DoAlignSelectedActorsLoc(EAxis::Z, /*bMirrored*/false);
	return FReply::Handled();
}

FReply SPivotAlign::OnAlignSelectedActorsLocMirrorXButtonClicked()
{
	DoAlignSelectedActorsLoc(EAxis::X, /*bMirrored*/true);
	return FReply::Handled();
}

FReply SPivotAlign::OnAlignSelectedActorsLocMirrorYButtonClicked()
{
	DoAlignSelectedActorsLoc(EAxis::Y, /*bMirrored*/true);
	return FReply::Handled();
}

FReply SPivotAlign::OnAlignSelectedActorsLocMirrorZButtonClicked()
{
	DoAlignSelectedActorsLoc(EAxis::Z, /*bMirrored*/true);
	return FReply::Handled();
}

void SPivotAlign::DoAlignSelectedActorsLoc(EAxis::Type InAxis, bool bMirrored/* = false*/) const
{
	ECoordSystem CoordSystem = GLevelEditorModeTools().GetCoordSystem();	
	FPivotToolUtil::AlignSelectedActorsWithPivotOffset(CoordSystem, InAxis, bMirrored);
}

FReply SPivotAlign::OnAlignSelectedActorsRotButtonClicked()
{
	FPivotToolUtil::AlignSelectionRotation(EAxis::None);
	return FReply::Handled();
}

FReply SPivotAlign::OnAlignSelectedActorsRotXButtonClicked()
{
	FPivotToolUtil::AlignSelectionRotation(EAxis::X);
	return FReply::Handled();
}

FReply SPivotAlign::OnAlignSelectedActorsRotYButtonClicked()
{
	FPivotToolUtil::AlignSelectionRotation(EAxis::Y);
	return FReply::Handled();
}

FReply SPivotAlign::OnAlignSelectedActorsRotZButtonClicked()
{
	FPivotToolUtil::AlignSelectionRotation(EAxis::Z);
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
