// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PREFABRICATORRUNTIME_PrefabricatorSettings_generated_h
#error "PrefabricatorSettings.generated.h already included, missing '#pragma once' in PrefabricatorSettings.h"
#endif
#define PREFABRICATORRUNTIME_PrefabricatorSettings_generated_h

#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_SPARSE_DATA
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_RPC_WRAPPERS
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_RPC_WRAPPERS_NO_PURE_DECLS
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPrefabricatorSettings(); \
	friend struct Z_Construct_UClass_UPrefabricatorSettings_Statics; \
public: \
	DECLARE_CLASS(UPrefabricatorSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(UPrefabricatorSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Prefabricator");} \



#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUPrefabricatorSettings(); \
	friend struct Z_Construct_UClass_UPrefabricatorSettings_Statics; \
public: \
	DECLARE_CLASS(UPrefabricatorSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/PrefabricatorRuntime"), NO_API) \
	DECLARE_SERIALIZER(UPrefabricatorSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Prefabricator");} \



#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPrefabricatorSettings(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPrefabricatorSettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPrefabricatorSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPrefabricatorSettings); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPrefabricatorSettings(UPrefabricatorSettings&&); \
	NO_API UPrefabricatorSettings(const UPrefabricatorSettings&); \
public:


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPrefabricatorSettings(UPrefabricatorSettings&&); \
	NO_API UPrefabricatorSettings(const UPrefabricatorSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPrefabricatorSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPrefabricatorSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPrefabricatorSettings)


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_PRIVATE_PROPERTY_OFFSET
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_20_PROLOG
#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_RPC_WRAPPERS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_INCLASS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_INCLASS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h_23_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PREFABRICATORRUNTIME_API UClass* StaticClass<class UPrefabricatorSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_Prefabricator_Source_PrefabricatorRuntime_Public_PrefabricatorSettings_h


#define FOREACH_ENUM_EPREFABRICATORPIVOTPOSITION(op) \
	op(EPrefabricatorPivotPosition::ExtremeLeft) \
	op(EPrefabricatorPivotPosition::ExtremeRight) \
	op(EPrefabricatorPivotPosition::Center) 

enum class EPrefabricatorPivotPosition : uint8;
template<> PREFABRICATORRUNTIME_API UEnum* StaticEnum<EPrefabricatorPivotPosition>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
