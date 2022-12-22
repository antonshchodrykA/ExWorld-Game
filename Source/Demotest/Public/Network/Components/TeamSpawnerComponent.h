// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/PlayerStart.h"
#include "Demotest\DemotestCharacter.h"
#include "TeamSpawnerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEMOTEST_API UTeamSpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTeamSpawnerComponent();

	UFUNCTION(BlueprintCallable)
	void RequestPlayerToSpawn(APlayerController* Controller, TSubclassOf<AActor> PlayerClass);

	UFUNCTION(BlueprintCallable)
	void RequestPlayerUniqueId();
	
	UPROPERTY(EditAnywhere)
		APawn* CharacterClass;


protected:
	class APlayerStart* GetNextPlayerStart();
	TMap<APlayerController*, int32> SpawnedPlayers;
	TArray<class APlayerStart*> PlayerStarts;
	int32 NextPlayerStart;
	int32 PlayerIndex = 0;

		
};
