// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animation/Notify/EXWNotify_AddStateOverrider.h"
#include "Core/EXWCharacter.h"

void UEXWNotify_AddStateOverrider::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
	{
		OwnerCharacter->AddStateOverrider(StateOverriderToAdd);
	}
	Received_Notify(MeshComp, Animation);
}
