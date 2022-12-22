// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWPlaceableCraftStation.h"
#include "Core/EXWCharacter.h"

AEXWPlaceableCraftStation::AEXWPlaceableCraftStation()
{
	AvailableInteractionTypes = { EEXWInteractionType::IT_Craft };
	InteractionMaxDistance = 600.f;
}

void AEXWPlaceableCraftStation::StartCrafting(AEXWCharacter* SourceCharacter, const FName CraftID)
{
	if (SourceCharacter)
	{
		FTimerDelegate CraftingTimerDelegate;
		CraftingTimerDelegate.BindLambda([&] { StopCrafting(SourceCharacter, CraftID); });
		GetWorld()->GetTimerManager().SetTimer(CraftingTimerHandle, CraftingTimerDelegate, .1f, false, CraftingDuration);

		SourceCharacter->Client_Gathering(LifeSkillType, CraftingDuration);
	}
}

void AEXWPlaceableCraftStation::StopCrafting(AEXWCharacter* SourceCharacter, const FName CraftID)
{
	if (SourceCharacter)
	{
		if (SourceCharacter->Replicated_ExecuteCraft(CraftID)) {
			// Give experience
			for (TPair<EEXWLifeSkillType, int32>& Experience : Experiences)
			{
				SourceCharacter->GainLifeSkillExperience(Experience.Key, Experience.Value);
			}
		}
	}
}

void AEXWPlaceableCraftStation::OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType)
{
	if (SourceCharacter)
	{
		SourceCharacter->Multicast_CreateCraftWidget(SourceCharacter, this, CraftCategory);
	}
}
