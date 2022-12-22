// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ConstructionSystemRuntime/Public/ConstructionSystem/UI/ConstructionSystemUI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConstructionSystemUI() {}
// Cross Module References
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemBuildUI_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemBuildUI();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_ConstructionSystemRuntime();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemComponent_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemUIAsset_NoRegister();
// End Cross Module References
	void IConstructionSystemBuildUI::SetConstructionSystem(UConstructionSystemComponent* ConstructionSystem)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetConstructionSystem instead.");
	}
	void IConstructionSystemBuildUI::SetUIAsset(UConstructionSystemUIAsset* UIAsset)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetUIAsset instead.");
	}
	void UConstructionSystemBuildUI::StaticRegisterNativesUConstructionSystemBuildUI()
	{
	}
	struct Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstructionSystem_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConstructionSystem;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::NewProp_ConstructionSystem_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::NewProp_ConstructionSystem = { "ConstructionSystem", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemBuildUI_eventSetConstructionSystem_Parms, ConstructionSystem), Z_Construct_UClass_UConstructionSystemComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::NewProp_ConstructionSystem_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::NewProp_ConstructionSystem_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::NewProp_ConstructionSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemBuildUI, nullptr, "SetConstructionSystem", nullptr, nullptr, sizeof(ConstructionSystemBuildUI_eventSetConstructionSystem_Parms), Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_UIAsset;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::NewProp_UIAsset = { "UIAsset", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemBuildUI_eventSetUIAsset_Parms, UIAsset), Z_Construct_UClass_UConstructionSystemUIAsset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::NewProp_UIAsset,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUI.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemBuildUI, nullptr, "SetUIAsset", nullptr, nullptr, sizeof(ConstructionSystemBuildUI_eventSetUIAsset_Parms), Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UConstructionSystemBuildUI_NoRegister()
	{
		return UConstructionSystemBuildUI::StaticClass();
	}
	struct Z_Construct_UClass_UConstructionSystemBuildUI_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConstructionSystemBuildUI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UConstructionSystemBuildUI_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UConstructionSystemBuildUI_SetConstructionSystem, "SetConstructionSystem" }, // 979630882
		{ &Z_Construct_UFunction_UConstructionSystemBuildUI_SetUIAsset, "SetUIAsset" }, // 4269845324
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemBuildUI_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/UI/ConstructionSystemUI.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConstructionSystemBuildUI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IConstructionSystemBuildUI>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UConstructionSystemBuildUI_Statics::ClassParams = {
		&UConstructionSystemBuildUI::StaticClass,
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
		0x000040A1u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemBuildUI_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemBuildUI_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UConstructionSystemBuildUI()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UConstructionSystemBuildUI_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UConstructionSystemBuildUI, 1035495712);
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<UConstructionSystemBuildUI>()
	{
		return UConstructionSystemBuildUI::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UConstructionSystemBuildUI(Z_Construct_UClass_UConstructionSystemBuildUI, &UConstructionSystemBuildUI::StaticClass, TEXT("/Script/ConstructionSystemRuntime"), TEXT("UConstructionSystemBuildUI"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConstructionSystemBuildUI);
	static FName NAME_UConstructionSystemBuildUI_SetConstructionSystem = FName(TEXT("SetConstructionSystem"));
	void IConstructionSystemBuildUI::Execute_SetConstructionSystem(UObject* O, UConstructionSystemComponent* ConstructionSystem)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UConstructionSystemBuildUI::StaticClass()));
		ConstructionSystemBuildUI_eventSetConstructionSystem_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UConstructionSystemBuildUI_SetConstructionSystem);
		if (Func)
		{
			Parms.ConstructionSystem=ConstructionSystem;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UConstructionSystemBuildUI_SetUIAsset = FName(TEXT("SetUIAsset"));
	void IConstructionSystemBuildUI::Execute_SetUIAsset(UObject* O, UConstructionSystemUIAsset* UIAsset)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UConstructionSystemBuildUI::StaticClass()));
		ConstructionSystemBuildUI_eventSetUIAsset_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UConstructionSystemBuildUI_SetUIAsset);
		if (Func)
		{
			Parms.UIAsset=UIAsset;
			O->ProcessEvent(Func, &Parms);
		}
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
