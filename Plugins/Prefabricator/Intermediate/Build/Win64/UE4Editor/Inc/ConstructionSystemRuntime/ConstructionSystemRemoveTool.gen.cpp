// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ConstructionSystemRuntime/Public/ConstructionSystem/Tools/ConstructionSystemRemoveTool.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConstructionSystemRemoveTool() {}
// Cross Module References
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemRemoveTool_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemRemoveTool();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemTool();
	UPackage* Z_Construct_UPackage__Script_ConstructionSystemRuntime();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemRemoveTool_HandleInput_RemoveAtCursor();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_APrefabActor_NoRegister();
// End Cross Module References
	void UConstructionSystemRemoveTool::StaticRegisterNativesUConstructionSystemRemoveTool()
	{
		UClass* Class = UConstructionSystemRemoveTool::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HandleInput_RemoveAtCursor", &UConstructionSystemRemoveTool::execHandleInput_RemoveAtCursor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UConstructionSystemRemoveTool_HandleInput_RemoveAtCursor_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemRemoveTool_HandleInput_RemoveAtCursor_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ConstructionSystem/Tools/ConstructionSystemRemoveTool.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemRemoveTool_HandleInput_RemoveAtCursor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemRemoveTool, nullptr, "HandleInput_RemoveAtCursor", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemRemoveTool_HandleInput_RemoveAtCursor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemRemoveTool_HandleInput_RemoveAtCursor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemRemoveTool_HandleInput_RemoveAtCursor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemRemoveTool_HandleInput_RemoveAtCursor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UConstructionSystemRemoveTool_NoRegister()
	{
		return UConstructionSystemRemoveTool::StaticClass();
	}
	struct Z_Construct_UClass_UConstructionSystemRemoveTool_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FocusedActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FWeakObjectPropertyParams NewProp_FocusedActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TraceDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TraceDistance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UConstructionSystemTool,
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UConstructionSystemRemoveTool_HandleInput_RemoveAtCursor, "HandleInput_RemoveAtCursor" }, // 3636801066
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ConstructionSystem/Tools/ConstructionSystemRemoveTool.h" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/Tools/ConstructionSystemRemoveTool.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_FocusedActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/ConstructionSystem/Tools/ConstructionSystemRemoveTool.h" },
	};
#endif
	const UE4CodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_FocusedActor = { "FocusedActor", nullptr, (EPropertyFlags)0x0044000000002000, UE4CodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemRemoveTool, FocusedActor), Z_Construct_UClass_APrefabActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_FocusedActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_FocusedActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_TraceDistance_MetaData[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/Tools/ConstructionSystemRemoveTool.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_TraceDistance = { "TraceDistance", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemRemoveTool, TraceDistance), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_TraceDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_TraceDistance_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_FocusedActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::NewProp_TraceDistance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConstructionSystemRemoveTool>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::ClassParams = {
		&UConstructionSystemRemoveTool::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::PropPointers),
		0,
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UConstructionSystemRemoveTool()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UConstructionSystemRemoveTool_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UConstructionSystemRemoveTool, 1387782853);
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<UConstructionSystemRemoveTool>()
	{
		return UConstructionSystemRemoveTool::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UConstructionSystemRemoveTool(Z_Construct_UClass_UConstructionSystemRemoveTool, &UConstructionSystemRemoveTool::StaticClass, TEXT("/Script/ConstructionSystemRuntime"), TEXT("UConstructionSystemRemoveTool"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConstructionSystemRemoveTool);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
