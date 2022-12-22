// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_SwitchPoints.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API UBTTask_SwitchPoints : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_SwitchPoints(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);

private:
	enum class EDirection
	{
		Forward,Reverse
	};
	
	EDirection Direction = EDirection::Forward;
};
