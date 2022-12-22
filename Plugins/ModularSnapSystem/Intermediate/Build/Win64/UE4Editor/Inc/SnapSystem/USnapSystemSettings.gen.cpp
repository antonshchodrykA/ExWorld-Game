// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SnapSystem/Public/USnapSystemSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUSnapSystemSettings() {}
// Cross Module References
	SNAPSYSTEM_API UEnum* Z_Construct_UEnum_SnapSystem_EShowSocketMode();
	UPackage* Z_Construct_UPackage__Script_SnapSystem();
	SNAPSYSTEM_API UClass* Z_Construct_UClass_UUSnapSystemSettings_NoRegister();
	SNAPSYSTEM_API UClass* Z_Construct_UClass_UUSnapSystemSettings();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSoftClassPath();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	static UEnum* EShowSocketMode_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_SnapSystem_EShowSocketMode, Z_Construct_UPackage__Script_SnapSystem(), TEXT("EShowSocketMode"));
		}
		return Singleton;
	}
	template<> SNAPSYSTEM_API UEnum* StaticEnum<EShowSocketMode::Type>()
	{
		return EShowSocketMode_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EShowSocketMode(EShowSocketMode_StaticEnum, TEXT("/Script/SnapSystem"), TEXT("EShowSocketMode"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_SnapSystem_EShowSocketMode_Hash() { return 2682550033U; }
	UEnum* Z_Construct_UEnum_SnapSystem_EShowSocketMode()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_SnapSystem();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EShowSocketMode"), 0, Get_Z_Construct_UEnum_SnapSystem_EShowSocketMode_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EShowSocketMode::Short", (int64)EShowSocketMode::Short },
				{ "EShowSocketMode::Normal", (int64)EShowSocketMode::Normal },
				{ "EShowSocketMode::Full", (int64)EShowSocketMode::Full },
				{ "EShowSocketMode::MAX", (int64)EShowSocketMode::MAX },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Full.Comment", "//Shows the transform and the full socket name\n" },
				{ "Full.Name", "EShowSocketMode::Full" },
				{ "Full.ToolTip", "Shows the transform and the full socket name" },
				{ "MAX.Hidden", "" },
				{ "MAX.Name", "EShowSocketMode::MAX" },
				{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
				{ "Normal.Comment", "//Shows the transform and the snap point name\n" },
				{ "Normal.Name", "EShowSocketMode::Normal" },
				{ "Normal.ToolTip", "Shows the transform and the snap point name" },
				{ "Short.Comment", "//Shows only the transform\n" },
				{ "Short.Name", "EShowSocketMode::Short" },
				{ "Short.ToolTip", "Shows only the transform" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_SnapSystem,
				nullptr,
				"EShowSocketMode",
				"EShowSocketMode::Type",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Namespaced,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void UUSnapSystemSettings::StaticRegisterNativesUUSnapSystemSettings()
	{
	}
	UClass* Z_Construct_UClass_UUSnapSystemSettings_NoRegister()
	{
		return UUSnapSystemSettings::StaticClass();
	}
	struct Z_Construct_UClass_UUSnapSystemSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetComponentClasses_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TargetComponentClasses;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetComponentClasses_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SourceComponentClasses_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SourceComponentClasses;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SourceComponentClasses_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIgnoreSplineSocketScale_MetaData[];
#endif
		static void NewProp_bIgnoreSplineSocketScale_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIgnoreSplineSocketScale;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NoSnapbackTolerance_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_NoSnapbackTolerance;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bNoSnapback_MetaData[];
#endif
		static void NewProp_bNoSnapback_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNoSnapback;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSnapPivot_MetaData[];
#endif
		static void NewProp_bSnapPivot_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSnapPivot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAttachToSocket_MetaData[];
#endif
		static void NewProp_bAttachToSocket_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAttachToSocket;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAttachToParent_MetaData[];
#endif
		static void NewProp_bAttachToParent_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAttachToParent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIgnoreSocketParams_MetaData[];
#endif
		static void NewProp_bIgnoreSocketParams_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIgnoreSocketParams;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultScaleSnap_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DefaultScaleSnap;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultRotSnap_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_DefaultRotSnap;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bUseNoSnapTag_MetaData[];
#endif
		static void NewProp_bUseNoSnapTag_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bUseNoSnapTag;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OpenCheckRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_OpenCheckRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSnapOpenOnly_MetaData[];
#endif
		static void NewProp_bSnapOpenOnly_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSnapOpenOnly;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSnapAttachedToo_MetaData[];
#endif
		static void NewProp_bSnapAttachedToo_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSnapAttachedToo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIgnoreSocketName_MetaData[];
#endif
		static void NewProp_bIgnoreSocketName_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIgnoreSocketName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxAngle_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxAngle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SearchDist_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SearchDist;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShowSocketMode_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ShowSocketMode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShowSockets_MetaData[];
#endif
		static void NewProp_bShowSockets_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowSockets;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsEnabled_MetaData[];
#endif
		static void NewProp_bIsEnabled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsEnabled;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUSnapSystemSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SnapSystem,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Snap system plugin settings \n */" },
		{ "IncludePath", "USnapSystemSettings.h" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Snap system plugin settings" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_TargetComponentClasses_MetaData[] = {
		{ "Category", "Search" },
		{ "Comment", "//Components to snap to. Target of search operation.\n//\n//Components of actors that was not moved where matching snap points can be located.\n//Can be any component containig sockets and SplineComponent \n//(endpoints are considered as sockets for splines)\n//\n//Default: (StaticMeshComponent, SplineComponent)\n" },
		{ "MetaClass", "SceneComponent" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Components to snap to. Target of search operation.\n\nComponents of actors that was not moved where matching snap points can be located.\nCan be any component containig sockets and SplineComponent\n(endpoints are considered as sockets for splines)\n\nDefault: (StaticMeshComponent, SplineComponent)" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_TargetComponentClasses = { "TargetComponentClasses", nullptr, (EPropertyFlags)0x0010040002004001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUSnapSystemSettings, TargetComponentClasses), METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_TargetComponentClasses_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_TargetComponentClasses_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_TargetComponentClasses_Inner = { "TargetComponentClasses", nullptr, (EPropertyFlags)0x0000000000004000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSoftClassPath, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SourceComponentClasses_MetaData[] = {
		{ "Category", "Search" },
		{ "Comment", "//Components to snap. Source of search operation.\n//\n//Components of moved actors around which we will start to search for snapping points\n//Can be any scene component containig sockets and SplineComponent \n//(endpoints are considered as sockets for splines)\n//\n//Default: (StaticMeshComponent, SplineComponent)\n" },
		{ "MetaClass", "SceneComponent" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Components to snap. Source of search operation.\n\nComponents of moved actors around which we will start to search for snapping points\nCan be any scene component containig sockets and SplineComponent\n(endpoints are considered as sockets for splines)\n\nDefault: (StaticMeshComponent, SplineComponent)" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SourceComponentClasses = { "SourceComponentClasses", nullptr, (EPropertyFlags)0x0010040002004001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUSnapSystemSettings, SourceComponentClasses), METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SourceComponentClasses_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SourceComponentClasses_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SourceComponentClasses_Inner = { "SourceComponentClasses", nullptr, (EPropertyFlags)0x0000000000004000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FSoftClassPath, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSplineSocketScale_MetaData[] = {
		{ "Category", "Snap" },
		{ "Comment", "//Ignore scale when using spline end point as socket.\n//\n//Spline point scale is often non-uniform and in general \n//quite different thing from normal actor's scale.\n//Therefore scaling actors to it can lead to weird results.\n//\n//This flag is taken into account when snapping actors, \n//but ignored when snapping spline endpoint to another spline endpoint. \n//Spline endpoints will use socket scale when it's \n//allowed by global and socket parameters.\n//\n//Default: true\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Ignore scale when using spline end point as socket.\n\nSpline point scale is often non-uniform and in general\nquite different thing from normal actor's scale.\nTherefore scaling actors to it can lead to weird results.\n\nThis flag is taken into account when snapping actors,\nbut ignored when snapping spline endpoint to another spline endpoint.\nSpline endpoints will use socket scale when it's\nallowed by global and socket parameters.\n\nDefault: true" },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSplineSocketScale_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bIgnoreSplineSocketScale = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSplineSocketScale = { "bIgnoreSplineSocketScale", nullptr, (EPropertyFlags)0x0010040000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSplineSocketScale_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSplineSocketScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSplineSocketScale_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_NoSnapbackTolerance_MetaData[] = {
		{ "Category", "Snap" },
		{ "Comment", "//How close is considered equals for \"No Snapback\" \n//\n//Because of numerical errors for very large objects \n//the default value of 0.1 can be too much. Try to increase.\n//For very small objects 1mm may be too much. Try to decrease.\n//\n//Default: 0.1 (1mm)\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "How close is considered equals for \"No Snapback\"\n\nBecause of numerical errors for very large objects\nthe default value of 0.1 can be too much. Try to increase.\nFor very small objects 1mm may be too much. Try to decrease.\n\nDefault: 0.1 (1mm)" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_NoSnapbackTolerance = { "NoSnapbackTolerance", nullptr, (EPropertyFlags)0x0010040000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUSnapSystemSettings, NoSnapbackTolerance), METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_NoSnapbackTolerance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_NoSnapbackTolerance_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bNoSnapback_MetaData[] = {
		{ "Category", "Snap" },
		{ "Comment", "//Prevents \"snapping back\" to the previous snap point.\n//\n//If you snap an actor to another, then move it away a little it will snap back.\n//That can be annoying. Setting bNoSnapback to true prevents this behaviour.\n//Snap operation will be aborted if the transform after the snap \n//is equal to the transform before the move started.\n//\n//Default: true\n//\n//See also: \"Hold to Skip Snap\" keyboard shortcut (default: C) under \n//\"Editor Preferences -> Keyboard Shortcuts -> SnapSystem Plugin\"\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Prevents \"snapping back\" to the previous snap point.\n\nIf you snap an actor to another, then move it away a little it will snap back.\nThat can be annoying. Setting bNoSnapback to true prevents this behaviour.\nSnap operation will be aborted if the transform after the snap\nis equal to the transform before the move started.\n\nDefault: true\n\nSee also: \"Hold to Skip Snap\" keyboard shortcut (default: C) under\n\"Editor Preferences -> Keyboard Shortcuts -> SnapSystem Plugin\"" },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bNoSnapback_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bNoSnapback = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bNoSnapback = { "bNoSnapback", nullptr, (EPropertyFlags)0x0010040000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bNoSnapback_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bNoSnapback_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bNoSnapback_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapPivot_MetaData[] = {
		{ "Category", "Snap" },
		{ "Comment", "//Move the selection pivot to the snap point. Useful for rotating the snapped actors\n//around the last snap point. \n//\n//Default: false.\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Move the selection pivot to the snap point. Useful for rotating the snapped actors\naround the last snap point.\n\nDefault: false." },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapPivot_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bSnapPivot = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapPivot = { "bSnapPivot", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapPivot_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapPivot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapPivot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToSocket_MetaData[] = {
		{ "Category", "Snap" },
		{ "Comment", "//When snapping to the socket marked with \"_A\" parameter, should we attach to the target socket or to the target actor's root?\n//\n//If this is true (default), the snapped actor will be attached to the matched target actor's socket.\n//Otherwise, it will be attached to the target actor's origin.\n//Attaching to socket may be important when attaching to skeletal meshes (attach to the hand for example),\n//but also can give problems when the attached actor is duplicated using alt-drag \n//(Unreal fails to calculate the correct transform for the duplicated actor, so it will be upside-down)\n//\n//Attaching to Static Mesh Components ignores this parameter, always attach to the origin.\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "When snapping to the socket marked with \"_A\" parameter, should we attach to the target socket or to the target actor's root?\n\nIf this is true (default), the snapped actor will be attached to the matched target actor's socket.\nOtherwise, it will be attached to the target actor's origin.\nAttaching to socket may be important when attaching to skeletal meshes (attach to the hand for example),\nbut also can give problems when the attached actor is duplicated using alt-drag\n(Unreal fails to calculate the correct transform for the duplicated actor, so it will be upside-down)\n\nAttaching to Static Mesh Components ignores this parameter, always attach to the origin." },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToSocket_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bAttachToSocket = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToSocket = { "bAttachToSocket", nullptr, (EPropertyFlags)0x0010040000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToSocket_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToSocket_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToSocket_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToParent_MetaData[] = {
		{ "Category", "Snap" },
		{ "Comment", "//Attach selected actors to the parent ot the target actor (the actor who has the matched socket).\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Attach selected actors to the parent ot the target actor (the actor who has the matched socket)." },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToParent_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bAttachToParent = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToParent = { "bAttachToParent", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToParent_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToParent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToParent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketParams_MetaData[] = {
		{ "Category", "Snap" },
		{ "Comment", "//Don't use socket parameters when snapping.\n//\n//If true: snap point parameters like rotsnap (the part of the socket name after the first \"_\") \n//will not be used, only the default values defined here in settings will be used.\n//\n//Deafult: false\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Don't use socket parameters when snapping.\n\nIf true: snap point parameters like rotsnap (the part of the socket name after the first \"_\")\nwill not be used, only the default values defined here in settings will be used.\n\nDeafult: false" },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketParams_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bIgnoreSocketParams = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketParams = { "bIgnoreSocketParams", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketParams_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketParams_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketParams_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultScaleSnap_MetaData[] = {
		{ "Category", "Snap" },
		{ "Comment", "//Scale snap flag. Can be overriden in socket name using _SX _SY _SZ parameters.\n//\n//0 means: keep world scale, no scale snap, \n//1: snap to the target socket world scale\n//Allowed values: 0 or 1. Default (1, 1, 1). \n//\n//WARNING! UE4 Actor's scale is always in actor's LOCAL SPACE (not socket space).\n//It means, that for non uniform scaling weird results are expected.\n//\n//USE WITH CAUTION!\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Scale snap flag. Can be overriden in socket name using _SX _SY _SZ parameters.\n\n0 means: keep world scale, no scale snap,\n1: snap to the target socket world scale\nAllowed values: 0 or 1. Default (1, 1, 1).\n\nWARNING! UE4 Actor's scale is always in actor's LOCAL SPACE (not socket space).\nIt means, that for non uniform scaling weird results are expected.\n\nUSE WITH CAUTION!" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultScaleSnap = { "DefaultScaleSnap", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUSnapSystemSettings, DefaultScaleSnap), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultScaleSnap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultScaleSnap_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultRotSnap_MetaData[] = {
		{ "Category", "Snap" },
		{ "Comment", "//Rotation snap in degrees. Can be overriden in socket name using _RX _RY _RZ parameters.\n//\n//0 means: keep world rotation, no rotation snap, \n//360: snap to the target socket world rotation,\n//angles in between: snap to the nearest increment from the target socket world rotation. \n//\n//Allowed values [0-360]. Default (90, 360, 360)\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Rotation snap in degrees. Can be overriden in socket name using _RX _RY _RZ parameters.\n\n0 means: keep world rotation, no rotation snap,\n360: snap to the target socket world rotation,\nangles in between: snap to the nearest increment from the target socket world rotation.\n\nAllowed values [0-360]. Default (90, 360, 360)" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultRotSnap = { "DefaultRotSnap", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUSnapSystemSettings, DefaultRotSnap), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultRotSnap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultRotSnap_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bUseNoSnapTag_MetaData[] = {
		{ "Category", "Search" },
		{ "Comment", "//Enables the check of \"nosnap\" component tag. \n//If the component has such tag it will not be considered for snap operation.\n//\n//Default: true\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Enables the check of \"nosnap\" component tag.\nIf the component has such tag it will not be considered for snap operation.\n\nDefault: true" },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bUseNoSnapTag_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bUseNoSnapTag = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bUseNoSnapTag = { "bUseNoSnapTag", nullptr, (EPropertyFlags)0x0010040000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bUseNoSnapTag_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bUseNoSnapTag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bUseNoSnapTag_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_OpenCheckRadius_MetaData[] = {
		{ "Category", "Search" },
		{ "Comment", "//If bSnapOpenOnly is enabled, how far to look for obstruction\n//Wii trace with a sphere centered at this distance in front of the socket\n//\n//Default: 2cm\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "If bSnapOpenOnly is enabled, how far to look for obstruction\nWii trace with a sphere centered at this distance in front of the socket\n\nDefault: 2cm" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_OpenCheckRadius = { "OpenCheckRadius", nullptr, (EPropertyFlags)0x0010040000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUSnapSystemSettings, OpenCheckRadius), METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_OpenCheckRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_OpenCheckRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapOpenOnly_MetaData[] = {
		{ "Category", "Search" },
		{ "Comment", "//Check if a socket is \"open\" before considering it for snapping\n//Runs an additional sphere trace just in front of the socket to see if there is no obstruction\n//Only components in TargetComponentClasses are considered as blockers!\n//\n//If false: don't run \"open\" checks\n//If true: check if the socket is not hidden by something else\n//\n//Default: false\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Check if a socket is \"open\" before considering it for snapping\nRuns an additional sphere trace just in front of the socket to see if there is no obstruction\nOnly components in TargetComponentClasses are considered as blockers!\n\nIf false: don't run \"open\" checks\nIf true: check if the socket is not hidden by something else\n\nDefault: false" },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapOpenOnly_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bSnapOpenOnly = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapOpenOnly = { "bSnapOpenOnly", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapOpenOnly_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapOpenOnly_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapOpenOnly_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapAttachedToo_MetaData[] = {
		{ "Category", "Search" },
		{ "Comment", "//When moving an actor with other actors attached to it \n//consider sockets of attached actors too, even if they are not selected.\n//Useful with some \"prefab\" style plugins.\n//\n//If false: consider only sockets of selected actors\n//If true: consider selected actors and actors attached to them (everything that moves)\n//\n//Default: false\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "When moving an actor with other actors attached to it\nconsider sockets of attached actors too, even if they are not selected.\nUseful with some \"prefab\" style plugins.\n\nIf false: consider only sockets of selected actors\nIf true: consider selected actors and actors attached to them (everything that moves)\n\nDefault: false" },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapAttachedToo_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bSnapAttachedToo = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapAttachedToo = { "bSnapAttachedToo", nullptr, (EPropertyFlags)0x0010040000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapAttachedToo_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapAttachedToo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapAttachedToo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketName_MetaData[] = {
		{ "Category", "Search" },
		{ "Comment", "//Don't check socket names when searching for socket to snap to.\n//\n//If false: only sockets with matching names (same prefix before the first \"_\" character) will snap.\n//If true: all sockets will snap, regardless of their names.\n//\n//Deafult: false\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Don't check socket names when searching for socket to snap to.\n\nIf false: only sockets with matching names (same prefix before the first \"_\" character) will snap.\nIf true: all sockets will snap, regardless of their names.\n\nDeafult: false" },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketName_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bIgnoreSocketName = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketName = { "bIgnoreSocketName", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketName_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_MaxAngle_MetaData[] = {
		{ "Category", "Search" },
		{ "ClampMax", "180" },
		{ "ClampMin", "0" },
		{ "Comment", "//Max angle in degrees between sockets that are allowed to snap.\n//\n//0 means X-axis should be stricty opposing each other, \n//while 180 means sockets at any angle can snap.\n//\n//Allowed values [0-180]. Default value is 75 degrees.\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Max angle in degrees between sockets that are allowed to snap.\n\n0 means X-axis should be stricty opposing each other,\nwhile 180 means sockets at any angle can snap.\n\nAllowed values [0-180]. Default value is 75 degrees." },
		{ "UIMax", "180" },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_MaxAngle = { "MaxAngle", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUSnapSystemSettings, MaxAngle), METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_MaxAngle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_MaxAngle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SearchDist_MetaData[] = {
		{ "Category", "Search" },
		{ "ClampMin", "0" },
		{ "Comment", "//How far in centimeters to look for a matching socket. \n//\n//Default: 100cm.\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "How far in centimeters to look for a matching socket.\n\nDefault: 100cm." },
		{ "UIMin", "0" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SearchDist = { "SearchDist", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUSnapSystemSettings, SearchDist), METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SearchDist_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SearchDist_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_ShowSocketMode_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "//Modes for showing sockets\n//Default: Normal\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Modes for showing sockets\nDefault: Normal" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_ShowSocketMode = { "ShowSocketMode", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UUSnapSystemSettings, ShowSocketMode), Z_Construct_UEnum_SnapSystem_EShowSocketMode, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_ShowSocketMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_ShowSocketMode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bShowSockets_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "//Show sockets on selected actors. Only the \"snap point name\" \n//is shown (the part of the socket name before the first \"_\")\n//\n//Default: false\n//\n//You can configure the keyboard shortcut for this and other commands\n//under \"Editor Preferences -> Keyboard Shortcuts -> SnapSystem Plugin\"\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Show sockets on selected actors. Only the \"snap point name\"\nis shown (the part of the socket name before the first \"_\")\n\nDefault: false\n\nYou can configure the keyboard shortcut for this and other commands\nunder \"Editor Preferences -> Keyboard Shortcuts -> SnapSystem Plugin\"" },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bShowSockets_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bShowSockets = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bShowSockets = { "bShowSockets", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bShowSockets_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bShowSockets_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bShowSockets_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIsEnabled_MetaData[] = {
		{ "Category", "Settings" },
		{ "Comment", "//Enables or disables SnapSystem Plugin. Same as the viewport button.\n//\n//You can configure the keyboard shortcut for this and other commands\n//under \"Editor Preferences -> Keyboard Shortcuts -> SnapSystem Plugin\"\n" },
		{ "ModuleRelativePath", "Public/USnapSystemSettings.h" },
		{ "ToolTip", "Enables or disables SnapSystem Plugin. Same as the viewport button.\n\nYou can configure the keyboard shortcut for this and other commands\nunder \"Editor Preferences -> Keyboard Shortcuts -> SnapSystem Plugin\"" },
	};
#endif
	void Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIsEnabled_SetBit(void* Obj)
	{
		((UUSnapSystemSettings*)Obj)->bIsEnabled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIsEnabled = { "bIsEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UUSnapSystemSettings), &Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIsEnabled_SetBit, METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIsEnabled_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIsEnabled_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUSnapSystemSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_TargetComponentClasses,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_TargetComponentClasses_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SourceComponentClasses,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SourceComponentClasses_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSplineSocketScale,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_NoSnapbackTolerance,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bNoSnapback,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapPivot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToSocket,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bAttachToParent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketParams,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultScaleSnap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_DefaultRotSnap,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bUseNoSnapTag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_OpenCheckRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapOpenOnly,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bSnapAttachedToo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIgnoreSocketName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_MaxAngle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_SearchDist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_ShowSocketMode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bShowSockets,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUSnapSystemSettings_Statics::NewProp_bIsEnabled,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUSnapSystemSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUSnapSystemSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUSnapSystemSettings_Statics::ClassParams = {
		&UUSnapSystemSettings::StaticClass,
		"EditorPerProjectUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UUSnapSystemSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::PropPointers),
		0,
		0x001000A4u,
		0x00000000u,
		METADATA_PARAMS(Z_Construct_UClass_UUSnapSystemSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUSnapSystemSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUSnapSystemSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUSnapSystemSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUSnapSystemSettings, 3864139215);
	template<> SNAPSYSTEM_API UClass* StaticClass<UUSnapSystemSettings>()
	{
		return UUSnapSystemSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUSnapSystemSettings(Z_Construct_UClass_UUSnapSystemSettings, &UUSnapSystemSettings::StaticClass, TEXT("/Script/SnapSystem"), TEXT("UUSnapSystemSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUSnapSystemSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
