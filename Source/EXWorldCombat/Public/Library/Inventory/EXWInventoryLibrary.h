// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

// Libraries
#include "Library/EXWDataLibrary.h"
#include "Library/Inventory/EXWInventoryStruct.h"

#include "EXWInventoryLibrary.generated.h"


//Inventory Log declaration
DECLARE_LOG_CATEGORY_EXTERN(EXWInventoryLog, Log, All);

class UUniformGridPanel;
class UUserWidget;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWInventoryLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	/**
	 * General Inventory Systems
	 */

	/**
	* Returns the Item Data from the DataTable
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static bool GetItemData(const FName ItemID, FEXWItemData& OutItemData);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static bool GetCraftingOptionData(const FName CraftingOptionID, FEXWCraftingOption& OutCraftingOptionData);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static FTransform GetItemSpawnTransform(AActor* Spawner);

	/**
	* Item ID parsing
	*/
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool SplitItemGeneratedData(UPARAM(ref)FName& ItemID,/* FText& StrItemID,*/ int32& Level, TArray<FString>& RNG);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static bool SplitItemID(UPARAM(ref) FName& ItemID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static bool SplitItemRNG(FName ItemID, TMap<EEXWStatType,float>& Stats, TMap<EEXWAttributeType, float>& Attributes);

	/**
	 * Returns whether the Inventory given into argument has an empty slot or not
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static int32 HasEmptySlot(UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static bool IsValidSlot(UPARAM(ref) FEXWInventorySlot& InventorySlot);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static TArray<FEXWInventorySlot> GetAllEmptySlots(UPARAM(ref) FEXWInventory& Inventory);

	/**
	 * Sets all the content of the slot to null
	 */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static void ResetSlot(UPARAM(ref) FEXWInventorySlot& InventorySlot);

	/**
	 * Return the Item counts of the ItemID in the Inventory given into argument
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static int32 GetItemCount(const FName ItemID, const FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static bool HasItems(const FName ItemID, const int32 Count, const FEXWInventory& Inventory);

	// Warning : The item count should not be above the MaxStackSize of the item itself, returns the slot
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static int32 CanAddItems(const FName ItemID, const int32 Count, UPARAM(ref) FEXWInventory& Inventory);

	// Warning : The item count should not be above the MaxStackSize of the item itself
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool AddItems(const FName ItemID, const int32 Count, UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool AddSilver(const int32 Quantity, UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool AddGold(const int32 Quantity, UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static bool CanRemoveItems(const FName ItemID, const int32 Count, UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool RemoveItems(const FName ItemID, int32 Count, UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool RemoveItemsFromSlot(const int32 SlotIndex, UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool RemoveItemCountFromSlot(const int32 ItemCountToRemove, UPARAM(ref) FEXWInventorySlot& Inventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool RemoveItemCountFromSlotByIndex(const int32 ItemCountToRemove, const int32 SlotIndex, UPARAM(ref) FEXWInventory& InventorySlot);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static void SwapInventorySlots(UPARAM(ref) FEXWInventorySlot& Slot1, UPARAM(ref) FEXWInventorySlot& Slot2);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool MoveInventorySlot(const int32 SourceSlotIndex, const int32 TargetSlotIndex, UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool SwapDifferentInventorySlots(const int32 Inventory1Slot, const int32 Inventory2Slot, UPARAM(ref) FEXWInventory& Inventory1, UPARAM(ref) FEXWInventory& Inventory2);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool MoveInventorySlotsToInventory(UPARAM(ref) FEXWInventory& Inventory1, UPARAM(ref) FEXWInventory& Inventory2);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static void MoveCoins(UPARAM(ref) FEXWInventory& Inventory1, UPARAM(ref) FEXWInventory& Inventory2);


	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static FText GetStatEffectsAsText(const FName ItemID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static FText GetAttributeEffectsAsText(const FName ItemID);

	/**
	 * Shop and Trade System
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static EEXWBuyResult CanBuyItems(const FName ItemID, int32 Count, UPARAM(ref) FEXWInventory& BuyerInventory, UPARAM(ref) FEXWInventory& SellerInventory, FEXWInventorySlot& OutSlot);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static EEXWBuyResult CanBuyItemFromSlot(const FEXWInventorySlot ItemSlot, int32 Count, UPARAM(ref) FEXWInventory& BuyerInventory, UPARAM(ref) FEXWInventory& SellerInventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static EEXWBuyResult BuyItems(const FName ItemID, int32 Count, UPARAM(ref) FEXWInventory& BuyerInventory, UPARAM(ref) FEXWInventory& SellerInventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static EEXWBuyResult BuyItemFromSlot(const FEXWInventorySlot ItemSlot, int32 Count, UPARAM(ref) FEXWInventory& BuyerInventory, UPARAM(ref) FEXWInventory& SellerInventory);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static bool CanAddTradeInventory(const FEXWInventory& TradeInventory, UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	static bool CanRemoveTradeInventory(const FEXWInventory& TradeInventory, UPARAM(ref) FEXWInventory& Inventory);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static bool TradeItems(UPARAM(ref) FEXWInventory& Inventory1, UPARAM(ref) FEXWInventory& Inventory2, UPARAM(ref) FEXWInventory& TradeInventory1, UPARAM(ref) FEXWInventory& TradeInventory2);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static void SetItemSlotPrice(const FEXWInventorySlot ItemSlot, int32 PriceSilver, int32 PriceGold, UPARAM(ref) FEXWInventory& Inventory);

	/*
	* Ui Utility
	*/

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory")
	static void AddChildToPanel(UUniformGridPanel* GridPanel, UWidget* SlotWidget, const int32 CurrentIndex, const int32 MaxColumns = 5);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory", meta = (CompactNodeTitle = "Equipment to Text"))
	static FText GetEquipmentTypeAsText(EEXWEquipmentType EquipmentType);

	/**
	 * Crafting
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory|Crafting")
	static bool HasEnoughCraftingItems(const FName CraftID, UPARAM(ref) FEXWInventory& Inventory);

	 UFUNCTION(BlueprintCallable, Category = "EXWorld|Inventory|Crafting")
	 static bool CanExecuteCrafting(const FName CraftID, UPARAM(ref) FEXWInventory &Inventory);

	 /**
	  * Equipment
	  */

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Equipment")
	 static bool GetSlotIndexByType(int32& OutSlotIndex, UPARAM(ref) FEXWInventory& InInventoryEquipment, const EEXWSlotType SlotType);
};
