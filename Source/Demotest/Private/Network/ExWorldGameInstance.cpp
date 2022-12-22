// Fill out your copyright notice in the Description page of Project Settings.


#include "Network/ExWorldGameInstance.h"
#include "ExWorldLog.h"
#include "Core/EXWPlayerController.h"
#include "Network/ExWorldGameState.h"
#include "Core/EXWCharacter.h"
#include "PlayFabClientDataModels.h"
#include "PlayFabCppBaseModel.h"
#include "PlayFabJsonObject.h"
#include "PlayFabJsonValue.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabGroupsAPI.h"
#include "PlayFabApiSettings.h"
#include <IPlayFab.h>
#include <Runtime/JsonUtilities/Public/JsonObjectConverter.h>
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "Library/EXWDataLibrary.h"

void UExWorldGameInstance::Init()
{
	Super::Init();
	if (IsDedicatedServerInstance())
	{	
	FWebSocketsModule& Module = FModuleManager::LoadModuleChecked<FWebSocketsModule>(TEXT("WebSockets"));
	ConnectWebSocket();
	}
	else
	{

	}
	//For Loading Screen Module
	//EWLoadingScreenSystem = MakeShareable(new FEWLoadingScreenSystem(this));
}


bool UExWorldGameInstance::IsInEditor()
{
	return GIsEditor;
}

void UExWorldGameInstance::ConnectWebSocket()
{
	Socket = FWebSocketsModule::Get().CreateWebSocket(WSServerURL, ServerProtocol);
	//FSocket::SetSendBufferSize
	//Socket-

	Socket->OnConnected().AddLambda([]() -> void {
		UE_LOG(LogTemp, Error, TEXT("Connected"));
	});

	Socket->OnConnectionError().AddLambda([](const FString& Error) -> void {
		UE_LOG(LogTemp, Warning, TEXT("Connection failed: %s"), *Error);
	});

	Socket->OnClosed().AddLambda([](int32 StatusCode, const FString& Reason, bool bWasClean) -> void {
		// This code will run when the connection to the server has been terminated.
		// Because of an error or a call to Socket->Close().
		UE_LOG(LogTemp, Error, TEXT("Connection Closed: %s"), *Reason);
	});

	Socket->OnMessage().AddLambda([&](const FString& Message) -> void {
		// This code will run when we receive a string message from the server.
		ProcessWSMessage(Message);
		UE_LOG(LogTemp, Error, TEXT("Message recieved: %s"), *Message);
	});

	Socket->OnRawMessage().AddLambda([](const void* Data, SIZE_T Size, SIZE_T BytesRemaining) -> void {
		// This code will run when we receive a raw (binary) message from the server.
		UE_LOG(LogTemp, Error, TEXT("Raw message: %s"), Data);
	});

	Socket->OnMessageSent().AddLambda([](const FString& MessageString) -> void {
		// This code is called after we sent a message to the server.
		UE_LOG(LogTemp, Error, TEXT("message sent: %s"), *MessageString);
	});


	// And we finally connect to the server. 
	Socket->Connect();
	Socket->Send("hello");

}

bool UExWorldGameInstance::IsWebSocketValid()
{
	if (Socket.IsValid() == true)
	{
		return true;
	}
	else
	{
		Socket->Connect();
		Socket->Send("Reconnect");
		return true;
	}
}

void UExWorldGameInstance::ProcessWSMessage(FString message)
{
	//Json String to Object
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(message);
	FJsonSerializer::Deserialize(JsonReader, JsonObject);

	UE_LOG(LogTemp, Warning, TEXT("In Process Message"));
	if (JsonObject->GetStringField("Function").Contains("LoadPlayerData"))
	{
		//convert Json data to character load data struct
		FEXWCharacterInfoLoadData_S CharData;
		FJsonObjectConverter::JsonObjectToUStruct(JsonObject->GetObjectField("Character").ToSharedRef(), &CharData, 0, 0);
		UE_LOG(LogTemp, Warning, TEXT("In Process Message Loadplayerdata Fname found"));
		if (this)
		{
			UE_LOG(LogTemp, Warning, TEXT("Server GI Valid"));
			AExWorldGameState* const MyGameState = GetWorld() != NULL ? GetWorld()->GetGameState<AExWorldGameState>() : NULL;
			MyGameState->SetPlayerData(JsonObject->GetStringField("PlayerID"), CharData);
		}
	}
}

void UExWorldGameInstance::SavePlayerData(FString PlayerID, FString characterID, AEXWCharacter *Character)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("Function", "SavePlayerData");
	JsonObject->SetNumberField("PlayerID", FCString::Atoi(*PlayerID));
	JsonObject->SetNumberField("CharacterID", FCString::Atoi(*characterID));

	FEXWCharacterInfoSaveData_S CharacterSaveData;
	CharacterSaveData.CharacterID =characterID;

	CharacterSaveData.Position.Location = Character->GetActorLocation().ToString();
	CharacterSaveData.Position.Rotation = Character->GetActorRotation().ToString();

	CharacterSaveData.ProgressionLevel = Character->ProgressionLevel;
	CharacterSaveData.ProgressionExperience = Character->ProgressionExperience;

	//inventory subobject//convert inventory to cloud struct
	FEXWInventorySlotItem_S CloudInventorySlotItem;
	for (int i=0;i< Character->Inventory.ItemSlots.Num();i++)
	{
		CloudInventorySlotItem.SlotID = i;
		CloudInventorySlotItem.RowName = Character->Inventory.ItemSlots[i].ItemID.ToString();
		CloudInventorySlotItem.Count = Character->Inventory.ItemSlots[i].Count;
		CharacterSaveData.Inventory.ItemSlots.Add(CloudInventorySlotItem);
	}
	CharacterSaveData.Inventory.CoinsGold= Character->Inventory.CoinsGold;
	CharacterSaveData.Inventory.CoinsSilver = Character->Inventory.CoinsSilver;
	CharacterSaveData.Inventory.Shards = Character->Inventory.Shards;


	//equipment subobject//convert equipment to cloud struct;
	for (int i = 0; i < Character->InventoryEquipment.ItemSlots.Num(); i++)
	{
		CloudInventorySlotItem.SlotID = i;
		CloudInventorySlotItem.RowName = Character->InventoryEquipment.ItemSlots[i].ItemID.ToString();
		CharacterSaveData.Equipment.ItemSlots.Add(CloudInventorySlotItem);
	}

	//Cosmetic subobject//convert equipment to cloud struct
	for (int i = 0; i < Character->InventoryCosmeticEquipment.ItemSlots.Num(); i++)
	{
		CloudInventorySlotItem.SlotID = i;
		CloudInventorySlotItem.RowName = Character->InventoryCosmeticEquipment.ItemSlots[i].ItemID.ToString();
		CharacterSaveData.Cosmetic.ItemSlots.Add(CloudInventorySlotItem);
	}

	CharacterSaveData.Stats.StatLevelPoints= Character->StatLevelPoints;
	CharacterSaveData.Stats.UnspentPoints = Character->UnspentLevelPoints;
	//CharacterSaveData.ActiveAbilities = Character->AvailableActions;
	
	//Ability subobject//convert Ability to cloud struct
	/*for (int i = 0; i < Character->AvailableActions.Num(); i++)
	{
		FEXWActiveAbilitySlot_Info_S AbilityCloudItem;
		AbilityCloudItem.SlotID = i;
		AbilityCloudItem.ActionID = Character->AvailableActions[i].ID.ToString();
		AbilityCloudItem.Level = Character->AvailableActions[i].Level;

		CharacterSaveData.ActiveAbilities.AbilitySlots.Add(AbilityCloudItem);
	}*/

	TArray<FEXWAction> DefaultActions = UEXWDataLibrary::GetDefaultActionsByRaceAndClass(Character->Race, Character->Class);
	for (FEXWAction Action : Character->AvailableActions)
	{
		if (DefaultActions.Contains(Action))
		{
			continue;
		}
		FEXWActiveAbilitySlot_Info_S AbilityCloudItem;

		AbilityCloudItem.SlotID = 0;
		AbilityCloudItem.ActionID = Action.ID.ToString();
		AbilityCloudItem.Level = Action.Level;

		CharacterSaveData.ActiveAbilities.AbilitySlots.Add(AbilityCloudItem);
	}

	CharacterSaveData.ActiveAbilities.UnspentPoints = Character->AbilityPoints;

	FString OutputString;
	FJsonObjectConverter::UStructToJsonObjectString(CharacterSaveData, OutputString);

	TSharedPtr<FJsonObject> JObject = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(OutputString);
	FJsonSerializer::Deserialize(JsonReader, JObject);

	//JsonObject->SetStringField("CharacterData", OutputString);
	JsonObject->SetObjectField("CharacterData", JObject);


	//OutputString;
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	//UE_LOG(LogTemp, Error, TEXT("Message Sending: %s"), *OutputString);


	if (IsWebSocketValid())
	{
		Socket->Send(OutputString);
	}
}


void UExWorldGameInstance::SendLoadPlayerDataRequest(int playerId,int characterID)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("Function", "LoadPlayerData");
	JsonObject->SetNumberField("PlayerID", playerId);
	JsonObject->SetNumberField("CharacterID", characterID);

	FString OutputString;
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	if (IsWebSocketValid())
	{
		Socket->Send(OutputString);
	}
	else
	{
		Socket->Connect();
		Socket->Send(OutputString);
	}
}

void UExWorldGameInstance::Login(FString Username,FString Password)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

	JsonObject->SetStringField("Type", "Login");
	JsonObject->SetStringField("Username", Username);
	JsonObject->SetStringField("Password", Password);

	//json object to string
	FString OutputString;
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	//http request
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetURL(*FString::Printf(TEXT("%s/GameLogin"), *LoginUrlAddress));
	HttpRequest->SetContentAsString(OutputString);
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UExWorldGameInstance::OnLoginSuccess);
	HttpRequest->ProcessRequest();
}

void UExWorldGameInstance::OnLoginSuccess(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response->GetContentType() == "application/json; charset=utf-8")
	{
		//Json String to Object
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
		FJsonSerializer::Deserialize(JsonReader, JsonObject);

		UE_LOG(LogTemp, Warning, TEXT("Login response : %s"), *Response->GetContentAsString());
		EXWORLDLOG("Success API Call to EXWorld");

		//set global variables
		SessionToken = JsonObject->GetStringField("loginToken");;
		CustomId = JsonObject->GetStringField("id");
		GlobalPlayerID = JsonObject->GetStringField("id");;
		LoadedUsername = JsonObject->GetStringField("userName");
		Role =JsonObject->GetStringField("AccountType");
	}
	else
	{
		//OnLoginResponseEvent.Broadcast(GlobalPlayerID, LoadedUsername);
	}
	OnLoginResponseEvent.Broadcast(GlobalPlayerID, *Response->GetContentAsString());
}


void UExWorldGameInstance::GetDeploymentList()
{
	//http request
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetURL(*FString::Printf(TEXT("%s/ListDeployments"), *CharDataUrlAddress));
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UExWorldGameInstance::OnGetDeploymentsResponse);
	HttpRequest->ProcessRequest();
}

bool UExWorldGameInstance::IsValidDeploymentSelected()
{
	return !SelectedDeploymentDetails.DeploymentId.IsEmpty();
}

void UExWorldGameInstance::OnGetDeploymentsResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful && Response->GetContentType() == "application/json; charset=utf-8")
	{
		//json String to Deployment struct
		FJsonObjectConverter::JsonArrayStringToUStruct(Response->GetContentAsString(), &AvailableDeployments, 0, 0);

		UE_LOG(LogTemp, Warning, TEXT("Deployments response : %s"), *Response->GetContentAsString());
		EXWORLDLOG("Success API Call to EXWorld");

		OnGetDeploymentList.Broadcast(AvailableDeployments);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Deployments response : %s"), *Response->GetContentAsString());
	}
}

void UExWorldGameInstance::GetSpatialTokens()
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField("Username", LoadedUsername);
	JsonObject->SetStringField("DeploymentID", SelectedDeploymentDetails.DeploymentId);

	//json object to string
	FString OutputString;
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	//http request
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetURL(*FString::Printf(TEXT("%s/SpatialTokens"), *CharDataUrlAddress));
	HttpRequest->SetContentAsString(OutputString);
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UExWorldGameInstance::OnGetSpatialTokens);
	HttpRequest->ProcessRequest();
}

void UExWorldGameInstance::OnGetSpatialTokens(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	UE_LOG(LogTemp, Warning, TEXT("Spatial Tokens response : %s"), *Response->GetContentAsString());

	if (bWasSuccessful && Response->GetContentType() == "application/json; charset=utf-8")
	{
		//json string to Tokens struct
		FEXWSpatialTokens Tokens;
		FJsonObjectConverter::JsonObjectStringToUStruct(Response->GetContentAsString(), &Tokens, 0, 0);

		UE_LOG(LogTemp, Warning, TEXT("Spatial Tokens response : %s"), *Response->GetContentAsString());

		//call join spatial deployment in the controller
		AEXWPlayerController* APC = Cast<AEXWPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		APC->JoinSpatialDeployment(Tokens.LT, Tokens.PIT);
		OnGetSpatialTokensResponse.Broadcast("Connecting");
	}
	else
		OnGetSpatialTokensResponse.Broadcast("Failed");
	
}

void UExWorldGameInstance::CreateCharacterOnline(FEXWCharacterCreation CharacterCreationData)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);

	//add values to main json object
	JsonObject->SetStringField("FEXWAccount_InfoId", GlobalPlayerID);
	JsonObject->SetStringField("ServerID", "Default");
	JsonObject->SetStringField("Name", CharacterCreationData.Name);
	JsonObject->SetStringField("Race", UEnum::GetDisplayValueAsText(CharacterCreationData.Race).ToString().Replace(TEXT("R_"), TEXT("")));
	JsonObject->SetStringField("Class", UEnum::GetDisplayValueAsText(CharacterCreationData.Class).ToString().Replace(TEXT("C_"), TEXT("")).Replace(TEXT(" "), TEXT("")));
	JsonObject->SetNumberField("ProgressionLevel", 1);

	//appearance json subobject
	TSharedPtr<FJsonObject> JOAppearance = MakeShareable(new FJsonObject);
	JOAppearance->SetStringField("Gender", UEnum::GetDisplayValueAsText(CharacterCreationData.Gender).ToString().Replace(TEXT("G_"), TEXT("")));
	JOAppearance->SetStringField("Hair", CharacterCreationData.Hair.ToString());
	JOAppearance->SetStringField("HairColor", CharacterCreationData.HairColor.ToString());
	JOAppearance->SetStringField("Face", CharacterCreationData.Face.ToString());
	JOAppearance->SetStringField("Eyes", CharacterCreationData.Eyes.ToString());
	JOAppearance->SetStringField("EyeColor", CharacterCreationData.EyeColor.ToString());
	JOAppearance->SetStringField("BodyType", CharacterCreationData.BodyType.ToString());
	JOAppearance->SetStringField("SkinColor", CharacterCreationData.SkinColor.ToString());

	JsonObject->SetObjectField("Appearance", JOAppearance);

	//stats json subobject
	TSharedPtr<FJsonObject> JOStats = MakeShareable(new FJsonObject);
	JOStats->SetNumberField("UnspentPoints", 0);

	for (auto obj : CharacterCreationData.StatLevelPoints)
	{
		JOStats->SetNumberField(*UEnum::GetDisplayValueAsText(obj.Key).ToString(), obj.Value);
	}
	JsonObject->SetObjectField("Stat", JOStats);

	//json object to json string//	//FJsonObjectConverter::UStructToJsonObjectString(CharacterCreationData, OutputString);
	FString OutputString;
	TSharedRef<TJsonWriter<TCHAR>> JsonWriter = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter);

	//http request
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("POST");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetURL(*FString::Printf(TEXT("%s/InsertCharacter"), *CharDataUrlAddress));
	HttpRequest->SetContentAsString(OutputString);
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UExWorldGameInstance::OnCharacterCreationResponse);
	HttpRequest->ProcessRequest();
}

void UExWorldGameInstance::OnCharacterCreationResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	OnCharacterCreation.Broadcast(*Response->GetContentAsString());
}

void UExWorldGameInstance::GetAllPlayerCharacters()
{
	//http request
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetURL(*FString::Printf(TEXT("%s/%s"), *CharDataUrlAddress, *GlobalPlayerID));
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UExWorldGameInstance::OnGetAllPlayerCharacters);
	HttpRequest->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Sending get characters request"));
}

void UExWorldGameInstance::OnGetAllPlayerCharacters(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	UE_LOG(LogTemp, Warning, TEXT("GetCharacters response : %s"), *Response->GetContentType());

	if (bWasSuccessful && Response->GetContentType() == "application/json; charset=utf-8")
	{
		//clear old character info array for new data
		CharactersInfoArray.Empty();

		//make Json object into json object
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Response->GetContentAsString());
		FJsonSerializer::Deserialize(JsonReader, JsonObject);
		UE_LOG(LogTemp, Warning, TEXT("Characters response : %s"), *Response->GetContentAsString());

		FJsonObjectConverter::JsonArrayStringToUStruct(Response->GetContentAsString(), &CharactersInfoArray, 0, 0);


		OnGetAllCharacters.Broadcast(CharactersInfoArray);
	}
	else
	{
	}
}

void UExWorldGameInstance::DeleteCharacter(int Id)
{
	//http request
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb("DELETE");
	HttpRequest->SetHeader("Content-Type", "application/json");
	HttpRequest->SetURL(*FString::Printf(TEXT("%s/%d"), *CharDataUrlAddress, Id));
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UExWorldGameInstance::OnCharacterDeleteResponse);
	HttpRequest->ProcessRequest();

	UE_LOG(LogTemp, Warning, TEXT("Sending get characters request"));
}

void UExWorldGameInstance::OnCharacterDeleteResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	//if (bWasSuccessful)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Char Deletion response : %s"), *Response->GetContentAsString());
	//}
	//else
	//{
	//}
	OnCharacterDelete.Broadcast(*Response->GetContentAsString());
}

//-------------------OLD/PLAYFAB/-----------------

void UExWorldGameInstance::CallExWorldApi()
{
}


void UExWorldGameInstance::SetLoginTicketsFromLauncher()
{
	//TODO @HT
}


void UExWorldGameInstance::UpdateDisplayName()
{
	ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	PlayFab::ClientModels::FUpdateUserTitleDisplayNameRequest request;
	request.DisplayName = CustomId;
	ClientAPI->UpdateUserTitleDisplayName(request,PlayFab::UPlayFabClientAPI::FUpdateUserTitleDisplayNameDelegate::CreateUObject(this, &UExWorldGameInstance::OnDisplayNameUpdated),
	PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
}

void UExWorldGameInstance::OnDisplayNameUpdated(const PlayFab::ClientModels::FUpdateUserTitleDisplayNameResult& Result)
{
	EXWORLDLOG_SW("Display Name Updated", Result.DisplayName)
	GlobalDisplayName = Result.DisplayName;
	bApiCallSuccessful = true;
	OnGetDisplayName.Broadcast(GlobalDisplayName);
	GetWorld()->GetTimerManager().SetTimer(Handle, [this]() {
		GetExWorldPlayerInfo(GlobalPlayerID);
        }, 5.0, false);
}

void UExWorldGameInstance::GetPlayerInventory()
{
	TSharedPtr<FJsonObject> PFJsonObject = MakeShareable(new FJsonObject);
	PFJsonObject->SetStringField("CatalogVersion","PlayerInventory");
	ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	PlayFab::ClientModels::FExecuteCloudScriptRequest request;
	request.FunctionName = TEXT("SetupPlayerInventory");
	request.FunctionParameter = PFJsonObject;
	ClientAPI->ExecuteCloudScript(request,
    PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &UExWorldGameInstance::GetPlayerInventory_Cloud),
    PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
}

void UExWorldGameInstance::GetPlayerStats()
{
	PlayerDataObject = HeadObject->GetObjectField("UserData");
	DexterityObject = PlayerDataObject->GetObjectField("Dexterity");
	ExWorldPlayerInfo_S.PlayerStats.Dexterity = DexterityObject->GetStringField("Value");
	EnduranceObject = PlayerDataObject->GetObjectField("Endurance");
	ExWorldPlayerInfo_S.PlayerStats.Endurance = EnduranceObject->GetStringField("Value");
	IntelligenceObject = PlayerDataObject->GetObjectField("Intelligence");
	ExWorldPlayerInfo_S.PlayerStats.Intelligence = IntelligenceObject->GetStringField("Value");
	LuckObject = PlayerDataObject->GetObjectField("Luck");
	ExWorldPlayerInfo_S.PlayerStats.Luck = LuckObject->GetStringField("Value");
	StaminaObject = PlayerDataObject->GetObjectField("Stamina");
	ExWorldPlayerInfo_S.PlayerStats.Stamina = StaminaObject->GetStringField("Value");
	StrengthObject = PlayerDataObject->GetObjectField("Strength");
	ExWorldPlayerInfo_S.PlayerStats.Strength = StrengthObject->GetStringField("Value");
}

void UExWorldGameInstance::GetPlayerInventory_Cloud(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result)
{
	if(Result.FunctionResult.notNull())
	{
		FunctionResultValue = Result.FunctionResult.GetJsonValue();
		HeadObject = FunctionResultValue->AsObject();
		auto Catalog = HeadObject->GetArrayField("Catalog");
		for (int32 i = 0; i < Catalog.Num(); i++)
		{
			HeadObject = Catalog[i]->AsObject();
			FString ItemName = HeadObject->GetStringField("DisplayName");
			ExWorldPlayerInfo_S.PlayerInventory.ItemName.Insert(ItemName,i);
		}
	}
}

void UExWorldGameInstance::GetExWorldPlayerInfo(FString PlayerID)
{
	TSharedPtr<FJsonObject> PFJsonObject = MakeShareable(new FJsonObject); //for safety check is valid TODO
	PFJsonObject->SetStringField("PlayFabId",PlayerID);
	ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	PlayFab::ClientModels::FExecuteCloudScriptRequest request;
	request.FunctionName = TEXT("GetLoggedInPlayerInfo");
	request.GeneratePlayStreamEvent = true;
	ClientAPI->ExecuteCloudScript(request,
    PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &UExWorldGameInstance::GetPlayerInfo_Cloud),
    PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
	
}

void UExWorldGameInstance::GetPlayerInfo_Cloud(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result)
{
	//GetPlayerInventory();
	//if(Result.FunctionResult.notNull())
	//{	 
	//	FunctionResultValue = Result.FunctionResult.GetJsonValue();
	//	HeadObject = FunctionResultValue->AsObject();
	//	ExWorldPlayerInfo_S.PlayerLoginInfo.PlayerUniqueId = HeadObject->GetStringField("PlayFabId");
	//	HeadObject = HeadObject->GetObjectField("InfoResultPayload");
	//	VirtualCurrencyObject = HeadObject->GetObjectField("UserVirtualCurrency");
	//	ExWorldPlayerInfo_S.PlayerLoginInfo.Currency.Gold = VirtualCurrencyObject->GetNumberField(TEXT("GL"));  //TODO Make a seperate fucntion
	//	ExWorldPlayerInfo_S.PlayerLoginInfo.Currency.Silver = VirtualCurrencyObject->GetNumberField(TEXT("SL"));
	//	AccountInfoObject = HeadObject->GetObjectField("AccountInfo");
	//	TitleInfoObject = AccountInfoObject->GetObjectField("TitleInfo");
	//	ExWorldPlayerInfo_S.PlayerLoginInfo.DisplayName = TitleInfoObject->GetStringField("DisplayName");
	//	ExWorldPlayerInfo_S.PlayerLoginInfo.LoginPlatform = TitleInfoObject->GetStringField("Origination");
	//	ExWorldPlayerInfo_S.PlayerLoginInfo.LastLogin = TitleInfoObject->GetStringField("LastLogin");
	//	ExWorldPlayerInfo_S.PlayerLoginInfo.IsBanned = TitleInfoObject->GetBoolField("isBanned");
	//	GetPlayerStats();
	//	GetWorld()->GetTimerManager().SetTimer(Handle, [this]() {
 //           RequestPlayerInfo(ExWorldPlayerInfo_S_D);
 //       }, 0.5, false);
	//
	//	EXWORLDLOG("Player info called IN ExWorldGameInstance.cpp")
	//}
}

void UExWorldGameInstance::RequestPlayerInfo(FExWorldPlayerInfo_S PlayerInfo)
{
	//TODO Brodcast not working in player controller base class - Fix working in Debug mode
	//TODO convert gold and silver into a struct name-> currency - Fix
	
	OnGetExWorldPlayerInfo.Broadcast(PlayerInfo);

}

void UExWorldGameInstance::GetPlayerInfo(FString DisplayName)
{
	bAddFriend = false;
	ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	PlayFab::ClientModels::FGetAccountInfoRequest request;
	request.TitleDisplayName = DisplayName;
	ClientAPI->GetAccountInfo(request,
	PlayFab::UPlayFabClientAPI::FGetAccountInfoDelegate::CreateUObject(this, &UExWorldGameInstance::OnReceiveAccountInfo),
	PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
}

void UExWorldGameInstance::AddOnlineFriend(FString DisplayName)
{	
	bAddFriend = true;
	ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	PlayFab::ClientModels::FGetAccountInfoRequest request;
	request.TitleDisplayName = DisplayName;
	ClientAPI->GetAccountInfo(request,
    PlayFab::UPlayFabClientAPI::FGetAccountInfoDelegate::CreateUObject(this, &UExWorldGameInstance::OnReceiveAccountInfo),
	PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
}

void UExWorldGameInstance::OnReceiveAccountInfo(const PlayFab::ClientModels::FGetAccountInfoResult& Result)
{
	FString FriendUniqueID = Result.AccountInfo->PlayFabId;
	GlobalFriendID = FriendUniqueID;
	GlobalFriendTitleID = Result.AccountInfo->TitleInfo->TitlePlayerAccount->Id;
	if (bAddFriend) {
		GetWorld()->GetTimerManager().SetTimer(Handle, [this, FriendUniqueID]() {
			GetUniqueIdentifier(FriendUniqueID);
			}, 0.5, false);
	}
	else if(!bAddFriend)
	{
		GroupAPI = IPlayFabModuleInterface::Get().GetGroupsAPI();
		PlayFab::GroupsModels::FCreateGroupRequest request;
		request.GroupName = FriendUniqueID;
		GroupAPI->CreateGroup(request,
		PlayFab::UPlayFabGroupsAPI::FCreateGroupDelegate::CreateUObject(this, &UExWorldGameInstance::OnPartyCreated),
		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
	}
}

void UExWorldGameInstance::GetUniqueIdentifier(FString FriendUniqueID)
{
	//TODO Replace it with cloud execution
	
	TSharedPtr<FJsonObject> PFJsonObject = MakeShareable(new FJsonObject); //for safety check is valid TODO
	PFJsonObject->SetStringField("FriendPlayFabId",FriendUniqueID);
	ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	PlayFab::ClientModels::FExecuteCloudScriptRequest request;
	request.FunctionName = TEXT("SendFriendRequest");
	request.FunctionParameter = PFJsonObject; //No need to convert json into string
	request.GeneratePlayStreamEvent = true;
	ClientAPI->ExecuteCloudScript(request,
    PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &UExWorldGameInstance::OnRequestSentSuccess),
	PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
}
void UExWorldGameInstance::OnRequestSentSuccess(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result)
{
	EXWORLDLOG("Friend Request Sent");
}

void UExWorldGameInstance::CheckFriendRequest_Cloud(FString PlayerID)
{
	const TSharedPtr<FJsonObject> PFJsonObject = MakeShareable(new FJsonObject); 
	ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	PlayFab::ClientModels::FExecuteCloudScriptRequest request;
	PFJsonObject->SetStringField("PlayFabId",PlayerID);
	request.FunctionName = TEXT("CheckFriendRequest");
	request.FunctionParameter = PFJsonObject; //No need to convert json into string
	request.GeneratePlayStreamEvent = true;
	ClientAPI->ExecuteCloudScript(request,
    PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &UExWorldGameInstance::OnGetFriendRequestList_Cloud),
    PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
}

void UExWorldGameInstance::CreatePartyAndInvite(FString DisplayName)
{
	GetPlayerInfo(DisplayName);
}

void UExWorldGameInstance::OnPartyCreated(const PlayFab::GroupsModels::FCreateGroupResponse& Response)
{
	EXWORLDLOG("Party Created")
	ExWorldPartyInfo_S.PartyName = Response.GroupName;
	ExWorldPartyInfo_S.PartyID = Response.Group.Id;
	ExWorldPartyInfo_S.PartyCreatedTime = Response.Created;
	ExWorldPartyInfo_S.PartyRoles = Response.Roles;
	GroupAPI = IPlayFabModuleInterface::Get().GetGroupsAPI();
	PlayFab::GroupsModels::FInviteToGroupRequest request;
	request.Group.Id = Response.Group.Id;
	request.RoleId = RoleType(ERoleType::PartyMembers);
	request.Entity.Id = GlobalFriendTitleID; //Add the ID
	request.Entity.Type = TEXT("title_player_account");
	GroupAPI->InviteToGroup(request,PlayFab::UPlayFabGroupsAPI::FInviteToGroupDelegate::CreateUObject(this,&UExWorldGameInstance::OnPartyMemberAdded),
        PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
}

void UExWorldGameInstance::OnPartyMemberAdded(const PlayFab::GroupsModels::FInviteToGroupResponse& Response)
{
	//Pop up 
	EXWORLDLOG("Party Member Created")
	//Response.InvitedByEntity->Key->Id;
}

void UExWorldGameInstance::OnGetFriendRequestList_Cloud(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result)
{
	FunctionResultValue = Result.FunctionResult.GetJsonValue();
	auto result = FunctionResultValue->AsArray();
	for (int32 i = 0; i < result.Num(); i++)
	{
		const TSharedPtr<FJsonValue> FriendListVal = result[i];
		const TSharedPtr<FJsonObject> FriendListObj = FriendListVal->AsObject();
		FString name = FriendListObj->GetStringField("TitleDisplayName");
		TArray<TSharedPtr<FJsonValue>> FriendTag = FriendListObj->GetArrayField("Tags");
		for (int32 j = 0; j < FriendTag.Num(); j++)
		{
			FString FriendTagVal = FriendTag[i]->AsString();
			DisplayPopUp=true;
		}
	}
}

void UExWorldGameInstance::CreateGuild(FString GuildName)
{
	//Group API not found on cloud - Fix
	GroupAPI = IPlayFabModuleInterface::Get().GetGroupsAPI();
	PlayFab::GroupsModels::FCreateGroupRequest request;
	request.GroupName = GuildName;
	GroupAPI->CreateGroup(request,
		PlayFab::UPlayFabGroupsAPI::FCreateGroupDelegate::CreateUObject(this, &UExWorldGameInstance::OnGuildCreated),
		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
}

void UExWorldGameInstance::OnGuildCreated(const PlayFab::GroupsModels::FCreateGroupResponse& Response)
{
	ExWorldGuldInfo_S.GuildName = Response.GroupName;
	ExWorldGuldInfo_S.GuildID = Response.Group.Id;
	ExWorldGuldInfo_S.GuildCreatedTime = Response.Created;
	ExWorldGuldInfo_S.GuildRoles = Response.Roles;
	ExWorldGuldInfo_S.AdminRoleId = Response.AdminRoleId;
	ExWorldGuldInfo_S.MemberRoleId = Response.MemberRoleId;
	GroupAPI = IPlayFabModuleInterface::Get().GetGroupsAPI();
	PlayFab::GroupsModels::FCreateGroupRoleRequest request;
	request.Group.Id = ExWorldGuldInfo_S.GuildID; 
	GetWorld()->GetTimerManager().SetTimer(Handle, [this]() {
        RequestGuildInfo(ExWorldGuldInfo_S);
    }, 0.5, false);
}

void UExWorldGameInstance::InviteToGuild(FString GuildId, FString PlayerEntityIdToAdd, ERoleType Role)
{
	GroupAPI = IPlayFabModuleInterface::Get().GetGroupsAPI();
	PlayFab::GroupsModels::FInviteToGroupRequest request;
	request.Group.Id = GuildId;
	request.RoleId = RoleType(Role);
	request.Entity.Id = PlayerEntityIdToAdd;
	request.Entity.Type = TEXT("title_player_account");
	GroupAPI->InviteToGroup(request,PlayFab::UPlayFabGroupsAPI::FInviteToGroupDelegate::CreateUObject(this,&UExWorldGameInstance::OnGuildInvitationSent),
		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
}




void UExWorldGameInstance::UpdateInventoryOnPF(FEXWCharacterInventory_Info playerinventoryslots)
{


}

void UExWorldGameInstance::UpdateInventoryOnPlayFab(FEXWCharacterInventory_Info playerinventoryslots)
{
}

void UExWorldGameInstance::CheckFriendRequest()
{
	if(bApiCallSuccessful)
	{
		CheckAPI = IPlayFabModuleInterface::Get().GetClientAPI();
		PlayFab::ClientModels::FGetFriendsListRequest request;
		request.ProfileConstraints = nullptr;
		CheckAPI->GetFriendsList(request,
        PlayFab::UPlayFabClientAPI::FGetFriendsListDelegate::CreateUObject(this, &UExWorldGameInstance::OnGetFriendRequestList),
        PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
	}
}

void UExWorldGameInstance::OnGetFriendRequestList(const PlayFab::ClientModels::FGetFriendsListResult& Result)
{
	EXWORLDLOG("Get the friends list")
    TArray<PlayFab::ClientModels::FFriendInfo> FriendRequests = Result.Friends;
	TArray<FString>FriendRequestNames;
	for (int32 i = 0; i<FriendRequests.Num();i++)
	{
		if (FriendRequests[i].Tags[0] == "client")
		{
			FriendRequestNames.Add(FriendRequests[i].TitleDisplayName);
			//PushNotification_UI();
			DisplayPopUp=true;
		}
	}
	OnGetFriendsRequest.Broadcast(FriendRequestNames);
}

void UExWorldGameInstance::PushNotification_UI_Implementation()
{
	DisplayPopUpOnScreen();
}

void UExWorldGameInstance::OnGetCharacterAttributes(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result)
{
	EXWORLDLOG("Character Created");
	FString PlayerID = "";
	FunctionResultValue = Result.FunctionResult.GetJsonValue();
	HeadObject = FunctionResultValue->AsObject();
	PlayerID = HeadObject->GetStringField("PlayFabId");
	PlayerDataObject = HeadObject->GetObjectField("Data");
	RaceObject = PlayerDataObject->GetObjectField("CharacterRace");
	ExWorldPlayerInfo_S.CharacterCreationStats.Race = RaceObject->GetStringField("Value");
	GenderObject = PlayerDataObject->GetObjectField("CharacterGender");
	ExWorldPlayerInfo_S.CharacterCreationStats.Gender = GenderObject->GetStringField("Value");
	HairObject = PlayerDataObject->GetObjectField("Hair");
	ExWorldPlayerInfo_S.CharacterCreationStats.Hair = HairObject->GetStringField("Value");
	FaceObject = PlayerDataObject->GetObjectField("Face");
	ExWorldPlayerInfo_S.CharacterCreationStats.Face = FaceObject->GetStringField("Value");
	EyesObject = PlayerDataObject->GetObjectField("Eyes");
	ExWorldPlayerInfo_S.CharacterCreationStats.Eyes = EyesObject->GetStringField("Value");
	BodyTypeObject = PlayerDataObject->GetObjectField("BodyType");
	ExWorldPlayerInfo_S.CharacterCreationStats.BodyType = BodyTypeObject->GetStringField("Value");
	SkinColorObject = PlayerDataObject->GetObjectField("SkinColor");
	ExWorldPlayerInfo_S.CharacterCreationStats.SkinColor = SkinColorObject->GetStringField("Value");
	NameObject = PlayerDataObject->GetObjectField("CharacterName");
	ExWorldPlayerInfo_S.CharacterCreationStats.Name = NameObject->GetStringField("Value");
	ClassObject = PlayerDataObject->GetObjectField("CharacterType");
	ExWorldPlayerInfo_S.CharacterCreationStats.PlayerClass = ClassObject->GetStringField("Value");
	OnGetCreationStats.Broadcast(ExWorldPlayerInfo_S);
	/*GetWorld()->GetTimerManager().SetTimer(Handle, [this, PlayerID]() {
            GetAllPlayerCharacters(PlayerID);
        }, 1, false);*/
}



void UExWorldGameInstance::DisplayPopUpOnScreen()
{
	DisplayPopUp = true;
}

//deprecated
void UExWorldGameInstance::GetAllCharacterData(int CharIndex)
{
	//SelectedCharacterID = CharIndex;

	////local characterid
	//FString CharID = CharactersInfoArray[SelectedCharacterID].characterId;
	////Empty Json
	//const TSharedPtr<FJsonObject> PFJsonObject = MakeShareable(new FJsonObject); //for safety check is valid TODO
	//PFJsonObject->SetStringField("CharacterId", CharID);

	//ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	//PlayFab::ClientModels::FExecuteCloudScriptRequest request;

	//request.FunctionName = TEXT("GetAllCharacterData");
	//request.FunctionParameter = PFJsonObject; //No need to convert json into string
	//request.GeneratePlayStreamEvent = true;
	//ClientAPI->ExecuteCloudScript(request,
	//	PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &UExWorldGameInstance::OnGetAllCharacterData),
	//	PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));

	//UE_LOG(LogTemp, Warning, TEXT("Sending get character data request"));
}

//deprecated
void UExWorldGameInstance::OnGetAllCharacterData(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result)
{

	//FString FunctionResultStringValue = Result.FunctionResult.GetJsonValue()->AsString();
	//FString CharID = CharactersInfoArray[SelectedCharacterID].characterId;

	//TSharedPtr<FJsonObject> JsonParsed;
	//TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(FunctionResultStringValue);

	////deserialize json string from server
	//if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	//{

	//	//convert json data into the struct object directly
	//	FExWorldCharacterInfo_S ConvertedData;
	//	if (FJsonObjectConverter::JsonObjectStringToUStruct(FunctionResultStringValue, &ConvertedData, 0, 0))
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("CONVERTED"));

	//		//complete remaining data of current character
	//		CharactersInfoArray[SelectedCharacterID].Race = ConvertedData.Race;
	//		CharactersInfoArray[SelectedCharacterID].ProgressionLevel = ConvertedData.ProgressionLevel;
	//		CharactersInfoArray[SelectedCharacterID].Appearance = ConvertedData.Appearance;
	//	}
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("CONVERTION FAILED"));
	//}
}

void UExWorldGameInstance::SetCharacter(int CharID)
{
	SelectedCharacterID = CharID;
}




void UExWorldGameInstance::OnGuildInvitationSent(const PlayFab::GroupsModels::FInviteToGroupResponse& Response)
{
	EXWORLDLOG("Guild invitation Request Sent");	
}

void UExWorldGameInstance::RequestGuildInfo(FGuildInfo_S GuildInfo)
{
	OnGetGuildInfo.Broadcast(GuildInfo);
	GetWorld()->GetTimerManager().SetTimer(Handle, [this]() {
        Test();
    }, 10.0, false);
}

FString UExWorldGameInstance::RoleType(ERoleType Role)
{
	FString GuildMaster = TEXT("admins");
	FString ViceCaptain = TEXT("vicecaptain");
	FString Council = TEXT("council");
	FString Member = TEXT("members");
	FString Recruits = TEXT("recruits");
	
	switch (Role)
	{
	case ERoleType::GuildMaster:
		return GuildMaster;

	case ERoleType::ViceCaptain:
		return ViceCaptain;

	case ERoleType::Council:
		return Council;

	case ERoleType::Members:
		return Member;
		
	case ERoleType::Recruits:
		return Recruits;
	}
	return Member;   // By Default return member
}

void UExWorldGameInstance::OnError(const PlayFab::FPlayFabCppError& ErrorResult) const
{
	//UE_LOG(LogTemp, Error, TEXT("Error in ExWorld Game instance :\n%s"), *ErrorResult.GenerateErrorReport());
	EXWORLDLOG_SE("Error in ExWorld Game instance ",ErrorResult.GenerateErrorReport())
}

void UExWorldGameInstance::Test()
{
	InviteToGuild(ExWorldGuldInfo_S.GuildID, TEXT("1CEA7753EAED8C19"),ERoleType::GuildMaster); //temp id
}


void UExWorldGameInstance::UpdateStatsOnPlayFab(FEXWCharacterStat_Info playerStatData)
{

	//TArray< TSharedPtr<FJsonValue> > LocalJsonArray;

	////make stat data json sub array
	//for (auto obj : playerStatData.StatLevelPoints)
	//{
	//	TSharedPtr<FJsonObject> LocalJsonObject = MakeShareable(new FJsonObject);//local loop veriable
	//	LocalJsonObject->SetStringField("StatType", *UEnum::GetDisplayValueAsText(obj.StatType).ToString());
	//	LocalJsonObject->SetNumberField("Level", obj.Level);

	//	TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(LocalJsonObject));
	//	LocalJsonArray.Add(JsonValue);
	//}

	////make stats main json object from converted data above
	//TSharedPtr<FJsonObject> LocalPFJsonObject = MakeShareable(new FJsonObject);

	//LocalPFJsonObject->SetArrayField("StatLevelPoints", (LocalJsonArray));
	//LocalPFJsonObject->SetNumberField("UnspentPoints", playerStatData.UnspentPoints);


	//const TSharedPtr<FJsonObject> PFJsonObject = MakeShareable(new FJsonObject);

	////add in character id parameter and inventory Key/value
	//if (CharactersInfoArray.IsValidIndex(SelectedCharacterID))
	//{
	//	PFJsonObject->SetStringField("CharacterId", CharactersInfoArray[SelectedCharacterID].characterId);
	//	PFJsonObject->SetObjectField("Stats", LocalPFJsonObject);

	//	//playfab api call to write inventory
	//	ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	//	PlayFab::ClientModels::FExecuteCloudScriptRequest request;

	//	request.FunctionName = TEXT("UpdateStatData");
	//	request.FunctionParameter = PFJsonObject; //No need to convert json into string
	//	request.GeneratePlayStreamEvent = true;
	//	ClientAPI->ExecuteCloudScript(request,
	//		PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &UExWorldGameInstance::OnStatsUpdated),
	//		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
	//}

}

void UExWorldGameInstance::OnStatsUpdated(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result)
{
	UE_LOG(LogTemp, Warning, TEXT("StatUpdated"));
	UE_LOG(LogTemp, Error, TEXT("%s"), *Result.toJSONString());
}

void UExWorldGameInstance::UpdateCharacterTransformOnPlayFab(FVector Location, FRotator Rotation)
{
	//TSharedPtr<FJsonObject> LocalPFJsonObject = MakeShareable(new FJsonObject);

	//LocalPFJsonObject->SetStringField("Location", Location.ToString());
	//LocalPFJsonObject->SetStringField("Rotation", Rotation.ToString());

	//const TSharedPtr<FJsonObject> PFJsonObject = MakeShareable(new FJsonObject);



	//if (CharactersInfoArray.IsValidIndex(SelectedCharacterID))
	//{
	//	PFJsonObject->SetStringField("CharacterId", CharactersInfoArray[SelectedCharacterID].characterId);
	//	PFJsonObject->SetObjectField("Transform", LocalPFJsonObject);

	//	//playfab api call to write inventory
	//	ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();
	//	PlayFab::ClientModels::FExecuteCloudScriptRequest request;

	//	request.FunctionName = TEXT("UpdateTransformData");
	//	request.FunctionParameter = PFJsonObject; //No need to convert json into string
	//	request.GeneratePlayStreamEvent = true;
	//	ClientAPI->ExecuteCloudScript(request,
	//		PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &UExWorldGameInstance::OnTransformUpdated),
	//		PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &UExWorldGameInstance::OnError));
	//}
}

void UExWorldGameInstance::OnTransformUpdated(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result)
{
	UE_LOG(LogTemp, Warning, TEXT("TransformUpdated"));
	UE_LOG(LogTemp, Error, TEXT("%s"), *Result.toJSONString());
}