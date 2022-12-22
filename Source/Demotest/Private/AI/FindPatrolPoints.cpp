// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPatrolPoints.h"
#include "NPC_Tier2Controller.h"
#include "NPC_CharacterBase.h"
#include "..\..\Public\AI\NPCBlackboardKeys.h"
#include "ExWorldLog.h"
#include "BehaviorTree/BlackboardComponent.h"

UFindPatrolPoints::UFindPatrolPoints(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Find Patrol Points");
}

EBTNodeResult::Type UFindPatrolPoints::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	const ANPC_Tier2Controller* Tier2Controller = Cast<ANPC_Tier2Controller>(owner_comp.GetAIOwner());
	if (Tier2Controller) {
		const int index = Tier2Controller->GetBlackboardComponent()->GetValueAsInt(ExWorldNPC_bbkeys::PatrolPointsIndex);
		ANPC_CharacterBase* NPCCharacter = Cast<ANPC_CharacterBase>(Tier2Controller->GetPawn());
		if(NPCCharacter)
		{
			const FVector Points = NPCCharacter->GetPatrolPoints_Refer()->GetPatrolPoints(index);
			const FVector GlobalPoints = NPCCharacter->GetPatrolPoints_Refer()->GetActorTransform().TransformPosition(Points);
			Tier2Controller->GetBlackboardComponent()->SetValueAsVector(ExWorldNPC_bbkeys::PatrolPoints, GlobalPoints);
			FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	}
	FinishLatentTask(owner_comp, EBTNodeResult::Failed);
	return EBTNodeResult::Failed;
	
}
