// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Library/EXWDataStruct.h"
#include "EXWSpawnableAbility.generated.h"

class AEXWCharacter;
class UCapsuleComponent;
class USceneComponent;
class UProjectileMovementComponent;

DECLARE_LOG_CATEGORY_EXTERN(EXWSALog, Log, All);

UCLASS()
class EXWORLDCOMBAT_API AEXWSpawnableAbility : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEXWSpawnableAbility();

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Data")
	FEXWSpawnableAbilityData SpawnableAbilityData;

	/** Shape component used for collision */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* Root;

	/** Shape component used for collision */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CollisionComponent;

	/** Projectile movement component that controls the movement of the projectile (Speed, Homing or not homing)*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(Replicated)
	TArray<AEXWCharacter*> AffectedCharacters; // TODO : TWeakPtrObj

	/** Is true after colliding with something */
	UPROPERTY(Replicated)
	bool bHasHit = false;

	UPROPERTY(Replicated)
	bool bIsSetForDestruction = false;

	UPROPERTY()
	FTimerHandle TickingTimerHandle;
	
	UPROPERTY()
	FTimerHandle DurationHandle;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Called for replicating class variables */
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/**
	 * Data Setters and Getters
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Spawnable Ability|Data")
	void SetSpawnableAbilityData(FEXWSpawnableAbilityData InData);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Spawnable Ability|Data")
	void Server_SetSpawnableAbilityData(FEXWSpawnableAbilityData InData);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Spawnable Ability|Data")
	AEXWCharacter* GetSourceCharacter();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Spawnable Ability|Data")
	AEXWCharacter* GetTargetCharacter();

	/**
	 * Temp Values
	 */
	UPROPERTY()
	FVector InitialDirectionCashed;
	UPROPERTY()
	AActor* TargetActor;

	/**
	 * Movement
	 */

	/** Initiate the SpawnableAbility movement data by setting its target actor to home towards and Initial direction to head to. (Does not replicate)
	 * @param InitialDirection The initial direction that the SpawnableAbility will be launched into.
	 * @param TargetActor The target actor to home towards.
	 */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Spawnable Ability|Movement")
	virtual void InitializeMovement(const FVector InitialDirection, AActor* InTargetActor);

	/** Initiate the SpawnableAbility movement data by setting its target actor to home towards and Initial direction to head to. (On the server side and calls NetMulticast)
	 * @param InitialDirection The initial direction that the SpawnableAbility will be launched into.
	 * @param TargetActor The target actor to home towards.
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Spawnable Ability|Movement")
	virtual void Server_InitializeMovement(const FVector InitialDirection, AActor* InTargetActor);

	/** Initiate the SpawnableAbility movement data by setting its target actor to home towards and Initial direction to head (On all clients)
	 * @param InitialDirection The initial direction that the SpawnableAbility will be launched into.
	 * @param TargetActor The target actor to home towards.
	 */
	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Spawnable Ability|Movement")
	virtual void Multicast_InitializeMovement(const FVector InitialDirection, AActor* InTargetActor);

	/**
	 * Collision
	 */

	UFUNCTION()
	virtual void OnCollisionBeginOverlap_Native(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Spawnable Ability|Collision")
	void OnCollisionBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/**
	 * Effects
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Spawnable Ability|Effect")
	void ApplyEffectsOnCollision();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Spawnable Ability|Effect")
	void ApplyEffectsOnTarget(AEXWCharacter* TargetCharacter);

	/**
	 * Timer
	 */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Spawnable Ability|Timer")
	void TriggerTicking();

	/**
	 * Destruction & Hiding
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Spawnable Ability|Destroy")
	void StartDestructionTimer();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Spawnable Ability|Destroy")
	void ForceDestroy();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Spawnable Ability|Destroy")
	void Server_HideAbility();

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Spawnable Ability|Destroy")
	void Multicast_HideAbility();

	/**
	 * Emitter and Sound
	 */

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Spawnable Ability|Emitter")
	void Multicast_SpawnEmitter(UParticleSystem* EmitterToSpawn);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Spawnable Ability|Emitter")
	void Multicast_SpawnNiagaraEmitter(UNiagaraSystem* EmitterToSpawn);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Spawnable Ability|Emitter")
	void Multicast_SpawnEmitterOnTarget(UParticleSystem* EmitterToSpawn, AEXWCharacter* InTarget, const FName SocketName = "spine_02");

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Spawnable Ability|Emitter")
	void Multicast_SpawnNiagaraEmitterOnTarget(UNiagaraSystem* NiagraTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType);
};