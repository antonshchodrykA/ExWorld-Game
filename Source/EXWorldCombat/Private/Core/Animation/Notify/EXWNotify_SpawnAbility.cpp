// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animation/Notify/EXWNotify_SpawnAbility.h"
#include "Core/EXWCharacter.h"
#include "Library/EXWDataLibrary.h"


void UEXWNotify_SpawnAbility::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp->GetOwner())
	{
		if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
		{
			if (OwnerCharacter->IsLocallyControlled())
			{
				OwnerCharacter->MakeSpawnableAbility(RowName);
			}
		}
	}
}

FString UEXWNotify_SpawnAbility::GetNotifyName_Implementation() const
{
	return FString("Spawn Ability [" + RowName.ToString() + "]");
}
