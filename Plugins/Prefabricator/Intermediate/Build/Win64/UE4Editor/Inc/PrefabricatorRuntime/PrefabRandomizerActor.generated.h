// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PREFABRICATORRUNTIME_PrefabRandomizerActor_generated_h
#error "PrefabRandomizerActor.generated.h already included, missing '#pragma once' in PrefabRandomizerActor.h"
#endif
#define PREFABRICATORRUNTIME_PrefabRandomizerActor_generated_h

#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_8_DELEGATE \
static inline void FPrefabRandomizerCompleteBindableEvent_DelegateWrapper(const FMulticastScriptDelegate& PrefabRandomizerCompleteBindableEvent) \
{ \
	PrefabRandomizerCompleteBindableEvent.ProcessMulticastDelegate<UObject>(NULL); \
}


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_SPARSE_DATA
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRandomize) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_InSeed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Randomize(Z_Param_InSeed); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRandomize) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_InSeed); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Randomize(Z_Param_InSeed); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPrefabRandomizer(); \
	friend struct Z_Construct_UClass_APrefabRandomizer_Statics; \
public: \
	DECLARE_CLASS(APrefabRandomizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(APrefabRandomizer)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAPrefabRandomizer(); \
	friend struct Z_Construct_UClass_APrefabRandomizer_Statics; \
public: \
	DECLARE_CLASS(APrefabRandomizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(APrefabRandomizer)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APrefabRandomizer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APrefabRandomizer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APrefabRandomizer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APrefabRandomizer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APrefabRandomizer(APrefabRandomizer&&); \
	NO_API APrefabRandomizer(const APrefabRandomizer&); \
public:


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APrefabRandomizer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APrefabRandomizer(APrefabRandomizer&&); \
	NO_API APrefabRandomizer(const APrefabRandomizer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APrefabRandomizer); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APrefabRandomizer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APrefabRandomizer)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_PRIVATE_PROPERTY_OFFSET
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_10_PROLOG
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_RPC_WRAPPERS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_INCLASS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_INCLASS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h_12_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class PrefabRandomizer."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PREFABRICATORRUNTIME_API UClass* StaticClass<class APrefabRandomizer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_Prefab_Random_PrefabRandomizerActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
