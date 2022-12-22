// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ai/Decorators/EXW_BTDecorator_Base.h"
#include "Core/Ai/EXWAiController.h"
#include "Core/EXWCharacter.h"

AEXWAiController* UEXW_BTDecorator_Base::GetAiController(UBehaviorTreeComponent* OwnerComp) const
{
	TWeakObjectPtr<AEXWAiController> AiController;
	// Controller pointer reference
	if (AEXWAiController* AiControllerPtr = Cast<AEXWAiController>(OwnerComp->GetOwner()))
	{
		AiController = MakeWeakObjectPtr<AEXWAiController>(AiControllerPtr);
	}
	return AiController.Get();
}

AEXWCharacter* UEXW_BTDecorator_Base::GetAiCharacter(UBehaviorTreeComponent* OwnerComp) const
{
	TWeakObjectPtr<AEXWCharacter> AiCharacter;
	if (AEXWAiController* AiControllerPtr = GetAiController(OwnerComp))
	{
		if (AEXWCharacter* AiCharacterPtr = Cast<AEXWCharacter>(AiControllerPtr->GetPawn()))
		{
			AiCharacter = MakeWeakObjectPtr<AEXWCharacter>(AiCharacterPtr);
		}
	}
	return AiCharacter.Get();
}
