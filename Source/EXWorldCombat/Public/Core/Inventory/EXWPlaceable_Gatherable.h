// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Inventory/EXWPlaceable.h"
#include "Library/Inventory/EXWInventoryStruct.h"
#include "EXWPlaceable_Gatherable.generated.h"

class AEXWCharacter;

/**
 * 
 */
UCLASS(Abstract)
class EXWORLDCOMBAT_API AEXWPlaceable_Gatherable : public AEXWPlaceable
{
	GENERATED_BODY()

public:

	AEXWPlaceable_Gatherable();

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	TArray<FEXWGatheringRate> GatheringItemRates;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	TMap<EEXWLifeSkillType, int32> Experiences;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	float GatheringDuration;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	float RespawnTime;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	EEXWEquipmentType RequiredTool = EEXWEquipmentType::ET_Pickaxe;

	// Make sure the montage is a loop
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	TMap<EEXWGender,class UAnimMontage*> GatheringMontages;

	// Make sure the montage is a loop
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	class UAnimMontage* GatheringMontage = nullptr;

	// The ending part of the gathering montage
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	FName MontageEndSectionName = FName("None");

	UPROPERTY(ReplicatedUsing = OnRep_IsResourceAvailable, BlueprintReadOnly, Category = "EXWorld|Gatherable")
	uint8 bIsResourceAvailable : 1;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Gatherable")
	void Server_DropItems(AEXWCharacter* SourceCharacter);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Gatherable")
	void Server_Respawn();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Gatherable")
	void SetIsResourceAvailable(const bool bNewValue);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Gatherable")
	void OnUpdateResourceAvailablity();
	virtual void OnUpdateResourceAvailablity_Native();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	FTimerHandle GatheringTimerHandle;

protected:

	void StartGathering(AEXWCharacter* SourceCharacter);

	void StopGathering();

	void OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:

	UFUNCTION()
	void OnRep_IsResourceAvailable();

	UPROPERTY(Replicated)
	TWeakObjectPtr<AEXWCharacter> GatheringCharacter;

	FTimerHandle RespawnTimerHandle;
};
