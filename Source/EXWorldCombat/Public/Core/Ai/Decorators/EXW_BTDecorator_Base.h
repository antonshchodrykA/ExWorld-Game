// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "EXW_BTDecorator_Base.generated.h"


class AEXWCharacter;
class AEXWAiController;
/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXW_BTDecorator_Base : public UBTDecorator
{
	GENERATED_BODY()

public:

	AEXWAiController* GetAiController(UBehaviorTreeComponent* OwnerComp) const;

	AEXWCharacter* GetAiCharacter(UBehaviorTreeComponent* OwnerComp) const;
};
