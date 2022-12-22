// Fill out your copyright notice in the Description page of Project Settings.


#include "TeamSpawnerComponent.h"
#include "MetaDataComponent.h"
#include "CharacterPlayerController.h"
#include "ExWorldLog.h"
#include "Network/ExWorldGameInstance.h"
#include "EngineUtils.h"
#include "Engine/World.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/GameModeBase.h"

// Sets default values for this component's properties
UTeamSpawnerComponent::UTeamSpawnerComponent()
{
	
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	NextPlayerStart = 0;

	// ...
}


//TODO Remove custom id when you get the proper api call data
void UTeamSpawnerComponent::RequestPlayerToSpawn(APlayerController* Controller, TSubclassOf<AActor> PlayerClass)
{
	PlayerIndex++;

	for (TActorIterator<APlayerStart> It(GetWorld()); It; ++It)
	{
		APlayerStart* PlayerStart = *It;
		
		PlayerStarts.Add(PlayerStart);
	}
		// In case wants to add rules for Index ID
		if (AGameModeBase* GameMode = GetWorld()->GetAuthGameMode())
		{
			APawn* NewPawn = nullptr;
			//In UI On button click given index 
			FActorSpawnParameters SpawnInfo;
			FVector Location = PlayerStarts[PlayerIndex]->GetActorLocation();
			FRotator Rotation = PlayerStarts[PlayerIndex]->GetActorRotation();
			//ADD a little offset
			AActor* ActorPawn = GetWorld()->SpawnActor<AActor>(PlayerClass, Location, Rotation, SpawnInfo);
			NewPawn = Cast<APawn>(ActorPawn);
		
			if(NewPawn){
				Controller->Possess(NewPawn);
			}
		
			//NewPawn = GameMode->SpawnDefaultPawnFor(Controller, PlayerStarts[PlayerIndex]);
	
			if (UMetaDataComponent* MetaDataComponent = Cast<UMetaDataComponent>(NewPawn->GetComponentByClass(UMetaDataComponent::StaticClass())))
			{
				FEXMetaData MetaData;
				MetaData.PlayerIndex = PlayerIndex;
				MetaDataComponent->SetMetaData(MetaData);
				EXWORLDLOG("META NUM<BER");
			}

			UExWorldGameInstance* ExWorldGameInstance = Cast<UExWorldGameInstance>(GameMode->GetGameInstance());
			if (ExWorldGameInstance)
			{
				ExWorldGameInstance->CallExWorldApi();
			}
		}
	}



void UTeamSpawnerComponent::RequestPlayerUniqueId()
{
	
	
}

APlayerStart* UTeamSpawnerComponent::GetNextPlayerStart()
{
	APlayerStart* PlayerStart = PlayerStarts[NextPlayerStart];
	NextPlayerStart = (NextPlayerStart + 1) % PlayerStarts.Num();

	return PlayerStart;
}
