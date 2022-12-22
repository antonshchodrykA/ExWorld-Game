// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Inventory/EXWPlaceable.h"
#include "Library/Inventory/EXWInventoryEnum.h"
#include "EXWPlaceableCraftStation.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWPlaceableCraftStation : public AEXWPlaceable
{
	GENERATED_BODY()

	

public:
	AEXWPlaceableCraftStation();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="EXWorld|Placeable")
	EEXWCraftCategory CraftCategory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EXWorld|Placeable")
	TMap<EEXWLifeSkillType, int32> Experiences;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EXWorld|Placeable")
	float CraftingDuration = 3.f;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Station")
	void StartCrafting(AEXWCharacter* SourceCharacter, const FName CraftID = "None");

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Station")
	void StopCrafting(AEXWCharacter* SourceCharacter, const FName CraftID = "None");

	virtual void OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType) override;

private:
	FTimerHandle CraftingTimerHandle;
};
