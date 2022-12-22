// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PrefabricatorRuntime/Public/Prefab/PrefabActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrefabActor() {}
// Cross Module References
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_APrefabActor_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_APrefabActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_PrefabricatorRuntime();
	PREFABRICATORRUNTIME_API UFunction* Z_Construct_UFunction_APrefabActor_GetPrefabAsset();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAsset_NoRegister();
	PREFABRICATORRUNTIME_API UFunction* Z_Construct_UFunction_APrefabActor_IsPrefabOutdated();
	PREFABRICATORRUNTIME_API UFunction* Z_Construct_UFunction_APrefabActor_LoadPrefab();
	PREFABRICATORRUNTIME_API UFunction* Z_Construct_UFunction_APrefabActor_RandomizeSeed();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRandomStream();
	PREFABRICATORRUNTIME_API UFunction* Z_Construct_UFunction_APrefabActor_SavePrefab();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabComponent_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_AReplicablePrefabActor_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_AReplicablePrefabActor();
// End Cross Module References
	void APrefabActor::StaticRegisterNativesAPrefabActor()
	{
		UClass* Class = APrefabActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetPrefabAsset", &APrefabActor::execGetPrefabAsset },
			{ "IsPrefabOutdated", &APrefabActor::execIsPrefabOutdated },
			{ "LoadPrefab", &APrefabActor::execLoadPrefab },
			{ "RandomizeSeed", &APrefabActor::execRandomizeSeed },
			{ "SavePrefab", &APrefabActor::execSavePrefab },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics
	{
		struct PrefabActor_eventGetPrefabAsset_Parms
		{
			UPrefabricatorAsset* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PrefabActor_eventGetPrefabAsset_Parms, ReturnValue), Z_Construct_UClass_UPrefabricatorAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APrefabActor, nullptr, "GetPrefabAsset", nullptr, nullptr, sizeof(PrefabActor_eventGetPrefabAsset_Parms), Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APrefabActor_GetPrefabAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APrefabActor_GetPrefabAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics
	{
		struct PrefabActor_eventIsPrefabOutdated_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((PrefabActor_eventIsPrefabOutdated_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PrefabActor_eventIsPrefabOutdated_Parms), &Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APrefabActor, nullptr, "IsPrefabOutdated", nullptr, nullptr, sizeof(PrefabActor_eventIsPrefabOutdated_Parms), Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APrefabActor_IsPrefabOutdated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APrefabActor_IsPrefabOutdated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APrefabActor_LoadPrefab_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APrefabActor_LoadPrefab_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prefabricator" },
		{ "Comment", "/// End of AActor Interface \n" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
		{ "ToolTip", "End of AActor Interface" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APrefabActor_LoadPrefab_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APrefabActor, nullptr, "LoadPrefab", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APrefabActor_LoadPrefab_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APrefabActor_LoadPrefab_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APrefabActor_LoadPrefab()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APrefabActor_LoadPrefab_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics
	{
		struct PrefabActor_eventRandomizeSeed_Parms
		{
			FRandomStream InRandom;
			bool bRecursive;
		};
		static void NewProp_bRecursive_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRecursive;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InRandom_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InRandom;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::NewProp_bRecursive_SetBit(void* Obj)
	{
		((PrefabActor_eventRandomizeSeed_Parms*)Obj)->bRecursive = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::NewProp_bRecursive = { "bRecursive", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(PrefabActor_eventRandomizeSeed_Parms), &Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::NewProp_bRecursive_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::NewProp_InRandom_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::NewProp_InRandom = { "InRandom", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PrefabActor_eventRandomizeSeed_Parms, InRandom), Z_Construct_UScriptStruct_FRandomStream, METADATA_PARAMS(Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::NewProp_InRandom_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::NewProp_InRandom_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::NewProp_bRecursive,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::NewProp_InRandom,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prefabricator" },
		{ "CPP_Default_bRecursive", "true" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APrefabActor, nullptr, "RandomizeSeed", nullptr, nullptr, sizeof(PrefabActor_eventRandomizeSeed_Parms), Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APrefabActor_RandomizeSeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APrefabActor_RandomizeSeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APrefabActor_SavePrefab_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APrefabActor_SavePrefab_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APrefabActor_SavePrefab_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APrefabActor, nullptr, "SavePrefab", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APrefabActor_SavePrefab_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APrefabActor_SavePrefab_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APrefabActor_SavePrefab()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APrefabActor_SavePrefab_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APrefabActor_NoRegister()
	{
		return APrefabActor::StaticClass();
	}
	struct Z_Construct_UClass_APrefabActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Seed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastUpdateID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LastUpdateID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrefabComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PrefabComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrefabActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APrefabActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APrefabActor_GetPrefabAsset, "GetPrefabAsset" }, // 3378360949
		{ &Z_Construct_UFunction_APrefabActor_IsPrefabOutdated, "IsPrefabOutdated" }, // 867228790
		{ &Z_Construct_UFunction_APrefabActor_LoadPrefab, "LoadPrefab" }, // 184750222
		{ &Z_Construct_UFunction_APrefabActor_RandomizeSeed, "RandomizeSeed" }, // 2999907398
		{ &Z_Construct_UFunction_APrefabActor_SavePrefab, "SavePrefab" }, // 1452421575
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IgnoreCategoryKeywordsInSubclasses", "true" },
		{ "IncludePath", "Prefab/PrefabActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "IsConversionRoot", "true" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabActor_Statics::NewProp_Seed_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_APrefabActor_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APrefabActor, Seed), METADATA_PARAMS(Z_Construct_UClass_APrefabActor_Statics::NewProp_Seed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabActor_Statics::NewProp_Seed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabActor_Statics::NewProp_LastUpdateID_MetaData[] = {
		{ "Comment", "// The last update ID of the prefab asset when this actor was refreshed from it\n// This is used to test if the prefab has changed since we last recreated it\n" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
		{ "ToolTip", "The last update ID of the prefab asset when this actor was refreshed from it\nThis is used to test if the prefab has changed since we last recreated it" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_APrefabActor_Statics::NewProp_LastUpdateID = { "LastUpdateID", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APrefabActor, LastUpdateID), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UClass_APrefabActor_Statics::NewProp_LastUpdateID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabActor_Statics::NewProp_LastUpdateID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabActor_Statics::NewProp_PrefabComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ExposeFunctionCategories", "Prefabricator,Mobility" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APrefabActor_Statics::NewProp_PrefabComponent = { "PrefabComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APrefabActor, PrefabComponent), Z_Construct_UClass_UPrefabComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APrefabActor_Statics::NewProp_PrefabComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabActor_Statics::NewProp_PrefabComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APrefabActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabActor_Statics::NewProp_Seed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabActor_Statics::NewProp_LastUpdateID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabActor_Statics::NewProp_PrefabComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrefabActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrefabActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrefabActor_Statics::ClassParams = {
		&APrefabActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APrefabActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APrefabActor_Statics::PropPointers),
		0,
		0x009000A4u,
		0x00000010u,
		METADATA_PARAMS(Z_Construct_UClass_APrefabActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrefabActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrefabActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrefabActor, 2699968788);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<APrefabActor>()
	{
		return APrefabActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrefabActor(Z_Construct_UClass_APrefabActor, &APrefabActor::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("APrefabActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrefabActor);
	void AReplicablePrefabActor::StaticRegisterNativesAReplicablePrefabActor()
	{
	}
	UClass* Z_Construct_UClass_AReplicablePrefabActor_NoRegister()
	{
		return AReplicablePrefabActor::StaticClass();
	}
	struct Z_Construct_UClass_AReplicablePrefabActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AReplicablePrefabActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APrefabActor,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReplicablePrefabActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IgnoreCategoryKeywordsInSubclasses", "true" },
		{ "IncludePath", "Prefab/PrefabActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "IsConversionRoot", "true" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AReplicablePrefabActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AReplicablePrefabActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AReplicablePrefabActor_Statics::ClassParams = {
		&AReplicablePrefabActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		0x00000010u,
		METADATA_PARAMS(Z_Construct_UClass_AReplicablePrefabActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AReplicablePrefabActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AReplicablePrefabActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AReplicablePrefabActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AReplicablePrefabActor, 2636124525);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<AReplicablePrefabActor>()
	{
		return AReplicablePrefabActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AReplicablePrefabActor(Z_Construct_UClass_AReplicablePrefabActor, &AReplicablePrefabActor::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("AReplicablePrefabActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AReplicablePrefabActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
