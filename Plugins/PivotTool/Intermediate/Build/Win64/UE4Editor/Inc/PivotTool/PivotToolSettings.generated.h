// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PIVOTTOOL_PivotToolSettings_generated_h
#error "PivotToolSettings.generated.h already included, missing '#pragma once' in PivotToolSettings.h"
#endif
#define PIVOTTOOL_PivotToolSettings_generated_h

#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_SPARSE_DATA
#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_RPC_WRAPPERS
#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPivotToolSettings(); \
	friend struct Z_Construct_UClass_UPivotToolSettings_Statics; \
public: \
	DECLARE_CLASS(UPivotToolSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/PivotTool"), NO_API) \
	DECLARE_SERIALIZER(UPivotToolSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Editor");} \



#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUPivotToolSettings(); \
	friend struct Z_Construct_UClass_UPivotToolSettings_Statics; \
public: \
	DECLARE_CLASS(UPivotToolSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/PivotTool"), NO_API) \
	DECLARE_SERIALIZER(UPivotToolSettings) \
	static const TCHAR* StaticConfigName() {return TEXT("Editor");} \



#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPivotToolSettings(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPivotToolSettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPivotToolSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPivotToolSettings); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPivotToolSettings(UPivotToolSettings&&); \
	NO_API UPivotToolSettings(const UPivotToolSettings&); \
public:


#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPivotToolSettings(UPivotToolSettings&&); \
	NO_API UPivotToolSettings(const UPivotToolSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPivotToolSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPivotToolSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPivotToolSettings)


#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_PRIVATE_PROPERTY_OFFSET
#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_17_PROLOG
#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_SPARSE_DATA \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_RPC_WRAPPERS \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_INCLASS \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_SPARSE_DATA \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_INCLASS_NO_PURE_DECLS \
	Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PIVOTTOOL_API UClass* StaticClass<class UPivotToolSettings>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_PivotTool_Source_PivotTool_Private_EdMode_PivotToolSettings_h


#define FOREACH_ENUM_EPIVOTTOOLPREVIEWSHAPE(op) \
	op(EPivotToolPreviewShape::None) \
	op(EPivotToolPreviewShape::Point) \
	op(EPivotToolPreviewShape::Sphere) \
	op(EPivotToolPreviewShape::Coordinate) 

enum class EPivotToolPreviewShape : uint8;
template<> PIVOTTOOL_API UEnum* StaticEnum<EPivotToolPreviewShape>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
