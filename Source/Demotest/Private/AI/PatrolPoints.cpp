// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolPoints.h"

// Sets default values
APatrolPoints::APatrolPoints()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

const FVector APatrolPoints::GetPatrolPoints(const int index)
{
	return PatrolPoints[index];
}

const int APatrolPoints::PatrolPonitsCount()
{
	return PatrolPoints.Num();
}
