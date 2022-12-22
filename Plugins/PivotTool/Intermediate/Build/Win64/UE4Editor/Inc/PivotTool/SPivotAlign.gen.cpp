// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PivotTool/Private/Widgets/SPivotAlign.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSPivotAlign() {}
// Cross Module References
	PIVOTTOOL_API UEnum* Z_Construct_UEnum_PivotTool_EPivotAlignCoord();
	UPackage* Z_Construct_UPackage__Script_PivotTool();
// End Cross Module References
	static UEnum* EPivotAlignCoord_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PivotTool_EPivotAlignCoord, Z_Construct_UPackage__Script_PivotTool(), TEXT("EPivotAlignCoord"));
		}
		return Singleton;
	}
	template<> PIVOTTOOL_API UEnum* StaticEnum<EPivotAlignCoord>()
	{
		return EPivotAlignCoord_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPivotAlignCoord(EPivotAlignCoord_StaticEnum, TEXT("/Script/PivotTool"), TEXT("EPivotAlignCoord"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PivotTool_EPivotAlignCoord_Hash() { return 2972529482U; }
	UEnum* Z_Construct_UEnum_PivotTool_EPivotAlignCoord()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PivotTool();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPivotAlignCoord"), 0, Get_Z_Construct_UEnum_PivotTool_EPivotAlignCoord_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPivotAlignCoord::Auto", (int64)EPivotAlignCoord::Auto },
				{ "EPivotAlignCoord::Local", (int64)EPivotAlignCoord::Local },
				{ "EPivotAlignCoord::World", (int64)EPivotAlignCoord::World },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Auto.Name", "EPivotAlignCoord::Auto" },
				{ "Local.Name", "EPivotAlignCoord::Local" },
				{ "ModuleRelativePath", "Private/Widgets/SPivotAlign.h" },
				{ "World.Name", "EPivotAlignCoord::World" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PivotTool,
				nullptr,
				"EPivotAlignCoord",
				"EPivotAlignCoord",
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
