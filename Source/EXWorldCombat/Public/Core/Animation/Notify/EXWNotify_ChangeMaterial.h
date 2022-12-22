// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "EXWNotify_ChangeMaterial.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNotify_ChangeMaterial : public UAnimNotify
{
	GENERATED_BODY()

protected:

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:

	UPROPERTY(EditAnywhere, Category = Base)
	UMaterialInterface* Material = nullptr;

	UPROPERTY(EditAnywhere, Category = Base)
	float Duration = 1.f;
};
