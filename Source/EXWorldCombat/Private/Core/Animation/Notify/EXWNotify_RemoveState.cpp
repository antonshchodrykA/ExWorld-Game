// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animation/Notify/EXWNotify_RemoveState.h"
#include "Core/EXWcharacter.h"

void UEXWNotify_RemoveState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
	{
		OwnerCharacter->RemoveState(StateToRemove);
	}
}
