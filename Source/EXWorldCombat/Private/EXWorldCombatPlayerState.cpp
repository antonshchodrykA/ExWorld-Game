// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWorldCombatPlayerState.h"
#include "GameFramework/Actor.h"
#include "Library/EXWDataLibrary.h"
#include "Library/EXWCharacterDataStruct.h"
#include "Core/EXWCharacter.h"
#include "ALSV4_CPP/Public/Character/ALSBaseCharacter.h"
#include "Demotest/Public/Network/ExWorldGameState.h"
#include <EXWorldCombat/Public/Library/Inventory/EXWInventoryLibrary.h>
#include <Runtime/Engine/Public/Net/UnrealNetwork.h>

DEFINE_LOG_CATEGORY(EXWPSLog);

AEXWorldCombatPlayerState::AEXWorldCombatPlayerState()
{
	
}

void AEXWorldCombatPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Character data
	DOREPLIFETIME(AEXWorldCombatPlayerState, Name);
	DOREPLIFETIME(AEXWorldCombatPlayerState, Race);
	DOREPLIFETIME(AEXWorldCombatPlayerState, Class);
	DOREPLIFETIME(AEXWorldCombatPlayerState, Faction);
	DOREPLIFETIME(AEXWorldCombatPlayerState, ProgressionLevel);
	DOREPLIFETIME(AEXWorldCombatPlayerState, MainAttribute);
	DOREPLIFETIME(AEXWorldCombatPlayerState, Attributes);
	DOREPLIFETIME(AEXWorldCombatPlayerState, ActiveStatusEffects);

	DOREPLIFETIME(AEXWorldCombatPlayerState, CurrentParty);
	DOREPLIFETIME(AEXWorldCombatPlayerState, ActiveQuests);
	DOREPLIFETIME(AEXWorldCombatPlayerState, FinishedQuests);
}

void AEXWorldCombatPlayerState::OnRep_PlayerId()
{
}

void AEXWorldCombatPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

void AEXWorldCombatPlayerState::OnRep_CurrentParty()
{
	OnCurrentPartyUpdated.Broadcast(CurrentParty);
}

void AEXWorldCombatPlayerState::OnRep_ActiveStatusEffects()
{
	OnStatusEffectsUpdated.Broadcast();
}

void AEXWorldCombatPlayerState::SetLoadedPlayerData(FEXWCharacterInfoLoadData_S CharData)
{

	/*TempSpawning*/
	if (!GetPawn())
	{
		UE_LOG(LogTemp, Warning, TEXT("<PlayerState> Pawn not valid") );
		return;
	}

	AEXWCharacter* ControlledPawn = Cast<AEXWCharacter>(GetPawn());

	UE_LOG(LogTemp, Warning, TEXT("<PlayerState> starting set loaded data"));
	//Set General Settings
	ControlledPawn->Name = FText::AsCultureInvariant(CharData.Name);
	ControlledPawn->Race = (EEXWRace)(StaticEnum<EEXWRace>()->UEnum::FindEnumIndex(FName(FString(TEXT("R_") + (CharData.Race)))));
	ControlledPawn->Class = (EEXWClass)(StaticEnum<EEXWClass>()->UEnum::FindEnumIndex(FName(FString(TEXT("C_") + (CharData.Class)))));
	if (ControlledPawn->Class == EEXWClass::C_Fighter)
		ControlledPawn->MainAttribute = EEXWAttributeType::Rage;
	ControlledPawn->ProgressionLevel = CharData.ProgressionLevel;

	//Set Appearance
	ControlledPawn->Gender = (EEXWGender)(StaticEnum<EEXWGender>()->UEnum::FindEnumIndex(FName(FString(TEXT("G_") + (CharData.Appearance.Gender)))));
	ControlledPawn->FaceName = FName(CharData.Appearance.Face);
	ControlledPawn->EyesName = FName(CharData.Appearance.Eyes);
	ControlledPawn->EyeColorName = FName(CharData.Appearance.EyeColor);
	ControlledPawn->HairName = FName(CharData.Appearance.Hair);
	ControlledPawn->HairColorName = FName(CharData.Appearance.HairColor);
	ControlledPawn->SkinName = FName(CharData.Appearance.SkinColor);

	//body base meshes
	UDataTable* RaceClassesDataDT;
	if (UEXWDataLibrary::GetRaceClassesDataDT(RaceClassesDataDT))
	{
		static const FString ContextString(TEXT("RaceClassesDataDT"));
		FEXWBaseSkeletalMeshes MeshNameList = UEXWDataLibrary::GetRaceBodyMeshData(RaceClassesDataDT->FindRow<FEXWClassRaces>(FName(CharData.Race), ContextString, true)->Classlist, ControlledPawn->Class, ControlledPawn->Gender);

		ControlledPawn->TorsoName = MeshNameList.Torso;
		ControlledPawn->HeadName = MeshNameList.Head;
		ControlledPawn->ArmsName = MeshNameList.Arms;
		ControlledPawn->BodyName = MeshNameList.Body;
		ControlledPawn->FaceName = MeshNameList.Face;
		ControlledPawn->FeetName = MeshNameList.Feet;
		ControlledPawn->LegsName = MeshNameList.Legs;

		UAnimMontage* DeathMontage;

		if (UEXWDataLibrary::GetDeathAnimationByRaceAndGender(DeathMontage, RaceClassesDataDT->FindRow<FEXWClassRaces>(FName(CharData.Race), ContextString, true)->Classlist, ControlledPawn->Class, ControlledPawn->Gender))
		{
			ControlledPawn->DeathMontage=DeathMontage;
		}

		//set inventory
		FEXWItemData ItemData;
		for (auto obj : CharData.Inventory.ItemSlots)
		{
			if (obj.RowName != "None")
			{
				ControlledPawn->Inventory.ItemSlots[obj.SlotID].ItemID = FName(*obj.RowName);
				ControlledPawn->Inventory.ItemSlots[obj.SlotID].Count = obj.Count;
			}
		}
		ControlledPawn->Inventory.CoinsGold=CharData.Inventory.CoinsGold;
		ControlledPawn->Inventory.CoinsSilver=CharData.Inventory.CoinsSilver;

		//set equipment
		for (auto obj : CharData.Equipment.ItemSlots)
		{
			if (obj.RowName != "None")
			{
				ControlledPawn->InventoryEquipment.ItemSlots[obj.SlotID].ItemID = FName(*obj.RowName);
				ControlledPawn->InventoryEquipment.ItemSlots[obj.SlotID].Count = 1;

				ControlledPawn->OnEquipItem_Native(FName(*obj.RowName));
			}
		}
		//set Cosmetics
		for (auto obj : CharData.Cosmetic.ItemSlots)
		{
			if (obj.RowName != "None")
			{
				ControlledPawn->InventoryCosmeticEquipment.ItemSlots[obj.SlotID].ItemID = FName(*obj.RowName);
				ControlledPawn->InventoryCosmeticEquipment.ItemSlots[obj.SlotID].Count = 1;

				ControlledPawn->OnEquipItem_Native(FName(*obj.RowName));
			}
		}

		ControlledPawn->LeftHandWeaponOffset = MeshNameList.LeftHandWeaponOffset;
		ControlledPawn->OnRep_LeftHandWeaponOffset();

		ControlledPawn->UpdateWeaponAttachmentSockets();

		//set IK values
		UDataTable* IKDT;
		UEXWDataLibrary::GetIKValueDT(IKDT);
		FDataTableRowHandle IKParams;
		IKParams.DataTable = IKDT;
		IKParams.RowName = FName(FString(CharData.Race) + (CharData.Appearance.Gender));
		Cast<AALSBaseCharacter>(ControlledPawn)->SetFootIKValueAdjustments(IKParams);

		//Set learned Actions
		TMap<FName, int32> ActionIDs;
		for (auto obj : CharData.ActiveAbilities.AbilitySlots)
		{
			ActionIDs.Add(FName(*obj.ActionID), obj.Level);
			//set level and slot numbers here 
			//obj.Level
			//obj.SlotID
		}

		ControlledPawn->ProgressionLevel = CharData.ProgressionLevel;
		ControlledPawn->ProgressionExperience = CharData.ProgressionExperience;

		//ControlledPawn->AvailableActions = UEXWDataLibrary::GetActions(ActionIDs);
		//ControlledPawn->AvailableActions = UEXWDataLibrary::GetDefaultActionsByRaceAndClass(ControlledPawn->Race, ControlledPawn->Class);
		ControlledPawn->SetActiveAbilities(UEXWDataLibrary::GetDefaultActionsByRaceAndClass(ControlledPawn->Race, ControlledPawn->Class));
		ControlledPawn->SetIFrameActions(UEXWDataLibrary::GetDefaultIFrameActionsByRaceAndClass(ControlledPawn->Race, ControlledPawn->Class));

		for (FEXWAction Ability : UEXWDataLibrary::GetActions(ActionIDs))
		{
			ControlledPawn->AddAbility(Ability);
		}
		
		ControlledPawn->AbilityPoints = CharData.ActiveAbilities.UnspentPoints;

		ControlledPawn->SetCanUseTargeting(UEXWDataLibrary::GetDefaultTargetingByRaceAndClass(ControlledPawn->Race, ControlledPawn->Class));


	}
	Client_BindDelegates();
	UE_LOG(LogTemp, Warning, TEXT("<PlayerState> Data load done"));

	ControlledPawn->InitializeCharacterData();
	UE_LOG(LogTemp, Warning, TEXT("<PlayerState> initialized"));

	ControlledPawn->SetActorHiddenInGame(false);
	ControlledPawn->OnCharacterDataLoaded();

	SetPlayerStateDataAndBinding();
	UE_LOG(LogTemp, Warning, TEXT("<PlayerState> bp loaded event called"));

}

void AEXWorldCombatPlayerState::SetPlayerStateDataAndBinding()
{
	AEXWCharacter* ControlledPawn = Cast<AEXWCharacter>(GetPawn());
	Name = ControlledPawn->Name;
	Race = ControlledPawn->Race;
	Class = ControlledPawn->Class;
	Faction = ControlledPawn->Faction;
	ProgressionLevel = ControlledPawn->ProgressionLevel;
	MainAttribute = ControlledPawn->MainAttribute;
	Attributes = ControlledPawn->Attributes;
	ActiveStatusEffects = ControlledPawn->ActiveStatusEffects;

	ControlledPawn->OnAttributeGained.AddDynamic(this, &AEXWorldCombatPlayerState::OnAttributeUpdate);
	ControlledPawn->OnAttributeLost.AddDynamic(this, &AEXWorldCombatPlayerState::OnAttributeUpdate);
	ControlledPawn->OnActiveStatusEffectsUpdated.AddDynamic(this, &AEXWorldCombatPlayerState::OnStatusEffectsUpdate);
}

void AEXWorldCombatPlayerState::Client_BindDelegates_Implementation()
{
	if (AEXWCharacter* Character = GetPawn<AEXWCharacter>())
	{
		Character->OnCharacterKill.AddDynamic(this, &AEXWorldCombatPlayerState::Server_HandleCharacterKill);
		Character->OnInteract.AddDynamic(this, &AEXWorldCombatPlayerState::Server_HandleCharacterInteract);
		Character->OnCharacterGatherComplete.AddDynamic(this, &AEXWorldCombatPlayerState::Server_HandleCharacterGatherComplete);
	}
	
}

void AEXWorldCombatPlayerState::SetCurrentParty(FEXWParty Party)
{
	if (this!=nullptr)
	{	
		if (HasAuthority()) {
			CurrentParty = Party;
		}
	}
}

void AEXWorldCombatPlayerState::OnAttributeUpdate(EEXWAttributeType AttributeType, float Value)
{
	if ((CurrentParty.Members.Num()>0) && (AttributeType == EEXWAttributeType::Health || AttributeType == MainAttribute))
	{
		//if(AEXWCharacter* Character = GetPawn<AEXWCharacter>())
		//{
		//	for (auto obj : CurrentParty.Members)
		//	{
		//		if (AEXWorldCombatPlayerState* PartymemberPlayerState = Cast<AEXWorldCombatPlayerState>(obj.Character->GetPlayerState()))
		//		{
		//			PartymemberPlayerState->Attributes=
		//		}
		//	
		//	}
		//}
		Attributes = GetPawn<AEXWCharacter>()->Attributes;
	}
}

void AEXWorldCombatPlayerState::OnStatusEffectsUpdate()
{
	ActiveStatusEffects= GetPawn<AEXWCharacter>()->ActiveStatusEffects;
	OnStatusEffectsUpdated.Broadcast();
}

void AEXWorldCombatPlayerState::OnRep_ActiveQuests(TArray<FEXWQuest> ActiveQuests)
{
	OnActiveQuestsUpdated.Broadcast(ActiveQuests);
}

void AEXWorldCombatPlayerState::OnRep_FinishedQuests(TArray<FName> FinishedQuests)
{
	OnFinishedQuestsUpdated.Broadcast(FinishedQuests);
}

/**
 * Quests System
 */
 
bool AEXWorldCombatPlayerState::IsQuestCompleted(FName QuestID)
{
	return FinishedQuests.Contains(QuestID);
}

bool AEXWorldCombatPlayerState::IsQuestActive(FName QuestID)
{
	FEXWQuest Quest = UEXWDataLibrary::GetQuestByID(QuestID);
	return ActiveQuests.Contains(Quest);
}

bool AEXWorldCombatPlayerState::IsValidQuest(FName QuestID)
{
	FEXWQuest Quest = UEXWDataLibrary::GetQuestByID(QuestID);

	return Quest.ID != "None" && Quest.Objectives.Num() > 0;
}

bool AEXWorldCombatPlayerState::GetQuestByID(FName QuestID, FEXWQuest& OutQuest)
{
	for (FEXWQuest& ActiveQuest : ActiveQuests)
	{
		if (ActiveQuest.ID == QuestID)
		{
			OutQuest = ActiveQuest;
			return true;
		}
	}
	return false;
}

bool AEXWorldCombatPlayerState::CanQuestBeAccepted(FName QuestID)
{
	if (HasAuthority())
	{
		return !IsQuestCompleted(QuestID) && !IsQuestActive(QuestID) && IsValidQuest(QuestID) && ActiveQuests.Num() <= MaximumActiveQuests;
	}
	return false;
}

void AEXWorldCombatPlayerState::Server_AddQuest_Implementation(FName QuestID)
{
	if (CanQuestBeAccepted(QuestID))
	{
		FEXWQuest Quest = UEXWDataLibrary::GetQuestByID(QuestID);
		ActiveQuests.AddUnique(Quest);

		//SaveQuests()

		Client_CallOnQuestAdded(Quest);

	}
	else {
		UE_LOG(EXWPSLog, Error, TEXT("Quest Can't be Accepted"));
	}

}

void AEXWorldCombatPlayerState::Client_CallOnQuestAdded_Implementation(FEXWQuest Quest)
{
	OnQuestAdded.Broadcast(Quest);

	CallOnQuestAdded(Quest);
}

void AEXWorldCombatPlayerState::Server_CompleteQuest_Implementation(FName QuestID)
{
	//UE_LOG(EXWPSLog, Error, TEXT("CompleteQuest - Start"));
	FEXWQuest Quest;
	if (GetQuestByID(QuestID, Quest))
	{
		//UE_LOG(EXWPSLog, Error, TEXT("CompleteQuest - Get Quest"));
		if (Quest.HasFinishedObjectives()) {
			//UE_LOG(EXWPSLog, Error, TEXT("CompleteQuest - Check Finished Objectives == true"));
			ActiveQuests.Remove(Quest);
			FinishedQuests.Add(QuestID);
			Server_DistributeQuestRewards(QuestID);
			Client_CallOnQuestCompleted(Quest);
		}
	}
}

bool AEXWorldCombatPlayerState::Server_CompleteQuest_Validate(FName QuestID)
{
	//TODO : Validate that the player completed the quest
	if (!IsValidQuest(QuestID))
	{
		return false;
	}
	
	if (IsQuestCompleted(QuestID))
	{
		return false;
	}

	if (!IsQuestActive(QuestID))
	{
		return false;
	}
	return true;
}

void AEXWorldCombatPlayerState::Client_CallOnQuestCompleted_Implementation(FEXWQuest Quest)
{
	OnQuestCompleted.Broadcast(Quest); 
}


void AEXWorldCombatPlayerState::Server_DistributeQuestRewards_Implementation(FName QuestID)
{
	if (AEXWCharacter* Character = GetPawn<AEXWCharacter>())
	{
		FEXWQuest Quest = UEXWDataLibrary::GetQuestByID(QuestID);
		if (Quest.Rewards.Num() > 0)
		{
			for (FEXWQuestReward Reward : Quest.Rewards)
			{
				switch (Reward.Type)
				{
				case EEXWQuestRewardType::QRT_Experience:
					Character->GainExperience(Reward.Quantity);
					break;
				case EEXWQuestRewardType::QRT_Gold:
					Character->Server_GainGold(Reward.Quantity);
					break;
				case EEXWQuestRewardType::QRT_Silver:
					Character->Server_GainSilver(Reward.Quantity);
					break;
				case EEXWQuestRewardType::QRT_Item:
					Character->Server_AddItemsToInventory(Reward.Item, Reward.Quantity);
					break;
				default:
					break;
				}
			}
		}
		Client_CallOnQuestRewardsDistributed(QuestID);
		CallOnQuestRewardsDistributed(QuestID);
	}

}

bool AEXWorldCombatPlayerState::Server_DistributeQuestRewards_Validate(FName QuestID)
{
	//TODO validate stuff here
	if (!FinishedQuests.Contains(QuestID))
	{
		return false;
	}
	return true;
}

void AEXWorldCombatPlayerState::Client_CallOnQuestRewardsDistributed_Implementation(FName QuestID)
{
	OnQuestRewardsDistributed.Broadcast(QuestID);
}

void AEXWorldCombatPlayerState::Client_CallOnQuestObjectiveProgressed_Implementation(FEXWQuest Quest, FEXWQuestObjective Objective)
{
	OnQuestObjectiveProgressed.Broadcast(Quest, Objective);
}

void AEXWorldCombatPlayerState::Server_HandleObjectiveComplete_Implementation(FEXWQuest Quest, FEXWQuestObjective Objective)
{
	Server_CompleteQuest(Quest.ID);
	Client_CallOnObjectiveCompleted(Quest, Objective);
	CallOnObjectiveCompleted(Quest, Objective);
}

void AEXWorldCombatPlayerState::Client_CallOnObjectiveCompleted_Implementation(FEXWQuest Quest, FEXWQuestObjective Objective)
{
	OnQuestObjectiveCompleted.Broadcast(Quest, Objective);
}


void AEXWorldCombatPlayerState::Server_HandleCharacterKill_Implementation(AEXWCharacter* Victim)
{
	if (AEXWCharacter* TargetCharacter = Cast<AEXWCharacter>(Victim))
	{
		//We can't use For-Ranged Loop as it is not allowed to modify it  during iteration
		for (int32 i = 0; i < ActiveQuests.Num(); i++)
		{
			FEXWQuest& ActiveQuest = ActiveQuests[i];

			for (int32 j = 0; j < ActiveQuest.Objectives.Num(); j++)
			{
				FEXWQuestObjective& Objective = ActiveQuest.Objectives[j];
				if (Objective.Type == EEXWQuestObjectiveType::QOT_Hunt)
				{
					if (Objective.ObjectiveClass == Victim->GetClass())
					{
						Objective.ProgressObjective(1);
						if (Objective.bIsCompleted)
						{
							Server_HandleObjectiveComplete(ActiveQuest, Objective);
						}
						else {
							Client_CallOnQuestObjectiveProgressed(ActiveQuest, Objective);
						}
					}
				}
			}
		}
	}
}

void AEXWorldCombatPlayerState::Server_HandleCharacterInteract_Implementation(AActor* TargetActor, EEXWInteractionType InteractionType)
{
	if (InteractionType == EEXWInteractionType::IT_Talk)
	{
		if (AEXWCharacter* TargetCharacter = Cast<AEXWCharacter>(TargetActor))
		{
			//We can't use For-Ranged Loop as it is not allowed to modify it  during iteration
			for (int32 i = 0; i < ActiveQuests.Num(); i++)
			{
				FEXWQuest& ActiveQuest = ActiveQuests[i];

				for (int32 j = 0; j < ActiveQuest.Objectives.Num(); j++)
				{
					FEXWQuestObjective& Objective = ActiveQuest.Objectives[j];
					if (Objective.Type == EEXWQuestObjectiveType::QOT_Talk)
					{
						if (Objective.GoalName.EqualTo(TargetCharacter->Name))
						{
							Objective.SetCompleted();
							Server_HandleObjectiveComplete(ActiveQuest, Objective);
						}
					}
				}
			}
			
		}
	}
}

void AEXWorldCombatPlayerState::Server_HandleCharacterGatherComplete_Implementation(FName ItemID, int32 ItemCount)
{
	//We can't use For-Ranged Loop as it is not allowed to modify it  during iteration
	for (int32 i = 0; i < ActiveQuests.Num(); i++)
	{
		FEXWQuest& ActiveQuest = ActiveQuests[i];

		for (int32 j = 0; j < ActiveQuest.Objectives.Num(); j++)
		{
			FEXWQuestObjective& Objective = ActiveQuest.Objectives[j];
			if (Objective.Type == EEXWQuestObjectiveType::QOT_Gather)
			{
				if (Objective.GoalName.EqualTo(FText::FromName(ItemID)))
				{
					Objective.ProgressObjective(ItemCount);
					if (Objective.bIsCompleted)
					{
						Server_HandleObjectiveComplete(ActiveQuest, Objective);
					}
					else {
						Client_CallOnQuestObjectiveProgressed(ActiveQuest, Objective);
					}
				}
			}
		}
	}
}

