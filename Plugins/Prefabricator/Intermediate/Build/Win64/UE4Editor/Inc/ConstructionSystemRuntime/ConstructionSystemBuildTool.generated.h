// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrefabricatorAssetInterface;
#ifdef CONSTRUCTIONSYSTEMRUNTIME_ConstructionSystemBuildTool_generated_h
#error "ConstructionSystemBuildTool.generated.h already included, missing '#pragma once' in ConstructionSystemBuildTool.h"
#endif
#define CONSTRUCTIONSYSTEMRUNTIME_ConstructionSystemBuildTool_generated_h

#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_SPARSE_DATA
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execHandleInput_RotateCursorStep) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NumSteps); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInput_RotateCursorStep(Z_Param_NumSteps); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleInput_CursorMovePrev) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInput_CursorMovePrev(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleInput_CursorMoveNext) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInput_CursorMoveNext(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleInput_ConstructAtCursor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInput_ConstructAtCursor(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActivePrefab) \
	{ \
		P_GET_OBJECT(UPrefabricatorAssetInterface,Z_Param_InActivePrefabAsset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetActivePrefab(Z_Param_InActivePrefabAsset); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleInput_RotateCursorStep) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NumSteps); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInput_RotateCursorStep(Z_Param_NumSteps); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleInput_CursorMovePrev) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInput_CursorMovePrev(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleInput_CursorMoveNext) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInput_CursorMoveNext(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleInput_ConstructAtCursor) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleInput_ConstructAtCursor(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActivePrefab) \
	{ \
		P_GET_OBJECT(UPrefabricatorAssetInterface,Z_Param_InActivePrefabAsset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetActivePrefab(Z_Param_InActivePrefabAsset); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUConstructionSystemBuildTool(); \
	friend struct Z_Construct_UClass_UConstructionSystemBuildTool_Statics; \
public: \
	DECLARE_CLASS(UConstructionSystemBuildTool, UConstructionSystemTool, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ConstructionSystemRuntime"), NO_API) \
	DECLARE_SERIALIZER(UConstructionSystemBuildTool)


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUConstructionSystemBuildTool(); \
	friend struct Z_Construct_UClass_UConstructionSystemBuildTool_Statics; \
public: \
	DECLARE_CLASS(UConstructionSystemBuildTool, UConstructionSystemTool, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ConstructionSystemRuntime"), NO_API) \
	DECLARE_SERIALIZER(UConstructionSystemBuildTool)


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UConstructionSystemBuildTool(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UConstructionSystemBuildTool) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UConstructionSystemBuildTool); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UConstructionSystemBuildTool); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UConstructionSystemBuildTool(UConstructionSystemBuildTool&&); \
	NO_API UConstructionSystemBuildTool(const UConstructionSystemBuildTool&); \
public:


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UConstructionSystemBuildTool(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UConstructionSystemBuildTool(UConstructionSystemBuildTool&&); \
	NO_API UConstructionSystemBuildTool(const UConstructionSystemBuildTool&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UConstructionSystemBuildTool); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UConstructionSystemBuildTool); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UConstructionSystemBuildTool)


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Cursor() { return STRUCT_OFFSET(UConstructionSystemBuildTool, Cursor); } \
	FORCEINLINE static uint32 __PPO__ActivePrefabAsset() { return STRUCT_OFFSET(UConstructionSystemBuildTool, ActivePrefabAsset); }


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_14_PROLOG
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_RPC_WRAPPERS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_INCLASS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_INCLASS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<class UConstructionSystemBuildTool>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystem_Tools_ConstructionSystemBuildTool_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
