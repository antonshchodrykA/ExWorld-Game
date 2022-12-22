// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWAIMultiSpawner.h"
#include "AIController.h"
#include "Core/EXWCharacter.h"
#include "Library/EXWDataStruct.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Kismet/KismetMathLibrary.h"

DEFINE_LOG_CATEGORY(EXWAIMultiSpawnerLog);

// Sets default values
AEXWAIMultiSpawner::AEXWAIMultiSpawner(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Component"));
	SetRootComponent(SceneComponent);

#if WITH_EDITORONLY_DATA
	
	if (!IsRunningCommandlet())
	{
		BoxComponent = CreateEditorOnlyDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
		if (BoxComponent)
		{
			BoxComponent->SetupAttachment(SceneComponent);
			BoxComponent->SetHiddenInGame(true);
			BoxComponent->SetBoxExtent(FVector(RoamRadius));
		}
	}
#endif // WITH_EDITORONLY_DATA

	SetCanBeDamaged(false);
	SetHidden(true);
}

// Called when the game starts or when spawned
void AEXWAIMultiSpawner::BeginPlay()
{
	Super::BeginPlay();

	// Create a spawn stack to handle the loop later on
	SpawnStack = AIs;
	
	//first we sort our Stack from Least possible spawn to Highest Possible to spawn
	SpawnStack.Sort([](const FEXWAISpawnerData& lhs, const FEXWAISpawnerData& rhs) {
		return lhs.SpawnChance < rhs.SpawnChance;
		});

	for (int32 i = 0; i < Population; i++)
	{
		for (FEXWAISpawnerData AISpawner : SpawnStack)
		{
			int32 Index;
			if (AIs.Find(AISpawner, Index)) {
				FEXWAISpawnerData& AI = AIs[Index];
				if ((AI.SpawnedAmount > 0 && 
					AI.SpawnedAmount >= AI.MinimumRequiredAmountToSpawn &&
					AI.SpawnedAmount == AI.MaximumRequiredAmountToSpawn) 
					|| Population < AI.MinimumRequiredEntitiesToSpawn)
				{
					UE_LOG(EXWAIMultiSpawnerLog, Display, TEXT("<%s>: <%s> Removed from Stack"), *GetName(), *AISpawner.AICharacterClass->GetName());
					SpawnStack.Remove(AISpawner);
					continue;
				}

				if ((AI.MinimumRequiredAmountToSpawn > 0 && AI.SpawnedAmount < AI.MinimumRequiredAmountToSpawn) &&
					(AI.MaximumRequiredAmountToSpawn == 0 || AI.SpawnedAmount < AI.MaximumRequiredAmountToSpawn))
				{
					UE_LOG(EXWAIMultiSpawnerLog, Display, TEXT("<%s>: Force Spawning: %s"), *GetName(), *AI.AICharacterClass->GetName());
					Server_SpawnAI(AI);
					break;
				}

				if (FMath::FRandRange(0.f, 100.f) <= AI.SpawnChance)
				{
					UE_LOG(EXWAIMultiSpawnerLog, Display, TEXT("<%s>: Normal Spawning: %s"), *GetName(), *AI.AICharacterClass->GetName());
					Server_SpawnAI(AI);
					break;
				}
			}
		}
	}
	
}

void AEXWAIMultiSpawner::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	BoxComponent->SetBoxExtent(FVector(RoamRadius));
	GeneratePreview();

}

void AEXWAIMultiSpawner::GeneratePreview()
{
#if WITH_EDITORONLY_DATA

	if (!IsRunningCommandlet())
	{
		// Create a spawn stack to handle the loop later on
		SpawnStack = AIs;

		//first we sort our Stack from Least possible spawn to Highest Possible to spawn
		SpawnStack.Sort([](const FEXWAISpawnerData& lhs, const FEXWAISpawnerData& rhs) {
			return lhs.SpawnChance < rhs.SpawnChance;
			});

		for (UInstancedStaticMeshComponent* InstancedMesh : InstancedMeshes)
		{
			InstancedMesh->ClearInstances();
		}

		InstancedMeshes.Empty();

		for (FEXWAISpawnerData AISpawner : SpawnStack)
		{
			if (AISpawner.StaticMesh)
			{
				UInstancedStaticMeshComponent* InstancedMesh = NewObject<UInstancedStaticMeshComponent>(this, UInstancedStaticMeshComponent::StaticClass());
				InstancedMesh->SetupAttachment(BoxComponent);
				InstancedMesh->RegisterComponent();
				InstancedMesh->SetStaticMesh(AISpawner.StaticMesh);
				InstancedMeshes.Add(InstancedMesh);
			}
			else {
				SpawnStack.Remove(AISpawner);
			}
		}
		
		for (int32 i = 0; i < Population; i++)
		{
			for (int32 j = 0; j < SpawnStack.Num(); j++)
			{
				FEXWAISpawnerData AISpawner = SpawnStack[j];
				if (AISpawner.StaticMesh)
				{
					int32 Index;
					if (AIs.Find(AISpawner, Index)) {
						FEXWAISpawnerData& AI = AIs[Index];
						if ((AI.SpawnedAmount > 0 &&
							AI.SpawnedAmount >= AI.MinimumRequiredAmountToSpawn &&
							AI.SpawnedAmount == AI.MaximumRequiredAmountToSpawn)
							|| Population < AI.MinimumRequiredEntitiesToSpawn)
						{
							SpawnStack.Remove(AISpawner);
							continue;
						}

						if (((AI.MinimumRequiredAmountToSpawn > 0 && AI.SpawnedAmount < AI.MinimumRequiredAmountToSpawn) &&
							(AI.MaximumRequiredAmountToSpawn == 0 || AI.SpawnedAmount < AI.MaximumRequiredAmountToSpawn)) ||
							FMath::FRandRange(0.f, 100.f) <= AI.SpawnChance
							)
						{
							FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), FVector(RoamRadius));
							SpawnLocation.Z = GetActorLocation().Z + 200.f;
							FRotator SpawnRotation = FRotator(0.f, FMath::FRandRange(0.f, 360.f), 0.f);
							FVector SpawnScale = FVector(1.0f);
							InstancedMeshes[j]->AddInstanceWorldSpace(FTransform(SpawnRotation, SpawnLocation, SpawnScale));
							
							break;
						}
					}
				}
				
			}
		}
	}
#endif // WITH_EDITORONLY_DATA
	
}


FEXWAISpawnerData AEXWAIMultiSpawner::GetSpawnerDataFromCharacter(AEXWCharacter* Character)
{
	FEXWAISpawnerData SpawnerData;
	for (FEXWAISpawnerData AISpawnerData : AIs) {
		if (AISpawnerData.AICharacterClass == Character->GetClass() &&
			AISpawnerData.Level == Character->ProgressionLevel)
		{
			SpawnerData = AISpawnerData;
			break;
		}
	}
	return SpawnerData;
}

void AEXWAIMultiSpawner::Server_SpawnAI_Implementation(FEXWAISpawnerData AISpawnerData)
{
	if (AISpawnerData.AICharacterClass && AISpawnerData.BehaviorTree)
	{
		FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), FVector(RoamRadius));
		SpawnLocation.Z = GetActorLocation().Z + 200;

		if (APawn* AIPawnPtr = UAIBlueprintHelperLibrary::SpawnAIFromClass(this, AISpawnerData.AICharacterClass, AISpawnerData.BehaviorTree, SpawnLocation, GetActorRotation(), false, this))
		{
			if (AEXWCharacter* AICharacterPtr = Cast<AEXWCharacter>(AIPawnPtr))
			{
				AICharacterPtr->Server_SetLevel(AISpawnerData.Level);
				if (AAIController* AIController = AICharacterPtr->GetController<AAIController>())
				{
					AIController->GetBlackboardComponent()->SetValueAsEnum("Tier", uint8(AISpawnerData.Tier));
					AIController->GetBlackboardComponent()->SetValueAsObject("Spawner", this);
					AIController->GetBlackboardComponent()->SetValueAsFloat("RoamRadius", RoamRadius);
				}

				AICharacterPtr->OnCharacterDeath.AddDynamic(this, &AEXWAIMultiSpawner::HandleAIDeath);

				int32 Index;
				if (AIs.Find(AISpawnerData, Index)) {
					++AIs[Index].SpawnedAmount;
				}
				
				AICharacters.Add(MakeWeakObjectPtr<AEXWCharacter>(AICharacterPtr));
			}
		}
		else {
			UE_LOG(EXWAIMultiSpawnerLog, Error, TEXT("SpawnAIFromClass Failed!"));
		}
	}
	else
	{
		UE_LOG(EXWAIMultiSpawnerLog, Warning, TEXT("<%s> Could not spawn Ai"), *GetName());
	}
}

void AEXWAIMultiSpawner::TriggerRespawnTimer(FEXWAISpawnerData AISpawnerData)
{
	if (UWorld* World = GetWorld())
	{
		FTimerHandle RespawnTimerHandle;
		FTimerDelegate RespawnTimerDelegate;
		RespawnTimerDelegate.BindUFunction(this, "Server_SpawnAI", AISpawnerData);
		World->GetTimerManager().SetTimer(RespawnTimerHandle, RespawnTimerDelegate, 0.1, false, AISpawnerData.RespawnTimer);
	}
}


void AEXWAIMultiSpawner::HandleAIDeath(AEXWCharacter* DeadCharacter, AEXWCharacter* Killer)
{
	for (TWeakObjectPtr<AEXWCharacter> Character : AICharacters)
	{
		if (Character.IsValid())
		{
			if (Character.Get() == DeadCharacter)
			{
				TriggerRespawnTimer(GetSpawnerDataFromCharacter(DeadCharacter));
				AICharacters.Remove(Character);
				break;
			}
		}
	}
}