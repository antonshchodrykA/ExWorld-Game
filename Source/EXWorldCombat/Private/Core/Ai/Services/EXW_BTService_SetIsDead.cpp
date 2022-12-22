// Fill out your copyright notice in the Description page of Project Settings.


#include "EXW_BTService_SetIsDead.h"
#include "Core/EXWCharacter.h"

// BT
#include "BehaviorTree/BlackboardComponent.h"

void UEXW_BTService_SetIsDead::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	/*TickNode(OwnerComp, NodeMemory, DeltaSeconds);*/
	if (AEXWCharacter* CharacterTemp = GetAiCharacter(&OwnerComp))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(IsDeadKey.SelectedKeyName, CharacterTemp->IsDead());
	}
}
