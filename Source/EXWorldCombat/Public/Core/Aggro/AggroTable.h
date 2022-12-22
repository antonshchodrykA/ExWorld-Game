
#pragma once
#include "CoreMinimal.h"
#include "AggroBase.h"

#include <unordered_map>
#include <map>

class UAggroHolder;

// Container for Aggro Targets
class AgTable
{
public:

	using TargetBaseType = EXAggro::TargetBaseType;
	using TargetType = EXAggro::TargetType;
	using ValueType = EXAggro::ValueType;
	using MultiType = EXAggro::MultiType;

	struct AgTableElem
	{
		TargetType Target;
		ValueType Value = 1.0;

		// Element[0] -> Common Multiplier (anyone can use [for example different abilities])
		// Element[1] -> Range Multiplier (ony ObserveChangeRange use it)
		TArray<MultiType, TFixedAllocator<2>> Coefs{ 1.f , 0.f };

		AgTableElem();
		AgTableElem(TargetBaseType* InTarget, ValueType InValue, TPair<uint8, MultiType> InCoef);
		AgTableElem(TargetBaseType* InTarget, ValueType InValue, TArray<TPair<uint8, MultiType>> InCoefs = TArray<TPair<uint8, MultiType>>{});

		// Get accumulated total value of target's aggression
		ValueType GetTotalValue() const;

		void GetState(FString& OutState) const;

		bool IsValid() const { return Target.IsValid(); }
		bool operator<(const AgTableElem& Other) const { return Value < Other.Value; }
		bool operator==(const AgTableElem& Other) const { return Target == Other.Target; }
		bool operator==(const TargetBaseType*& OtherTarget) const { return Target == OtherTarget; }
	};

public:

	AgTable();

	// Edit or Add (if no exists) Table Element Value
	void EditValue(TargetBaseType* InTarget, ValueType InValue, bool bOverride = false);

	void EditMultiplier(TargetBaseType* InTarget, MultiType InValue, uint8 MultiplierIndex = 0, bool bOverride = false);

	// Get Target with the greatest Value
	TWeakPtr<AgTableElem> GetTopTarget();

	void ClearAll();

	// Debug
	void GetState(FString& OutState) const;

	UAggroHolder* Owner;

protected:

	TWeakPtr<AgTableElem> AddElement(TargetBaseType* InTarget, ValueType InValue, TPair<uint8, MultiType> InCoef);
	TWeakPtr<AgTableElem> AddElement(TargetBaseType* InTarget, ValueType InValue, TArray<TPair<uint8, MultiType>> InCoefs = TArray<TPair<uint8, MultiType>>{});
	bool TryRemoveElement(TargetBaseType* InTarget, bool bTemporarily = false);
	bool TryRemoveElement(ValueType InValue, TSharedPtr<AgTableElem> InElem, bool bTemporarily = false);
	void SwitchTotalValue(TSharedPtr<AgTableElem> InElem, ValueType PrevTotal);
	void Refresh();

private:

	uint32 GetTargetHash(const TargetBaseType * Obj) const;


	std::multimap<ValueType, TSharedPtr<AgTableElem>, std::greater<ValueType>> SortedTable;
	std::unordered_map<uint32, TSharedPtr<AgTableElem>> HashTable;

};


bool operator==(const TSharedPtr<AgTable::AgTableElem> L, const AgTable::TargetBaseType * RKey);