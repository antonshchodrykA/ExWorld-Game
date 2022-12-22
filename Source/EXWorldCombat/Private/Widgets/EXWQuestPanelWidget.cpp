// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWQuestPanelWidget.h"
#include "Core/EXWPlayerController.h"
#include "Library/EXWDataLibrary.h"
#include "EXWorldCombatPlayerState.h"

void UEXWQuestPanelWidget::LoadQuestData()
{
	Quest = UEXWDataLibrary::GetQuestByID(QuestID);
}

void UEXWQuestPanelWidget::ExitQuest()
{
	if (AEXWPlayerController* PC = GetOwningPlayer<AEXWPlayerController>())
	{
		PC->QuestPanelWidget->RemoveFromParent();
		PC->QuestPanelWidget = nullptr;
	}
}

void UEXWQuestPanelWidget::StartQuest()
{
	if (AEXWorldCombatPlayerState* PS = GetOwningPlayer()->GetPlayerState<AEXWorldCombatPlayerState>())
	{
		PS->Server_AddQuest(Quest.ID);
	}
}
