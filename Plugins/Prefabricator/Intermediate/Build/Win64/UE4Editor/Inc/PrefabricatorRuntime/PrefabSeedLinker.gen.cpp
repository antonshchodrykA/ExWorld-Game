// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PrefabricatorRuntime/Public/Prefab/Random/PrefabSeedLinker.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrefabSeedLinker() {}
// Cross Module References
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabSeedLinkerComponent_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabSeedLinkerComponent();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_PrefabricatorRuntime();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_APrefabSeedLinker_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_APrefabSeedLinker();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_APrefabActor_NoRegister();
// End Cross Module References
	void UPrefabSeedLinkerComponent::StaticRegisterNativesUPrefabSeedLinkerComponent()
	{
	}
	UClass* Z_Construct_UClass_UPrefabSeedLinkerComponent_NoRegister()
	{
		return UPrefabSeedLinkerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EditorSpriteTexture_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_EditorSpriteTexture;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Prefab/Random/PrefabSeedLinker.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Prefab/Random/PrefabSeedLinker.h" },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::NewProp_EditorSpriteTexture_MetaData[] = {
		{ "ModuleRelativePath", "Public/Prefab/Random/PrefabSeedLinker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::NewProp_EditorSpriteTexture = { "EditorSpriteTexture", nullptr, (EPropertyFlags)0x0040000800000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabSeedLinkerComponent, EditorSpriteTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::NewProp_EditorSpriteTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::NewProp_EditorSpriteTexture_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::NewProp_EditorSpriteTexture,
	};
#endif // WITH_EDITORONLY_DATA
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabSeedLinkerComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::ClassParams = {
		&UPrefabSeedLinkerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		IF_WITH_EDITORONLY_DATA(Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::PropPointers, nullptr),
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		IF_WITH_EDITORONLY_DATA(UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::PropPointers), 0),
		0,
		0x00B000A4u,
		0x00000010u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabSeedLinkerComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabSeedLinkerComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabSeedLinkerComponent, 2999455519);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<UPrefabSeedLinkerComponent>()
	{
		return UPrefabSeedLinkerComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabSeedLinkerComponent(Z_Construct_UClass_UPrefabSeedLinkerComponent, &UPrefabSeedLinkerComponent::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("UPrefabSeedLinkerComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabSeedLinkerComponent);
	void APrefabSeedLinker::StaticRegisterNativesAPrefabSeedLinker()
	{
	}
	UClass* Z_Construct_UClass_APrefabSeedLinker_NoRegister()
	{
		return APrefabSeedLinker::StaticClass();
	}
	struct Z_Construct_UClass_APrefabSeedLinker_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SeedLinkerComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SeedLinkerComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LinkedActors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_LinkedActors;
		static const UE4CodeGen_Private::FWeakObjectPropertyParams NewProp_LinkedActors_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrefabSeedLinker_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabSeedLinker_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IgnoreCategoryKeywordsInSubclasses", "true" },
		{ "IncludePath", "Prefab/Random/PrefabSeedLinker.h" },
		{ "IsBlueprintBase", "true" },
		{ "IsConversionRoot", "true" },
		{ "ModuleRelativePath", "Public/Prefab/Random/PrefabSeedLinker.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_SeedLinkerComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Prefab/Random/PrefabSeedLinker.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_SeedLinkerComponent = { "SeedLinkerComponent", nullptr, (EPropertyFlags)0x0010000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APrefabSeedLinker, SeedLinkerComponent), Z_Construct_UClass_UPrefabSeedLinkerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_SeedLinkerComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_SeedLinkerComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_LinkedActors_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/Prefab/Random/PrefabSeedLinker.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_LinkedActors = { "LinkedActors", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APrefabSeedLinker, LinkedActors), METADATA_PARAMS(Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_LinkedActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_LinkedActors_MetaData)) };
	const UE4CodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_LinkedActors_Inner = { "LinkedActors", nullptr, (EPropertyFlags)0x0004000000000000, UE4CodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_APrefabActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APrefabSeedLinker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_SeedLinkerComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_LinkedActors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabSeedLinker_Statics::NewProp_LinkedActors_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrefabSeedLinker_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrefabSeedLinker>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrefabSeedLinker_Statics::ClassParams = {
		&APrefabSeedLinker::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APrefabSeedLinker_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APrefabSeedLinker_Statics::PropPointers),
		0,
		0x009000A4u,
		0x00000010u,
		METADATA_PARAMS(Z_Construct_UClass_APrefabSeedLinker_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabSeedLinker_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrefabSeedLinker()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrefabSeedLinker_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrefabSeedLinker, 2788057065);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<APrefabSeedLinker>()
	{
		return APrefabSeedLinker::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrefabSeedLinker(Z_Construct_UClass_APrefabSeedLinker, &APrefabSeedLinker::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("APrefabSeedLinker"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrefabSeedLinker);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
