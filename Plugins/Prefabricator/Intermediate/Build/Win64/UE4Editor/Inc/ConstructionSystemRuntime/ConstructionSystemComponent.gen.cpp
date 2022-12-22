// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ConstructionSystemRuntime/Public/ConstructionSystemComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConstructionSystemComponent() {}
// Cross Module References
	CONSTRUCTIONSYSTEMRUNTIME_API UEnum* Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType();
	UPackage* Z_Construct_UPackage__Script_ConstructionSystemRuntime();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemComponent_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemComponent_DisableConstructionSystem();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemTool_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemComponent_GetTool();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemComponent_HideBuildMenu();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemComponent_ShowBuildMenu();
	CONSTRUCTIONSYSTEMRUNTIME_API UFunction* Z_Construct_UFunction_UConstructionSystemComponent_ToggleConstructionSystem();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemUIAsset_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemItemUserData_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UConstructionSystemItemUserData();
	ENGINE_API UClass* Z_Construct_UClass_UAssetUserData();
// End Cross Module References
	static UEnum* EConstructionSystemToolType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType, Z_Construct_UPackage__Script_ConstructionSystemRuntime(), TEXT("EConstructionSystemToolType"));
		}
		return Singleton;
	}
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UEnum* StaticEnum<EConstructionSystemToolType>()
	{
		return EConstructionSystemToolType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EConstructionSystemToolType(EConstructionSystemToolType_StaticEnum, TEXT("/Script/ConstructionSystemRuntime"), TEXT("EConstructionSystemToolType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType_Hash() { return 748688686U; }
	UEnum* Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ConstructionSystemRuntime();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EConstructionSystemToolType"), 0, Get_Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EConstructionSystemToolType::BuildTool", (int64)EConstructionSystemToolType::BuildTool },
				{ "EConstructionSystemToolType::RemoveTool", (int64)EConstructionSystemToolType::RemoveTool },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "BuildTool.DisplayName", "Build Tool" },
				{ "BuildTool.Name", "EConstructionSystemToolType::BuildTool" },
				{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
				{ "RemoveTool.DisplayName", "Remove Tool" },
				{ "RemoveTool.Name", "EConstructionSystemToolType::RemoveTool" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
				nullptr,
				"EConstructionSystemToolType",
				"EConstructionSystemToolType",
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
	void UConstructionSystemComponent::StaticRegisterNativesUConstructionSystemComponent()
	{
		UClass* Class = UConstructionSystemComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DisableConstructionSystem", &UConstructionSystemComponent::execDisableConstructionSystem },
			{ "EnableConstructionSystem", &UConstructionSystemComponent::execEnableConstructionSystem },
			{ "GetActiveTool", &UConstructionSystemComponent::execGetActiveTool },
			{ "GetActiveToolType", &UConstructionSystemComponent::execGetActiveToolType },
			{ "GetTool", &UConstructionSystemComponent::execGetTool },
			{ "HideBuildMenu", &UConstructionSystemComponent::execHideBuildMenu },
			{ "SetActiveTool", &UConstructionSystemComponent::execSetActiveTool },
			{ "ShowBuildMenu", &UConstructionSystemComponent::execShowBuildMenu },
			{ "ToggleConstructionSystem", &UConstructionSystemComponent::execToggleConstructionSystem },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UConstructionSystemComponent_DisableConstructionSystem_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemComponent_DisableConstructionSystem_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemComponent_DisableConstructionSystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemComponent, nullptr, "DisableConstructionSystem", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemComponent_DisableConstructionSystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_DisableConstructionSystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemComponent_DisableConstructionSystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemComponent_DisableConstructionSystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics
	{
		struct ConstructionSystemComponent_eventEnableConstructionSystem_Parms
		{
			EConstructionSystemToolType InToolType;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_InToolType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_InToolType_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::NewProp_InToolType = { "InToolType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemComponent_eventEnableConstructionSystem_Parms, InToolType), Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::NewProp_InToolType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::NewProp_InToolType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::NewProp_InToolType_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemComponent, nullptr, "EnableConstructionSystem", nullptr, nullptr, sizeof(ConstructionSystemComponent_eventEnableConstructionSystem_Parms), Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics
	{
		struct ConstructionSystemComponent_eventGetActiveTool_Parms
		{
			UConstructionSystemTool* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemComponent_eventGetActiveTool_Parms, ReturnValue), Z_Construct_UClass_UConstructionSystemTool_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemComponent, nullptr, "GetActiveTool", nullptr, nullptr, sizeof(ConstructionSystemComponent_eventGetActiveTool_Parms), Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics
	{
		struct ConstructionSystemComponent_eventGetActiveToolType_Parms
		{
			EConstructionSystemToolType ReturnValue;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemComponent_eventGetActiveToolType_Parms, ReturnValue), Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::NewProp_ReturnValue_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemComponent, nullptr, "GetActiveToolType", nullptr, nullptr, sizeof(ConstructionSystemComponent_eventGetActiveToolType_Parms), Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics
	{
		struct ConstructionSystemComponent_eventGetTool_Parms
		{
			EConstructionSystemToolType InToolType;
			UConstructionSystemTool* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_InToolType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_InToolType_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemComponent_eventGetTool_Parms, ReturnValue), Z_Construct_UClass_UConstructionSystemTool_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::NewProp_InToolType = { "InToolType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemComponent_eventGetTool_Parms, InToolType), Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::NewProp_InToolType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::NewProp_InToolType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::NewProp_InToolType_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemComponent, nullptr, "GetTool", nullptr, nullptr, sizeof(ConstructionSystemComponent_eventGetTool_Parms), Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemComponent_GetTool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemComponent_GetTool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemComponent_HideBuildMenu_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemComponent_HideBuildMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemComponent_HideBuildMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemComponent, nullptr, "HideBuildMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemComponent_HideBuildMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_HideBuildMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemComponent_HideBuildMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemComponent_HideBuildMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics
	{
		struct ConstructionSystemComponent_eventSetActiveTool_Parms
		{
			EConstructionSystemToolType InToolType;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_InToolType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_InToolType_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::NewProp_InToolType = { "InToolType", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ConstructionSystemComponent_eventSetActiveTool_Parms, InToolType), Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::NewProp_InToolType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::NewProp_InToolType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::NewProp_InToolType_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemComponent, nullptr, "SetActiveTool", nullptr, nullptr, sizeof(ConstructionSystemComponent_eventSetActiveTool_Parms), Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemComponent_ShowBuildMenu_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemComponent_ShowBuildMenu_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemComponent_ShowBuildMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemComponent, nullptr, "ShowBuildMenu", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemComponent_ShowBuildMenu_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_ShowBuildMenu_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemComponent_ShowBuildMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemComponent_ShowBuildMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UConstructionSystemComponent_ToggleConstructionSystem_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UConstructionSystemComponent_ToggleConstructionSystem_Statics::Function_MetaDataParams[] = {
		{ "Category", "ConstructionSystem" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UConstructionSystemComponent_ToggleConstructionSystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UConstructionSystemComponent, nullptr, "ToggleConstructionSystem", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, (ESpatialFunctionFlags)0x00000000, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UConstructionSystemComponent_ToggleConstructionSystem_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UConstructionSystemComponent_ToggleConstructionSystem_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UConstructionSystemComponent_ToggleConstructionSystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UConstructionSystemComponent_ToggleConstructionSystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UConstructionSystemComponent_NoRegister()
	{
		return UConstructionSystemComponent::StaticClass();
	}
	struct Z_Construct_UClass_UConstructionSystemComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tools_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_Tools;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Tools_Key_KeyProp;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Tools_Key_KeyProp_Underlying;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Tools_ValueProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActiveToolType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ActiveToolType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ActiveToolType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BuildMenuUIInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BuildMenuUIInstance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BuildMenuData_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BuildMenuData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BuildMenuUI_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_BuildMenuUI;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstructionCameraTransitionExp_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ConstructionCameraTransitionExp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstructionCameraTransitionTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ConstructionCameraTransitionTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstructionCameraActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConstructionCameraActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TraceSweepRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TraceSweepRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TraceStartDistance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TraceStartDistance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CursorInvalidMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CursorInvalidMaterial;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CursorMaterial_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CursorMaterial;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConstructionSystemComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UConstructionSystemComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UConstructionSystemComponent_DisableConstructionSystem, "DisableConstructionSystem" }, // 2996494505
		{ &Z_Construct_UFunction_UConstructionSystemComponent_EnableConstructionSystem, "EnableConstructionSystem" }, // 3961781389
		{ &Z_Construct_UFunction_UConstructionSystemComponent_GetActiveTool, "GetActiveTool" }, // 4087144467
		{ &Z_Construct_UFunction_UConstructionSystemComponent_GetActiveToolType, "GetActiveToolType" }, // 2869995512
		{ &Z_Construct_UFunction_UConstructionSystemComponent_GetTool, "GetTool" }, // 1475967411
		{ &Z_Construct_UFunction_UConstructionSystemComponent_HideBuildMenu, "HideBuildMenu" }, // 3078211346
		{ &Z_Construct_UFunction_UConstructionSystemComponent_SetActiveTool, "SetActiveTool" }, // 1397568517
		{ &Z_Construct_UFunction_UConstructionSystemComponent_ShowBuildMenu, "ShowBuildMenu" }, // 3772344203
		{ &Z_Construct_UFunction_UConstructionSystemComponent_ToggleConstructionSystem, "ToggleConstructionSystem" }, // 2629950117
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "IncludePath", "ConstructionSystemComponent.h" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools_MetaData[] = {
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools = { "Tools", nullptr, (EPropertyFlags)0x0010000000002000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, Tools), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools_MetaData)) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools_Key_KeyProp = { "Tools_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools_Key_KeyProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools_ValueProp = { "Tools", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UConstructionSystemTool_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ActiveToolType_MetaData[] = {
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ActiveToolType = { "ActiveToolType", nullptr, (EPropertyFlags)0x0010000000002000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, ActiveToolType), Z_Construct_UEnum_ConstructionSystemRuntime_EConstructionSystemToolType, METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ActiveToolType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ActiveToolType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ActiveToolType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUIInstance_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUIInstance = { "BuildMenuUIInstance", nullptr, (EPropertyFlags)0x0010000000082008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, BuildMenuUIInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUIInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUIInstance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuData_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuData = { "BuildMenuData", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, BuildMenuData), Z_Construct_UClass_UConstructionSystemUIAsset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUI_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUI = { "BuildMenuUI", nullptr, (EPropertyFlags)0x0014000000000005, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, BuildMenuUI), Z_Construct_UClass_UUserWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUI_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUI_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionExp_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionExp = { "ConstructionCameraTransitionExp", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, ConstructionCameraTransitionExp), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionExp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionExp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionTime_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionTime = { "ConstructionCameraTransitionTime", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, ConstructionCameraTransitionTime), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraActor_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraActor = { "ConstructionCameraActor", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, ConstructionCameraActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceSweepRadius_MetaData[] = {
		{ "Category", "Cursor" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceSweepRadius = { "TraceSweepRadius", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, TraceSweepRadius), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceSweepRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceSweepRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceStartDistance_MetaData[] = {
		{ "Category", "Cursor" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceStartDistance = { "TraceStartDistance", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, TraceStartDistance), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceStartDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceStartDistance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorInvalidMaterial_MetaData[] = {
		{ "Category", "Cursor" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorInvalidMaterial = { "CursorInvalidMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, CursorInvalidMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorInvalidMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorInvalidMaterial_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorMaterial_MetaData[] = {
		{ "Category", "Cursor" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorMaterial = { "CursorMaterial", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemComponent, CursorMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorMaterial_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UConstructionSystemComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools_Key_KeyProp_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_Tools_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ActiveToolType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ActiveToolType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUIInstance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_BuildMenuUI,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionExp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraTransitionTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_ConstructionCameraActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceSweepRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_TraceStartDistance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorInvalidMaterial,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemComponent_Statics::NewProp_CursorMaterial,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConstructionSystemComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConstructionSystemComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UConstructionSystemComponent_Statics::ClassParams = {
		&UConstructionSystemComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UConstructionSystemComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		0x00000010u,
		METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UConstructionSystemComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UConstructionSystemComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UConstructionSystemComponent, 3839271451);
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<UConstructionSystemComponent>()
	{
		return UConstructionSystemComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UConstructionSystemComponent(Z_Construct_UClass_UConstructionSystemComponent, &UConstructionSystemComponent::StaticClass, TEXT("/Script/ConstructionSystemRuntime"), TEXT("UConstructionSystemComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConstructionSystemComponent);
	void UConstructionSystemItemUserData::StaticRegisterNativesUConstructionSystemItemUserData()
	{
	}
	UClass* Z_Construct_UClass_UConstructionSystemItemUserData_NoRegister()
	{
		return UConstructionSystemItemUserData::StaticClass();
	}
	struct Z_Construct_UClass_UConstructionSystemItemUserData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Seed_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Seed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UConstructionSystemItemUserData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAssetUserData,
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemItemUserData_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ConstructionSystemComponent.h" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UConstructionSystemItemUserData_Statics::NewProp_Seed_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystemComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UConstructionSystemItemUserData_Statics::NewProp_Seed = { "Seed", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UConstructionSystemItemUserData, Seed), METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemItemUserData_Statics::NewProp_Seed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemItemUserData_Statics::NewProp_Seed_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UConstructionSystemItemUserData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UConstructionSystemItemUserData_Statics::NewProp_Seed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UConstructionSystemItemUserData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UConstructionSystemItemUserData>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UConstructionSystemItemUserData_Statics::ClassParams = {
		&UConstructionSystemItemUserData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UConstructionSystemItemUserData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemItemUserData_Statics::PropPointers),
		0,
		0x003010A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UConstructionSystemItemUserData_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UConstructionSystemItemUserData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UConstructionSystemItemUserData()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UConstructionSystemItemUserData_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UConstructionSystemItemUserData, 649197532);
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<UConstructionSystemItemUserData>()
	{
		return UConstructionSystemItemUserData::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UConstructionSystemItemUserData(Z_Construct_UClass_UConstructionSystemItemUserData, &UConstructionSystemItemUserData::StaticClass, TEXT("/Script/ConstructionSystemRuntime"), TEXT("UConstructionSystemItemUserData"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UConstructionSystemItemUserData);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
