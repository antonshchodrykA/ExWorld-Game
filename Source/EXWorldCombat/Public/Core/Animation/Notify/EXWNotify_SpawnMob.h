// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "EXWNotify_SpawnMob.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNotify_SpawnMob : public UAnimNotify
{
	GENERATED_BODY()
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	TSubclassOf<class AEXWCharacter> Mob;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	int32 MobsToSpawn = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	float MinSpawnLocation = -1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	float MaxSpawnLocation = 1000.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	float RoamRadius = 1000.0f;



};
