// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Library/EXWDataStruct.h"
#include "EXWQuestPanelWidget.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWQuestPanelWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Data")
	FName QuestID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Data")
	FEXWQuest Quest;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "EXWorld|Dialogue")
	void InitQuestPanel();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Data")
	void LoadQuestData();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Widget")
	void ExitQuest();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Widget")
	void StartQuest();
};
