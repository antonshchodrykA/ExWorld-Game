// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EXWChatEnum.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EEXWChatChannel : uint8
{
	C_General = 0 UMETA(DisplayName = "General"),
	C_Race = 1 UMETA(DisplayName = "Race"),
	C_Guild = 2 UMETA(DisplayName = "Guild"),
	C_Party = 3 UMETA(DisplayName = "Party"),
	C_Shout = 4 UMETA(DisplayName = "Shout"),
	C_Server = 5 UMETA(DisplayName = "Server"),
	C_Whisper = 6 UMETA(DisplayName = "Whisper"),
	C_Command= 7 UMETA(DisplayName = "Command"),
	C_ChatCommand = 8 UMETA(DisplayName = "ChatCommand")
};

UENUM(BlueprintType)
enum class EEXWChannelVisibility : uint8
{
	CV_Hidden = 0 UMETA(DisplayName = "Hidden"),
	CV_AlwaysThere = 0 UMETA(DisplayName = "AlwaysThere"),
	CV_GeneralOnly = 1 UMETA(DisplayName = "GeneralOnly"),
	CV_GeneralWithTab = 2 UMETA(DisplayName = "GeneralWithTab")
};

UENUM(BlueprintType)
enum class EEXWChatCommandType : uint8
{
	CC_Respawn = 0 UMETA(DisplayName = "Respawn"),
	CC_LevelUp = 1 UMETA(DisplayName = "LevelUp"),
	CC_PartyChat = 2 UMETA(DisplayName = "ChatToParty"),
	CC_PartyInvite = 3 UMETA(DisplayName = "InviteToParty"),
	CC_PartyKick = 4 UMETA(DisplayName = "KickFromParty"),
	CC_PartyPromote = 5 UMETA(DisplayName = "PromoteInParty"),
	CC_Teleport = 6 UMETA(DisplayName = "Teleport"),
	CC_AddItem = 7 UMETA(DisplayName = "AddItem")
};

