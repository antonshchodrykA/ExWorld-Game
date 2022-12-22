// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Ai/Tasks/EXW_BTTask_Base.h"
#include "EXW_BTTask_ExecuteAction.generated.h"

/**
 * 
 */
UCLASS(Category = EXWorld, meta = (DisplayName = "Execute Action"))
class EXWORLDCOMBAT_API UEXW_BTTask_ExecuteAction : public UEXW_BTTask_Base
{
	GENERATED_BODY()
	
public:

	/** Maximum distance the random location picked may be from pawn. */
	UPROPERTY(Category = EXWorld, EditAnywhere)
	FName ActionRowName = FName(TEXT("Insert_Row_Name_Here"));
	
	UEXW_BTTask_ExecuteAction();

protected:

	/** starts this task, should return Succeeded, Failed or InProgress
	 *  (use FinishLatentTask() when returning InProgress)
	 * this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

	virtual FString GetStaticDescription() const override;

};
