// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Library/EXWDataStruct.h"
#include "EXWNotifyState_Target.generated.h"


class AEXWCharacter;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNotifyState_Target : public UAnimNotifyState
{
	GENERATED_BODY()

protected:

	virtual void NotifyBegin(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime) override;
	virtual void NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation) override;

public:

	/** Tag of the collision component to trace from in order to deal damage. This component should have a Primitive Component as a parent */
	UPROPERTY(EditAnywhere, Category = Base)
	FEXWTargetingParams TargetingParams;

};
