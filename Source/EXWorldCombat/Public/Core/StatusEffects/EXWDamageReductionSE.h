// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/EXWStatusEffect.h"
#include "Core/DamageTypes/EXWMagicalDamageType.h"
#include "Core/DamageTypes/EXWPhysicalDamageType.h"
#include "EXWDamageReductionSE.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWDamageReductionSE : public AEXWStatusEffect
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Status Effect|Damage Reduction")
	TArray<FEXWDamageReduction> DamageReductions = 
	{
		FEXWDamageReduction(UEXWPhysicalDamageType::StaticClass(), 20.f),
		FEXWDamageReduction(UEXWMagicalDamageType::StaticClass(), 20.f)
	};

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Overridable function called whenever this actor is being removed from a level */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Status Effect|Damage Reduction")
	void ApplyDamageReductionGain();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Status Effect|Damage Reduction")
	void ApplyDamageReductionLoss();
};
