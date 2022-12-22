// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ConstructionSystemRuntime/Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConstructionSystemUIAsset() {}
// Cross Module References
	CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FConstructionSystemUICategory();
	UPackage* Z_Construct_UPackage__Script_ConstructionSystemRuntime();
	CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAssetInterface_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemUIAsset_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemUIAsset();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
// End Cross Module References
class UScriptStruct* FConstructionSystemUICategory::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CONSTRUCTIONSYSTEMRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemUICategory_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FConstructionSystemUICategory, Z_Construct_UPackage__Script_ConstructionSystemRuntime(), TEXT("ConstructionSystemUICategory"), sizeof(FConstructionSystemUICategory), Get_Z_Construct_UScriptStruct_FConstructionSystemUICategory_Hash());
	}
	return Singleton;
}
template<> CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* StaticStruct<FConstructionSystemUICategory>()
{
	return FConstructionSystemUICategory::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FConstructionSystemUICategory(FConstructionSystemUICategory::StaticStruct, TEXT("/Script/ConstructionSystemRuntime"), TEXT("ConstructionSystemUICategory"), false, nullptr, nullptr);
static struct FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemUICategory
{
	FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemUICategory()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ConstructionSystemUICategory")),new UScriptStruct::TCppStructOps<FConstructionSystemUICategory>);
	}
} ScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemUICategory;
	struct Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrefabEntries_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PrefabEntries;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PrefabEntries_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Icon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_DisplayName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FConstructionSystemUICategory>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_PrefabEntries_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_PrefabEntries = { "PrefabEntries", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemUICategory, PrefabEntries), METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_PrefabEntries_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_PrefabEntries_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_PrefabEntries_Inner = { "PrefabEntries", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_Icon_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemUICategory, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_Icon_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_Icon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_DisplayName_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemUICategory, DisplayName), METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_DisplayName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_DisplayName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_PrefabEntries,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_PrefabEntries_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_Icon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::NewProp_DisplayName,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
		nullptr,
		&NewStructOps,
		"ConstructionSystemUICategory",
		sizeof(FConstructionSystemUICategory),
		alignof(FConstructionSystemUICategory),
		Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FConstructionSystemUICategory()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemUICategory_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ConstructionSystemRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ConstructionSystemUICategory"), sizeof(FConstructionSystemUICategory), Get_Z_Construct_UScriptStruct_FConstructionSystemUICategory_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FConstructionSystemUICategory_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemUICategory_Hash() { return 3657242260U; }
class UScriptStruct* FConstructionSystemUIPrefabEntry::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CONSTRUCTIONSYSTEMRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry, Z_Construct_UPackage__Script_ConstructionSystemRuntime(), TEXT("ConstructionSystemUIPrefabEntry"), sizeof(FConstructionSystemUIPrefabEntry), Get_Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Hash());
	}
	return Singleton;
}
template<> CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* StaticStruct<FConstructionSystemUIPrefabEntry>()
{
	return FConstructionSystemUIPrefabEntry::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FConstructionSystemUIPrefabEntry(FConstructionSystemUIPrefabEntry::StaticStruct, TEXT("/Script/ConstructionSystemRuntime"), TEXT("ConstructionSystemUIPrefabEntry"), false, nullptr, nullptr);
static struct FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemUIPrefabEntry
{
	FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemUIPrefabEntry()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ConstructionSystemUIPrefabEntry")),new UScriptStruct::TCppStructOps<FConstructionSystemUIPrefabEntry>);
	}
} ScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemUIPrefabEntry;
	struct Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Prefab_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Prefab;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Icon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tooltip_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_Tooltip;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DisplayName_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_DisplayName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FConstructionSystemUIPrefabEntry>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Prefab_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Prefab = { "Prefab", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemUIPrefabEntry, Prefab), Z_Construct_UClass_UPrefabricatorAssetInterface_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Prefab_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Prefab_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Icon_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemUIPrefabEntry, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Icon_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Icon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Tooltip_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Tooltip = { "Tooltip", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemUIPrefabEntry, Tooltip), METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Tooltip_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Tooltip_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_DisplayName_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_DisplayName = { "DisplayName", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemUIPrefabEntry, DisplayName), METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_DisplayName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_DisplayName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Prefab,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Icon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_Tooltip,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::NewProp_DisplayName,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
		nullptr,
		&NewStructOps,
		"ConstructionSystemUIPrefabEntry",
		sizeof(FConstructionSystemUIPrefabEntry),
		alignof(FConstructionSystemUIPrefabEntry),
		Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ConstructionSystemRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ConstructionSystemUIPrefabEntry"), sizeof(FConstructionSystemUIPrefabEntry), Get_Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemUIPrefabEntry_Hash() { return 1716987017U; }
	void UConstructionSystemUIAsset::StaticRegisterNativesUConstructionSystemUIAsset()
	{
	}
	UClass* Z_Construct_UClass_UConstructionSystemUIAsset_NoRegister()
	{
		return UConstructionSystemUIAsset::StaticClass();
	}
	struct Z_Construct_UClass_UConstructionSystemUIAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Categories_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Categories;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Categories_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MenuTitle_MetaData[];
#endif
		static const UE4CodeGen_Private::FTextPropertyParams NewProp_MenuTitle;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConstructionSystemUIAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemUIAsset_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_Categories_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_Categories = { "Categories", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemUIAsset, Categories), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_Categories_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_Categories_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_Categories_Inner = { "Categories", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FConstructionSystemUICategory, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_MenuTitle_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUIAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FTextPropertyParams Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_MenuTitle = { "MenuTitle", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemUIAsset, MenuTitle), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_MenuTitle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_MenuTitle_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UConstructionSystemUIAsset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_Categories,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_Categories_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemUIAsset_Statics::NewProp_MenuTitle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConstructionSystemUIAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConstructionSystemUIAsset>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UConstructionSystemUIAsset_Statics::ClassParams = {
		&UConstructionSystemUIAsset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UConstructionSystemUIAsset_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemUIAsset_Statics::PropPointers),
		0,
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemUIAsset_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemUIAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UConstructionSystemUIAsset()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UConstructionSystemUIAsset_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UConstructionSystemUIAsset, 3420984455);
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<UConstructionSystemUIAsset>()
	{
		return UConstructionSystemUIAsset::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UConstructionSystemUIAsset(Z_Construct_UClass_UConstructionSystemUIAsset, &UConstructionSystemUIAsset::StaticClass, TEXT("/Script/ConstructionSystemRuntime"), TEXT("UConstructionSystemUIAsset"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConstructionSystemUIAsset);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
