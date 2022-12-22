// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "EXW_BTTask_Base.generated.h"

class AEXWAiController;
class AEXWCharacter;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXW_BTTask_Base : public UBTTaskNode
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Ai")
	AEXWAiController* GetAiController(UBehaviorTreeComponent* OwnerComp);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Ai")
	AEXWCharacter* GetAiCharacter(UBehaviorTreeComponent* OwnerComp);

protected:

	virtual void SetReferences(UBehaviorTreeComponent& OwnerComp);

private:

	UPROPERTY()
	TWeakObjectPtr<AEXWAiController> AiController;

	UPROPERTY()
	TWeakObjectPtr<AEXWCharacter> AiCharacter;
};
