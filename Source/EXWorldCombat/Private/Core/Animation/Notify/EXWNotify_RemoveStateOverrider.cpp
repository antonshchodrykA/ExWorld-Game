// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animation/Notify/EXWNotify_RemoveStateOverrider.h"
#include "Core/EXWCharacter.h"

void UEXWNotify_RemoveStateOverrider::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
	{
		OwnerCharacter->RemoveStateOverrider(StateOverriderToRemove);
	}
	Received_Notify(MeshComp, Animation);
}
