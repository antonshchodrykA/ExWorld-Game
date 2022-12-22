// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/EXWActorIndicator.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AEXWActorIndicator::AEXWActorIndicator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent *SceneComp= CreateDefaultSubobject<USceneComponent>("Root Component");
	if (SceneComp)
	{
		SetRootComponent(SceneComp);
	}
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	if (StaticMesh)
	{
		StaticMesh->SetupAttachment(SceneComp);
	}
}

void AEXWActorIndicator::SetStaticMesh(UStaticMesh* NewStaticMesh)
{
	StaticMesh->SetStaticMesh(NewStaticMesh);
}

// Called when the game starts or when spawned
void AEXWActorIndicator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEXWActorIndicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

