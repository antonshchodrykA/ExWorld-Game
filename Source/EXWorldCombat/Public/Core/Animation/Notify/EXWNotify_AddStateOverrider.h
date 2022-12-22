// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Library/EXWDataLibrary.h"
#include "EXWNotify_AddStateOverrider.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNotify_AddStateOverrider : public UAnimNotify
{
	GENERATED_BODY()

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	EEXWStateOverrider StateOverriderToAdd = EEXWStateOverrider::SO_SuperArmor;
	
};
