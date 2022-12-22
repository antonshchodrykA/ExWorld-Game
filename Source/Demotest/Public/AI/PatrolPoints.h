// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPoints.generated.h"

UCLASS()
class DEMOTEST_API APatrolPoints : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APatrolPoints();

	const FVector GetPatrolPoints(const int index);
	const int PatrolPonitsCount();
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorld_NPC", meta = (MakeEditWidget = "true", AllowPrivateAccess = "true"))
		TArray<FVector>PatrolPoints;


};
