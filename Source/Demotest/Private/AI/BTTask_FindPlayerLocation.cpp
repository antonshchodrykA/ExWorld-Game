// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "NPC_ControllerBase.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "..\..\Public\AI\NPCBlackboardKeys.h"
#include "ExWorldLog.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

UBTTask_FindPlayerLocation::UBTTask_FindPlayerLocation(const FObjectInitializer& ObjectInitializer) {

	NodeName = TEXT("NPC Find Player Location");

}
EBTNodeResult::Type UBTTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	const ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	auto const Controller = Cast<ANPC_ControllerBase>(owner_comp.GetAIOwner());
	FVector PlayerLocation;
	if (Controller && NPC_SearchRandom && Player)
	{
		PlayerLocation = Player->GetActorLocation();
		FNavLocation NavLoc;
		const UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld());
		if (NavigationSystem->GetRandomPointInNavigableRadius(PlayerLocation, NPC_SearchPlayerRadius, NavLoc, nullptr)) {
			Controller->GetBlackboardComponent()->SetValueAsVector(ExWorldNPC_bbkeys::target_location, NavLoc.Location);
		}
	}
	else if (Player)
	{
		EXWORLDLOG("Random Search Is Off !!")
			Controller->GetBlackboardComponent()->SetValueAsVector(ExWorldNPC_bbkeys::target_location, PlayerLocation);


	}

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
