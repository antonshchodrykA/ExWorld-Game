// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWNotifyState_GhostTrail.h"
#include "Kismet/GameplayStatics.h"
#include "Core/EXWCharacter.h"
#include "Core/Animation/EXWCharacterPose.h"


void UEXWNotifyState_GhostTrail::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	if (MeshComp && MeshComp->GetOwner())
	{
		AEXWCharacter* Character = Cast<AEXWCharacter>(MeshComp->GetOwner());
		if (Character)
		{
			Character->ActivateGhostTrail(GhostTrailParams);
		}
	}
}

void UEXWNotifyState_GhostTrail::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UEXWNotifyState_GhostTrail::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (MeshComp && MeshComp->GetOwner())
	{
		AEXWCharacter* Character = Cast<AEXWCharacter>(MeshComp->GetOwner());
		if (Character)
		{
			Character->DeactivateGhostTrail();
		}
	}
}
