// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#pragma once

#include "CoreMinimal.h"
#include "Library/EXWDataEnum.h"
#include "Engine/DataTable.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/DamageType.h"
#include "EXWDataStruct.generated.h"

/**
 * Forward declaration
 */
class AEXWCharacter;
class AEXWStatusEffect;
class AEXWSpawnableAbility;
class AEXWSpawnableAbilityIndicator;
class UNiagaraSystem;
class AEXWorldCombatPlayerState;

USTRUCT(BlueprintType)
struct FEXWAttribute
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEXWAttributeType AttributeType = EEXWAttributeType::Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentValue = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 bIsCapped : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bIsCapped"))
		float MaxValue = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 bCanBeBelowZero : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 bDefaultCurrentValueZero : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEXWStatType StatType = EEXWStatType::Agility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float StatModifier = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 bApplyRegen : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bApplyRegen"))
		float RegenValue = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bApplyRegen"))
		float RegenTickingRate = 1.f;

	/** Timer handle to manage this resource regeneration ticking */
	FTimerHandle RegenTimerHandle;

	FEXWAttribute()
	{
		// Default construction here
		bIsCapped = false;
		bCanBeBelowZero = false;
		bDefaultCurrentValueZero = false;
		bApplyRegen = false;
	};

	FEXWAttribute(const EEXWAttributeType NewAttributeType)
	{
		bIsCapped = false;
		bCanBeBelowZero = false;
		bDefaultCurrentValueZero = false;
		bApplyRegen = false;
		AttributeType = NewAttributeType;
	};

	FEXWAttribute(const EEXWAttributeType NewAttributeType,
		const bool bNewIsCapped,
		const bool bNewCanBeBelowZero,
		const EEXWStatType NewStatType,
		const float NewStatModifier,
		const bool bNewApplyRegen = false,
		const float NewRegenValue = 0.f,
		const float NewRegenTickingRate = 1.f,
		const bool bNewDefaultCurrentValueZero = false)
	{
		AttributeType = NewAttributeType;
		bIsCapped = bNewIsCapped;
		bCanBeBelowZero = bNewCanBeBelowZero;
		StatType = NewStatType;
		StatModifier = NewStatModifier;
		bApplyRegen = bNewApplyRegen;
		RegenValue = NewRegenValue;
		RegenTickingRate = NewRegenTickingRate;
		bDefaultCurrentValueZero = bNewDefaultCurrentValueZero;
	};

	void GainAttribute(const float Value) {
		
		if (CurrentValue + Value > MaxValue && bIsCapped) {
			CurrentValue = MaxValue;
		}
			
		else if (!bCanBeBelowZero)
			CurrentValue = FMath::Max(0.0f, CurrentValue + Value);
		else
			CurrentValue = CurrentValue + Value;
	};

	void LoseAttribute(const float Value) {
		if (CurrentValue - Value >= 0)
		{
			CurrentValue = CurrentValue - Value;
		}
		else if (bCanBeBelowZero)
		{
			CurrentValue = CurrentValue - Value;
		}
		else
		{
			CurrentValue = 0;
		}
	};

	FORCEINLINE bool operator==(const FEXWAttribute& rhs) const
	{
		return (rhs.AttributeType == this->AttributeType);
	};
};

USTRUCT(BlueprintType)
struct FEXWStat
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEXWStatType StatType = EEXWStatType::Agility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Value = 0.f;

	FEXWStat()
	{

	};

	FEXWStat(const EEXWStatType NewStatType)
	{
		StatType = NewStatType;
	};

	FEXWStat(const EEXWStatType NewStatType, const float NewValue)
	{
		StatType = NewStatType;
		Value = NewValue;
	};

	void GainStat(const float InValue) {
		Value += InValue;
	};

	void LoseStat(const float InValue) {
		if (Value - InValue > 0)
			Value -= InValue;
		else Value = 0;
	};

	FORCEINLINE bool operator==(const FEXWStat& rhs) const
	{
		return (rhs.StatType == this->StatType);
	};
};

USTRUCT(BlueprintType)
struct FEXWStatLevelPoint
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEXWStatType StatType = EEXWStatType::Agility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Level = 0;

	FEXWStatLevelPoint()
	{
		// Default constructor
	};

	FEXWStatLevelPoint(EEXWStatType NewStatType)
	{
		StatType = NewStatType;
	};

	FORCEINLINE bool operator==(const FEXWStatLevelPoint& rhs) const
	{
		return (rhs.StatType == this->StatType);
	};
};

USTRUCT(BlueprintType)
struct FEXWCharacterStat_Info
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats")
		TArray<FEXWStatLevelPoint> StatLevelPoints;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stats")
		int32 UnspentPoints;

};

USTRUCT(BlueprintType)
struct FEXWStatLevelModifier
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEXWStatType StatType = EEXWStatType::Intelligence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> LevelModifiers;

	FEXWStatLevelModifier() {
		// initialize the LevelModifiers to be 20 levels giving 10 stats each.
		for (uint8 i = 0; i < 20; i++)
			LevelModifiers.Add(10);
	};
};

USTRUCT(BlueprintType)
struct FEXWStatLevelModifierData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FEXWStatLevelModifier> LevelModifiers;

	FEXWStatLevelModifierData() : Super() {
		AddNewLevelModifier(EEXWStatType::Strength);
		AddNewLevelModifier(EEXWStatType::Agility);
		AddNewLevelModifier(EEXWStatType::Endurance);
		AddNewLevelModifier(EEXWStatType::Intelligence);
		AddNewLevelModifier(EEXWStatType::Luck);
	};

private:

	void AddNewLevelModifier(EEXWStatType StatType) {
		FEXWStatLevelModifier LevelModifier;
		LevelModifier.StatType = StatType;
		LevelModifiers.Add(LevelModifier);
	};
};


USTRUCT(BlueprintType)
struct FEXWAttributeEffect
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEXWAttributeType AttributeType = EEXWAttributeType::Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEXWEffectType EffectType = EEXWEffectType::Loss;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UDamageType> DamageType = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEXWValueType ValueType = EEXWValueType::Static;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ValueType == EEXWValueType::Static"))
		float StaticValue = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ValueType == EEXWValueType::DynamicOnSource || ValueType == EEXWValueType::DynamicOnTarget"))
		EEXWAttributeType ValueAttributeType = EEXWAttributeType::MagicDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "ValueType == EEXWValueType::DynamicOnSource || ValueType == EEXWValueType::DynamicOnTarget"))
		float ValueAttributePrecentage = 50.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effect")
		TArray<FString> StatusEffects;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Faction")
		bool bAffectOtherFaction = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Faction")
		bool bAffectOwnerFaction = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Faction")
		bool bAffectOwner = false;
};

USTRUCT(BlueprintType)
struct FEXWStatusEffectData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base")
		FName ID = "None";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display")
		FText Name = FText::FromString("Default_Status_Effect_Name");

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display")
		FText Description = FText::FromString("Default_Status_Effect_Description");

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Display")
		UTexture2D* DisplayIcon = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		EEXWStatusEffectType Type = EEXWStatusEffectType::Buff;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effect")
		TArray<FEXWAttributeEffect> AttributeEffects;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effect", meta = (ClampMin = 0.f, ClampMax = 5.f))
		float MovementModifierValue = 1.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		float Duration = 3.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		float TickingRate = 1.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "General")
		float TickingDelay = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
		TSubclassOf<AEXWStatusEffect> StatusEffectClass = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
		bool bAttachToTargetActor = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
		FName SocketName = "spine_03";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Misc")
		bool bCanStack = true;

	/**
	 * TempValues specific for this instance
	 */

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FTimerHandle TickingTimerHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FTimerHandle DurationHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FTimerHandle CountdownHandle;

	UPROPERTY()
		TWeakObjectPtr<AEXWCharacter> SourceCharacter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TWeakObjectPtr<AEXWCharacter> TargetCharacter;

	UPROPERTY()
		TWeakObjectPtr<AEXWStatusEffect> StatusEffectActor;

	/**
	 * Operators
	 */

	FORCEINLINE bool operator==(const FEXWStatusEffectData& rhs) const
	{
		return (rhs.ID == this->ID);
	}

	bool IsValid() {
		return ID != "None";
	}
};

USTRUCT(BlueprintType)
struct FEXWDamageReduction
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UDamageType> DamageType;

	/** Value between 0 and 100 representing the damage to be reduced/blocked */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Value;

	FEXWDamageReduction()
	{
		// Default Constructor
		Value = 0.f;
	};
	FEXWDamageReduction(const TSubclassOf<UDamageType> NewDamageType, const float NewValue)
	{
		DamageType = NewDamageType;
		Value = NewValue;
	};
};


USTRUCT(BlueprintType)
struct FEXWDamageAbsorption
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Value;

	FEXWDamageAbsorption()
	{
		// Default Constructor
		Value = 0.f;
	};
	FEXWDamageAbsorption(const TSubclassOf<UDamageType> NewDamageType, const float NewValue)
	{
		DamageType = NewDamageType;
		Value = NewValue;
	};
};

USTRUCT(BlueprintType)
struct FEXWSpawnableAbilityData : public FTableRowBase
{
	GENERATED_BODY()

public:

	/** The ID of the Spawnable Ability.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		FName ID = "None";

	/** The displayable name of the Spawnable Ability.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Display)
		FText Name = FText::FromString("Default_Spawnable_Ability_Name");

	/** The displayable description of the Spawnable Ability.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Display)
		FText Description = FText::FromString("Default_Spawnable_Ability_Description");

	/** The displayable icon of the Spawnable Ability.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Display)
		UTexture2D* DisplayIcon = nullptr;

	/** Type of the Spawnable ability (picking whether it's a projectile or instant ability..etc) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Transform)
		EEXWSpawnableAbilityType SpawnableAbilityType = EEXWSpawnableAbilityType::Projectile;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Transform, meta = (EditCondition = "SpawnableAbilityType == EEXWSpawnableAbilityType::Projectile || SpawnableAbilityType == EEXWSpawnableAbilityType::InstantAtTarget"))
		EEXWTargetingType TargetingType = EEXWTargetingType::TT_AimWithoutPitch;

	/** Homes towards a target if a target is valid and the projectile actor has "IsHomingProjectile" true.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Transform, meta = (EditCondition = "SpawnableAbilityType == EEXWSpawnableAbilityType::Projectile"))
		uint8 bIsHomingProjectile : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Transform)
		float DistanceRange = 2000.f;

	/** Whether to use the Character rotation or the socket rotation on spawn */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Transform)
		uint8 bUseCharacterRotation : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Transform)
		FName SourceSocketName = "spine_03";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Transform, meta = (EditCondition = "SpawnableAbilityType == EEXWSpawnableAbilityType::InstantAtSelf"))
		uint8 bAttachToSource : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Transform)
		FName TargetSocketName = "spine_03";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		uint8 bTargetOwnerFaction : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		uint8 bTargetOtherFaction : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		uint8 bTargetDead : 1;

	/** The effects that are going to be executed on the spawn event of the Spawnable Ability.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Effect)
		TArray<FEXWAttributeEffect> AttributeEffectsOnTarget;

	/** The effects that are going to be executed on the collision event of the Spawnable Ability.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Effect)
		TArray<FEXWAttributeEffect> AttributeEffectsOnCollision;

	/** The effects that are going to be executed on the tick trigger event of the Spawnable Ability.*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Effect)
		TArray<FEXWAttributeEffect> AttributeEffectsOnTick;

	/** If the Spawnable Ability will affect the target only once. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Effect)
		uint8 bAffectOnce : 1;

	/** The ticking rate of the effects. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Effect)
		float TickingRate = 1.f;

	/** Set the Spawnable Ability to be destroyed on collision event after applying the effects */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Destroy)
		uint8 bDestroyOnHit : 1;

	/** The timer that will represent the end of the Spawnable Ability after calling "Destroy Spawnable". */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "bDestroyOnHit"), Category = Destroy)
		float DestroyTimer = 2.f;

	/** The duration of the ability until the Destroy timer will start. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (EditCondition = "!bDestroyOnHit"), Category = Destroy)
		float Duration = 5.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Transform)
		TSubclassOf<AEXWSpawnableAbility> SpawnableAbilityClass = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Reaction)
		FName ReactionRowName = "None";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Reaction)
		uint8 bUseCharacterReactionDT : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Emitter)
		UParticleSystem* EmitterOnSpawn = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Emitter)
		UParticleSystem* EmitterOnApplyEffect = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Emitter, meta = (EditCondition = "EmitterOnApplyEffect != nullptr"))
		FName EmitterOnApplyEffectSocket = "spine_02";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Emitter)
		UParticleSystem* EmitterOnDestroy = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Emitter")
		UNiagaraSystem* NiagaraEmitterOnDestroy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Emitter, meta = (EditCondition = "NiagaraEmitterOnDestroy != nullptr"))
		FName EmitterOnDestroySocket = "none";

	/**
	 * TempValues specific for this instance
	 */

	UPROPERTY()
		FTimerHandle DurationHandle;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		TWeakObjectPtr<AEXWCharacter> SourceCharacter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		TWeakObjectPtr<AEXWCharacter> TargetCharacter;

	UPROPERTY()
		TWeakObjectPtr<AEXWSpawnableAbility> SpawnableAbilityActor;

	FEXWSpawnableAbilityData() {
		bAffectOnce = true;
		bDestroyOnHit = true;
		bUseCharacterReactionDT = true;
		bTargetOtherFaction = true;
		bTargetDead = false;
		bIsHomingProjectile = true;
		bAttachToSource = false;
	};
};

USTRUCT(BlueprintType)
struct FEXWSpawnableAbilitySpawnParams
{
	GENERATED_BODY()

public:

	UPROPERTY()
		FEXWSpawnableAbilityData SpawnableAbilityData;

	UPROPERTY()
		FVector Direction = FVector::ZeroVector;

	UPROPERTY()
		FTransform SpawnTransform;

	UPROPERTY()
		AEXWCharacter* SourceCharacter = nullptr;

	UPROPERTY()
		AEXWCharacter* TargetCharacter = nullptr;
};

USTRUCT(Blueprintable, BlueprintType)
struct FEXWTargetingParams
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		float Distance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		float Width;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		EEXWTargetingType TargetingType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		EEXWTargetFaction TargetFaction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		float StopTargetingDelay;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		uint8 bDebug : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = General)
		uint8 bHighlightTarget : 1;

	FEXWTargetingParams()
	{
		Distance = 2000.f;
		Width = 100.f;
		TargetingType = EEXWTargetingType::TT_AimWithoutPitch;
		TargetFaction = EEXWTargetFaction::TF_OtherFactionOnly;
		bDebug = false;
		bHighlightTarget = true;
		StopTargetingDelay = 0.f;
	};

	FEXWTargetingParams(const float NewDistance, const float NewWidth = 100.f,
		const EEXWTargetingType NewTargetingType = EEXWTargetingType::TT_AimWithoutPitch,
		const EEXWTargetFaction NewTargetFaction = EEXWTargetFaction::TF_OtherFactionOnly,
		const uint8 bNewDebug = false,
		const uint8 bNewHighlightTarget = true,
		const float NewStopTargetingDelay = 0.f)
	{
		Distance = NewDistance;
		Width = NewWidth;
		TargetingType = NewTargetingType;
		TargetFaction = NewTargetFaction;
		bDebug = bNewDebug;
		bHighlightTarget = bNewHighlightTarget;
		StopTargetingDelay = NewStopTargetingDelay;
	};
};

USTRUCT(Blueprintable, BlueprintType)
struct FEXWCooldown
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		FName ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		float Duration;

	UPROPERTY(BlueprintReadWrite)
		FTimerHandle TimerHandle;

	FORCEINLINE bool operator==(const FEXWCooldown& rhs) const
	{
		return (rhs.ID == this->ID);
	}

	FEXWCooldown()
	{
		ID = "None";
		Duration = 2.f;
	}
	FEXWCooldown(FName InID)
	{
		this->ID = InID;
	}
	FEXWCooldown(const FName InID, const float InDuration)
	{
		ID = InID;
		Duration = InDuration;
	}
};

USTRUCT(Blueprintable, BlueprintType)
struct FEXWMontageData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		UAnimMontage* AnimMontage = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		EEXWActionDirection Direction = EEXWActionDirection::AD_Any;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		EEXWDirectionMode DirectionMode = EEXWDirectionMode::CameraRotation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		uint8 bIsStateFree : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base, meta = (EditCondition = "!bIsStateFree"))
		TArray<EEXWState> ValidStates = {};

	FEXWMontageData()
	{
		bIsStateFree = true;
	};
};

USTRUCT(Blueprintable, BlueprintType)
struct FEXWReactionMontage
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		UAnimMontage* AnimMontage = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		EEXWRelativePosition RelativePosition;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		uint8 bIsStateFree : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		TArray<EEXWState> ValidStates = {};

	FEXWReactionMontage()
	{
		bIsStateFree = true;
	}
};


USTRUCT(BlueprintType)
struct FEXWActionLevel : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		int32 RequiredLevel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		float AttributeValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		float Cooldown;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		float LevelModifier;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		float Damage;

};

USTRUCT(BlueprintType)
struct FEXWActionAttributeLevelUpgrades : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		int32 RequiredLevel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		float AttributeValue;


};

USTRUCT(BlueprintType)
struct FEXWActionAttributeLevel : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		EEXWActionAttribute Attribute;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		int32 CurrentLevel = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		int32 MaxLevel = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		TArray<FEXWActionAttributeLevelUpgrades> Levels;

	FEXWActionAttributeLevel() {
		Attribute = EEXWActionAttribute::AA_Cooldown;
		CurrentLevel = 1;
		Levels = {};
	}

};

USTRUCT(BlueprintType)
struct FEXWAction : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		FName ID = "None";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Display)
		FText Name = FText::FromString("Action_Name");

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Display)
		UTexture2D* DisplayIcon = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Display)
		FText Description = FText::FromString("Action_Description");

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		bool bIsGenderFree = true;

	/** Animation Montage to play for this Action (Define one montage if it's a single animation or multiple if it's a Combination of montages (Combo System)) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base, meta = (EditCondition = "bIsGenderFree == true"))
		TArray<FEXWMontageData> MontagesData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base, meta = (EditCondition = "bIsGenderFree == false"))
		TArray<FEXWMontageData> MaleMontagesData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base, meta = (EditCondition = "bIsGenderFree == false"))
		TArray<FEXWMontageData> FemaleMontagesData;

	/** Attribute type to use. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		EEXWAttributeType Attribute = EEXWAttributeType::Mana;

	/** Value of the resources to consume */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		float Value = 10;

	/** Cooldown of the Action to be able to use it again This doesn't work on the Combo System. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		float Cooldown = 2.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		bool bIsPassive = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base, meta = (EditCondition = "bIsPassive"))
		FName StatusEffect = "None";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Level)
		int Level = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Level)
		float LevelModifier = 1.1f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Level)
		TArray<FEXWActionLevel> LevelUpgrades;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Level)
		TArray<FEXWActionAttributeLevel> AttributeLevelUpgrades;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		bool bShowCooldown = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Target)
		TSubclassOf<AEXWSpawnableAbilityIndicator> IndicatorClass = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Target)
		bool bEnableTargeting = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Target, meta = (EditCondition = "bEnableTargeting"))
		FEXWTargetingParams TargetingParams;

	FORCEINLINE bool operator==(const FEXWAction& Other) const
	{
		return ID == Other.ID;
	}

};

USTRUCT(BlueprintType)
struct FEXWReaction : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		FName ID = "None";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Display)
		FText Name = FText::FromString("Reaction_Name");

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		bool bIsGenderFree = true;

	/** Animation Montage to play for this Action (Define one montage if it's a single animation or multiple if it's depending on the orientation or state) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base, meta = (EditCondition = "bIsGenderFree == true", EditConditionHides))
		TArray<FEXWReactionMontage> MontagesData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base, meta = (EditCondition = "bIsGenderFree == false", EditConditionHides))
		TArray<FEXWReactionMontage> MaleMontagesData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base, meta = (EditCondition = "bIsGenderFree == false", EditConditionHides))
		TArray<FEXWReactionMontage> FemaleMontagesData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		uint8 bForceRotate : 1;
};

USTRUCT(BlueprintType)
struct FEXWReactionSendingParams
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		FName RowName = "None";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Base)
		uint8 bUseCharacterReactionDT : 1;

	UPROPERTY()
		AEXWCharacter* SourceCharacter = nullptr;

	UPROPERTY()
		AEXWCharacter* TargetCharacter = nullptr;
};

//Character Creation
USTRUCT(BlueprintType)
struct FEXWCharacterCreation
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		EEXWClass Class;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		EEXWRace Race;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		EEXWGender Gender;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		FName Face;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		FName Eyes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		FName EyeColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		FName BodyType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		FName SkinColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		FName Hair;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
		FName HairColor;


	//UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreation")
	//	FEXWCharacterStat_Info  StatLevelPoints;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<EEXWStatType, int32> StatLevelPoints;
};


// Equipment And Inventory
USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		FName ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		UTexture2D* Icon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		FName Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		FString Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		EItemQuality Quality;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		EItemType Type;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		int32 Amount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		bool IsStackable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		int32 MaxStackSize;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		bool IsDroppable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		UStaticMesh* WorldMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		int32 Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		float Duration;

};

USTRUCT(BlueprintType)
struct FInvItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		FName ItemID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		int32 Amount;

};
USTRUCT(BlueprintType)
struct FEquipmentList : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
		FName Head;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
		FName Shoulder;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
		FName Chest;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
		FName Hands;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
		FName Legs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
		FName Feet;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
		FName Back;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
		FName Waist;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Equipment")
		TArray<FInvItem> ExInventoryItems;

};

USTRUCT(BlueprintType)
struct FEXWCharacterInventory_Info
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		TArray<FInvItem> InventorySlots;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
		int32 Currency;

};

USTRUCT(BlueprintType)
struct FEXWExperienceOnKill
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Experience")
		bool bGiveExperienceOnKill = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Experience", meta = (EditCondition = "bGiveExperienceOnKill"))
		int32 MidLevelRange = 3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Experience", meta = (EditCondition = "bGiveExperienceOnKill"))
		int32 InLevelRangeExperience = 100;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Experience", meta = (EditCondition = "bGiveExperienceOnKill"))
		int32 LossPerLevelExperience = 25;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Experience", meta = (EditCondition = "bGiveExperienceOnKill"))
		int32 MinimumExperience = 1;
};

USTRUCT(BlueprintType)
struct FEXWLifeSkill
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		EEXWLifeSkillType Type;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 Experience;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int32 Level;

	FEXWLifeSkill()
	{
		Type = EEXWLifeSkillType::LS_Alchemy;
		Experience = 0;
		Level = 1;
	};

	FEXWLifeSkill(const EEXWLifeSkillType NewLifeSkillType)
	{
		Type = NewLifeSkillType;
		Experience = 0;
		Level = 1;
	};

	FEXWLifeSkill(const EEXWLifeSkillType NewLifeSkillType, const int32 NewLevel)
	{
		Type = NewLifeSkillType;
		Level = NewLevel;
		Experience = 0;
	};
};

USTRUCT(BlueprintType)
struct FEXWLifeSkillExperienceData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<int32, int32> ExperiencePerLevel;

	FEXWLifeSkillExperienceData()
	{
		int32 Experience = 100;
		for (uint32 i = 1; i < 51; i++)
		{
			ExperiencePerLevel.Add(i, Experience);
			Experience += 200;
		}
	};
};

USTRUCT(BlueprintType)
struct FEXWLifeSkillVisualData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		EEXWLifeSkillType Type;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UTexture2D* Icon;
};

USTRUCT(BlueprintType)
struct FEXWHighlightData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName HighlightMaterialParamName = "HighlightColor";

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FLinearColor HighlightEnemyColor = (FLinearColor::Red * 25);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FLinearColor HighlightAllyColor = (FLinearColor::Green * 25);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FLinearColor HighlightNeutralColor = (FLinearColor::White * 25);

	FEXWHighlightData()
	{
		// Default Constructor
	};
};

USTRUCT(BlueprintType)
struct FEXWGhostTrailParams
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class USkeletalMesh* SkeletalMesh = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UMaterialInterface* Material = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Duration = 1.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Rate = .2f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FName OpacityParamName = "Opacity";
};

USTRUCT(BlueprintType)
struct FEXWScreenMessageData : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class UEXWScreenMessageWidget> ScreenMessageWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Text = FText::FromString("You cannot do this.");

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FSlateColor ColorAndOpactiy = FSlateColor(FLinearColor(.8f, 0.f, 0.f, 1.f));
};


/**
 * Party
 */
USTRUCT(BlueprintType)
struct FEXWPartyMember
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EEXWPartyMemberRoles Role;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		AEXWCharacter* Character = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		AEXWorldCombatPlayerState* PlayerState = nullptr;

	FEXWPartyMember() {
		Role = EEXWPartyMemberRoles::PMR_Member;
	}

	FEXWPartyMember(AEXWCharacter* InCharacter) {
		Role = EEXWPartyMemberRoles::PMR_Member;
		Character = InCharacter;
	};

	FEXWPartyMember(EEXWPartyMemberRoles InRole, AEXWCharacter* InCharacter, AEXWorldCombatPlayerState* InPlayerState) {
		Role = InRole;
		Character = InCharacter;	
		PlayerState = InPlayerState;
	};

	FEXWPartyMember(AEXWCharacter* InCharacter, AEXWorldCombatPlayerState* InPlayerState) {
		Role = EEXWPartyMemberRoles::PMR_Member;
		Character = InCharacter;
		PlayerState = InPlayerState;//Cast<AEXWorldCombatPlayerState>(Character->GetPlayerState());
	};

	FORCEINLINE bool operator==(const FEXWPartyMember& Other) const
	{
		return Character == Other.Character && Role == Other.Role;
	}
};

USTRUCT(BlueprintType)
struct FEXWParty
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Name = FText::FromString("Default Party");

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FEXWPartyMember> Members = {};

	FEXWParty() {
		ID = "-1";
	};

	FEXWParty(FName PartyID) {
		ID = PartyID;
	};

	FEXWParty(FName PartyID, FText PartyName) {
		ID = PartyID;
		Name = PartyName;
	};

	FEXWParty(FName PartyID, FText PartyName, TArray<FEXWPartyMember> PartyMembers) {
		ID = PartyID;
		Name = PartyName;
		Members = PartyMembers;
	};

	FORCEINLINE bool operator==(const FEXWParty& Other) const
	{
		return ID == Other.ID;
	}
};

/**
 * Quest System
 */

USTRUCT(BlueprintType)
struct FEXWQuestReward
{
	GENERATED_BODY()

public:

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EEXWQuestRewardType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "Type == EEXWQuestRewardType::QRT_Item"))
		FName Item;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 Quantity;

};

USTRUCT(BlueprintType)
struct FEXWQuestObjectiveLocation
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool bHasLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector Location;

};

USTRUCT(BlueprintType)
struct FEXWQuestObjective
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EEXWQuestObjectiveType Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FEXWQuestObjectiveLocation Location;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText GoalName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 AmountToGoal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<AActor> ObjectiveClass;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	//int32 ObjectiveID;
	UPROPERTY(BlueprintReadOnly)
		bool bIsCompleted;

	UPROPERTY(BlueprintReadOnly)
		int32 CurrentAmount;

	void ProgressObjective(int32 Amount) {
		CurrentAmount += Amount;
		if (CurrentAmount >= AmountToGoal)
		{
			SetCompleted();
		}
	}

	void SetCompleted() {
		bIsCompleted = true;
	}

	FORCEINLINE bool operator==(const FEXWQuestObjective& Other) const
	{
		return ID == Other.ID;
	}
};

USTRUCT(BlueprintType)
struct FEXWQuest : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EEXWQuestCategory Category;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FEXWQuestReward> Rewards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int32 RequiredLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FEXWQuestObjective> Objectives;

	bool HasTalkObjective(FEXWQuestObjective& OutObjective) {
		for (FEXWQuestObjective& Objective : Objectives)
		{
			if (Objective.Type == EEXWQuestObjectiveType::QOT_Talk)
			{
				OutObjective = Objective;
				return true;
			}
		}
		return false;
	}

	bool HasHuntObjective(FEXWQuestObjective& OutObjective) {
		for (FEXWQuestObjective& Objective : Objectives)
		{
			if (Objective.Type == EEXWQuestObjectiveType::QOT_Hunt)
			{
				OutObjective = Objective;
				return true;
			}
		}
		return false;
	}

	bool HasFinishedObjectives() {
		for (FEXWQuestObjective& Objective : Objectives)
		{
			if (!Objective.bIsCompleted)
			{
				return false;
			}
		}
		return true;
	}

	bool CompleteObjective(FName ObjectiveID) {
		FEXWQuestObjective Objective;
		if (GetObjectiveByID(ObjectiveID, Objective))
		{
			Objective.bIsCompleted = true;
			return true;
		}
		return false;
	}

	bool GetObjectiveByID(FName ObjectiveID, FEXWQuestObjective& OutObjective) {
		for (FEXWQuestObjective& Objective : Objectives)
		{
			if (Objective.ID == ObjectiveID)
			{
				OutObjective = Objective;
				return true;
			}
		}
		return false;
	}

	FORCEINLINE bool operator==(const FEXWQuest& Other) const
	{
		return ID == Other.ID;
	}
};

USTRUCT(BlueprintType)
struct FEXWDialogueSpeaker : public FTableRowBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UTexture2D* Portrait;
};

USTRUCT(BlueprintType)
struct FEXWDialogueResponse
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Branch UMETA(DisplayName = "Next Dialogue");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName QuestID;
};


USTRUCT(BlueprintType)
struct FEXWDialogue : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName SpeakerID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FEXWDialogueResponse> Responses;
		//TMap<FString, FEXWDialogue> Responses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName Branch UMETA(DisplayName = "Next Dialogue");

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName QuestID;

	FEXWDialogue() {
		ID = "None";
	}
};

USTRUCT(BlueprintType)
struct FEXWShopItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Quantity;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float PriceSilver;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float PriceGold;
};

USTRUCT(BlueprintType)
struct FEXWShop : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FEXWShopItem> Items;
};


/**
 * AI Spawner
 */

USTRUCT(BlueprintType)
struct FEXWAISpawnerData {
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<APawn> AICharacterClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UBehaviorTree* BehaviorTree = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float RespawnTimer = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = 1))
	int32 Level = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EEXWAITier Tier = EEXWAITier::AIT_One;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = 0.f, ClampMax = 100.f))
	float SpawnChance = 100.f;

	/** This determines how many AIs in the stack must be spawned before this AI can be considered for spawning
	* E.g: a Minimum Required Entities To Spawn = 10 means that this AI will only spawn if the total population
	* of the AI Multi Spawner is 10 or more.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Population", meta = (ClampMin = 0))
	int32 MinimumRequiredEntitiesToSpawn = 0;

	/** This determines how many of this Entity to spawn in a population,
	* if for example it is set to 1, in a population of 100 AIs at least 1 of them will be this AI.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Population", meta = (ClampMin = 0))
	int32 MinimumRequiredAmountToSpawn = 0;

	/** This determines the max amount of this Entity to be spawned in a population,
	* E.g: if this is set to 5, in a population of 100 AIs there will be at most 5 of this Entity spawned.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Population", meta = (ClampMin = 0))
	int32 MaximumRequiredAmountToSpawn = 0;

	int32 SpawnedAmount = 0;

	FORCEINLINE bool operator==(const FEXWAISpawnerData& Other) const{
		return AICharacterClass == Other.AICharacterClass &&
			BehaviorTree == Other.BehaviorTree &&
			StaticMesh == Other.StaticMesh &&
			RespawnTimer == Other.RespawnTimer &&
			Level == Other.Level &&
			Tier == Other.Tier &&
			SpawnChance == Other.SpawnChance &&
			MinimumRequiredEntitiesToSpawn == Other.MinimumRequiredEntitiesToSpawn &&
			MinimumRequiredAmountToSpawn == Other.MinimumRequiredAmountToSpawn &&
			MaximumRequiredAmountToSpawn == Other.MaximumRequiredAmountToSpawn;
	}
	
};