// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/NPC_ControllerBase.h"
#include "NPC_Tier2Controller.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API ANPC_Tier2Controller : public ANPC_ControllerBase
{
	GENERATED_BODY()
	
public:
	ANPC_Tier2Controller(const FObjectInitializer& ObjectInitializer);

	void Senses_OnTargetUpdated(AActor* Target, const FAIStimulus Stimulus) override;

};
