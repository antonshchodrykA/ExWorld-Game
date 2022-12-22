// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPC_CharacterBase.h"
#include "NPC_Tier1Mob.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API ANPC_Tier1Mob : public ANPC_CharacterBase
{
	GENERATED_BODY()
public:

	ANPC_Tier1Mob(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
};
