// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWInteractable.h"
#include "Components/WidgetComponent.h"


// Add default functionality here for any IEXWInteractable functions that are not pure virtual.

void IEXWInteractable::OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType)
{
	
}

void IEXWInteractable::OnReceiveClick(AEXWCharacter* SourceCharacter)
{

}

UWidgetComponent* IEXWInteractable::GetInteractionWidgetComponent()
{
	return MakeWeakObjectPtr<UWidgetComponent>(nullptr).Get();
}

void IEXWInteractable::SetInteractionWidgetVisibility(const bool bNewVisibility /*= true*/)
{
	// Nothing for now
}
