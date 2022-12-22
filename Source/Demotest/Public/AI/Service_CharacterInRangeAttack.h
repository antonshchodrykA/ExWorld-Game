// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Service_CharacterInRangeAttack.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API UService_CharacterInRangeAttack : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UService_CharacterInRangeAttack(const FObjectInitializer& ObjectInitializer);
	void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere , Category = "ExWorld_NPC")
		float MeleeRange = 25.0f;
	
};
