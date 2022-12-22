// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PivotTool/Private/EdMode/PivotToolUISetting.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePivotToolUISetting() {}
// Cross Module References
	PIVOTTOOL_API UClass* Z_Construct_UClass_UPivotToolUISetting_NoRegister();
	PIVOTTOOL_API UClass* Z_Construct_UClass_UPivotToolUISetting();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_PivotTool();
// End Cross Module References
	void UPivotToolUISetting::StaticRegisterNativesUPivotToolUISetting()
	{
	}
	UClass* Z_Construct_UClass_UPivotToolUISetting_NoRegister()
	{
		return UPivotToolUISetting::StaticClass();
	}
	struct Z_Construct_UClass_UPivotToolUISetting_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPivotToolUISetting_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_PivotTool,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPivotToolUISetting_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EdMode/PivotToolUISetting.h" },
		{ "ModuleRelativePath", "Private/EdMode/PivotToolUISetting.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPivotToolUISetting_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPivotToolUISetting>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPivotToolUISetting_Statics::ClassParams = {
		&UPivotToolUISetting::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UPivotToolUISetting_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPivotToolUISetting_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPivotToolUISetting()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPivotToolUISetting_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPivotToolUISetting, 1452189998);
	template<> PIVOTTOOL_API UClass* StaticClass<UPivotToolUISetting>()
	{
		return UPivotToolUISetting::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPivotToolUISetting(Z_Construct_UClass_UPivotToolUISetting, &UPivotToolUISetting::StaticClass, TEXT("/Script/PivotTool"), TEXT("UPivotToolUISetting"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPivotToolUISetting);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
