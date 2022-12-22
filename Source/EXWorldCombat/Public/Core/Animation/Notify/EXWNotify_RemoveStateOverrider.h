// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Library/EXWDataLibrary.h"
#include "EXWNotify_RemoveStateOverrider.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNotify_RemoveStateOverrider : public UAnimNotify
{
	GENERATED_BODY()
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	EEXWStateOverrider StateOverriderToRemove = EEXWStateOverrider::SO_SuperArmor;

};
