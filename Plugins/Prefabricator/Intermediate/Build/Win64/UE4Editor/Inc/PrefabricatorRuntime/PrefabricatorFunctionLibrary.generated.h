// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class APrefabActor;
struct FRandomStream;
class UObject;
class UPrefabricatorAssetInterface;
struct FTransform;
#ifdef PREFABRICATORRUNTIME_PrefabricatorFunctionLibrary_generated_h
#error "PrefabricatorFunctionLibrary.generated.h already included, missing '#pragma once' in PrefabricatorFunctionLibrary.h"
#endif
#define PREFABRICATORRUNTIME_PrefabricatorFunctionLibrary_generated_h

#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_SPARSE_DATA
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAllAttachedActors) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Prefab); \
		P_GET_TARRAY_REF(AActor*,Z_Param_Out_AttachedActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPrefabricatorBlueprintLibrary::GetAllAttachedActors(Z_Param_Prefab,Z_Param_Out_AttachedActors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRandomizePrefab) \
	{ \
		P_GET_OBJECT(APrefabActor,Z_Param_PrefabActor); \
		P_GET_STRUCT_REF(FRandomStream,Z_Param_Out_InRandom); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPrefabricatorBlueprintLibrary::RandomizePrefab(Z_Param_PrefabActor,Z_Param_Out_InRandom); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnPrefab) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(UPrefabricatorAssetInterface,Z_Param_Prefab); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_Transform); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Seed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(APrefabActor**)Z_Param__Result=UPrefabricatorBlueprintLibrary::SpawnPrefab(Z_Param_WorldContextObject,Z_Param_Prefab,Z_Param_Out_Transform,Z_Param_Seed); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAllAttachedActors) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_Prefab); \
		P_GET_TARRAY_REF(AActor*,Z_Param_Out_AttachedActors); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPrefabricatorBlueprintLibrary::GetAllAttachedActors(Z_Param_Prefab,Z_Param_Out_AttachedActors); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRandomizePrefab) \
	{ \
		P_GET_OBJECT(APrefabActor,Z_Param_PrefabActor); \
		P_GET_STRUCT_REF(FRandomStream,Z_Param_Out_InRandom); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UPrefabricatorBlueprintLibrary::RandomizePrefab(Z_Param_PrefabActor,Z_Param_Out_InRandom); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSpawnPrefab) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_OBJECT(UPrefabricatorAssetInterface,Z_Param_Prefab); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_Transform); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Seed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(APrefabActor**)Z_Param__Result=UPrefabricatorBlueprintLibrary::SpawnPrefab(Z_Param_WorldContextObject,Z_Param_Prefab,Z_Param_Out_Transform,Z_Param_Seed); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPrefabricatorBlueprintLibrary(); \
	friend struct Z_Construct_UClass_UPrefabricatorBlueprintLibrary_Statics; \
public: \
	DECLARE_CLASS(UPrefabricatorBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(UPrefabricatorBlueprintLibrary)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUPrefabricatorBlueprintLibrary(); \
	friend struct Z_Construct_UClass_UPrefabricatorBlueprintLibrary_Statics; \
public: \
	DECLARE_CLASS(UPrefabricatorBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(UPrefabricatorBlueprintLibrary)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPrefabricatorBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPrefabricatorBlueprintLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPrefabricatorBlueprintLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPrefabricatorBlueprintLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPrefabricatorBlueprintLibrary(UPrefabricatorBlueprintLibrary&&); \
	NO_API UPrefabricatorBlueprintLibrary(const UPrefabricatorBlueprintLibrary&); \
public:


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPrefabricatorBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPrefabricatorBlueprintLibrary(UPrefabricatorBlueprintLibrary&&); \
	NO_API UPrefabricatorBlueprintLibrary(const UPrefabricatorBlueprintLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPrefabricatorBlueprintLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPrefabricatorBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPrefabricatorBlueprintLibrary)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_PRIVATE_PROPERTY_OFFSET
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_12_PROLOG
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_RPC_WRAPPERS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_INCLASS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_INCLASS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PREFABRICATORRUNTIME_API UClass* StaticClass<class UPrefabricatorBlueprintLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Utils_PrefabricatorFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
