// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Library/EXWDataStruct.h"
#include "EXWNPCShopWidget.generated.h"

struct FEXWShop;
class AEXWCharacter;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNPCShopWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Data")
	FName ShopID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Data")
	FEXWShop Shop;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Data")
	AEXWCharacter* ShopOwner;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Data")
	void LoadShopData();
	
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Widget")
	void ExitShop();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "EXWorld|Shop")
	void InitShop();

};
