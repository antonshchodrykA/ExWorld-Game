// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/StatusEffects/EXWDamageReductionSE.h"
#include "Core/EXWCharacter.h"

void AEXWDamageReductionSE::BeginPlay()
{
	Super::BeginPlay();
	ApplyDamageReductionGain();
}

void AEXWDamageReductionSE::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	ApplyDamageReductionLoss();
	Super::EndPlay(EndPlayReason);
}

void AEXWDamageReductionSE::ApplyDamageReductionGain()
{
	if (AEXWCharacter* TargetCharacter = GetTargetCharacter())
	{
		if (TargetCharacter->IsLocallyControlled())
		{
			for (FEXWDamageReduction &DamageReduction : DamageReductions)
			{
				TargetCharacter->Server_GainDamageReduction(DamageReduction.DamageType, DamageReduction.Value);
			}
		}
	}
}

void AEXWDamageReductionSE::ApplyDamageReductionLoss()
{
	if (AEXWCharacter* TargetCharacter = GetTargetCharacter())
	{
		if (TargetCharacter->IsLocallyControlled())
		{
			for (FEXWDamageReduction& DamageReduction : DamageReductions)
			{
				TargetCharacter->Server_LoseDamageReduction(DamageReduction.DamageType, DamageReduction.Value);
			}
		}
	}
}
