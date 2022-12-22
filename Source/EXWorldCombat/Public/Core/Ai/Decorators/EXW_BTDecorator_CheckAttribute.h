// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Ai/Decorators/EXW_BTDecorator_Base.h"
#include "Library/EXWDataEnum.h"
#include "EXW_BTDecorator_CheckAttribute.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXW_BTDecorator_CheckAttribute : public UEXW_BTDecorator_Base
{
	GENERATED_BODY()
	

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	EEXWAttributeType AttributeType = EEXWAttributeType::Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	EEXWValueComparaisonType ComparaisonType = EEXWValueComparaisonType::VC_IsLess;

	/**
	 * Whether to compare to the concrete value or to the percentage of what the character currently has.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	uint8 bUsePercentage : 1;

	/** If UsePercentage is false, this will be a set value independent from total attribute value of the character, 
	 *  in case UsePercentage is true, this will be dependent on how much % the character has as a current value.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	float ValueToCompareTo = 10.f;

	UEXW_BTDecorator_CheckAttribute();

protected:

	/** calculates raw, core value of decorator's condition. Should not include calling IsInversed */
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	virtual FString GetStaticDescription() const override;

};
