// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Ai/Services/EXW_BTService_Base.h"
#include "EXW_BTService_SetIsDead.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXW_BTService_SetIsDead : public UEXW_BTService_Base
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true", AllowPrivateAccess = "true"), Category = EXWorld)
	FBlackboardKeySelector IsDeadKey;

protected:

	/** update next tick interval
	 * this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
