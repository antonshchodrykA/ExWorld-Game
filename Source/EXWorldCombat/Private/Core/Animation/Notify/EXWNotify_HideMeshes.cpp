// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animation/Notify/EXWNotify_HideMeshes.h"
#include "Core/EXWCharacter.h"

void UEXWNotify_HideMeshes::NotifyBegin(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float TotalDuration)
{
	if (MeshComp->GetOwner())
	{
		if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
		{
			OwnerCharacter->SetAllMeshVisibility(false);
		}
	}
	Received_NotifyBegin(MeshComp, Animation, TotalDuration);
}

void UEXWNotify_HideMeshes::NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Received_NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UEXWNotify_HideMeshes::NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation)
{
	if (MeshComp->GetOwner())
	{
		if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
		{
			OwnerCharacter->SetAllMeshVisibility(true);
		}
	}
	Received_NotifyEnd(MeshComp, Animation);
}
