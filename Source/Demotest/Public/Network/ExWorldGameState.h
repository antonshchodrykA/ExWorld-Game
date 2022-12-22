// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Library/Cloud/EXWCloudStruct.h"
//#include "EXWorldCombat/Public/Library/Party/EXWPartyStruct.h"
#include <EXWorldCombat/Public/Library/EXWDataStruct.h>

#include "ExWorldGameState.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(EXWGSLog, Log, All);

/**
 * 
 */
UCLASS()
class DEMOTEST_API AExWorldGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|DATA")
	void SetPlayerData(FString PlayerId, FEXWCharacterInfoLoadData_S CharData);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|DATA")
	void AddPartyDetailsToPlayerArray(AEXWorldCombatPlayerState* PlayerState);

	virtual void AddPlayerState(APlayerState* PlayerState);

	virtual void RemovePlayerState(APlayerState* PlayerState);

	//variables
	//UPROPERTY(Transient, BlueprintReadOnly, Category = GameState)
	//	TMap<FString, AEXWorldCombatPlayerState*> PlayerMap;

	/*UPROPERTY(Transient, BlueprintReadOnly, Category = "GameState")
	TArray<FEXWPartyMember_Info> PlayerParty_Info;*/

	//UPROPERTY(Transient, BlueprintReadOnly, Category = "GameState")
	//TArray<FEXWParty_Info> ActiveParties_Info;

	/**
	 * Party Implementation
	 */
	

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	void CreateParty(FName PartyID, FText PartyName, AEXWCharacter* PartyAdmin, TArray<AEXWCharacter*> PartyMembers);
	
	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	void RemoveParty(FEXWParty Party, AEXWCharacter* LeaderCharacter);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	void InviteToParty(FEXWParty Party, FText CharacterName);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	void InviteToPartyCharacter(FEXWParty Party, AEXWCharacter* Character);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	void JoinParty(FEXWParty Party, AEXWCharacter* Character);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	void LeaveParty(FEXWParty Party, AEXWCharacter* Character);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	void PromoteMember(FEXWParty Party, AEXWCharacter* LeaderCharacter, AEXWCharacter* CharacterToPromote);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	bool KickMember(FEXWParty Party, AEXWCharacter* LeaderCharacter, AEXWCharacter* CharacterToKick);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	void UpdatePartyMembers(FEXWParty Party);

	UFUNCTION(Client, Reliable, Category = "ExWorldGameState|Party")
	void Client_SetPartyFaction(FEXWParty Party, AEXWCharacter* Character);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	FEXWParty FindParty(FText PartyName);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	FEXWParty GetParty(FName PartyID);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	AEXWCharacter* GetPartyLeader(FEXWParty Party);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	EEXWPartyMemberRoles GetPartyRole(FEXWParty Party, AEXWCharacter* Character);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	FEXWPartyMember GetMemberFromCharacter(FEXWParty Party, AEXWCharacter* Character);

	UFUNCTION(BlueprintCallable, Category = "ExWorldGameState|Party")
	AEXWCharacter* GetCharacterFromText(FText CharacterName);

	UPROPERTY(BlueprintReadWrite, Category = "ExWorldGameState|Party")
	int32 MaxPartyMembers = 5;

	//UPROPERTY(Transient, BlueprintReadOnly, Category = "ExWorldGameState|Party")
	TArray<FEXWParty> ActiveParties;

	/**
	* Quest System
	*/
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "ExWorldGameState|Quest")
	void Server_AddQuestToCharacter(FEXWQuest Quest, AEXWCharacter* Character);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "ExWorldGameState|Quest")
	void Server_CompleteQuest(FEXWQuest Quest, AEXWCharacter* Character);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "ExWorldGameState|Quest")
	void Server_AbandonQuest(FEXWQuest Quest, AEXWCharacter* Character);

	
};
