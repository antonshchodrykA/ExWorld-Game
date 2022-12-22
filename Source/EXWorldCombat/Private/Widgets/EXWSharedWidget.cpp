// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/EXWSharedWidget.h"
#include "Core/EXWCharacter.h"

void UEXWSharedWidget::InitializeWidget(AEXWCharacter* InSourceCharacter, AEXWCharacter* InTargetCharacter, const bool bAddToViewport)
{
	SourceCharacter = InSourceCharacter;
	TargetCharacter = InTargetCharacter;
	if (bAddToViewport)
	{
		AddToViewport();
	}
	OnFinishInitialisation_Native();
}

void UEXWSharedWidget::OnFinishInitialisation_Native()
{
	OnFinishInitialisation();
}
