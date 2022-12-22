// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Library/EXWDataStruct.h"
#include "EXWNotifyState_GhostTrail.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNotifyState_GhostTrail : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Base)
	FEXWGhostTrailParams GhostTrailParams;

protected:

	void NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration) override;
	void NotifyTick(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float FrameDeltaTime) override;
	void NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation) override;

};
