// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"

#include "InventoryDatabase.generated.h"


UENUM(BlueprintType)
enum class EItemsQuality : uint8
{
	Poor,
	Common,
	Uncommon,
	Rare,
	Epic,
	Legendary
};


UENUM(BlueprintType)
enum class EItemTypes : uint8
{
	Miscellaneous,
	Equipment,
	Consumable,
	Currency
};

UENUM(BlueprintType)
enum class EEquipmentTypes : uint8
{
	Armor,
	Weapon,
	Shield,
	Miscellaneous

};

UENUM(BlueprintType)
enum class EEXWorldClasses : uint8
{
	Fighter		UMETA(DisplayName = "Fighter"),
    Knight		UMETA(DisplayName = "Knight"),
    Vampire     UMETA(DisplayName = "Vampire"),
    Priest      UMETA(DisplayName = "Priest"),
    Mage		UMETA(DisplayName = "Mage")
};

UENUM(BlueprintType)
enum class EEquipmentSlotType : uint8
{
	Head,
	Shoulder,
	Chest,
	Hands,
	Legs,
	Feet,
	Back,
	Waist,
	Accessory,
	Earring,
	Ring,
	Trinket,
	MainHand,
	OffHand

};

USTRUCT(BlueprintType)
struct DEMOTEST_API FItemInformation
{
	GENERATED_BODY()

public:

	UPROPERTY()
		FName ID;

	UPROPERTY()
		UTexture2D* Icon;

	UPROPERTY()
		FName Name;

	UPROPERTY()
		int32 Amount;
};


USTRUCT(BlueprintType)
struct DEMOTEST_API FContainerInfo
{
public:

	GENERATED_BODY()

	UPROPERTY()
		FName Name;

	UPROPERTY()
		uint8 SlotsPerRow;

	UPROPERTY()
		bool IsStorageContainer;

	UPROPERTY()
		int32 StorageInventorySize;
};

USTRUCT(BlueprintType)
struct DEMOTEST_API FInventoryItems
{
	GENERATED_BODY()

public:

	UPROPERTY()
		FName ID;

	UPROPERTY()
		UTexture2D* Icon;

	UPROPERTY()
		FName Name;

	UPROPERTY()
		FString Description;

	UPROPERTY()
		int32 Amount;

	UPROPERTY()
	bool IsStackable;

	UPROPERTY()
	int32 MaxStackSize;

	UPROPERTY()
	bool IsDroppable;

	UPROPERTY()
	UStaticMesh* WorldMesh;

	UPROPERTY()
	int32 Health;

	UPROPERTY()
	float Duration;

	//WeaponActor Add only if needed

	UPROPERTY()
	USkeletalMesh* EquipmentMesh;

	UPROPERTY()
	EEquipmentSlotType EquipmentSlot;

	UPROPERTY()
	int32 Damage;

	UPROPERTY()
	int32 Armor;

	UPROPERTY()
	int32 Strength;

	UPROPERTY()
	int32 Dexterity;

	UPROPERTY()
	int32 Intelligence;
};

USTRUCT(BlueprintType)
struct DEMOTEST_API FEmptyInventorySpace
{
	GENERATED_BODY()

public:

	UPROPERTY()
		bool LocalSuccess;

	UPROPERTY()
		int32 LocalIndex;
};

