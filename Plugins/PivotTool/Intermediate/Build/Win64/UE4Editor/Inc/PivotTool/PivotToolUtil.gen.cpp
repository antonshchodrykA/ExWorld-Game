// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PivotTool/Private/PivotToolUtil.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePivotToolUtil() {}
// Cross Module References
	PIVOTTOOL_API UEnum* Z_Construct_UEnum_PivotTool_EPivotPreset();
	UPackage* Z_Construct_UPackage__Script_PivotTool();
// End Cross Module References
	static UEnum* EPivotPreset_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PivotTool_EPivotPreset, Z_Construct_UPackage__Script_PivotTool(), TEXT("EPivotPreset"));
		}
		return Singleton;
	}
	template<> PIVOTTOOL_API UEnum* StaticEnum<EPivotPreset>()
	{
		return EPivotPreset_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPivotPreset(EPivotPreset_StaticEnum, TEXT("/Script/PivotTool"), TEXT("EPivotPreset"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PivotTool_EPivotPreset_Hash() { return 2005705932U; }
	UEnum* Z_Construct_UEnum_PivotTool_EPivotPreset()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PivotTool();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPivotPreset"), 0, Get_Z_Construct_UEnum_PivotTool_EPivotPreset_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPivotPreset::BoundingBoxCenter", (int64)EPivotPreset::BoundingBoxCenter },
				{ "EPivotPreset::BoundingBoxCenterTop", (int64)EPivotPreset::BoundingBoxCenterTop },
				{ "EPivotPreset::BoundingBoxCenterBottom", (int64)EPivotPreset::BoundingBoxCenterBottom },
				{ "EPivotPreset::BoundingBoxCenterLeft", (int64)EPivotPreset::BoundingBoxCenterLeft },
				{ "EPivotPreset::BoundingBoxCenterRight", (int64)EPivotPreset::BoundingBoxCenterRight },
				{ "EPivotPreset::BoundingBoxCenterFront", (int64)EPivotPreset::BoundingBoxCenterFront },
				{ "EPivotPreset::BoundingBoxCenterBack", (int64)EPivotPreset::BoundingBoxCenterBack },
				{ "EPivotPreset::BoundingBoxCornerTop1", (int64)EPivotPreset::BoundingBoxCornerTop1 },
				{ "EPivotPreset::BoundingBoxCornerTop2", (int64)EPivotPreset::BoundingBoxCornerTop2 },
				{ "EPivotPreset::BoundingBoxCornerTop3", (int64)EPivotPreset::BoundingBoxCornerTop3 },
				{ "EPivotPreset::BoundingBoxCornerTop4", (int64)EPivotPreset::BoundingBoxCornerTop4 },
				{ "EPivotPreset::BoundingBoxCornerBottom1", (int64)EPivotPreset::BoundingBoxCornerBottom1 },
				{ "EPivotPreset::BoundingBoxCornerBottom2", (int64)EPivotPreset::BoundingBoxCornerBottom2 },
				{ "EPivotPreset::BoundingBoxCornerBottom3", (int64)EPivotPreset::BoundingBoxCornerBottom3 },
				{ "EPivotPreset::BoundingBoxCornerBottom4", (int64)EPivotPreset::BoundingBoxCornerBottom4 },
				{ "EPivotPreset::BoundingBoxEdgeTop1", (int64)EPivotPreset::BoundingBoxEdgeTop1 },
				{ "EPivotPreset::BoundingBoxEdgeTop2", (int64)EPivotPreset::BoundingBoxEdgeTop2 },
				{ "EPivotPreset::BoundingBoxEdgeTop3", (int64)EPivotPreset::BoundingBoxEdgeTop3 },
				{ "EPivotPreset::BoundingBoxEdgeTop4", (int64)EPivotPreset::BoundingBoxEdgeTop4 },
				{ "EPivotPreset::BoundingBoxEdgeMid1", (int64)EPivotPreset::BoundingBoxEdgeMid1 },
				{ "EPivotPreset::BoundingBoxEdgeMid2", (int64)EPivotPreset::BoundingBoxEdgeMid2 },
				{ "EPivotPreset::BoundingBoxEdgeMid3", (int64)EPivotPreset::BoundingBoxEdgeMid3 },
				{ "EPivotPreset::BoundingBoxEdgeMid4", (int64)EPivotPreset::BoundingBoxEdgeMid4 },
				{ "EPivotPreset::BoundingBoxEdgeBottom1", (int64)EPivotPreset::BoundingBoxEdgeBottom1 },
				{ "EPivotPreset::BoundingBoxEdgeBottom2", (int64)EPivotPreset::BoundingBoxEdgeBottom2 },
				{ "EPivotPreset::BoundingBoxEdgeBottom3", (int64)EPivotPreset::BoundingBoxEdgeBottom3 },
				{ "EPivotPreset::BoundingBoxEdgeBottom4", (int64)EPivotPreset::BoundingBoxEdgeBottom4 },
				{ "EPivotPreset::MAX", (int64)EPivotPreset::MAX },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BoundingBoxCenter.DisplayName", "C" },
				{ "BoundingBoxCenter.Name", "EPivotPreset::BoundingBoxCenter" },
				{ "BoundingBoxCenterBack.DisplayName", "CB" },
				{ "BoundingBoxCenterBack.Name", "EPivotPreset::BoundingBoxCenterBack" },
				{ "BoundingBoxCenterBottom.DisplayName", "CB" },
				{ "BoundingBoxCenterBottom.Name", "EPivotPreset::BoundingBoxCenterBottom" },
				{ "BoundingBoxCenterFront.DisplayName", "CF" },
				{ "BoundingBoxCenterFront.Name", "EPivotPreset::BoundingBoxCenterFront" },
				{ "BoundingBoxCenterLeft.DisplayName", "CL" },
				{ "BoundingBoxCenterLeft.Name", "EPivotPreset::BoundingBoxCenterLeft" },
				{ "BoundingBoxCenterRight.DisplayName", "CR" },
				{ "BoundingBoxCenterRight.Name", "EPivotPreset::BoundingBoxCenterRight" },
				{ "BoundingBoxCenterTop.DisplayName", "CT" },
				{ "BoundingBoxCenterTop.Name", "EPivotPreset::BoundingBoxCenterTop" },
				{ "BoundingBoxCornerBottom1.DisplayName", "BC1" },
				{ "BoundingBoxCornerBottom1.Name", "EPivotPreset::BoundingBoxCornerBottom1" },
				{ "BoundingBoxCornerBottom2.DisplayName", "BC2" },
				{ "BoundingBoxCornerBottom2.Name", "EPivotPreset::BoundingBoxCornerBottom2" },
				{ "BoundingBoxCornerBottom3.DisplayName", "BC3" },
				{ "BoundingBoxCornerBottom3.Name", "EPivotPreset::BoundingBoxCornerBottom3" },
				{ "BoundingBoxCornerBottom4.DisplayName", "BC4" },
				{ "BoundingBoxCornerBottom4.Name", "EPivotPreset::BoundingBoxCornerBottom4" },
				{ "BoundingBoxCornerTop1.Comment", "/*******************\n\x09   2 _________ 3\n\x09    /        /\n\x09   /        /\n\x09""1 /________/ 4\n\n\x09******************/" },
				{ "BoundingBoxCornerTop1.DisplayName", "TC1" },
				{ "BoundingBoxCornerTop1.Name", "EPivotPreset::BoundingBoxCornerTop1" },
				{ "BoundingBoxCornerTop1.ToolTip", "2 _________ 3\n /        /\n/        /\n1 /________/ 4" },
				{ "BoundingBoxCornerTop2.DisplayName", "TC2" },
				{ "BoundingBoxCornerTop2.Name", "EPivotPreset::BoundingBoxCornerTop2" },
				{ "BoundingBoxCornerTop3.DisplayName", "TC3" },
				{ "BoundingBoxCornerTop3.Name", "EPivotPreset::BoundingBoxCornerTop3" },
				{ "BoundingBoxCornerTop4.DisplayName", "TC4" },
				{ "BoundingBoxCornerTop4.Name", "EPivotPreset::BoundingBoxCornerTop4" },
				{ "BoundingBoxEdgeBottom1.DisplayName", "BE1" },
				{ "BoundingBoxEdgeBottom1.Name", "EPivotPreset::BoundingBoxEdgeBottom1" },
				{ "BoundingBoxEdgeBottom2.DisplayName", "BE2" },
				{ "BoundingBoxEdgeBottom2.Name", "EPivotPreset::BoundingBoxEdgeBottom2" },
				{ "BoundingBoxEdgeBottom3.DisplayName", "BE3" },
				{ "BoundingBoxEdgeBottom3.Name", "EPivotPreset::BoundingBoxEdgeBottom3" },
				{ "BoundingBoxEdgeBottom4.DisplayName", "BE4" },
				{ "BoundingBoxEdgeBottom4.Name", "EPivotPreset::BoundingBoxEdgeBottom4" },
				{ "BoundingBoxEdgeMid1.DisplayName", "ME1" },
				{ "BoundingBoxEdgeMid1.Name", "EPivotPreset::BoundingBoxEdgeMid1" },
				{ "BoundingBoxEdgeMid2.DisplayName", "ME2" },
				{ "BoundingBoxEdgeMid2.Name", "EPivotPreset::BoundingBoxEdgeMid2" },
				{ "BoundingBoxEdgeMid3.DisplayName", "ME3" },
				{ "BoundingBoxEdgeMid3.Name", "EPivotPreset::BoundingBoxEdgeMid3" },
				{ "BoundingBoxEdgeMid4.DisplayName", "ME4" },
				{ "BoundingBoxEdgeMid4.Name", "EPivotPreset::BoundingBoxEdgeMid4" },
				{ "BoundingBoxEdgeTop1.Comment", "/*******************\n\x09    ___ 2____\n\x09   /        /\n\x09  1        3\n\x09 /___ 4 __/ \n\n\x09******************/" },
				{ "BoundingBoxEdgeTop1.DisplayName", "TE1" },
				{ "BoundingBoxEdgeTop1.Name", "EPivotPreset::BoundingBoxEdgeTop1" },
				{ "BoundingBoxEdgeTop1.ToolTip", "___ 2____\n/        /\n1        3\n/___ 4 __/" },
				{ "BoundingBoxEdgeTop2.DisplayName", "TE2" },
				{ "BoundingBoxEdgeTop2.Name", "EPivotPreset::BoundingBoxEdgeTop2" },
				{ "BoundingBoxEdgeTop3.DisplayName", "TE3" },
				{ "BoundingBoxEdgeTop3.Name", "EPivotPreset::BoundingBoxEdgeTop3" },
				{ "BoundingBoxEdgeTop4.DisplayName", "TE4" },
				{ "BoundingBoxEdgeTop4.Name", "EPivotPreset::BoundingBoxEdgeTop4" },
				{ "MAX.Name", "EPivotPreset::MAX" },
				{ "ModuleRelativePath", "Private/PivotToolUtil.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PivotTool,
				nullptr,
				"EPivotPreset",
				"EPivotPreset",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
