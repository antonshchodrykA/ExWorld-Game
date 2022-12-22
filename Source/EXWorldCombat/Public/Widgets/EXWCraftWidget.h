// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Library/Inventory/EXWInventoryEnum.h"
#include "EXWCraftWidget.generated.h"


class AEXWPlaceableCraftStation;
/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWCraftWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Data")
	EEXWCraftCategory CraftCategory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Data")
	AEXWPlaceableCraftStation* CraftStation;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "EXWorld|Craft")
	void InitCraftWidget();
};
