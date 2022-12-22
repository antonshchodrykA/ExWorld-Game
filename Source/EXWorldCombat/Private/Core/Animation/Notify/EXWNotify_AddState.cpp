// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#include "Core/Animation/Notify/EXWNotify_AddState.h"
#include "Core/EXWcharacter.h"

void UEXWNotify_AddState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
	{
		OwnerCharacter->AddState(StateToAdd);
	}
}
