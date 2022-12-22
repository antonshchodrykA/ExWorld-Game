// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#pragma once

#include "CoreMinimal.h"
#include "EXWDataEnum.generated.h"

UENUM(BlueprintType)
enum class EEXWAttributeType : uint8
{
	Health = 0,
	Mana = 1,
	Stamina = 2,
	Rage = 3,
	Damage = 4,
	MagicDamage = 5,
	Defense = 6,
	MagicDefense = 7,
	AttackSpeed = 8,
	Aim = 9,
	Evasion = 10,
	CriticalHitRate = 11,
	CriticalDamage = 12,
	CriticalNullifier = 13,
	CriticalDamageNullifier = 14,
	ArmorPenetration = 15,
	MagicArmorPenetration = 16,
	MovementSpeed = 17,
	CastSpeed = 18
};

UENUM(BlueprintType)
enum class EEXWStatType : uint8
{
	Strength = 0,
	Agility = 1,
	Endurance = 2,
	Intelligence = 3,
	Luck = 4,
	Stamina=5
};

UENUM(BlueprintType)
enum class EEXWRace : uint8
{
	R_Human UMETA (DisplayName = "Human"),
	R_Vampire UMETA(DisplayName = "Vampire"),
	R_Werewolf UMETA(DisplayName = "Werewolf"),
	R_DeathGod UMETA(DisplayName = "DeathGod"),
	R_Other UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)
enum class EEXWClass : uint8
{
	C_Knight UMETA(DisplayName = "Knight"),
	C_Fighter UMETA(DisplayName = "Fighter"),
	C_Archer UMETA(DisplayName = "Archer"),
	C_DarkArts UMETA(DisplayName = "Dark Arts"),
	C_Priest UMETA(DisplayName = "Priest"),
	C_BloodVampire UMETA(DisplayName = "Blood Vampire"),
	C_UndeadVampire UMETA(DisplayName = "Undead Vampire"),
	C_NightVampire UMETA(DisplayName = "Night Vampire"),
	C_DreadKnight UMETA(DisplayName = "Dread Knight"),
	C_Lycan UMETA(DisplayName = "Lycan"),
	C_Beta UMETA(DisplayName = "Beta"),
	C_Other UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)
enum class EEXWGender : uint8
{
	G_Male UMETA(DisplayName = "Male"),
	G_Female UMETA(DisplayName = "Female"),
	G_Other UMETA(DisplayName = "Other") // Welcome to 2021 I guess
};

UENUM(BlueprintType)
enum class EEXWMeshType : uint8
{
	MT_HeadType UMETA(DisplayName = "Head"),
	MT_HairType UMETA(DisplayName = "Hair"),
	MT_HairColor UMETA(DisplayName = "HairColor"),
	MT_ArmsType UMETA(DisplayName = "Arms"),
	MT_BodyType UMETA(DisplayName = "Body"),
	MT_TorsoType UMETA(DisplayName = "Torso"),
	MT_EyesType UMETA(DisplayName = "Eyes"),
	MT_EyeColor UMETA(DisplayName = "EyeColor"),
	MT_FaceType UMETA(DisplayName = "Face"),
	MT_FeetType UMETA(DisplayName = "Feet"),
	MT_LegsType UMETA(DisplayName = "Legs"),
	MT_SkinType UMETA(DisplayName = "Skin")
};

UENUM(BlueprintType)
enum class EEXWEffectType : uint8
{
	Gain,
	Loss
};

UENUM(BlueprintType)
enum class EEXWAttributeEffectType : uint8
{
	AET_Heal = 0 UMETA(DisplayName = "Heal"),
	AET_PhysicalDamage = 2 UMETA(DisplayName = "Physical Damage"),
	AET_MagicalDamage = 4 UMETA(DisplayName = "Magical Damage")
};

UENUM(BlueprintType)
enum class EEXWValueComparaisonType : uint8
{
	VC_IsLess UMETA(DisplayName = "IsLess"),
	VC_IsMore UMETA(DisplayName = "IsMore"),
	VC_IsEqual UMETA(DisplayName = "IsEqual")
};

UENUM(BlueprintType)
enum class EEXWValueType : uint8
{
	Static,
	DynamicOnSource,
	DynamicOnTarget
};

UENUM(BlueprintType)
enum class EEXWStatusEffectType : uint8
{
	Buff,
	Debuff
};

UENUM(BlueprintType)
enum class EEXWSpawnableAbilityType : uint8
{
	InstantAtTarget UMETA(Tooltip = "Spawns the ability at the target's location."),
	InstantAtSelf UMETA(Tooltip = "Spawns the ability at owner's location."),
	InstantAtCrosshair UMETA(Tooltip = "Spawns the ability at the crosshair location."),
	Projectile UMETA(Tooltip = "Spawns the ability as a projectile that follows the crosshair's direction.")
};

UENUM(BlueprintType)
enum class EEXWActionDirection : uint8
{
	AD_Any UMETA(DisplayName = "Any"),
	AD_Forward UMETA(DisplayName = "Forward"),
	AD_Backward UMETA(DisplayName = "Backward"),
	AD_Right UMETA(DisplayName = "Right"),
	AD_Left UMETA(DisplayName = "Left"),
};

UENUM(BlueprintType)
enum class EEXWRelativePosition : uint8
{
	RP_Front UMETA(DisplayName = "Front"),
	RP_Back UMETA(DisplayName = "Back"),
	RP_Right UMETA(DisplayName = "Right"),
	RP_Left UMETA(DisplayName = "Left"),
};

UENUM(BlueprintType)
enum class EEXWDirectionMode : uint8
{
	CameraRotation,
	CharacterRotation
};

UENUM(BlueprintType)
enum class EEXWState : uint8
{
	S_InAction = 0 UMETA(DisplayName = "In Action"),
	S_Blocking = 1 UMETA(DisplayName = "Blocking"),
	S_Stunned = 2 UMETA(DisplayName = "Stunned"),
	S_Feared = 3 UMETA(DisplayName = "Feared"),
	S_Silenced = 4 UMETA(DisplayName = "Silenced"),
	S_Rooted = 5 UMETA(DisplayName = "Rooted"),
	S_KnockedDown = 6 UMETA(DisplayName = "Knocked Down"),
	S_KnockedBack = 7 UMETA(DisplayName = "Knocked Back"),
	S_Dead = 8 UMETA(DisplayName = "Dead"),
	S_Disarmed = 9 UMETA(DisplayName = "Disarmed"),
	S_Vending = 10 UMETA(DisplayName = "Vending"),
	S_Invulnerable = 11 UMETA(DisplayName = "Invulnerable"),
	S_Gathering = 12 UMETA(DisplayName = "Gathering"),
};

UENUM(BlueprintType)
enum class EEXWStateOverrider : uint8
{
	SO_SuperArmor = 0 UMETA(DisplayName = "Super Armor"),
	SO_Invincible = 1 UMETA(DisplayName = "Invincible")
};

UENUM(BlueprintType)
enum class EEXWActionExecutionResult : uint8
{
	AER_Success UMETA(DisplayName = "Success"),
	AER_InvalidState UMETA(DisplayName = "Invalid State"),
	AER_IsTargeting UMETA(DisplayName = "Is Targeting"),
	AER_OnCooldown UMETA(DisplayName = "On Cooldown"),
	AER_NotEnoughAttribute UMETA(DisplayName = "Not Enough Attribute"),
	AER_NoAnimMontage UMETA(DisplayName = "No Anim Montage"),
	AER_NoValidMontageData UMETA(DisplayName = "No Valid Montage Data"),
	AER_DataTableNotFound UMETA(DisplayName = "Data Table Not Found"),
	AER_NoWeapon UMETA(DisplayName = "No Weapon Equipped"),
	AER_IsSilenced UMETA(DisplayName = "Silenced"),
	AER_Disarmed UMETA(DisplayName = "Disarmed"),
	AER_IsPassive UMETA(DisplayName = "Is Passive Ability"),
	AER_UnknownError UMETA(DisplayName = "Unknown Error")
};

UENUM(BlueprintType)
enum class EEXWItemUseResult : uint8
{
	IUR_Success UMETA(DisplayName = "Success"),
	IUR_OnCooldown UMETA(DisplayName = "On Cooldown"),
	IUR_UnknownError UMETA(DisplayName = "Unknown Error")
};

UENUM(BlueprintType)
enum class EItemQuality : uint8
{
	Poor		UMETA(DisplayName = "Poor"),
    Common		UMETA(DisplayName = "Common"),
    Uncommon	UMETA(DisplayName = "Uncommon"),
    Rare		UMETA(DisplayName = "Rare"),
    Epic		UMETA(DisplayName = "Epic"),
    Legendary	UMETA(DisplayName = "Legendary"),
};


UENUM(BlueprintType)
enum class EItemType : uint8
{
	Miscellaneous		UMETA(DisplayName = "Miscellaneous"),
    Equipment			UMETA(DisplayName = "Equipment"),
    Consumable			UMETA(DisplayName = "Consumable"),
    Currency			UMETA(DisplayName = "Currency")
};

UENUM(BlueprintType)
enum class EEquipmentType : uint8
{
	Armor			UMETA(DisplayName = "Armor"),
    Weapon			UMETA(DisplayName = "Weapon"),
    Miscellaneous	UMETA(DisplayName = "Miscellaneous")
};

UENUM(BlueprintType)
enum class EEXWValidityBranch : uint8
{
	VB_Valid UMETA(DisplayName = "Valid"),
	VB_NotValid UMETA(DisplayName = "Not Valid")
};

UENUM(BlueprintType)
enum class EEXWTargetingType : uint8
{
	TT_AimWithPitch = 0 UMETA(DisplayName = "Forward With Pitch"),
	TT_AimWithoutPitch = 1 UMETA(DisplayName = "Forward Without Pitch"),
	TT_Crosshair = 2 UMETA(DisplayName = "Crosshair")
};

UENUM(BlueprintType)
enum class EEXWTargetFaction : uint8
{
	TF_OtherFactionOnly = 0 UMETA(DisplayName = "Other Faction Only"),
	TF_OwnerFactionOnly = 1 UMETA(DisplayName = "Owner Faction Only"),
	TF_ALLFactions = 2 UMETA(DisplayName = "All Factions")
};

UENUM(BlueprintType)
enum class EEXWInteractionType : uint8
{
	IT_Shop = 0 UMETA(DisplayName = "Shop"),
	IT_TradeRequest = 1 UMETA(DisplayName = "Trade"),
	IT_DuelRequest = 2 UMETA(DisplayName = "Duel"),
	IT_PickItem = 3 UMETA(DisplayName = "Pick Item"),
	IT_Use = 4 UMETA(DisplayName =  "Use"),
	IT_Gather = 5 UMETA(DisplayName = "Gather"),
	IT_InviteToParty = 6 UMETA(DisplayName = "Invite To Party"),
	IT_Talk = 7 UMETA(DisplayName = "Talk"),
	IT_AskForQuest = 8 UMETA(DisplayName = "Ask for Quest"),
	IT_Craft = 9 UMETA(DisplayName = "Craft Station"),
	//IT_Shop = 9 UMETA(DisplayName = "Shop"),
};

UENUM(BlueprintType)
enum class EEXWLifeSkillType : uint8
{
	LS_Mining = 0 UMETA(DisplayName = "Mining"),
	LS_Cooking = 1 UMETA(DisplayName = "Cooking"),
	LS_FireMaking = 2 UMETA(DisplayName = "Fire Making"),
	LS_WoodCutting = 3 UMETA(DisplayName = "Wood Cutting"),
	LS_Gathering = 4 UMETA(DisplayName = "Gathering"),
	LS_Fishing = 5 UMETA(DisplayName = "Fishing"),
	LS_Alchemy = 6 UMETA(DisplayName = "Alchemy"),
	LS_Smiting = 7 UMETA(DisplayName = "Smiting"),
	LS_Crafting = 8 UMETA(DisplayName = "Crafting"),
	LS_Tailoring = 9 UMETA(DisplayName = "Tailoring"),
	LS_Farming = 10 UMETA(DisplayName = "Farming"),
	LS_Breeding = 11 UMETA(DisplayName = "Breeding"),
	LS_BountyHunting = 12 UMETA(DisplayName = "Bounty Hunting")
};

UENUM(BlueprintType)
enum class EEXWScreenMessageType : uint8
{
	SM_EquipmentClassError = 0 UMETA(DisplayName = "Equipment Class Error"),
	SM_EquipmentLevelError = 1 UMETA(DisplayName = "Equipment Level Error"),
	SM_InventorySpaceError = 2 UMETA(DisplayName = "Inventory Space Error"),
	SM_GatheringNoToolError = 3 UMETA(DisplayName = "Gathering No Tool Error"),
	SM_InteractionRangeError = 4 UMETA(DisplayName = "Interaction Range Error"),
	SM_ResourceBeingGatheredError = 5 UMETA(DisplayName = "Resource Being Gathered Error"),
	SM_NoResourceToGatherError = 6 UMETA(DisplayName = "No Resource To Gather"),
	SM_GatheringPlayerLevelRequirementUnmet = 7 UMETA(DisplayName = "Player Level not enough"),
	SM_GatheringLifeSkillLevelRequirementUnmet = 8 UMETA(DisplayName = "Player Life Skill Level not enough")
};

UENUM(BlueprintType)
enum class EEXWUIButtonVisibilityType : uint8
{
	Visible, 
	Hidden,
	Disabled 
};

/**
 * Party
 */

UENUM(BlueprintType)
enum class EEXWPartyMemberRoles : uint8
{
	PMR_Admin = 0 UMETA(DisplayName = "Party Admin"),
	PMR_Member = 1 UMETA(DisplayName = "Party Member")
};

/**
 * Abilities
 */
 UENUM(BlueprintType)
enum class EEXWActionAttribute : uint8 
{
	AA_Cooldown = 0 UMETA(DisplayName = "Cooldown"),
	AA_AttributeValue = 1 UMETA(DisplayName = "Cost"),
	AA_LevelModifier = 2 UMETA(DisplayName = "Level Modifier"),
	AA_Damage = 3 UMETA(DisplayName = "Damage"),

};

/**
 * Quest System
 */

UENUM(BlueprintType)
enum class EEXWQuestCategory : uint8
 {
	 QC_Main = 0 UMETA(DisplayName = "Main Quest"),
	 QC_Side = 1 UMETA(DisplayName = "Side Quest"),
	 QC_Event = 2 UMETA(DisplayName = "Event"),
 };

 UENUM(BlueprintType)
	 enum class EEXWQuestObjectiveType : uint8
 {
	 QOT_Custom = 0 UMETA(DisplayName = "Custom Objective"),
	 QOT_Hunt = 1 UMETA(DisplayName = "Hunt Objective"),
	 QOT_Find = 2 UMETA(DisplayName = "Find Objective"),
	 QOT_Talk = 3 UMETA(DisplayName = "Talk Objective"),
	 QOT_Gather = 4 UMETA(DisplayName = "Gather Objective"),
	 QOT_Escort = 5 UMETA(DisplayName = "Escort Objective"),
	 QOT_Summon = 6 UMETA(DisplayName = "Summon Objective"),
 };

 UENUM(BlueprintType)
	 enum class EEXWQuestState : uint8
 {
	 QS_Pending = 0 UMETA(DisplayName = "Pending Quest"),
	 QS_Complete = 1 UMETA(DisplayName = "Completed Quest"),
 };
 UENUM(BlueprintType)
 enum class EEXWQuestRewardType : uint8
 {
	 QRT_Experience = 0 UMETA(DisplayName = "Experience"),
	 QRT_Silver = 1 UMETA(DisplayName = "Silver"),
	 QRT_Gold = 2 UMETA(DisplayName = "Gold"),
	 QRT_Item = 3 UMETA(DisplayName = "Item"),
 };


 /**
  * AI 
  */
UENUM(BlueprintType)
enum class EEXWAITier : uint8 {
	AIT_One = 0 UMETA(DisplayName = "Tier 1"),
	AIT_Two = 1 UMETA(DisplayName = "Tier 2"),
	AIT_Three = 2 UMETA(DisplayName = "Tier 3"),
	AIT_Elite = 3 UMETA(DisplayName = "Tier Elite")
};