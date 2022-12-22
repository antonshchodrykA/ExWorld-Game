// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/InventoryComponent.h"
#include "DemotestCharacter.h"
#include "EquipmentInventoryComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DEMOTEST_API UEquipmentInventoryComponent : public UInventoryComponent
{
	GENERATED_BODY()

public:
	//Will be casted and called in player controller
	ADemotestCharacter* BaseCharacterRefer;
	
};
