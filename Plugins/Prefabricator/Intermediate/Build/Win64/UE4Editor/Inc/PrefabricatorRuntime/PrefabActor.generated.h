// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FRandomStream;
class UPrefabricatorAsset;
#ifdef PREFABRICATORRUNTIME_PrefabActor_generated_h
#error "PrefabActor.generated.h already included, missing '#pragma once' in PrefabActor.h"
#endif
#define PREFABRICATORRUNTIME_PrefabActor_generated_h

#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_SPARSE_DATA
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRandomizeSeed) \
	{ \
		P_GET_STRUCT_REF(FRandomStream,Z_Param_Out_InRandom); \
		P_GET_UBOOL(Z_Param_bRecursive); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RandomizeSeed(Z_Param_Out_InRandom,Z_Param_bRecursive); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrefabAsset) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UPrefabricatorAsset**)Z_Param__Result=P_THIS->GetPrefabAsset(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPrefabOutdated) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPrefabOutdated(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSavePrefab) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SavePrefab(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadPrefab) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadPrefab(); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRandomizeSeed) \
	{ \
		P_GET_STRUCT_REF(FRandomStream,Z_Param_Out_InRandom); \
		P_GET_UBOOL(Z_Param_bRecursive); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RandomizeSeed(Z_Param_Out_InRandom,Z_Param_bRecursive); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPrefabAsset) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UPrefabricatorAsset**)Z_Param__Result=P_THIS->GetPrefabAsset(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPrefabOutdated) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPrefabOutdated(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSavePrefab) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SavePrefab(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadPrefab) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->LoadPrefab(); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPrefabActor(); \
	friend struct Z_Construct_UClass_APrefabActor_Statics; \
public: \
	DECLARE_CLASS(APrefabActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(APrefabActor)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_INCLASS \
private: \
	static void StaticRegisterNativesAPrefabActor(); \
	friend struct Z_Construct_UClass_APrefabActor_Statics; \
public: \
	DECLARE_CLASS(APrefabActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(APrefabActor)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APrefabActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APrefabActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APrefabActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APrefabActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APrefabActor(APrefabActor&&); \
	NO_API APrefabActor(const APrefabActor&); \
public:


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APrefabActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APrefabActor(APrefabActor&&); \
	NO_API APrefabActor(const APrefabActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APrefabActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APrefabActor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APrefabActor)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_PRIVATE_PROPERTY_OFFSET
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_9_PROLOG
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_RPC_WRAPPERS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_INCLASS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_INCLASS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_11_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class PrefabActor."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PREFABRICATORRUNTIME_API UClass* StaticClass<class APrefabActor>();

#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_SPARSE_DATA
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_RPC_WRAPPERS
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_RPC_WRAPPERS_NO_PURE_DECLS
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAReplicablePrefabActor(); \
	friend struct Z_Construct_UClass_AReplicablePrefabActor_Statics; \
public: \
	DECLARE_CLASS(AReplicablePrefabActor, APrefabActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(AReplicablePrefabActor)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_INCLASS \
private: \
	static void StaticRegisterNativesAReplicablePrefabActor(); \
	friend struct Z_Construct_UClass_AReplicablePrefabActor_Statics; \
public: \
	DECLARE_CLASS(AReplicablePrefabActor, APrefabActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(AReplicablePrefabActor)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AReplicablePrefabActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AReplicablePrefabActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AReplicablePrefabActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AReplicablePrefabActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AReplicablePrefabActor(AReplicablePrefabActor&&); \
	NO_API AReplicablePrefabActor(const AReplicablePrefabActor&); \
public:


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AReplicablePrefabActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AReplicablePrefabActor(AReplicablePrefabActor&&); \
	NO_API AReplicablePrefabActor(const AReplicablePrefabActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AReplicablePrefabActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AReplicablePrefabActor); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AReplicablePrefabActor)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_PRIVATE_PROPERTY_OFFSET
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_116_PROLOG
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_RPC_WRAPPERS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_INCLASS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_INCLASS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h_118_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class ReplicablePrefabActor."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PREFABRICATORRUNTIME_API UClass* StaticClass<class AReplicablePrefabActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_PrefabActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
