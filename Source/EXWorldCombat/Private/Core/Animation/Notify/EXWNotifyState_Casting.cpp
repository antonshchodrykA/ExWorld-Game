// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWNotifyState_Casting.h"

#include "Core/EXWCharacter.h"
#include "Core/EXWPlayerController.h"




UEXWNotifyState_Casting::UEXWNotifyState_Casting() : Super()
{
}

void UEXWNotifyState_Casting::NotifyBegin(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float TotalDuration)
{
	if (MeshComp->GetOwner())
	{
		OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner());
		if (OwnerCharacter)
		{
			if (OwnerCharacter->IsLocallyControlled())
			{
				Cast<AEXWPlayerController>(OwnerCharacter->GetController())->OnToggleCasting(ActionID,true,TotalDuration);
			}
		}
	}
	Received_NotifyBegin(MeshComp, Animation, TotalDuration);
}

void UEXWNotifyState_Casting::NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	if (OwnerCharacter)
	{
		if (OwnerCharacter->IsLocallyControlled())
		{
			
		}
	}
	Received_NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UEXWNotifyState_Casting::NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation)
{
	if (OwnerCharacter)
	{
		if (OwnerCharacter->IsLocallyControlled())
		{
			if (OwnerCharacter->IsLocallyControlled())
			{
				Cast<AEXWPlayerController>(OwnerCharacter->GetController())->OnToggleCasting(ActionID,false,0.f);
			}
		}
	}
	Received_NotifyEnd(MeshComp, Animation);
}