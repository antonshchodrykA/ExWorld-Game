// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <EXWorldCombat/Public/Library/Chat/ExwChatEnum.h>
#include "EXWChatStruct.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct FEXWChatMessage
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Chat")
		TEnumAsByte<EEXWChatChannel> Channel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Chat")
		FText CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Chat")
		FText Message;
};


USTRUCT(BlueprintType)
struct FEXWChatCommand
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Chat")
		TEnumAsByte<EEXWChatCommandType> Commands;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Chat")
		FString Shortcut;
};

USTRUCT(BlueprintType)
struct FEXWChatChannelChannel
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Chat")
		EEXWChatChannel Channel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Chat")
		EEXWChannelVisibility ChannelVisibility;
};