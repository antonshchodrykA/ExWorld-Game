// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EXWLifeSkillStruct.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FEXWFireLog
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<AActor> FireLogClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<AActor> IndicatorClass;

	UPROPERTY()
		TWeakObjectPtr<AActor> SpawnedActor;

};