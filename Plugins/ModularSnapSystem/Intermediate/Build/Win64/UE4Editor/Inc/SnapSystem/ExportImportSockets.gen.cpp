// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SnapSystem/Public/ExportImportSockets.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExportImportSockets() {}
// Cross Module References
	SNAPSYSTEM_API UClass* Z_Construct_UClass_UExportImportSockets_NoRegister();
	SNAPSYSTEM_API UClass* Z_Construct_UClass_UExportImportSockets();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_SnapSystem();
// End Cross Module References
	void UExportImportSockets::StaticRegisterNativesUExportImportSockets()
	{
	}
	UClass* Z_Construct_UClass_UExportImportSockets_NoRegister()
	{
		return UExportImportSockets::StaticClass();
	}
	struct Z_Construct_UClass_UExportImportSockets_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UExportImportSockets_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SnapSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExportImportSockets_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "ExportImportSockets.h" },
		{ "ModuleRelativePath", "Public/ExportImportSockets.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UExportImportSockets_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExportImportSockets>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UExportImportSockets_Statics::ClassParams = {
		&UExportImportSockets::StaticClass,
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
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UExportImportSockets_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UExportImportSockets_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UExportImportSockets()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UExportImportSockets_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UExportImportSockets, 19950987);
	template<> SNAPSYSTEM_API UClass* StaticClass<UExportImportSockets>()
	{
		return UExportImportSockets::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UExportImportSockets(Z_Construct_UClass_UExportImportSockets, &UExportImportSockets::StaticClass, TEXT("/Script/SnapSystem"), TEXT("UExportImportSockets"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UExportImportSockets);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
