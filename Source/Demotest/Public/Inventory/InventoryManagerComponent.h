// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EquipmentInventoryComponent.h"
#include "Inventory/UI/InventoryUI.h"
#include "InventoryComponent.h"
#include "InventoryManagerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEMOTEST_API UInventoryManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryManagerComponent();

public:	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerEquipment", meta = (AllowPrivateAccess = "true"))
	class UDataTable* EquipmentDataTable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerEquipment", meta = (AllowPrivateAccess = "true"))
	class UDataTable* InventoryDataTable;

	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "PlayerInventory", meta = (AllowPrivateAccess = "true"))
	int32 InventorySize = 25;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerInventory", meta = (AllowPrivateAccess = "true"))
	uint8 SlotsPerRow = 5;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ExWorld Inventory")
	TSubclassOf<UInventoryUI> InventoryUITemplate;

	UInventoryComponent* LocalInventory;
	FName LocalItemID;
	int32 LocalItemAmount;
	FInventoryItem LocalInventoryItem;

	//Will be called in player controller where this will feed the information
	// will be a default subclass in player controller from where we will set the values
	UFUNCTION(BlueprintCallable)
	void InitializeInventoryManager(UInventoryComponent* PlayerInventoryComponent, APlayerController* PlayerController, EEXWClass Classes);
	
	void InitializeInventoryManagerUI(TSubclassOf<UInventoryUI> InventoryUI); //TODO Add inventory UI info here
	void LoadItemsOnServer(UInventoryComponent* PlayerInventoryComponent,APlayerController* PlayerController, EEXWClass Classes);
	bool AddItemToInventory(FInventoryItem InventoryItem); 
	bool TryToRemoveItemFromInventory(UInventoryComponent* Inventory, FName ItemID, int32 Amount);
	bool CheckInventoryForItemAmount(UInventoryComponent* Inventory, FName ItemID, int32 Amount);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
public:

	UInventoryComponent* PlayerInventoryComponent;

	// Widget Functions:
	void OpenInventoryWindow();
	void CloseInventoryWindow();
	void OpenContainerWindow();
	void CloseContainerWindow();
	void OpenEquipmentWindow();
	void CloseEquipmentWindow();

	//Inventory functions

	void LoadInventory();
	void CreateInventorySlots(int32 InventorySize, uint8 SlotsPerRow);
	void ClearInventorySlot(int32 InventorySlot);
	void GetInventorySlotItem(int32 InventorySlot);
	void IncreaseInventorySlots(int32 Amount);
	void DecreaseInventorySlots(int32 Amount);
	void AddInventorySlot(int32 Row, int32 Column, int32 Slot);
	void RemoveInventorySlot(int32 InventorySlot);
	void RefreshInventorySlots();
	void ClearInventorySlotItems();

	//Containers

	

	//Hotbar

	

	//Stacks
	
	//TODO SET ITEM AMOUNT 2) ADD TO ITEM AMOUNT 3) Remove From item amount


	//Inventory

	void AddItems(UInventoryComponent* Inventory, int32 InventorySlot, FInventoryItem InventoryItem); 
	void RemoveItems(UInventoryComponent* Inventory, int32 InventorySlot);
	void MoveItem(UInventoryComponent* FromInventory, int32 FromInventorySlot, UInventoryComponent* ToInventory, int32 ToInventorySlot);
	void DropItems(UInventoryComponent* Inventory, int32 InventorySlot);
	bool HasItem(UInventoryComponent* Inventory, FName ItemID, int32& InventorySlot);
	void AddGold(int32 Amount);
	void SplitItem(UInventoryComponent* FromInventory, int32 FromInventorySlot, UInventoryComponent* ToInventory, int32 ToInventorySlot, int32 Amount);
	void IncreaseInventorySize(UInventoryComponent* Inventory, int32 Amount);
	void DecreaseInventorySize(UInventoryComponent* Inventory, int32 Amount);
	bool CheckSlotsForItems(UInventoryComponent* Inventory, int32 Amount);

	//Containers
	void UseContainer(AActor* Container);
	void OpenContainer(AActor* Container);
	void CloseContainer();
	void UseContainerItem(int32 ContainerSlot);

	//Items

	void UseInventoryItem(int32 InventorySlot);
	void UseEquipmentItem(int32 InventorySlot, UInventoryComponent* ToInventory, FInventoryItem InventoryItem); 
	void UseConsumableItem(int32 InventorySlot);

	//Eqipment

	void EquipItem(UInventoryComponent* FromInventory, int32 FromInventorySlot, UInventoryComponent* ToInventory, int32 ToInventorySlot);
	void UnEquipItem(UInventoryComponent* FromInventory, int32 FromInventorySlot, UInventoryComponent* ToInventory, int32 ToInventorySlot);
	void UpdateEquippedStats();

	//UI
	UFUNCTION(Client, Reliable, Category="Inventory|UI")
	void Client_LoadInventoryUI();

	UFUNCTION(Server, Reliable, Category="Inventory|UI")
    void Server_InitializeInventorySlots();
	
};
