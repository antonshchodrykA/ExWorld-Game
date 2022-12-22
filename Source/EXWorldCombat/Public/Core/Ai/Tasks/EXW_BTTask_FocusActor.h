// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Ai/Tasks/EXW_BTTask_Base.h"
#include "EXW_BTTask_FocusActor.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXW_BTTask_FocusActor : public UEXW_BTTask_Base
{
	GENERATED_BODY()
	

public:


	UPROPERTY(Category = EXWorld, EditAnywhere)
	uint8 bClearFocus : 1;

	UPROPERTY(Category = EXWorld, EditAnywhere, meta = (EditCondition = "!bClearFocus"))
	FBlackboardKeySelector ActorKey;

	UEXW_BTTask_FocusActor();

protected:

	/** starts this task, should return Succeeded, Failed or InProgress
	 *  (use FinishLatentTask() when returning InProgress)
	 * this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	virtual FString GetStaticDescription() const override;
};
