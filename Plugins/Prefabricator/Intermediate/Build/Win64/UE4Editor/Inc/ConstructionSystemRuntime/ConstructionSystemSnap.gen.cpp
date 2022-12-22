// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ConstructionSystemRuntime/Public/ConstructionSystem/ConstructionSystemSnap.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConstructionSystemSnap() {}
// Cross Module References
	CONSTRUCTIONSYSTEMRUNTIME_API UEnum* Z_Construct_UEnum_ConstructionSystemRuntime_EPrefabricatorConstructionSnapType();
	UPackage* Z_Construct_UPackage__Script_ConstructionSystemRuntime();
	CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPCSnapConstraintWall();
	CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FPCSnapConstraintFloor();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_UPrefabricatorConstructionSnapComponent();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_APrefabricatorConstructionSnap_NoRegister();
	CONSTRUCTIONSYSTEMRUNTIME_API UClass* Z_Construct_UClass_APrefabricatorConstructionSnap();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static UEnum* EPrefabricatorConstructionSnapType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ConstructionSystemRuntime_EPrefabricatorConstructionSnapType, Z_Construct_UPackage__Script_ConstructionSystemRuntime(), TEXT("EPrefabricatorConstructionSnapType"));
		}
		return Singleton;
	}
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UEnum* StaticEnum<EPrefabricatorConstructionSnapType>()
	{
		return EPrefabricatorConstructionSnapType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPrefabricatorConstructionSnapType(EPrefabricatorConstructionSnapType_StaticEnum, TEXT("/Script/ConstructionSystemRuntime"), TEXT("EPrefabricatorConstructionSnapType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ConstructionSystemRuntime_EPrefabricatorConstructionSnapType_Hash() { return 3176448705U; }
	UEnum* Z_Construct_UEnum_ConstructionSystemRuntime_EPrefabricatorConstructionSnapType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ConstructionSystemRuntime();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPrefabricatorConstructionSnapType"), 0, Get_Z_Construct_UEnum_ConstructionSystemRuntime_EPrefabricatorConstructionSnapType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPrefabricatorConstructionSnapType::Floor", (int64)EPrefabricatorConstructionSnapType::Floor },
				{ "EPrefabricatorConstructionSnapType::Wall", (int64)EPrefabricatorConstructionSnapType::Wall },
				{ "EPrefabricatorConstructionSnapType::Object", (int64)EPrefabricatorConstructionSnapType::Object },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Floor.Name", "EPrefabricatorConstructionSnapType::Floor" },
				{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
				{ "Object.Name", "EPrefabricatorConstructionSnapType::Object" },
				{ "Wall.Name", "EPrefabricatorConstructionSnapType::Wall" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
				nullptr,
				"EPrefabricatorConstructionSnapType",
				"EPrefabricatorConstructionSnapType",
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
class UScriptStruct* FPCSnapConstraintWall::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CONSTRUCTIONSYSTEMRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FPCSnapConstraintWall_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCSnapConstraintWall, Z_Construct_UPackage__Script_ConstructionSystemRuntime(), TEXT("PCSnapConstraintWall"), sizeof(FPCSnapConstraintWall), Get_Z_Construct_UScriptStruct_FPCSnapConstraintWall_Hash());
	}
	return Singleton;
}
template<> CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* StaticStruct<FPCSnapConstraintWall>()
{
	return FPCSnapConstraintWall::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPCSnapConstraintWall(FPCSnapConstraintWall::StaticStruct, TEXT("/Script/ConstructionSystemRuntime"), TEXT("PCSnapConstraintWall"), false, nullptr, nullptr);
static struct FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFPCSnapConstraintWall
{
	FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFPCSnapConstraintWall()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("PCSnapConstraintWall")),new UScriptStruct::TCppStructOps<FPCSnapConstraintWall>);
	}
} ScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFPCSnapConstraintWall;
	struct Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachRight_MetaData[];
#endif
		static void NewProp_AttachRight_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachRight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachLeft_MetaData[];
#endif
		static void NewProp_AttachLeft_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachLeft;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachBottom_MetaData[];
#endif
		static void NewProp_AttachBottom_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachBottom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachTop_MetaData[];
#endif
		static void NewProp_AttachTop_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachTop;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCSnapConstraintWall>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachRight_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachRight_SetBit(void* Obj)
	{
		((FPCSnapConstraintWall*)Obj)->AttachRight = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachRight = { "AttachRight", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintWall), &Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachRight_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachRight_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachRight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachLeft_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachLeft_SetBit(void* Obj)
	{
		((FPCSnapConstraintWall*)Obj)->AttachLeft = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachLeft = { "AttachLeft", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintWall), &Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachLeft_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachLeft_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachLeft_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachBottom_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachBottom_SetBit(void* Obj)
	{
		((FPCSnapConstraintWall*)Obj)->AttachBottom = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachBottom = { "AttachBottom", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintWall), &Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachBottom_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachBottom_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachBottom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachTop_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachTop_SetBit(void* Obj)
	{
		((FPCSnapConstraintWall*)Obj)->AttachTop = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachTop = { "AttachTop", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintWall), &Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachTop_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachTop_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachTop_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachRight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachLeft,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachBottom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::NewProp_AttachTop,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
		nullptr,
		&NewStructOps,
		"PCSnapConstraintWall",
		sizeof(FPCSnapConstraintWall),
		alignof(FPCSnapConstraintWall),
		Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPCSnapConstraintWall()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPCSnapConstraintWall_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ConstructionSystemRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PCSnapConstraintWall"), sizeof(FPCSnapConstraintWall), Get_Z_Construct_UScriptStruct_FPCSnapConstraintWall_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPCSnapConstraintWall_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPCSnapConstraintWall_Hash() { return 3003170222U; }
class UScriptStruct* FPCSnapConstraintFloor::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CONSTRUCTIONSYSTEMRUNTIME_API uint32 Get_Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPCSnapConstraintFloor, Z_Construct_UPackage__Script_ConstructionSystemRuntime(), TEXT("PCSnapConstraintFloor"), sizeof(FPCSnapConstraintFloor), Get_Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Hash());
	}
	return Singleton;
}
template<> CONSTRUCTIONSYSTEMRUNTIME_API UScriptStruct* StaticStruct<FPCSnapConstraintFloor>()
{
	return FPCSnapConstraintFloor::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPCSnapConstraintFloor(FPCSnapConstraintFloor::StaticStruct, TEXT("/Script/ConstructionSystemRuntime"), TEXT("PCSnapConstraintFloor"), false, nullptr, nullptr);
static struct FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFPCSnapConstraintFloor
{
	FScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFPCSnapConstraintFloor()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("PCSnapConstraintFloor")),new UScriptStruct::TCppStructOps<FPCSnapConstraintFloor>);
	}
} ScriptStruct_ConstructionSystemRuntime_StaticRegisterNativesFPCSnapConstraintFloor;
	struct Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachZNegative_MetaData[];
#endif
		static void NewProp_AttachZNegative_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachZNegative;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachZ_MetaData[];
#endif
		static void NewProp_AttachZ_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachZ;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachYNegative_MetaData[];
#endif
		static void NewProp_AttachYNegative_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachYNegative;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachY_MetaData[];
#endif
		static void NewProp_AttachY_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachY;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachXNegative_MetaData[];
#endif
		static void NewProp_AttachXNegative_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachXNegative;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttachX_MetaData[];
#endif
		static void NewProp_AttachX_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_AttachX;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPCSnapConstraintFloor>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZNegative_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZNegative_SetBit(void* Obj)
	{
		((FPCSnapConstraintFloor*)Obj)->AttachZNegative = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZNegative = { "AttachZNegative", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintFloor), &Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZNegative_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZNegative_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZNegative_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZ_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZ_SetBit(void* Obj)
	{
		((FPCSnapConstraintFloor*)Obj)->AttachZ = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZ = { "AttachZ", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintFloor), &Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZ_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZ_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZ_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachYNegative_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachYNegative_SetBit(void* Obj)
	{
		((FPCSnapConstraintFloor*)Obj)->AttachYNegative = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachYNegative = { "AttachYNegative", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintFloor), &Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachYNegative_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachYNegative_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachYNegative_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachY_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachY_SetBit(void* Obj)
	{
		((FPCSnapConstraintFloor*)Obj)->AttachY = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachY = { "AttachY", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintFloor), &Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachY_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachY_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachY_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachXNegative_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachXNegative_SetBit(void* Obj)
	{
		((FPCSnapConstraintFloor*)Obj)->AttachXNegative = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachXNegative = { "AttachXNegative", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintFloor), &Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachXNegative_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachXNegative_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachXNegative_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachX_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachX_SetBit(void* Obj)
	{
		((FPCSnapConstraintFloor*)Obj)->AttachX = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachX = { "AttachX", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FPCSnapConstraintFloor), &Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachX_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachX_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachX_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZNegative,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachYNegative,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachY,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachXNegative,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::NewProp_AttachX,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
		nullptr,
		&NewStructOps,
		"PCSnapConstraintFloor",
		sizeof(FPCSnapConstraintFloor),
		alignof(FPCSnapConstraintFloor),
		Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPCSnapConstraintFloor()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ConstructionSystemRuntime();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PCSnapConstraintFloor"), sizeof(FPCSnapConstraintFloor), Get_Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPCSnapConstraintFloor_Hash() { return 2401229972U; }
	void UPrefabricatorConstructionSnapComponent::StaticRegisterNativesUPrefabricatorConstructionSnapComponent()
	{
	}
	UClass* Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_NoRegister()
	{
		return UPrefabricatorConstructionSnapComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxGroundPlacementSlope_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxGroundPlacementSlope;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseMaxGroundSlopeConstraint_MetaData[];
#endif
		static void NewProp_bUseMaxGroundSlopeConstraint_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseMaxGroundSlopeConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAlignToGroundSlope_MetaData[];
#endif
		static void NewProp_bAlignToGroundSlope_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAlignToGroundSlope;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WallConstraint_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WallConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FloorConstraint_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FloorConstraint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SnapType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_SnapType;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_SnapType_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBoxComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "HideCategories", "Object LOD Lighting TextureStreaming Object LOD Lighting TextureStreaming Activation Components|Activation Trigger" },
		{ "IncludePath", "ConstructionSystem/ConstructionSystemSnap.h" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_MaxGroundPlacementSlope_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "EditCondition", "bUseMaxGroundSlopeConstraint" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_MaxGroundPlacementSlope = { "MaxGroundPlacementSlope", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorConstructionSnapComponent, MaxGroundPlacementSlope), METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_MaxGroundPlacementSlope_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_MaxGroundPlacementSlope_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bUseMaxGroundSlopeConstraint_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bUseMaxGroundSlopeConstraint_SetBit(void* Obj)
	{
		((UPrefabricatorConstructionSnapComponent*)Obj)->bUseMaxGroundSlopeConstraint = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bUseMaxGroundSlopeConstraint = { "bUseMaxGroundSlopeConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPrefabricatorConstructionSnapComponent), &Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bUseMaxGroundSlopeConstraint_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bUseMaxGroundSlopeConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bUseMaxGroundSlopeConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bAlignToGroundSlope_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	void Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bAlignToGroundSlope_SetBit(void* Obj)
	{
		((UPrefabricatorConstructionSnapComponent*)Obj)->bAlignToGroundSlope = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bAlignToGroundSlope = { "bAlignToGroundSlope", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UPrefabricatorConstructionSnapComponent), &Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bAlignToGroundSlope_SetBit, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bAlignToGroundSlope_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bAlignToGroundSlope_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_WallConstraint_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_WallConstraint = { "WallConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorConstructionSnapComponent, WallConstraint), Z_Construct_UScriptStruct_FPCSnapConstraintWall, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_WallConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_WallConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_FloorConstraint_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_FloorConstraint = { "FloorConstraint", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorConstructionSnapComponent, FloorConstraint), Z_Construct_UScriptStruct_FPCSnapConstraintFloor, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_FloorConstraint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_FloorConstraint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_SnapType_MetaData[] = {
		{ "Category", "Prefabricator" },
		{ "Comment", "//~ End UPrimitiveComponent Interface.\n" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_SnapType = { "SnapType", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPrefabricatorConstructionSnapComponent, SnapType), Z_Construct_UEnum_ConstructionSystemRuntime_EPrefabricatorConstructionSnapType, METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_SnapType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_SnapType_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_SnapType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_MaxGroundPlacementSlope,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bUseMaxGroundSlopeConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_bAlignToGroundSlope,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_WallConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_FloorConstraint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_SnapType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::NewProp_SnapType_Underlying,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPrefabricatorConstructionSnapComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::ClassParams = {
		&UPrefabricatorConstructionSnapComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::PropPointers),
		0,
		0x00B010A4u,
		0x00000010u,
		METADATA_PARAMS(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPrefabricatorConstructionSnapComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPrefabricatorConstructionSnapComponent, 3065385560);
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<UPrefabricatorConstructionSnapComponent>()
	{
		return UPrefabricatorConstructionSnapComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPrefabricatorConstructionSnapComponent(Z_Construct_UClass_UPrefabricatorConstructionSnapComponent, &UPrefabricatorConstructionSnapComponent::StaticClass, TEXT("/Script/ConstructionSystemRuntime"), TEXT("UPrefabricatorConstructionSnapComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPrefabricatorConstructionSnapComponent);
	void APrefabricatorConstructionSnap::StaticRegisterNativesAPrefabricatorConstructionSnap()
	{
	}
	UClass* Z_Construct_UClass_APrefabricatorConstructionSnap_NoRegister()
	{
		return APrefabricatorConstructionSnap::StaticClass();
	}
	struct Z_Construct_UClass_APrefabricatorConstructionSnap_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConstructionSnapComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConstructionSnapComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ConstructionSystemRuntime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::Class_MetaDataParams[] = {
		{ "IgnoreCategoryKeywordsInSubclasses", "true" },
		{ "IncludePath", "ConstructionSystem/ConstructionSystemSnap.h" },
		{ "IsConversionRoot", "true" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::NewProp_ConstructionSnapComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Prefabricator" },
		{ "EditInline", "true" },
		{ "ExposeFunctionCategories", "Prefabricator" },
		{ "ModuleRelativePath", "Public/ConstructionSystem/ConstructionSystemSnap.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::NewProp_ConstructionSnapComponent = { "ConstructionSnapComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APrefabricatorConstructionSnap, ConstructionSnapComponent), Z_Construct_UClass_UPrefabricatorConstructionSnapComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::NewProp_ConstructionSnapComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::NewProp_ConstructionSnapComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::NewProp_ConstructionSnapComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrefabricatorConstructionSnap>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::ClassParams = {
		&APrefabricatorConstructionSnap::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::PropPointers),
		0,
		0x009000A4u,
		0x00000010u,
		METADATA_PARAMS(Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrefabricatorConstructionSnap()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrefabricatorConstructionSnap_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrefabricatorConstructionSnap, 1839608122);
	template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<APrefabricatorConstructionSnap>()
	{
		return APrefabricatorConstructionSnap::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrefabricatorConstructionSnap(Z_Construct_UClass_APrefabricatorConstructionSnap, &APrefabricatorConstructionSnap::StaticClass, TEXT("/Script/ConstructionSystemRuntime"), TEXT("APrefabricatorConstructionSnap"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrefabricatorConstructionSnap);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
