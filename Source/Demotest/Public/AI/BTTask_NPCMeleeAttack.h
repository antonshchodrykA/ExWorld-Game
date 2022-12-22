// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPC_CharacterBase.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_NPCMeleeAttack.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API UBTTask_NPCMeleeAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTTask_NPCMeleeAttack(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory) override;

private:
	bool MeleeMontageEnded(ANPC_CharacterBase* NPC_Character);
	
};
