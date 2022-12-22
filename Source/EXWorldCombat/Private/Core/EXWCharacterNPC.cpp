// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWCharacterNPC.h"
#include "EXWPlayerController.h"
#include "Library/EXWDataLibrary.h"
#include "Library/Inventory/EXWInventoryLibrary.h"

AEXWCharacterNPC::AEXWCharacterNPC(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	AvailableInteractionTypes = { EEXWInteractionType::IT_Talk, EEXWInteractionType::IT_AskForQuest};
	InteractionMaxDistance = 600.f;
}

void AEXWCharacterNPC::OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType)
{
	//Super::OnReceiveInteraction(SourceCharacter, InteractionType);
	if (SourceCharacter)
	{
		if (AEXWCharacter* Character = Cast<AEXWCharacter>(SourceCharacter))
		{
			// TODO: use switch case instead.
			if (InteractionType == EEXWInteractionType::IT_Talk)
			{
				Character->Multicast_CreateDialogueWidget(SourceCharacter, DialogueID);
				return;
			}
			if (InteractionType == EEXWInteractionType::IT_Shop)
			{
				Character->Multicast_CreateNPCShopWidget(SourceCharacter, this, ShopID);
			}
		}
	}
	
}

void AEXWCharacterNPC::BeginPlay()
{
	Super::BeginPlay();
	if (!ShopID.IsNone())
	{
		AvailableInteractionTypes.Add(EEXWInteractionType::IT_Shop);
		//UEXWInventoryLibrary
		FEXWShop NPCShop = UEXWDataLibrary::GetNPCShopByID(ShopID);
		for (FEXWShopItem ShopItem : NPCShop.Items)
		{
			UEXWInventoryLibrary::AddItems(ShopItem.ItemID, ShopItem.Quantity, this->InventoryShop);
		}
	}
	
}

