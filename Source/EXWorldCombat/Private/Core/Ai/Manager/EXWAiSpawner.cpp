// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Ai/Manager/EXWAiSpawner.h"
#include "Core/EXWCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


//General Character Log
DEFINE_LOG_CATEGORY(EXWAiSpawnerLog);

// Sets default values
AEXWAiSpawner::AEXWAiSpawner(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.f;

	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	SetRootComponent(SceneComponent);

#if WITH_EDITORONLY_DATA

	if (!IsRunningCommandlet())
	{
		SkeletalMeshComponent = CreateEditorOnlyDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
		if (SkeletalMeshComponent)
		{
			SkeletalMeshComponent->SetupAttachment(SceneComponent);
			SkeletalMeshComponent->SetHiddenInGame(true);
		}
	}
#endif // WITH_EDITORONLY_DATA

	SetCanBeDamaged(false);
	SetHidden(true);
}

// Called when the game starts or when spawned
void AEXWAiSpawner::BeginPlay()
{
	Super::BeginPlay();

	Server_SpawnAi();
}

void AEXWAiSpawner::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if(SkeletalMeshComponent !=NULL && SkeletalMesh != NULL)// needed to package
	SkeletalMeshComponent->SetSkeletalMesh(SkeletalMesh);
}

// Called every frame
void AEXWAiSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bIsDead && AiCharacter.IsValid())
	{
		if (AiCharacter.Get()->IsDead())
		{
			TriggerRespawnTimer();
		}
	}
	else if (!AiCharacter.IsValid())
	{
		TriggerRespawnTimer();
	}
	
}

void AEXWAiSpawner::SetAiCharacter(AEXWCharacter* NewAiCharacter)
{
	if (NewAiCharacter)
	{
		AiCharacter = MakeWeakObjectPtr<AEXWCharacter>(NewAiCharacter);
	}
}

void AEXWAiSpawner::Server_SpawnAi_Implementation()
{
	FVector SpawnLocation = GetActorLocation();
	SpawnLocation.Z = SpawnLocation.Z + 200;
	if (AiCharacterClass && BehaviorTree)
	{
		if (APawn* AiPawnPtr = UAIBlueprintHelperLibrary::SpawnAIFromClass(this, AiCharacterClass, BehaviorTree, SpawnLocation, GetActorRotation(), false, this))
		{
			if (AEXWCharacter* AiCharacterPtr = Cast<AEXWCharacter>(AiPawnPtr))
			{
				AiCharacterPtr->Server_SetLevel(Level);
				AAIController* AIController = AiCharacterPtr->GetController<AAIController>();
				
				AIController->GetBlackboardComponent()->SetValueAsVector("SpawnLocation", GetActorLocation());
				AIController->GetBlackboardComponent()->SetValueAsFloat("RoamRadius", RoamRadius);
				AiCharacterPtr->SetOwner(this);// for getting spwaner as querier for eqs as centre point

				SetAiCharacter(AiCharacterPtr);
			}
			bIsDead = false;
		}
	}
	else
	{
		UE_LOG(EXWAiSpawnerLog, Warning, TEXT("<%s> Could not spawn Ai"), *GetName());
	}
}

void AEXWAiSpawner::TriggerRespawnTimer()
{
	if (UWorld* World = GetWorld())
	{
		bIsDead = true;
		FTimerDelegate RespawnTimerDelegate;
		RespawnTimerDelegate.BindUFunction(this, FName("Respawn"));
		World->GetTimerManager().SetTimer(RespawnTimerHandle, RespawnTimerDelegate, 0.1, false, RespawnTimer);
	}
}

void AEXWAiSpawner::Respawn()
{
	if (AiCharacter.IsValid())
	{
		AiCharacter.Get()->Destroy(true);
	}
	Server_SpawnAi();
}

void AEXWAiSpawner::InitializeCharacter()
{

}

