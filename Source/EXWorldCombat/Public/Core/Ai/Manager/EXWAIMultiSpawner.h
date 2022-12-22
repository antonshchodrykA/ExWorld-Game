// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Library/EXWDataStruct.h"
#include "EXWAIMultiSpawner.generated.h"

class AEXWCharacter;


DECLARE_LOG_CATEGORY_EXTERN(EXWAIMultiSpawnerLog, Log, All);

UCLASS()
class EXWORLDCOMBAT_API AEXWAIMultiSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEXWAIMultiSpawner(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|AI|Spawner")
	TArray<FEXWAISpawnerData> AIs;
	
	/** This is the total number of AIs to spawn.
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|AI|Spawner", meta = (ClampMin = "1"))
	int32 Population = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|AI|Spawner")
	float RoamRadius = 1000.f;
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform);

	virtual void GeneratePreview();

	FEXWAISpawnerData GetSpawnerDataFromCharacter(AEXWCharacter* Character);

public:	
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|AI|Spawner")
	void Server_SpawnAI(FEXWAISpawnerData AISpawnerData);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|AI|Spawner")
	void TriggerRespawnTimer(FEXWAISpawnerData AISpawnerData);

	UFUNCTION()
	virtual void HandleAIDeath(AEXWCharacter* DeadCharacter, AEXWCharacter* Killer);


protected:
	class UBoxComponent* BoxComponent;

private:

	UPROPERTY()
	TArray<TWeakObjectPtr<AEXWCharacter>> AICharacters;

	UPROPERTY()
	TArray<FEXWAISpawnerData> SpawnStack;

	UPROPERTY()
	TArray<UInstancedStaticMeshComponent*> InstancedMeshes;
};
