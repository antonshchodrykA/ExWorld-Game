// Fill out your copyright notice in the Description page of Project Settings.


#include "EXW_BTTask_SetMovementSpeed.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Core/EXWCharacter.h"

UEXW_BTTask_SetMovementSpeed::UEXW_BTTask_SetMovementSpeed()
{
	NodeName = "Set Movement Speed";
}

EBTNodeResult::Type UEXW_BTTask_SetMovementSpeed::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AEXWCharacter* Character = GetAiCharacter(&OwnerComp))
	{
		// Pretty sure all the ACharacter instances contain a valid CharacterMovementComponent
		Cast<UCharacterMovementComponent>(Character->GetMovementComponent())->MaxWalkSpeed = NewMovementSpeed;
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}

FString UEXW_BTTask_SetMovementSpeed::GetStaticDescription() const
{
	return FString("New movement speed value : " + FString::SanitizeFloat(NewMovementSpeed));
}
