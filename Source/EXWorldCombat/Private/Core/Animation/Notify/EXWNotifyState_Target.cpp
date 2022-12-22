// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animation/Notify/EXWNotifyState_Target.h"
#include "Core/EXWCharacter.h"

void UEXWNotifyState_Target::NotifyBegin(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float TotalDuration)
{
	if (MeshComp->GetOwner())
	{
		if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
		{
			if (OwnerCharacter->IsLocallyControlled())
			{
				OwnerCharacter->StartTargeting(TargetingParams);
			}	
		}	
	}
	Received_NotifyBegin(MeshComp, Animation, TotalDuration);
}

void UEXWNotifyState_Target::NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Received_NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UEXWNotifyState_Target::NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation)
{
	if (MeshComp->GetOwner())
	{
		if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
		{
			if (OwnerCharacter->IsLocallyControlled())
			{
				OwnerCharacter->StopTargeting();
			}
		}
	}
	Received_NotifyEnd(MeshComp, Animation);
}
