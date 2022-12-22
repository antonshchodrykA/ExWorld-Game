// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Ai/Services/EXW_BTService_Base.h"
#include "EXW_BTService_LookForTarget.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXW_BTService_LookForTarget : public UEXW_BTService_Base
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true", AllowPrivateAccess = "true"), Category = EXWorld)
	FBlackboardKeySelector TargetKey;

	/** Maximum distance the random location picked may be from pawn. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true", AllowPrivateAccess = "true"), Category = EXWorld)
	FBlackboardKeySelector TargetFactionTypeKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ExposeOnSpawn = "true", AllowPrivateAccess = "true"), Category = EXWorld)
	FBlackboardKeySelector CanTargetDeadKey;

protected:

	/** update next tick interval
	 * this function should be considered as const (don't modify state of object) if node is not instanced! */
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
