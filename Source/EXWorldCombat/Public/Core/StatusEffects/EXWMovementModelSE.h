// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/EXWStatusEffect.h"
#include "EXWMovementModelSE.generated.h"

class AALSBaseCharacter;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWMovementModelSE : public AEXWStatusEffect
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Status Effect|Damage Reduction")
	FDataTableRowHandle MovementModel;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Overridable function called whenever this actor is being removed from a level */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void Tick(float DeltaTime) override;

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Status Effect")
	AALSBaseCharacter* GetTargetALSBaseCharacter();

private:

	TWeakObjectPtr<AALSBaseCharacter> ALSBaseCharacter;

	FDataTableRowHandle PreviousMovementModel;
};
