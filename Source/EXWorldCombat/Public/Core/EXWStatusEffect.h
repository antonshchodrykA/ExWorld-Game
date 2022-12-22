// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Library/EXWDataStruct.h"
#include "EXWStatusEffect.generated.h"

UCLASS()
class EXWORLDCOMBAT_API AEXWStatusEffect : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AEXWStatusEffect();

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Data")
	FEXWStatusEffectData StatusEffectData;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	
	/**
	 * Actor General
	 */
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Called for replicating class variables */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/**
	 * Data
	 */

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|StatusEffect|Data")
	void Server_SetStatusEffectData(FEXWStatusEffectData InData);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|StatusEffect|Data")
	AEXWCharacter* GetSourceCharacter();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|StatusEffect|Data")
	AEXWCharacter* GetTargetCharacter();

	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "EXWorld|StatusEffect|Misc")
	void Server_AttachToTarget();

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|StatusEffect|Misc")
	void MulticastAttachToTarget();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|StatusEffect|Misc")
	void AttachToTarget();
};
