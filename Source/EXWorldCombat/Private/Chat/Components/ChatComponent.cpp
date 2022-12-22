// Fill out your copyright notice in the Description page of Project Settings.


#include "ChatComponent.h"
#include "Kismet/GameplayStatics.h"
#include <Core/EXWPlayerController.h>
#include "Library/EXWDataLibrary.h"
#include <Core/EXWCharacter.h>


// Sets default values for this component's properties
UChatComponent::UChatComponent()
{

}


// Called when the game starts
void UChatComponent::BeginPlay()
{
	Super::BeginPlay();


}

void UChatComponent::Server_SendMessage_Implementation(FEXWChatMessage Message)
{

	switch (Message.Channel)
	{
	case EEXWChatChannel::C_General:
	{
		AExWorldGameState* const EXWGameState = GetOwner()->GetWorld() != NULL ? GetOwner()->GetWorld()->GetGameState<AExWorldGameState>() : NULL;
		for (auto& obj : EXWGameState->PlayerArray)
		{
			if (Cast<AEXWorldCombatPlayerState>(obj)->GetPawn()->GetController()->FindComponentByClass<UChatComponent>())//FEXWPlayerID.Equals(PlayerId))
			{
				UE_LOG(LogTemp, Warning, TEXT("General channel chat on server : %s"), *obj->GetPawn()->GetName());
				Cast<AEXWorldCombatPlayerState>(obj)->GetPawn()->GetController()->FindComponentByClass<UChatComponent>()->Client_RecieveMessage(Message);
			}
		}
	}
	break;

	//case EEXWChatChannel::C_Race:
	//	break;

	//case EEXWChatChannel::C_Guild:
	//	break;

	//case EEXWChatChannel::C_Party:
	//	break;

	//case EEXWChatChannel::C_Shout:
	//	break;

	//case EEXWChatChannel::C_Server:
	//	break;
	//	
	//case EEXWChatChannel::C_Command:
	//	break;

	default:
		Cast<AEXWPlayerController>(GetOwner())->FindComponentByClass<UChatComponent>()->Client_RecieveMessage(Message);
		break;
	}
}

void UChatComponent::Client_RecieveMessage_Implementation(FEXWChatMessage Message)
{
	onChatMessageRecieved.Broadcast(Message);
	ChatLog.Add(Message);
}

void UChatComponent::SendMessage_Implementation(FEXWChatMessage Message)
{
	if (!Message.Message.IsEmpty())
	{
		FString MessageStr = Message.Message.ToString();
		if (MessageStr.StartsWith("/", ESearchCase::IgnoreCase) && MessageStr.Len() > 1)
		{
			ProcessCommand(Message.Message.ToString());
		}
		else
		{
			Server_SendMessage(Message);
			return;
		}
	}

}

void UChatComponent::ProcessCommand(FString Message)
{
	FString CommandStr, Params;

	if (Message.Contains(" "))
		Message.Split(TEXT(" "), &CommandStr, &Params);
	else
		CommandStr = Message;

	EEXWChatCommandType* Command = ChatCommands.Find(CommandStr);

	if (Command != nullptr)
	{

		AEXWPlayerController* PlayerController = Cast<AEXWPlayerController>(GetOwner());
		AEXWCharacter* PlayerCharacter = PlayerController->GetPawn<AEXWCharacter>();
		FEXWParty Party = PlayerController->GetPlayerState<AEXWorldCombatPlayerState>()->CurrentParty;
		AExWorldGameState* GameState = GetWorld()->GetGameState<AExWorldGameState>();


		switch (*Command)
		{
		case EEXWChatCommandType::CC_Respawn:
		{
			Cast<AEXWPlayerController>(GetOwner())->RequestRespawnPawn(false);
			break;
		}
		case EEXWChatCommandType::CC_LevelUp:
		{
			if (Params.Len() > 0)
				Cast<AEXWCharacter>(Cast<AEXWPlayerController>(GetOwner())->GetPawn())->Server_SetLevel(FCString::Atoi(*Params));
			else
				Cast<AEXWCharacter>(Cast<AEXWPlayerController>(GetOwner())->GetPawn())->Server_LevelUp();
			break;
		}
		case EEXWChatCommandType::CC_PartyChat:
			break;

		case EEXWChatCommandType::CC_PartyInvite:
			if (Params.Len() == 0)
			{
				break;
			}

			//Check if Party exists
			if (Party.ID == "-1")
			{
				//Create Party
				FName PartyID = FName(*FString::SanitizeFloat(FMath::FRandRange(0.f, 20000.f)));
				FString PartyName = PlayerCharacter->Name.ToString();
				PartyName.Append("'s Party");
				TArray<AEXWCharacter*> PartyMembers;
				PartyMembers.Add(GameState->GetCharacterFromText(FText::FromString(Params)));
				PlayerCharacter->RequestCreateParty(PartyID, FText::FromString(PartyName), PartyMembers);
			}
			
			//First check if party admin
			if (GameState->GetPartyLeader(Party) == PlayerCharacter)
			{
				PlayerCharacter->RequestInviteToParty(Party, FText::FromString(Params));
			}
			

			break;

		case EEXWChatCommandType::CC_PartyKick:
			if (Params.Len() == 0)
			{
				break;
			}

			//First check if party admin
			if (GameState->GetPartyLeader(Party) == PlayerCharacter)
			{
				if (AEXWCharacter* Character = GameState->GetCharacterFromText(FText::FromString(Params))) {
					PlayerCharacter->RequestKickMember(Party, Character);
					break;
				}
			}
			break;

		case EEXWChatCommandType::CC_PartyPromote:
			if (Params.Len() == 0)
			{
				break;
			}

			//First check if party admin
			if (GameState->GetPartyLeader(Party) == PlayerCharacter)
			{
				if (AEXWCharacter* Character = GameState->GetCharacterFromText(FText::FromString(Params))) {
					PlayerCharacter->RequestPromoteMember(Party, Character);
					break;
				}
			}
			break;

		case EEXWChatCommandType::CC_Teleport:
			if(UWorld* World=GetOwner()->GetWorld())
			{
				//UExWorldGameInstance* GameInstance = Cast<UExWorldGameInstance>(UGameplayStatics::GetGameInstance(World));
				AEXWRespawnPoint* TargetRespawnPoint;
				if (UEXWDataLibrary::GetRespawnPointWithName(PlayerCharacter, Params, TargetRespawnPoint))
				{
					PlayerCharacter->Replicated_SetActorLocationAndRotation(TargetRespawnPoint->GetActorLocation(), TargetRespawnPoint->GetActorRotation());
				}
			}
			break;

		case EEXWChatCommandType::CC_AddItem:
			
			if (Params.Len() > 0)
			{
				FString ItemName,Count;
				Params.Split(TEXT(" "), &ItemName, &Count);
				PlayerCharacter->Server_AddItemsToInventory(FName(ItemName),FCString::Atoi(*Count));
			}

			PlayerCharacter->Server_AddItemsToInventory(FName(Params),1);
			break;

		default:
			break;
		}
	}
}

TArray<FEXWChatMessage> UChatComponent::GetChatLog()
{
	return ChatLog;
}

