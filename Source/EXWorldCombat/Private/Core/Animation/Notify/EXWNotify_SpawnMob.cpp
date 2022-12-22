// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWNotify_SpawnMob.h"
#include "Core/EXWCharacter.h"

void UEXWNotify_SpawnMob::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp->GetOwner())
	{
		if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
		{
			for (int32 i = 0; i < MobsToSpawn; i++)
			{
				OwnerCharacter->SpawnAiCharacter(Mob, BehaviorTree, MinSpawnLocation, MaxSpawnLocation, Level, RoamRadius);
			}
		}
	}
}
