// Fill out your copyright notice in the Description page of Project Settings.

#include "EXWDamageAbsorptionSE.h"
#include "Core/EXWCharacter.h"


void AEXWDamageAbsorptionSE::BeginPlay()
{
	Super::BeginPlay();
	ApplyDamageAbsorptionGain();
}

void AEXWDamageAbsorptionSE::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	ApplyDamageAbsorptionLoss();
	Super::EndPlay(EndPlayReason);
}

void AEXWDamageAbsorptionSE::ApplyDamageAbsorptionGain()
{
	if (AEXWCharacter* TargetCharacter = GetTargetCharacter())
	{
		if (TargetCharacter->IsLocallyControlled())
		{
			for (FEXWDamageAbsorption& DamageAbsorption : DamageAbsorptions)
			{
				TargetCharacter->Server_GainDamageAbsorption(DamageAbsorption.DamageType, DamageAbsorption.Value);
			}
		}
	}
}

void AEXWDamageAbsorptionSE::ApplyDamageAbsorptionLoss()
{
	if (AEXWCharacter* TargetCharacter = GetTargetCharacter())
	{
		if (TargetCharacter->IsLocallyControlled())
		{
			for (FEXWDamageAbsorption& DamageAbsorption : DamageAbsorptions)
			{
				TargetCharacter->Server_LoseDamageAbsorption(DamageAbsorption.DamageType, DamageAbsorption.Value);
			}
		}
	}
}
