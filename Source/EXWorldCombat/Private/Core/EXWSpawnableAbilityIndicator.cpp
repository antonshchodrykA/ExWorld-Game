// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/EXWSpawnableAbilityIndicator.h"
#include "Engine/DecalActor.h"
#include "Engine/StaticMeshActor.h"
#include "Core/EXWCharacter.h"

// Sets default values
AEXWSpawnableAbilityIndicator::AEXWSpawnableAbilityIndicator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEXWSpawnableAbilityIndicator::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEXWSpawnableAbilityIndicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateLocation();
}

void AEXWSpawnableAbilityIndicator::UpdateLocation()
{
	if (OwnerCharacter.IsValid())
	{
		if (SpawnableAbilityType == EEXWSpawnableAbilityType::InstantAtCrosshair)
		{
			SetActorLocation(OwnerCharacter.Get()->GetClosestGroundToCrosshair(Distance, false));
		}
	}
}

void AEXWSpawnableAbilityIndicator::SpawnDecal(TSubclassOf<ADecalActor> ClassToSpawn, const FVector Offset /*= FVector::ZeroVector*/)
{
	if (UWorld* World = GetWorld())
	{
		FVector SpawnLocation = GetActorLocation() + Offset;
		DecalActor = World->SpawnActor<ADecalActor>(ClassToSpawn, SpawnLocation, FRotator(0, 0, 0));
		if (DecalActor)
		{
			DecalActor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		}
	}
}

void AEXWSpawnableAbilityIndicator::SpawnStaticMesh(TSubclassOf<AStaticMeshActor> ClassToSpawn, const FVector Offset /*= FVector::ZeroVector*/)
{
	if (UWorld* World = GetWorld())
	{
		FVector SpawnLocation = GetActorLocation() + Offset;
		StaticMeshActor = World->SpawnActor<AStaticMeshActor>(ClassToSpawn, SpawnLocation, FRotator(0, 0, 0));
		if (StaticMeshActor)
		{
			StaticMeshActor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		}
	}
}

void AEXWSpawnableAbilityIndicator::SetOwnerCharacter(AEXWCharacter* NewCharacter)
{
	if (NewCharacter)
	{
		SetOwner(NewCharacter);
		OwnerCharacter = MakeWeakObjectPtr<AEXWCharacter>(NewCharacter);
	}
}

AEXWCharacter* AEXWSpawnableAbilityIndicator::GetOwnerCharacter()
{
	if (OwnerCharacter.IsValid())
	{
		return OwnerCharacter.Get();
	}
	return nullptr;
}

