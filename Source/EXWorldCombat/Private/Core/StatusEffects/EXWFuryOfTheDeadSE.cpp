// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWFuryOfTheDeadSE.h"
#include "Core/EXWCharacter.h"

void AEXWFuryOfTheDeadSE::BeginPlay()
{
	if (GetSourceCharacter())
	{
		if (!GetSourceCharacter()->ActiveStatusEffects.Contains(StatusEffectData))
		{
			GetSourceCharacter()->OnStateAdded.AddDynamic(this, &AEXWFuryOfTheDeadSE::AddStack);
			GetSourceCharacter()->OnStateRemoved.AddDynamic(this, &AEXWFuryOfTheDeadSE::RemoveStack);
		}
	}
	
}

void AEXWFuryOfTheDeadSE::AddStack(EEXWState State)
{
	if (State == EEXWState::S_Disarmed || 
		State == EEXWState::S_Feared ||
		State == EEXWState::S_KnockedBack ||
		State == EEXWState::S_KnockedDown ||
		State == EEXWState::S_Rooted || 
		State == EEXWState::S_Silenced ||
		State == EEXWState::S_Stunned)
	{
		GetSourceCharacter()->Server_ConstructStatusEffect(RowName, GetSourceCharacter(), GetSourceCharacter());
	}
}

void AEXWFuryOfTheDeadSE::RemoveStack(EEXWState State)
{
	if (State == EEXWState::S_Disarmed ||
		State == EEXWState::S_Feared ||
		State == EEXWState::S_KnockedBack ||
		State == EEXWState::S_KnockedDown ||
		State == EEXWState::S_Rooted ||
		State == EEXWState::S_Silenced ||
		State == EEXWState::S_Stunned)
	{
		GetSourceCharacter()->Server_RemoveActiveStatusEffect(StatusEffectData);
	}
}
