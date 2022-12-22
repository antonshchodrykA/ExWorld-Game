// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/InventoryManagerComponent.h"
#include "ExWorldLog.h"
#include "UnrealNetwork.h"


// Sets default values for this component's properties
UInventoryManagerComponent::UInventoryManagerComponent()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> EquipmentDataTableObject(TEXT("DataTable'/Game/InventorySystem/DataTable/DT_PlayerEquipment.DT_PlayerEquipment'"));
	static ConstructorHelpers::FObjectFinder<UDataTable> InventoryDataTableObject(TEXT("DataTable'/Game/InventorySystem/DataTable/DT_PlayerInventory.DT_PlayerInventory'"));
	if (EquipmentDataTableObject.Succeeded() && InventoryDataTableObject.Succeeded())
	{
		EquipmentDataTable = EquipmentDataTableObject.Object;
		InventoryDataTable = InventoryDataTableObject.Object;
	}
}


void UInventoryManagerComponent::InitializeInventoryManager(UInventoryComponent* PlayerInventoryComponent, APlayerController* PlayerController, EEXWClass Classes)
{
	//LoadItemsOnServer(PlayerInventoryComponent,PlayerController,Classes);
}

void UInventoryManagerComponent::InitializeInventoryManagerUI(TSubclassOf<UInventoryUI> InventoryUI)
{
	InventoryUITemplate = InventoryUI;
}

void UInventoryManagerComponent::LoadItemsOnServer(UInventoryComponent* PlayerInventoryComponent, APlayerController* PlayerController, EEXWClass Classes)
{
	    //TODO check for authority -> Might move to Player controller class for implementation
		//TODO Run a safety check if data table are loaded correctly
	/*	static const FString ContextString(TEXT("EquipmentDataTable"));
		TArray<FInventoryItem> LocalInventory;
		FInventoryItem Items;
		FInventoryItem* InventoryList = nullptr;
		const FText ClassText = UEnum::GetDisplayValueAsText(Classes);
		const FName ClassName = FName(*ClassText.ToString());
		FEquipmentList* EquipmentList = EquipmentDataTable->FindRow<FEquipmentList>(ClassName, ContextString, true);
		//TODO Also put condition if row not found
	    if (EquipmentList)
	    {
	    	TArray<FName> EquipId;
	    	EquipId.Add(EquipmentList->Head);
	    	EquipId.Add(EquipmentList->Shoulder);
	    	EquipId.Add(EquipmentList->Chest);
	    	EquipId.Add(EquipmentList->Hands);
	    	EquipId.Add(EquipmentList->Legs);
	    	EquipId.Add(EquipmentList->Feet);
	    	EquipId.Add(EquipmentList->Back);
	    	EquipId.Add(EquipmentList->Waist);
			
	    	for(int32 i = 0; i < EquipId.Num(); i++)
	    	{
	    		InventoryList = InventoryDataTable->FindRow<FInventoryItem>(EquipId[i], ContextString, true);
	    		//Fill the array
	    		(InventoryList)?LocalInventory.Insert(*InventoryList,i):LocalInventory.Insert(Items,i);
	    	}

	    	for(int32 i = 0; i < EquipmentList->ExInventoryItems.Num(); i++)
	    	{
	    		InventoryList = InventoryDataTable->FindRow<FInventoryItem>(EquipmentList->ExInventoryItems[i].ItemID, ContextString, true);
	            if (InventoryList)
	            {
		            InventoryList->Amount = EquipmentList->ExInventoryItems[i].Amount;
	            }
	    		//Add currency 
	            (InventoryList->Type == EItemType::Currency)?AddItemToInventory(*InventoryList):LocalInventory.Add(*InventoryList);
	    	}
	    	// Clear the inventory and add the local items
	    	PlayerInventoryComponent->InitializeInventoryItems(InventorySize,LocalInventory);
	    	Client_LoadInventoryUI();
	    }*/
}

bool UInventoryManagerComponent::AddItemToInventory(FInventoryItem InventoryItem)
{
	
	LocalInventoryItem = InventoryItem;
	LocalItemID = LocalInventoryItem.ID;
	LocalItemAmount = LocalInventoryItem.Amount;
	if(LocalInventoryItem.Type == EItemType::Currency)
	{
		AddGold(LocalItemAmount);
		return true;
	}

	// else if check if item is stackable
	// yes -> get empty inventory slot space
	// yes -> add item
	// else inventiry full
	
	return false;
}

void UInventoryManagerComponent::LoadInventory()
{

	/*
	|    |     |
	_______________	
	|	 |	   |
	_______________	
	|    |	   |
	_______________
	|    |     |
	_______________
	|    |     |
	*/
	//TODO get the ui and clear the slots
	// Create Inventory Slots
/*	if (InventorySize>0)
	{
		const int32 LocalInventorySize = InventorySize;
		const int32 LocalInventorySlots = SlotsPerRow;
		//TODO Expose to BP
		// Equipment Slots + Inventory Slots
		int32 Slots = 8;                                                     
		int32 LoopCount = 0;
		int32 Count = round(LocalInventorySize/LocalInventorySlots);
		Count = Count-1;
		for (int32 Row=0; Row<=Count; Row++)
		{
			// Add Slots
			for(int32 Column=0; Column<=LocalInventorySlots-1; Column++)
			{
				Slots+=1;
				LoopCount+=1;
				AddInventorySlot(Row,Column,Slots);
				if(LoopCount == LocalInventorySize){break;}
			}
		}
	}*/
}

void UInventoryManagerComponent::Client_LoadInventoryUI_Implementation()
{
	LoadInventory();
}


bool UInventoryManagerComponent::TryToRemoveItemFromInventory(UInventoryComponent* Inventory, FName ItemID, int32 Amount)
{
	return false;
}

bool UInventoryManagerComponent::CheckInventoryForItemAmount(UInventoryComponent* Inventory, FName ItemID, int32 Amount)
{
	return false;
}

void UInventoryManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UInventoryManagerComponent, InventorySize);
}


void UInventoryManagerComponent::OpenInventoryWindow()
{
}

void UInventoryManagerComponent::CloseInventoryWindow()
{
}

void UInventoryManagerComponent::OpenContainerWindow()
{
}

void UInventoryManagerComponent::CloseContainerWindow()
{
}

void UInventoryManagerComponent::OpenEquipmentWindow()
{
}

void UInventoryManagerComponent::CloseEquipmentWindow()
{
}




void UInventoryManagerComponent::CreateInventorySlots(int32 InventorySize, uint8 SlotsPerRow)
{
}


void UInventoryManagerComponent::ClearInventorySlot(int32 InventorySlot)
{
}

void UInventoryManagerComponent::GetInventorySlotItem(int32 InventorySlot)
{
}

void UInventoryManagerComponent::IncreaseInventorySlots(int32 Amount)
{
}

void UInventoryManagerComponent::DecreaseInventorySlots(int32 Amount)
{
}

void UInventoryManagerComponent::AddInventorySlot(int32 Row, int32 Column, int32 Slot)
{
				EXWORLDLOG_IW("ROW   ", Row)
                EXWORLDLOG_IW("Column   ", Column)
                EXWORLDLOG_IW("Slots   ", Slot)
}

void UInventoryManagerComponent::RemoveInventorySlot(int32 InventorySlot)
{
}

void UInventoryManagerComponent::RefreshInventorySlots()
{
	//Get client inventory from server
}

void UInventoryManagerComponent::ClearInventorySlotItems()
{
}


void UInventoryManagerComponent::AddItems(UInventoryComponent* Inventory, int32 InventorySlot, FInventoryItem InventoryItem)
{
}

void UInventoryManagerComponent::RemoveItems(UInventoryComponent* Inventory, int32 InventorySlot)
{
}

void UInventoryManagerComponent::MoveItem(UInventoryComponent* FromInventory, int32 FromInventorySlot, UInventoryComponent* ToInventory, int32 ToInventorySlot)
{
}

void UInventoryManagerComponent::DropItems(UInventoryComponent* Inventory, int32 InventorySlot)
{
}

bool UInventoryManagerComponent::HasItem(UInventoryComponent* Inventory, FName ItemID, int32& InventorySlot)
{
	return false;
}

void UInventoryManagerComponent::AddGold(int32 Amount)
{
}

void UInventoryManagerComponent::SplitItem(UInventoryComponent* FromInventory, int32 FromInventorySlot, UInventoryComponent* ToInventory, int32 ToInventorySlot, int32 Amount)
{
}

void UInventoryManagerComponent::IncreaseInventorySize(UInventoryComponent* Inventory, int32 Amount)
{
}

void UInventoryManagerComponent::DecreaseInventorySize(UInventoryComponent* Inventory, int32 Amount)
{
}

bool UInventoryManagerComponent::CheckSlotsForItems(UInventoryComponent* Inventory, int32 Amount)
{
	return false;
}

void UInventoryManagerComponent::UseContainer(AActor* Container)
{
}

void UInventoryManagerComponent::OpenContainer(AActor* Container)
{
}

void UInventoryManagerComponent::CloseContainer()
{
}

void UInventoryManagerComponent::UseContainerItem(int32 ContainerSlot)
{
}

void UInventoryManagerComponent::UseInventoryItem(int32 InventorySlot)
{
}

void UInventoryManagerComponent::UseEquipmentItem(int32 InventorySlot, UInventoryComponent* ToInventory, FInventoryItem InventoryItem)
{
}

void UInventoryManagerComponent::UseConsumableItem(int32 InventorySlot)
{
}

void UInventoryManagerComponent::EquipItem(UInventoryComponent* FromInventory, int32 FromInventorySlot, UInventoryComponent* ToInventory, int32 ToInventorySlot)
{
}

void UInventoryManagerComponent::UnEquipItem(UInventoryComponent* FromInventory, int32 FromInventorySlot, UInventoryComponent* ToInventory, int32 ToInventorySlot)
{
}

void UInventoryManagerComponent::UpdateEquippedStats()
{
}

void UInventoryManagerComponent::Server_InitializeInventorySlots_Implementation()
{
	RefreshInventorySlots();
}


