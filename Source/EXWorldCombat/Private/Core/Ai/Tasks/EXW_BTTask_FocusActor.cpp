// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ai/Tasks/EXW_BTTask_FocusActor.h"
#include "Core/Ai/EXWAiController.h"
#include "BehaviorTree/BTFunctionLibrary.h"

// BT
#include "BehaviorTree/BlackboardComponent.h"

UEXW_BTTask_FocusActor::UEXW_BTTask_FocusActor()
{
	NodeName = "Focus or Clear Actor";
}

EBTNodeResult::Type UEXW_BTTask_FocusActor::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (FBTNodeBPImplementationHelper::AISpecific)
	{
		if (AEXWAiController* ControllerTemp = GetAiController(&OwnerComp))
		{
			if (!bClearFocus)
			{
				if (AActor* ActorKeyValue = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(ActorKey.SelectedKeyName)))
				{
					ControllerTemp->SetFocus(ActorKeyValue, EAIFocusPriority::Default);
					return EBTNodeResult::Succeeded;
				}
			}
			else
			{
				ControllerTemp->ClearFocus(EAIFocusPriority::Default);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}

FString UEXW_BTTask_FocusActor::GetStaticDescription() const
{
	return (!bClearFocus) ? FString("Focus " + ActorKey.SelectedKeyName.ToString()) : FString ("Clear Focus");
}
