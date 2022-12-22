// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Library/EXWDataStruct.h"
#include "EXWSingleton.generated.h"

class UDataTable;
class UEXWSharedWidget;
class UEXWFloatingWidget;
class UEXWScreenMessageWidget;

/**
 * 
 */
UCLASS(Blueprintable)
class EXWORLDCOMBAT_API UEXWSingleton : public UObject
{
	GENERATED_BODY()
	
public:

	/** Stat level modifier data table to use on every level up. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Stats")
	UDataTable* StatLevelModifiersDT = nullptr;

	/** Stat level modifier data table to use on every level up. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|StatusEffect")
	UDataTable* StatusEffectsDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|SpawnableAbility")
	UDataTable* SpawnableAbilityDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Action")
	UDataTable* ActionDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Reaction")
	UDataTable* ReactionDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Quest")
	UDataTable* QuestDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Dialogue")
	UDataTable* DialogueDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Dialogue")
	UDataTable* DialogueSpeakerDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Inventory")
	UDataTable* ItemDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Inventory")
	UDataTable* CraftingOptionsDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|NPC Shop")
	UDataTable* NPCShopDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Inventory")
	UDataTable* ItemSetDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Inventory")
	float ItemSpawnDistance = 50.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Inventory")
	float ItemSpawnDistanceVariance = 80.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Highlight")
	FEXWHighlightData HighlightData;

	/**
	 * Widgets
	 */

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Widget")
	TSubclassOf<UEXWSharedWidget> ShopWidgetClass = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Widget")
	TSubclassOf<UEXWSharedWidget> TradeWidgetClass = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Widget|FloatingText")
	TSubclassOf<UEXWFloatingWidget> FloatingTextWidgetClass = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Widget|FloatingText")
	TMap<EEXWAttributeEffectType, FLinearColor> FloatingTextColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Widget|ScreenMessage")
	TMap<EEXWScreenMessageType, FEXWScreenMessageData> ScreenMessages = 
	{
	   {EEXWScreenMessageType::SM_EquipmentClassError, FEXWScreenMessageData()},
	   {EEXWScreenMessageType::SM_EquipmentLevelError, FEXWScreenMessageData()},
	   {EEXWScreenMessageType::SM_InventorySpaceError, FEXWScreenMessageData()},
	   {EEXWScreenMessageType::SM_GatheringNoToolError, FEXWScreenMessageData()},
	   {EEXWScreenMessageType::SM_InteractionRangeError, FEXWScreenMessageData()},
	   {EEXWScreenMessageType::SM_ResourceBeingGatheredError, FEXWScreenMessageData()},
	   {EEXWScreenMessageType::SM_NoResourceToGatherError, FEXWScreenMessageData()}
	};

	/**
	 * Cosmetics
	 */

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* IKDataTable = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics")
		UDataTable* RaceClassDataDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* HeadTypeDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* HairTypeDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* HairColorDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* ArmsTypeDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* BodyTypeDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* TorsoTypeDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* EyesTypeDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* EyesColorDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* FaceTypeDT = nullptr;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* FeetTypeDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* LegsTypeDT = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Cosmetics|Appearance")
		UDataTable* SkinTypeDT = nullptr;
};
