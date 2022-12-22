// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWDialogueWidget.h"
#include "Core/EXWPlayerController.h"
#include "Library/EXWDataLibrary.h"

void UEXWDialogueWidget::LoadDialogueData()
{
	Dialogue = UEXWDataLibrary::GetDialogueByID(DialogueID);
}

void UEXWDialogueWidget::ExitDialogue()
{
	if (AEXWPlayerController* PC = GetOwningPlayer<AEXWPlayerController>())
	{
		PC->DialogueWidget->RemoveFromParent();
		PC->DialogueWidget = nullptr;
	}
}

void UEXWDialogueWidget::StartQuest(FName QuestID)
{
	if (AEXWPlayerController* PC = GetOwningPlayer<AEXWPlayerController>())
	{
		PC->DisplayQuestPanelUI(QuestID);
	}
}

void UEXWDialogueWidget::HandleResponse(FEXWDialogueResponse Response)
{
	if (Response.Branch == "None")
	{
		if (Response.QuestID != "None")
		{
			StartQuest(Response.QuestID);
		}
		else if (Dialogue.QuestID != "None")
		{
			StartQuest(Dialogue.QuestID);
			
		}
		ExitDialogue();
	}
	else
	{
		DialogueID = Response.Branch;
		InitDialogue();
	}
}

/*void UEXWDialogueWidget::HandleResponse(FEXWDialogue Response)
{
	if (Response.QuestID != "None")
	{
		StartQuest(Response.QuestID);
		ExitDialogue();
	}
	else {
		InitDialogueWithData(Response);
	}
}*/
