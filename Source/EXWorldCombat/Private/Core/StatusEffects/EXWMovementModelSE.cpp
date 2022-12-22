// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/StatusEffects/EXWMovementModelSE.h"
#include "Core/EXWCharacter.h"
#include "Character/ALSBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void AEXWMovementModelSE::BeginPlay()
{
	Super::BeginPlay();
	if (AALSBaseCharacter* ALSBaseCharacterTemp = GetTargetALSBaseCharacter())
	{
		PreviousMovementModel = ALSBaseCharacterTemp->GetMovementModel();
		ALSBaseCharacter = MakeWeakObjectPtr<AALSBaseCharacter>(ALSBaseCharacterTemp);
		ALSBaseCharacter->GetMovementComponent()->SetActive(false);
	}
	else if (GetTargetCharacter()) // for AI
	{
		if (!GetTargetCharacter()->IsPlayerControlled())
		{
			GetTargetCharacter()->GetCharacterMovement()->SetActive(false);//SetMovementMode(MOVE_None);
		}

	}
}

void AEXWMovementModelSE::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (ALSBaseCharacter.IsValid())
	{
		ALSBaseCharacter.Get()->SetMovementModel(PreviousMovementModel);
		ALSBaseCharacter->GetMovementComponent()->SetActive(true);
	} else if (GetTargetCharacter()) // for AI
	{
		if (!GetTargetCharacter()->IsPlayerControlled())
		{
			GetTargetCharacter()->GetCharacterMovement()->SetActive(true);//SetMovementMode(MOVE_None);
		}
		
	}
}

void AEXWMovementModelSE::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ALSBaseCharacter.IsValid())
	{
		//ALSBaseCharacter.Get()->SetMovementModel(MovementModel);
	}
}

AALSBaseCharacter* AEXWMovementModelSE::GetTargetALSBaseCharacter()
{
	if (StatusEffectData.TargetCharacter.IsValid())
	{
		return Cast<AALSBaseCharacter>(StatusEffectData.TargetCharacter.Get());
	}
	return nullptr;
}
