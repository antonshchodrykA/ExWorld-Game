// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DemotestCharacter.generated.h"


UCLASS(config=Game, SpatialType)
class ADemotestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADemotestCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "ExWorld Player")
		float PlayerHealth = 100.0f;

	UFUNCTION(BlueprintImplementableEvent, Category = "ExWorld Player")
		void SetHealth(float NewHealth);

	class UAIPerceptionStimuliSourceComponent* NPC_SensorDetector;


};

