// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_NPCMeleeAttack.h"
#include "NPC_CharacterBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "Animation/AnimInstance.h"
#include "..\..\Public\AI\NPCBlackboardKeys.h"
#include "AIController.h"


UBTTask_NPCMeleeAttack::UBTTask_NPCMeleeAttack(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("Melee Attack");
}
EBTNodeResult::Type UBTTask_NPCMeleeAttack::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	AAIController* Controller = Cast<AAIController>(owner_comp.GetAIOwner());
	ANPC_CharacterBase* CharacterBase = Cast<ANPC_CharacterBase>(Controller->GetPawn());
	
		if (Controller)
		{
			if(MeleeMontageEnded(CharacterBase))
			{
				//CharacterBase->NPC_MeleeAttack_Implementation();
				CharacterBase->NPC_MeleeAttack();
				
			}
			
			FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
		FinishLatentTask(owner_comp, EBTNodeResult::Failed);
		return EBTNodeResult::Failed;
}

bool UBTTask_NPCMeleeAttack::MeleeMontageEnded(ANPC_CharacterBase* NPC_Character)
{
	return NPC_Character->GetMesh()->GetAnimInstance()->Montage_GetIsStopped(NPC_Character->GetNPC_AnimMontage());
}
