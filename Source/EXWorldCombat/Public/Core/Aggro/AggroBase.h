

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Union.h"
#include "Engine/DataTable.h"
#include "AggroBase.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(EXAgroLog, Log, All);

class UAggroTransmitter;

namespace EXAggro
{
	extern const TArray<FString> RangeLevels;


	using TargetBaseType = UAggroTransmitter;
	using TargetType = TLazyObjectPtr<TargetBaseType>;
	using ValueType = double;
	using MultiType = float;

	// Aggro Out range level
	constexpr uint8 out_range_level = 0u;

	//Aggro Table Element Multiplier Indexes
	enum EMultiplierIndex
	{
		EMI_Common = 0,
		EMI_Range = 1
	};
}

UENUM(BlueprintType)
enum class EAgRangeLevel : uint8
{
	OutOfRange = 0,
	LongRange = 1,
	ShortRange = 2
};


UENUM(BlueprintType)
enum class EAggroSource : uint8
{
	None = 0   UMETA(Hidden),
	TakeDamage = 1 UMETA(ToolTip = "Holder got damage from target"),
	ObserveHeal = 2 UMETA(ToolTip = "Holder observed target heal"),
	ObserveChangeRange = 3 UMETA(ToolTip = "Holder observed target changed range"),
	ObserveDeath = 4 UMETA(ToolTip = "Holder observed target's death"),
	TakeAction = 5 UMETA(ToolTip = "Holder got action from target"),
	ObserveAction = 6 UMETA(ToolTip = "Holder observed target's action")
};

USTRUCT(BlueprintType)
struct FAggroMultiplier
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(DisplayName="Aggro Source Type", ToolTip="Action Type that trigger Aggro Changes"))
	EAggroSource SourceType = EAggroSource::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(DisplayName="Aggro Multiplier Value", ToolTip="When Aggro will be received by NPC,\n then Aggro value will be multiplier by this multiplier.\n For example DamageValue * Multiplier = Result Aggro Value.\n To complitely ignore Aggro, we can set multipliter to zero value and result Aggro will be zero."))
	float Value = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(DisplayName="Optional Subtype", ToolTip="'Aggro Source Type' = TakeAction, then 'Postfix' -> 'Acion Name'.\n'Aggro Source Type' = ObserveChangeRange, then 'Postfix' -> 'RangeLevel' [OutOfRange='0', LongDistanceRange='1', ShortDistanceRange='2']"))
	FString Postfix;
};

USTRUCT(BlueprintType)
struct FAggroMultiplierRow : public FTableRowBase
{
	GENERATED_BODY()

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(DisplayName="Preset Name", ToolTip="Preset Name for Multipliers set. Then several different NPC can upload it and use"))
	//FString PresetName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName ="Multipliers Set", ToolTip="Bunch of multipliers for different Aggro source types"))
	TArray<FAggroMultiplier> Multipliers;
};



// Aggro data that holder (NPC) can Process
struct FReceivedAggro
{
	using ParamType = TUnion<EXAggro::ValueType, bool, uint8, decltype(nullptr)>;
	static ParamType ParamNone;

	EAggroSource SourceType = EAggroSource::None;

	EXAggro::TargetBaseType* Target;

	// generic aggro data parameters (every different "SourceType" has own parameters)
	// TakeDamage -> Param1<AgTable::ValueType>(DamageValue); Param2(nullptr)
	// ObserveChangeRange -> Param1<uint8>(RangeLevel); Param2(nullptr) ----- RangeLevel {0 - out of range, 1 - long range, 2 - short range}; ----- ag_out_level - is a global variable for out_of range value
	// ObserveHeal -> Param1<AgTable::ValueType>(HealValue); Param2(nullptr)
	// ...
	ParamType Param1 = ParamNone;
	ParamType Param2 = ParamNone;

	// Think... maybe for more generic code use fixed array instead of {Param1, Param2 ...}
	//TArray<ParamType, TFixedAllocator<2>> Params;

	FReceivedAggro() = default;
	FReceivedAggro(EAggroSource InSourceType, EXAggro::TargetBaseType* InTarget, ParamType InParam1 = ParamNone, ParamType InParam2 = ParamNone);

	FString ToString() const;
	FString ParamToString(const ParamType & InParam) const;

	static TSharedPtr<FReceivedAggro> MakeTakeDamageData(EXAggro::TargetBaseType* Target, EXAggro::ValueType DamageValue, uint8 DamageType);
	static TSharedPtr<FReceivedAggro> MakeObserveChangeRangeData(EXAggro::TargetBaseType* Target, uint8 RangeLevel);
	static TSharedPtr<FReceivedAggro> MakeObserveHealData(EXAggro::TargetBaseType* Target, EXAggro::ValueType HealValue, uint8 HealType);
};
