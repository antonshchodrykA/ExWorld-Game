// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "Network/ExWorldOnlineDatabase.h"
//#include "Network/ExWorldGameInstance.h"
#include "Network/ExWorldGameState.h"
#include "EXWorldCombatPlayerState.h"
#include "GameFramework/Actor.h"
#include <EXWorldCombat/Public/Library/Chat/EXWChatStruct.h>
#include "Core/Gameplay/EXWRespawnPoint.h"
#include "ChatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FonChatMessageRecieved, FEXWChatMessage,Message);

UCLASS(SpatialType, ClassGroup=(Blueprintable), meta=(BlueprintSpawnableComponent) )
class EXWORLDCOMBAT_API UChatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UChatComponent();


//Delegates	
	UPROPERTY(BlueprintAssignable)
	FonChatMessageRecieved onChatMessageRecieved;

//functions
	UFUNCTION(Client, Reliable,BlueprintCallable, Category = "EXWorld|ChatComponent")
	void SendMessage(FEXWChatMessage Message);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|ChatComponent")
	TArray<FEXWChatMessage> GetChatLog();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable, Category = "EXWorld|ChatComponent")
	void Server_SendMessage(FEXWChatMessage Message);

	UFUNCTION(Client, Reliable, Category = "EXWorld|ChatComponent")
	void Client_RecieveMessage(FEXWChatMessage Message);

	UFUNCTION(Category = "EXWorld|ChatComponent")
	void ProcessCommand(FString Message);


//variables
public:	
	UPROPERTY(BlueprintReadOnly, Category = "EXWorld|ChatComponent")
		TMap<EEXWChatChannel, EEXWChannelVisibility> ChannelVisibility = {
		{EEXWChatChannel::C_General, EEXWChannelVisibility::CV_AlwaysThere},
		{EEXWChatChannel::C_Race, EEXWChannelVisibility::CV_GeneralWithTab},
		{EEXWChatChannel::C_Guild, EEXWChannelVisibility::CV_GeneralWithTab},
		{EEXWChatChannel::C_Party, EEXWChannelVisibility::CV_GeneralWithTab},
		{EEXWChatChannel::C_Shout, EEXWChannelVisibility::CV_GeneralOnly},
		{EEXWChatChannel::C_Server, EEXWChannelVisibility::CV_GeneralOnly},
		{EEXWChatChannel::C_Whisper, EEXWChannelVisibility::CV_GeneralWithTab}
		};
protected:
	TArray<FEXWChatMessage> ChatLog;

	//&key is for admin accounts
	TMap<FString, EEXWChatCommandType> ChatCommands={
		{"/Respawn", EEXWChatCommandType::CC_Respawn},
		{"/LevelUp", EEXWChatCommandType::CC_LevelUp},
		{"/party", EEXWChatCommandType::CC_PartyChat},
		{"/p", EEXWChatCommandType::CC_PartyChat},
		{"/invite", EEXWChatCommandType::CC_PartyInvite},
		{"/kick", EEXWChatCommandType::CC_PartyKick},
		{"/promote", EEXWChatCommandType::CC_PartyPromote},
		{"/&tp", EEXWChatCommandType::CC_Teleport},
		{"/&ai", EEXWChatCommandType::CC_AddItem}
	};

private:
	//AExWorldGameState* const EXWGameState= nullptr;
		
};
