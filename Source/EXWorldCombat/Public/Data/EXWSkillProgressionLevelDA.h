// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Library/EXWDataStruct.h"
#include "EXWSkillProgressionLevelDA.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWSkillProgressionLevelDA : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UEXWSkillProgressionLevelDA(const FObjectInitializer& ObjectInitializer);

	// This variable represents how much Experience is required per level.
	UPROPERTY(EditAnywhere)
	TMap<EEXWLifeSkillType, FEXWLifeSkillExperienceData> Experiences;

	int32 GetExperience(const EEXWLifeSkillType LifeSkillType, const int32 Level);
};
