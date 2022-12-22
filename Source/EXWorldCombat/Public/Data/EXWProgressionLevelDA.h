// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EXWProgressionLevelDA.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWProgressionLevelDA : public UDataAsset
{
	GENERATED_BODY()

public:

	// This variable represents how much Experience is required per level.
	UPROPERTY(EditAnywhere)
	TArray<int32> ExperiencePerLevel = {
		100, 300, 500, 700, 900, 1000, 1200, 1400, 1600, 1700,
		1900, 2100, 2300, 2500, 2700, 2900, 3100, 3400, 3600, 3800
	};

	int32 GetExperience(const int32 Level);
};
