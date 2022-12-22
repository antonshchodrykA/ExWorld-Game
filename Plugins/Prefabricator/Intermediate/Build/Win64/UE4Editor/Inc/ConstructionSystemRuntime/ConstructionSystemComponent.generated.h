// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EConstructionSystemToolType : uint8;
class UConstructionSystemTool;
#ifdef CONSTRUCTIONSYSTEMRUNTIME_ConstructionSystemComponent_generated_h
#error "ConstructionSystemComponent.generated.h already included, missing '#pragma once' in ConstructionSystemComponent.h"
#endif
#define CONSTRUCTIONSYSTEMRUNTIME_ConstructionSystemComponent_generated_h

#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_SPARSE_DATA
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetTool) \
	{ \
		P_GET_ENUM(EConstructionSystemToolType,Z_Param_InToolType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UConstructionSystemTool**)Z_Param__Result=P_THIS->GetTool(EConstructionSystemToolType(Z_Param_InToolType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActiveTool) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UConstructionSystemTool**)Z_Param__Result=P_THIS->GetActiveTool(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActiveToolType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EConstructionSystemToolType*)Z_Param__Result=P_THIS->GetActiveToolType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActiveTool) \
	{ \
		P_GET_ENUM(EConstructionSystemToolType,Z_Param_InToolType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetActiveTool(EConstructionSystemToolType(Z_Param_InToolType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHideBuildMenu) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HideBuildMenu(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShowBuildMenu) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ShowBuildMenu(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisableConstructionSystem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DisableConstructionSystem(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableConstructionSystem) \
	{ \
		P_GET_ENUM(EConstructionSystemToolType,Z_Param_InToolType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnableConstructionSystem(EConstructionSystemToolType(Z_Param_InToolType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execToggleConstructionSystem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ToggleConstructionSystem(); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetTool) \
	{ \
		P_GET_ENUM(EConstructionSystemToolType,Z_Param_InToolType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UConstructionSystemTool**)Z_Param__Result=P_THIS->GetTool(EConstructionSystemToolType(Z_Param_InToolType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActiveTool) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UConstructionSystemTool**)Z_Param__Result=P_THIS->GetActiveTool(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetActiveToolType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EConstructionSystemToolType*)Z_Param__Result=P_THIS->GetActiveToolType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActiveTool) \
	{ \
		P_GET_ENUM(EConstructionSystemToolType,Z_Param_InToolType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetActiveTool(EConstructionSystemToolType(Z_Param_InToolType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHideBuildMenu) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HideBuildMenu(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execShowBuildMenu) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ShowBuildMenu(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisableConstructionSystem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DisableConstructionSystem(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEnableConstructionSystem) \
	{ \
		P_GET_ENUM(EConstructionSystemToolType,Z_Param_InToolType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EnableConstructionSystem(EConstructionSystemToolType(Z_Param_InToolType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execToggleConstructionSystem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ToggleConstructionSystem(); \
		P_NATIVE_END; \
	}


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUConstructionSystemComponent(); \
	friend struct Z_Construct_UClass_UConstructionSystemComponent_Statics; \
public: \
	DECLARE_CLASS(UConstructionSystemComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ConstructionSystemRuntime"), NO_API) \
	DECLARE_SERIALIZER(UConstructionSystemComponent)


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_INCLASS \
private: \
	static void StaticRegisterNativesUConstructionSystemComponent(); \
	friend struct Z_Construct_UClass_UConstructionSystemComponent_Statics; \
public: \
	DECLARE_CLASS(UConstructionSystemComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ConstructionSystemRuntime"), NO_API) \
	DECLARE_SERIALIZER(UConstructionSystemComponent)


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UConstructionSystemComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UConstructionSystemComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UConstructionSystemComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UConstructionSystemComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UConstructionSystemComponent(UConstructionSystemComponent&&); \
	NO_API UConstructionSystemComponent(const UConstructionSystemComponent&); \
public:


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UConstructionSystemComponent(UConstructionSystemComponent&&); \
	NO_API UConstructionSystemComponent(const UConstructionSystemComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UConstructionSystemComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UConstructionSystemComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UConstructionSystemComponent)


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_PRIVATE_PROPERTY_OFFSET
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_24_PROLOG
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_RPC_WRAPPERS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_INCLASS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_INCLASS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<class UConstructionSystemComponent>();

#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_SPARSE_DATA
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_RPC_WRAPPERS
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_RPC_WRAPPERS_NO_PURE_DECLS
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUConstructionSystemItemUserData(); \
	friend struct Z_Construct_UClass_UConstructionSystemItemUserData_Statics; \
public: \
	DECLARE_CLASS(UConstructionSystemItemUserData, UAssetUserData, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ConstructionSystemRuntime"), NO_API) \
	DECLARE_SERIALIZER(UConstructionSystemItemUserData)


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_INCLASS \
private: \
	static void StaticRegisterNativesUConstructionSystemItemUserData(); \
	friend struct Z_Construct_UClass_UConstructionSystemItemUserData_Statics; \
public: \
	DECLARE_CLASS(UConstructionSystemItemUserData, UAssetUserData, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ConstructionSystemRuntime"), NO_API) \
	DECLARE_SERIALIZER(UConstructionSystemItemUserData)


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UConstructionSystemItemUserData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UConstructionSystemItemUserData) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UConstructionSystemItemUserData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UConstructionSystemItemUserData); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UConstructionSystemItemUserData(UConstructionSystemItemUserData&&); \
	NO_API UConstructionSystemItemUserData(const UConstructionSystemItemUserData&); \
public:


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UConstructionSystemItemUserData(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UConstructionSystemItemUserData(UConstructionSystemItemUserData&&); \
	NO_API UConstructionSystemItemUserData(const UConstructionSystemItemUserData&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UConstructionSystemItemUserData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UConstructionSystemItemUserData); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UConstructionSystemItemUserData)


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_PRIVATE_PROPERTY_OFFSET
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_124_PROLOG
#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_RPC_WRAPPERS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_INCLASS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_PRIVATE_PROPERTY_OFFSET \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_SPARSE_DATA \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_RPC_WRAPPERS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_INCLASS_NO_PURE_DECLS \
	Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h_126_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CONSTRUCTIONSYSTEMRUNTIME_API UClass* StaticClass<class UConstructionSystemItemUserData>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Game_Plugins_Prefabricator_Source_ConstructionSystemRuntime_Public_ConstructionSystemComponent_h


#define FOREACH_ENUM_ECONSTRUCTIONSYSTEMTOOLTYPE(op) \
	op(EConstructionSystemToolType::BuildTool) \
	op(EConstructionSystemToolType::RemoveTool) 

enum class EConstructionSystemToolType : uint8;
template<> CONSTRUCTIONSYSTEMRUNTIME_API UEnum* StaticEnum<EConstructionSystemToolType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
