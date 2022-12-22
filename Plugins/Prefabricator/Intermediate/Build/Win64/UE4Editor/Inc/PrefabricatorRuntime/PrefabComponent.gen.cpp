// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PrefabricatorRuntime/Public/Prefab/PrefabComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrefabComponent() {}
// Cross Module References
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabComponent_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabComponent();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_PrefabricatorRuntime();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorAssetInterface_NoRegister();
// End Cross Module References
	void UPrefabComponent::StaticRegisterNativesUPrefabComponent()
	{
	}
	UClass* Z_Construct_UClass_UPrefabComponent_NoRegister()
	{
		return UPrefabComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabComponent_Statics
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
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrefabAssetInterface_MetaData[];
#endif
		static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_PrefabAssetInterface;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_EDITORONLY_DATA
#endif // WITH_EDITORONLY_DATA
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Prefab/PrefabComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabComponent.h" },
	};
#endif
#if WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabComponent_Statics::NewProp_EditorSpriteTexture_MetaData[] = {
		{ "ModuleRelativePath", "Public/Prefab/PrefabComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPrefabComponent_Statics::NewProp_EditorSpriteTexture = { "EditorSpriteTexture", nullptr, (EPropertyFlags)0x0040000800000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabComponent, EditorSpriteTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPrefabComponent_Statics::NewProp_EditorSpriteTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabComponent_Statics::NewProp_EditorSpriteTexture_MetaData)) };
#endif // WITH_EDITORONLY_DATA
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabComponent_Statics::NewProp_PrefabAssetInterface_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "DisplayName", "Prefab" },
		{ "ModuleRelativePath", "Public/Prefab/PrefabComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UPrefabComponent_Statics::NewProp_PrefabAssetInterface = { "PrefabAssetInterface", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabComponent, PrefabAssetInterface), Z_Construct_UClass_UPrefabricatorAssetInterface_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UPrefabComponent_Statics::NewProp_PrefabAssetInterface_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabComponent_Statics::NewProp_PrefabAssetInterface_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPrefabComponent_Statics::PropPointers[] = {
#if WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabComponent_Statics::NewProp_EditorSpriteTexture,
#endif // WITH_EDITORONLY_DATA
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabComponent_Statics::NewProp_PrefabAssetInterface,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabComponent_Statics::ClassParams = {
		&UPrefabComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPrefabComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		0x00000010u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabComponent, 583782017);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<UPrefabComponent>()
	{
		return UPrefabComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabComponent(Z_Construct_UClass_UPrefabComponent, &UPrefabComponent::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("UPrefabComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
