// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/Inventory/EXWInventoryLibrary.h"

// Dependencies
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "GenericPlatform/GenericPlatformMath.h"
#include "Kismet/KismetMathLibrary.h"

DEFINE_LOG_CATEGORY(EXWInventoryLog);

bool UEXWInventoryLibrary::GetItemData(const FName ItemID, FEXWItemData& OutItemData)
{
	if (ItemID != "None")
	{
		// Find data table
		if (UDataTable* ItemDT = UEXWDataLibrary::GetItemDT())
		{
			FName SItemID = ItemID;
			SplitItemID(SItemID);
			static const FString ContextString(TEXT("ItemDT"));
			FEXWItemData* ItemData = ItemDT->FindRow<FEXWItemData>(SItemID, ContextString, true);

			// Check if the the row data was found.
			if (ItemData)
			{
				OutItemData = *ItemData;
				return true;
			}
			else
			{
				UE_LOG(EXWInventoryLog, Warning, TEXT("Inventory Item [Row Name : %s] Not Found"), *ItemID.ToString());
			}
		}
	}
	return false;
}

bool UEXWInventoryLibrary::GetCraftingOptionData(const FName CraftingOptionID, FEXWCraftingOption& OutCraftingOptionData)
{
	if (CraftingOptionID != "None")
	{
		// Find data table
		if (UDataTable* CraftingOptionsDT = UEXWDataLibrary::GetCraftingOptionsDT())
		{
			static const FString ContextString(TEXT("CraftingOptionID"));
			FEXWCraftingOption* CraftingOptionData = CraftingOptionsDT->FindRow<FEXWCraftingOption>(CraftingOptionID, ContextString, true);

			// Check if the the row data was found.
			if (CraftingOptionData)
			{
				OutCraftingOptionData = *CraftingOptionData;
				return true;
			}
			else
			{
				UE_LOG(EXWInventoryLog, Warning, TEXT("Crafting option [Row Name : %s] Not Found"), *CraftingOptionID.ToString());
			}
		}
	}
	return false;
}

FTransform UEXWInventoryLibrary::GetItemSpawnTransform(AActor* Spawner)
{
	int32 UnsignedVarianceX = UKismetMathLibrary::RandomInteger(UKismetMathLibrary::FTrunc(UEXWDataLibrary::GetItemSpawnDistanceVariance()));
	int8 VarianceSignX = UKismetMathLibrary::RandomBool() ? 1 : -1;
	int32 UnsignedVarianceY = UKismetMathLibrary::RandomInteger(UKismetMathLibrary::FTrunc(UEXWDataLibrary::GetItemSpawnDistanceVariance()));
	int8 VarianceSignY = UKismetMathLibrary::RandomBool() ? 1 : -1;

	FVector VarianceVector(UnsignedVarianceX * VarianceSignX, UnsignedVarianceY * VarianceSignY, UnsignedVarianceX);
	FVector SpawnLocation = Spawner->GetActorLocation() + VarianceVector +
							UKismetMathLibrary::GetForwardVector(Spawner->GetActorRotation()) * UEXWDataLibrary::GetItemSpawnDistance();
	return FTransform(	Spawner->GetActorRotation(), 
						SpawnLocation,
						FVector(1.));
}



bool UEXWInventoryLibrary::SplitItemGeneratedData(FName& ItemID, /*FText& TxtItemID,*/ int32& Level, TArray<FString>& RNG)
{
	FString RightSide;
	FString FullItemId=ItemID.ToString();
	FString StringItemId = ItemID.ToString();
	FString StrLevel;
	FString StrRNG;
	if (FullItemId.Split("|", &StringItemId, &RightSide, ESearchCase::IgnoreCase, ESearchDir::FromStart))//separate itemID from remaining
	{
		ItemID = FName(StringItemId);
		if (!RightSide.IsEmpty())
		{
			if (RightSide.Split("|", &StrLevel, &StrRNG, ESearchCase::IgnoreCase, ESearchDir::FromStart))//separate Level and RNG
			{
				Level=FCString::Atoi(*StrLevel);
				if (!StrRNG.IsEmpty())
				{
					StrRNG.ParseIntoArray(RNG, TEXT(","), true);
				}
			}
		}
		else
		{
			RNG.Empty();
		}
		return true;
	}
	else
	{
		Level = 0;
	}

	return false;
}

bool UEXWInventoryLibrary::SplitItemID(FName& ItemID)
{
	FString RightSide;
	FString StringItemId = ItemID.ToString();
	if (StringItemId.Split("|", &StringItemId, &RightSide, ESearchCase::IgnoreCase, ESearchDir::FromStart))//separate itemID from remaining
	{
		ItemID = FName(StringItemId);
		return true;
	}
	return false;
}

bool UEXWInventoryLibrary::SplitItemRNG(FName ItemID, TMap<EEXWStatType, float>& Stats, TMap<EEXWAttributeType, float>& Attributes)
{
	return false;
}

int32 UEXWInventoryLibrary::HasEmptySlot(FEXWInventory& Inventory)
{
	int32 index = 0;
	for (FEXWInventorySlot& InventorySlot : Inventory.ItemSlots)
	{
		if (InventorySlot.ItemID == "None")
		{
			return index;
		}
		index++;
	}
	return -1;
}

bool UEXWInventoryLibrary::IsValidSlot(FEXWInventorySlot& InventorySlot)
{
	return InventorySlot.ItemID != "None";
}

TArray<FEXWInventorySlot> UEXWInventoryLibrary::GetAllEmptySlots(FEXWInventory& Inventory)
{
	TArray<FEXWInventorySlot> InventorySlots;
	for (FEXWInventorySlot& InventorySlot : InventorySlots)
	{
		if (InventorySlot.ItemID == "None")
		{
			InventorySlots.Add(InventorySlot);
		}
	}
	return InventorySlots;
}

void UEXWInventoryLibrary::ResetSlot(FEXWInventorySlot& InventorySlot)
{
	InventorySlot = FEXWInventorySlot();
}

int32 UEXWInventoryLibrary::GetItemCount(const FName ItemID, const FEXWInventory& Inventory)
{
	int32 ResultValue = 0;
	for (FEXWInventorySlot ItemSlot : Inventory.ItemSlots)
	{
		if (ItemSlot.Count >= 0 && ItemSlot.ItemID == ItemID)
		{
				ResultValue += ItemSlot.Count;
		}
	}
	return ResultValue;
}

bool UEXWInventoryLibrary::HasItems(const FName ItemID, const int32 Count, const FEXWInventory& Inventory)
{
	return ItemID  != "None" && (GetItemCount(ItemID, Inventory) >= Count || GetItemCount(ItemID, Inventory) == -1);
}

int32 UEXWInventoryLibrary::CanAddItems(const FName ItemID, const int32 Count, FEXWInventory& Inventory)
{
	int32 index = 0;
	// Check if there is an item slot that exists in the inventory
	for (FEXWInventorySlot& InventorySlot : Inventory.ItemSlots)
	{
		// Check if there is an empty Slot
		if (InventorySlot.Count > 0)
		{
			if (InventorySlot.ItemID == ItemID)
			{
				// Check if we can add on the slot stack found of this item
				FEXWItemData ItemData;
				if (GetItemData(ItemID, ItemData))
				{
					if (InventorySlot.Count + Count <= ItemData.MaxStackSize)
					{
						return index;
					}
				}
			}
		}
		index++;
	}
	return HasEmptySlot(Inventory);
}

bool UEXWInventoryLibrary::AddItems(const FName ItemID, const int32 Count, FEXWInventory& Inventory)
{
	int32 AddIndex = CanAddItems(ItemID, Count, Inventory);
	if (AddIndex != -1)
	{
		Inventory.ItemSlots[AddIndex].ItemID = ItemID;
		Inventory.ItemSlots[AddIndex].Count += Count;
		UE_LOG(EXWInventoryLog, Log, TEXT("%d x [%s] item(s) were added to the inventory"), Count, *ItemID.ToString());
		return true;
	}
	UE_LOG(EXWInventoryLog, Log, TEXT("%d x [%s] item(s) were not able to be added to the inventory"), Count, *ItemID.ToString());
	return false;
}

bool UEXWInventoryLibrary::AddSilver(const int32 Quantity, FEXWInventory& Inventory)
{
	Inventory.CoinsSilver += Quantity;
	return true;
}

bool UEXWInventoryLibrary::AddGold(const int32 Quantity, FEXWInventory& Inventory)
{
	Inventory.CoinsGold += Quantity;
	return true;
}

bool UEXWInventoryLibrary::CanRemoveItems(const FName ItemID, const int32 Count, FEXWInventory& Inventory)
{
	return HasItems(ItemID, Count, Inventory);
}

bool UEXWInventoryLibrary::RemoveItems(const FName ItemID, int32 Count, FEXWInventory& Inventory)
{
	if (CanRemoveItems(ItemID, Count, Inventory))
	{
		for (FEXWInventorySlot &InventorySlot : Inventory.ItemSlots)
		{
			if (InventorySlot.ItemID == ItemID ) // Check if it is the item we are looking for
			{
				if (InventorySlot.Count > Count) // Check if the stack contains more than what we want to remove
				{
					InventorySlot.Count -= Count;
				}
				else if (InventorySlot.Count == -1)
				{
					// Do nothing.
				}
				else // Check if the stack contains less or equal to what we want to remove
				{
					Count -= InventorySlot.Count;
					ResetSlot(InventorySlot);
				}
			}
		}
		return true;
	}
	return false;
}

bool UEXWInventoryLibrary::RemoveItemsFromSlot(const int32 SlotIndex, FEXWInventory& Inventory)
{
	if (Inventory.ItemSlots.IsValidIndex(SlotIndex))
	{
		if (CanRemoveItems(Inventory.ItemSlots[SlotIndex].ItemID, Inventory.ItemSlots[SlotIndex].Count, Inventory))
		{
			ResetSlot(Inventory.ItemSlots[SlotIndex]);
			UE_LOG(EXWInventoryLog, Log, TEXT("%d x [%s] item(s) were removed from the inventory"), Inventory.ItemSlots[SlotIndex].Count, *Inventory.ItemSlots[SlotIndex].ItemID.ToString());
			return true;
		}
		UE_LOG(EXWInventoryLog, Log, TEXT("%d x [%s] item(s) were not able to be removed to the inventory"), Inventory.ItemSlots[SlotIndex].Count, *Inventory.ItemSlots[SlotIndex].ItemID.ToString());
	}
	return false;
}

bool UEXWInventoryLibrary::RemoveItemCountFromSlot(const int32 ItemCountToRemove, FEXWInventorySlot& InventorySlot)
{
	if (InventorySlot.Count > ItemCountToRemove)
	{
		InventorySlot.Count -= ItemCountToRemove;
		return true;
	}
	else if (InventorySlot.Count == ItemCountToRemove)
	{
		ResetSlot(InventorySlot);
		return true;
	}
	UE_LOG(EXWInventoryLog, Log, TEXT("Not enough items to remove from the slot."));
	return false;
}

bool UEXWInventoryLibrary::RemoveItemCountFromSlotByIndex(const int32 ItemCountToRemove, const int32 SlotIndex, FEXWInventory& Inventory)
{
	if (Inventory.ItemSlots.IsValidIndex(SlotIndex))
	{
		if (RemoveItemCountFromSlot(ItemCountToRemove, Inventory.ItemSlots[SlotIndex]))
		{
			return true;
		}
	}
	UE_LOG(EXWInventoryLog, Log, TEXT("Could not remove items from the given inventory and slot index."));
	return false;
}

void UEXWInventoryLibrary::SwapInventorySlots(FEXWInventorySlot& Slot1, FEXWInventorySlot& Slot2)
{
	// Create temp
	FEXWInventorySlot TempSlot = Slot2;

	// Copy to Slot2
	Slot2.ItemID = Slot1.ItemID;
	Slot2.Count = Slot1.Count;

	// Copy to Slot1
	Slot1.ItemID = TempSlot.ItemID;
	Slot1.Count = TempSlot.Count;
}

bool UEXWInventoryLibrary::MoveInventorySlot(const int32 SourceSlotIndex, const int32 TargetSlotIndex, FEXWInventory& Inventory)
{
	if (Inventory.ItemSlots.Num() > SourceSlotIndex && Inventory.ItemSlots.Num() > TargetSlotIndex)
	{
		if (Inventory.IsSlotEmpty(SourceSlotIndex))
		{
			UE_LOG(EXWInventoryLog, Log, TEXT("Cannot move an empty item slot"));
			return false;
		}

		// Normal Swapping
		SwapInventorySlots(Inventory.ItemSlots[SourceSlotIndex], Inventory.ItemSlots[TargetSlotIndex]);
		return true;

		/* TODO : PROPER SWAPPING / ADDING - REMOVING
		FEXWItemData ItemData;
		if (GetItemData(Inventory.GetItemID(SourceSlotIndex), ItemData))
		{
			// Check if it is the same Item type (ID)
			if (Inventory.GetItemID(SourceSlotIndex) == Inventory.GetItemID(TargetSlotIndex))
			{
				if (Inventory.GetItemCount(TargetSlotIndex) < ItemData.MaxStackSize)
				{
					int32 FreeSpace = ItemData.MaxStackSize - Inventory.GetItemCount(TargetSlotIndex);
					if (Inventory.GetItemCount(SourceSlotIndex) > FreeSpace)
					{

					}
					Inventory.ItemSlots[TargetSlotIndex];
				}
			}
		}
		*/
	}
	return false;
}

bool UEXWInventoryLibrary::SwapDifferentInventorySlots(const int32 Inventory1Slot, const int32 Inventory2Slot, FEXWInventory& Inventory1, FEXWInventory& Inventory2)
{
	if (Inventory1.ItemSlots.IsValidIndex(Inventory1Slot) && Inventory2.ItemSlots.IsValidIndex(Inventory2Slot))
	{
		SwapInventorySlots(Inventory1.ItemSlots[Inventory1Slot], Inventory2.ItemSlots[Inventory2Slot]);
		return true;
	}
	return false;
}

bool UEXWInventoryLibrary::MoveInventorySlotsToInventory(FEXWInventory& Inventory1, FEXWInventory& Inventory2)
{
	for (FEXWInventorySlot& ItemSlot : Inventory1.ItemSlots)
	{
		if (ItemSlot.ItemID != "None")
		{
			AddItems(ItemSlot.ItemID, ItemSlot.Count, Inventory2);
			ResetSlot(ItemSlot);
		}
	}
	return true;
}

void UEXWInventoryLibrary::MoveCoins(FEXWInventory& Inventory1, FEXWInventory& Inventory2)
{
	Inventory2.CoinsSilver += Inventory1.CoinsSilver;
	Inventory2.CoinsGold += Inventory1.CoinsGold;
}

FText UEXWInventoryLibrary::GetStatEffectsAsText(const FName ItemID)
{
	FEXWItemData ItemData;
	FString FinalString;
	if (GetItemData(ItemID, ItemData))
	{
		for (TPair<EEXWStatType, float>& StatEffect : ItemData.StatEffectsOnEquip)
		{
			FinalString += (UEXWDataLibrary::StatTypeAsText(StatEffect.Key).ToString() + FString(" ") + FString::FromInt((int32)StatEffect.Value) + "\n");
		}
	}
	return FText::FromString(FinalString);
}

FText UEXWInventoryLibrary::GetAttributeEffectsAsText(const FName ItemID)
{
	FEXWItemData ItemData;
	FString FinalString;
	if (GetItemData(ItemID, ItemData))
	{
		for (TPair<EEXWAttributeType, float>& AttributeEffect : ItemData.AttributeEffectsOnEquip)
		{
			FinalString += (FString::FromInt((int32)AttributeEffect.Value) + FString(" ") + UEXWDataLibrary::AttributeTypeAsText(AttributeEffect.Key).ToString() + "\n");
		}
	}
	return FText::FromString(FinalString);
}

EEXWBuyResult UEXWInventoryLibrary::CanBuyItems(const FName ItemID, int32 Count, FEXWInventory& BuyerInventory, FEXWInventory& SellerInventory, FEXWInventorySlot& OutSlot)
{	
	FEXWItemData Item;

	bool bIsValidItem = false;
	bool bSellerHasItems = false;
	bool bHasEnoughCoins = false;
	bool bHasEnoughSpace = false;

	// Check if the item is valid
	if (GetItemData(ItemID, Item))
	{
		bIsValidItem = true;
		// Check if the seller has the items
		bSellerHasItems = HasItems(ItemID, Count, SellerInventory);
		// Check if the currency is enough to buy these items
		if (BuyerInventory.CoinsSilver >= Item.PriceSilver * Count && BuyerInventory.CoinsGold >= Item.PriceGold * Count)
		{
			bHasEnoughCoins = true;
		}
		// Check if there are enough slots to buy the item
		bHasEnoughSpace = (CanAddItems(ItemID, Count, BuyerInventory) != -1);
	}
	// Return the value depending on the situation found
	if (!bIsValidItem)
	{
		return EEXWBuyResult::BR_UnvalidItem;
	}
	else if (!bSellerHasItems)
	{
		return EEXWBuyResult::BR_SellerHasNoItem;
	}
	else if (!bHasEnoughCoins)
	{
		return EEXWBuyResult::BR_NotEnoughCoins;
	}
	else if (!bHasEnoughSpace)
	{
		return EEXWBuyResult::BR_NotEnoughSpace;
	}
	return EEXWBuyResult::BR_Success;
}

EEXWBuyResult UEXWInventoryLibrary::CanBuyItemFromSlot(const FEXWInventorySlot ItemSlot, int32 Count, FEXWInventory& BuyerInventory, FEXWInventory& SellerInventory)
{
	FEXWItemData Item;

	bool bIsValidItem = false;
	bool bSellerHasItems = false;
	bool bHasEnoughCoins = false;
	bool bHasEnoughSpace = false;

	// Check if the item is valid
	if (GetItemData(ItemSlot.ItemID, Item))
	{
		bIsValidItem = true;
		// Check if the seller has the items
		bSellerHasItems = HasItems(ItemSlot.ItemID, Count, SellerInventory);
		// Check if the currency is enough to buy these items
		if (BuyerInventory.CoinsSilver >= ItemSlot.PriceSilver * Count && BuyerInventory.CoinsGold >= ItemSlot.PriceGold * Count)
		{
			bHasEnoughCoins = true;
		}
		// Check if there are enough slots to buy the item
		bHasEnoughSpace = (CanAddItems(ItemSlot.ItemID, Count, BuyerInventory) != -1);
	}
	// Return the value depending on the situation found
	if (!bIsValidItem)
	{
		return EEXWBuyResult::BR_UnvalidItem;
	}
	else if (!bSellerHasItems)
	{
		return EEXWBuyResult::BR_SellerHasNoItem;
	}
	else if (!bHasEnoughCoins)
	{
		return EEXWBuyResult::BR_NotEnoughCoins;
	}
	else if (!bHasEnoughSpace)
	{
		return EEXWBuyResult::BR_NotEnoughSpace;
	}
	return EEXWBuyResult::BR_Success;
}

EEXWBuyResult UEXWInventoryLibrary::BuyItems(const FName ItemID, int32 Count, FEXWInventory& BuyerInventory, FEXWInventory& SellerInventory)
{
	FEXWInventorySlot ResultSlot;
	EEXWBuyResult BuyResult = CanBuyItems(ItemID, Count, BuyerInventory, SellerInventory, ResultSlot);
	if (BuyResult == EEXWBuyResult::BR_Success)
	{
		RemoveItems(ItemID, Count, SellerInventory);
		AddItems(ItemID, Count, BuyerInventory);
		FEXWItemData ItemData;
		GetItemData(ItemID, ItemData);
		BuyerInventory.CoinsSilver -= ItemData.PriceSilver * Count;
		BuyerInventory.CoinsGold -= ItemData.PriceGold * Count;
		SellerInventory.CoinsSilver += ItemData.PriceSilver * Count;
		SellerInventory.CoinsGold += ItemData.PriceGold * Count;
	}
	return BuyResult;
}

EEXWBuyResult UEXWInventoryLibrary::BuyItemFromSlot(const FEXWInventorySlot ItemSlot, int32 Count, FEXWInventory& BuyerInventory, FEXWInventory& SellerInventory)
{
	FEXWInventorySlot ResultSlot;
	EEXWBuyResult BuyResult = CanBuyItemFromSlot(ItemSlot, Count, BuyerInventory, SellerInventory);
	if (BuyResult == EEXWBuyResult::BR_Success)
	{
		RemoveItems(ItemSlot.ItemID, Count, SellerInventory);
		AddItems(ItemSlot.ItemID, Count, BuyerInventory);
		
		BuyerInventory.CoinsSilver -= ItemSlot.PriceSilver * Count;
		BuyerInventory.CoinsGold -= ItemSlot.PriceGold * Count;
		SellerInventory.CoinsSilver += ItemSlot.PriceSilver * Count;
		SellerInventory.CoinsGold += ItemSlot.PriceGold * Count;
	}
	return BuyResult;
}

bool UEXWInventoryLibrary::CanAddTradeInventory(const FEXWInventory& TradeInventory, FEXWInventory& Inventory)
{
	if (TradeInventory.ItemSlots.Num() < GetAllEmptySlots(Inventory).Num())
	{
		return true;
	}
	return false;
}

bool UEXWInventoryLibrary::CanRemoveTradeInventory(const FEXWInventory& TradeInventory, FEXWInventory& Inventory)
{
	for (FEXWInventorySlot InventorySlots : TradeInventory.ItemSlots)
	{
		if (!CanRemoveItems(InventorySlots.ItemID, InventorySlots.Count, Inventory))
		{
			return false;
		}
	}
	//TODO: Confirms if its an AND or an OR
	if (TradeInventory.CoinsSilver > Inventory.CoinsSilver && TradeInventory.CoinsGold > Inventory.CoinsGold)
	{
		return false;
	}
	return true;
}

bool UEXWInventoryLibrary::TradeItems(FEXWInventory& Inventory1, FEXWInventory& Inventory2, FEXWInventory& TradeInventory1, FEXWInventory& TradeInventory2)
{
	return (CanRemoveTradeInventory(TradeInventory1, Inventory1) && CanRemoveTradeInventory(TradeInventory2, Inventory2))
		&& (CanAddTradeInventory(TradeInventory1, Inventory2) && CanAddTradeInventory(TradeInventory2, Inventory1));
}

void UEXWInventoryLibrary::SetItemSlotPrice(const FEXWInventorySlot ItemSlot, int32 PriceSilver, int32 PriceGold, FEXWInventory& Inventory)
{
	for (FEXWInventorySlot& InventorySlot : Inventory.ItemSlots) {
		if (ItemSlot == InventorySlot)
		{
			UE_LOG(EXWInventoryLog, Warning, TEXT("SetItemSlotPrice: %s, Gold: %d, Silver: %d"), *ItemSlot.ItemID.ToString(), PriceGold, PriceSilver);
			InventorySlot.PriceGold = PriceGold;
			InventorySlot.PriceSilver = PriceSilver;
			break;
		}
	}
}

void UEXWInventoryLibrary::AddChildToPanel(UUniformGridPanel* GridPanel, UWidget* SlotWidget, const int32 CurrentIndex, const int32 MaxColumns)
{
	if (GridPanel && SlotWidget)
	{
		UUniformGridSlot* SlotPanelWidget = Cast<UUniformGridSlot>(GridPanel->AddChild(SlotWidget));
		SlotPanelWidget->SetColumn(FGenericPlatformMath::Fmod(CurrentIndex, MaxColumns));
		SlotPanelWidget->SetRow(UKismetMathLibrary::FTrunc(CurrentIndex / MaxColumns));
	}
}

FText UEXWInventoryLibrary::GetEquipmentTypeAsText(EEXWEquipmentType EquipmentType)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EEXWEquipmentType"), true);
	if (!enumPtr)
	{
		return FText::FromString("Invalid");
	}
	return enumPtr->GetDisplayNameText((int32)EquipmentType);
}

bool UEXWInventoryLibrary::HasEnoughCraftingItems(const FName CraftID, FEXWInventory& Inventory)
{
	FEXWCraftingOption CraftingOption;
	if (GetCraftingOptionData(CraftID, CraftingOption))
	{
		for (TPair<FName, int32>& Item : CraftingOption.ItemsToUse)
		{
			if (!HasItems(Item.Key, Item.Value, Inventory))
			{
				UE_LOG(EXWInventoryLog, Log, TEXT("Cannot find enough required items [%s] to process the craft."), *Item.Key.ToString());
				return false;
			}
		}
	}
	return false;
}

bool UEXWInventoryLibrary::CanExecuteCrafting(const FName CraftID, FEXWInventory& Inventory)
{
	FEXWCraftingOption CraftingOption;
	if (GetCraftingOptionData(CraftID, CraftingOption))
	{
		// Check if there is empty space if 1 item to add only
		if (CraftingOption.ItemsToCreate.Num() == 1)
		{
			TArray<FName> Keys;
			CraftingOption.ItemsToCreate.GetKeys(Keys);
			TArray<int32> Values;
			CraftingOption.ItemsToCreate.GenerateValueArray(Values);
			if (CanAddItems(Keys[0], Values[0], Inventory) == -1)
			{
				UE_LOG(EXWInventoryLog, Log, TEXT("Cannot find enough space to process the craft."));
				return false;
			}
		}
		// Check if there is empty space if there are more than 1 item to add
		else
		{
			TArray<FEXWInventorySlot> InventorySlots = GetAllEmptySlots(Inventory);
			if (InventorySlots.Num() < CraftingOption.ItemsToCreate.Num())
			{
				UE_LOG(EXWInventoryLog, Log, TEXT("Cannot find enough space to process the craft."));
				return false;
			}
		}

		for (TPair<FName, int32>& Item : CraftingOption.ItemsToUse)
		{
			if (!HasItems(Item.Key, Item.Value, Inventory))
			{
				UE_LOG(EXWInventoryLog, Log, TEXT("Cannot find enough required items [%s] to process the craft."), *Item.Key.ToString());
				return false;
			}
		}
		
	}
	return true;
}

bool UEXWInventoryLibrary::GetSlotIndexByType(int32& OutSlotIndex, FEXWInventory& InInventoryEquipment, const EEXWSlotType SlotType)
{
	OutSlotIndex = -1;
	for (uint16 i = 0; i < InInventoryEquipment.ItemSlots.Num(); i++)
	{
		if (InInventoryEquipment.ItemSlots[i].AcceptableSlotTypes.Contains(SlotType))
		{
			if (InInventoryEquipment.IsSlotEmpty(i))
			{
				OutSlotIndex = i;
				return true;
			}
			OutSlotIndex = i;
		}
	}
	if (OutSlotIndex > -1)
	{
		return true;
	}
	return false;
}