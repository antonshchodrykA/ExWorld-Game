// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/EXWStatusEffect.h"
#include "Library/EXWDataEnum.h"
#include "EXWStateSE.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWStateSE : public AEXWStatusEffect
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Status Effect|State")
	EEXWState State;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Overridable function called whenever this actor is being removed from a level */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Status Effect|State")
	void ApplyState();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Status Effect|State")
	void ClearState();
	
};
