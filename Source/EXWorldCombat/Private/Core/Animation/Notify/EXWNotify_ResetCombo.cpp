// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#include "Core/Animation/Notify/EXWNotify_ResetCombo.h"
#include "Core/EXWcharacter.h"

void UEXWNotify_ResetCombo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
	{
		OwnerCharacter->ComboCounter = 0;
	}
}
