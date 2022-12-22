// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ai/Manager/EXWMobSpawner.h"

// Sets default values
AEXWMobSpawner::AEXWMobSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEXWMobSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEXWMobSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEXWMobSpawner::SpawnMob_Implementation()
{

}

