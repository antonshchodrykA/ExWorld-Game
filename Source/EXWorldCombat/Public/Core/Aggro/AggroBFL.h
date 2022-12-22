// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AggroBase.h"
//#include "GameFramework/Actor.h"
//#include "AggroHolder.h"
#include "AggroBFL.generated.h"

/**
 * 
 */

class UAggroHolder;
class UAggroTransmitter;

UCLASS()
class EXWORLDCOMBAT_API UAggroBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	static void SendAggroFromTakeDamage(UAggroTransmitter* From, UAggroHolder* To, float Damage, uint8 DamageType);

	UFUNCTION(BlueprintCallable)
	static void SendAggroFromObserveChangeRange(UAggroTransmitter* From, UAggroHolder* To, EAgRangeLevel RangeLevel);

	UFUNCTION(BlueprintCallable)
	static void SendAggroFromObserveHeal(UAggroTransmitter* From, float Heal, uint8 HealType);
};
