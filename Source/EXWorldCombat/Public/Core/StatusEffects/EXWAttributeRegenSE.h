// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/EXWStatusEffect.h"
#include "EXWAttributeRegenSE.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWAttributeRegenSE : public AEXWStatusEffect
{
	GENERATED_BODY()

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
