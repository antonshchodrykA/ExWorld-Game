// Fill out your copyright notice in the Description page of Project Settings.

// Main Header
#include "Core/Ai/EXWAiController.h"

// Perception
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"

// Behaviour Tree/Black Board
#include "BehaviorTree/BehaviorTree.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

// Dependencies
#include "Library/EXWDataLibrary.h"
#include "Core/EXWCharacter.h"

//General Character Log
DEFINE_LOG_CATEGORY(EXWAiLog);

AEXWAiController::AEXWAiController()
{
	// We need this AIController to run its Tick method.
	PrimaryActorTick.bCanEverTick = true;

	// Setup Perception Component
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
	 
	UAISenseConfig_Sight *SightSenseConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	if (SightSenseConfig)
	{
		SightSenseConfig->Implementation = UAISense_Sight::StaticClass();
		SightSenseConfig->SightRadius = 3000.f;
		SightSenseConfig->LoseSightRadius = 3500.f;
		SightSenseConfig->PeripheralVisionAngleDegrees = 80.f;
		SightSenseConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightSenseConfig->DetectionByAffiliation.bDetectFriendlies = true;
		SightSenseConfig->DetectionByAffiliation.bDetectNeutrals = true;
		SightSenseConfig->SetMaxAge(0.f);
		GetPerceptionComponent()->ConfigureSense(*SightSenseConfig);
		GetPerceptionComponent()->SetDominantSense(*SightSenseConfig->GetSenseImplementation());
	}

	UAISenseConfig_Hearing* HearingSenseConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Config"));
	if (HearingSenseConfig)
	{
		HearingSenseConfig->Implementation = UAISense_Hearing::StaticClass();
		HearingSenseConfig->HearingRange = 1500.f;
		HearingSenseConfig->bUseLoSHearing = true;
		HearingSenseConfig->HearingRange = 2000.f;
		HearingSenseConfig->DetectionByAffiliation.bDetectEnemies = true;
		HearingSenseConfig->DetectionByAffiliation.bDetectFriendlies = true;
		HearingSenseConfig->DetectionByAffiliation.bDetectNeutrals = true;
		HearingSenseConfig->SetMaxAge(0.f);
		GetPerceptionComponent()->ConfigureSense(*HearingSenseConfig);
	}
	// Set the method to respond when the perception component updates.
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AEXWAiController::OnPerceptionUpdate);
}

void AEXWAiController::BeginPlay()
{
	Super::BeginPlay();
}

void AEXWAiController::OnPossess(APawn* NewPawn)
{
	Super::OnPossess(NewPawn);
	NewPawn->OnTakeAnyDamage.AddDynamic(this, &AEXWAiController::OnPawnTakeDamage);
}

void AEXWAiController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AEXWAiController::OnPerceptionUpdate(const TArray<AActor*>& DetectedPawns)
{
}

AActor* AEXWAiController::ChooseTarget(TArray<AActor*> Targets)
{
	AActor* TargetPawn = Cast<AActor>(GetTarget());
	if (APawn* ControlledPawn = GetPawn())
	{
		// Check if there is an actual pawn seen (has to be close)
		if (AActor* ClosestActor = UEXWDataLibrary::GetClosestActor(ControlledPawn, Targets))
		{	
			return ClosestActor;	
		}
	}
	return nullptr;
}

void AEXWAiController::SetTarget(UObject* NewTarget, const FName KeyName /*= "Target"*/)
{
	if (UBlackboardComponent* CurrentBlackboard = UAIBlueprintHelperLibrary::GetBlackboard(this))
	{
		CurrentBlackboard->SetValueAsObject(KeyName, NewTarget);
	}
}

UObject* AEXWAiController::GetTarget(const FName KeyName /*= "Target"*/)
{
	if (UBlackboardComponent* CurrentBlackboard = UAIBlueprintHelperLibrary::GetBlackboard(this))
	{
		return CurrentBlackboard->GetValueAsObject(KeyName);
	}
	return nullptr;
}

void AEXWAiController::SetIsTargetAlive(bool bIsTargetAlive, const FName KeyName /*= "IsTargetAlive"*/)
{
	if (UBlackboardComponent* CurrentBlackboard = UAIBlueprintHelperLibrary::GetBlackboard(this))
	{
		CurrentBlackboard->SetValueAsBool(KeyName, bIsTargetAlive);
	}
}

EEXWTargetFaction AEXWAiController::GetTargetFactionType(const FName KeyName /*= "TargetFactionType"*/)
{
	if (UBlackboardComponent* CurrentBlackboard = UAIBlueprintHelperLibrary::GetBlackboard(this))
	{
		return static_cast<EEXWTargetFaction>(CurrentBlackboard->GetValueAsEnum(KeyName));
	}
	return EEXWTargetFaction::TF_OtherFactionOnly;
}

void AEXWAiController::SetTargetFactionType(const EEXWTargetFaction NewTargetFactionType, const FName KeyName /*= "TargetFactionType"*/)
{
	if (UBlackboardComponent* CurrentBlackboard = UAIBlueprintHelperLibrary::GetBlackboard(this))
	{
		CurrentBlackboard->SetValueAsEnum(KeyName, static_cast<uint8>(NewTargetFactionType));
	}
}

void AEXWAiController::SetSpawnerActor(UObject* NewSpawner, const FName KeyName /*= "Spawner"*/)
{
	if (UBlackboardComponent* CurrentBlackboard = UAIBlueprintHelperLibrary::GetBlackboard(this))
	{
		CurrentBlackboard->SetValueAsObject(KeyName, NewSpawner);
	}
}

UObject* AEXWAiController::GetSpawnerActor(const FName KeyName /*= "Spawner"*/)
{
	if (UBlackboardComponent* CurrentBlackboard = UAIBlueprintHelperLibrary::GetBlackboard(this))
	{
		return CurrentBlackboard->GetValueAsObject(KeyName);
	}
	return nullptr;
}

void AEXWAiController::SetBehaviorTree(UBehaviorTree* NewBehaviorTree, bool bRunBT)
{
	if (NewBehaviorTree)
	{
		BehaviorTree = MakeWeakObjectPtr<UBehaviorTree>(NewBehaviorTree);
		if (bRunBT)
		{
			RunBehaviorTree(NewBehaviorTree);
		}
	}
}

UBehaviorTree* AEXWAiController::GetBehaviorTree()
{
	return (BehaviorTree.IsValid()) ? BehaviorTree.Get() : nullptr;
}


void AEXWAiController::OnPawnTakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* EventInstigator, AActor* DamageCauser)
{
	if (!GetTarget())
	{
		SetTarget(DamageCauser);
	}
}
