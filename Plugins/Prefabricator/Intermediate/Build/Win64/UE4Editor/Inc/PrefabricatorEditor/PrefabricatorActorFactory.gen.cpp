// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PrefabricatorEditor/Public/Asset/PrefabricatorActorFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrefabricatorActorFactory() {}
// Cross Module References
	PREFABRICATOREDITOR_API UClass* Z_Construct_UClass_UPrefabricatorActorFactory_NoRegister();
	PREFABRICATOREDITOR_API UClass* Z_Construct_UClass_UPrefabricatorActorFactory();
	UNREALED_API UClass* Z_Construct_UClass_UActorFactory();
	UPackage* Z_Construct_UPackage__Script_PrefabricatorEditor();
// End Cross Module References
	void UPrefabricatorActorFactory::StaticRegisterNativesUPrefabricatorActorFactory()
	{
	}
	UClass* Z_Construct_UClass_UPrefabricatorActorFactory_NoRegister()
	{
		return UPrefabricatorActorFactory::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabricatorActorFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabricatorActorFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorActorFactory_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object" },
		{ "IncludePath", "Asset/PrefabricatorActorFactory.h" },
		{ "ModuleRelativePath", "Public/Asset/PrefabricatorActorFactory.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabricatorActorFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabricatorActorFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabricatorActorFactory_Statics::ClassParams = {
		&UPrefabricatorActorFactory::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001030ACu,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorActorFactory_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorActorFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabricatorActorFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabricatorActorFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabricatorActorFactory, 655656888);
	template<> PREFABRICATOREDITOR_API UClass* StaticClass<UPrefabricatorActorFactory>()
	{
		return UPrefabricatorActorFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabricatorActorFactory(Z_Construct_UClass_UPrefabricatorActorFactory, &UPrefabricatorActorFactory::StaticClass, TEXT("/Script/PrefabricatorEditor"), TEXT("UPrefabricatorActorFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabricatorActorFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
