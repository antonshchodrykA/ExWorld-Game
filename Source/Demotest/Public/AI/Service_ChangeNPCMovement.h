// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Service_ChangeNPCMovement.generated.h"

/**
 * 
 */
UCLASS()
class DEMOTEST_API UService_ChangeNPCMovement : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UService_ChangeNPCMovement(const FObjectInitializer& ObjectInitializer);
	void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComponent, uint8* NodeMemory) override;
	 
	virtual FString GetStaticServiceDescription() const override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorld_NPC", meta = (AllowPrivateAccess = "true"))
		float NPC_Speed = 0.0f;
	
};
