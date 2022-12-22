// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Library/Inventory/EXWInventoryEnum.h"
#include "Library/EXWDataStruct.h"
#include "EXWInventoryStruct.generated.h"

class UStaticMesh;
class UTexture2D;
class UParticleSystem;
class UNiagaraSystem;


USTRUCT(BlueprintType)
struct FEXWRacialSkeletalMeshes
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EEXWRace Race = EEXWRace::R_Human;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EEXWGender, USkeletalMesh*> SkeletalMeshes;
};

USTRUCT(BlueprintType)
struct FEXWItemData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = General)
	FName ID = "None";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = General)
	FText ItemName = FText::FromString("Item_Name");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot)
	UTexture2D* Icon = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
	float Cooldown = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot)
	FText Description = FText::FromString("Item_Description");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = General)
	EEXWItemType ItemType = EEXWItemType::IT_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = General)
	EEXWItemRarety ItemRarity = EEXWItemRarety::IR_Common;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = World)
	UStaticMesh* WorldMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = World)
	FVector WorldCollisionSize = FVector(15.f, 15.f, 15.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = World)
	UParticleSystem* ParticleSystem = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = World)
	UNiagaraSystem* NiagaraSystem = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = World)
	bool bUseBillboard = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = World, meta = (EditCondition = "bUseBillboard"))
	FVector BillboardSize = FVector(.1f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = World, meta = (EditCondition = "bUseBillboard"))
	UTexture2D* WorldIconReplacement = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot)
	int32 MaxStackSize = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot)
	EEXWSlotType SlotType = EEXWSlotType::ST_Any;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot, meta = (EditCondition = "SlotType == EEXWSlotType::ST_Equipment_RightHand || SlotType == EEXWSlotType::ST_Equipment_LeftHand"))
	uint8 bDualWielding : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot)
	int32 PriceSilver = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Slot)
	int32 PriceGold = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemSet)
	FName ItemSetID;

	/** How long it takes for item to become loot-able by everyone */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timers)
	float LootTime = 60.f;

	/** How long it takes for item to be destroyed and disappear */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Timers)
	float DestroyTime = 180.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects, meta = (EditCondition = "ItemType == EEXWItemType::IT_Ability"))
	FName AbilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects, meta = (EditCondition = "ItemType == EEXWItemType::IT_Consumable || ItemType == EEXWItemType::IT_Equip || ItemType == EEXWItemType::IT_Cosmetic"))
	TArray<FName> StatusEffectsOnUse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects, meta = (EditCondition = "ItemType == EEXWItemType::IT_Placeable"))
	TSubclassOf<class AEXWPlaceable> PlaceableClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects, meta = (EditCondition = "ItemType == EEXWItemType::IT_Equip || ItemType == EEXWItemType::IT_Cosmetic"))
	TMap<EEXWStatType, float> StatEffectsOnEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Effects, meta = (EditCondition = "ItemType == EEXWItemType::IT_Equip || ItemType == EEXWItemType::IT_Cosmetic"))
	TMap<EEXWAttributeType, float> AttributeEffectsOnEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment, meta = (EditCondition = "ItemType == EEXWItemType::IT_Equip || ItemType == EEXWItemType::IT_Cosmetic"))
	EEXWEquipmentType EquipmentType = EEXWEquipmentType::ET_Torso;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment, meta = (EditCondition = "ItemType == EEXWItemType::IT_Equip || ItemType == EEXWItemType::IT_Cosmetic"))
	bool MultiRace = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment, meta = (EditCondition = "ItemType == EEXWItemType::IT_Equip || ItemType == EEXWItemType::IT_Cosmetic && MultiRace == false"))
	TMap<EEXWGender, USkeletalMesh*> SkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Equipment, meta = (EditCondition = "ItemType == EEXWItemType::IT_Cosmetic && MultiRace == true"))
	TArray<FEXWRacialSkeletalMeshes> RacialSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Requirements, meta = (EditCondition = "ItemType == EEXWItemType::IT_Consumable || ItemType == EEXWItemType::IT_Equip || ItemType == EEXWItemType::IT_Cosmetic"))
	int32 RequiredLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Requirements, meta = (EditCondition = "ItemType == EEXWItemType::IT_Equip || ItemType == EEXWItemType::IT_Cosmetic"))
	TArray<EEXWClass> RequiredClasses = {};

	FORCEINLINE bool operator==(const FEXWItemData& Other) const
	{
		return ID == Other.ID;
	};
};

USTRUCT(BlueprintType)
struct FEXWItemSetEventEffect {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VFX")
	FName BoneName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VFX")
	UParticleSystem* Effect;
};

USTRUCT(BlueprintType)
struct FEXWItemSet : public FTableRowBase {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FName> SetItems;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat Effects")
	TMap<EEXWStatType, float> StatEffectsOnFullAssembly;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "VFX")
	TMap<EEXWItemSetEvent, FEXWItemSetEventEffect> EventEffects;

	FORCEINLINE bool operator==(const FEXWItemSet& rhs) const {
		return rhs.ID == this->ID;
	}
};


USTRUCT(BlueprintType)
struct FEXWInventorySlot
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<EEXWSlotType> AcceptableSlotTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PriceSilver = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 PriceGold = 0;

	FEXWInventorySlot()
	{
		// Default Constructor
		ItemID = "None";
		Count = 0;
		AcceptableSlotTypes = { EEXWSlotType::ST_Any };
	}

	FEXWInventorySlot(const FName& NewItemID, const int32& NewCount)
	{
		ItemID = NewItemID;
		Count = NewCount;
		AcceptableSlotTypes = { EEXWSlotType::ST_Any };
	}

	FEXWInventorySlot(const FName& NewItemID, const int32& NewCount, const TArray<EEXWSlotType> NewAcceptableSlotTypes)
	{
		ItemID = NewItemID;
		Count = NewCount;
		AcceptableSlotTypes = NewAcceptableSlotTypes;
	}
	FORCEINLINE bool operator==(const FEXWInventorySlot& rhs) const
	{
		return rhs.ItemID == this->ItemID;
	}
	/*friend uint32 GetTypeHash(const FEXWInventorySlot& other)
	{
		return GetTypeHash(other.ItemID.ToString() + FString::FromInt(other.Count));
	}*/
};

USTRUCT(BlueprintType)
struct FEXWInventory
{
	GENERATED_BODY()

public:

	// Item Slots containing item(s) which depends on the stack
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEXWInventorySlot> ItemSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CoinsSilver = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CoinsGold = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Shards = 0;

	FEXWInventory()
	{
		// Initialize the Slot size to 20
		for (uint8 i = 0; i < 20 ; i++)
		{
			ItemSlots.Add(FEXWInventorySlot());
		}
	}

	FEXWInventory(const uint16 Size)
	{
		// Initialize the Slot size to 20
		for (uint16 i = 0; i < Size; i++)
		{
			ItemSlots.Add(FEXWInventorySlot());
		}
	}

	FName GetItemID(const int32 SlotIndex)
	{
		return ItemSlots[SlotIndex].ItemID;
	}
	
	/**
	 * Returns the Count of the item in the slot passed in argument.
	 */
	int32 GetItemCount(const int32 SlotIndex)
	{
		return ItemSlots[SlotIndex].Count;
	}

	int32 GetTotalItemCount(const FName ItemID)
	{
		int32 Result = 0;
		for (FEXWInventorySlot InventorySlot : ItemSlots)
		{
			if (InventorySlot.ItemID == ItemID)
			{
				Result += InventorySlot.Count;
			}
		}
		return Result;
	}

	bool IsSlotEmpty(const int32 SlotIndex)
	{
		return GetItemID(SlotIndex) == "None";
	}
};

/*USTRUCT(Blueprintable, BlueprintType)
struct FEXWCooldown
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		FName ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		float Duration;

	UPROPERTY(BlueprintReadWrite)
		FTimerHandle TimerHandle;

	FORCEINLINE bool operator==(const FEXWCooldown& rhs) const
	{
		return (rhs.ID == this->ID);
	}

	FEXWCooldown()
	{
		ID = "None";
		Duration = 2.f;
	}
	FEXWCooldown(FName InID)
	{
		this->ID = InID;
	}
	FEXWCooldown(const FName InID, const float InDuration)
	{
		ID = InID;
		Duration = InDuration;
		FEXWCooldown();
	}
};*/

USTRUCT(BlueprintType)
struct FEXWItemDropRate
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID = "None";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CountVariation = 1;

	/** Drop rate of the item between 1 and 0 where 1 represents 100% and 0 represents 0% chance of getting the item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMax = 1.f, ClampMin = 0.f));
	float DropRate = 1.f;

	FEXWItemDropRate()
	{
		// Default
	}

	FEXWItemDropRate(const FName NewItemID, const int32 NewCount, const int32 NewCountVariation, const float NewDropRate)
	{
		ItemID = NewItemID;
		Count = NewCount;
		CountVariation = NewCountVariation;
		DropRate = NewDropRate;
	}
};


USTRUCT(BlueprintType)
struct FEXWGatheringRate : public FEXWItemDropRate
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ToolFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LevelFactor;

	FEXWGatheringRate() : Super()
	{
		ToolFactor = 0.f;
		LevelFactor = 0.f;
	}

	FEXWGatheringRate(const FName NewItemID, const int32 NewCount, const int32 NewCountVariation, const float NewDropRate, 
		const float NewToolFactor, const float NewLevelFactor) : Super(NewItemID, NewCount, NewCountVariation, NewDropRate)
	{
		ToolFactor = NewToolFactor;
		LevelFactor = NewLevelFactor;
	}
};

USTRUCT(BlueprintType)
struct FEXWCraftingOption : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RequiredPlayerLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEXWCraftCategory CraftCategory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RequiredLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bRequiresCraftingStation = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, int32> ItemsToUse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, int32> ItemsToCreate;
};