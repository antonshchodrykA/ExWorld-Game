// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/EXWStatusEffect.h"
#include "EXWFuryOfTheDeadSE.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWFuryOfTheDeadSE : public AEXWStatusEffect
{
	GENERATED_BODY()


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Status Effect|Stack")
	FName RowName = "Undead_FuryOfTheDead";

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Status Effect|Stack")
	void AddStack(EEXWState State);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Status Effect|Stack")
	void RemoveStack(EEXWState State);

};
