// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Library/EXWDataEnum.h"
#include "EXWNotify_RemoveState.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNotify_RemoveState : public UAnimNotify
{
	GENERATED_BODY()
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	EEXWState StateToRemove = EEXWState::S_InAction;

};
