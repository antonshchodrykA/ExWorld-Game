// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PivotTool/Private/EdMode/PivotToolSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePivotToolSettings() {}
// Cross Module References
	PIVOTTOOL_API UEnum* Z_Construct_UEnum_PivotTool_EPivotToolPreviewShape();
	UPackage* Z_Construct_UPackage__Script_PivotTool();
	PIVOTTOOL_API UClass* Z_Construct_UClass_UPivotToolSettings_NoRegister();
	PIVOTTOOL_API UClass* Z_Construct_UClass_UPivotToolSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
// End Cross Module References
	static UEnum* EPivotToolPreviewShape_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PivotTool_EPivotToolPreviewShape, Z_Construct_UPackage__Script_PivotTool(), TEXT("EPivotToolPreviewShape"));
		}
		return Singleton;
	}
	template<> PIVOTTOOL_API UEnum* StaticEnum<EPivotToolPreviewShape>()
	{
		return EPivotToolPreviewShape_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPivotToolPreviewShape(EPivotToolPreviewShape_StaticEnum, TEXT("/Script/PivotTool"), TEXT("EPivotToolPreviewShape"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PivotTool_EPivotToolPreviewShape_Hash() { return 4252422600U; }
	UEnum* Z_Construct_UEnum_PivotTool_EPivotToolPreviewShape()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PivotTool();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPivotToolPreviewShape"), 0, Get_Z_Construct_UEnum_PivotTool_EPivotToolPreviewShape_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPivotToolPreviewShape::None", (int64)EPivotToolPreviewShape::None },
				{ "EPivotToolPreviewShape::Point", (int64)EPivotToolPreviewShape::Point },
				{ "EPivotToolPreviewShape::Sphere", (int64)EPivotToolPreviewShape::Sphere },
				{ "EPivotToolPreviewShape::Coordinate", (int64)EPivotToolPreviewShape::Coordinate },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Coordinate.Name", "EPivotToolPreviewShape::Coordinate" },
				{ "ModuleRelativePath", "Private/EdMode/PivotToolSettings.h" },
				{ "None.Name", "EPivotToolPreviewShape::None" },
				{ "Point.Name", "EPivotToolPreviewShape::Point" },
				{ "Sphere.Name", "EPivotToolPreviewShape::Sphere" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PivotTool,
				nullptr,
				"EPivotToolPreviewShape",
				"EPivotToolPreviewShape",
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
	void UPivotToolSettings::StaticRegisterNativesUPivotToolSettings()
	{
	}
	UClass* Z_Construct_UClass_UPivotToolSettings_NoRegister()
	{
		return UPivotToolSettings::StaticClass();
	}
	struct Z_Construct_UClass_UPivotToolSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PivotPresetPreviewColor_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PivotPresetPreviewColor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PivotPresetPreviewShape_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_PivotPresetPreviewShape;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_PivotPresetPreviewShape_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDisplayPivotPresetPreview_MetaData[];
#endif
		static void NewProp_bDisplayPivotPresetPreview_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDisplayPivotPresetPreview;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPivotToolSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PivotTool,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPivotToolSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EdMode/PivotToolSettings.h" },
		{ "ModuleRelativePath", "Private/EdMode/PivotToolSettings.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewColor_MetaData[] = {
		{ "Category", "PivotPreset" },
		{ "ModuleRelativePath", "Private/EdMode/PivotToolSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewColor = { "PivotPresetPreviewColor", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPivotToolSettings, PivotPresetPreviewColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewColor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewShape_MetaData[] = {
		{ "Category", "PivotPreset" },
		{ "ModuleRelativePath", "Private/EdMode/PivotToolSettings.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewShape = { "PivotPresetPreviewShape", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPivotToolSettings, PivotPresetPreviewShape), Z_Construct_UEnum_PivotTool_EPivotToolPreviewShape, METADATA_PARAMS(Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewShape_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewShape_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewShape_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_bDisplayPivotPresetPreview_MetaData[] = {
		{ "Category", "PivotPreset" },
		{ "ModuleRelativePath", "Private/EdMode/PivotToolSettings.h" },
	};
#endif
	void Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_bDisplayPivotPresetPreview_SetBit(void* Obj)
	{
		((UPivotToolSettings*)Obj)->bDisplayPivotPresetPreview = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_bDisplayPivotPresetPreview = { "bDisplayPivotPresetPreview", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPivotToolSettings), &Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_bDisplayPivotPresetPreview_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_bDisplayPivotPresetPreview_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_bDisplayPivotPresetPreview_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPivotToolSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewColor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewShape,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_PivotPresetPreviewShape_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPivotToolSettings_Statics::NewProp_bDisplayPivotPresetPreview,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPivotToolSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPivotToolSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPivotToolSettings_Statics::ClassParams = {
		&UPivotToolSettings::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPivotToolSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPivotToolSettings_Statics::PropPointers),
		0,
		0x000000A6u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UPivotToolSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPivotToolSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPivotToolSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPivotToolSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPivotToolSettings, 2529274581);
	template<> PIVOTTOOL_API UClass* StaticClass<UPivotToolSettings>()
	{
		return UPivotToolSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPivotToolSettings(Z_Construct_UClass_UPivotToolSettings, &UPivotToolSettings::StaticClass, TEXT("/Script/PivotTool"), TEXT("UPivotToolSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPivotToolSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
