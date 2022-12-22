// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Library/Cloud/EXWCloudStruct.h"
#include <EXWorldCombat/Public/Library/EXWDataStruct.h>
//#include <EXWorldCombat/Public/Party/Components/EXWPartyComponent.h>
#include "EXWorldCombatPlayerState.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(EXWPSLog, Log, All);

struct FEXWParty;
struct FEXWQuests;
class AEXWCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStatusEffectUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEXWorldCombatPlayerStateCurrentPartyUpdated, FEXWParty, Party);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveQuestsUpdated, TArray<FEXWQuest>, ActiveQuests);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFinishedQuestsUpdated, TArray<FName>, FinishedQuests);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestAdded, FEXWQuest, Quest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestCompleted, FEXWQuest, Quest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestObjectiveProgressed, FEXWQuest, Quest, FEXWQuestObjective, Objective);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuestObjectiveCompleted, FEXWQuest, Quest, FEXWQuestObjective, Objective);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestRewardsDistributed, FName, QuestID);


//DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEXWorldCombatPlayerStateQuestCompleted, FEXWQuest, Quest);

//class UEXWPartyComponent;
/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWorldCombatPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	AEXWorldCombatPlayerState();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void OnRep_PlayerId();

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnRep_CurrentParty();
	
	UFUNCTION()
	void OnRep_ActiveStatusEffects();

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void SetLoadedPlayerData(FEXWCharacterInfoLoadData_S CharData);

	UFUNCTION(BlueprintCallable, Category = "EXWPlayerState|PlayerData")
	void SetPlayerStateDataAndBinding();

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "ExWorldInstance|Login")
	void Client_BindDelegates();

	void SetCurrentParty(FEXWParty Party);

	UFUNCTION(BlueprintImplementableEvent, Category = "ExWorldPlayerState | Party")
	void OnReceiveInvitation(FEXWParty Party);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldInstance|Login")
	FString FEXWPlayerID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldInstance|Login")
	FString FEXWCharacterID;


	/**
	 * Character relevant replicated data
	 */
	UFUNCTION(BlueprintCallable, Category = "EXWPlayerState|PlayerData")
	void OnAttributeUpdate(EEXWAttributeType AttributeType, float Value);
	
	UFUNCTION(BlueprintCallable, Category = "EXWPlayerState|PlayerData")
	void OnStatusEffectsUpdate();

	UPROPERTY(Replicated, BlueprintReadOnly, EditAnywhere, Category = "EXWorld|PlayerState|CharacterData")
	FText Name = FText::FromString(FString("Character_Name"));

	UPROPERTY(Replicated, BlueprintReadOnly, EditAnywhere, Category = "EXWorld|PlayerState|CharacterData")
	EEXWRace Race;

	UPROPERTY(Replicated, BlueprintReadOnly, EditAnywhere, Category = "EXWorld|PlayerState|CharacterData")
	EEXWClass Class = EEXWClass::C_Other;

	UPROPERTY(Replicated, BlueprintReadOnly, EditAnywhere, Category = "EXWorld|PlayerState|CharacterData")
	int32  Faction;

	UPROPERTY(Replicated, BlueprintReadOnly, EditAnywhere, Category = "EXWorld|PlayerState|CharacterData")
	int32 ProgressionLevel = 1;

	UPROPERTY(Replicated, BlueprintReadOnly, EditAnywhere, Category = "EXWorld|PlayerState|CharacterData")
	EEXWAttributeType MainAttribute = EEXWAttributeType::Mana;

	UPROPERTY(Replicated, BlueprintReadOnly, EditAnywhere, Category = "EXWorld|PlayerState|CharacterData")
	TArray<FEXWAttribute> Attributes;

	UPROPERTY(ReplicatedUsing = OnRep_ActiveStatusEffects, BlueprintReadWrite, Category = "EXWorld|PlayerState|CharacterData")
	TArray<FEXWStatusEffectData> ActiveStatusEffects;

	//Party
	UPROPERTY(ReplicatedUsing=OnRep_CurrentParty, EditAnywhere, BlueprintReadOnly, Category = "ExWorldPlayerState | Party")
	FEXWParty CurrentParty;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldPlayerState | Party")
	FOnEXWorldCombatPlayerStateCurrentPartyUpdated OnCurrentPartyUpdated;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldPlayerState | CharacterData")
	FOnStatusEffectUpdated OnStatusEffectsUpdated;

	
	/**
	 * Quest System
	 */
	
	UFUNCTION()
	void OnRep_ActiveQuests(TArray<FEXWQuest> ActiveQuests);

	UFUNCTION()
	void OnRep_FinishedQuests(TArray<FName> FinishedQuests);

	UFUNCTION()
	bool IsQuestCompleted(FName QuestID);

	UFUNCTION()
	bool IsQuestActive(FName QuestID);

	UFUNCTION()
	bool IsValidQuest(FName QuestID);

	UFUNCTION()
	bool GetQuestByID(FName QuestID, FEXWQuest& OutQuest);

	UFUNCTION(BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	bool CanQuestBeAccepted(FName QuestID);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Server_AddQuest(FName QuestID);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Client_CallOnQuestAdded(FEXWQuest Quest);

	UFUNCTION(BlueprintImplementableEvent, Category = "ExWorldPlayerState | Quest")
	void CallOnQuestAdded(FEXWQuest Quest);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Server_CompleteQuest(FName QuestID);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Client_CallOnQuestCompleted(FEXWQuest Quest);

	UFUNCTION(BlueprintImplementableEvent, Category = "ExWorldPlayerState | Quest")
	void CallOnQuestCompleted(FName QuestID);

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Server_DistributeQuestRewards(FName QuestID);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Client_CallOnQuestRewardsDistributed(FName QuestID);

	UFUNCTION(BlueprintImplementableEvent, Category = "ExWorldPlayerState | Quest")
	void CallOnQuestRewardsDistributed(FName QuestID);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Client_CallOnQuestObjectiveProgressed(FEXWQuest Quest, FEXWQuestObjective Objective);

	UFUNCTION(BlueprintImplementableEvent, Category = "ExWorldPlayerState | Quest")
	void CallOnQuestObjectiveProgressed(FEXWQuest Quest, FEXWQuestObjective Objective);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Server_HandleObjectiveComplete(FEXWQuest Quest, FEXWQuestObjective Objective);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Client_CallOnObjectiveCompleted(FEXWQuest Quest, FEXWQuestObjective Objective);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "ExWorldPlayerState | Quest")
	void CallOnObjectiveCompleted(FEXWQuest Quest, FEXWQuestObjective Objective);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Server_HandleCharacterKill(AEXWCharacter* Victim);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Server_HandleCharacterInteract(AActor* TargetActor, EEXWInteractionType InteractionType);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "ExWorldPlayerState | Quest")
	void Server_HandleCharacterGatherComplete(FName ItemID, int32 ItemCount);

	
	UPROPERTY(ReplicatedUsing = OnRep_ActiveQuests, BlueprintReadOnly, Category = "ExWorldPlayerState | Quest")
	TArray<FEXWQuest> ActiveQuests;

	//TArray<FEXWQuestObjective> QuestsObjectives;

	UPROPERTY(ReplicatedUsing = OnRep_FinishedQuests, BlueprintReadOnly, Category = "ExWorldPlayerState | Quest")
	TArray<FName> FinishedQuests;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ExWorldPlayerState | Quest")
	int32 MaximumActiveQuests = 5;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldPlayerState | Quest")
	FOnActiveQuestsUpdated OnActiveQuestsUpdated;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldPlayerState | Quest")
	FOnFinishedQuestsUpdated OnFinishedQuestsUpdated;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldPlayerState | Quest")
	FOnQuestAdded OnQuestAdded;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldPlayerState | Quest")
	FOnQuestCompleted OnQuestCompleted;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldPlayerState | Quest")
	FOnQuestObjectiveProgressed OnQuestObjectiveProgressed;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldPlayerState | Quest")
	FOnQuestObjectiveCompleted OnQuestObjectiveCompleted;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldPlayerState | Quest")
	FOnQuestRewardsDistributed OnQuestRewardsDistributed;

};