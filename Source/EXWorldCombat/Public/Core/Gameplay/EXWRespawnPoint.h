// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "EXWRespawnPoint.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWRespawnPoint : public ATargetPoint
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Respawn")
	FString PointName="";
	
};
