// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWNotify_ChangeMaterial.h"
#include "Core/EXWCharacter.h"

void UEXWNotify_ChangeMaterial::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner()))
	{
		if (OwnerCharacter->IsLocallyControlled())
		{
			OwnerCharacter->SetMaterialOnAllMeshesForDuration(Material, Duration);
		}
	}
}
