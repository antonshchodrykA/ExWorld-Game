// Fill out your copyright notice in the Description page of Project Settings.


#include "AggroHolder.h"
#include "UObject/NameTypes.h"

// ToDo: move to ProjectCoreVariables file and then this file to PCH
const FString UAggroHolder::EXStringNone = FString{};

/*================================================================
* [Start] Aggro Holder Main Functionality
================================================================*/

//---------------------------------------------------------------------------------------------------------
// Sets default values for this component's properties
//---------------------------------------------------------------------------------------------------------
UAggroHolder::UAggroHolder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Multipliers = {
	{GetMultiplierHash(EAggroSource::ObserveChangeRange, FString::FromInt((uint8)EAgRangeLevel::OutOfRange)), 0.0},
	{GetMultiplierHash(EAggroSource::ObserveChangeRange, FString::FromInt((uint8)EAgRangeLevel::LongRange)), 1.1},
	{GetMultiplierHash(EAggroSource::ObserveChangeRange, FString::FromInt((uint8)EAgRangeLevel::ShortRange)), 1.3} };

	AggroTable.Owner = this;
	// ...
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::ReceiveAggro(TSharedPtr<FReceivedAggro> ReceivedData)
{
	ReceiveAggro(TArray<TSharedPtr<FReceivedAggro>>{ReceivedData});
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::ReceiveAggro(TArray<TSharedPtr<FReceivedAggro>> ReceivedData)
{
	FilterReceivedData(ReceivedData);
	TryProcessReceivedData(ReceivedData);


	if (TryChangeTarget())
	{
		OnTargetChanged.Broadcast(Target.Get());
	}
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::ClearAllAggro()
{
	if (Target.IsValid())
	{
		AggroTable.ClearAll();
		Target.Reset();
		OnTargetChanged.Broadcast(nullptr);
	}
	else
	{
		AggroTable.ClearAll();
		Target.Reset();
	}
}

//---------------------------------------------------------------------------------------------------------
// Called when the game starts
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



//---------------------------------------------------------------------------------------------------------
// Called every frame
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//---------------------------------------------------------------------------------------------------------
// When any aggro data changed we call this function to understand if the most interesting target is changed
//---------------------------------------------------------------------------------------------------------
bool UAggroHolder::TryChangeTarget()
{
	auto TopTarget = AggroTable.GetTopTarget();
	if (!TopTarget.IsValid())
	{
		Target.Reset();
		return false;
	}

	if (Target.IsValid())
	{		
		if (Target == TopTarget.Pin()->Target)
		{
			return false;
		}
		else
		{
			Target = TopTarget.Pin()->Target;
			return true;
		}
	}
	else
	{
		Target = TopTarget.Pin()->Target;
		return true;
	}
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::FilterReceivedData(TArray<TSharedPtr<FReceivedAggro>> & ReceivedData) const
{
}

//---------------------------------------------------------------------------------------------------------
// When Derrived class will override, it can use this function and see UnProcessed Data as we removeing Processed Data
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::TryProcessReceivedData(TArray<TSharedPtr<FReceivedAggro>> & ReceivedData)
{
	for (int32 i = ReceivedData.Num() - 1; i >= 0; --i)
	{
		check(ReceivedData[i].IsValid());

		switch (ReceivedData[i]->SourceType)
		{
			case EAggroSource::TakeDamage:
			{
				ProcessTakeDamage(ReceivedData[i]);
				ReceivedData.RemoveAt(i);
			}
			break;
			case EAggroSource::ObserveChangeRange:
			{
				ProcessObserveChangeRange(ReceivedData[i]);
				ReceivedData.RemoveAt(i);
			}
			break;
			case EAggroSource::ObserveHeal:
			{
				ProcessObserveHeal(ReceivedData[i]);
				ReceivedData.RemoveAt(i);
			}
			break;
			default:
			{
			}
		}
	}
}

//---------------------------------------------------------------------------------------------------------
// Process Take Damage received data
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::ProcessTakeDamage(const TSharedPtr<FReceivedAggro>& Data)
{
	check(Data->Param1.HasSubtype<EXAggro::ValueType>());
	if (!Data->Param1.HasSubtype<EXAggro::ValueType>()) return;

	auto FinalValue = GetMultiplier(Data->SourceType) * Data->Param1.GetSubtype<EXAggro::ValueType>();
	UE_LOG(EXAgroLog, Log, TEXT("->\n\n\t%s ----------START----------\n\tReceivedData:{%s} FinalValue=%s"), *FString(__FUNCTION__), *Data->ToString(), *FString::SanitizeFloat(FinalValue));
	AggroTable.EditValue(Data->Target, FinalValue);

#ifdef WITH_EDITOR
	FString TableState;
	AggroTable.GetState(TableState);
	UE_LOG(EXAgroLog, Log, TEXT("->\n\t%s ----------FINISH AND PRINT STATE----------\n\tTableState:{%s}\n\n"), *FString(__FUNCTION__), *TableState);
#endif
}

//---------------------------------------------------------------------------------------------------------
// Process observe heal received data (Think... may be connect ProcessTakeDamage function with ProcessobserveHeal)
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::ProcessObserveHeal(const TSharedPtr<FReceivedAggro>& Data)
{
	check(Data->Param1.HasSubtype<EXAggro::ValueType>());
	if (!Data->Param1.HasSubtype<EXAggro::ValueType>()) return;

	auto FinalValue = GetMultiplier(Data->SourceType) * Data->Param1.GetSubtype<EXAggro::ValueType>();
	UE_LOG(EXAgroLog, Log, TEXT("->\n\n\t%s ----------START----------\n\tReceivedData:{%s} FinalValue=%s"), *FString(__FUNCTION__), *Data->ToString(), *FString::SanitizeFloat(FinalValue));
	AggroTable.EditValue(Data->Target, Data->Param1.GetSubtype<EXAggro::ValueType>());

#ifdef WITH_EDITOR
	FString TableState;
	AggroTable.GetState(TableState);
	UE_LOG(EXAgroLog, Log, TEXT("->\n\t%s ----------FINISH AND PRINT STATE---------- \n\tTableState:{%s}\n\n"), *FString(__FUNCTION__), *TableState);
#endif
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::ProcessObserveChangeRange(const TSharedPtr<FReceivedAggro>& Data)
{
	check(Data->Param1.HasSubtype<uint8>());
	if (!Data->Param1.HasSubtype<uint8>()) return;

	uint8 RangeLevel = Data->Param1.GetSubtype<uint8>();
	check(EXAggro::RangeLevels.IsValidIndex(RangeLevel));
	if (!EXAggro::RangeLevels.IsValidIndex(RangeLevel)) return;

	// To get RangeMultiplier as (Enum + FString)
	//const FString & RangePostfix = EXAggro::RangeLevels[RangeLevel];
	//auto FinalValue = GetMultiplier(Data->SourceType, RangePostfix);

	// To get RangeMultiplier as (Enum + uint)
	auto FinalValue = GetMultiplier(Data->SourceType, FString::FromInt(RangeLevel));
	UE_LOG(EXAgroLog, Log, TEXT("->\n\n\t%s ----------START----------\n\t%s FinalValue=%s"), *FString(__FUNCTION__), *Data->ToString(), *FString::SanitizeFloat(FinalValue));
	AggroTable.EditMultiplier(Data->Target, FinalValue, EXAggro::EMI_Range, true);

#ifdef WITH_EDITOR
	FString TableState;
	AggroTable.GetState(TableState);
	UE_LOG(EXAgroLog, Log, TEXT("->\n\t%s ----------FINISH AND PRINT STATE----------\n\tTableState:{%s}"), *FString(__FUNCTION__), *TableState);
#endif
}

/*================================================================
* [End] Aggro Holder Main Functionality
================================================================*/

/*================================================================
* [Start] Multiplier Functionality (ToDo: Transfer to seperate file)
================================================================*/

//---------------------------------------------------------------------------------------------------------
// Get multiplier hash for Multipliers unoredred_map
//---------------------------------------------------------------------------------------------------------
uint32 UAggroHolder::GetMultiplierHash(EAggroSource Source,const FString & Postfix)
{
	FString HashSource = FString::FromInt((int32)Source).Append(Postfix);
	uint32 Hash = GetTypeHash(HashSource);
	//uint8* Buffer = nullptr;
	//FString::ToBlob(HashSource, Buffer, HashSource.Len());
	//uint32 Hash = FCrc::MemCrc32(Buffer, HashSource.Len() / 3 + 1);
	return Hash;
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
EXAggro::ValueType UAggroHolder::GetMultiplier(EAggroSource Source,const FString & Postfix) const
{
	auto Res = Multipliers.find(GetMultiplierHash(Source, Postfix));
	if (Res != Multipliers.end())
	{
		return Res->second;
	}
	else
	{
		return 1.0;
	}
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void UAggroHolder::AddMultiplier(FAggroMultiplier InMultiplier)
{
	auto Hash = GetMultiplierHash(InMultiplier.SourceType, InMultiplier.Postfix);
	Multipliers.insert({ Hash, InMultiplier.Value });
}

/*================================================================
* [End] Multiplier Functionality (ToDo: Transfer to seperate file)
=================================================================*/

/*================================================================
* [End] Aggro Holder Debug
================================================================*/

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
FString UAggroHolder::GetState() const
{
	FString Result;
	AggroTable.GetState(Result);
	return Result;
}

/*================================================================
* [End] Aggro Holder Debug
================================================================*/