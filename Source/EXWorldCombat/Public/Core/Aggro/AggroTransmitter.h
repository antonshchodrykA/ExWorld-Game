// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AggroBase.h"
#include "AggroTransmitter.generated.h"

class UAggroHolder;

UCLASS(BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXWORLDCOMBAT_API UAggroTransmitter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAggroTransmitter();

	UFUNCTION(BlueprintCallable)
	void SendAggroFromObserveHeal(float HealValue, uint8 HealType);

	void AddAggroHolder(UAggroHolder* Holder);
	bool TryRemoveAggroHolder(UAggroHolder* Holder);

	UFUNCTION(BlueprintCallable)
	void ClearAllHolders();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	uint16 GetValidHoldersNum();

	// NPC's that have any aggro data about this transmitter
	TArray<TLazyObjectPtr<UAggroHolder>> AggroHolders;
};
