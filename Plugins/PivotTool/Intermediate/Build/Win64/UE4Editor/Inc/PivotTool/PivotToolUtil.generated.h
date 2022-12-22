// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PIVOTTOOL_PivotToolUtil_generated_h
#error "PivotToolUtil.generated.h already included, missing '#pragma once' in PivotToolUtil.h"
#endif
#define PIVOTTOOL_PivotToolUtil_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_PivotTool_Source_PivotTool_Private_PivotToolUtil_h


#define FOREACH_ENUM_EPIVOTPRESET(op) \
	op(EPivotPreset::BoundingBoxCenter) \
	op(EPivotPreset::BoundingBoxCenterTop) \
	op(EPivotPreset::BoundingBoxCenterBottom) \
	op(EPivotPreset::BoundingBoxCenterLeft) \
	op(EPivotPreset::BoundingBoxCenterRight) \
	op(EPivotPreset::BoundingBoxCenterFront) \
	op(EPivotPreset::BoundingBoxCenterBack) \
	op(EPivotPreset::BoundingBoxCornerTop1) \
	op(EPivotPreset::BoundingBoxCornerTop2) \
	op(EPivotPreset::BoundingBoxCornerTop3) \
	op(EPivotPreset::BoundingBoxCornerTop4) \
	op(EPivotPreset::BoundingBoxCornerBottom1) \
	op(EPivotPreset::BoundingBoxCornerBottom2) \
	op(EPivotPreset::BoundingBoxCornerBottom3) \
	op(EPivotPreset::BoundingBoxCornerBottom4) \
	op(EPivotPreset::BoundingBoxEdgeTop1) \
	op(EPivotPreset::BoundingBoxEdgeTop2) \
	op(EPivotPreset::BoundingBoxEdgeTop3) \
	op(EPivotPreset::BoundingBoxEdgeTop4) \
	op(EPivotPreset::BoundingBoxEdgeMid1) \
	op(EPivotPreset::BoundingBoxEdgeMid2) \
	op(EPivotPreset::BoundingBoxEdgeMid3) \
	op(EPivotPreset::BoundingBoxEdgeMid4) \
	op(EPivotPreset::BoundingBoxEdgeBottom1) \
	op(EPivotPreset::BoundingBoxEdgeBottom2) \
	op(EPivotPreset::BoundingBoxEdgeBottom3) \
	op(EPivotPreset::BoundingBoxEdgeBottom4) 

enum class EPivotPreset : uint8;
template<> PIVOTTOOL_API UEnum* StaticEnum<EPivotPreset>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
