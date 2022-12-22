// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "NPC_ControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API ANPC_ControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	ANPC_ControllerBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	

	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

	virtual void OnUnPossess() override;

	void SlowDownTheNPC();

	//TODO Convert this into inline function for faster performance
	class UBlackboardComponent* GetBlackboardComponent() const;

protected:

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "ExWorld_NPC" , meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* NPCBehaviorTree_Component;


	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "ExWorld_NPC", meta = (AllowPrivateAccess = "true"))
		class UBehaviorTree* NPCBehaviorTree;

	
	
protected:

	UFUNCTION()
		void Senses_OnUpdated(const TArray<AActor*>& UpdatedActors);

		void Senses_OnSetup(float SightRadius, float LooseSightRadius, float VisionAngle, float MaxAge, float LastSeenRange, bool DetectEnemies, bool DetectFriends, bool DetectNeutrals);
		
	UFUNCTION()
		virtual void Senses_OnTargetUpdated(AActor * Target, const FAIStimulus Stimulus);

	class UBlackboardComponent* NPC_Blackboard;

	class UAISenseConfig_Sight* NPC_Senses_Sight;


	

};
