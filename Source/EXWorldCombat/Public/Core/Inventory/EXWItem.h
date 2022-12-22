// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/EXWInteractable.h"
#include "EXWItem.generated.h"

class UStaticMeshComponent;
class UBoxComponent;
class AEXWCharacter;
class UWidgetComponent;
class UBillboardComponent;
class UParticleSystemComponent;
class UNiagaraComponent;

UCLASS()
class EXWORLDCOMBAT_API AEXWItem : public AActor, public IEXWInteractable
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* CollisionComp;

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UBillboardComponent* Billboard;

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* ParticleSystemComp;

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UNiagaraComponent* NiagaraComp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	FName ItemID = "None";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	int32 Count = 1;

public:	
	// Sets default values for this actor's properties
	AEXWItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	void SetMesh(UStaticMesh* NewMesh);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	UStaticMeshComponent* GetMesh() {return Mesh;};

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	void SetItemData(const FName NewItemID, const int32 NewCount = 1, const bool bForceLootable = false);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory|Item")
	void Server_SetItemData(const FName NewItemID, const int32 NewCount = 1, const bool bForceLootable = false);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "Inventory|Item")
	void Multicast_SetItemData(const FName NewItemID, const int32 NewCount = 1, const bool bForceLootable = false);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory|Item")
	void Server_SetCount(const int32 NewCount = 1);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory|Item")
	void Server_Destroy();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory|Item")
	void Server_SetIsLootable(const bool bNewIsLootable);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Item")
	void UpdateItemData();

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "Inventory|Item")
	void Multicast_UpdateItemData();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Inventory|Item")
	void Server_EnablePhysics(const bool bNewCollisionState);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "Inventory|Item")
	void Multicast_EnablePhysics(const bool bNewCollisionState);

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType) override;

	virtual void OnReceiveClick(AEXWCharacter* SourceCharacter) override;

	virtual UWidgetComponent* GetInteractionWidgetComponent() override;

	virtual void SetInteractionWidgetVisibility(const bool bNewVisibility = true) override;

protected:

	virtual void StartTimers();

	// This timer will cause the item to be loot-able by everyone
	FTimerHandle LootTimer;

	// This timer will cause the item to be destroyed
	FTimerHandle DestroyTimer;

	// This timer will cause the item to change the Physics
	FTimerHandle PhysicsTimer;

	// Whether or not this item is loot-able by everyone
	UPROPERTY(Replicated)
	uint8 bIsLootable : 1;
};
