// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWNotify_SpawnStatusEffect.h"
#include "Core/EXWCharacter.h"

void UEXWNotify_SpawnStatusEffect::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp->GetOwner())
	{
		if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
		{
			if (OwnerCharacter->IsLocallyControlled())
			{
				OwnerCharacter->Server_ConstructStatusEffect(RowName, OwnerCharacter, OwnerCharacter);
			}
		}
	}
}

FString UEXWNotify_SpawnStatusEffect::GetNotifyName_Implementation() const
{
	return FString("Spawn Status Effect [" + RowName.ToString() + "]");
}
