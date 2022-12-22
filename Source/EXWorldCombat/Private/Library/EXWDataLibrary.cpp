// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh


#include "Library/EXWDataLibrary.h"
#include "Library/Inventory/EXWInventoryStruct.h"
#include "Core/EXWCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Core/EXWSingleton.h"
#include "Core/Gameplay/EXWRespawnPoint.h"
#include "Core/DamageTypes/EXWMagicalDamageType.h"
#include "Core/DamageTypes/EXWPhysicalDamageType.h"
#include "Interface/EXWInteractable.h"
#include "Components/WidgetComponent.h"
#include "Widgets/EXWSharedWidget.h"

void UEXWDataLibrary::GetValidName(TArray<FName> Array, const int32 Index, FName& ResultItem, EEXWValidityBranch &Result)
{
	if (Array.IsValidIndex(Index))
	{
		ResultItem = Array[Index];
		Result = EEXWValidityBranch::VB_Valid;
	}
	else Result = EEXWValidityBranch::VB_NotValid;
}

EEXWActionDirection UEXWDataLibrary::ConvertFloatToDirection(const float InValue)
{
	if (InValue >= 30 && InValue <= 150) return EEXWActionDirection::AD_Right;
	else if (InValue >= -150 && InValue <= -30) return EEXWActionDirection::AD_Left;
	else if (InValue > -30 && InValue < 30) return EEXWActionDirection::AD_Forward;
	else if (InValue > 150 || InValue < -150) return EEXWActionDirection::AD_Backward;
	return EEXWActionDirection::AD_Backward;
}

EEXWRelativePosition UEXWDataLibrary::GetRelativePosition(AActor* MainActor, AActor* TargetActor, float& OutOrientationValue)
{
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(MainActor->GetActorLocation(), TargetActor->GetActorLocation());
	// Calculate the orientation on the Z axis (Yaw).
	OutOrientationValue = UKismetMathLibrary::NormalizedDeltaRotator(MainActor->GetActorRotation(), LookAtRotation).Yaw;
	// Compare the value of the orientation to know the exact rotation
	if (OutOrientationValue > -135.f && OutOrientationValue < -45.f) return EEXWRelativePosition::RP_Right;
	if (OutOrientationValue > 45.f && OutOrientationValue < 135.f) return EEXWRelativePosition::RP_Left;
	if (OutOrientationValue > -45.f && OutOrientationValue < 45.f) return EEXWRelativePosition::RP_Front;
	if (OutOrientationValue >= 135.f || OutOrientationValue <= -135.f) return EEXWRelativePosition::RP_Back;
	return EEXWRelativePosition::RP_Back;
}

TArray<AEXWCharacter*> UEXWDataLibrary::ConvertToCharacterArray(TArray<TWeakObjectPtr<AEXWCharacter>> CharacteWeakObjPtrrArray)
{
	TArray<AEXWCharacter*> ResultArray;
	for (TWeakObjectPtr<AEXWCharacter> WeakObjPtrCharacter : CharacteWeakObjPtrrArray)
	{
		if (WeakObjPtrCharacter.IsValid())
		{
			ResultArray.AddUnique(WeakObjPtrCharacter.Get());
		}
	}
	return ResultArray;
}

TArray<TWeakObjectPtr<AEXWCharacter>> UEXWDataLibrary::ConvertToWeakObjPtrCharacterArray(TArray<AEXWCharacter*> CharacterArray)
{
	TArray<TWeakObjectPtr<AEXWCharacter>> ResultArray;
	for (AEXWCharacter* Character : CharacterArray)
	{
		if (Character)
		{
			ResultArray.AddUnique(MakeWeakObjectPtr<AEXWCharacter>(Character));
		}
	}
	return ResultArray;
}

bool UEXWDataLibrary::ExistsInWeakObjPtrCharacterArray(TArray<TWeakObjectPtr<AEXWCharacter>> WeakObjPtrCharacterArray, AEXWCharacter* InCharacter)
{
	TArray<AEXWCharacter*> Characters = ConvertToCharacterArray(WeakObjPtrCharacterArray);
	return Characters.Contains(InCharacter);
}

bool UEXWDataLibrary::AddUniqueWeakObjPtrCharacter(TArray<TWeakObjectPtr<AEXWCharacter>> &WeakObjPtrCharacterArray, AEXWCharacter* InCharacter)
{
	if (InCharacter)
	{
		bool bFound = false;
		TArray<AEXWCharacter*> Characters = ConvertToCharacterArray(WeakObjPtrCharacterArray);
		for (AEXWCharacter* CharacterTemp : Characters)
		{
			if (CharacterTemp == InCharacter)
			{
				bFound = true;
			}
		}
		if (bFound)
		{
			return false;
		}
		else
		{
			Characters.AddUnique(InCharacter);
			WeakObjPtrCharacterArray.Empty();
			WeakObjPtrCharacterArray = ConvertToWeakObjPtrCharacterArray(Characters);
			return true;
		}
	}
	return false;
}

bool UEXWDataLibrary::RemoveWeakObjPtrCharacter(TArray<TWeakObjectPtr<AEXWCharacter>> &WeakObjPtrCharacterArray, AEXWCharacter* InCharacter)
{
	if (InCharacter)
	{
		bool bFound = false;
		TArray<AEXWCharacter*> Characters = ConvertToCharacterArray(WeakObjPtrCharacterArray);
		for (AEXWCharacter* CharacterTemp : Characters)
		{
			if (CharacterTemp == InCharacter)
			{
				bFound = true;
			}
		}
		if (bFound)
		{
			Characters.Remove(InCharacter);
			WeakObjPtrCharacterArray.Empty();
			WeakObjPtrCharacterArray = ConvertToWeakObjPtrCharacterArray(Characters);
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

AActor* UEXWDataLibrary::GetClosestActor(AActor* TargetActor, TArray<AActor*> ActorsArray)
{
	float MinDistance = 90000.f;
	AActor* ClosestActor = nullptr;

	for (AActor* TempActor : ActorsArray)
	{
		float TempDistance = TargetActor->GetDistanceTo(TempActor);
		if (TempDistance < MinDistance)
		{
			MinDistance = TempDistance;
			ClosestActor = TempActor;
		}
	}
	return ClosestActor;
}

AEXWCharacter* UEXWDataLibrary::GetClosestCharacter(AActor* TargetActor, TArray<AEXWCharacter*> CharactersArray)
{
	float MinDistance = 90000.f;
	AEXWCharacter* ClosestCharacter = nullptr;

	for (AEXWCharacter* TempChar : CharactersArray)
	{
		float TempDistance = TargetActor->GetDistanceTo(TempChar);
		if (TempDistance < MinDistance)
		{
			MinDistance = TempDistance;
			ClosestCharacter = TempChar;
		}
	}
	return ClosestCharacter;
}

bool UEXWDataLibrary::GetClosestRespawnPoint(AEXWCharacter* Character, AEXWRespawnPoint*& RespawnPoint)
{
	TArray<AActor*> ResultActors;
	UGameplayStatics::GetAllActorsOfClass(Character, AEXWRespawnPoint::StaticClass(), ResultActors);

	if (AEXWRespawnPoint* TempRespawnPoint = Cast<AEXWRespawnPoint>(GetClosestActor(Character, ResultActors)))
	{
		RespawnPoint = TempRespawnPoint;
		return true;
	}
	return false;
}

bool UEXWDataLibrary::GetClosestRespawnPointLocationAndRotation(AEXWCharacter* Character, FVector& RespawnPointPosition, FRotator& RespawnPointRotation)
{
	AEXWRespawnPoint* RespawnPoint;
	if (GetClosestRespawnPoint(Character, RespawnPoint))
	{
		RespawnPointPosition = RespawnPoint->GetActorLocation();
		RespawnPointRotation = RespawnPoint->GetActorRotation();
		return true;
	}
	else
	{
		RespawnPointPosition = Character->GetActorLocation();
		RespawnPointRotation = Character->GetActorRotation();
		return false;
	}
}

bool UEXWDataLibrary::GetRespawnPointWithName(AEXWCharacter* Character, FString RespawnPointName, AEXWRespawnPoint*& RespawnPoint)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(Character, AEXWRespawnPoint::StaticClass(), FoundActors);
					
	for (auto obj : FoundActors)
	{
		AEXWRespawnPoint* TempRespawnPoint = Cast<AEXWRespawnPoint>(obj);
		if (TempRespawnPoint->PointName==RespawnPointName)
		{
			RespawnPoint = TempRespawnPoint;
			return true;
		}
	}
	return false;
}

bool UEXWDataLibrary::GetPlayerStartWithName(AEXWCharacter* Character, FName RespawnPointName, APlayerStart*& PlayerStart)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(Character, APlayerStart::StaticClass(), FoundActors);

	for (auto obj : FoundActors)
	{
		APlayerStart* TempRespawnPoint = Cast<APlayerStart>(obj);
		if (TempRespawnPoint->PlayerStartTag==RespawnPointName)
		{
			PlayerStart = TempRespawnPoint;
			return true;
		}
	}

	return false;
}

void UEXWDataLibrary::FilterByDeathState(TArray<AActor*>& OutActors, TArray<AActor*> InActors, bool bIsDead /*= false*/)
{
	OutActors.Empty();
	for (AActor* TempActor : InActors)
	{
		if (AEXWCharacter* TempCharacter = Cast<AEXWCharacter>(TempActor))
		{
			if (TempCharacter->IsDead() == bIsDead)
			{
				OutActors.AddUnique(TempCharacter);
			}
		}
	}
}

void UEXWDataLibrary::RemoveCharactersWithDifferentFaction(int32 InFaction, TArray<AEXWCharacter*> InCharacterArray, TArray<AEXWCharacter*> &OutCharacterArray)
{
	OutCharacterArray.Empty();
	for (AEXWCharacter* CharacterTemp : InCharacterArray)
	{
		if (CharacterTemp->Faction != InFaction)
		{
			OutCharacterArray.AddUnique(CharacterTemp);
		}
	}
}

void UEXWDataLibrary::RemoveCharactersWithSameFaction(int32 InFaction, TArray<AEXWCharacter*> InCharacterArray, TArray<AEXWCharacter*>& OutCharacterArray)
{
	OutCharacterArray.Empty();
	for (AEXWCharacter* CharacterTemp : InCharacterArray)
	{
		if (CharacterTemp->Faction == InFaction)
		{
			OutCharacterArray.AddUnique(CharacterTemp);
		}
	}
}

void UEXWDataLibrary::RemoveCharactersWithDifferentFaction_Cast(int32 InFaction, TArray<AActor*> InCharacterArray, TArray<AActor*>& OutCharacterArray)
{
	OutCharacterArray.Empty();
	for (AActor* ActorTemp : InCharacterArray)
	{
		if (AEXWCharacter* CharacterTemp = Cast<AEXWCharacter>(ActorTemp))
		{
			if (CharacterTemp->Faction != InFaction)
			{
				OutCharacterArray.AddUnique(CharacterTemp);
			}
		}
	}
}

void UEXWDataLibrary::RemoveCharactersWithSameFaction_Cast(int32 InFaction, TArray<AActor*> InCharacterArray, TArray<AActor*>& OutCharacterArray)
{
	OutCharacterArray.Empty();
	for (AActor* ActorTemp : InCharacterArray)
	{
		if (AEXWCharacter* CharacterTemp = Cast<AEXWCharacter>(ActorTemp))
		{
			if (CharacterTemp->Faction == InFaction)
			{
				OutCharacterArray.AddUnique(CharacterTemp);
			}
		}
	}
}

void UEXWDataLibrary::FilterByFaction(TArray<AActor*>& OutActors, AEXWCharacter* TargetCharacter, TArray<AActor*> InActors, EEXWTargetFaction TargetFactionType /*= EEXWTargetFaction::TF_OtherFactionOnly*/)
{
	OutActors.Empty();
	for (AActor* TempActor : InActors)
	{
		if (AEXWCharacter* TempCharacter = Cast<AEXWCharacter>(TempActor))
		{
			if (TargetFactionType == EEXWTargetFaction::TF_OtherFactionOnly && !TargetCharacter->IsSameFaction(TempCharacter))
			{
				OutActors.AddUnique(TempCharacter);
			}
			else if (TargetFactionType == EEXWTargetFaction::TF_OwnerFactionOnly && TargetCharacter->IsSameFaction(TempCharacter))
			{
				OutActors.AddUnique(TempCharacter);
			}
			else if (TargetFactionType == EEXWTargetFaction::TF_ALLFactions)
			{
				OutActors.AddUnique(TempCharacter);
			}
		}
	}
}

float UEXWDataLibrary::GetAttributeEffectValue(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const EEXWValueType ValueType, const float StaticValue, const EEXWAttributeType ValueAttributeType, const float ValueAttributePrecentage)
{
	float FinalValue = 0.f;
	if (SourceCharacter && TargetCharacter) {
		if (ValueType == EEXWValueType::Static) // Taking Static Value as base effect value
			FinalValue = StaticValue;
		else if (ValueType == EEXWValueType::DynamicOnSource) { // Taking Percentage of the Source attribute as a base effect value
			float AttributeTempVal = 0.f;
			if (SourceCharacter->GetAttributeCurrentValue(ValueAttributeType, AttributeTempVal))
				FinalValue = (AttributeTempVal * ValueAttributePrecentage) / 100.f;
		}
		else if (ValueType == EEXWValueType::DynamicOnTarget) { // Taking Percentage of the target attribute as a base effect value
			float AttributeTempVal = 0.f;
			if (TargetCharacter->GetAttributeCurrentValue(ValueAttributeType, AttributeTempVal))
				FinalValue = (AttributeTempVal * ValueAttributePrecentage) / 100.f;
		}
	}
	// apply attribute modifier per level
	/*if (SourceCharacter->LastActiveAction.Level > 1)
	{
		FinalValue = FinalValue + (FinalValue * SourceCharacter->LastActiveAction.Level * SourceCharacter->LastActiveAction.LevelModifier);
	}*/
	return FinalValue;
}

bool UEXWDataLibrary::ApplyAttributeEffect(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect &AttributeEffect)
{
	if (TargetCharacter && SourceCharacter) {

		if (!TargetCharacter->IsDead())
		{
			float FinalValue = 0.f;
			if(!(/*AttributeEffect.AttributeType==EEXWAttributeType::Stamina && */AttributeEffect.EffectType == EEXWEffectType::Loss && TargetCharacter==SourceCharacter))
			{
			TargetCharacter->LastCharacterAffectedBy = SourceCharacter;
			SourceCharacter->LastCharacterAffected = TargetCharacter;
			}

			// Gain Attribute
			if (AttributeEffect.EffectType == EEXWEffectType::Gain)
			{
				FinalValue = GetAttributeEffectValue(SourceCharacter, TargetCharacter, AttributeEffect.ValueType, AttributeEffect.StaticValue, AttributeEffect.ValueAttributeType, AttributeEffect.ValueAttributePrecentage);
				TargetCharacter->Server_GainAttribute(AttributeEffect.AttributeType, FinalValue);
			}
			// Lose Attribute
			else if (AttributeEffect.EffectType == EEXWEffectType::Loss)
			{
				FinalValue = GetAttributeEffectValue(SourceCharacter, TargetCharacter, AttributeEffect.ValueType, AttributeEffect.StaticValue, AttributeEffect.ValueAttributeType, AttributeEffect.ValueAttributePrecentage);
				if (AttributeEffect.AttributeType == EEXWAttributeType::Health)
				{
					SourceCharacter->Server_ApplyDamage(TargetCharacter, FinalValue, AttributeEffect.DamageType);
				}
				else
				{
					TargetCharacter->Server_LoseAttribute(AttributeEffect.AttributeType, FinalValue);
				}
			}

			// Execute Status Effects on target
			for (FString StatusEffect : AttributeEffect.StatusEffects)
			{
				SourceCharacter->Server_ConstructStatusEffect(FName(StatusEffect), SourceCharacter, TargetCharacter);
				UE_LOG(LogTemp, Log, TEXT("Constructing Status Effect"));
			}

			// Notify the clients locally
			SourceCharacter->Client_ApplyAttributeNotify(SourceCharacter, TargetCharacter, AttributeEffect);
			TargetCharacter->Client_ApplyAttributeNotify(SourceCharacter, TargetCharacter, AttributeEffect);

			return true;
		}
	}
	return false;
}

bool UEXWDataLibrary::ApplyAttributeMultiEffects(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect> &AttributeEffects)
{
	if (SourceCharacter && TargetCharacter) {
		for (const FEXWAttributeEffect& AttributeEffect : AttributeEffects)
		{
			ApplyAttributeEffect(SourceCharacter, TargetCharacter, AttributeEffect);
		}
		return true;
	}
	return false;
}

bool UEXWDataLibrary::ApplyAttributeEffectByFactionCheck(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect& AttributeEffect)
{
	bool bHasHit = false;
	if (SourceCharacter && TargetCharacter) 
	{
		if (AttributeEffect.bAffectOwner && SourceCharacter == TargetCharacter) 
		{
			ApplyAttributeEffect(SourceCharacter, TargetCharacter, AttributeEffect);
			bHasHit = true;
		}
		if (AttributeEffect.bAffectOtherFaction && !SourceCharacter->IsSameFaction(TargetCharacter))
		{
			ApplyAttributeEffect(SourceCharacter, TargetCharacter, AttributeEffect);
			bHasHit = true;
		}
		if ((AttributeEffect.bAffectOwnerFaction && SourceCharacter->IsSameFaction(TargetCharacter)) && (SourceCharacter != TargetCharacter))
		{
			ApplyAttributeEffect(SourceCharacter, TargetCharacter, AttributeEffect);
			bHasHit = true;
		}
		if (AttributeEffect.bAffectOtherFaction && TargetCharacter->DuelingCharacter==SourceCharacter)
		{
			ApplyAttributeEffect(SourceCharacter, TargetCharacter, AttributeEffect);
			bHasHit = true;
		}
	}
	return bHasHit;
}

bool UEXWDataLibrary::ApplyAttributeMultiEffectsByFactionCheck(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect>& AttributeEffects)
{
	bool bHasHit = false;
	if (SourceCharacter && TargetCharacter) {
		for (FEXWAttributeEffect AttributeEffect : AttributeEffects)
		{
			if (ApplyAttributeEffectByFactionCheck(SourceCharacter, TargetCharacter, AttributeEffect)) 
			{
				bHasHit = true;
			}
		}
	}
	return bHasHit;
}

bool UEXWDataLibrary::ReverseAttributeEffect(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect& AttributeEffect)
{
	FEXWAttributeEffect NewAttributeEffect = AttributeEffect;
	if (AttributeEffect.EffectType == EEXWEffectType::Gain)
	{
		NewAttributeEffect.EffectType = EEXWEffectType::Loss;
	} else if (AttributeEffect.EffectType == EEXWEffectType::Loss)
	{
		NewAttributeEffect.EffectType = EEXWEffectType::Gain;
	}
	return ApplyAttributeEffect(SourceCharacter, TargetCharacter, NewAttributeEffect);
}

bool UEXWDataLibrary::ReverseAttributeMultiEffects(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect>& AttributeEffects)
{
	if (SourceCharacter && TargetCharacter) {
		for (const FEXWAttributeEffect& AttributeEffect : AttributeEffects)
		{
			ReverseAttributeEffect(SourceCharacter, TargetCharacter, AttributeEffect);
		}
		return true;
	}
	return false;
}

bool UEXWDataLibrary::GetAttribute(TArray<FEXWAttribute> Attributes, const EEXWAttributeType AttributeType, FEXWAttribute& OutAttribute)
{
	for (FEXWAttribute Attribute : Attributes)  // Check if it is actually having the right value or not due to ref
	{
		if (Attribute.AttributeType == AttributeType)
		{
			OutAttribute = Attribute;
			return true;
		}
	}
	return false;
}

bool UEXWDataLibrary::GetAttributeCurrentValue(TArray<FEXWAttribute> Attributes, const EEXWAttributeType AttributeType, float& OutValue)
{
	FEXWAttribute OutAttribute;
	if (GetAttribute(Attributes, AttributeType, OutAttribute))
	{
		OutValue = OutAttribute.CurrentValue;
		return true;
	}
	return false;
}

bool UEXWDataLibrary::GetAttributePercentage(TArray<FEXWAttribute> Attributes, const EEXWAttributeType AttributeType, float& OutValue)
{
	FEXWAttribute OutAttribute;
	if (GetAttribute(Attributes, AttributeType, OutAttribute))
	{
		OutValue = OutAttribute.CurrentValue / OutAttribute.MaxValue;
		return true;
	}
	return false;
}

bool UEXWDataLibrary::GetAttributeMaxValue(TArray<FEXWAttribute> Attributes, const EEXWAttributeType AttributeType, float& OutValue)
{
	FEXWAttribute OutAttribute;
	if (GetAttribute(Attributes, AttributeType, OutAttribute))
	{
		OutValue = OutAttribute.MaxValue;
		return true;
	}
	return false;
}

bool UEXWDataLibrary::GetSingleton(UEXWSingleton* &OutSingleton)
{
	if (GEngine)
		if (UEXWSingleton* SingletonObj = Cast<UEXWSingleton>(GEngine->GameSingleton)) {
			OutSingleton = SingletonObj;
			return true;
		}
	return false;
}

UEXWSingleton* UEXWDataLibrary::GetSingleton()
{
	if (GEngine)
	{
		return Cast<UEXWSingleton>(GEngine->GameSingleton);
	}
	return nullptr;
}

bool UEXWDataLibrary::GetStatusEffectDT(UDataTable* &OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->StatusEffectsDT) {
			OutDataTable = SingletonObj->StatusEffectsDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetSpawnableAbilityDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->SpawnableAbilityDT) {
			OutDataTable = SingletonObj->SpawnableAbilityDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetActionDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->ActionDT) {
			OutDataTable = SingletonObj->ActionDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetReactionDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->ReactionDT) {
			OutDataTable = SingletonObj->ReactionDT;
			return true;
		}
	return false;
}

UDataTable* UEXWDataLibrary::GetItemDT()
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
	{
		if (SingletonObj->ItemDT) 
		{
			return SingletonObj->ItemDT;
		}
	}
	return nullptr;
}

FEXWItemData UEXWDataLibrary::GetItemByID(FName ItemID)
{
	FEXWItemData Item;

	if (UDataTable* ItemsDT = GetItemDT()) {
		static const FString ContextString(TEXT("ItemDT"));
		if (FEXWItemData* Row = ItemsDT->FindRow<FEXWItemData>(ItemID, ContextString))
		{
			Item = *Row;
		}

	}

	return Item;
}

UDataTable* UEXWDataLibrary::GetCraftingOptionsDT()
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
	{
		if (SingletonObj->CraftingOptionsDT)
		{
			return SingletonObj->CraftingOptionsDT;
		}
	}
	return nullptr;
}

float UEXWDataLibrary::GetItemSpawnDistance()
{
	if (UEXWSingleton* Singleton = GetSingleton())
	{
		return Singleton->ItemSpawnDistance;
	}
	return 50.f;
}

float UEXWDataLibrary::GetItemSpawnDistanceVariance()
{
	if (UEXWSingleton* Singleton = GetSingleton())
	{
		return Singleton->ItemSpawnDistanceVariance;
	}
	return 80.f;
}

bool UEXWDataLibrary::GetStatLevelModifierDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->StatLevelModifiersDT) {
			OutDataTable = SingletonObj->StatLevelModifiersDT;
			return true;
		}
	return false;
}

FEXWHighlightData UEXWDataLibrary::GetHighlightData()
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
	{
		return SingletonObj->HighlightData;
	}
	return FEXWHighlightData();
}

TSubclassOf<UEXWSharedWidget> UEXWDataLibrary::GetShopWidgetClass()
{
	if (UEXWSingleton* Singleton = GetSingleton())
	{
		return Singleton->ShopWidgetClass;
	}
	return nullptr;
}

TSubclassOf<UEXWSharedWidget> UEXWDataLibrary::GetTradeWidgetClass()
{
	if (UEXWSingleton* Singleton = GetSingleton())
	{
		return Singleton->TradeWidgetClass;
	}
	return nullptr;
}

TSubclassOf<UEXWFloatingWidget> UEXWDataLibrary::GetFloatingTextWidgetClass()
{
	if (UEXWSingleton* Singleton = GetSingleton())
	{
		return Singleton->FloatingTextWidgetClass;
	}
	return nullptr;
}

FLinearColor UEXWDataLibrary::GetFloatingTextColor(const EEXWAttributeEffectType AttributeEffectType)
{
	if (UEXWSingleton* Singleton = GetSingleton())
	{
		if (FLinearColor* ResultColor = Singleton->FloatingTextColor.Find(AttributeEffectType))
		{
			return *ResultColor;
		}
	}
	return FLinearColor(1.f, 1.f, 1.f, 1.f);
}

FEXWScreenMessageData* UEXWDataLibrary::GetScreenMessageData(const EEXWScreenMessageType ScreenMessageType)
{
	if (UEXWSingleton* Singleton = GetSingleton())
	{
		return Singleton->ScreenMessages.Find(ScreenMessageType);
	}
	return nullptr;
}

void UEXWDataLibrary::MakeReactionSendingParams(FEXWReactionSendingParams& ReactionSendingParams, const FName RowName, const bool bUseCharacterReactionDT, AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter)
{
	if (SourceCharacter && TargetCharacter)
	{
		ReactionSendingParams.RowName = RowName;
		ReactionSendingParams.bUseCharacterReactionDT = bUseCharacterReactionDT;
		ReactionSendingParams.SourceCharacter = SourceCharacter;
		ReactionSendingParams.TargetCharacter = TargetCharacter;
	}
}

int32 UEXWDataLibrary::CalculateExperienceOnKill(AEXWCharacter* KillerCharacter, AEXWCharacter* KilledCharacter)
{
	int32 FinalValue = KilledCharacter->ExperienceOnKill.MinimumExperience;
	int32 InLevelRangeExperience = KilledCharacter->ExperienceOnKill.InLevelRangeExperience;
	int32 LevelDifference = UKismetMathLibrary::Abs(KillerCharacter->ProgressionLevel - KilledCharacter->ProgressionLevel);
	int32 LevelRangeDifference = LevelDifference - KilledCharacter->ExperienceOnKill.MidLevelRange;

	if (LevelDifference <= KilledCharacter->ExperienceOnKill.MidLevelRange )
	{
		FinalValue = InLevelRangeExperience;
	}
	else
	{
		FinalValue = InLevelRangeExperience - (LevelRangeDifference * KilledCharacter->ExperienceOnKill.LossPerLevelExperience);
		if (FinalValue <= 0)
		{
			FinalValue = KilledCharacter->ExperienceOnKill.MinimumExperience;
		}
	}
	return FinalValue;
}

TArray<EEXWInteractionType> UEXWDataLibrary::GetAvailableInteractionTypes(AActor* InteractableActor)
{
	if (IEXWInteractable* InteractableInterface = Cast<IEXWInteractable>(InteractableActor))
	{
		return InteractableInterface->AvailableInteractionTypes;
	}
	return TArray<EEXWInteractionType>();
}

void UEXWDataLibrary::SetAvailableInteractionTypes(AActor* InteractableActor, TArray<EEXWInteractionType> NewInteractionTypes)
{
	if (IEXWInteractable* InteractableInterface = Cast<IEXWInteractable>(InteractableActor))
	{
		InteractableInterface->AvailableInteractionTypes = NewInteractionTypes;
	}
}

void UEXWDataLibrary::AddInteractionType(AActor* InteractableActor, EEXWInteractionType InteractionType)
{
	if (IEXWInteractable* InteractableInterface = Cast<IEXWInteractable>(InteractableActor))
	{
		InteractableInterface->AvailableInteractionTypes.AddUnique(InteractionType);
	}
}

void UEXWDataLibrary::RemoveInteractionType(AActor* InteractableActor, EEXWInteractionType InteractionType)
{
	if (IEXWInteractable* InteractableInterface = Cast<IEXWInteractable>(InteractableActor))
	{
		InteractableInterface->AvailableInteractionTypes.Remove(InteractionType);
	}
}

UWidgetComponent* UEXWDataLibrary::GetInteractionWidgetComponent(AActor* InteractableActor)
{
	if (IEXWInteractable* InteractableInterface = Cast<IEXWInteractable>(InteractableActor))
	{
		return InteractableInterface->GetInteractionWidgetComponent();
	}
	return nullptr;
}

void UEXWDataLibrary::SetInteractionWidgetVisibility(AActor* InteractableActor, const bool bNewVisibility /*= true*/)
{
	if (IEXWInteractable* InteractableInterface = Cast<IEXWInteractable>(InteractableActor))
	{
		return InteractableInterface->SetInteractionWidgetVisibility(bNewVisibility);
	}
}

bool UEXWDataLibrary::GetStatusEffectData(const FName StatusEffectID, FEXWStatusEffectData& OutStatusEffectData)
{
	UDataTable* StatusEffectsDT;
	if (GetStatusEffectDT(StatusEffectsDT))
	{
		static const FString ContextString(TEXT("StatusEffectsDT"));
		FEXWStatusEffectData* StatusEffectData = StatusEffectsDT->FindRow<FEXWStatusEffectData>(StatusEffectID, ContextString, true);
		// Check if the the row data was found.
		if (StatusEffectData) {
			OutStatusEffectData = *StatusEffectData;
			return true;
		}
	}
	return false;
}

FText UEXWDataLibrary::GetStatusEffectAsText(const FName StatusEffectID)
{
	FEXWStatusEffectData StatusEffectData;
	FString FinalString;
	if (GetStatusEffectData(StatusEffectID, StatusEffectData))
	{
		for (FEXWAttributeEffect& AttributeEffect : StatusEffectData.AttributeEffects)
		{
			float Value = (AttributeEffect.ValueType == EEXWValueType::Static) ? AttributeEffect.StaticValue : AttributeEffect.ValueAttributePrecentage;
			FinalString += (AttributeEffect.EffectType == EEXWEffectType::Gain) ? "+" : "-";
			FinalString += FString::SanitizeFloat(Value);
			FinalString += (AttributeEffect.ValueType == EEXWValueType::Static) ? "" : "%";
			FinalString += " ";
			UEnum* AttributeTypePtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EEXWAttributeType"), true);
			FinalString += AttributeTypePtr->GetDisplayNameTextByIndex((int32)AttributeEffect.AttributeType).ToString();
			FinalString += " every ";
			FinalString += FString::SanitizeFloat(StatusEffectData.Duration);
			FinalString += "\n";
		}
		FinalString.TrimEnd();
		return FText::FromString(FinalString);
	}
	return FText();
}

FText UEXWDataLibrary::GetStatusEffectsAsText(const TArray<FName> StatusEffectIDs)
{
	FString FinalString;
	for (FName StatusEffectID : StatusEffectIDs)
	{
		FinalString += GetStatusEffectAsText(StatusEffectID).ToString();
		FinalString += "\n";
	}
	FinalString.TrimEnd();
	return FText::FromString(FinalString);
}


FText UEXWDataLibrary::GetLifeSkillAsText(const EEXWLifeSkillType LifeSkillType)
{
	UEnum* AttributeTypePtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EEXWLifeSkillType"), true);
	check(AttributeTypePtr);
	return AttributeTypePtr->GetDisplayNameTextByIndex((int32)LifeSkillType);
}

bool UEXWDataLibrary::GetRaceClassesDataDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->RaceClassDataDT) {
			OutDataTable = SingletonObj->RaceClassDataDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetIKValueDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->IKDataTable) {
			OutDataTable = SingletonObj->IKDataTable;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetHeadTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->HeadTypeDT) {
			OutDataTable = SingletonObj->HeadTypeDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetHairTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->HairTypeDT) {
			OutDataTable = SingletonObj->HairTypeDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetHairColorDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->HairColorDT) {
			OutDataTable = SingletonObj->HairColorDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetArmsTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->ArmsTypeDT) {
			OutDataTable = SingletonObj->ArmsTypeDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetBodyTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->BodyTypeDT) {
			OutDataTable = SingletonObj->BodyTypeDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetTorsoTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->TorsoTypeDT) {
			OutDataTable = SingletonObj->TorsoTypeDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetEyesTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->EyesTypeDT) {
			OutDataTable = SingletonObj->EyesTypeDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetEyeColorDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->EyesColorDT) {
			OutDataTable = SingletonObj->EyesColorDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetFaceTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->FaceTypeDT) {
			OutDataTable = SingletonObj->FaceTypeDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetFeetTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->FeetTypeDT) {
			OutDataTable = SingletonObj->FeetTypeDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetLegsTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->LegsTypeDT) {
			OutDataTable = SingletonObj->LegsTypeDT;
			return true;
		}
	return false;
}

bool UEXWDataLibrary::GetSkinTypeDT(UDataTable*& OutDataTable)
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
		if (SingletonObj->SkinTypeDT) {
			OutDataTable = SingletonObj->SkinTypeDT;
			return true;
		}
	return false;
}

FEXWBaseSkeletalMeshes UEXWDataLibrary::GetRaceBodyMeshData(TArray<FEXWClassVisualData> Classlist, EEXWClass Class, EEXWGender Gender)
{
	FEXWBaseSkeletalMeshes Result;
	for (int i = 0; i < Classlist.Num(); i++)
	{
		if (Classlist[i].Class == Class)
		{
			if (Gender == EEXWGender::G_Male)
			{ 
				Result= Classlist[i].MaleBaseMeshes;
				break; 
			}
			else if(Gender == EEXWGender::G_Female)
			{ 
				Result= Classlist[i].FemaleBaseMeshes;
				break;
			}
			else
			{
				Result= Classlist[0].MaleBaseMeshes;
				break; 
			}
		}
	}
	return Result; 	
}

bool UEXWDataLibrary::GetDeathAnimationByRaceAndGender(UAnimMontage*& DeathAnimation, TArray<FEXWClassVisualData> Classlist, EEXWClass Class, EEXWGender Gender)
{
	for (int i = 0; i < Classlist.Num(); i++)
	{
		if (Classlist[i].Class == Class)
		{
			if (Gender == EEXWGender::G_Male)
			{ 
				DeathAnimation = Classlist[i].MaleDeathAnimation;
				return true; 
			}
			else if(Gender == EEXWGender::G_Female)
			{ 
				DeathAnimation= Classlist[i].FemaleDeathAnimation;
				return true; 
			}
		}
	}
	return false;
}

bool UEXWDataLibrary::GetAnimBPFromDT(FName RowName, UAnimBlueprint*& OutBPClass)
{
	UDataTable* RaceClassesDataDT;
	if (UEXWDataLibrary::GetRaceClassesDataDT(RaceClassesDataDT))
	{
		return true;
	}
	return false;
}

bool UEXWDataLibrary::GetRootMeshFromDT(FName RowName, USkeletalMesh*& OutMesh)
{
	return false;
}

bool UEXWDataLibrary::GetHeadMeshFromDT(FName RowName, USkeletalMesh*& Mesh)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetHeadTypeDT(DT);
	Mesh=DT->FindRow<FEXWHeadType>(RowName, ContextString, true)->SkeletalMesh;
	if (DT!=nullptr)
		return true;
	return false;
}

bool UEXWDataLibrary::GetHairMeshFromDT(FName RowName, FEXWHairType& OutHairData)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetHairTypeDT(DT);
	if (DT != nullptr && DT->FindRow<FEXWHairType>(RowName, ContextString, true)!= nullptr)
	{
		OutHairData = *DT->FindRow<FEXWHairType>(RowName, ContextString, true);
		return true;
	}		
	return false;
}

bool UEXWDataLibrary::GetHairColorFromDT(FName RowName, FLinearColor& OutColor)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetHairColorDT(DT);
	if (DT)
	{
		if (FEXWHairColor *HairColor = DT->FindRow<FEXWHairColor>(RowName, ContextString, true))
		{
			OutColor = HairColor->Color;
			return true;
		}
	}
	return false;
}

bool UEXWDataLibrary::GetArmsMeshFromDT(FName RowName, USkeletalMesh*& Mesh)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetArmsTypeDT(DT);
	Mesh = DT->FindRow<FEXWArmsType>(RowName, ContextString, true)->SkeletalMesh;
	if (DT != nullptr)
		return true;
	return false;
}

bool UEXWDataLibrary::GetBodyMorphsFromDT(FName RowName, USkeletalMesh*& Mesh)
{
	return false;
}

bool UEXWDataLibrary::GetTorsoMeshFromDT(FName RowName, USkeletalMesh*& Mesh)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetTorsoTypeDT(DT);
	Mesh = DT->FindRow<FEXWTorsoType>(RowName, ContextString, true)->SkeletalMesh;
	if (DT != nullptr)
		return true;
	return false;
}

bool UEXWDataLibrary::GetEyesMeshFromDT(FName RowName, USkeletalMesh*& Mesh, USkeletalMesh*& EyeBrowMesh)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetEyesTypeDT(DT);
	Mesh = DT->FindRow<FEXWEyesType>(RowName, ContextString, true)->EyesMesh;
	EyeBrowMesh = DT->FindRow<FEXWEyesType>(RowName, ContextString, true)->EyeBrowsMesh;
	if (DT != nullptr)
		return true;
	return false;
}

bool UEXWDataLibrary::GetEyeColorFromDT(FName RowName,FLinearColor& OutColor)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetEyeColorDT(DT);
	if (DT)
	{
		if (FEXWEyeColor *EyeColor = DT->FindRow<FEXWEyeColor>(RowName, ContextString, true))
		{
			OutColor = EyeColor->Color;
			return true;
		}
	}
	return false;
}

bool UEXWDataLibrary::GetFaceMeshFromDT(FName RowName, USkeletalMesh*& Mesh)
{

	return false;
}

bool UEXWDataLibrary::GetFeetMeshFromDT(FName RowName, USkeletalMesh*& Mesh)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetFeetTypeDT(DT);
	Mesh = DT->FindRow<FEXWFeetType>(RowName, ContextString, true)->SkeletalMesh;
	if (DT != nullptr)
		return true;
	return false;
}

bool UEXWDataLibrary::GetLegsMeshFromDT(FName RowName, USkeletalMesh*& Mesh)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetLegsTypeDT(DT);
	if (DT)
	{
		if (FEXWLegsType *Legstype = DT->FindRow<FEXWLegsType>(RowName, ContextString, true))
		{
			Mesh = Legstype->SkeletalMesh;
			return true;
		}
	}
	return false;
}

bool UEXWDataLibrary::GetSkinTypeFromDT(FName RowName, FEXWSkinType& SkinTypeData)
{
	UDataTable* DT;
	static const FString ContextString(TEXT("DT"));
	GetSkinTypeDT(DT);
	if (DT)
	{
		if (FEXWSkinType *SkinType = DT->FindRow<FEXWSkinType>(RowName, ContextString, true))
		{
			SkinTypeData=*SkinType;
			return true;
		}
	}

	return false;
}

FText UEXWDataLibrary::AttributeTypeAsText(EEXWAttributeType Type)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EEXWAttributeType"), true);
	if (!enumPtr)
	{
		return FText::FromString("Invalid");
	}
	return enumPtr->GetDisplayNameText((int32)Type);
}

FText UEXWDataLibrary::StatTypeAsText(EEXWStatType Type)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EEXWStatType"), true);
	if (!enumPtr)
	{
		return FText::FromString("Invalid");
	}
	return enumPtr->GetDisplayNameText((int32)Type);
}

UDataTable* UEXWDataLibrary::GetActionsDT()
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
	{
		if (SingletonObj->ActionDT)
		{
			return SingletonObj->ActionDT;
		}
	}
	return nullptr;
}


TArray<FName> UEXWDataLibrary::GetAvailableActions(TArray<FEXWClassVisualData> Classlist, EEXWClass Class)
{
	for (int i = 0; i < Classlist.Num(); i++)
	{
		if (Classlist[i].Class == Class)
		{
			return Classlist[i].DefaultActions;
		}
	}
	return Classlist[0].DefaultActions;
}

TArray<FEXWAction> UEXWDataLibrary::GetActions(TMap<FName, int32> ActionIDs)
{
	TArray<FEXWAction> Actions;
	
	if (UDataTable* ActionsDT = GetActionsDT())
	{
		for (auto Row: ActionsDT->GetRowMap())
		{
			FEXWAction& Action = *reinterpret_cast<FEXWAction*>(Row.Value);
			if (ActionIDs.Contains(Action.ID))
			{
				Action.Level = ActionIDs[Action.ID];
				
				for (FEXWActionLevel LevelUpgrade : Action.LevelUpgrades)
				{
					if (LevelUpgrade.RequiredLevel == Action.Level)
					{
						Action.Value = LevelUpgrade.AttributeValue;
						Action.Cooldown = LevelUpgrade.Cooldown;
						Action.LevelModifier = LevelUpgrade.LevelModifier;
						break;
					}
				}

				Actions.AddUnique(Action);
			}
		}
	}
	
	return Actions;
}

TArray<FEXWAction> UEXWDataLibrary::GetActionsByRaceAndClass(EEXWRace Race, EEXWClass Class)
{
	TArray<FEXWAction> Actions;

	UDataTable* RaceClassesDataDT;
	if (UEXWDataLibrary::GetRaceClassesDataDT(RaceClassesDataDT))
	{
		TArray<FName> AvailableActions;

		static const FString ContextString(TEXT("RaceClassesDataDT"));
		//We CHop 12 from the right to account for EEXWRace::R_ prefix
		if (FEXWClassRaces* Row = RaceClassesDataDT->FindRow<FEXWClassRaces>(FName(UEnum::GetValueAsString(Race).RightChop(12)), ContextString, true))
		{
			TArray<FEXWClassVisualData> ClassList = Row->Classlist;
			for (FEXWClassVisualData ClassL : ClassList)
			{
				if (ClassL.Class == Class)
				{
					AvailableActions = ClassL.AvailableActions;
					break;
				}
			}

			if (UDataTable* ActionsDT = GetActionsDT()) {
				for (auto Row : ActionsDT->GetRowMap())
				{
					FEXWAction Action = *reinterpret_cast<FEXWAction*>(Row.Value);
					if (AvailableActions.Contains(Action.ID))
					{
						Actions.AddUnique(Action);
						
					}
				}
			}
		}
	}

	return Actions;
}

TArray<FEXWAction> UEXWDataLibrary::GetDefaultActionsByRaceAndClass(EEXWRace Race, EEXWClass Class)
{
	TArray<FEXWAction> Actions;

	UDataTable* RaceClassesDataDT;
	if (UEXWDataLibrary::GetRaceClassesDataDT(RaceClassesDataDT))
	{
		TArray<FName> AvailableActions;

		static const FString ContextString(TEXT("RaceClassesDataDT"));
		//We CHop 12 from the right to account for EEXWRace::R_ prefix
		if (FEXWClassRaces* Row = RaceClassesDataDT->FindRow<FEXWClassRaces>(FName(UEnum::GetValueAsString(Race).RightChop(12)), ContextString, true))
		{
			TArray<FEXWClassVisualData> ClassList = Row->Classlist;
			for (FEXWClassVisualData ClassL : ClassList)
			{
				if (ClassL.Class == Class)
				{
					AvailableActions = ClassL.DefaultActions;
					break;
				}
			}

			if (UDataTable* ActionsDT = GetActionsDT()) {
				for (auto Row : ActionsDT->GetRowMap())
				{
					FEXWAction Action = *reinterpret_cast<FEXWAction*>(Row.Value);
					if (AvailableActions.Contains(Action.ID))
					{
						Actions.AddUnique(Action);

					}
				}
			}
		}
	}

	return Actions;
}

TArray<FEXWAction> UEXWDataLibrary::GetDefaultIFrameActionsByRaceAndClass(EEXWRace Race, EEXWClass Class)
{
	TArray<FEXWAction> Actions;

	UDataTable* RaceClassesDataDT;
	if (UEXWDataLibrary::GetRaceClassesDataDT(RaceClassesDataDT))
	{
		TArray<FName> AvailableActions;

		static const FString ContextString(TEXT("RaceClassesDataDT"));
		//We CHop 12 from the right to account for EEXWRace::R_ prefix
		if (FEXWClassRaces* Row = RaceClassesDataDT->FindRow<FEXWClassRaces>(FName(UEnum::GetValueAsString(Race).RightChop(12)), ContextString, true))
		{
			TArray<FEXWClassVisualData> ClassList = Row->Classlist;
			for (FEXWClassVisualData ClassL : ClassList)
			{
				if (ClassL.Class == Class)
				{
					AvailableActions = ClassL.DefaultIFrameActions;
					break;
				}
			}

			if (UDataTable* ActionsDT = GetActionsDT()) {
				for (auto Row : ActionsDT->GetRowMap())
				{
					FEXWAction Action = *reinterpret_cast<FEXWAction*>(Row.Value);
					if (AvailableActions.Contains(Action.ID))
					{
						Actions.AddUnique(Action);

					}
				}
			}
		}
	}

	return Actions;
}

UDataTable* UEXWDataLibrary::GetQuestsDT()
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
	{
		if (SingletonObj->QuestDT)
		{
			return SingletonObj->QuestDT;
		}
	}
	return nullptr;
}

FEXWQuest UEXWDataLibrary::GetQuestByID(FName QuestID)
{
	FEXWQuest Quest;

	if (UDataTable* QuestsDT = GetQuestsDT()) {
		static const FString ContextString(TEXT("QuestDT"));
		if (FEXWQuest* Row = QuestsDT->FindRow<FEXWQuest>(QuestID, ContextString))
		{
			Quest = *Row;
		}
		
	}

	return Quest;
}

TArray<FEXWQuest> UEXWDataLibrary::GetQuestsByIDs(TArray<FName> QuestIDs)
{
	TArray<FEXWQuest> Quests;
	if (UDataTable* QuestsDT = GetQuestsDT()) {
		static const FString ContextString(TEXT("QuestDT"));
		for (FName QuestID : QuestIDs)
		{
			if (FEXWQuest* Row = QuestsDT->FindRow<FEXWQuest>(QuestID, ContextString))
			{
				Quests.Add(*Row);
			}
		}
	}
	return Quests;
}

UDataTable* UEXWDataLibrary::GetDialoguesDT()
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
	{
		if (SingletonObj->DialogueDT)
		{
			return SingletonObj->DialogueDT;
		}
	}
	return nullptr;
}

FEXWDialogue UEXWDataLibrary::GetDialogueByID(FName DialogueID)
{
	FEXWDialogue Dialogue;

	if (UDataTable* DialoguesDT = GetDialoguesDT()) {
		static const FString ContextString(TEXT("DialogueDT"));
		if (FEXWDialogue* Row = DialoguesDT->FindRow<FEXWDialogue>(DialogueID, ContextString))
		{
			Dialogue = *Row;
		}
		
	}

	return Dialogue;
}

UDataTable* UEXWDataLibrary::GetDialogueSpeakersDT()
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
	{
		if (SingletonObj->DialogueSpeakerDT)
		{
			return SingletonObj->DialogueSpeakerDT;
		}
	}
	return nullptr;
}

FEXWDialogueSpeaker UEXWDataLibrary::GetDialogueSpeakerByID(FName SpeakerID)
{
	FEXWDialogueSpeaker DialogueSpeaker;

	if (UDataTable* DialogueSpeakersDT = GetDialogueSpeakersDT()) {
		static const FString ContextString(TEXT("DialogueSpeakerDT"));
		if (FEXWDialogueSpeaker* Row = DialogueSpeakersDT->FindRow<FEXWDialogueSpeaker>(SpeakerID, ContextString))
		{
			DialogueSpeaker = *Row;
		}
		
	}

	return DialogueSpeaker;
}

bool UEXWDataLibrary::GetDefaultTargetingByRaceAndClass(EEXWRace Race, EEXWClass Class)
{
	bool bCanUseDefaultTargeting = false;

	UDataTable* RaceClassesDataDT;
	if (UEXWDataLibrary::GetRaceClassesDataDT(RaceClassesDataDT))
	{
		static const FString ContextString(TEXT("RaceClassesDataDT"));
		//We CHop 12 from the right to account for EEXWRace::R_ prefix
		if (FEXWClassRaces* Row = RaceClassesDataDT->FindRow<FEXWClassRaces>(FName(UEnum::GetValueAsString(Race).RightChop(12)), ContextString, true))
		{
			TArray<FEXWClassVisualData> ClassList = Row->Classlist;
			for (FEXWClassVisualData ClassL : ClassList)
			{
				if (ClassL.Class == Class)
				{
					//UE_LOG(LogTemp, Warning, TEXT("Default Targeting for %s is %s"), *UEnum::GetValueAsString(ClassL.Class), (ClassL.bCanUseDefaultTargeting ? TEXT("true") : TEXT("false")));
					bCanUseDefaultTargeting = ClassL.bCanUseDefaultTargeting;
					break;
				}
			}

		}
	}

	return bCanUseDefaultTargeting;
}

bool UEXWDataLibrary::UpdateLastAffectedPlayer(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter)
{
	if (SourceCharacter!=nullptr && TargetCharacter!=nullptr)
	{
		SourceCharacter->LastCharacterAffected = TargetCharacter;
		TargetCharacter->LastCharacterAffectedBy = SourceCharacter;
	}
	else
	{
		SourceCharacter->LastCharacterAffected = nullptr;
	}
	return true;
}

UDataTable* UEXWDataLibrary::GetNPCShopsDT()
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
	{
		if (SingletonObj->NPCShopDT)
		{
			return SingletonObj->NPCShopDT;
		}
	}
	return nullptr;
}

FEXWShop UEXWDataLibrary::GetNPCShopByID(FName NPCShopID)
{
	FEXWShop Shop;

	if (UDataTable* ShopsDT = GetNPCShopsDT()) {
		static const FString ContextString(TEXT("NPCShopDT"));
		if (FEXWShop* Row = ShopsDT->FindRow<FEXWShop>(NPCShopID, ContextString))
		{
			Shop = *Row;
		}
	}
	return Shop;
}

UAnimMontage* UEXWDataLibrary::GetVendingAnimMontageByRaceAndClass(EEXWRace Race, EEXWClass Class)
{
	UAnimMontage* AnimMontage = nullptr;

	UDataTable* RaceClassesDataDT;
	if (UEXWDataLibrary::GetRaceClassesDataDT(RaceClassesDataDT))
	{
		static const FString ContextString(TEXT("RaceClassesDataDT"));
		//We CHop 12 from the right to account for EEXWRace::R_ prefix
		if (FEXWClassRaces* Row = RaceClassesDataDT->FindRow<FEXWClassRaces>(FName(UEnum::GetValueAsString(Race).RightChop(12)), ContextString, true))
		{
			TArray<FEXWClassVisualData> ClassList = Row->Classlist;
			for (FEXWClassVisualData ClassL : ClassList)
			{
				if (ClassL.Class == Class)
				{
					//UE_LOG(LogTemp, Warning, TEXT("Default Targeting for %s is %s"), *UEnum::GetValueAsString(ClassL.Class), (ClassL.bCanUseDefaultTargeting ? TEXT("true") : TEXT("false")));
					AnimMontage = ClassL.VendingAnimation;
					break;
				}
			}

		}
	}

	return AnimMontage;
}

UDataTable* UEXWDataLibrary::GetItemSetsDT()
{
	UEXWSingleton* SingletonObj;
	if (GetSingleton(SingletonObj))
	{
		if (SingletonObj->ItemSetDT)
		{
			return SingletonObj->ItemSetDT;
		}
	}
	return nullptr;
}

FEXWItemSet UEXWDataLibrary::GetItemSetByID(FName ItemSetID)
{
	FEXWItemSet ItemSet;

	if (UDataTable* ItemSetsDT = GetItemSetsDT()) {
		static const FString ContextString(TEXT("ItemSetDT"));
		if (FEXWItemSet* Row = ItemSetsDT->FindRow<FEXWItemSet>(ItemSetID, ContextString))
		{
			ItemSet = *Row;
		}
	}
	return ItemSet;
}
