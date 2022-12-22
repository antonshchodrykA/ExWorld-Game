// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BTTask_ChasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API UBTTask_ChasePlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTTask_ChasePlayer(const FObjectInitializer& ObjectInitializer);
	
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory);
	
};
