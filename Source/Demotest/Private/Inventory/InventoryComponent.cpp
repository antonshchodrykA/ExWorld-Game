// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "..\..\Public\Inventory\InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
}

void UInventoryComponent::InitializeInventoryItems(int32 InventorySize,
	TArray<FInventoryItem> InventoryItems)
{
	FInventoryItem LocalItem;
	//First clear the inventory
	Inventory.Empty();
	// Set the inventory item array depending on the size of an array
	for(int32 i = 0 ; i < InventorySize-1;i++)
	{
		Inventory.Add(LocalItem);
	}

	for (int32 i = 0 ; i < InventoryItems.Num();i++)
	{
		//Set Inventory Items
		Inventory.Insert(InventoryItems[i],i);
		LocalItem = Inventory[i];
	}
}


