// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Library/EXWDataStruct.h"
#include "EXWCharacterDataStruct.h"
#include "EXWCloudStruct.h"
#include "EXWCloudLibrary.generated.h"




/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWCloudLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Initialization")
		static FEXWBaseSkeletalMeshes GetBaseCharaterSkeletalMeshes(EEXWRace Race, EEXWClass Class, EEXWGender Gender);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Initialization")
		static EEXWRace StringToRaceEnum(FString race);

private:
	 
};
