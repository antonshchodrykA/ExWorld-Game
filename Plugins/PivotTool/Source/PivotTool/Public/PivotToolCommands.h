// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "PivotToolStyle.h"

#include "Framework/Commands/Commands.h"

class FPivotToolCommands : public TCommands<FPivotToolCommands>
{
public:

	FPivotToolCommands()
		: TCommands<FPivotToolCommands>(TEXT("PivotTool"), NSLOCTEXT("Contexts", "PivotTool", "PivotTool Plugin"), NAME_None, FPivotToolStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPivotTool;
};