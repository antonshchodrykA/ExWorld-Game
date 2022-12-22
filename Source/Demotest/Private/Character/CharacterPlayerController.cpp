// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPlayerController.h"
#include "..\..\Public\Network\Components\SpawnRequestPublisher.h"
#include "GameFramework/GameState.h"
#include "GameFramework/PlayerState.h"
#include "ExWorldGameInstance.h"
#include "Character/ALSBaseCharacter.h"
#include "Character/ALSPlayerCameraManager.h"
#include "ExWorldLoadingScreen.h"
#include "UserWidget.h"
#include "Interfaces/EXWorldInterface.h"
#include "Runtime/Engine/Classes/Engine/World.h"

ACharacterPlayerController::ACharacterPlayerController()
{
	
}

void ACharacterPlayerController::ServerRequestPlayerNameAndConnect_Implementation(const FString& Username, const FString& Password )
{
	if(PlayerState)
	{
		PlayerState->SetPlayerName(Username);
		UExWorldGameInstance* GameInstance = Cast<UExWorldGameInstance>(GetGameInstance());
		//GameInstance->CustomId = Username;
		GameInstance->Login(Username,Password);
	}
}

bool ACharacterPlayerController::ServerRequestPlayerNameAndConnect_Validate(const FString& Username, const FString& Password)
{
	return true;
}

void ACharacterPlayerController::ServerJoinGame_Implementation(const int32& PlayerSpawnIndex)
{

	if (USpawnRequestPublisher* Spawner = Cast<USpawnRequestPublisher>(GetWorld()->GetGameState()->GetComponentByClass(USpawnRequestPublisher::StaticClass())))
	{
		Spawner->RequestSpawn(this, PlayerSpawnIndex);
		return;
	}
}

bool ACharacterPlayerController::ServerJoinGame_Validate(const int32& PlayerSpawnIndex)
{
	return true;
}

void ACharacterPlayerController::ServerOnInteract_Implementation(FVector StartLocation, FVector EndLocation)
{
	OnInteract(StartLocation,EndLocation);
}

void ACharacterPlayerController::ConnectToPlayfab()
{
	UExWorldGameInstance* GameInstance = Cast<UExWorldGameInstance>(GetGameInstance());
	if(GameInstance)
	{
		GameInstance->CallExWorldApi();
	}
}



void ACharacterPlayerController::InitializePlayer()
{
}

void ACharacterPlayerController::ServerLoadPlayerInventoryItems()
{
}

void ACharacterPlayerController::OnInteract(FVector StartLocation, FVector EndLocation)
{
	if(HasAuthority())
	{
		//TODO Get player camera manager inputs
		FVector StartLoc = StartLocation;
		FVector EndLoc = EndLocation;
		FCollisionQueryParams CollisionParams;
		FHitResult Hit;
		FCollisionQueryParams TraceParams;
		bool bHit = GetWorld()->LineTraceSingleByChannel(Hit,StartLoc,EndLoc,ECC_Visibility,TraceParams);
		if (bHit && Hit.GetActor()->GetClass()->ImplementsInterface(UEXWorldInterface::StaticClass()))
		{
			Cast<IEXWorldInterface>(Hit.GetActor())->OnItemInteracted(this);
		}
		
	}
}

void ACharacterPlayerController::OnRestartPawn(APawn* NewPawn)
{
	PossessedCharacter = Cast<AALSBaseCharacter>(NewPawn);
	check(PossessedCharacter);

	//Call "OnPossess" in Player Camera Manager when possessing a pawn
	AALSPlayerCameraManager * CastedMgr = Cast<AALSPlayerCameraManager>(PlayerCameraManager);
	if (CastedMgr)
	{
		CastedMgr->OnPossess(PossessedCharacter);
	}
}

//Loading
