// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Containers/Union.h"

#include <unordered_map>

#include "AggroTable.h"
#include "AggroBase.h"
#include "AggroTransmitter.h"

#include "AggroHolder.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetChanged, UAggroTransmitter*, Target);


/* UAggroHodler -> Component to calculate the most interesting Target for Owner.
*  Class take different Aggro Data from different Sources and trigger TargetChanged
*  when the most interesting Target was changed */
UCLASS(BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class EXWORLDCOMBAT_API UAggroHolder : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Sets default values for this component's properties
	UAggroHolder();

	//

	// Any Aggro Transmitter(Player or someone else) can trigger this function to transmit Aggro data to Holder
	void ReceiveAggro(TSharedPtr<FReceivedAggro> ReceivedData);
	void ReceiveAggro(TArray<TSharedPtr<FReceivedAggro>> ReceivedData);

	// Delegate handle OnChangeTarget event (when NPC need to change his target)
	UPROPERTY(BlueprintAssignable)
	FOnTargetChanged OnTargetChanged;

	// Data Table Row Name (with NPC Aggro multipliers presets)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EXWorld|Aggro|Settings")
	FName MultipliersPresetRow;

	// DEBUG
	UFUNCTION(BlueprintCallable)
	FString GetState() const;

	// Get Current Top Most Interesting Aggro Target
	UFUNCTION(BlueprintCallable)
	UAggroTransmitter* GetTopTarget() const { return Target.Get(); }

	// Clear all dynamic aggro information (clear all possible targets) (for example when Combat finished)
	UFUNCTION(BlueprintCallable)
	void ClearAllAggro();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void FilterReceivedData(TArray<TSharedPtr<FReceivedAggro>>& ReceivedData) const;
	virtual void TryProcessReceivedData(TArray<TSharedPtr<FReceivedAggro>>& ReceivedData);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	//When any aggro data changed we call this function to understand if the most interesting target is changed
	bool TryChangeTarget();

	// Get multiplier hash for Multipliers unoredred_map
	static uint32 GetMultiplierHash(EAggroSource Source, const FString & Postfix = EXStringNone);
	EXAggro::ValueType GetMultiplier(EAggroSource Source, const FString & Postfix = EXStringNone) const;
	void AddMultiplier(FAggroMultiplier InMultiplier);

	void ProcessTakeDamage(const TSharedPtr<FReceivedAggro>& Data);
	void ProcessObserveHeal(const TSharedPtr<FReceivedAggro> & Data);
	void ProcessObserveChangeRange(const TSharedPtr<FReceivedAggro>& Data);

private:

	// table with all possible targets and there total aggro value
	AgTable AggroTable;

	// multipliers for different aggro data types
	std::unordered_map<uint32, EXAggro::ValueType> Multipliers;

	EXAggro::TargetType Target;
	//TLazyObjectPtr<AgTable::TargetBaseType> OverrideTarget;

	// Static Empty string for default string references
	// ToDo: move to ProjectCoreVariables file and then this file to PCH
	const static FString EXStringNone;
};
