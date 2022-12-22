// Copyright (c)ExWorld Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnRequestPublisher.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpawnRequest, APlayerController*, Controller, int32, PlayerSpawnIndex);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DEMOTEST_API USpawnRequestPublisher : public UActorComponent
{
	GENERATED_BODY()

public:
	USpawnRequestPublisher();

	UPROPERTY(BlueprintAssignable)
		FSpawnRequest OnSpawnRequest;

	void RequestSpawn(APlayerController* Controller, int32 PlayerSpawnIndex) { OnSpawnRequest.Broadcast(Controller, PlayerSpawnIndex); }

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		bool bAutoConnect;
};
