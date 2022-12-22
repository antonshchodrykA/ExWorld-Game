// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EXWInventoryEnum.generated.h"

UENUM(BlueprintType)
enum class EEXWItemType : uint8
{
	IT_None = 0 UMETA(DisplayName = "None"),
	IT_Material = 1 UMETA(DisplayName = "Material"),
	IT_Consumable = 2 UMETA(DisplayName = "Consumable"),
	IT_Placeable = 3 UMETA(DisplayName = "Placeable"),
	IT_Scroll = 4 UMETA(DisplayName = "Scroll"),
	IT_Mount = 5 UMETA(DisplayName = "Mount"),
	IT_Equip = 6 UMETA(DisplayName = "Equip"),
	IT_Cosmetic = 7 UMETA(DisplayName = "Cosmetic"),
	IT_Ability = 8 UMETA(DisplayName = "Ability"),
};

UENUM(BlueprintType)
enum class EEXWItemRarety : uint8
{
	IR_Common = 0 UMETA(DisplayName = "Common"),
	IR_Uncommon = 1 UMETA(DisplayName = "Uncommon"),
	IR_Rare = 2 UMETA(DisplayName = "Rare"),
	IR_Epic = 3 UMETA(DisplayName = "Epic"),
	IR_Legendary = 4 UMETA(DisplayName = "Legendary")
};

UENUM(BlueprintType)
enum class EEXWBuyResult : uint8
{
	BR_UnvalidItem = 0 UMETA(DisplayName = "Unvalid Item"),
	BR_SellerHasNoItem = 1 UMETA(DisplayName = "Seller Has No Item"),
	BR_NotEnoughCoins = 2 UMETA(DisplayName = "Not Enough Coins"),
	BR_NotEnoughSpace = 3 UMETA(DisplayName = "Not Enough Space"),
	BR_Success = 4 UMETA(DisplayName = "Success")
};

UENUM(BlueprintType)
enum class EEXWCraftCategory : uint8
{
	CC_Mining = 0 UMETA(DisplayName = "Mining"),
	CC_Cooking = 1 UMETA(DisplayName = "Cooking"),
	CC_WoodCutting = 2 UMETA(DisplayName = "WoodCutting"),
	CC_Camping = 3 UMETA(DisplayName = "Camping"),
	CC_Gathering = 4 UMETA(DisplayName = "Gathering"),
	CC_Fishing = 5 UMETA(DisplayName = "Fishing"),
	CC_Alchemy = 6 UMETA(DisplayName = "Alchemy"),
	CC_Smiting = 7 UMETA(DisplayName = "Smiting")
};

UENUM(BlueprintType)
enum class EEXWEquipmentType : uint8
{
	ET_Head = 0 UMETA(DisplayName = "Head"),
	ET_Torso = 1 UMETA(DisplayName = "Torso"),
	ET_Arms = 2 UMETA(DisplayName = "Arms"),
	ET_Legs = 3 UMETA(DisplayName = "Legs"),
	ET_Feet = 4 UMETA(DisplayName = "Feet"),
	ET_Ring = 5 UMETA(DisplayName = "Ring"),
	ET_Necklace = 6 UMETA(DisplayName = "Necklace"),
	ET_Earring = 7 UMETA(DisplayName = "Earring"),
	ET_Axe = 8 UMETA(DisplayName = "Axe"),
	ET_Crystal = 9 UMETA(DisplayName = "Crystal"),
	ET_BloodBag = 10 UMETA(DisplayName = "Blood Bag"),
	ET_ShortSword = 11 UMETA(DisplayName = "Short Sword"),
	ET_OneHandedSword = 12 UMETA(DisplayName = "One Handed Sword"),
	ET_OneHandedShield = 13 UMETA(DisplayName = "One Handed Shield"),
	ET_OneHandedHammer = 14 UMETA(DisplayName = "OneHandedHammer"),
	ET_Claws = 15 UMETA(DisplayName = "Claws"),
	ET_GreatSword = 16 UMETA(DisplayName = "Great Sword"),
	ET_Scepter = 17 UMETA(DisplayName = "Scepter"),
	ET_Dagger = 18 UMETA(DisplayName = "Dagger"),
	ET_ShortAxe = 19 UMETA(DisplayName = "Short Axe"),
	ET_FishingRod = 20 UMETA(DisplayName = "Fishing Rod"),
	ET_Pickaxe = 21 UMETA(DisplayName = "Pickaxe")
};

UENUM(BlueprintType)
enum class EEXWSlotType : uint8
{
	ST_Any = 0 UMETA(DisplayName = "Any"),
	ST_Ability = 1 UMETA(DisplayName = "Ability"),
	ST_Equipment_Head = 2 UMETA(DisplayName = "Equipment Head"),
	ST_Equipment_Arms = 3 UMETA(DisplayName = "Equipment Arms"),
	ST_Equipment_Torso = 4 UMETA(DisplayName = "Equipment Torso"),
	ST_Equipment_Legs = 5 UMETA(DisplayName = "Equipment Legs"),
	ST_Equipment_Feet = 6 UMETA(DisplayName = "Equipment Feet"),
	ST_Equipment_Ring = 8 UMETA(DisplayName = "Equipment Ring"),
	ST_Equipment_Belt = 9 UMETA(DisplayName = "Equipment Belt"),
	ST_Equipment_Necklace = 10 UMETA(DisplayName = "Equipment Necklace"),
	ST_Equipment_Earring = 11 UMETA(DisplayName = "Equipment Earring"),
	ST_Equipment_RightHand = 12 UMETA(DisplayName = "Equipment Right Hand"),
	ST_Equipment_LeftHand = 13 UMETA(DisplayName = "Equipment Left Hand"),
	ST_Cosmetic_Head = 14 UMETA(DisplayName = "Cosmetic Head"),
	ST_Cosmetic_Arms = 15 UMETA(DisplayName = "Cosmetic Arms"),
	ST_Cosmetic_Torso = 16 UMETA(DisplayName = "Cosmetic Torso"),
	ST_Cosmetic_Legs = 17 UMETA(DisplayName = "Cosmetic Legs"),
	ST_Cosmetic_Feet = 18 UMETA(DisplayName = "Cosmetic Feet"),
	ST_Cosmetic_Ring = 19 UMETA(DisplayName = "Cosmetic Ring"),
	ST_Cosmetic_Belt = 20 UMETA(DisplayName = "Cosmetic Belt"),
	ST_Cosmetic_Necklace = 21 UMETA(DisplayName = "Cosmetic Necklace"),
	ST_Cosmetic_Earring = 22 UMETA(DisplayName = "Cosmetic Earring"),
	ST_Cosmetic_RightHand = 23 UMETA(DisplayName = "Cosmetic Right Hand"),
	ST_Cosmetic_LeftHand = 24 UMETA(DisplayName = "Cosmetic Left Hand"),
	ST_Cosmetic_Cape = 25 UMETA(DisplayName = "Cosmetic Cape")

};

UENUM(BlueprintType)
enum class EEXWItemSetEvent : uint8 {
	ISE_OnEquip = 0 UMETA(DisplayName = "On Equip"),
	ISE_OnUnEquip = 1 UMETA(DisplayName = "On UnEquip"),
	ISE_OnDeath = 2 UMETA(DisplayName = "On Death"),
	ISE_OnKill = 3 UMETA(DisplayName = "On Kill"),
	ISE_OnGatherComplete = 4 UMETA(DisplayName = "On Gathering Complete"),
	ISE_OnCraftComplete = 5 UMETA(DisplayName = "On Crafting Complete"),
	ISE_OnLogin = 6 UMETA(DisplayName = "On Login"),
	ISE_OnRespawn = 7 UMETA(DisplayName = "On Respawn")
};