// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PrefabricatorRuntime/Public/PrefabricatorSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrefabricatorSettings() {}
// Cross Module References
	PREFABRICATORRUNTIME_API UEnum* Z_Construct_UEnum_PrefabricatorRuntime_EPrefabricatorPivotPosition();
	UPackage* Z_Construct_UPackage__Script_PrefabricatorRuntime();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorSettings_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorSettings();
	ENGINE_API UClass* Z_Construct_UClass_UDeveloperSettings();
// End Cross Module References
	static UEnum* EPrefabricatorPivotPosition_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_PrefabricatorRuntime_EPrefabricatorPivotPosition, Z_Construct_UPackage__Script_PrefabricatorRuntime(), TEXT("EPrefabricatorPivotPosition"));
		}
		return Singleton;
	}
	template<> PREFABRICATORRUNTIME_API UEnum* StaticEnum<EPrefabricatorPivotPosition>()
	{
		return EPrefabricatorPivotPosition_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPrefabricatorPivotPosition(EPrefabricatorPivotPosition_StaticEnum, TEXT("/Script/PrefabricatorRuntime"), TEXT("EPrefabricatorPivotPosition"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_PrefabricatorRuntime_EPrefabricatorPivotPosition_Hash() { return 1225784570U; }
	UEnum* Z_Construct_UEnum_PrefabricatorRuntime_EPrefabricatorPivotPosition()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_PrefabricatorRuntime();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPrefabricatorPivotPosition"), 0, Get_Z_Construct_UEnum_PrefabricatorRuntime_EPrefabricatorPivotPosition_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPrefabricatorPivotPosition::ExtremeLeft", (int64)EPrefabricatorPivotPosition::ExtremeLeft },
				{ "EPrefabricatorPivotPosition::ExtremeRight", (int64)EPrefabricatorPivotPosition::ExtremeRight },
				{ "EPrefabricatorPivotPosition::Center", (int64)EPrefabricatorPivotPosition::Center },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Center.Name", "EPrefabricatorPivotPosition::Center" },
				{ "ExtremeLeft.Name", "EPrefabricatorPivotPosition::ExtremeLeft" },
				{ "ExtremeRight.Name", "EPrefabricatorPivotPosition::ExtremeRight" },
				{ "ModuleRelativePath", "Public/PrefabricatorSettings.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
				nullptr,
				"EPrefabricatorPivotPosition",
				"EPrefabricatorPivotPosition",
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
	void UPrefabricatorSettings::StaticRegisterNativesUPrefabricatorSettings()
	{
	}
	UClass* Z_Construct_UClass_UPrefabricatorSettings_NoRegister()
	{
		return UPrefabricatorSettings::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabricatorSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultThumbnailZoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DefaultThumbnailZoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultThumbnailYaw_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DefaultThumbnailYaw;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultThumbnailPitch_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DefaultThumbnailPitch;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAllowDynamicUpdate_MetaData[];
#endif
		static void NewProp_bAllowDynamicUpdate_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowDynamicUpdate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PivotPosition_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_PivotPosition;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_PivotPosition_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabricatorSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "PrefabricatorSettings.h" },
		{ "ModuleRelativePath", "Public/PrefabricatorSettings.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailZoom_MetaData[] = {
		{ "Category", "Thumbnail" },
		{ "Comment", "/** Use this zoom value while saving the prefab asset */" },
		{ "ModuleRelativePath", "Public/PrefabricatorSettings.h" },
		{ "ToolTip", "Use this zoom value while saving the prefab asset" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailZoom = { "DefaultThumbnailZoom", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorSettings, DefaultThumbnailZoom), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailZoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailZoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailYaw_MetaData[] = {
		{ "Category", "Thumbnail" },
		{ "Comment", "/** Use this angle while saving the prefab asset */" },
		{ "ModuleRelativePath", "Public/PrefabricatorSettings.h" },
		{ "ToolTip", "Use this angle while saving the prefab asset" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailYaw = { "DefaultThumbnailYaw", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorSettings, DefaultThumbnailYaw), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailYaw_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailYaw_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailPitch_MetaData[] = {
		{ "Category", "Thumbnail" },
		{ "Comment", "/** Use this angle while saving the prefab asset */" },
		{ "ModuleRelativePath", "Public/PrefabricatorSettings.h" },
		{ "ToolTip", "Use this angle while saving the prefab asset" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailPitch = { "DefaultThumbnailPitch", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorSettings, DefaultThumbnailPitch), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailPitch_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailPitch_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_bAllowDynamicUpdate_MetaData[] = {
		{ "Category", "General Settings" },
		{ "Comment", "/** Whenever a prefab is saved, update all the other similar prefabs in the scene to reflect this new change */" },
		{ "ModuleRelativePath", "Public/PrefabricatorSettings.h" },
		{ "ToolTip", "Whenever a prefab is saved, update all the other similar prefabs in the scene to reflect this new change" },
	};
#endif
	void Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_bAllowDynamicUpdate_SetBit(void* Obj)
	{
		((UPrefabricatorSettings*)Obj)->bAllowDynamicUpdate = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_bAllowDynamicUpdate = { "bAllowDynamicUpdate", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPrefabricatorSettings), &Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_bAllowDynamicUpdate_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_bAllowDynamicUpdate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_bAllowDynamicUpdate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_PivotPosition_MetaData[] = {
		{ "Category", "General Settings" },
		{ "Comment", "/* Position pivot on extreme corner (bottom, left up), instead of center. */" },
		{ "ModuleRelativePath", "Public/PrefabricatorSettings.h" },
		{ "ToolTip", "Position pivot on extreme corner (bottom, left up), instead of center." },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_PivotPosition = { "PivotPosition", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorSettings, PivotPosition), Z_Construct_UEnum_PrefabricatorRuntime_EPrefabricatorPivotPosition, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_PivotPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_PivotPosition_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_PivotPosition_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPrefabricatorSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailZoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailYaw,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_DefaultThumbnailPitch,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_bAllowDynamicUpdate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_PivotPosition,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorSettings_Statics::NewProp_PivotPosition_Underlying,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabricatorSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabricatorSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabricatorSettings_Statics::ClassParams = {
		&UPrefabricatorSettings::StaticClass,
		"Prefabricator",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPrefabricatorSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabricatorSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabricatorSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabricatorSettings, 2178041482);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<UPrefabricatorSettings>()
	{
		return UPrefabricatorSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabricatorSettings(Z_Construct_UClass_UPrefabricatorSettings, &UPrefabricatorSettings::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("UPrefabricatorSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabricatorSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
