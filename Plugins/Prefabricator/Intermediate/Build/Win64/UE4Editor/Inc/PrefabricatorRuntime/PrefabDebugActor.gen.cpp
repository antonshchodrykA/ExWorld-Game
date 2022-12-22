// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PrefabricatorRuntime/Public/Utils/Debug/PrefabDebugActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrefabDebugActor() {}
// Cross Module References
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_APrefabDebugActor_NoRegister();
	PREFABRICATORRUNTIME_API UClass* Z_Construct_UClass_APrefabDebugActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_PrefabricatorRuntime();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	void APrefabDebugActor::StaticRegisterNativesAPrefabDebugActor()
	{
	}
	UClass* Z_Construct_UClass_APrefabDebugActor_NoRegister()
	{
		return APrefabDebugActor::StaticClass();
	}
	struct Z_Construct_UClass_APrefabDebugActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorData_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActorData;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ActorData_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrefabDebugActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_PrefabricatorRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabDebugActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Utils/Debug/PrefabDebugActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Utils/Debug/PrefabDebugActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_ActorData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Utils/Debug/PrefabDebugActor.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_ActorData = { "ActorData", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APrefabDebugActor, ActorData), METADATA_PARAMS(Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_ActorData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_ActorData_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_ActorData_Inner = { "ActorData", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_Actor_MetaData[] = {
		{ "Category", "Debug" },
		{ "ModuleRelativePath", "Public/Utils/Debug/PrefabDebugActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APrefabDebugActor, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_Actor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_Actor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APrefabDebugActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_ActorData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_ActorData_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabDebugActor_Statics::NewProp_Actor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrefabDebugActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrefabDebugActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrefabDebugActor_Statics::ClassParams = {
		&APrefabDebugActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APrefabDebugActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APrefabDebugActor_Statics::PropPointers),
		0,
		0x009000A4u,
		0x00000010u,
		METADATA_PARAMS(Z_Construct_UClass_APrefabDebugActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabDebugActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrefabDebugActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrefabDebugActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrefabDebugActor, 2032127988);
	template<> PREFABRICATORRUNTIME_API UClass* StaticClass<APrefabDebugActor>()
	{
		return APrefabDebugActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrefabDebugActor(Z_Construct_UClass_APrefabDebugActor, &APrefabDebugActor::StaticClass, TEXT("/Script/PrefabricatorRuntime"), TEXT("APrefabDebugActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrefabDebugActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
