// Copyright 2017-2019 marynate. All Rights Reserved.

#include "PivotToolEdModeToolkit.h"
#include "PivotToolEdMode.h"

#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "FPivotToolEdModeToolkit"

void FPivotToolEdModeToolkit::RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager)
{
}

void FPivotToolEdModeToolkit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& TabManager)
{
}

void FPivotToolEdModeToolkit::Init(const TSharedPtr<class IToolkitHost>& InitToolkitHost)
{
	PivotToolEditorWidget = SNew(SPivotToolEditor, SharedThis(this));

	FPivotToolEdMode* EditorMode = static_cast<FPivotToolEdMode*>(GetEditorMode());
	if (EditorMode)
	{
		EditorMode->SetOnSelectionChangedDelegate(::FOnSelectionChanged::CreateRaw(PivotToolEditorWidget.Get() , &SPivotToolEditor::NotifySelectionChanged));
	}

	FModeToolkit::Init(InitToolkitHost);
}

FPivotToolEdModeToolkit::FPivotToolEdModeToolkit()
{
	
}

FName FPivotToolEdModeToolkit::GetToolkitFName() const
{
	return FName("PivotToolEditor");
}

FText FPivotToolEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("PivotToolEditor", "DisplayName", "Pivot Tool");
}

class FEdMode* FPivotToolEdModeToolkit::GetEditorMode() const
{
	return GLevelEditorModeTools().GetActiveMode(FPivotToolEdMode::EM_PivotToolEdModeId);
}


void FPivotToolEdModeToolkit::SaveUISetting(UPivotToolUISetting* InUISetting)
{
	PivotToolEditorWidget->SaveUISetting(InUISetting);
}

void FPivotToolEdModeToolkit::LoadUISetting(const UPivotToolUISetting* InUISetting)
{
	PivotToolEditorWidget->LoadUISetting(InUISetting);
}

#undef LOCTEXT_NAMESPACE
