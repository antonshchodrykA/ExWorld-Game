// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "SPivotToolEditor.h"
#include "PivotToolEdMode.h"
#include "PivotToolUISettingCustomization.h"
#include "PivotToolActorCustomization.h"

#include "Interfaces/IPluginManager.h"

#include "IDetailsView.h"
#include "PropertyEditorModule.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SScrollBox.h"
#include "EditorModeManager.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"

#include "Widgets/Notifications/SErrorText.h"

#define LOCTEXT_NAMESPACE "PivotToolEditor"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPivotToolEditor::Construct(const FArguments& InArgs, TSharedRef<FPivotToolEdModeToolkit> InParentToolkit)
{
	const FText VersionName = FText::FromString(IPluginManager::Get().FindPlugin(TEXT("PivotTool"))->GetDescriptor().VersionName);
	const FText CreatedBy = FText::FromString(TEXT("by " ) + IPluginManager::Get().FindPlugin(TEXT("PivotTool"))->GetDescriptor().CreatedBy);
	const FText FriendlyName = FText::FromString(IPluginManager::Get().FindPlugin(TEXT("PivotTool"))->GetDescriptor().FriendlyName);
	
	FPivotToolEdMode* EditMode = GetEditorMode();
	
	FPropertyEditorModule& PropetyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	
	FDetailsViewArgs ActorDetailsViewArgs;
	{
		ActorDetailsViewArgs.bUpdatesFromSelection = true;
		ActorDetailsViewArgs.bLockable = false;
		ActorDetailsViewArgs.bAllowSearch = false;
		ActorDetailsViewArgs.NameAreaSettings = FDetailsViewArgs::ActorsUseNameArea;
	}
	ActorDetailView = PropetyEditorModule.CreateDetailView(ActorDetailsViewArgs);
	
	auto IsPropertyVisible = [](const FPropertyAndParent& PropetyAndParent)
	{
		if (PropetyAndParent.Property.GetFName() == TEXT("PivotOffset"))
		{
			return true;
		}
		return false;
	};
	
	ActorDetailView->SetIsPropertyVisibleDelegate(FIsPropertyVisible::CreateLambda(IsPropertyVisible));
	ActorDetailView->RegisterInstancedCustomPropertyLayout(AActor::StaticClass(), 
		FOnGetDetailCustomizationInstance::CreateStatic(&FPivotToolActorCustomization::MakeInstance, EditMode)
		);

	
	FDetailsViewArgs ToolDetailsViewArgs(
		/*InUpdateFromSelection=*/ false, 
		/*InLockable=*/ false, 
		/*InAllowSearch=*/false, 
		/*InHideSelectionTip=*/ FDetailsViewArgs::HideNameArea);
	TSharedPtr<IDetailsView> ToolDetailView = PropetyEditorModule.CreateDetailView(ToolDetailsViewArgs);
	ToolDetailView->RegisterInstancedCustomPropertyLayout(UPivotToolUISetting::StaticClass(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FPivotToolUISettingCustomization::MakeInstance, EditMode)
		);
	ToolDetailView->SetObject(EditMode->UISetting);
	
	ChildSlot
	[
		SNew(SVerticalBox)
		
		// Error Text
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 5)
		[
			SAssignNew(ErrorText, SErrorText)
		]

		// Main
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot().Padding(0, 5)
			[
				SNew(SVerticalBox)

				// Actor Pivot
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					.Padding(0)
					[
					ActorDetailView.ToSharedRef()
					]
				]

				// Pivot Tool UI Setting
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					.Padding(0)
					[
						ToolDetailView.ToSharedRef()
					]
				]
			]
		]
	
		// Version
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(0, 0, 0, 5)
		[
			SAssignNew(VersionText, SErrorText)
		]
	];
}

void SPivotToolEditor::NotifySelectionChanged()
{
	TArray<UObject*> SelectedActors;
	GEditor->GetSelectedActors()->GetSelectedObjects(AActor::StaticClass(), SelectedActors);
	ActorDetailView->SetObjects(SelectedActors, true);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FPivotToolEdMode* SPivotToolEditor::GetEditorMode()
{
	return (FPivotToolEdMode*)GLevelEditorModeTools().GetActiveMode(FPivotToolEdMode::EM_PivotToolEdModeId);
}

void SPivotToolEditor::SaveUISetting(UPivotToolUISetting* InUISetting)
{

}

void SPivotToolEditor::LoadUISetting(const UPivotToolUISetting* InUISetting)
{

}

#undef LOCTEXT_NAMESPACE
