// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "GameFramework/Pawn.h"
#include "UObject/UObjectGlobals.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_FindLocation.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DEMOTEST_API UBTTask_FindLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	//Drag into the tree and will be set
	UBTTask_FindLocation(const FObjectInitializer& ObjectInitializer);

		//Execute the task
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);


private:

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "ExWorld_NPC", meta = (AllowPrivateAccess = "true"))
		float NPC_SearchRadius = 1500.0f;

};
