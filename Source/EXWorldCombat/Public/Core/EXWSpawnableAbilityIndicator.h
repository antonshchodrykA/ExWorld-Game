// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Library/EXWDataEnum.h"
#include "EXWSpawnableAbilityIndicator.generated.h"

class ADecalActor;
class AStaticMeshActor;
class AEXWCharacter;

UCLASS()
class EXWORLDCOMBAT_API AEXWSpawnableAbilityIndicator : public AActor
{
	GENERATED_BODY()
	
public:	
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Indicator")
	EEXWSpawnableAbilityType SpawnableAbilityType = EEXWSpawnableAbilityType::InstantAtCrosshair;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Indicator")
	float Distance = 2000.f;

public:
	
	// Sets default values for this actor's properties
	AEXWSpawnableAbilityIndicator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable, Category = "EXWorld|Indicator")
	void UpdateLocation();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Indicator")
	void SpawnDecal(TSubclassOf<ADecalActor> ClassToSpawn, const FVector Offset = FVector::ZeroVector);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Indicator")
	void SpawnStaticMesh(TSubclassOf<AStaticMeshActor> ClassToSpawn, const FVector Offset = FVector::ZeroVector);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Indicator")
	void SetOwnerCharacter(AEXWCharacter* NewCharacter);

	UFUNCTION(BlueprintCallable, BlueprintGetter, Category = "EXWorld|Indicator")
	AEXWCharacter* GetOwnerCharacter();

private:

	ADecalActor* DecalActor;

	AStaticMeshActor* StaticMeshActor;

	TWeakObjectPtr<AEXWCharacter> OwnerCharacter;
};
