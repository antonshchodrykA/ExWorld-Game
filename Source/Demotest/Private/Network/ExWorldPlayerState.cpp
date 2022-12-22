// Fill out your copyright notice in the Description page of Project Settings.


#include "..\..\Public\Network\ExWorldPlayerState.h"
#include "ExWorldLog.h"
#include "GameFramework/GameState.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "../../Public/Library/EXWDataStruct.h"
#include "../../Public/Network/ExWorldGameState.h"


void AExWorldPlayerState::BeginPlay()
{
	Super::BeginPlay();
	PublishPlayerUpdate(EPlayerProgress::Connected);
	EXWORLDLOG("ExWorldPlayer State Connected")
}

void AExWorldPlayerState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	PublishPlayerUpdate(EPlayerProgress::Disconnected);
	EXWORLDLOG("ExWorldPlayer State Disconnected")
}


void AExWorldPlayerState::PublishPlayerUpdate(EPlayerProgress PlayerProgress)
{
	if (HasAuthority() && IsValid(this))
	{
		if (UPlayerPublisher* Publisher = Cast<UPlayerPublisher>(GetWorld()->GetGameState()->GetComponentByClass(UPlayerPublisher::StaticClass()))) {

			Publisher->PublishPlayer(this, PlayerProgress);
			EXWORLDLOG("ExWorldPlayer State Has Authority")
		}

	}
}
