// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/Ai/Services/EXW_BTService_SetTargetLocation.h"

// BT
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"

void UEXW_BTService_SetTargetLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if (UObject* TargetObject = OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetKey.SelectedKeyName))
	{
		if (AActor* TargetActor = Cast<AActor>(TargetObject))
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(LocationKey.SelectedKeyName, TargetActor->GetActorLocation());
		}
	}
}
