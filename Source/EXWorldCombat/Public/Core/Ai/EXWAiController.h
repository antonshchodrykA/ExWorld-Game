// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Library/EXWDataEnum.h"
#include "Perception/AIPerceptionTypes.h"
#include "EXWAiController.generated.h"

//General Character Log
DECLARE_LOG_CATEGORY_EXTERN(EXWAiLog, Log, All);

class UBehaviorTree;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWAiController : public AAIController
{
	GENERATED_BODY()
	
public:

	// Sets default values for this AI Controller's properties.
	AEXWAiController();

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Called when the AIController is taken over.
	virtual void OnPossess(APawn* NewPawn) override;

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	// Gets called when the perception component updates. This is
	// where check to see if the PlayerCharacter was detected.
	UFUNCTION()
	void OnPerceptionUpdate(const TArray<AActor*>& DetectedPawns);

	/**
	 * Initialization
	 */


	/**
	 * Targeting
	 */

	/** Choose closest target */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai")
	AActor* ChooseTarget(TArray<AActor*> Targets);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai|Blackboard")
	void SetTarget(UObject* NewTarget, const FName KeyName = "Target");

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Ai|Blackboard")
	UObject* GetTarget(const FName KeyName = "Target");

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai|Blackboard")
	void SetIsTargetAlive(bool bIsTargetAlive, const FName KeyName = "IsTargetAlive");

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Ai|Blackboard")
	EEXWTargetFaction GetTargetFactionType(const FName KeyName = "TargetFactionType");

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai|Blackboard")
	void SetTargetFactionType(const EEXWTargetFaction NewTargetFactionType,const FName KeyName = "TargetFactionType");

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai|Blackboard")
	void SetSpawnerActor(UObject* NewSpawner, const FName KeyName = "Spawner");

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai|Blackboard")
	UObject* GetSpawnerActor(const FName KeyName = "Spawner");


	/**
	 * Behavior Tree
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai")
	void SetBehaviorTree(UBehaviorTree* NewBehaviorTree, bool bRunBT = true);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Ai")
	UBehaviorTree* GetBehaviorTree();


protected:
	UPROPERTY()
	TWeakObjectPtr<UBehaviorTree> BehaviorTree;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai")
	void OnPawnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* EventInstigator, AActor* DamageCauser);
};
