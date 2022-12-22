// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EXWFloatingWidget.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWFloatingWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, Category = "Widget")
	FText TextToDisplay = FText::FromString("-");

	UPROPERTY(BlueprintReadOnly, Category = "Widget")
	FLinearColor TextColor = FLinearColor(1, 1, 1);
};
