// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Library/EXWDataEnum.h"
#include "EXWInteractable.generated.h"

class AEXWCharacter;
class UWidgetComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UEXWInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class EXWORLDCOMBAT_API IEXWInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType);
	
	virtual void OnReceiveClick(AEXWCharacter* SourceCharacter);

	virtual UWidgetComponent* GetInteractionWidgetComponent();

	virtual void SetInteractionWidgetVisibility(const bool bNewVisibility = true);

	TArray<EEXWInteractionType> AvailableInteractionTypes;

	float InteractionMaxDistance = 100.f;
};
