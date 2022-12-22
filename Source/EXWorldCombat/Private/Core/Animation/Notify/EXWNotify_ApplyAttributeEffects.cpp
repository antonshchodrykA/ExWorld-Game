// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animation/Notify/EXWNotify_ApplyAttributeEffects.h"
#include "Core/EXWCharacter.h"

void UEXWNotify_ApplyAttributeEffects::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp)
	{
		if (AEXWCharacter* Character = Cast<AEXWCharacter>(MeshComp->GetOwner()))
		{
			if (Character->IsLocallyControlled())
			{
				Character->Replicated_ApplyAttributeMultiEffects(Character, AttributeEffects);
			}
		}
	}
	Received_Notify(MeshComp, Animation);
}
