// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Library/Cloud/EXWCloudLibrary.h"
#include "Library/Inventory/EXWInventoryStruct.h"
#include "Http.h"
#include "Core/PlayFabError.h"
#include "Core/PlayFabSettings.h"
#include "PlayFab.h"
#include "ExWorldBlueprintFunctionLibrary.h"
#include "Library/EXWDataStruct.h"
#include "Library/Cloud/EXWCloudStruct.h"
#include "Network/ExWorldOnlineDatabase.h"
#include "PlayFabJsonObject.h"
#include "Core/PlayFabClientDataModels.h"
#include "Core/PlayFabGroupsAPI.h"
#include "EngineClasses/SpatialGameInstance.h"
#include "WebSocketsModule.h"
#include "IWebSocket.h"
#include "ExWorldBlueprintFunctionLibrary.h"
#include "ExWorldGameInstance.generated.h"


//For loading screen
//class FEWLoadingScreenSystem;

//For callbacks

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLoginResponse, FString, PlayerUniqueId, FString, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetDeploymentList, const TArray<FEXWDeploymentInfo>&, DeploymentList);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterCreateResponse, FString, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterDeleteResponse, FString, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGetSpatialTokensResponse, FString, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGuildCreated, FGuildInfo_S, GuildInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FExWorldPlayerInfo, FExWorldPlayerInfo_S, PlayerInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterCreationStats, FExWorldPlayerInfo_S, CreationInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetAllCharacters, const TArray<FEXWCharacterInfo_S>&, CharactersInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetAllCharacterData, FExWorldCharacterInfo_S, CharacterData);//characterdata delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetFriendRequest, const TArray<FString>&, FriendRequestName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetDisplayName, FString, PlayerDisplayName);

UCLASS()
class DEMOTEST_API UExWorldGameInstance : public USpatialGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UFUNCTION(BlueprintPure, Category = Loading)
	static bool IsInEditor();
	
	UFUNCTION(BlueprintCallable, Category="ExWorldInstance|Login|Socket")
	void ConnectWebSocket();

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login|Socket")
	bool IsWebSocketValid();

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void ProcessWSMessage(FString message);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void SavePlayerData(FString PlayerID, FString characterID, AEXWCharacter* Character);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void SendLoadPlayerDataRequest(int playerId, int characterID);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")//remove after launcher done
	void Login(FString Username, FString Password);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void GetDeploymentList();

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	bool IsValidDeploymentSelected();

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void GetSpatialTokens();

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void CreateCharacterOnline(FEXWCharacterCreation CharacterCreationData);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void GetAllPlayerCharacters();

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void DeleteCharacter(int Id);

	//----------------OLD Stuff need to go through----------------
	
	void CallExWorldApi();

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
		void SetLoginTicketsFromLauncher();

	UFUNCTION(BlueprintCallable,Category="ExWorldInstance|Friends")
	void AddOnlineFriend(FString DisplayName);

	UFUNCTION(BlueprintCallable,Category="ExWorldInstance|Guild")
	void CreateGuild(FString GuildName);


	UFUNCTION(BlueprintCallable,Category="ExWorldInstance|Login")
    void GetExWorldPlayerInfo(FString PlayerID);

	UFUNCTION(BlueprintCallable,Category="ExWorldInstance|Guild")
    void InviteToGuild(FString GuildId, FString PlayerEntityIdToAdd, ERoleType Role);


	
	UFUNCTION(BlueprintCallable, Category="ExWorldInstance|Friend")
	void CheckFriendRequest();

	UFUNCTION(BlueprintCallable, Category="ExWorldInstance|Friend")
    void CheckFriendRequest_Cloud(FString PlayerID);

	UFUNCTION(NetMulticast,Reliable,BlueprintCallable,Category="ExWorldInstance|Friend")
	void PushNotification_UI();

	UFUNCTION(BlueprintCallable,Category="ExWorldInstance|Party")
    void CreatePartyAndInvite(FString DisplayName);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Login")
	void GetPlayerInfo(FString DisplayName);


	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|CharacterData")
	void GetAllCharacterData(int CharIndex);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|CharacterData")
		void SetCharacter(int CharID);


	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Inventory")
		void UpdateInventoryOnPF(FEXWCharacterInventory_Info playerinventoryslots);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Inventory")
		void UpdateInventoryOnPlayFab(FEXWCharacterInventory_Info playerinventoryslots);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Stats")
		void UpdateStatsOnPlayFab(FEXWCharacterStat_Info playerStatData);

	UFUNCTION(BlueprintCallable, Category = "ExWorldInstance|Transform")
		void UpdateCharacterTransformOnPlayFab(FVector Location, FRotator Rotation);


	//delegates
	UPROPERTY(BlueprintAssignable, Category="ExWorldInstance")
	FGuildCreated OnGetGuildInfo;

	UPROPERTY(BlueprintAssignable, Category="ExWorldInstance|Login")
	FExWorldPlayerInfo OnGetExWorldPlayerInfo;

	UPROPERTY(BlueprintAssignable, Category="ExWorldInstance|Login")
	FOnLoginResponse OnLoginResponseEvent;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldInstance|Login")
	FOnGetDeploymentList OnGetDeploymentList;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldInstance|Login")
	FOnCharacterCreateResponse OnCharacterCreation;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldInstance|Login")
	FOnCharacterDeleteResponse OnCharacterDelete;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldInstance|Login")
	FOnGetSpatialTokensResponse OnGetSpatialTokensResponse;

	UPROPERTY(BlueprintAssignable, Category="ExWorldInstance|Login")
	FCharacterCreationStats OnGetCreationStats;

	UPROPERTY(BlueprintAssignable, Category="ExWorldInstance|Login")
	FGetAllCharacters OnGetAllCharacters;

	UPROPERTY(BlueprintAssignable, Category = "ExWorldInstance|Login")
	FGetAllCharacterData OnGetAllCharacterDataComplete;

	UPROPERTY(BlueprintAssignable, Category="ExWorldInstance|Friend")
	FGetFriendRequest OnGetFriendsRequest;

	UPROPERTY(BlueprintAssignable, Category="ExWorldInstance|Friend")
	FGetDisplayName OnGetDisplayName;


	//variables
	TSharedPtr<IWebSocket> Socket = nullptr;
	TSharedPtr<FEWLoadingScreenSystem> EWLoadingScreenSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExWorldInstance|Friend")
	bool DisplayPopUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExWorldInstance|Login")
	int32 PlayerSpawnIndex;

	UPROPERTY(EditAnywhere, Category="ExWorldInstance|Login")
	FExWorldPlayerInfo_S ExWorldPlayerInfo_S;              

	UPROPERTY(EditAnywhere, Category="ExWorldInstance|Guild")
	FGuildInfo_S ExWorldGuldInfo_S;

	UPROPERTY(EditAnywhere, Category="ExWorldInstance|Login")
	FString GlobalPlayerID;

	UPROPERTY(EditAnywhere, Category="ExWorldInstance|Login")
	FString GlobalFriendID;

	UPROPERTY(EditAnywhere, Category="ExWorldInstance|Login")
	FString GlobalFriendTitleID;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ExWorldInstance|Login")
	FString GlobalDisplayName;

	UPROPERTY(EditAnywhere, Category="ExWorldInstance|Guild")
	FPartyInfo_S ExWorldPartyInfo_S;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "ExWorldInstance|Login")
	FString CustomId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldInstance|Login")
	FString LoadedUsername;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldInstance|Login")
	FString Role;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldInstance|Login")
	FString SessionToken;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldInstance|Login")
	TArray<FEXWDeploymentInfo> AvailableDeployments;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldInstance|Login")
	FEXWDeploymentInfo SelectedDeploymentDetails;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldInstance|Character")
	int32 SelectedCharacterID = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldInstance|Login")
	TArray<FEXWCharacterInfo_S> CharactersInfoArray;


	UPROPERTY()
	UExWorldBlueprintFunctionLibrary* BlueprintFunctionLibrary;
	
	
	//Callbacks
	void OnLoginSuccess(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnGetDeploymentsResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnCharacterCreationResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnCharacterDeleteResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnGetSpatialTokens(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	void OnRequestSentSuccess(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
	void OnGuildCreated(const PlayFab::GroupsModels::FCreateGroupResponse& Response);
	void OnPartyCreated(const PlayFab::GroupsModels::FCreateGroupResponse& Response);
	void OnGuildInvitationSent(const PlayFab::GroupsModels::FInviteToGroupResponse& Response);
	void OnPartyMemberAdded(const PlayFab::GroupsModels::FInviteToGroupResponse& Response);
	void GetPlayerInfo_Cloud(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
	void OnDisplayNameUpdated(const PlayFab::ClientModels::FUpdateUserTitleDisplayNameResult& Result);
	void OnReceiveAccountInfo(const PlayFab::ClientModels::FGetAccountInfoResult& Result);
	void OnGetCharacterAttributes(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
	void OnGetFriendRequestList(const PlayFab::ClientModels::FGetFriendsListResult& Result);
	void OnGetAllPlayerCharacters(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful); //on recive character data from playfab
	void OnGetAllCharacterData(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
	void OnInventoryUpdated(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
	void OnStatsUpdated(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
	void OnTransformUpdated(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
	void OnGetFriendRequestList_Cloud(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
	void GetPlayerInventory_Cloud(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
	void OnError(const PlayFab::FPlayFabCppError& ErrorResult) const;                               //Mutual Callback
	void Test();                                                                                   // TODO Delete after use

	
	

	FTimerHandle Handle;

	//Broadcast the event
	
	void RequestPlayerInfo(FExWorldPlayerInfo_S PlayerInfo);
	void RequestGuildInfo(FGuildInfo_S GuildInfo);
	void UpdateDisplayName();
	void GetPlayerInventory();
	void GetPlayerStats();
	void GetUniqueIdentifier(FString FriendUniqueID);
	
	void DisplayPopUpOnScreen();
	FString RoleType(ERoleType Role);
	
	

protected:
	//Related to player info
	// TODO Make them local
	TSharedPtr<FJsonObject> HeadObject;
	TSharedPtr<FJsonObject> AccountInfoObject;
	TSharedPtr<FJsonObject> VirtualCurrencyObject;
	TSharedPtr<FJsonValue> FunctionResultValue;
	TSharedPtr<FJsonObject> TitleInfoObject;
	TSharedPtr<FJsonObject> PlayerDataObject;
	TSharedPtr<FJsonObject> DexterityObject;
	TSharedPtr<FJsonObject> EnduranceObject;
	TSharedPtr<FJsonObject> IntelligenceObject;
	TSharedPtr<FJsonObject> LuckObject;
	TSharedPtr<FJsonObject> StaminaObject;
	TSharedPtr<FJsonObject> StrengthObject;
	TSharedPtr<FJsonObject> RaceObject;
	TSharedPtr<FJsonObject> GenderObject;
	TSharedPtr<FJsonObject> HairObject;
	TSharedPtr<FJsonObject> FaceObject;
	TSharedPtr<FJsonObject> EyesObject;
	TSharedPtr<FJsonObject> BodyTypeObject;
	TSharedPtr<FJsonObject> SkinColorObject;
	TSharedPtr<FJsonObject> NameObject;
	TSharedPtr<FJsonObject> ClassObject;

private:
	PlayFabAdminPtr AdminAPI = nullptr;
	PlayFabClientPtr ClientAPI = nullptr;
	PlayFabGroupsPtr GroupAPI = nullptr;
	PlayFabClientPtr CheckAPI = nullptr;

	//URLS

	//editor

	//FString CharDataUrlAddress = "https://localhost:44320/CharacterData";
	//FString LoginUrlAddress = "https://localhost:44320/Login";
	//const FString WSServerURL = TEXT("ws://localhost:50540/ws");

	//FString CharDataUrlAddress = "http://localhost:5000/CharacterData";
	//FString LoginUrlAddress = "http://localhost:5000/Login";
	//const FString WSServerURL = TEXT("ws://localhost:5000/ws");

	//const FString WSServerURL = TEXT("wss://echo.websocket.org");

	//package
	
	FString CharDataUrlAddress = "https://api.zhousestudios.com/CharacterData";
	FString LoginUrlAddress = "https://api.zhousestudios.com/Login";
	const FString WSServerURL = TEXT("wss://api.zhousestudios.com/ws");

	//FString UrlAddress= "https://api.zhousestudios.com/CharacterData";

	const FString ServerProtocol = TEXT("ws");              // The WebServer protocol you want to use.
	

	bool bApiCallSuccessful;
	bool bAddFriend;
	
	//Loading Screen System
/*
	virtual void Init() override;
	virtual void Shutdown() override;*/

};


