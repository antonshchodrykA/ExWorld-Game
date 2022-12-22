// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Library/EXWDataEnum.h"
#include "Library/EXWDataStruct.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEMOTEST_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	TArray<FInventoryItem> Inventory;
	
	void InitializeInventoryItems(int32 InventorySize, TArray<FInventoryItem> InventoryItems);

	
};
