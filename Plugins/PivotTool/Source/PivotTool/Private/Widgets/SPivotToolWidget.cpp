// Copyright 2017-2019 marynate. All Rights Reserved.

#include "SPivotToolWidget.h"
#include "PivotToolUtil.h"
#include "PivotToolSettings.h"
#include "PivotToolStyle.h"
#include "PivotTool.h"

#include "LevelEditorActions.h"
#include "EditorModeManager.h"
#include "StaticMeshResources.h"
#include "RawMesh.h"
#include "EditorSupportDelegates.h"
#include "Interfaces/IPluginManager.h"
#include "Engine/Selection.h"
#include "Engine/StaticMeshActor.h"
#include "Widgets/Input/SVectorInputBox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Layout/SScaleBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Layout/SSpacer.h"
#include "DrawDebugHelpers.h"
#include "Misc/ConfigCacheIni.h"

#define LOCTEXT_NAMESPACE "SPivotToolWidget"

#define HORIZONTAL_SPACER + SHorizontalBox::Slot().FillWidth(1.f) [ SNew(SSpacer) ]
#define VERTICAL_SPACER + SVerticalBox::Slot().FillHeight(1.f) [ SNew(SSpacer) ]

void SPivotToolWidget::Construct(const FArguments& InArgs)
{
	LoadUISetting();

	WidthLastFrame = 0.f;

	PivotOffsetInput = FVector::ZeroVector;

	bIsCtrlDown = false;
	bIsShiftDown = false;
	bIsAltDown = false;

	bAlternativeButtons = false;
	bCanToggleAlternativeButton = true;

	PreviewPivots.Empty();

	const FText VersionName = FText::FromString(IPluginManager::Get().FindPlugin(TEXT("PivotTool"))->GetDescriptor().VersionName);
	const FText CreatedBy = FText::FromString(TEXT("by ") + IPluginManager::Get().FindPlugin(TEXT("PivotTool"))->GetDescriptor().CreatedBy);
	const FText FriendlyName = FText::FromString(IPluginManager::Get().FindPlugin(TEXT("PivotTool"))->GetDescriptor().FriendlyName);

	const FText PivotToolVersion = FText::Format(LOCTEXT("PivotToolVersion", "{0} {1}"), FriendlyName, VersionName);

	const float ButtonContentPadding = 4.f;
	const float ButtonTextMinDesiredWidth = 20.f;
	const float VerticalPadding = 3.f;

	ChildSlot
	[
		SNew(SBorder)
		.BorderBackgroundColor(FLinearColor(0.f, 0.f, 0.f))
		.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
		.Padding(0.f)
		[

		SNew(SScrollBox)
		.Orientation(Orient_Vertical)
		.ScrollBarAlwaysVisible(false)
		+ SScrollBox::Slot()
		[

		SNew(SVerticalBox)

		// Pivot Preset >>
#if PIVOTTOOL_FOLD
		+ SVerticalBox::Slot().Padding(0, VerticalPadding, 0, 0).AutoHeight()
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			[
				SNew(SBorder)
				//.BorderBackgroundColor(FLinearColor(.1f,.1f,.1f))
				.BorderBackgroundColor(FLinearColor(0.f, 0.f, 0.f))
				.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
				.Padding(2.0f)
				[
					SAssignNew(PivotPreset, SPivotPreset)
					.OnSelected(this, &SPivotToolWidget::OnPivotPresetSelected)
					.OnHovered(this, &SPivotToolWidget::OnPivotPresetHovered)
					.OnUnhovered(this, &SPivotToolWidget::OnPivotPresetUnhovered)
				]
			]
		]
#endif	// Pivot Preset <<

		//VERTICAL_SPACER

		// Pivot UI >>
#if PIVOTTOOL_FOLD
		+ SVerticalBox::Slot().Padding(0, VerticalPadding, 0, 0).FillHeight(1.f)
		[
			SNew(SVerticalBox)

			// Pivot Offset >>
#if PIVOTTOOL_FOLD
			+ SVerticalBox::Slot().Padding(0, VerticalPadding).AutoHeight()
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.FillWidth(1.f)
				.Padding(2, 0)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SAssignNew(ApplyOffsetWrapBox, SWrapBox)
					.InnerSlotPadding(FVector2D(4.f, 2.f))

					// Pivot Offset Input
					+ SWrapBox::Slot().HAlign(HAlign_Center)
					[
						SNew(SHorizontalBox)

						// Apply Offset Input
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0)
						[
							SNew(SVectorInputBox)
							.Visibility(this, &SPivotToolWidget::GetPivotOffsetInputVisibility)
							.bColorAxisLabels(true)
							.AllowResponsiveLayout(false)
							//.AllowSpin(true)
							.X(this, &SPivotToolWidget::GetPivotOffsetInputX)
							.Y(this, &SPivotToolWidget::GetPivotOffsetInputY)
							.Z(this, &SPivotToolWidget::GetPivotOffsetInputZ)
							.OnXCommitted(this, &SPivotToolWidget::OnSetPivotOffsetInput, 0)
							.OnYCommitted(this, &SPivotToolWidget::OnSetPivotOffsetInput, 1)
							.OnZCommitted(this, &SPivotToolWidget::OnSetPivotOffsetInput, 2)
						]

						// Apply Offset Button
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0)
						[
							SNew(SButton)
							.Visibility(this, &SPivotToolWidget::GetPivotOffsetInputVisibility)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ContentPadding(ButtonContentPadding)
							.ButtonStyle(&FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.Round.DarkGray"))
							.OnClicked(this, &SPivotToolWidget::OnApplyOffsetClicked)
							.IsEnabled(this, &SPivotToolWidget::IsApplyOffsetEnabled)
							.ToolTipText(LOCTEXT("ApplyOffsetButtonTooltip", "Apply offset to pivot"))
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText")
								.Text(LOCTEXT("Offset", "Offset"))
								.MinDesiredWidth(ButtonTextMinDesiredWidth)
								.Justification(ETextJustify::Center)
							]
						]
					]

					+ SWrapBox::Slot().HAlign(HAlign_Center)
					[
#if PIVOTTOOL_FOLD
						SNew(SHorizontalBox)

						// Snap to Vertex
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ContentPadding(ButtonContentPadding)
							.ButtonStyle(&FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.Round.DarkGray"))
							.OnClicked(this, &SPivotToolWidget::OnSnapToVertexClicked)
							.IsEnabled(this, &SPivotToolWidget::IsSnapToVertexEnabled)
							.ToolTipText(LOCTEXT("SnapToVertexButtonTooltip", "Snap pivot to closest vertex postion"))
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText")
								.Text(LOCTEXT("SnapToVertex", "Snap to Vert"))
								.MinDesiredWidth(ButtonTextMinDesiredWidth)
								.Justification(ETextJustify::Center)
							]
						]
#endif
					]
				]
			]
#endif		// Pivot Offset <<

			// Toolbar
#if PIVOTTOOL_FOLD
			+ SVerticalBox::Slot().Padding(0, VerticalPadding, 0, 0).AutoHeight()
			[
				SNew(SBorder)
				.BorderBackgroundColor(FLinearColor(0.4f, 0.4f, 0.4f))
				.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
				.HAlign(HAlign_Center)
				[
					SAssignNew(MainToolboxWrapBox, SWrapBox)
					.InnerSlotPadding(FVector2D(5.f, 2.f))

					+ SWrapBox::Slot().HAlign(HAlign_Center)
					[
						SNew(SHorizontalBox)

						// Set
#if PIVOTTOOL_FOLD
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ContentPadding(ButtonContentPadding)
							.ButtonStyle(&FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.Round.Black"))
							.OnClicked(this, &SPivotToolWidget::OnSaveClicked)
							.ToolTipText(LOCTEXT("SaveButtonTooltip", "Save temporary actor pivot placement (Alt + Middle mouse)"))
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText")
								.Text(LOCTEXT("Set", "Set"))
								.MinDesiredWidth(ButtonTextMinDesiredWidth)
								.Justification(ETextJustify::Center)
							]
						]
#endif
						// Reset
#if PIVOTTOOL_FOLD
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ContentPadding(ButtonContentPadding)
							.ButtonStyle(&FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.Round.Black"))
							.OnClicked(this, &SPivotToolWidget::OnResetClicked)
							.ToolTipText(LOCTEXT("ResetButtonTooltip", "Reset actor pivot"))
							[
								SNew(STextBlock)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText")
								.Text(LOCTEXT("Reset", "Reset"))
								.MinDesiredWidth(ButtonTextMinDesiredWidth)
								.Justification(ETextJustify::Center)
							]
						]
#endif
						//+ SHorizontalBox::Slot().AutoWidth().Padding(10, 0)[SNew(SImage).Image(FPivotToolStyle::Get().GetBrush("PivotTool.DividingLine"))]
						//+ SHorizontalBox::Slot().AutoWidth().Padding(2, 0)[SNew(SSpacer)]
					]

					+ SWrapBox::Slot().HAlign(HAlign_Center)
					[
						SNew(SHorizontalBox)

						// Copy
#if PIVOTTOOL_FOLD
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ContentPadding(ButtonContentPadding)
							.ButtonStyle(&FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.Round.Black"))
							.OnClicked(this, &SPivotToolWidget::OnCopyClicked)
							.ToolTipText(LOCTEXT("CopyButtonTooltip", "Copy actor pivot"))
							[
								SNew(STextBlock)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText")
								.Text(LOCTEXT("Copy", "Copy"))
								.MinDesiredWidth(ButtonTextMinDesiredWidth)
								.Justification(ETextJustify::Center)
							]
						]
#endif
						// Paste
#if PIVOTTOOL_FOLD
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0, 0, 0)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ContentPadding(ButtonContentPadding)
							.ButtonStyle(&FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.Round.Black"))
							.OnClicked(this, &SPivotToolWidget::OnPasteClicked)
							.IsEnabled(this, &SPivotToolWidget::IsPasteEnabled)
							.ToolTipText(LOCTEXT("PasteButtonTooltip", "Paste actor pivot"))
							[
								SNew(STextBlock)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText")
								.Text(LOCTEXT("Paste", "Paste"))
								.MinDesiredWidth(ButtonTextMinDesiredWidth)
								.Justification(ETextJustify::Center)
							]
						]
#endif
						// Copy Past in Worldspace?
#if PIVOTTOOL_FOLD
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 2, 0, 2)
						.VAlign(VAlign_Center)
						[
							SNew(SCheckBox)
							.OnCheckStateChanged(this, &SPivotToolWidget::OnPivotCopiedInWorldSpaceCheckStateChanged)
							.IsChecked(this, &SPivotToolWidget::IsPivotCopiedInWorldSpace)
							.ToolTipText(LOCTEXT("CopyWorldSpaceTip", "Copy pivot in world space?"))
							.Content()
							[
								SNew(STextBlock)
								.Text(this, &SPivotToolWidget::GetCopyInWorldSpaceCheckboxText)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
								.Justification(ETextJustify::Center)
							]
						]

						+ SHorizontalBox::Slot().AutoWidth().Padding(2, 0)[SNew(SSpacer)]
#endif
					]

					+ SWrapBox::Slot().HAlign(HAlign_Center)
					[
						SNew(SHorizontalBox)

						// Bake
#if PIVOTTOOL_FOLD
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ContentPadding(ButtonContentPadding)
							.ButtonStyle(&FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.Round.Black"))
							.OnClicked(this, &SPivotToolWidget::OnBakeClicked)
							.IsEnabled(this, &SPivotToolWidget::IsBakeEnabled)
							.ToolTipText(LOCTEXT("BakeButtonTooltip", "Bake last selected static mesh actor's pivot to static mesh.\nYou can not undo this operation!"))
							[
								SNew(STextBlock)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText")
								.Text(LOCTEXT("Bake", "Bake"))
								.MinDesiredWidth(ButtonTextMinDesiredWidth)
								.Justification(ETextJustify::Center)
							]
						]
#endif
						// Duplicate and Bake
#if PIVOTTOOL_FOLD
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 0, 0, 0)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ContentPadding(ButtonContentPadding)
							.ButtonStyle(&FPivotToolStyle::Get().GetWidgetStyle<FButtonStyle>("PivotTool.ButtonStyle.Round.Black"))
							.OnClicked(this, &SPivotToolWidget::OnDuplicateAndBakeClicked)
							.IsEnabled(this, &SPivotToolWidget::IsBakeEnabled)
							.ToolTipText(LOCTEXT("DuplicateAndBakeButtonTooltip", "Duplicate static mesh and bake last selected static mesh actor's pivot to duplicated static mesh.\nYou can not undo this operation!"))
							[
								SNew(STextBlock)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.ButtonText")
								.Text(LOCTEXT("DuplicateAndBake", "D.Bake"))
								.MinDesiredWidth(ButtonTextMinDesiredWidth)
								.Justification(ETextJustify::Center)
							]
						]
#endif
						// Freeze Rotation
#if PIVOTTOOL_FOLD
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.Padding(2, 2, 0, 2)
						.VAlign(VAlign_Center)
						[
							SNew(SCheckBox)
							.OnCheckStateChanged(this, &SPivotToolWidget::OnFreezeRotationCheckStateChanged)
							.IsChecked(this, &SPivotToolWidget::IsFreezeRotation)
							.ToolTipText(LOCTEXT("FreezeRotationTip", "Also freeze rotation when baking pivot"))
							.Content()
							[
								SNew(STextBlock)
								.Text(this, &SPivotToolWidget::GetFreezeRotationCheckboxText)
								.TextStyle(FPivotToolStyle::Get(), "PivotTool.CheckboxText")
								.Justification(ETextJustify::Center)
							]
						]
#endif
					]
				]
			] // End of Main Tool bar
#endif

			// Align Actors
#if PIVOTTOOL_FOLD
			+SVerticalBox::Slot().Padding(0, VerticalPadding, 0, 0).AutoHeight()
			[
				SNew(SBorder)
				.BorderBackgroundColor(FLinearColor(0.4f, 0.4f, 0.4f))
				.BorderImage(FEditorStyle::GetBrush("ToolPanel.GroupBorder"))
				.HAlign(HAlign_Center)
				[
					SAssignNew(AlignActorsWidget, SPivotAlign)
				]
			]
#endif

			VERTICAL_SPACER

			// Version
#if PIVOTTOOL_FOLD
			+ SVerticalBox::Slot()
			.Padding(0, VerticalPadding * 2)
			.AutoHeight()
			.HAlign(HAlign_Center)
			[
				SNew(SScaleBox)
				.Stretch(EStretch::ScaleToFit)
				[
					SNew(SHorizontalBox)

					+ SHorizontalBox::Slot()
					.Padding(2, 0)
					.AutoWidth()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.Padding(0)
						.AutoHeight()
						[
							SNew(SImage)
							.Image(FPivotToolStyle::Get().GetBrush("PivotTool.PivotToolText"))
						]
					]

					+ SHorizontalBox::Slot()
					.Padding(2, 0)
					.AutoWidth()
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(VersionName)
						.TextStyle(FPivotToolStyle::Get(), "PivotTool.VersionText")
					]
				]
			]
#endif

		]
#endif	// Pivot UI <<
	]]];
}

bool SPivotToolWidget::SupportsKeyboardFocus() const
{
	return true;
}

FReply SPivotToolWidget::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	FReply Reply = FReply::Unhandled();
	//if (IsEnabled())
	{
		if (InKeyEvent.GetKey() == EKeys::LeftControl || InKeyEvent.GetKey() == EKeys::RightControl)
		{
			bIsCtrlDown = true;
			Reply = FReply::Handled();
			if (bCanToggleAlternativeButton)
			{
				bAlternativeButtons = !bAlternativeButtons;
				bCanToggleAlternativeButton = false;
			}
			//Invalidate(EInvalidateWidget::Layout);
		}
		if (InKeyEvent.GetKey() == EKeys::LeftShift || InKeyEvent.GetKey() == EKeys::RightShift)
		{
			bIsShiftDown = true;
			Reply = FReply::Handled();
			//Invalidate(EInvalidateWidget::Layout);
		}
		if (InKeyEvent.GetKey() == EKeys::LeftAlt || InKeyEvent.GetKey() == EKeys::RightAlt)
		{
			bIsAltDown = true;
			Reply = FReply::Handled();
			//Invalidate(EInvalidateWidget::Layout);
		}
	}
	return Reply;
}

FReply SPivotToolWidget::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	FReply Reply = FReply::Unhandled();

	//if (IsEnabled())
	{
		if (InKeyEvent.GetKey() == EKeys::LeftControl || InKeyEvent.GetKey() == EKeys::RightControl)
		{
			bIsCtrlDown = false;
			Reply = FReply::Handled();
//			bCanToggleAlternativeButton = true;
		}
		if (InKeyEvent.GetKey() == EKeys::LeftShift || InKeyEvent.GetKey() == EKeys::RightShift)
		{
			bIsShiftDown = false;
			Reply = FReply::Handled();
			//Invalidate(EInvalidateWidget::Layout);
		}
		if (InKeyEvent.GetKey() == EKeys::LeftAlt || InKeyEvent.GetKey() == EKeys::RightAlt)
		{
			bIsAltDown = false;
			Reply = FReply::Handled();
			//Invalidate(EInvalidateWidget::Layout);
		}
	}

	return Reply;
}

void SPivotToolWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	TickPreviewPivots();

	if (WidthLastFrame != AllottedGeometry.Size.X)
	{
		WidthLastFrame = AllottedGeometry.Size.X;
		TickUIWrapping();
	}
}

void SPivotToolWidget::SaveUISetting()
{
	GConfig->SetBool(TEXT("PivotTool"), TEXT("bFreezeRotation"), bFreezeRotation, GEditorPerProjectIni);
	GConfig->SetBool(TEXT("PivotTool"), TEXT("bCopyPivotInWorldSpace"), bCopyPivotInWorldSpace, GEditorPerProjectIni);
}

void SPivotToolWidget::LoadUISetting()
{
	GConfig->GetBool(TEXT("PivotTool"), TEXT("bFreezeRotation"), bFreezeRotation, GEditorPerProjectIni);
	GConfig->GetBool(TEXT("PivotTool"), TEXT("bCopyPivotInWorldSpace"), bCopyPivotInWorldSpace, GEditorPerProjectIni);
}

FReply SPivotToolWidget::OnApplyOffsetClicked()
{
	ECoordSystem CoordSystem = GLevelEditorModeTools().GetCoordSystem();
	bool bWorldSpace = CoordSystem == COORD_World;
	FPivotToolUtil::OffsetSelectedActorsPivotOffset(PivotOffsetInput, bWorldSpace);
	return FReply::Handled();
}

bool SPivotToolWidget::IsApplyOffsetEnabled() const
{
	return !PivotOffsetInput.IsNearlyZero() && GEditor->GetSelectedActorCount() > 0;
}

FReply SPivotToolWidget::OnSnapToVertexClicked()
{
	FPivotToolUtil::SnapSelectedActorsPivotToVertex();
	return FReply::Handled();
}

bool SPivotToolWidget::IsSnapToVertexEnabled() const
{
	return GEditor->GetSelectedActorCount() > 0;
}

FReply SPivotToolWidget::OnSaveClicked()
{
	FEditorModeTools& EditorModeTools = GLevelEditorModeTools();
	FPivotToolUtil::UpdateSelectedActorsPivotOffset(EditorModeTools.PivotLocation, /*bWorldSpace=*/ true);
	return FReply::Handled();
}

FReply SPivotToolWidget::OnCopyClicked()
{	
	FPivotToolUtil::CopyActorPivotOffset(bCopyPivotInWorldSpace);
	return FReply::Handled();
}

FReply SPivotToolWidget::OnPasteClicked()
{
	FPivotToolUtil::PasteActorPivotOffset(bCopyPivotInWorldSpace);
	return FReply::Handled();
}

bool SPivotToolWidget::IsPasteEnabled() const
{
	return FPivotToolUtil::HasPivotOffsetCopied();
}

FReply SPivotToolWidget::OnResetClicked()
{
	//bool bWorldSpace = bAlternativeButtons;
	const bool bWorldSpace = false;
	FPivotToolUtil::UpdateSelectedActorsPivotOffset(FVector::ZeroVector, bWorldSpace);
	return FReply::Handled();
}

FReply SPivotToolWidget::OnBakeClicked()
{
	const bool bDuplicate = false;

	USelection* SelectedActors = GEditor->GetSelectedActors();
	int32 SucceedCount = 0;
	TArray<UStaticMesh*> BakedMeshes;

	FPivotToolOptions Options;
	UpdateOptions(Options);

	bool bSilentMode = SelectedActors->Num() > 1;
	for (FSelectionIterator SelectionIt(*SelectedActors); SelectionIt; ++SelectionIt)
	{
		if (AStaticMeshActor* StaticMeshActor = Cast<AStaticMeshActor>(*SelectionIt))
		{
			if (UStaticMesh* StaticMesh = StaticMeshActor->GetStaticMeshComponent()->GetStaticMesh())
			{
				if (BakedMeshes.Find(StaticMesh) == INDEX_NONE)
				{
					if (FPivotToolUtil::BakeStaticMeshActorsPivotOffsetToRawMesh(StaticMeshActor, Options, /*bDuplicate=*/ bDuplicate, /*bSilentMode=*/ bSilentMode))
					{
						++SucceedCount;
					}
					BakedMeshes.AddUnique(StaticMesh);
				}
				else
				{
					// Reset Pivot Offset if Mesh Pivot already baked
					FPivotToolUtil::UpdateActorPivotOffset(StaticMeshActor, FVector::ZeroVector, /*bWorldSpace=*/ false);
				}
			}
		}
	}

	FPivotToolUtil::NotifyMessage(FText::FromString(FString::Printf(TEXT("%d Static Mesh Baked!"), SucceedCount)), 0.5f);

// 	AStaticMeshActor* StaticMeshActor = GEditor->GetSelectedActors()->GetBottom<AStaticMeshActor>();
// 	if (StaticMeshActor)
// 	{
// 		//bool bDuplicate = bAlternativeButtons;
// 		const bool bDuplicate = false;
// 		FPivotToolUtil::BakeStaticMeshActorsPivotOffsetToRawMesh(StaticMeshActor, /*bBakeRotation=*/ bFreezeRotation, /*bDuplicate=*/ bDuplicate);
// 	}
// 	else
// 	{
// 		FPivotToolUtil::NotifyMessage(LOCTEXT("NoStaticMeshActor", "Can Only Bake to Static Mesh Actor! "), 0.5f);
// 	}
	
	return FReply::Handled();
}

FReply SPivotToolWidget::OnDuplicateAndBakeClicked()
{
	const bool bDuplicate = true;

	FPivotToolOptions Options;
	UpdateOptions(Options);

	USelection* SelectedActors = GEditor->GetSelectedActors();
	int32 SucceedCount = 0;
	for (FSelectionIterator SelectionIt(*SelectedActors); SelectionIt; ++SelectionIt)
	{
		AStaticMeshActor* StaticMeshActor = Cast<AStaticMeshActor>(*SelectionIt);
		if (StaticMeshActor)
		{
			if (FPivotToolUtil::BakeStaticMeshActorsPivotOffsetToRawMesh(StaticMeshActor, Options, /*bDuplicate=*/ bDuplicate))
			{
				++SucceedCount;
			}
		}
	}

	FPivotToolUtil::NotifyMessage(FText::FromString(FString::Printf(TEXT("%d Static Mesh Actor Baked!"), SucceedCount)), 0.5f);

// 	AStaticMeshActor* StaticMeshActor = GEditor->GetSelectedActors()->GetBottom<AStaticMeshActor>();
// 	if (StaticMeshActor)
// 	{
// 		const bool bDuplicate = true;
// 		FPivotToolUtil::BakeStaticMeshActorsPivotOffsetToRawMesh(StaticMeshActor, /*bBakeRotation=*/ bFreezeRotation, /*bDuplicate=*/ bDuplicate);
// 	}
// 	else
// 	{
// 		FPivotToolUtil::NotifyMessage(LOCTEXT("NoStaticMeshActor", "Can Only Bake to Static Mesh Actor! "), 0.5f);
// 	}

	return FReply::Handled();
}

bool SPivotToolWidget::IsBakeEnabled() const
{
	AStaticMeshActor* StaticMeshActor = GEditor->GetSelectedActors()->GetBottom<AStaticMeshActor>();
	return StaticMeshActor != NULL;
}

ECheckBoxState SPivotToolWidget::IsFreezeRotation() const
{
	return bFreezeRotation ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

void SPivotToolWidget::OnFreezeRotationCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bFreezeRotation = NewCHeckedState == ECheckBoxState::Checked;
	SaveUISetting();
}

FText SPivotToolWidget::GetFreezeRotationCheckboxText() const
{
	return WidthLastFrame > 418.f ? LOCTEXT("FreezeRotaion", "Freeze Rotation") : LOCTEXT("FreezeRotaion.Tight", "Rot");
}

ECheckBoxState SPivotToolWidget::IsPivotCopiedInWorldSpace() const
{
	return bCopyPivotInWorldSpace ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}

void SPivotToolWidget::OnPivotCopiedInWorldSpaceCheckStateChanged(ECheckBoxState NewCHeckedState)
{
	bCopyPivotInWorldSpace = NewCHeckedState == ECheckBoxState::Checked;
	SaveUISetting();
}

FText SPivotToolWidget::GetCopyInWorldSpaceCheckboxText() const
{
	return WidthLastFrame > 418.f ? LOCTEXT("WorldSpace", "World Space") : LOCTEXT("WorldSpace.Tight", "World");
}

FReply SPivotToolWidget::OnPivotPresetSelected(EPivotPreset InPreset)
{
	PIVOTTOOL_LOG(Display, TEXT("SPivotToolWidget::OnPivotPresetSelected: %d"), (int32)InPreset);

	FPivotToolOptions Options;
	UpdateOptions(Options);
	FPivotToolUtil::UpdateSelectedActorsPivotOffset(InPreset, Options);
	return FReply::Handled();
}

void SPivotToolWidget::OnPivotPresetHovered(EPivotPreset InPreset)
{
	PIVOTTOOL_LOG(Display, TEXT("SPivotToolWidget::OnPivotPresetHovered: %d"), (int32)InPreset);

	FPivotToolOptions Options;
	UpdateOptions(Options);

	FPivotToolUtil::GetPreviewPivotsOfSelectedActors(InPreset, Options, PreviewPivots);
}

void SPivotToolWidget::OnPivotPresetUnhovered(EPivotPreset InPreset)
{
	PIVOTTOOL_LOG(Display, TEXT("SPivotToolWidget::OnPivotPresetUnhovered: %d"), (int32)InPreset);

	PreviewPivots.Empty();
}

void SPivotToolWidget::OnSetPivotOffsetInput(float InValue, ETextCommit::Type CommitType, int32 InAxis)
{
	if (InAxis == 0)
	{
		PivotOffsetInput.X = InValue;
	}
	else if (InAxis == 1)
	{
		PivotOffsetInput.Y = InValue;
	}
	else if (InAxis == 2)
	{
		PivotOffsetInput.Z = InValue;
	}
}

EVisibility SPivotToolWidget::GetPivotOffsetInputVisibility() const
{
	return WidthLastFrame >= 180.f ? EVisibility::Visible : EVisibility::Collapsed;
}

void SPivotToolWidget::TickPreviewPivots()
{
	const UPivotToolSettings* PivotToolSettings = GetDefault<UPivotToolSettings>();

	if (!PivotToolSettings->bDisplayPivotPresetPreview)
	{
		return;
	}

	if (GEditor->GetSelectedActorCount() <= 0)
	{
		return;
	}

	if (PreviewPivots.Num() <= 0)
	{
		return;
	}

	if (AActor* LastSelectedActor = GEditor->GetSelectedActors()->GetBottom<AActor>())
	{
		if (UWorld* World = LastSelectedActor->GetWorld())
		{
			EPivotToolPreviewShape PreviewShape = PivotToolSettings->PivotPresetPreviewShape;
			const FColor PreviewColor = PivotToolSettings->PivotPresetPreviewColor;

			FVector ActorOrigin, ActorExtent;
			LastSelectedActor->GetActorBounds(/*bOnlyCollidingComponents*/false, ActorOrigin, ActorExtent);
			float Radius = FMath::Max3(ActorExtent.X, ActorExtent.Y, ActorExtent.Z) / 20.f;

			const float LineThickness = Radius / 10.f;			
			const int32 SphereSegments = 12;
			const float CoordScale = Radius * 2;

			const bool bPersistent = false;
			const float LifeTime = -1.f;
			uint8 DepthPriority = SDPG_Foreground;
			const float PointSize = 10.f;

			for (auto It = PreviewPivots.CreateConstIterator(); It; ++It)
			{
				const FTransform& Pivot = *It;

				if (PreviewShape == EPivotToolPreviewShape::Sphere)
				{
					DrawDebugSphere(World, Pivot.GetLocation(), Radius, SphereSegments, PreviewColor, bPersistent, LifeTime, DepthPriority, LineThickness);
				}
				else if (PreviewShape == EPivotToolPreviewShape::Point)
				{
					DrawDebugPoint(World, Pivot.GetLocation(), PointSize, PreviewColor, bPersistent, LifeTime, DepthPriority);
				}

				if (PreviewShape != EPivotToolPreviewShape::None)
				{
					DrawDebugCoordinateSystem(World, Pivot.GetLocation(), Pivot.Rotator(), CoordScale, bPersistent, LifeTime, DepthPriority, LineThickness);
				}
			}
		}
	}
}

void SPivotToolWidget::UpdateOptions(FPivotToolOptions& Options)
{
	Options.bAutoSave = PivotPreset->IsAutoSave() == ECheckBoxState::Checked;
	Options.bGroupMode = PivotPreset->IsGroupMode() == ECheckBoxState::Checked;
	Options.bLastSelectedMode = PivotPreset->IsLastSelectedMode() == ECheckBoxState::Checked;
	Options.bVertexMode = PivotPreset->IsVertexMode() == ECheckBoxState::Checked;
	Options.bChildrenMode = PivotPreset->IsChildrenMode() == ECheckBoxState::Checked;

	Options.bFreezeRotation = IsFreezeRotation() == ECheckBoxState::Checked;
}

void SPivotToolWidget::TickUIWrapping()
{
	ApplyOffsetWrapBox->SetWrapWidth(WidthLastFrame);
	MainToolboxWrapBox->SetWrapWidth(WidthLastFrame);
	AlignActorsWidget->SetWrapWidth(WidthLastFrame);

	PIVOTTOOL_LOG(Display, TEXT("SPivotToolWidget::TickUIWrapping: %.2f"), WidthLastFrame)
}

#undef HORIZONTAL_SPACER
#undef VERTICAL_SPACER

#undef LOCTEXT_NAMESPACE
