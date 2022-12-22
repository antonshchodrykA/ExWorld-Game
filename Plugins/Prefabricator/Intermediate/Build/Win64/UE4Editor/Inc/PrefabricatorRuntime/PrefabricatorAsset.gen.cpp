// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PrefabricatorRuntime/Public/Asset/PrefabricatorAsset.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrefabricatorAsset() {}
// Cross Module References
	PREFABRICATORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem();
	UPackage* Z_Construct_UPackage__Script_PrefabricatorRuntime();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAsset_NoRegister();
	PREFABRICATORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPrefabricatorActorData();
	PREFABRICATORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPrefabricatorComponentData();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorProperty_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftClassPath();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	PREFABRICATORRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftObjectPath();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorProperty();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorEventListener_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorEventListener();
	PREFABRICATORRUNTIME_API UFunction* Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_APrefabActor_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAssetInterface_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAssetInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAsset();
	ENGINE_API UClass* Z_Construct_UClass_UThumbnailInfo_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EComponentMobility();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAssetCollection_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAssetCollection();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
class UScriptStruct* FPrefabricatorAssetCollectionItem::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PREFABRICATORRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem, Z_Construct_UPackage__Script_PrefabricatorRuntime(), TEXT("PrefabricatorAssetCollectionItem"), sizeof(FPrefabricatorAssetCollectionItem), Get_Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Hash());
	}
	return Singleton;
}
template<> PREFABRICATORRUNTIME_API UScriptStruct* StaticStruct<FPrefabricatorAssetCollectionItem>()
{
	return FPrefabricatorAssetCollectionItem::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPrefabricatorAssetCollectionItem(FPrefabricatorAssetCollectionItem::StaticStruct, TEXT("/Script/PrefabricatorRuntime"), TEXT("PrefabricatorAssetCollectionItem"), false, nullptr, nullptr);
static struct FScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorAssetCollectionItem
{
	FScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorAssetCollectionItem()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("PrefabricatorAssetCollectionItem")),new UScriptStruct::TCppStructOps<FPrefabricatorAssetCollectionItem>);
	}
} ScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorAssetCollectionItem;
	struct Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Weight_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Weight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrefabAsset_MetaData[];
#endif
		static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_PrefabAsset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPrefabricatorAssetCollectionItem>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_Weight_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_Weight = { "Weight", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorAssetCollectionItem, Weight), METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_Weight_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_Weight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_PrefabAsset_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_PrefabAsset = { "PrefabAsset", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorAssetCollectionItem, PrefabAsset), Z_Construct_UClass_UPrefabricatorAsset_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_PrefabAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_PrefabAsset_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_Weight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::NewProp_PrefabAsset,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
		nullptr,
		&NewStructOps,
		"PrefabricatorAssetCollectionItem",
		sizeof(FPrefabricatorAssetCollectionItem),
		alignof(FPrefabricatorAssetCollectionItem),
		Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PrefabricatorRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PrefabricatorAssetCollectionItem"), sizeof(FPrefabricatorAssetCollectionItem), Get_Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem_Hash() { return 3697669926U; }
class UScriptStruct* FPrefabricatorActorData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PREFABRICATORRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorActorData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPrefabricatorActorData, Z_Construct_UPackage__Script_PrefabricatorRuntime(), TEXT("PrefabricatorActorData"), sizeof(FPrefabricatorActorData), Get_Z_Construct_UScriptStruct_FPrefabricatorActorData_Hash());
	}
	return Singleton;
}
template<> PREFABRICATORRUNTIME_API UScriptStruct* StaticStruct<FPrefabricatorActorData>()
{
	return FPrefabricatorActorData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPrefabricatorActorData(FPrefabricatorActorData::StaticStruct, TEXT("/Script/PrefabricatorRuntime"), TEXT("PrefabricatorActorData"), false, nullptr, nullptr);
static struct FScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorActorData
{
	FScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorActorData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("PrefabricatorActorData")),new UScriptStruct::TCppStructOps<FPrefabricatorActorData>);
	}
} ScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorActorData;
	struct Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ActorName;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Components_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Components;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Components_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Properties_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Properties;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Properties_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClassPathRef_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ClassPathRef;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClassPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ClassPath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RelativeTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RelativeTransform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrefabItemID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PrefabItemID;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPrefabricatorActorData>();
	}
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ActorName_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ActorName = { "ActorName", nullptr, (EPropertyFlags)0x0010000800000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorActorData, ActorName), METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ActorName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ActorName_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Components_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Components = { "Components", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorActorData, Components), METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Components_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Components_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Components_Inner = { "Components", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FPrefabricatorComponentData, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Properties_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Properties = { "Properties", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorActorData, Properties), METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Properties_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Properties_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Properties_Inner = { "Properties", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UPrefabricatorProperty_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPathRef_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPathRef = { "ClassPathRef", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorActorData, ClassPathRef), Z_Construct_UScriptStruct_FSoftClassPath, METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPathRef_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPathRef_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPath_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPath = { "ClassPath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorActorData, ClassPath), METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_RelativeTransform_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_RelativeTransform = { "RelativeTransform", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorActorData, RelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_RelativeTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_RelativeTransform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_PrefabItemID_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_PrefabItemID = { "PrefabItemID", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorActorData, PrefabItemID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_PrefabItemID_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_PrefabItemID_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ActorName,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Components,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Components_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Properties,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_Properties_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPathRef,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_ClassPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_RelativeTransform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::NewProp_PrefabItemID,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
		nullptr,
		&NewStructOps,
		"PrefabricatorActorData",
		sizeof(FPrefabricatorActorData),
		alignof(FPrefabricatorActorData),
		Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPrefabricatorActorData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorActorData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PrefabricatorRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PrefabricatorActorData"), sizeof(FPrefabricatorActorData), Get_Z_Construct_UScriptStruct_FPrefabricatorActorData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPrefabricatorActorData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorActorData_Hash() { return 3531888242U; }
class UScriptStruct* FPrefabricatorComponentData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PREFABRICATORRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorComponentData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPrefabricatorComponentData, Z_Construct_UPackage__Script_PrefabricatorRuntime(), TEXT("PrefabricatorComponentData"), sizeof(FPrefabricatorComponentData), Get_Z_Construct_UScriptStruct_FPrefabricatorComponentData_Hash());
	}
	return Singleton;
}
template<> PREFABRICATORRUNTIME_API UScriptStruct* StaticStruct<FPrefabricatorComponentData>()
{
	return FPrefabricatorComponentData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPrefabricatorComponentData(FPrefabricatorComponentData::StaticStruct, TEXT("/Script/PrefabricatorRuntime"), TEXT("PrefabricatorComponentData"), false, nullptr, nullptr);
static struct FScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorComponentData
{
	FScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorComponentData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("PrefabricatorComponentData")),new UScriptStruct::TCppStructOps<FPrefabricatorComponentData>);
	}
} ScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorComponentData;
	struct Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Properties_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Properties;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Properties_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ComponentName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ComponentName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RelativeTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RelativeTransform;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPrefabricatorComponentData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_Properties_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_Properties = { "Properties", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorComponentData, Properties), METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_Properties_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_Properties_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_Properties_Inner = { "Properties", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UPrefabricatorProperty_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_ComponentName_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_ComponentName = { "ComponentName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorComponentData, ComponentName), METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_ComponentName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_ComponentName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_RelativeTransform_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_RelativeTransform = { "RelativeTransform", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorComponentData, RelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_RelativeTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_RelativeTransform_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_Properties,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_Properties_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_ComponentName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::NewProp_RelativeTransform,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
		nullptr,
		&NewStructOps,
		"PrefabricatorComponentData",
		sizeof(FPrefabricatorComponentData),
		alignof(FPrefabricatorComponentData),
		Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPrefabricatorComponentData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorComponentData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PrefabricatorRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PrefabricatorComponentData"), sizeof(FPrefabricatorComponentData), Get_Z_Construct_UScriptStruct_FPrefabricatorComponentData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPrefabricatorComponentData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorComponentData_Hash() { return 3227881856U; }
class UScriptStruct* FPrefabricatorPropertyAssetMapping::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PREFABRICATORRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping, Z_Construct_UPackage__Script_PrefabricatorRuntime(), TEXT("PrefabricatorPropertyAssetMapping"), sizeof(FPrefabricatorPropertyAssetMapping), Get_Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Hash());
	}
	return Singleton;
}
template<> PREFABRICATORRUNTIME_API UScriptStruct* StaticStruct<FPrefabricatorPropertyAssetMapping>()
{
	return FPrefabricatorPropertyAssetMapping::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPrefabricatorPropertyAssetMapping(FPrefabricatorPropertyAssetMapping::StaticStruct, TEXT("/Script/PrefabricatorRuntime"), TEXT("PrefabricatorPropertyAssetMapping"), false, nullptr, nullptr);
static struct FScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorPropertyAssetMapping
{
	FScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorPropertyAssetMapping()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("PrefabricatorPropertyAssetMapping")),new UScriptStruct::TCppStructOps<FPrefabricatorPropertyAssetMapping>);
	}
} ScriptStruct_PrefabricatorRuntime_StaticRegisterNativesFPrefabricatorPropertyAssetMapping;
	struct Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseQuotes_MetaData[];
#endif
		static void NewProp_bUseQuotes_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseQuotes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AssetObjectPath_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_AssetObjectPath;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AssetClassName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AssetClassName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AssetReference_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AssetReference;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPrefabricatorPropertyAssetMapping>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_bUseQuotes_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_bUseQuotes_SetBit(void* Obj)
	{
		((FPrefabricatorPropertyAssetMapping*)Obj)->bUseQuotes = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_bUseQuotes = { "bUseQuotes", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPrefabricatorPropertyAssetMapping), &Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_bUseQuotes_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_bUseQuotes_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_bUseQuotes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetObjectPath_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetObjectPath = { "AssetObjectPath", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorPropertyAssetMapping, AssetObjectPath), METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetObjectPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetObjectPath_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetClassName_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetClassName = { "AssetClassName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorPropertyAssetMapping, AssetClassName), METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetClassName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetClassName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetReference_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetReference = { "AssetReference", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FPrefabricatorPropertyAssetMapping, AssetReference), Z_Construct_UScriptStruct_FSoftObjectPath, METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetReference_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetReference_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_bUseQuotes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetObjectPath,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetClassName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::NewProp_AssetReference,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
		nullptr,
		&NewStructOps,
		"PrefabricatorPropertyAssetMapping",
		sizeof(FPrefabricatorPropertyAssetMapping),
		alignof(FPrefabricatorPropertyAssetMapping),
		Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_PrefabricatorRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PrefabricatorPropertyAssetMapping"), sizeof(FPrefabricatorPropertyAssetMapping), Get_Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping_Hash() { return 4026501164U; }
	void UPrefabricatorProperty::StaticRegisterNativesUPrefabricatorProperty()
	{
	}
	UClass* Z_Construct_UClass_UPrefabricatorProperty_NoRegister()
	{
		return UPrefabricatorProperty::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabricatorProperty_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CrossReferencePrefabActorId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CrossReferencePrefabActorId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsCrossReferencedActor_MetaData[];
#endif
		static void NewProp_bIsCrossReferencedActor_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsCrossReferencedActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AssetSoftReferenceMappings_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_AssetSoftReferenceMappings;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AssetSoftReferenceMappings_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExportedValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ExportedValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PropertyName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabricatorProperty_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorProperty_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Asset/PrefabricatorAsset.h" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_CrossReferencePrefabActorId_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_CrossReferencePrefabActorId = { "CrossReferencePrefabActorId", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorProperty, CrossReferencePrefabActorId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_CrossReferencePrefabActorId_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_CrossReferencePrefabActorId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_bIsCrossReferencedActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	void Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_bIsCrossReferencedActor_SetBit(void* Obj)
	{
		((UPrefabricatorProperty*)Obj)->bIsCrossReferencedActor = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_bIsCrossReferencedActor = { "bIsCrossReferencedActor", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPrefabricatorProperty), &Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_bIsCrossReferencedActor_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_bIsCrossReferencedActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_bIsCrossReferencedActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_AssetSoftReferenceMappings_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_AssetSoftReferenceMappings = { "AssetSoftReferenceMappings", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorProperty, AssetSoftReferenceMappings), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_AssetSoftReferenceMappings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_AssetSoftReferenceMappings_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_AssetSoftReferenceMappings_Inner = { "AssetSoftReferenceMappings", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FPrefabricatorPropertyAssetMapping, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_ExportedValue_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_ExportedValue = { "ExportedValue", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorProperty, ExportedValue), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_ExportedValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_ExportedValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_PropertyName_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorProperty, PropertyName), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_PropertyName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_PropertyName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPrefabricatorProperty_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_CrossReferencePrefabActorId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_bIsCrossReferencedActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_AssetSoftReferenceMappings,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_AssetSoftReferenceMappings_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_ExportedValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorProperty_Statics::NewProp_PropertyName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabricatorProperty_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabricatorProperty>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabricatorProperty_Statics::ClassParams = {
		&UPrefabricatorProperty::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPrefabricatorProperty_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorProperty_Statics::PropPointers),
		0,
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorProperty_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorProperty_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabricatorProperty()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabricatorProperty_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabricatorProperty, 2045941170);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<UPrefabricatorProperty>()
	{
		return UPrefabricatorProperty::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabricatorProperty(Z_Construct_UClass_UPrefabricatorProperty, &UPrefabricatorProperty::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("UPrefabricatorProperty"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabricatorProperty);
	static FName NAME_UPrefabricatorEventListener_PostSpawn = FName(TEXT("PostSpawn"));
	void UPrefabricatorEventListener::PostSpawn(APrefabActor* Prefab)
	{
		PrefabricatorEventListener_eventPostSpawn_Parms Parms;
		Parms.Prefab=Prefab;
		ProcessEvent(FindFunctionChecked(NAME_UPrefabricatorEventListener_PostSpawn),&Parms);
	}
	void UPrefabricatorEventListener::StaticRegisterNativesUPrefabricatorEventListener()
	{
		UClass* Class = UPrefabricatorEventListener::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "PostSpawn", &UPrefabricatorEventListener::execPostSpawn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Prefab;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::NewProp_Prefab = { "Prefab", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PrefabricatorEventListener_eventPostSpawn_Parms, Prefab), Z_Construct_UClass_APrefabActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::NewProp_Prefab,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prefabricator" },
		{ "Comment", "/** Called when the prefab and all its child prefabs have been spawned and initialized */" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
		{ "ToolTip", "Called when the prefab and all its child prefabs have been spawned and initialized" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPrefabricatorEventListener, nullptr, "PostSpawn", nullptr, nullptr, sizeof(PrefabricatorEventListener_eventPostSpawn_Parms), Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPrefabricatorEventListener_NoRegister()
	{
		return UPrefabricatorEventListener::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabricatorEventListener_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabricatorEventListener_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPrefabricatorEventListener_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPrefabricatorEventListener_PostSpawn, "PostSpawn" }, // 1038472449
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorEventListener_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Asset/PrefabricatorAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabricatorEventListener_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabricatorEventListener>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabricatorEventListener_Statics::ClassParams = {
		&UPrefabricatorEventListener::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorEventListener_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorEventListener_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabricatorEventListener()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabricatorEventListener_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabricatorEventListener, 1635186921);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<UPrefabricatorEventListener>()
	{
		return UPrefabricatorEventListener::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabricatorEventListener(Z_Construct_UClass_UPrefabricatorEventListener, &UPrefabricatorEventListener::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("UPrefabricatorEventListener"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabricatorEventListener);
	void UPrefabricatorAssetInterface::StaticRegisterNativesUPrefabricatorAssetInterface()
	{
	}
	UClass* Z_Construct_UClass_UPrefabricatorAssetInterface_NoRegister()
	{
		return UPrefabricatorAssetInterface::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabricatorAssetInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bReplicates_MetaData[];
#endif
		static void NewProp_bReplicates_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bReplicates;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventListener_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_EventListener;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Asset/PrefabricatorAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_bReplicates_MetaData[] = {
		{ "Category", "Replication" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	void Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_bReplicates_SetBit(void* Obj)
	{
		((UPrefabricatorAssetInterface*)Obj)->bReplicates = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_bReplicates = { "bReplicates", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPrefabricatorAssetInterface), &Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_bReplicates_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_bReplicates_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_bReplicates_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_EventListener_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_EventListener = { "EventListener", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorAssetInterface, EventListener), Z_Construct_UClass_UPrefabricatorEventListener_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_EventListener_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_EventListener_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_bReplicates,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::NewProp_EventListener,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabricatorAssetInterface>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::ClassParams = {
		&UPrefabricatorAssetInterface::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::PropPointers),
		0,
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabricatorAssetInterface()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabricatorAssetInterface_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabricatorAssetInterface, 3217249019);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<UPrefabricatorAssetInterface>()
	{
		return UPrefabricatorAssetInterface::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabricatorAssetInterface(Z_Construct_UClass_UPrefabricatorAssetInterface, &UPrefabricatorAssetInterface::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("UPrefabricatorAssetInterface"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabricatorAssetInterface);
	void UPrefabricatorAsset::StaticRegisterNativesUPrefabricatorAsset()
	{
	}
	UClass* Z_Construct_UClass_UPrefabricatorAsset_NoRegister()
	{
		return UPrefabricatorAsset::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabricatorAsset_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_Version;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ThumbnailInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ThumbnailInfo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastUpdateID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LastUpdateID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrefabMobility_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_PrefabMobility;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorData_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActorData;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ActorData_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabricatorAsset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrefabricatorAssetInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAsset_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Asset/PrefabricatorAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_Version_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorAsset, Version), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_Version_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_Version_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ThumbnailInfo_MetaData[] = {
		{ "Comment", "/** Information for thumbnail rendering */" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
		{ "ToolTip", "Information for thumbnail rendering" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ThumbnailInfo = { "ThumbnailInfo", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorAsset, ThumbnailInfo), Z_Construct_UClass_UThumbnailInfo_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ThumbnailInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ThumbnailInfo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_LastUpdateID_MetaData[] = {
		{ "Comment", "// The ID that is regenerated on every update\n// This allows prefab actors to test against their own LastUpdateID and determine if a refresh is needed\n" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
		{ "ToolTip", "The ID that is regenerated on every update\nThis allows prefab actors to test against their own LastUpdateID and determine if a refresh is needed" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_LastUpdateID = { "LastUpdateID", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorAsset, LastUpdateID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_LastUpdateID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_LastUpdateID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_PrefabMobility_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_PrefabMobility = { "PrefabMobility", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorAsset, PrefabMobility), Z_Construct_UEnum_Engine_EComponentMobility, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_PrefabMobility_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_PrefabMobility_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ActorData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ActorData = { "ActorData", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorAsset, ActorData), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ActorData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ActorData_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ActorData_Inner = { "ActorData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FPrefabricatorActorData, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPrefabricatorAsset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_Version,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ThumbnailInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_LastUpdateID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_PrefabMobility,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ActorData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAsset_Statics::NewProp_ActorData_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabricatorAsset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabricatorAsset>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabricatorAsset_Statics::ClassParams = {
		&UPrefabricatorAsset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPrefabricatorAsset_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAsset_Statics::PropPointers),
		0,
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAsset_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAsset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabricatorAsset()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabricatorAsset_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabricatorAsset, 808472060);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<UPrefabricatorAsset>()
	{
		return UPrefabricatorAsset::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabricatorAsset(Z_Construct_UClass_UPrefabricatorAsset, &UPrefabricatorAsset::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("UPrefabricatorAsset"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabricatorAsset);
	void UPrefabricatorAssetCollection::StaticRegisterNativesUPrefabricatorAssetCollection()
	{
	}
	UClass* Z_Construct_UClass_UPrefabricatorAssetCollection_NoRegister()
	{
		return UPrefabricatorAssetCollection::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabricatorAssetCollection_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_Version;
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CustomThumbnail_MetaData[];
#endif
		static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_CustomThumbnail;
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Prefabs_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Prefabs;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Prefabs_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UPrefabricatorAssetInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Asset/PrefabricatorAsset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Version_MetaData[] = {
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorAssetCollection, Version), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Version_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Version_MetaData)) };
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_CustomThumbnail_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_CustomThumbnail = { "CustomThumbnail", nullptr, (EPropertyFlags)0x0014000800000001, UE4CodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorAssetCollection, CustomThumbnail), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_CustomThumbnail_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_CustomThumbnail_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Prefabs_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorAsset.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Prefabs = { "Prefabs", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorAssetCollection, Prefabs), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Prefabs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Prefabs_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Prefabs_Inner = { "Prefabs", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FPrefabricatorAssetCollectionItem, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Version,
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_CustomThumbnail,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Prefabs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::NewProp_Prefabs_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabricatorAssetCollection>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::ClassParams = {
		&UPrefabricatorAssetCollection::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::PropPointers),
		0,
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabricatorAssetCollection()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabricatorAssetCollection_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabricatorAssetCollection, 3725036290);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<UPrefabricatorAssetCollection>()
	{
		return UPrefabricatorAssetCollection::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabricatorAssetCollection(Z_Construct_UClass_UPrefabricatorAssetCollection, &UPrefabricatorAssetCollection::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("UPrefabricatorAssetCollection"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabricatorAssetCollection);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
