// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Library/EXWDataStruct.h"
#include "Library/Inventory/EXWInventoryStruct.h"
#include "EXWCloudStruct.generated.h"



//deployment/ spatialOS
USTRUCT(BlueprintType)
struct FEXWDeploymentInfo {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
		FString DeploymentId;
	UPROPERTY(BlueprintReadOnly)
		FString DeploymentName;
	UPROPERTY(BlueprintReadOnly)
		FString Region;
	UPROPERTY(BlueprintReadOnly)
		FString Cluster;
	UPROPERTY(BlueprintReadOnly)
		FString LoginToken;
	UPROPERTY(BlueprintReadOnly)
		int32 PlayerCount = 0;
	UPROPERTY(BlueprintReadOnly)
		int32 MaxPlayerCount = 0;
	UPROPERTY(BlueprintReadOnly)
		bool bAvailable = false;
};

USTRUCT(BlueprintType)
struct FEXWDeploymentsList {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
		TArray<FEXWDeploymentInfo> DeploymentList;
};

USTRUCT(BlueprintType)
struct FEXWSpatialTokens {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
		FString PIT;
	UPROPERTY(BlueprintReadOnly)
		FString LT;
};


USTRUCT(BlueprintType)
struct FEXWCharacterAppearance_Info_N
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Gender;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Face;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Eyes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString EyeColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString BodyType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString SkinColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Hair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString HairColor;

};

USTRUCT(BlueprintType)
struct FEXWAction_Cloud
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ExWorldPlayer Info|Actions")
	FName ActionID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ExWorldPlayer Info|Actions")
	int32 Level;
};

//character saved Data

USTRUCT(BlueprintType)
struct FEXWCharacterPosition_Info_N
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Transform")
		FString Location;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Transform")
		FString Rotation;

};

USTRUCT(BlueprintType)
struct FEXWCharacterInfo_S
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString CharacterID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Race;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		int32 ProgressionLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		int32 ProgressionExperience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FEXWCharacterAppearance_Info_N Appearance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FEXWCharacterPosition_Info_N Transform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FEXWCharacterStat_Info Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FEXWInventory Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FEXWInventory Equipment;
};


USTRUCT(BlueprintType)
struct FEXWInventorySlotItem_S
{
	GENERATED_USTRUCT_BODY();

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ExWorldPlayer Info|Inventory")
	int32 SlotID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ExWorldPlayer Info|Inventory")
	FString RowName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ExWorldPlayer Info|Inventory")
	int32 Count;
};

USTRUCT(BlueprintType)
struct FEXWInventory_S
{
	GENERATED_BODY()

public:

	// Item Slots containing item(s) which depends on the stack
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEXWInventorySlotItem_S> ItemSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CoinsSilver = 420;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CoinsGold = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Shards = 0;
};

USTRUCT(BlueprintType)
struct FEXWEquipment_S
{
	GENERATED_BODY()

public:

	// Item Slots containing item(s) which depends on the stack
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEXWInventorySlotItem_S> ItemSlots;
};

USTRUCT(BlueprintType)
struct FEXWActiveAbilitySlot_Info_S
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 SlotID = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ActionID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Level = 0;
};

USTRUCT(BlueprintType)
struct FEXWCharacterAbility_Info_S
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 UnspentPoints = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FEXWActiveAbilitySlot_Info_S> AbilitySlots;
};

USTRUCT(BlueprintType)
struct FEXWCharacterInfoSaveData_S
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FString CharacterID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	int32 ProgressionLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	int32 ProgressionExperience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWCharacterAppearance_Info_N Appearance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWCharacterPosition_Info_N Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWCharacterStat_Info Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWInventory_S Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWEquipment_S Equipment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWEquipment_S Cosmetic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWCharacterAbility_Info_S ActiveAbilities;

};

USTRUCT(BlueprintType)
struct FEXWCharacterInfoLoadData_S
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FString CharacterID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FString Race;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FString Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	int32 ProgressionLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	int32 ProgressionExperience;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWCharacterAppearance_Info_N Appearance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWCharacterPosition_Info_N Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWCharacterStat_Info Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWInventory_S Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWInventory_S Equipment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWInventory_S Cosmetic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
	FEXWCharacterAbility_Info_S ActiveAbilities;
};


/**
 * 
 */