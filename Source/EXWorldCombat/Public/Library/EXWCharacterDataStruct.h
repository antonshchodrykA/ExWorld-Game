// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include <EXWorldCombat/Public/Library/EXWDataEnum.h>
#include "EXWCharacterDataStruct.generated.h"


USTRUCT(BlueprintType)
struct FEXWMorphData 
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FText MorphTarget;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		float Value;
};

USTRUCT(BlueprintType)
struct FEXWHairType : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* DisplayIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USkeletalMesh* SkeletalMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector HumanOffset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector VampireOffset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FVector WerewolfOffset;
};

USTRUCT(BlueprintType)
struct FEXWHairColor : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FLinearColor Color;
};

USTRUCT(BlueprintType)
struct FEXWEyesType : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* DisplayIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USkeletalMesh* EyesMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USkeletalMesh* EyeBrowsMesh;
};

USTRUCT(BlueprintType)
struct FEXWEyeColor : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FLinearColor Color;
};

USTRUCT(BlueprintType)
struct FEXWFaceType : public FTableRowBase
{
	GENERATED_BODY()

public:
	//TBD
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* DisplayIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USkeletalMesh* SkeletalMesh;
};

USTRUCT(BlueprintType)
struct FEXWBodyType : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* DisplayIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FEXWMorphData> BodyMorphs;
};

USTRUCT(BlueprintType)
struct FEXWSkinType : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture* Texture;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FLinearColor Color;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FLinearColor HighlightColor = FLinearColor::White;
};

USTRUCT(BlueprintType)
struct FEXWHeadType : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USkeletalMesh* SkeletalMesh;
};

USTRUCT(BlueprintType)
struct FEXWTorsoType : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USkeletalMesh* SkeletalMesh;
};

USTRUCT(BlueprintType)
struct FEXWArmsType : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USkeletalMesh* SkeletalMesh;
};

USTRUCT(BlueprintType)
struct FEXWLegsType : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USkeletalMesh* SkeletalMesh;
};

USTRUCT(BlueprintType)
struct FEXWFeetType : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FText DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		USkeletalMesh* SkeletalMesh;
};


USTRUCT(BlueprintType)
struct FEXWBaseSkeletalMeshes 
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics") //delete later when all new meshes are imported
		UClass* AnimationBlueprintClass;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		USkeletalMesh* RootMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Hair;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName HairColor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Eyes;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName EyeColor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Face;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Body;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Skin;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Head;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Torso;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Arms;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Legs;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName Feet;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		USkeletalMesh* RightHandWeaponMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName RightHandWeapon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FVector RightHandWeaponOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		USkeletalMesh* LeftHandWeaponMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FName LeftHandWeapon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		FTransform LeftHandWeaponOffset;

	//TBD
	/*UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		USkeletalMesh* Teeth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character|Cosmetics")
		USkeletalMesh* Tongue;*/

};


USTRUCT(BlueprintType)
struct FEXWClassVisualData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EEXWClass Class;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FButtonStyle ButtonStyle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EEXWUIButtonVisibilityType ClassButtonVisibility;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EEXWStatType, int32> BaseStatLevelPoints;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FEXWBaseSkeletalMeshes MaleBaseMeshes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FEXWBaseSkeletalMeshes FemaleBaseMeshes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimMontage* MaleDeathAnimation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimMontage* FemaleDeathAnimation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UAnimMontage* VendingAnimation;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FName> DefaultActions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FName> DefaultIFrameActions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FName> AvailableActions;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bCanUseDefaultTargeting;
};

USTRUCT(BlueprintType)
struct FEXWPortraitCameraOffsets : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector MaleMainPortraitOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector FemaleMainPortraitOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bSeparatePartyPortraitOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bSeparatePartyPortraitOffset == true", EditConditionHides))
		FVector MalePartyPortraitOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bSeparatePartyPortraitOffset == true", EditConditionHides))
		FVector FemalePartyPortraitOffset;
};

USTRUCT(BlueprintType)
struct FEXWClassRaces : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEXWRace Race = EEXWRace::R_Human;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		EEXWUIButtonVisibilityType RaceButtonVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector MaleHeightOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector FemaleHeightOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FEXWClassVisualData> Classlist;
};

