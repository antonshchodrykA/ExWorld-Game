// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/EXWStatusEffect.h"
#include "EXWWorshipSE.generated.h"

class AALSBaseCharacter;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWWorshipSE : public AEXWStatusEffect
{
	GENERATED_BODY()
	/* TODO
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Status Effect|Damage Reduction")
	float MPRegen = 2.0f;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Status Effect")
		AALSBaseCharacter* GetTargetALSBaseCharacter();

private:

	TWeakObjectPtr<AALSBaseCharacter> ALSBaseCharacter;

	float IdleTimer = 0.0f;

	bool bIsIdle = false;*/
};
