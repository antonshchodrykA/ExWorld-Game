// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ChasePlayer.h"
#include "NPC_ControllerBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "..\..\Public\AI\NPCBlackboardKeys.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

UBTTask_ChasePlayer::UBTTask_ChasePlayer(const FObjectInitializer& ObjectInitializer)

{

	NodeName = TEXT("ChasePlayerImproved");
}
EBTNodeResult::Type UBTTask_ChasePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	auto const controller = Cast<ANPC_ControllerBase>(OwnerComponent.GetAIOwner());
	if(controller)
	{
		const FVector PlayerLoc = controller->GetBlackboardComponent()->GetValueAsVector(ExWorldNPC_bbkeys::target_location);
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(controller,PlayerLoc);
		FinishLatentTask(OwnerComponent, EBTNodeResult::Succeeded);
		return EBTNodeResult::Succeeded;
	}

	FinishLatentTask(OwnerComponent, EBTNodeResult::Failed);
	return EBTNodeResult::Failed;
}
