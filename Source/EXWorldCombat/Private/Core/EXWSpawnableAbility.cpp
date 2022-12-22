// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/EXWSpawnableAbility.h"
#include "Net/UnrealNetwork.h"
#include "Core/EXWCharacter.h"
#include "Components/SceneComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "Library/EXWDataLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"

DEFINE_LOG_CATEGORY(EXWSALog);

// Sets default values
AEXWSpawnableAbility::AEXWSpawnableAbility()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	if (Root) {
		SetRootComponent(Root);
	}

	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
	if (CollisionComponent) {
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AEXWSpawnableAbility::OnCollisionBeginOverlap_Native);
		
		if (Root)
		{
			CollisionComponent->SetupAttachment(Root);
			CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
		}
	}
	// Adding a Movement component for the projectile
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	if (ProjectileMovementComponent) {
		ProjectileMovementComponent->SetIsReplicated(true);
		ProjectileMovementComponent->InitialSpeed = 2000.f;
		ProjectileMovementComponent->MaxSpeed = 2400.f;
		ProjectileMovementComponent->ProjectileGravityScale = 0.f;
		ProjectileMovementComponent->bIsHomingProjectile = true;
		ProjectileMovementComponent->HomingAccelerationMagnitude = ProjectileMovementComponent->MaxSpeed * 10;
		ProjectileMovementComponent->bRotationFollowsVelocity = true;
	}
}

// Called when the game starts or when spawned
void AEXWSpawnableAbility::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) {

		// Apply effects on targets depending on the type of the spawn-able ability
		if (SpawnableAbilityData.SpawnableAbilityType == EEXWSpawnableAbilityType::InstantAtTarget)
		{
			if (SpawnableAbilityData.SourceCharacter.IsValid() && SpawnableAbilityData.TargetCharacter.IsValid())
			{
				ApplyEffectsOnTarget(SpawnableAbilityData.TargetCharacter.Get());
			}
			else UE_LOG(EXWSALog, Warning, TEXT("<%s> is InstantAtTarget but the source character or/and target character are not valid."), *SpawnableAbilityData.Name.ToString());
		}
		else if (SpawnableAbilityData.SpawnableAbilityType == EEXWSpawnableAbilityType::InstantAtSelf)
		{
			if (SpawnableAbilityData.SourceCharacter.IsValid())
			{
				ApplyEffectsOnTarget(SpawnableAbilityData.SourceCharacter.Get());
			}
			else UE_LOG(EXWSALog, Warning, TEXT("<%s> is InstantAtSelf but the source character is not valid."), *SpawnableAbilityData.Name.ToString());
		}

		
		


			// Start the timer for an effect that will tick
			GetWorld()->GetTimerManager().SetTimer(TickingTimerHandle, this, &AEXWSpawnableAbility::TriggerTicking, SpawnableAbilityData.TickingRate, true);
		

		// Start the timer for when the Ability will be destroyed
		if (SpawnableAbilityData.bDestroyOnHit)
		{

			GetWorld()->GetTimerManager().SetTimer(DurationHandle, this, &AEXWSpawnableAbility::StartDestructionTimer, SpawnableAbilityData.DestroyTimer, false);
		}
		else {
			GetWorld()->GetTimerManager().SetTimer(DurationHandle, this, &AEXWSpawnableAbility::StartDestructionTimer, .1f, false, SpawnableAbilityData.Duration);
		}

	}

	// Effects && Sound
	if (SpawnableAbilityData.EmitterOnSpawn)
	{
		if (UWorld* World = GetWorld())
		{
			// Spawn Emitter 
			UGameplayStatics::SpawnEmitterAtLocation(World, SpawnableAbilityData.EmitterOnSpawn, GetTransform());
			// Spawn Sound
			// ...
		}
	}
}

// Called every frame
void AEXWSpawnableAbility::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEXWSpawnableAbility::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AEXWSpawnableAbility, SpawnableAbilityData);
	DOREPLIFETIME(AEXWSpawnableAbility, AffectedCharacters);
	DOREPLIFETIME(AEXWSpawnableAbility, bHasHit);
	DOREPLIFETIME(AEXWSpawnableAbility, bIsSetForDestruction);
}

void AEXWSpawnableAbility::SetSpawnableAbilityData(FEXWSpawnableAbilityData InData)
{
	SpawnableAbilityData = InData;
}

void AEXWSpawnableAbility::Server_SetSpawnableAbilityData_Implementation(FEXWSpawnableAbilityData InData)
{
	SpawnableAbilityData = InData;
}

AEXWCharacter* AEXWSpawnableAbility::GetSourceCharacter()
{
	if (SpawnableAbilityData.SourceCharacter.IsValid())
	{
		return SpawnableAbilityData.SourceCharacter.Get();
	}
	return nullptr;
}

AEXWCharacter* AEXWSpawnableAbility::GetTargetCharacter()
{
	if (SpawnableAbilityData.TargetCharacter.IsValid())
	{
		return SpawnableAbilityData.TargetCharacter.Get();
	}
	return nullptr;
}

void AEXWSpawnableAbility::InitializeMovement(const FVector InitialDirection, AActor* InTargetActor)
{
	// Initialize the velocity
	ProjectileMovementComponent->Velocity = InitialDirection * ProjectileMovementComponent->InitialSpeed;
	// Check if homing and the target is available
	if (ProjectileMovementComponent->bIsHomingProjectile && InTargetActor && SpawnableAbilityData.bIsHomingProjectile) {
		// look for a component in the center of the actor to travel towards it. The component should have "Center" as tag.
		TArray<UActorComponent*> TargetActorComponents = InTargetActor->GetComponentsByTag(UActorComponent::StaticClass(), "Center");
		UActorComponent* TargetCenterActorComp;
		// Set the homing target component as the center component if found, else just pick the root component.
		if (TargetActorComponents.IsValidIndex(0)) {
			TargetCenterActorComp = TargetActorComponents[0];
			if (USceneComponent* TargetCenterSceneComp = Cast<USceneComponent>(TargetCenterActorComp))
				ProjectileMovementComponent->HomingTargetComponent = TargetCenterSceneComp;
		}
		else ProjectileMovementComponent->HomingTargetComponent = InTargetActor->GetRootComponent();
	}
}

void AEXWSpawnableAbility::Server_InitializeMovement_Implementation(const FVector InitialDirection, AActor* InTargetActor)
{
	Multicast_InitializeMovement(InitialDirection, InTargetActor);
}

void AEXWSpawnableAbility::Multicast_InitializeMovement_Implementation(const FVector InitialDirection, AActor* InTargetActor)
{
	InitializeMovement(InitialDirection, InTargetActor);
}

void AEXWSpawnableAbility::OnCollisionBeginOverlap_Native(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (HasAuthority())
	{
		//Set it for next tick so it detects all actors
		GetWorldTimerManager().SetTimerForNextTick(this, &AEXWSpawnableAbility::ApplyEffectsOnCollision);
		//ApplyEffectsOnCollision();
		if (SpawnableAbilityData.bDestroyOnHit && bHasHit)
		{
			StartDestructionTimer();
		}
	}
	OnCollisionBeginOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void AEXWSpawnableAbility::ApplyEffectsOnCollision()
{
	TArray<AActor*> OverlappingActors;
	CollisionComponent->GetOverlappingActors(OverlappingActors);
	for (AActor* ActorTemp : OverlappingActors)
	{
		if (AEXWCharacter* EXWCharacter = Cast<AEXWCharacter>(ActorTemp))
		{
			if (UEXWDataLibrary::ApplyAttributeMultiEffectsByFactionCheck(SpawnableAbilityData.SourceCharacter.Get(), EXWCharacter, SpawnableAbilityData.AttributeEffectsOnCollision))
			{
				bHasHit = true;
				if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(GetOwner()))
				{
					FEXWReactionSendingParams ReactionSendingParams;
					UEXWDataLibrary::MakeReactionSendingParams(ReactionSendingParams,
						SpawnableAbilityData.ReactionRowName,
						SpawnableAbilityData.bUseCharacterReactionDT,
						OwnerCharacter, EXWCharacter);
					OwnerCharacter->SendReaction(ReactionSendingParams);
				}

				// Spawn Emitter
				if (SpawnableAbilityData.EmitterOnApplyEffect)
				{
					Multicast_SpawnEmitterOnTarget(SpawnableAbilityData.EmitterOnApplyEffect, EXWCharacter, SpawnableAbilityData.EmitterOnApplyEffectSocket);
				}

				// Spawn Sound 
			}
		}
	}
}

void AEXWSpawnableAbility::ApplyEffectsOnTarget(AEXWCharacter* TargetCharacter)
{
	if (TargetCharacter) {
		if (SpawnableAbilityData.bAffectOnce && !AffectedCharacters.Contains(TargetCharacter))
		{
			if (UEXWDataLibrary::ApplyAttributeMultiEffectsByFactionCheck(SpawnableAbilityData.SourceCharacter.Get(), TargetCharacter, SpawnableAbilityData.AttributeEffectsOnTarget))
			{
				bHasHit = true;
				AffectedCharacters.AddUnique(TargetCharacter);

				// Spawn Emitter
				if (SpawnableAbilityData.EmitterOnApplyEffect)
				{
					Multicast_SpawnEmitterOnTarget(SpawnableAbilityData.EmitterOnApplyEffect, TargetCharacter, SpawnableAbilityData.EmitterOnApplyEffectSocket);
				}

				// Spawn Sound 
			}
		}
	}
}

void AEXWSpawnableAbility::TriggerTicking()
{
	if (!bIsSetForDestruction)
	{
		if (!SpawnableAbilityData.bAffectOnce)
		{
			AffectedCharacters.Empty();
		}
		TArray<AActor*> OverlappingActors;
		CollisionComponent->GetOverlappingActors(OverlappingActors);
		for (AActor* ActorTemp : OverlappingActors)
		{
			if (AEXWCharacter* EXWCharacter = Cast<AEXWCharacter>(ActorTemp))
			{
				if (!AffectedCharacters.Contains(EXWCharacter))
				{
					if (UEXWDataLibrary::ApplyAttributeMultiEffectsByFactionCheck(SpawnableAbilityData.SourceCharacter.Get(), EXWCharacter, SpawnableAbilityData.AttributeEffectsOnTick))
					{
						bHasHit = true;
						AffectedCharacters.AddUnique(EXWCharacter);

						// Spawn Emitter
						if (SpawnableAbilityData.EmitterOnApplyEffect)
						{
							Multicast_SpawnEmitterOnTarget(SpawnableAbilityData.EmitterOnApplyEffect, EXWCharacter, SpawnableAbilityData.EmitterOnApplyEffectSocket);
						}

						// Spawn Sound 
					}
				}
			}
		}
	}
}

void AEXWSpawnableAbility::StartDestructionTimer()
{
	Multicast_HideAbility();
	// Launch the timer for destruction
	GetWorld()->GetTimerManager().SetTimer(DurationHandle, this, &AEXWSpawnableAbility::ForceDestroy, SpawnableAbilityData.TickingRate, true);
	bIsSetForDestruction = true;

	// Spawn Emitter
	if (SpawnableAbilityData.EmitterOnDestroy)
	{
		Multicast_SpawnEmitter(SpawnableAbilityData.EmitterOnDestroy);
	}
	if (SpawnableAbilityData.NiagaraEmitterOnDestroy)
	{
		if(SpawnableAbilityData.EmitterOnDestroySocket=="none")
		{
			Multicast_SpawnNiagaraEmitter(SpawnableAbilityData.NiagaraEmitterOnDestroy);
		}
		else
		{
			FVector SocketWorldLocation= SpawnableAbilityData.SourceCharacter->GetMesh()->GetSocketLocation(SpawnableAbilityData.EmitterOnDestroySocket);
			Multicast_SpawnNiagaraEmitterOnTarget(SpawnableAbilityData.NiagaraEmitterOnDestroy, SpawnableAbilityData.SourceCharacter->GetMesh(), SpawnableAbilityData.EmitterOnDestroySocket, SocketWorldLocation, FRotator(0, 0, 0), EAttachLocation::KeepWorldPosition);
		}
	}
	// Sound
	// ...
}

void AEXWSpawnableAbility::ForceDestroy()
{
	if (HasAuthority())
	{
		if (SpawnableAbilityData.SpawnableAbilityType == EEXWSpawnableAbilityType::InstantAtSelf)
		{
			if (SpawnableAbilityData.SourceCharacter.IsValid())
			{

				if (AffectedCharacters.Contains(SpawnableAbilityData.SourceCharacter.Get()))
				{
					UEXWDataLibrary::ReverseAttributeMultiEffects(SpawnableAbilityData.SourceCharacter.Get(), SpawnableAbilityData.SourceCharacter.Get(), SpawnableAbilityData.AttributeEffectsOnTarget);
				}

			}
		}
		Destroy(true);
	}
}

void AEXWSpawnableAbility::Server_HideAbility_Implementation()
{
	Multicast_HideAbility();
}

void AEXWSpawnableAbility::Multicast_HideAbility_Implementation()
{
	SetActorEnableCollision(false);
	GetRootComponent()->SetVisibility(false, true);
}

void AEXWSpawnableAbility::Multicast_SpawnEmitter_Implementation(UParticleSystem* EmitterToSpawn)
{
	if (UWorld* World = GetWorld())
	{
		UGameplayStatics::SpawnEmitterAtLocation(World, EmitterToSpawn, GetTransform());
	}
}

void AEXWSpawnableAbility::Multicast_SpawnNiagaraEmitter_Implementation(UNiagaraSystem* EmitterToSpawn)
{
	if (UWorld* World = GetWorld())
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(World, EmitterToSpawn, GetTransform().GetLocation(), FRotator(GetTransform().GetRotation()), GetTransform().GetScale3D());
	}
}

void AEXWSpawnableAbility::Multicast_SpawnEmitterOnTarget_Implementation(UParticleSystem* EmitterToSpawn, AEXWCharacter* InTarget, const FName SocketName /*= "None"*/)
{
	if (UWorld* World = GetWorld())
	{
		if (InTarget)
		{
			FTransform SpawnTransform;
			SpawnTransform = (InTarget->GetMesh()) ? InTarget->GetMesh()->GetSocketTransform(SocketName) : InTarget->GetTransform();
			UGameplayStatics::SpawnEmitterAtLocation(World, EmitterToSpawn, SpawnTransform);
		}
	}
}

void AEXWSpawnableAbility::Multicast_SpawnNiagaraEmitterOnTarget_Implementation(UNiagaraSystem* NiagraTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType)
{
	if (UWorld* World = GetWorld())
	{
		if (AttachToComponent)
		{
			UNiagaraFunctionLibrary::SpawnSystemAttached(NiagraTemplate, AttachToComponent, AttachPointName, Location, Rotation, LocationType, true);
		}
	}
}
