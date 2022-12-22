// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EXWAiSpawner.generated.h"

//General Character Log
DECLARE_LOG_CATEGORY_EXTERN(EXWAiSpawnerLog, Log, All);

class AEXWCharacter;

UCLASS()
class EXWORLDCOMBAT_API AEXWAiSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEXWAiSpawner(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Ai|Spawner")
	TSubclassOf<AEXWCharacter> AiCharacterClass = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Ai|Spawner")
	class UBehaviorTree* BehaviorTree = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Ai|Spawner")
	float RespawnTimer = 10.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Ai|Spawner")
	int32 Level = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Ai|Spawner")
	float RoamRadius = 1000.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Ai|Spawner|Display")
	class USkeletalMesh* SkeletalMesh = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "EXWorld|Ai|Spawner")
	AEXWCharacter* GetAiCharacter(){ return (AiCharacter.IsValid()) ? AiCharacter.Get() : nullptr; };

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai|Spawner")
	void SetAiCharacter(AEXWCharacter* NewAiCharacter);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Ai|Spawner")
	void Server_SpawnAi();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ai|Spawner")
	void TriggerRespawnTimer();

	UFUNCTION()
	virtual void Respawn();

protected:
	
	virtual void InitializeCharacter();

	class USkeletalMeshComponent* SkeletalMeshComponent;

private :

	TWeakObjectPtr<AEXWCharacter> AiCharacter;

	uint8 bIsDead : 1;

	FTimerHandle RespawnTimerHandle;
};