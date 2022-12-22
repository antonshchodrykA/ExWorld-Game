
#include "AggroTable.h"
#include "AggroTransmitter.h"

bool operator==(const TSharedPtr<AgTable::AgTableElem> L, const AgTable::TargetBaseType * RKey)
{
	return L->Target == RKey;
}

/*================================================================
* [Start] AgTable Functionality
================================================================*/

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
AgTable::AgTable()
{
}

//---------------------------------------------------------------------------------------------------------
// Get accumulated total value of target's aggression
//---------------------------------------------------------------------------------------------------------
TWeakPtr<AgTable::AgTableElem> AgTable::GetTopTarget()
{
	Refresh();
	for (auto & Elem : SortedTable)
	{
		check(Elem.second.IsValid());
		if (Elem.second->IsValid() && Elem.first > 0.0)
		{
			return Elem.second;
		}
	}
	return nullptr;
}


//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void AgTable::EditValue(TargetBaseType * InTarget, AgTable::ValueType InValue, bool bOverride /* = false */)
{
	auto Res = HashTable.find(GetTargetHash(InTarget));
	if (Res != HashTable.end())
	{
		auto Elem = Res->second;
		check(Elem.IsValid());

		// Debug
#ifdef WITH_EDITOR
		FString OldState;
		Elem->GetState(OldState);
#endif
		auto PrevTotal = Elem->GetTotalValue();
		Elem->Value = FMath::Max(bOverride ? InValue : Elem->Value + InValue, 0.0);		
		SwitchTotalValue(Elem, PrevTotal);

		// Debug
#ifdef WITH_EDITOR
		FString NewState;
		Elem->GetState(NewState);
		UE_LOG(EXAgroLog, Log, TEXT("->\n\t%s FoundElem:\n\t\tOldState={%s}\n\t\tNewState={%s}"), *FString(__FUNCTION__), *OldState, *NewState);
#endif
	}
	else
	{
		AddElement(InTarget, InValue);
	}
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void AgTable::EditMultiplier(TargetBaseType* InTarget, MultiType InValue, uint8 MultiplierIndex /* = 0 */, bool bOverride /* = false */)
{
	auto Res = HashTable.find(GetTargetHash(InTarget));
	if (Res != HashTable.end())
	{
		auto Elem = Res->second;
		check(Elem.IsValid());

		// Debug
#ifdef WITH_EDITOR
		FString OldState;
		Elem->GetState(OldState);
#endif

		auto PrevTotal = Elem->GetTotalValue();
		Elem->Coefs[MultiplierIndex] = InValue;
		SwitchTotalValue(Elem, PrevTotal);

		// Debug
#ifdef WITH_EDITOR
		FString NewState;
		Elem->GetState(NewState);
		UE_LOG(EXAgroLog, Log, TEXT("->\n\t\t%s FoundElem:\n\t\tOldState={%s}\n\t\tNewState={%s}"), *FString(__FUNCTION__), *OldState, *NewState);
#endif
	}
	else
	{
		AddElement(InTarget, InValue, TPair<uint8, MultiType>{ MultiplierIndex, InValue });
	}
}

TWeakPtr<AgTable::AgTableElem> AgTable::AddElement(TargetBaseType* InTarget, ValueType InValue, TPair<uint8, MultiType> InCoef)
{
	return AddElement(InTarget, InValue, TArray<TPair<uint8, MultiType>>{InCoef});
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
TWeakPtr<AgTable::AgTableElem> AgTable::AddElement(TargetBaseType* InTarget, AgTable::ValueType InValue, TArray<TPair<uint8, MultiType>> InCoefs /* = nullptr */)
{
	auto Elem = MakeShared<AgTableElem>(InTarget, FMath::Max(InValue, 0.0), InCoefs);

	auto TotalAggro = Elem->GetTotalValue();

	SortedTable.insert({ TotalAggro, Elem });
	HashTable.insert({ GetTargetHash(InTarget), Elem });
	InTarget->AddAggroHolder(Owner);

#ifdef WITH_EDITOR
	FString State;
	Elem->GetState(State);
	UE_LOG(EXAgroLog, Log, TEXT("->\n\t\t%s: State:{%s}"), *FString(__FUNCTION__), *State);
#endif
	return Elem;
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void AgTable::SwitchTotalValue(TSharedPtr<AgTableElem> InElem, ValueType PrevTotal)
{
	auto NextTotal = InElem->GetTotalValue();
	if (NextTotal == PrevTotal) return;

	auto Res = TryRemoveElement(PrevTotal, InElem, true);
	check(Res);

	SortedTable.insert({ NextTotal, InElem });
	HashTable.insert({GetTypeHash(InElem->Target.GetUniqueID()), InElem });
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void AgTable::Refresh()
{
	TArray<TPair<AgTable::ValueType, TSharedPtr<AgTableElem>>> PendingRemoveArr;
	for (const auto & Elem : SortedTable)
	{
		check(Elem.second.IsValid())
		if (!Elem.second->IsValid())
		{
			PendingRemoveArr.Add(TPair<AgTable::ValueType, TSharedPtr<AgTableElem>>(Elem.first, Elem.second));
		}
	}

	for (int32 i = PendingRemoveArr.Num() - 1; i >= 0; --i)
	{
		auto Res = TryRemoveElement(PendingRemoveArr[i].Key, PendingRemoveArr[i].Value);
		check(Res);
	}
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void AgTable::ClearAll()
{
	SortedTable.clear();
	HashTable.clear();
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
bool AgTable::TryRemoveElement(ValueType InValue, TSharedPtr<AgTableElem> InElem, bool bTemporarily /* = false */)
{
	auto Elems = SortedTable.equal_range(InValue);
	if (Elems.first == SortedTable.end()) return false;

	size_t RNum = 0;
	for (auto It = Elems.first; It != Elems.second; ++It)
	{
		if (It->second == InElem)
		{
			if (It->second->Target.IsValid() && !bTemporarily)
			{
				It->second->Target->TryRemoveAggroHolder(Owner);
			}

			SortedTable.erase(It);
			++RNum;
			break;
		}
	}

	RNum += HashTable.erase(GetTypeHash(InElem->Target.GetUniqueID()));
	return RNum == 2;
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
bool AgTable::TryRemoveElement(TargetBaseType* InTarget, bool bTemporarily /* = false */)
{
	auto Res = HashTable.find(GetTargetHash(InTarget));
	if (Res != HashTable.end())
	{
		check(Res->second.IsValid());

		auto Elem = Res->second;
		return TryRemoveElement(Elem->GetTotalValue(), Elem);
	}
	return false;
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
uint32 AgTable::GetTargetHash(const TargetBaseType * Obj) const
{
	auto Guid = FUniqueObjectGuid::GetOrCreateIDForObject(static_cast<const UObject*>(Obj));
	return GetTypeHash(Guid);
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void AgTable::GetState(FString& OutState) const
{
	OutState = TEXT("\n\t\t\tSortedTable: \n");
	for (auto it = SortedTable.begin(); it != SortedTable.end(); ++it)
	{
		auto SortedElem = *it;
		FString ValueString;
		SortedElem.second->GetState(ValueString);

		OutState += FString::Format(TEXT("\t\t Key={0}, Value={1}{2}"), 
			{ FString::SanitizeFloat(SortedElem.first), ValueString, it == (--SortedTable.end())  ? TEXT("") : TEXT("\n")});
	}

	OutState += TEXT("\n\t\t\tHashTable: \n");
	for (auto it = HashTable.begin(); it != HashTable.end(); ++it)
	{
		auto HashElem = *it;
		FString ValueString;
		HashElem.second->GetState(ValueString);

		OutState += FString::Format(TEXT("\t\t Key={0}, Value={1}{2}"),
			{ FString::SanitizeFloat(HashElem.first), ValueString, it == (--HashTable.end()) ? TEXT("") : TEXT("\n")});
	}
}

/*================================================================
* [End] AgTable Functionality
================================================================*/

/*================================================================
* [Start] AgTableElem Functionality
================================================================*/

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
AgTable::AgTableElem::AgTableElem()
{
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
AgTable::AgTableElem::AgTableElem(TargetBaseType* InTarget, ValueType InValue, TPair<uint8, MultiType> InCoef)
	: Target(InTarget), Value(InValue)
{
	check(Coefs.IsValidIndex(InCoef.Key));
	if (!Coefs.IsValidIndex(InCoef.Key)) return;

	Coefs[InCoef.Key] = InCoef.Value;
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
AgTable::AgTableElem::AgTableElem(TargetBaseType* InTarget, ValueType InValue, TArray<TPair<uint8, MultiType>> InCoefs /* = TArray<>{} */)
	: Target(InTarget), Value(InValue)
{

	for (const auto& Coef : InCoefs)
	{
		check(Coefs.IsValidIndex(Coef.Key));
		if (!Coefs.IsValidIndex(Coef.Key)) continue;
		Coefs[Coef.Key] = Coef.Value;
	}

}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
AgTable::ValueType AgTable::AgTableElem::GetTotalValue() const
{
	ValueType Total = Value;
	for (const auto& Coef : Coefs)
	{
		Total *= (ValueType)Coef;
	}
	return Total;
}

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
void AgTable::AgTableElem::GetState(FString& OutState) const
{
	FString Name;
	if (Target.IsValid()) Target->GetName(Name);

	FString Multipliers;
	for (size_t i = 0; i < Coefs.Num(); ++i)
	{
		Multipliers += FString::Format(TEXT("Idx{0}={1}; "), { FString::FromInt(i), FString::SanitizeFloat(Coefs[i]) });
	}

	OutState = FString::Format(TEXT("TargetHash={0}, Value={1}, Multipliers={2}, Name(O) ={3}, Total={4}"),
		{ FString::SanitizeFloat(GetTypeHash(Target.GetUniqueID())), FString::SanitizeFloat(Value),
		Multipliers, Name, FString::SanitizeFloat(GetTotalValue()) });
}

/*================================================================
* [End] AgTableElem Functionality
================================================================*/
