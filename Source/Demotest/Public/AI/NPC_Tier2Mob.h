// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPC_CharacterBase.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "NPC_Tier2Mob.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API ANPC_Tier2Mob : public ANPC_CharacterBase
{
	GENERATED_BODY()
public:
	ANPC_Tier2Mob(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;

	void Attack_Start() override;
	void Attack_End() override;
// TODO Try moving this to base class
	UFUNCTION()
		void OnAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent,  AActor* OtherActor, UPrimitiveComponent* OtherComponent,  int OtherBodyIndex,  bool bSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnAttackEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int OtherBodyIndex);
};
