// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "DemotestCharacter.h"
#include "SpatialNetDriver.h"
#include "UnrealNetwork.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"

ADemotestCharacter::ADemotestCharacter(const FObjectInitializer& ObjectInitializer)
{
	NPC_SensorDetector = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("NPC_SensorDetector"));
	NPC_SensorDetector->RegisterForSense(TSubclassOf<UAISense_Sight>());
	NPC_SensorDetector->RegisterWithPerceptionSystem();

}

