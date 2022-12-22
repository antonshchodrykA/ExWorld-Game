// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_SwitchPoints.h"
#include "NPC_Tier2Controller.h"
#include "NPC_CharacterBase.h"
#include "..\..\Public\AI\NPCBlackboardKeys.h"
#include "ExWorldLog.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTTask_SwitchPoints::UBTTask_SwitchPoints(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Switching Points ++");

}
EBTNodeResult::Type UBTTask_SwitchPoints::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	const ANPC_Tier2Controller* Tier2Controller = Cast<ANPC_Tier2Controller>(owner_comp.GetAIOwner());
	if(Tier2Controller)
	{
		ANPC_CharacterBase* NPCCharacter = Cast<ANPC_CharacterBase>(Tier2Controller->GetPawn());
		if(NPCCharacter)
		{
			const int Count = NPCCharacter->GetPatrolPoints_Refer()->PatrolPonitsCount();
			const int min_index = 0;
			const int max_index = Count - 1;
			int index = Tier2Controller->GetBlackboardComponent()->GetValueAsInt(ExWorldNPC_bbkeys::PatrolPointsIndex);
			if(index >= max_index && Direction == EDirection::Forward)
			{
				Direction = EDirection::Reverse;
			}

			else if(index == min_index && Direction == EDirection::Reverse)
			{
				Direction = EDirection::Forward;
			}
			Tier2Controller->GetBlackboardComponent()->SetValueAsInt(ExWorldNPC_bbkeys::PatrolPointsIndex, (Direction == EDirection::Forward ? ++index : --index) % Count);
			FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	}
	FinishLatentTask(owner_comp, EBTNodeResult::Failed);
	return EBTNodeResult::Failed;
}
