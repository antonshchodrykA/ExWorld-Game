// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ConstructionSystemRuntime/Public/Save/ConstructionSystemSaveGame.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConstructionSystemSaveGame() {}
// Cross Module References
	CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo();
	UPackage* Z_Construct_UPackage__Script_ConstructionSystemRuntime();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAssetInterface_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemSaveGame_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemSaveGame();
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemSaveSystem_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemSaveSystem();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel();
// End Cross Module References
class UScriptStruct* FConstructionSystemSavePlayerInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CONSTRUCTIONSYSTEMRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo, Z_Construct_UPackage__Script_ConstructionSystemRuntime(), TEXT("ConstructionSystemSavePlayerInfo"), sizeof(FConstructionSystemSavePlayerInfo), Get_Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Hash());
	}
	return Singleton;
}
template<> CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* StaticStruct<FConstructionSystemSavePlayerInfo>()
{
	return FConstructionSystemSavePlayerInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FConstructionSystemSavePlayerInfo(FConstructionSystemSavePlayerInfo::StaticStruct, TEXT("/Script/ConstructionSystemRuntime"), TEXT("ConstructionSystemSavePlayerInfo"), false, nullptr, nullptr);
static struct FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemSavePlayerInfo
{
	FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemSavePlayerInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ConstructionSystemSavePlayerInfo")),new UScriptStruct::TCppStructOps<FConstructionSystemSavePlayerInfo>);
	}
} ScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemSavePlayerInfo;
	struct Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ControlRotation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ControlRotation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRestorePlayerInfo_MetaData[];
#endif
		static void NewProp_bRestorePlayerInfo_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRestorePlayerInfo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FConstructionSystemSavePlayerInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_ControlRotation_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_ControlRotation = { "ControlRotation", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemSavePlayerInfo, ControlRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_ControlRotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_ControlRotation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_Transform_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemSavePlayerInfo, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_Transform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_bRestorePlayerInfo_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_bRestorePlayerInfo_SetBit(void* Obj)
	{
		((FConstructionSystemSavePlayerInfo*)Obj)->bRestorePlayerInfo = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_bRestorePlayerInfo = { "bRestorePlayerInfo", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FConstructionSystemSavePlayerInfo), &Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_bRestorePlayerInfo_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_bRestorePlayerInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_bRestorePlayerInfo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_ControlRotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_Transform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::NewProp_bRestorePlayerInfo,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
		nullptr,
		&NewStructOps,
		"ConstructionSystemSavePlayerInfo",
		sizeof(FConstructionSystemSavePlayerInfo),
		alignof(FConstructionSystemSavePlayerInfo),
		Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ConstructionSystemRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ConstructionSystemSavePlayerInfo"), sizeof(FConstructionSystemSavePlayerInfo), Get_Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo_Hash() { return 2551265013U; }
class UScriptStruct* FConstructionSystemSaveConstructedItem::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CONSTRUCTIONSYSTEMRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem, Z_Construct_UPackage__Script_ConstructionSystemRuntime(), TEXT("ConstructionSystemSaveConstructedItem"), sizeof(FConstructionSystemSaveConstructedItem), Get_Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Hash());
	}
	return Singleton;
}
template<> CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* StaticStruct<FConstructionSystemSaveConstructedItem>()
{
	return FConstructionSystemSaveConstructedItem::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FConstructionSystemSaveConstructedItem(FConstructionSystemSaveConstructedItem::StaticStruct, TEXT("/Script/ConstructionSystemRuntime"), TEXT("ConstructionSystemSaveConstructedItem"), false, nullptr, nullptr);
static struct FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemSaveConstructedItem
{
	FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemSaveConstructedItem()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ConstructionSystemSaveConstructedItem")),new UScriptStruct::TCppStructOps<FConstructionSystemSaveConstructedItem>);
	}
} ScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFConstructionSystemSaveConstructedItem;
	struct Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Seed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrefabAsset_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PrefabAsset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FConstructionSystemSaveConstructedItem>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Transform_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemSaveConstructedItem, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Transform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Seed_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemSaveConstructedItem, Seed), METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Seed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Seed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_PrefabAsset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_PrefabAsset = { "PrefabAsset", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FConstructionSystemSaveConstructedItem, PrefabAsset), Z_Construct_UClass_UPrefabricatorAssetInterface_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_PrefabAsset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_PrefabAsset_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Transform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_Seed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::NewProp_PrefabAsset,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
		nullptr,
		&NewStructOps,
		"ConstructionSystemSaveConstructedItem",
		sizeof(FConstructionSystemSaveConstructedItem),
		alignof(FConstructionSystemSaveConstructedItem),
		Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ConstructionSystemRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ConstructionSystemSaveConstructedItem"), sizeof(FConstructionSystemSaveConstructedItem), Get_Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem_Hash() { return 2277018207U; }
	void UConstructionSystemSaveGame::StaticRegisterNativesUConstructionSystemSaveGame()
	{
	}
	UClass* Z_Construct_UClass_UConstructionSystemSaveGame_NoRegister()
	{
		return UConstructionSystemSaveGame::StaticClass();
	}
	struct Z_Construct_UClass_UConstructionSystemSaveGame_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstructedItems_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ConstructedItems;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ConstructedItems_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PlayerInfo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UserIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_UserIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SaveSlotName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SaveSlotName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConstructionSystemSaveGame_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemSaveGame_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Save/ConstructionSystemSaveGame.h" },
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_ConstructedItems_MetaData[] = {
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_ConstructedItems = { "ConstructedItems", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemSaveGame, ConstructedItems), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_ConstructedItems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_ConstructedItems_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_ConstructedItems_Inner = { "ConstructedItems", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FConstructionSystemSaveConstructedItem, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_PlayerInfo_MetaData[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_PlayerInfo = { "PlayerInfo", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemSaveGame, PlayerInfo), Z_Construct_UScriptStruct_FConstructionSystemSavePlayerInfo, METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_PlayerInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_PlayerInfo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_UserIndex_MetaData[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_UserIndex = { "UserIndex", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemSaveGame, UserIndex), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_UserIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_UserIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_SaveSlotName_MetaData[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_SaveSlotName = { "SaveSlotName", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemSaveGame, SaveSlotName), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_SaveSlotName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_SaveSlotName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UConstructionSystemSaveGame_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_ConstructedItems,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_ConstructedItems_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_PlayerInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_UserIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemSaveGame_Statics::NewProp_SaveSlotName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConstructionSystemSaveGame_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConstructionSystemSaveGame>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UConstructionSystemSaveGame_Statics::ClassParams = {
		&UConstructionSystemSaveGame::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UConstructionSystemSaveGame_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::PropPointers),
		0,
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemSaveGame_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UConstructionSystemSaveGame()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UConstructionSystemSaveGame_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UConstructionSystemSaveGame, 1743015351);
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<UConstructionSystemSaveGame>()
	{
		return UConstructionSystemSaveGame::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UConstructionSystemSaveGame(Z_Construct_UClass_UConstructionSystemSaveGame, &UConstructionSystemSaveGame::StaticClass, TEXT("/Script/ConstructionSystemRuntime"), TEXT("UConstructionSystemSaveGame"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConstructionSystemSaveGame);
	void UConstructionSystemSaveSystem::StaticRegisterNativesUConstructionSystemSaveSystem()
	{
		UClass* Class = UConstructionSystemSaveSystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HandleConstructionSystemLevelLoad", &UConstructionSystemSaveSystem::execHandleConstructionSystemLevelLoad },
			{ "LoadConstructionSystemLevel", &UConstructionSystemSaveSystem::execLoadConstructionSystemLevel },
			{ "SaveConstructionSystemLevel", &UConstructionSystemSaveSystem::execSaveConstructionSystemLevel },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics
	{
		struct ConstructionSystemSaveSystem_eventHandleConstructionSystemLevelLoad_Parms
		{
			const UObject* WorldContextObject;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemSaveSystem_eventHandleConstructionSystemLevelLoad_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::NewProp_WorldContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemSaveSystem, nullptr, "HandleConstructionSystemLevelLoad", nullptr, nullptr, sizeof(ConstructionSystemSaveSystem_eventHandleConstructionSystemLevelLoad_Parms), Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics
	{
		struct ConstructionSystemSaveSystem_eventLoadConstructionSystemLevel_Parms
		{
			const UObject* WorldContextObject;
			FName LevelName;
			bool bAbsolute;
			FString SaveSlotName;
			int32 UserIndex;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_UserIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SaveSlotName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SaveSlotName;
		static void NewProp_bAbsolute_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAbsolute;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LevelName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_LevelName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_UserIndex = { "UserIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemSaveSystem_eventLoadConstructionSystemLevel_Parms, UserIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_SaveSlotName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_SaveSlotName = { "SaveSlotName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemSaveSystem_eventLoadConstructionSystemLevel_Parms, SaveSlotName), METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_SaveSlotName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_SaveSlotName_MetaData)) };
	void Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_bAbsolute_SetBit(void* Obj)
	{
		((ConstructionSystemSaveSystem_eventLoadConstructionSystemLevel_Parms*)Obj)->bAbsolute = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_bAbsolute = { "bAbsolute", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ConstructionSystemSaveSystem_eventLoadConstructionSystemLevel_Parms), &Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_bAbsolute_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_LevelName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_LevelName = { "LevelName", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemSaveSystem_eventLoadConstructionSystemLevel_Parms, LevelName), METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_LevelName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_LevelName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemSaveSystem_eventLoadConstructionSystemLevel_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_WorldContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_UserIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_SaveSlotName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_bAbsolute,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_LevelName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemSaveSystem, nullptr, "LoadConstructionSystemLevel", nullptr, nullptr, sizeof(ConstructionSystemSaveSystem_eventLoadConstructionSystemLevel_Parms), Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics
	{
		struct ConstructionSystemSaveSystem_eventSaveConstructionSystemLevel_Parms
		{
			const UObject* WorldContextObject;
			FString SaveSlotName;
			int32 UserIndex;
			bool bSavePlayerState;
		};
		static void NewProp_bSavePlayerState_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSavePlayerState;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_UserIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SaveSlotName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SaveSlotName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_bSavePlayerState_SetBit(void* Obj)
	{
		((ConstructionSystemSaveSystem_eventSaveConstructionSystemLevel_Parms*)Obj)->bSavePlayerState = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_bSavePlayerState = { "bSavePlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ConstructionSystemSaveSystem_eventSaveConstructionSystemLevel_Parms), &Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_bSavePlayerState_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_UserIndex = { "UserIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemSaveSystem_eventSaveConstructionSystemLevel_Parms, UserIndex), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_SaveSlotName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_SaveSlotName = { "SaveSlotName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemSaveSystem_eventSaveConstructionSystemLevel_Parms, SaveSlotName), METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_SaveSlotName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_SaveSlotName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemSaveSystem_eventSaveConstructionSystemLevel_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_WorldContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_bSavePlayerState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_UserIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_SaveSlotName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemSaveSystem, nullptr, "SaveConstructionSystemLevel", nullptr, nullptr, sizeof(ConstructionSystemSaveSystem_eventSaveConstructionSystemLevel_Parms), Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UConstructionSystemSaveSystem_NoRegister()
	{
		return UConstructionSystemSaveSystem::StaticClass();
	}
	struct Z_Construct_UClass_UConstructionSystemSaveSystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConstructionSystemSaveSystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UConstructionSystemSaveSystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UConstructionSystemSaveSystem_HandleConstructionSystemLevelLoad, "HandleConstructionSystemLevelLoad" }, // 145846493
		{ &Z_Construct_UFunction_UConstructionSystemSaveSystem_LoadConstructionSystemLevel, "LoadConstructionSystemLevel" }, // 733374250
		{ &Z_Construct_UFunction_UConstructionSystemSaveSystem_SaveConstructionSystemLevel, "SaveConstructionSystemLevel" }, // 1437621766
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemSaveSystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Save/ConstructionSystemSaveGame.h" },
		{ "ModuleRelativePath", "Public/Save/ConstructionSystemSaveGame.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConstructionSystemSaveSystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConstructionSystemSaveSystem>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UConstructionSystemSaveSystem_Statics::ClassParams = {
		&UConstructionSystemSaveSystem::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemSaveSystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemSaveSystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UConstructionSystemSaveSystem()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UConstructionSystemSaveSystem_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UConstructionSystemSaveSystem, 3009675779);
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<UConstructionSystemSaveSystem>()
	{
		return UConstructionSystemSaveSystem::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UConstructionSystemSaveSystem(Z_Construct_UClass_UConstructionSystemSaveSystem, &UConstructionSystemSaveSystem::StaticClass, TEXT("/Script/ConstructionSystemRuntime"), TEXT("UConstructionSystemSaveSystem"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConstructionSystemSaveSystem);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
