
#include "AggroBase.h"
#include "AggroTransmitter.h"


DEFINE_LOG_CATEGORY(EXAgroLog);

namespace EXAggro
{
	const TArray<FString> RangeLevels = { TEXT("OutOfRange"), TEXT("LongRange"), TEXT("ShortRange") };
}


/*================================================================
* [Start] ReceivedAggro Data Functionality
================================================================*/

FReceivedAggro::ParamType FReceivedAggro::ParamNone = FReceivedAggro::ParamType(nullptr);

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
FReceivedAggro::FReceivedAggro(EAggroSource InSourceType, EXAggro::TargetBaseType* InTarget, ParamType InParam1, ParamType InParam2)
	: SourceType(InSourceType), Target(InTarget), Param1(InParam1), Param2(InParam2)
{
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
FString FReceivedAggro::ToString() const
{
	UEnum* NativeEnum = StaticEnum<EAggroSource>();
	FString StringType = NativeEnum->GetNameStringByValue((int64)SourceType);

	FString Name;
	if (Target) Target->GetName(Name);


	return FString::Format(TEXT("AggroData: Type={0}, TargetName={1}, Param1={2}, Param2={3}"), 
		{StringType, Name, ParamToString(Param1), ParamToString(Param2)});
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
FString FReceivedAggro::ParamToString(const FReceivedAggro::ParamType& InParam) const
{
	auto TypeIndex = InParam.GetCurrentSubtypeIndex();
	switch (TypeIndex)
	{
	case 0: return FString::Format(TEXT("Type=double, Value={0}"),
		{ FString::SanitizeFloat(InParam.GetSubtype<EXAggro::ValueType>()) });
	case 1: return FString::Format(TEXT("Type=bool, Value={0}"),
			{ InParam.GetSubtype<bool>() ? TEXT("true") : TEXT("false") });
	case 2: return FString::Format(TEXT("Type=uint8, Value={0}"),
		{ FString::FromInt(InParam.GetSubtype<uint8>()) });
	case 3: return TEXT("Type=nullptr");
	default: return TEXT("Type=error");
	}
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
TSharedPtr<FReceivedAggro> FReceivedAggro::MakeTakeDamageData(EXAggro::TargetBaseType* Target, EXAggro::ValueType DamageValue, uint8 DamageType)
{
	return MakeShared<FReceivedAggro>(EAggroSource::TakeDamage, Target, 
		static_cast<FReceivedAggro::ParamType>(DamageValue), static_cast<FReceivedAggro::ParamType>(DamageType));
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
TSharedPtr<FReceivedAggro> FReceivedAggro::MakeObserveChangeRangeData(EXAggro::TargetBaseType* Target, uint8 RangeLevel)
{
	return MakeShared<FReceivedAggro>(EAggroSource::ObserveChangeRange, Target, 
		static_cast<FReceivedAggro::ParamType>(RangeLevel));
}

TSharedPtr<FReceivedAggro> FReceivedAggro::MakeObserveHealData(EXAggro::TargetBaseType* Target, EXAggro::ValueType HealValue, uint8 HealType)
{
	return MakeShared<FReceivedAggro>(EAggroSource::ObserveHeal, Target,
		static_cast<FReceivedAggro::ParamType>(HealValue), static_cast<FReceivedAggro::ParamType>(HealType));
}

/*================================================================
* [End] ReceivedAggro Data Functionality
================================================================*/
