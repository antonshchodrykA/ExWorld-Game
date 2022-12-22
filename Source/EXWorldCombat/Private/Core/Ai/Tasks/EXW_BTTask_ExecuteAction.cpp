// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ai/Tasks/EXW_BTTask_ExecuteAction.h"
#include "Core/EXWCharacter.h"
#include "BehaviorTree/BTFunctionLibrary.h"

UEXW_BTTask_ExecuteAction::UEXW_BTTask_ExecuteAction()
{
	NodeName = "Execute Action";
}

EBTNodeResult::Type UEXW_BTTask_ExecuteAction::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (FBTNodeBPImplementationHelper::AISpecific)
	{
		Super::ExecuteTask(OwnerComp, NodeMemory);
		if (AEXWCharacter* Character = GetAiCharacter(&OwnerComp))
		{
			if (Character->ExecuteActionByDT(ActionRowName) == EEXWActionExecutionResult::AER_Success)
			{
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}

FString UEXW_BTTask_ExecuteAction::GetStaticDescription() const
{
	return "Execute Action : " + ActionRowName.ToString();
}
