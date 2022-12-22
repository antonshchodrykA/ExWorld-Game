// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "NPC_ControllerBase.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "..\..\Public\AI\NPCBlackboardKeys.h"
#include "ExWorldLog.h"


UBTTask_FindLocation::UBTTask_FindLocation(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Move Randomly");
}
EBTNodeResult::Type UBTTask_FindLocation::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	auto const controller = Cast<ANPC_ControllerBase>(owner_comp.GetAIOwner());
	if(controller)
	{
		auto const NPC_Pawn = controller->GetPawn();
		const FVector NPC_LocationOrigin = NPC_Pawn->GetActorLocation();
		FNavLocation NavMesh_Location;

		const UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
		if(NavigationSystem->GetRandomPointInNavigableRadius(NPC_LocationOrigin,NPC_SearchRadius,NavMesh_Location,nullptr))
		{
			controller->GetBlackboardComponent()->SetValueAsVector(ExWorldNPC_bbkeys::target_location, NavMesh_Location.Location);
			FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	


	}
	//Get Pawn
	EXWORLDLOG("AI Controller NOT CASTING");
	return EBTNodeResult::Failed;
}

