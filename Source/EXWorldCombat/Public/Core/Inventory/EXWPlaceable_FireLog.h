// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Inventory/EXWPlaceable.h"
#include "EXWPlaceable_FireLog.generated.h"

class UStaticMeshComponent;
class UParticleSystemComponent;
class UNiagaraComponent;

/**
 * 
 */
UCLASS(Abstract)
class EXWORLDCOMBAT_API AEXWPlaceable_FireLog : public AEXWPlaceable
{
	GENERATED_BODY()
	
public:

	AEXWPlaceable_FireLog();

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* ParticleSystemComp;

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UNiagaraComponent* NiagaraComp;

	UPROPERTY(ReplicatedUsing = OnRep_IsActive, EditDefaultsOnly, BlueprintReadOnly, Category = "EXWorld|Placeable|FireLog|Data")
	uint8 bIsActive : 1 ;

	/** The items that can be used to ignite the fire log */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EXWorld|Placeable|FireLog|Data")
	TArray<FName> IgniteItems;

	/** The abilities that has to be available to ignite the fire log */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EXWorld|Placeable|FireLog|Data")
	TArray<FName> IgniteAbilities;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Placeable|FireLog")
	TMap<EEXWLifeSkillType, int32> Experiences;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Placeable|FireLog")
	void Server_SetIsActive(const bool NewValue);

protected:

	void OnConstruction(const FTransform& Transform) override;

	UFUNCTION()
	void OnRep_IsActive();

	void ActivateEffects(const bool NewValue);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType) override;

private:

	bool CanCharacterIgnite(class AEXWCharacter* SourceCharacter);
};
