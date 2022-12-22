// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Animation/Notify/EXWNotifyState_Melee.h"
#include "EXWNotifyState_Casting.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNotifyState_Casting : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:

	UEXWNotifyState_Casting();

protected:

	virtual void NotifyBegin(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime) override;
	virtual void NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation) override;


public:
	UPROPERTY()
	AEXWCharacter* OwnerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify,meta = (Tooltip = "Action ID from DT Actions"))
	FName ActionID;
};