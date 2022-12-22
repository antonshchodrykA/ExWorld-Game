// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Library/EXWDataStruct.h"
#include "EXWDialogueWidget.generated.h"


struct FEXWDialogue;
/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWDialogueWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Data")
	FName DialogueID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Data")
	FEXWDialogue Dialogue;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "EXWorld|Dialogue")
	void InitDialogue();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "EXWorld|Dialogue")
	void InitDialogueWithData(FEXWDialogue DialogueData);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Data")
	void LoadDialogueData();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Widget")
	void ExitDialogue();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Widget")
	void StartQuest(FName QuestID);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Widget")
	void HandleResponse(FEXWDialogueResponse Response);

	/*UFUNCTION(BlueprintCallable, Category = "EXWorld|Widget")
	void HandleResponse(FEXWDialogue Response);*/
};
