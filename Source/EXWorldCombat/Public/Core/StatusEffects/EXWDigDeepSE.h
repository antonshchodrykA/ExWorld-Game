// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/EXWStatusEffect.h"
#include "EXWDigDeepSE.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWDigDeepSE : public AEXWStatusEffect
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Attributes")
	void IncreaseDamage(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Attributes")
	void DecreaseDamage(EEXWAttributeType AttributeType, float Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Status Effect|Magic Damage")
	float OriginalDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Status Effect|Magic Damage")
	float DamageIncreasePerManaLost = 0.5f;
};
