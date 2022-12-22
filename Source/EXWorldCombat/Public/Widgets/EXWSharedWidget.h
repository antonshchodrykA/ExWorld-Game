// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EXWSharedWidget.generated.h"

class AEXWCharacter;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWSharedWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Widget")
	AActor* Interactable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Widget")
	AEXWCharacter* SourceCharacter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Widget")
	AEXWCharacter* TargetCharacter;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Widget")
	void InitializeWidget(AEXWCharacter* InSourceCharacter, AEXWCharacter* InTargetCharacter, const bool bAddToViewport = true);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Widget")
	void OnFinishInitialisation();
	virtual void OnFinishInitialisation_Native();
};