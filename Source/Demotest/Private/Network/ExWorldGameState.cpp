// Fill out your copyright notice in the Description page of Project Settings.


#include "ExWorldGameState.h"
#include "GameFramework/Actor.h"
#include "Public/EXWorldCombatPlayerState.h"
#include "GameFramework/PlayerState.h"
#include "EXWorldCombat/Public/Core/EXWCharacter.h"



DEFINE_LOG_CATEGORY(EXWGSLog);

void AExWorldGameState::SetPlayerData(FString PlayerId, FEXWCharacterInfoLoadData_S CharData)
{
	if (!this)
	{
		return;
	}
		UE_LOG(LogTemp, Warning, TEXT("<GState> player id to find : %s"), *PlayerId);
		for (auto& obj : PlayerArray)
		{
			if (Cast<AEXWorldCombatPlayerState>(obj)->FEXWPlayerID.Equals(PlayerId))
			{
				Cast<AEXWorldCombatPlayerState>(obj)->SetLoadedPlayerData(CharData);

				AddPartyDetailsToPlayerArray(Cast<AEXWorldCombatPlayerState>(obj));
				break;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("<GState> loop player id : %s"), *Cast<AEXWorldCombatPlayerState>(obj)->FEXWPlayerID);
			}
		}
	
}

void AExWorldGameState::AddPartyDetailsToPlayerArray(AEXWorldCombatPlayerState* PlayerState)
{
	//FEXWPartyMember_Info NewPlayerInfo;
	//NewPlayerInfo.PlayerID = Cast<AEXWorldCombatPlayerState>(PlayerState)->PlayerId;
	//if (PlayerState)
	//{
	//	NewPlayerInfo.PlayerState = (PlayerState);	
	//	//NewPlayerInfo.PlayerName= Cast<AEXWCharacter>(PlayerState->GetPawn())->Name;
	//	PlayerParty_Info.AddUnique(NewPlayerInfo);
	//}
}

void AExWorldGameState::AddPlayerState(APlayerState* PlayerState)
{
	Super::AddPlayerState(PlayerState);
}

void AExWorldGameState::RemovePlayerState(APlayerState* PlayerState)
{
	Super::RemovePlayerState(PlayerState);

	//FEXWPartyMember_Info NewPlayerInfo;
	//NewPlayerInfo.PlayerID = PlayerState->PlayerId;
	//PlayerParty_Info.Remove(NewPlayerInfo);
}

void AExWorldGameState::CreateParty(FName PartyID, FText PartyName, AEXWCharacter* PartyAdmin, TArray<AEXWCharacter*> PartyMembers)
{
	if (!HasAuthority())
	{
		return;
	}
	// first check if partyID is already there
	FEXWParty oldParty = GetParty(PartyID);
	if (oldParty.ID != "-1")
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party already exists: <%s>"), *oldParty.ID.ToString());
		return;
	}
	if (PartyAdmin == nullptr)
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party Admin is nullptr, exiting..."));
		return;
	}

	if (PartyMembers.Num() == 0)
	{
		PartyMembers = TArray<AEXWCharacter*>();
	}
	//Remove Party Admin from Party Members
	PartyMembers.Remove(PartyAdmin);

	//Generate list of party members.
	TArray<FEXWPartyMember> PMembers;

	FEXWPartyMember PartyAdminMember = FEXWPartyMember(EEXWPartyMemberRoles::PMR_Admin, PartyAdmin, Cast<AEXWorldCombatPlayerState>(PartyAdmin->GetPlayerState()));
	PMembers.Add(PartyAdminMember);

	FEXWParty Party = FEXWParty(PartyID, PartyName, PMembers);

	ActiveParties.Add(Party);

	//Set Admin's Current Party
	PartyAdmin->GetPlayerState<AEXWorldCombatPlayerState>()->SetCurrentParty(Party);

	//Invite Party Members
	for (AEXWCharacter* Member : PartyMembers)
	{
		InviteToParty(Party, Member->Name);
	}

	UE_LOG(EXWGSLog, Display, TEXT("Party Created: <%s>"), *Party.ID.ToString());

}


void AExWorldGameState::RemoveParty(FEXWParty Party, AEXWCharacter* LeaderCharacter)
{
	if (!HasAuthority())
	{
		return;
	}

	if (Party.ID == "-1")
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party is Undefined, exiting..."));
		return;
	}

	if (LeaderCharacter == nullptr)
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party Admin is nullptr, exiting..."));
		return;
	}

	if (GetPartyLeader(Party) != LeaderCharacter)
	{
		UE_LOG(EXWGSLog, Warning, TEXT("Not Party Leader!"));
		return;
	}

	TArray<FEXWPartyMember> PartyMembers = Party.Members;

	ActiveParties.Remove(Party);

	// Kick everyone from the party
	for (FEXWPartyMember Member : PartyMembers)
	{
		AEXWCharacter* Character = Member.Character;

		//Set Current Party ID for each Character Player in State
		Character->GetPlayerState<AEXWorldCombatPlayerState>()->SetCurrentParty(FEXWParty());

		// Enable Friendly Fire
		Character->Client_SetTargetFaction(Character, Character->Faction);
	}
}

void AExWorldGameState::InviteToParty(FEXWParty Party, FText CharacterName)
{
	if (!HasAuthority())
	{
		return;
	}

	if (Party.ID == "-1")
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party is Undefined, exiting..."));
		return;
	}

	//First validate if we can invite more members to the party
	if (Party.Members.Num() >= MaxPartyMembers)
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party has reached player limit"));
		return;
	}

	if (AEXWCharacter* Character = GetCharacterFromText(CharacterName)) {
		if (!Character->GetHasPartyInvite())
		{
			Character->GetPlayerState<AEXWorldCombatPlayerState>()->OnReceiveInvitation(Party);
			Character->SetHasPartyInvite(true);
		}
	}
	else {
		UE_LOG(EXWGSLog, Error, TEXT("Character %s not found!"), *CharacterName.ToString());
	}
}


void AExWorldGameState::InviteToPartyCharacter(FEXWParty Party, AEXWCharacter* Character)
{
	if (!HasAuthority())
	{
		return;
	}

	if (Character)
	{
		if (!Character->GetHasPartyInvite())
		{
			Character->GetPlayerState<AEXWorldCombatPlayerState>()->OnReceiveInvitation(Party);
			Character->SetHasPartyInvite(true);
		}
	}
}

void AExWorldGameState::JoinParty(FEXWParty Party, AEXWCharacter* Character)
{
	if (!HasAuthority())
	{
		return;
	}

	//get updated party from admin just in case inveite ui had old party data  and other players already joined it
	FEXWParty refreshedParty;
	for (auto& obj : Party.Members)
	{
		if (obj.Role==EEXWPartyMemberRoles::PMR_Admin)
		{
			if(obj.PlayerState)
			{
				refreshedParty=obj.PlayerState->CurrentParty;
			}
		}
	}

	if (refreshedParty.ID == "-1")
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party is Undefined, exiting..."));
		return;
	}

	if (Character == nullptr)
	{
		UE_LOG(EXWGSLog, Error, TEXT("Passed Character Reference is a nullptr!"));
		return;
	}

	//First validate if we can add more members to the party
	if (refreshedParty.Members.Num() >= MaxPartyMembers)
	{
		Character->Client_CallOnRequestNotification(FText::FromString("Party is currently full"));
		UE_LOG(EXWGSLog, Error, TEXT("Party has reached player limit"));
		return;
	}

	FEXWPartyMember Member = FEXWPartyMember(Character, Cast<AEXWorldCombatPlayerState>(Character->GetPlayerState()));
	AEXWCharacter* PartyAdmin = GetPartyLeader(refreshedParty);

	FEXWParty AdminParty = PartyAdmin->GetPlayerState<AEXWorldCombatPlayerState>()->CurrentParty;
	AdminParty.Members.AddUnique(Member);
	
	Character->GetPlayerState<AEXWorldCombatPlayerState>()->SetCurrentParty(AdminParty);
		
	// Disable Friendly Fire
	PartyAdmin->Client_SetTargetFaction(Character, PartyAdmin->Faction);
	Character->Client_SetTargetFaction(PartyAdmin, Character->Faction);

	Client_SetPartyFaction(AdminParty, Character);

	UpdatePartyMembers(AdminParty);

	//Party Invite Tracker
	Character->SetHasPartyInvite(false);

	//notify members
	for (auto obj : AdminParty.Members)
	{
		if(obj.Character!=nullptr)
		{
			obj.Character->Client_CallOnRequestNotification(FText::FromString("<party>" + Character->Name.ToString()+" Joined the party <"+AdminParty.Name.ToString()+ "></>"));
		}
	}

	//->Client_CallOnRequestNotification(FText::FromString("<party>" + Character->Name.ToString()+"%s Joined the party <"+refreshedParty.Name.ToString()+ "></>"));
	//UE_LOG(EXWGSLog, Display, TEXT("%s Joined the party <%s>"), *Character->Name.ToString(), *refreshedParty.Name.ToString());


}

void AExWorldGameState::LeaveParty(FEXWParty Party, AEXWCharacter* Character)
{
	if (!HasAuthority())
	{
		return;
	}
	if (Party.ID == "-1")
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party is Undefined, exiting..."));
		return;
	}

	if (Character == nullptr)
	{
		UE_LOG(EXWGSLog, Error, TEXT("Passed Character Reference is a nullptr!"));
		return;
	}

	//first we check if its the leader
	FEXWPartyMember PartyMember = GetMemberFromCharacter(Party, Character);
	EEXWPartyMemberRoles MemberRole = PartyMember.Role;

	if (MemberRole == EEXWPartyMemberRoles::PMR_Admin)
	{
		//Promote someone else to be leader
		for (FEXWPartyMember& Member : Party.Members)
		{
			if (Member.Character != Character)
			{
				Member.Role = EEXWPartyMemberRoles::PMR_Admin;
				break;
			}
		}
	}

	//Now we remove it from the party
	Party.Members.Remove(PartyMember);

	// set the player state to not be in a party
	Character->GetPlayerState<AEXWorldCombatPlayerState>()->SetCurrentParty(FEXWParty());

	// Enable Friendly Fire
	Character->Client_SetTargetFaction(Character, Character->Faction);

	UpdatePartyMembers(Party);

	//notify members
	for (auto obj : Party.Members)
	{
		if(obj.Character!=nullptr)
		{
			obj.Character->Client_CallOnRequestNotification(FText::FromString("<party>" + Character->Name.ToString()+" Left the party <"+Party.Name.ToString()+ "></>"));
		}
	}

}

void AExWorldGameState::PromoteMember(FEXWParty Party, AEXWCharacter* LeaderCharacter, AEXWCharacter* CharacterToPromote)
{
	if (!HasAuthority())
	{
		return;
	}

	if (Party.ID == "-1")
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party is Undefined, exiting..."));
		return;
	}

	if (LeaderCharacter == nullptr)
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party Admin is nullptr, exiting..."));
		return;
	}

	if (CharacterToPromote == nullptr)
	{
		UE_LOG(EXWGSLog, Error, TEXT("Passed Character Reference is a nullptr!"));
		return;
	}

	if (GetPartyLeader(Party) != LeaderCharacter) {
		UE_LOG(EXWGSLog, Warning, TEXT("Player Character is not leader, unable to promote member"));
		return;
	}


	for (FEXWPartyMember& Member : Party.Members)
	{
		//First Demote current leader
		if (Member.Character == LeaderCharacter)
		{
			Member.Role = EEXWPartyMemberRoles::PMR_Member;
		}
		//Now we promote the new king
		if (Member.Character == CharacterToPromote)
		{
			Member.Role = EEXWPartyMemberRoles::PMR_Admin;
		}
	}
	UpdatePartyMembers(Party);

	//notify members
	for (auto obj : Party.Members)
	{
		if(obj.Character!=nullptr)
		{
			obj.Character->Client_CallOnRequestNotification(FText::FromString("<party>" + CharacterToPromote->Name.ToString()+" promoted to party admin <"+Party.Name.ToString()+ "></>"));
		}
	}
}

bool AExWorldGameState::KickMember(FEXWParty Party, AEXWCharacter* LeaderCharacter, AEXWCharacter* CharacterToKick)
{
	if (!HasAuthority())
	{
		return false;
	}
	if (Party.ID == "-1")
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party is Undefined, exiting..."));
		return false;
	}

	if (LeaderCharacter == nullptr)
	{
		UE_LOG(EXWGSLog, Error, TEXT("Party Admin is nullptr, exiting..."));
		return false;
	}

	if (CharacterToKick == nullptr)
	{
		UE_LOG(EXWGSLog, Error, TEXT("Passed Character Reference is a nullptr!"));
		return false;
	}

	if (GetPartyRole(Party, LeaderCharacter) != EEXWPartyMemberRoles::PMR_Admin) {
		UE_LOG(EXWGSLog, Warning, TEXT("Player Character is not leader, unable to kick member"));
		return false;
	}

	FEXWPartyMember Member = GetMemberFromCharacter(Party, CharacterToKick);
	Party.Members.Remove(Member);

	CharacterToKick->GetPlayerState<AEXWorldCombatPlayerState>()->SetCurrentParty(FEXWParty());

	// Enable Friendly Fire
	CharacterToKick->Client_SetTargetFaction(CharacterToKick, CharacterToKick->Faction);

	UpdatePartyMembers(Party);
	return true;
}

void AExWorldGameState::UpdatePartyMembers(FEXWParty Party)
{
	for (FEXWPartyMember Member : Party.Members)
	{
		Member.Character->GetPlayerState<AEXWorldCombatPlayerState>()->SetCurrentParty(Party);
	}
}

void AExWorldGameState::Client_SetPartyFaction_Implementation(FEXWParty Party, AEXWCharacter* Character)
{
	for (FEXWPartyMember Member : Party.Members)
	{
		Character->Client_SetTargetFaction(Member.Character, Character->Faction);
		Member.Character->Client_SetTargetFaction(Character, Member.Character->Faction);
	}
}

FEXWParty AExWorldGameState::FindParty(FText PartyName)
{
	//TODO Improve this to make it a search result instead of direct equal lookup
	for (FEXWParty Party : ActiveParties)
	{
		if (Party.Name.EqualTo(PartyName)) return Party;
	}
	return FEXWParty();
}

FEXWParty AExWorldGameState::GetParty(FName PartyID)
{
	for (FEXWParty Party : ActiveParties)
	{
		if (Party.ID.IsEqual(PartyID)) return Party;
	}

	return FEXWParty();
}

AEXWCharacter* AExWorldGameState::GetPartyLeader(FEXWParty Party)
{

	for (FEXWPartyMember Member : Party.Members)
	{
		if (Member.Role == EEXWPartyMemberRoles::PMR_Admin)
		{
			return Member.Character;
		}
	}

	return nullptr;
}

EEXWPartyMemberRoles AExWorldGameState::GetPartyRole(FEXWParty Party, AEXWCharacter* Character)
{
	return GetMemberFromCharacter(Party, Character).Role;
}

FEXWPartyMember AExWorldGameState::GetMemberFromCharacter(FEXWParty Party, AEXWCharacter* Character)
{

	for (FEXWPartyMember Member : Party.Members)
	{
		if (Member.Character == Character) return Member;
	}

	return FEXWPartyMember();
}

AEXWCharacter* AExWorldGameState::GetCharacterFromText(FText CharacterName)
{
	//TODO Rework this to something better, I don't know what or how but there must be something better :)
	for (APlayerState* PlayerState : this->PlayerArray)
	{
		if (AEXWCharacter* Character = PlayerState->GetPawn<AEXWCharacter>())
		{
			if (Character->Name.EqualTo(CharacterName)) return Character;
		}
	}
	return nullptr;
}
/**
 * Quests System
 */

void AExWorldGameState::Server_AddQuestToCharacter_Implementation(FEXWQuest Quest, AEXWCharacter* Character)
{
	AEXWorldCombatPlayerState* PlayerState = Character->GetPlayerState<AEXWorldCombatPlayerState>();
	/*FEXWQuests Quests = PlayerState->CurrentQuests;
	
	if (!Quests.ActiveQuests.Contains(Quest))
	{
		Quests.ActiveQuests.Add(Quest);

		PlayerState->SetCurrentQuests(Quests);
	}*/
}

void AExWorldGameState::Server_CompleteQuest_Implementation(FEXWQuest Quest, AEXWCharacter* Character)
{

}

void AExWorldGameState::Server_AbandonQuest_Implementation(FEXWQuest Quest, AEXWCharacter* Character)
{

}

