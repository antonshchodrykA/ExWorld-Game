// Fill out your copyright notice in the Description page of Project Settings.


#include "Service_ChangeNPCMovement.h"
#include "NPC_CharacterBase.h"
#include "AIController.h"
#include "GameFramework/CharacterMovementComponent.h"

UService_ChangeNPCMovement::UService_ChangeNPCMovement(const FObjectInitializer& ObjectInitializer)
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("NPC Movement Speed");
}
void UService_ChangeNPCMovement::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComponent, NodeMemory);
	auto const controller = OwnerComponent.GetAIOwner();
	ANPC_CharacterBase* NPCChar = Cast<ANPC_CharacterBase>(controller->GetPawn());
	NPCChar->GetCharacterMovement()->MaxWalkSpeed = NPC_Speed;
}

FString UService_ChangeNPCMovement::GetStaticServiceDescription() const
{
	return FString("NPC Character Speed Change");
}

