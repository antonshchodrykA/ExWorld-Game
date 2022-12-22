// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ai/Decorators/EXW_BTDecorator_CheckAttribute.h"
#include "Core/EXWCharacter.h"

UEXW_BTDecorator_CheckAttribute::UEXW_BTDecorator_CheckAttribute()
{
	NodeName = "Check Attribute";
}

bool UEXW_BTDecorator_CheckAttribute::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (AEXWCharacter* CharacterTemp = GetAiCharacter(&OwnerComp))
	{
		float OutValue = -1.f;
		if (bUsePercentage)
		{
			if (!CharacterTemp->GetAttributePercentage(AttributeType, OutValue))
			{
				return false;
			}
			OutValue *= 100.f;
		}
		else
		{
			if (!CharacterTemp->GetAttributeCurrentValue(AttributeType, OutValue))
			{
				return false;
			}
		}
		if (OutValue == ValueToCompareTo && ComparaisonType == EEXWValueComparaisonType::VC_IsEqual)
		{
			return true;
		}
		else if (OutValue < ValueToCompareTo && ComparaisonType == EEXWValueComparaisonType::VC_IsLess)
		{
			return true;
		}
		else if (OutValue > ValueToCompareTo && ComparaisonType == EEXWValueComparaisonType::VC_IsMore)
		{
			return true;
		}
	}
	return false;
}

FString UEXW_BTDecorator_CheckAttribute::GetStaticDescription() const
{
	int32 Index = -1;
	FString AttributeString = UEnum::GetValueAsString<EEXWAttributeType>(AttributeType);
	if (AttributeString.FindLastChar(':', Index))
	{
		AttributeString.RemoveAt(0, Index + 1);
	}

	FString ComparaisonString = UEnum::GetValueAsString<EEXWValueComparaisonType>(ComparaisonType);
	if (ComparaisonString.FindLastChar('_', Index))
	{
		ComparaisonString.RemoveAt(0, Index + 1);
	}

	return FString("Check if " + AttributeString + " " +
		ComparaisonString + " than " +
		FString::SanitizeFloat(ValueToCompareTo) + FString(bUsePercentage ? "%" : ""));
}
