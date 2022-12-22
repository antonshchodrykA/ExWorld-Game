// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ai/Decorators/EXW_BTDecorator_IsCooldownReady.h"
#include "Core/EXWCharacter.h"

UEXW_BTDecorator_IsCooldownReady::UEXW_BTDecorator_IsCooldownReady()
{
	NodeName = "Is cooldown ready?";
}

bool UEXW_BTDecorator_IsCooldownReady::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (AEXWCharacter* CharacterTemp = GetAiCharacter(&OwnerComp))
	{
		return CharacterTemp->IsCooldownReady(AbilityID);
	}
	return false;
}

FString UEXW_BTDecorator_IsCooldownReady::GetStaticDescription() const
{
	return FString("Is cooldown of " + AbilityID.ToString() + " ready?");
}
