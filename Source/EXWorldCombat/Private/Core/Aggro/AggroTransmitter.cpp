// Fill out your copyright notice in the Description page of Project Settings.


#include "AggroTransmitter.h"
#include "AggroHolder.h"


/*================================================================
* [Start] Aggro Transmitter Main Functionality
================================================================*/

//---------------------------------------------------------------------------------------------------------
// Sets default values for this component's properties
//---------------------------------------------------------------------------------------------------------
UAggroTransmitter::UAggroTransmitter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

//---------------------------------------------------------------------------------------------------------
// Called when the game starts
//---------------------------------------------------------------------------------------------------------
void UAggroTransmitter::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

//---------------------------------------------------------------------------------------------------------
// Called every frame
//---------------------------------------------------------------------------------------------------------
void UAggroTransmitter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void UAggroTransmitter::SendAggroFromObserveHeal(float HealValue, uint8 HealType)
{
	uint16 HoldersNum = GetValidHoldersNum();
	if (HoldersNum == 0) return;

	EXAggro::ValueType DevidedHeal = (EXAggro::ValueType)HealValue / (EXAggro::ValueType)HoldersNum;
	for (const auto& Holder : AggroHolders)
	{
		auto AggroData = FReceivedAggro::MakeObserveHealData(this, static_cast<EXAggro::ValueType>(HealValue), HealType);
		Holder->ReceiveAggro(AggroData);
	}
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
uint16 UAggroTransmitter::GetValidHoldersNum()
{
	if (AggroHolders.Num() == 0) return 0;

	uint16 Num = 0;
	for (int32 i = AggroHolders.Num() - 1; i >= 0; --i)
	{
		if (AggroHolders[i].IsValid())
		{
			++Num;
		}
		else
		{
			AggroHolders.RemoveAt(i);
		}
	}
	return Num;
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void UAggroTransmitter::AddAggroHolder(UAggroHolder* Holder)
{
	if (AggroHolders.Find(Holder) == INDEX_NONE)
	{
		AggroHolders.Add(Holder);
	}
	else
	{
		check(false);
	}
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void UAggroTransmitter::ClearAllHolders()
{
	AggroHolders.Empty();
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
bool UAggroTransmitter::TryRemoveAggroHolder(UAggroHolder* Holder)
{
	auto FoundIndex = AggroHolders.Find(Holder);
	if (FoundIndex != INDEX_NONE)
	{
		AggroHolders.RemoveAt(FoundIndex);
		return true;
	}
	else
	{
		return false;
	}

}

/*================================================================
* [End] Aggro Transmitter Main Functionality
================================================================*/

