// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PIVOTTOOL_SPivotAlign_generated_h
#error "SPivotAlign.generated.h already included, missing '#pragma once' in SPivotAlign.h"
#endif
#define PIVOTTOOL_SPivotAlign_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_PivotTool_Source_PivotTool_Private_Widgets_SPivotAlign_h


#define FOREACH_ENUM_EPIVOTALIGNCOORD(op) \
	op(EPivotAlignCoord::Auto) \
	op(EPivotAlignCoord::Local) \
	op(EPivotAlignCoord::World) 

enum class EPivotAlignCoord : uint8;
template<> PIVOTTOOL_API UEnum* StaticEnum<EPivotAlignCoord>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
