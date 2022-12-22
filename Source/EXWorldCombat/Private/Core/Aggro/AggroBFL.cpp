// Fill out your copyright notice in the Description page of Project Settings.


#include "AggroBFL.h"
#include "AggroHolder.h"
#include "AggroTransmitter.h"


void UAggroBFL::SendAggroFromTakeDamage(UAggroTransmitter* From, UAggroHolder* To, float Damage, uint8 DamageType)
{
	check(From && To);
	if (!From || !To) return;
	auto Data = FReceivedAggro::MakeTakeDamageData(From, static_cast<EXAggro::ValueType>(Damage), DamageType);
	To->ReceiveAggro(Data);
}

void UAggroBFL::SendAggroFromObserveChangeRange(UAggroTransmitter* From, UAggroHolder* To, EAgRangeLevel RangeLevel)
{
	check(From && To);
	if (!From || !To) return;
	auto Data = FReceivedAggro::MakeObserveChangeRangeData(From, static_cast<uint8>(RangeLevel));
	To->ReceiveAggro(Data);
}

void UAggroBFL::SendAggroFromObserveHeal(UAggroTransmitter* From, float Heal, uint8 HealType)
{
	check(From);
	if (!From) return;
	From->SendAggroFromObserveHeal(Heal, HealType);
}
