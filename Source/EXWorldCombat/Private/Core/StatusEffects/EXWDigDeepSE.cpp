// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWDigDeepSE.h"
#include "Core/EXWCharacter.h"

void AEXWDigDeepSE::BeginPlay()
{
	if (GetSourceCharacter())
	{
		GetSourceCharacter()->OnAttributeGained.AddDynamic(this, &AEXWDigDeepSE::DecreaseDamage);
		GetSourceCharacter()->OnAttributeLost.AddDynamic(this, &AEXWDigDeepSE::IncreaseDamage);

		GetSourceCharacter()->GetAttributeCurrentValue(EEXWAttributeType::MagicDamage, OriginalDamage);
	}
}

void AEXWDigDeepSE::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetSourceCharacter()->SetAttributeCurrentValue(EEXWAttributeType::MagicDamage, OriginalDamage);
}

void AEXWDigDeepSE::IncreaseDamage(EEXWAttributeType AttributeType, float Value)
{
	if (AttributeType == EEXWAttributeType::Mana)
	{
		GetSourceCharacter()->GainAttribute(EEXWAttributeType::MagicDamage, DamageIncreasePerManaLost * Value);
	}
	
}

void AEXWDigDeepSE::DecreaseDamage(EEXWAttributeType AttributeType, float Value)
{
	if (AttributeType == EEXWAttributeType::Mana)
	{
		GetSourceCharacter()->LoseAttribute(EEXWAttributeType::MagicDamage, DamageIncreasePerManaLost * Value);
	}
}
