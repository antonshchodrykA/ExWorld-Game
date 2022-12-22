// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWStateSE.h"
#include "Core/EXWCharacter.h"

void AEXWStateSE::BeginPlay()
{
	Super::BeginPlay();
	ApplyState();
}

void AEXWStateSE::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	ClearState();
	Super::EndPlay(EndPlayReason);
}

void AEXWStateSE::ApplyState()
{
	if (AEXWCharacter* TargetCharacter = GetTargetCharacter())
	{
		if (TargetCharacter->IsLocallyControlled())
		{
			if (TargetCharacter->CanAddState(State))
			{
				TargetCharacter->AddState(State);
			}
			
		}
	}
}

void AEXWStateSE::ClearState()
{
	if (AEXWCharacter* TargetCharacter = GetTargetCharacter())
	{
		if (TargetCharacter->IsLocallyControlled())
		{
			TargetCharacter->RemoveState(State);
		}
	}
}
