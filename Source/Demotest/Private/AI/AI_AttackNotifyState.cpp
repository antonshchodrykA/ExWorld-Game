// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_AttackNotifyState.h"
#include "Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "NPC_Tier2Mob.h"


void UAI_AttackNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	if(MeshComp && MeshComp->GetOwner())
	{
		if(ANPC_Tier2Mob* NPCCharacter = Cast<ANPC_Tier2Mob>(MeshComp->GetOwner()))
		{
			NPCCharacter->Attack_Start();
		}
	}
}
void UAI_AttackNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp && MeshComp->GetOwner())
	{
		if (ANPC_Tier2Mob* NPCCharacter = Cast<ANPC_Tier2Mob>(MeshComp->GetOwner()))
		{
			NPCCharacter->Attack_End();
		}
	}
}
