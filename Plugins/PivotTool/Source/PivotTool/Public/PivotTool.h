// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#define PIVOTTOOL_DEBUG 0
#define PIVOTTOOL_WIP 0
#define ENABLE_PIVOTTOOL_LOG 0

#define PIVOTTOOL_FOLD 1 // Code Folding

DECLARE_LOG_CATEGORY_EXTERN(LogPivotTool, Verbose, All);

#if ENABLE_PIVOTTOOL_LOG
#define PIVOTTOOL_LOG(Verbosity, Format, ...) \
	UE_LOG(LogPivotTool, Verbosity, Format, ##__VA_ARGS__);
#else
#define PIVOTTOOL_LOG(Verbosity, Format, ...)
#endif

class FToolBarBuilder;
class FMenuBuilder;

class FPivotToolModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command (by default it will bring up plugin window) */
	void OpenPivotToolTab();
	
private:

	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

private:
	TSharedPtr<class SPivotToolWidget> ToolWindow;
	TSharedPtr<class FUICommandList> ToolCommands;
};
