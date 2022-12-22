// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Library/EXWDataStruct.h"
#include "EXWScreenMessageWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class EXWORLDCOMBAT_API UEXWScreenMessageWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FEXWScreenMessageData ScreenMessageData;

	UEXWScreenMessageWidget(const FObjectInitializer& ObjectInitializer);

};
