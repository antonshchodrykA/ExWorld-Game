// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ai/Tasks/EXW_BTTask_Base.h"
#include "Core/Ai/EXWAiController.h"
#include "Core/EXWCharacter.h"

AEXWAiController* UEXW_BTTask_Base::GetAiController(UBehaviorTreeComponent* OwnerComp)
{
	if (AiController.IsValid())
	{
		return AiController.Get();
	}
	else
	{
		SetReferences(*OwnerComp);
		return (AiController.IsValid()) ? AiController.Get() : nullptr;
	}
	return nullptr;
}

AEXWCharacter* UEXW_BTTask_Base::GetAiCharacter(UBehaviorTreeComponent* OwnerComp)
{
	if (AiCharacter.IsValid())
	{
		return AiCharacter.Get();
	}
	else
	{
		SetReferences(*OwnerComp);
		return (AiCharacter.IsValid()) ? AiCharacter.Get() : nullptr;
	}
	return nullptr;
}

void UEXW_BTTask_Base::SetReferences(UBehaviorTreeComponent& OwnerComp)
{
	// Controller pointer reference
	if (AEXWAiController* AiControllerPtr = Cast<AEXWAiController>(OwnerComp.GetAIOwner()))
	{
		AiController = MakeWeakObjectPtr<AEXWAiController>(AiControllerPtr);
		
		// Character  pointer reference
		if (AiControllerPtr->GetPawn())
		{
			if (AEXWCharacter* AiCharacterPtr = Cast<AEXWCharacter>(AiControllerPtr->GetPawn()))
			{
				AiCharacter = MakeWeakObjectPtr<AEXWCharacter>(AiCharacterPtr);
			}
		}
	}
}
