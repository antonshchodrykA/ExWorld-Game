// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "EXW_BTService_Base.generated.h"


class AEXWAiController;
class AEXWCharacter;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXW_BTService_Base : public UBTService
{
	GENERATED_BODY()
	
public:

	AEXWAiController* GetAiController(UBehaviorTreeComponent* OwnerComp);

	AEXWCharacter* GetAiCharacter(UBehaviorTreeComponent* OwnerComp);

protected: 

	virtual void SetReferences(UBehaviorTreeComponent& OwnerComp);

	/** called when auxiliary node becomes active
	* this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:

	UPROPERTY()
	TWeakObjectPtr<AEXWAiController> AiController;

	UPROPERTY()
	TWeakObjectPtr<AEXWCharacter> AiCharacter;
};
