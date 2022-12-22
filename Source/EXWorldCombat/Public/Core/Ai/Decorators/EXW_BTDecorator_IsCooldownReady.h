// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Ai/Decorators/EXW_BTDecorator_Base.h"
#include "EXW_BTDecorator_IsCooldownReady.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXW_BTDecorator_IsCooldownReady : public UEXW_BTDecorator_Base
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	FName AbilityID = "Ability_ID_Here";
	
	UEXW_BTDecorator_IsCooldownReady();

protected:

	/** calculates raw, core value of decorator's condition. Should not include calling IsInversed */
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	virtual FString GetStaticDescription() const override;
};
