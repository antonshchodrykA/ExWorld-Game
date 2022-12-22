// Copyright 2016 marynate. All Rights Reserved.

#include "PivotToolSettings.h"

//////////////////////////////////////////////////////////////////////////
// UPivotToolEditorSettings

UPivotToolSettings::UPivotToolSettings()
	: bDisplayPivotPresetPreview(true)
	, PivotPresetPreviewShape(EPivotToolPreviewShape::Sphere)
	, PivotPresetPreviewColor(FColor::Yellow)
{
	if (!IsRunningCommandlet())
	{
	}
}
