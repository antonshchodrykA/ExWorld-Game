// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AI_AttackNotifyState.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API UAI_AttackNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()
public:
	void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	
};
