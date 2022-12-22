// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ai/Services/EXW_BTService_Base.h"
#include "Core/Ai/EXWAiController.h"
#include "Core/EXWCharacter.h"

AEXWAiController* UEXW_BTService_Base::GetAiController(UBehaviorTreeComponent* OwnerComp)
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

AEXWCharacter* UEXW_BTService_Base::GetAiCharacter(UBehaviorTreeComponent* OwnerComp)
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

void UEXW_BTService_Base::SetReferences(UBehaviorTreeComponent& OwnerComp)
{
	// Controller pointer reference
	if (AEXWAiController* AiControllerPtr = Cast<AEXWAiController>(OwnerComp.GetOwner()))
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

void UEXW_BTService_Base::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	SetReferences(OwnerComp);
}
