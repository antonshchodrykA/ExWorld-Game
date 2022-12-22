// Copyright 2017-2019 marynate. All Rights Reserved.

#include "PivotToolCommands.h"

#define LOCTEXT_NAMESPACE "PivotToolCommands"

void FPivotToolCommands::RegisterCommands()
{
	UI_COMMAND(OpenPivotTool, "PivotTool", "Bring up PivotTool window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
