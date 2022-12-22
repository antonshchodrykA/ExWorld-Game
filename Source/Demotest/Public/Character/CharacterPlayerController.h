// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CharacterPlayerController.generated.h"

/**
 * 
 */

 class AALSBaseCharacter;

UCLASS()
class DEMOTEST_API ACharacterPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Login")
		void ServerRequestPlayerNameAndConnect(const FString& Username, const FString& Password);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category="Login")
		void ServerJoinGame(const int32& PlayerSpawnIndex);

	UFUNCTION(Server, Reliable,BlueprintCallable, Category="Interaction")
        void ServerOnInteract(FVector StartLocation, FVector EndLocation);

	UFUNCTION(BlueprintCallable,Category="Login")
		void ConnectToPlayfab();
	
protected:

	AALSBaseCharacter* PossessedCharacter;

public:

	ACharacterPlayerController();
	// Will be taking care of loadin the player info and data table
	void InitializePlayer();

	//Will fetch the info from data table and filll inventiry structure
	void ServerLoadPlayerInventoryItems();

	void OnInteract(FVector StartLocation, FVector EndLocation);

	void OnRestartPawn(APawn* NewPawn);

	
};
