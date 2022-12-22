// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "..\..\Public\Network\Components\PlayerPublisher.h"
#include "ExWorldPlayerState.generated.h"



/**
 * 
 */
UCLASS()
class DEMOTEST_API AExWorldPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	

protected:

	UFUNCTION()
		void PublishPlayerUpdate(EPlayerProgress PlayerProgress);
	
	UPlayerPublisher* PlayerPublisherComponent;
	
};
