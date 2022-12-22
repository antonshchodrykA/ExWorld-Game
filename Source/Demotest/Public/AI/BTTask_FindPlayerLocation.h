// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindPlayerLocation.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class DEMOTEST_API UBTTask_FindPlayerLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_FindPlayerLocation(const FObjectInitializer& ObjectInitializer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorld_NPC", meta = (AllowProtectedAccess = "true"))
		bool NPC_SearchRandom = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorld_NPC", meta = (AllowProtectedAccess = "true"))
		float NPC_SearchPlayerRadius = 150.0f;

};
