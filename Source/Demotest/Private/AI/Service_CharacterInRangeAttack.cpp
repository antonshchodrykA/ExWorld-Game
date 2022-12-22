// Fill out your copyright notice in the Description page of Project Settings.


#include "Service_CharacterInRangeAttack.h"
#include "NPC_ControllerBase.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "..\..\Public\AI\NPCBlackboardKeys.h"
#include "GameFramework/Character.h"
#include "NPC_CharacterBase.h"


UService_CharacterInRangeAttack::UService_CharacterInRangeAttack(const FObjectInitializer& ObjectInitializer)
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Character In Range?");
}
void UService_CharacterInRangeAttack::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComponent, NodeMemory);
	const ANPC_ControllerBase* BaseController = Cast<ANPC_ControllerBase>(OwnerComponent.GetAIOwner());
	ANPC_CharacterBase* CharacterBase = Cast<ANPC_CharacterBase>(BaseController->GetPawn());
	if (BaseController && CharacterBase)
	{
		const ACharacter* Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
		BaseController->GetBlackboardComponent()->SetValueAsBool(ExWorldNPC_bbkeys::CharacterInRangeMelee, CharacterBase->GetDistanceTo(Player) <= MeleeRange);
	}
}
