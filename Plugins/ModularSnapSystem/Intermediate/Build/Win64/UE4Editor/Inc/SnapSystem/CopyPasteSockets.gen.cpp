// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SnapSystem/Public/CopyPasteSockets.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCopyPasteSockets() {}
// Cross Module References
	SNAPSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FCopySockets();
	UPackage* Z_Construct_UPackage__Script_SnapSystem();
	SNAPSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FExportSocket();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	SNAPSYSTEM_API UClass* Z_Construct_UClass_UCopyPasteSockets_NoRegister();
	SNAPSYSTEM_API UClass* Z_Construct_UClass_UCopyPasteSockets();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
// End Cross Module References
class UScriptStruct* FCopySockets::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SNAPSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FCopySockets_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCopySockets, Z_Construct_UPackage__Script_SnapSystem(), TEXT("CopySockets"), sizeof(FCopySockets), Get_Z_Construct_UScriptStruct_FCopySockets_Hash());
	}
	return Singleton;
}
template<> SNAPSYSTEM_API UScriptStruct* StaticStruct<FCopySockets>()
{
	return FCopySockets::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCopySockets(FCopySockets::StaticStruct, TEXT("/Script/SnapSystem"), TEXT("CopySockets"), false, nullptr, nullptr);
static struct FScriptStruct_SnapSystem_StaticRegisterNativesFCopySockets
{
	FScriptStruct_SnapSystem_StaticRegisterNativesFCopySockets()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("CopySockets")),new UScriptStruct::TCppStructOps<FCopySockets>);
	}
} ScriptStruct_SnapSystem_StaticRegisterNativesFCopySockets;
	struct Z_Construct_UScriptStruct_FCopySockets_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Sockets_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Sockets;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Sockets_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bPivotAtZero_MetaData[];
#endif
		static void NewProp_bPivotAtZero_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPivotAtZero;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCopySockets_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CopyPasteSockets.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCopySockets_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCopySockets>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_Sockets_MetaData[] = {
		{ "ModuleRelativePath", "Public/CopyPasteSockets.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_Sockets = { "Sockets", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCopySockets, Sockets), METADATA_PARAMS(Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_Sockets_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_Sockets_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_Sockets_Inner = { "Sockets", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FExportSocket, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_bPivotAtZero_MetaData[] = {
		{ "ModuleRelativePath", "Public/CopyPasteSockets.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_bPivotAtZero_SetBit(void* Obj)
	{
		((FCopySockets*)Obj)->bPivotAtZero = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_bPivotAtZero = { "bPivotAtZero", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FCopySockets), &Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_bPivotAtZero_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_bPivotAtZero_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_bPivotAtZero_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCopySockets_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_Sockets,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_Sockets_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCopySockets_Statics::NewProp_bPivotAtZero,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCopySockets_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SnapSystem,
		nullptr,
		&NewStructOps,
		"CopySockets",
		sizeof(FCopySockets),
		alignof(FCopySockets),
		Z_Construct_UScriptStruct_FCopySockets_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCopySockets_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCopySockets_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCopySockets_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCopySockets()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCopySockets_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SnapSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CopySockets"), sizeof(FCopySockets), Get_Z_Construct_UScriptStruct_FCopySockets_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCopySockets_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCopySockets_Hash() { return 3413600672U; }
class UScriptStruct* FExportSocket::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern SNAPSYSTEM_API uint32 Get_Z_Construct_UScriptStruct_FExportSocket_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FExportSocket, Z_Construct_UPackage__Script_SnapSystem(), TEXT("ExportSocket"), sizeof(FExportSocket), Get_Z_Construct_UScriptStruct_FExportSocket_Hash());
	}
	return Singleton;
}
template<> SNAPSYSTEM_API UScriptStruct* StaticStruct<FExportSocket>()
{
	return FExportSocket::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FExportSocket(FExportSocket::StaticStruct, TEXT("/Script/SnapSystem"), TEXT("ExportSocket"), false, nullptr, nullptr);
static struct FScriptStruct_SnapSystem_StaticRegisterNativesFExportSocket
{
	FScriptStruct_SnapSystem_StaticRegisterNativesFExportSocket()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ExportSocket")),new UScriptStruct::TCppStructOps<FExportSocket>);
	}
} ScriptStruct_SnapSystem_StaticRegisterNativesFExportSocket;
	struct Z_Construct_UScriptStruct_FExportSocket_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_T_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_T;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Name;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportSocket_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CopyPasteSockets.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FExportSocket_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FExportSocket>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_T_MetaData[] = {
		{ "ModuleRelativePath", "Public/CopyPasteSockets.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_T = { "T", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FExportSocket, T), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_T_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_T_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_Name_MetaData[] = {
		{ "ModuleRelativePath", "Public/CopyPasteSockets.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FExportSocket, Name), METADATA_PARAMS(Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_Name_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FExportSocket_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_T,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExportSocket_Statics::NewProp_Name,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FExportSocket_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SnapSystem,
		nullptr,
		&NewStructOps,
		"ExportSocket",
		sizeof(FExportSocket),
		alignof(FExportSocket),
		Z_Construct_UScriptStruct_FExportSocket_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportSocket_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FExportSocket_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExportSocket_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FExportSocket()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FExportSocket_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_SnapSystem();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ExportSocket"), sizeof(FExportSocket), Get_Z_Construct_UScriptStruct_FExportSocket_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FExportSocket_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FExportSocket_Hash() { return 2851442001U; }
	void UCopyPasteSockets::StaticRegisterNativesUCopyPasteSockets()
	{
	}
	UClass* Z_Construct_UClass_UCopyPasteSockets_NoRegister()
	{
		return UCopyPasteSockets::StaticClass();
	}
	struct Z_Construct_UClass_UCopyPasteSockets_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CopyData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CopyData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCopyPasteSockets_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SnapSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCopyPasteSockets_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "CopyPasteSockets.h" },
		{ "ModuleRelativePath", "Public/CopyPasteSockets.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCopyPasteSockets_Statics::NewProp_CopyData_MetaData[] = {
		{ "ModuleRelativePath", "Public/CopyPasteSockets.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCopyPasteSockets_Statics::NewProp_CopyData = { "CopyData", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UCopyPasteSockets, CopyData), Z_Construct_UScriptStruct_FCopySockets, METADATA_PARAMS(Z_Construct_UClass_UCopyPasteSockets_Statics::NewProp_CopyData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UCopyPasteSockets_Statics::NewProp_CopyData_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCopyPasteSockets_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCopyPasteSockets_Statics::NewProp_CopyData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCopyPasteSockets_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCopyPasteSockets>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCopyPasteSockets_Statics::ClassParams = {
		&UCopyPasteSockets::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UCopyPasteSockets_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UCopyPasteSockets_Statics::PropPointers),
		0,
		0x001000A0u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UCopyPasteSockets_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCopyPasteSockets_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCopyPasteSockets()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCopyPasteSockets_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCopyPasteSockets, 871377157);
	template<> SNAPSYSTEM_API UClass* StaticClass<UCopyPasteSockets>()
	{
		return UCopyPasteSockets::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCopyPasteSockets(Z_Construct_UClass_UCopyPasteSockets, &UCopyPasteSockets::StaticClass, TEXT("/Script/SnapSystem"), TEXT("UCopyPasteSockets"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCopyPasteSockets);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
