// Fill out your copyright notice in the Description page of Project Settings.


#include "ExWorldBlueprintFunctionLibrary.h"
#include "ExWorldLoadingScreen.h"
#include "Runtime/Core/Public/Misc/AES.h"
#include "Runtime/Core/Public/Misc/SecureHash.h"
#include "Runtime/Core/Public/Misc/Base64.h"
#include "Network/ExWorldGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Engine/LevelStreaming.h"

DEFINE_LOG_CATEGORY_STATIC(LogEWLoadingScreen, Log, All);
DEFINE_LOG_CATEGORY_STATIC(LogEWEncrypt, Log, All);
DEFINE_LOG_CATEGORY_STATIC(LogEWDecrypt, Log, All);


FEWLoadingScreenSystem::FEWLoadingScreenSystem(UGameInstance* InGameInstance)
	:GameInstance(InGameInstance)
{
	FCoreDelegates::OnAsyncLoadingFlushUpdate.AddRaw(this, &FEWLoadingScreenSystem::OnAsyncLoadingFlushUpdate);
}

void FEWLoadingScreenSystem::SetWidget(TSharedPtr<SWidget> InWidget)
{
	LoadingScreenWidget = InWidget;
}

FEWLoadingScreenSystem::~FEWLoadingScreenSystem()
{
}

void FEWLoadingScreenSystem::Tick(float DeltaTime)
{

}

float FEWLoadingScreenSystem::GetLoadingProgress()
{
	float Sum = 0.f;
	int32 PackageNum = 1;
	UPackage* PersistentLevelPackage = FindObjectFast<UPackage>(NULL, PackageName);
	if (PersistentLevelPackage && (PersistentLevelPackage->GetLoadTime() > 0))
	{
		Sum += 100.0f;
	}
	else
	{
		const float LevelLoadPercentage = GetAsyncLoadPercentage(PackageName);
		if (LevelLoadPercentage >= 0.0f)
		{
			Sum += LevelLoadPercentage;
		}
	}

	if (PersistentLevelPackage)
	{
		UWorld* World = UWorld::FindWorldInPackage(PersistentLevelPackage);
		TArray<FName>	PackageNames;
		PackageNames.Reserve(World->GetStreamingLevels().Num());
		for (ULevelStreaming* LevelStreaming : World->GetStreamingLevels())
		{
			if (LevelStreaming
				&& !LevelStreaming->GetWorldAsset().IsNull()
				&& LevelStreaming->GetWorldAsset() != World)
			{
				PackageNames.Add(LevelStreaming->GetWorldAssetPackageFName());
			}
		}
		for (FName& LevelName : PackageNames)
		{
			PackageNum++;
			UPackage* LevelPackage = FindObjectFast<UPackage>(NULL, LevelName);

			if (LevelPackage && (LevelPackage->GetLoadTime() > 0))
			{
				Sum += 100.0f;
			}
			else
			{
				const float LevelLoadPercentage = GetAsyncLoadPercentage(LevelName);
				if (LevelLoadPercentage >= 0.0f)
				{
					Sum += 100.0f;
				}
			}
		}
	}

	float Current = Sum / PackageNum;
	Progress = Current * 0.05f + Progress * 0.95f;
	UE_LOG(LogEWLoadingScreen, Verbose, TEXT("%6.3f %6.3f SubLevels %d"), Progress, Current, PackageNum);
	return Progress / 100.0f;
}

void FEWLoadingScreenSystem::OnAsyncLoadingFlushUpdate()
{
	check(IsInGameThread());

	QUICK_SCOPE_CYCLE_COUNTER(STAT_LoadingScreenManager_OnAsyncLoadingFlushUpdate);

	const double CurrentTime = FPlatformTime::Seconds();
	const double DeltaTime = CurrentTime - LastTickTime;
	if (DeltaTime > 1.0f / 60.0f)
	{
		LastTickTime = CurrentTime;
		if (bShowing) {
			// ??????
			FSlateApplication::Get().Tick();

			{
				TGuardValue<int32> DisableAsyncLoadDuringSync(GDoAsyncLoadingWhileWaitingForVSync, 0);
				FSlateApplication::Get().GetRenderer()->Sync();
			}
		}

		LastTickTime = CurrentTime;
	}
}
void FEWLoadingScreenSystem::ShowLoadingScreen()
{
	if (bShowing)
	{
		return;
	}

	bShowing = true;
	Progress = 0.0f;

	UE_LOG(LogEWLoadingScreen, Log, TEXT("Show loading screen"));

	if (GameInstance)
	{
		UGameViewportClient* GameViewportClient = GameInstance->GetGameViewportClient();
		if (GameViewportClient)
		{
			const int32 ZOrder = 10000;
			GameViewportClient->AddViewportWidgetContent(LoadingScreenWidget.ToSharedRef(), ZOrder);

			GameViewportClient->bDisableWorldRendering = true;
			if (!GIsEditor)
			{
				FSlateApplication::Get().Tick();
			}
		}
	}
}

void FEWLoadingScreenSystem::HideLoadingScreen()
{
	if (!bShowing)
	{
		return;
	}

	UE_LOG(LogEWLoadingScreen, Log, TEXT("Hide loading screen"));
	GEngine->ForceGarbageCollection(true);

	if (GameInstance)
	{
		UGameViewportClient* GameViewportClient = GameInstance->GetGameViewportClient();
		if (GameViewportClient && LoadingScreenWidget.IsValid())
		{
			GameViewportClient->RemoveViewportWidgetContent(LoadingScreenWidget.ToSharedRef());
		}

		if (GameViewportClient)
		{
			GameViewportClient->bDisableWorldRendering = false;
		}
	}
	bShowing = false;
}

UExWorldBlueprintFunctionLibrary::UExWorldBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{ }

void UExWorldBlueprintFunctionLibrary::SetLoadingScreenWidget(UUserWidget* InWidget)
{
	UWorld* World = GEngine->GetWorldFromContextObject(InWidget, EGetWorldErrorMode::LogAndReturnNull);
	if (World == nullptr) { return; }
	UExWorldGameInstance* GameInstance = Cast<UExWorldGameInstance>(World->GetGameInstance());
	if (GameInstance == nullptr) { return; }
	TSharedRef<SWidget> TakenWidget = InWidget->TakeWidget();
	GameInstance->EWLoadingScreenSystem->SetWidget(TakenWidget);
}

void UExWorldBlueprintFunctionLibrary::SetTargetPackageForLoadingProgress(const UObject* WorldContextObject, FName InPackageName)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World == nullptr) { return; }
	UExWorldGameInstance* GameInstance = Cast<UExWorldGameInstance>(World->GetGameInstance());
	if (GameInstance == nullptr) { return; }
	return GameInstance->EWLoadingScreenSystem->SetPackageNameForLoadingProgress(InPackageName);
}

float UExWorldBlueprintFunctionLibrary::GetLoadingProgress(const UObject* WorldContextObject)
{
	UExWorldGameInstance* GameInstance = Cast<UExWorldGameInstance>(WorldContextObject->GetOuter());
	if (GameInstance == nullptr)	
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
		if (World == nullptr) { return 0; }
		GameInstance = Cast<UExWorldGameInstance>(World->GetGameInstance());
		if (GameInstance == nullptr) { return 0; }
	}
	return GameInstance->EWLoadingScreenSystem->GetLoadingProgress();
}

void UExWorldBlueprintFunctionLibrary::ShowEWLoadingScreen(const UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World == nullptr) { return; }
	UExWorldGameInstance* GameInstance = Cast<UExWorldGameInstance>(World->GetGameInstance());
	if (GameInstance == nullptr) { return; }
	GameInstance->EWLoadingScreenSystem->ShowLoadingScreen();
}
void UExWorldBlueprintFunctionLibrary::HideEWLoadingScreen(const UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World == nullptr) { return; }
	UExWorldGameInstance* GameInstance = Cast<UExWorldGameInstance>(World->GetGameInstance());
	if (GameInstance == nullptr) { return; }
	GameInstance->EWLoadingScreenSystem->HideLoadingScreen();
}

FString UExWorldBlueprintFunctionLibrary::GetPlayerUniqueID()
{
	return RetrieveVar("GlobalPlayerID","",false);
	
}

FString UExWorldBlueprintFunctionLibrary::GetPlayerDisplayName()
{
	return "";
}

FString UExWorldBlueprintFunctionLibrary::GetFriendsUniqueId()
{
	return "";
}

void UExWorldBlueprintFunctionLibrary::PlayExWorldLoadingScreen(bool bPlayUntilStopped, float PlayTime ,const FString& MapName) {

	PlayTime = 10.0f;
	bPlayUntilStopped = false;
	IExWorldLoadingScreenModule& LoadingScreenModule = IExWorldLoadingScreenModule::Get();
	LoadingScreenModule.StartInGameLoadingScreen(bPlayUntilStopped, PlayTime,MapName);

}

void UExWorldBlueprintFunctionLibrary::StopLoadingScreen()
{
	IExWorldLoadingScreenModule& LoadingScreenModule = IExWorldLoadingScreenModule::Get();
	LoadingScreenModule.StopInGameLoadingScreen();
}

void UExWorldBlueprintFunctionLibrary::SaveVar(FString VarName, FString Data, bool Encrypt)
{
	if(!Encrypt)
	{
		const FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()) + TEXT("/shared.txt");

		if(FFileHelper::SaveStringToFile(VarName+"="+Data+"\r\n",*FilePath,FFileHelper::EEncodingOptions::AutoDetect,&IFileManager::Get(),FILEWRITE_Append))
		{
			UE_LOG(LogEWEncrypt, Log, TEXT("DataStored"),*Data);
		}
		else
		{
			UE_LOG(LogEWEncrypt, Error, TEXT("Failed to write Data."));
			//UE_LOG(LogTemp,Warning,TEXT(""))
		}
	}
	else
	{
		//Encrypt(VarName,Data)
	}
}

FString UExWorldBlueprintFunctionLibrary::RetrieveVar(FString VarName, FString Data, bool Decrypt)
{
	if(!Decrypt)
	{
		IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
		const FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir()) + TEXT("/shared.txt");
		FString FileContent;
		if (FileManager.FileExists(*FilePath))
		{
			// We use the LoadFileToString to load the file into
			if(FFileHelper::LoadFileToString(FileContent,*FilePath,FFileHelper::EHashOptions::None))
			{
				UE_LOG(LogEWDecrypt, Log, TEXT("Success"), *FileContent);
				FileContent = FileContent.RightChop(GetNum(VarName)+1);
				return FileContent;
			}
		}
	}
	else
	{
		//Decrypt("GlobalPlayerID");
	}
	return "";
}

FString UExWorldBlueprintFunctionLibrary::Encrypt(FString VarName, FString Data)
{
	if (VarName.IsEmpty()) return "";  //empty string? do nothing
	if (Data.IsEmpty()) return "";

	FString AddSymbol = "%@!L";
	VarName.Append(AddSymbol);
	Data = FMD5::HashAnsiString(*Data);
	TCHAR *KeyTChar = Data.GetCharArray().GetData();           
	ANSICHAR *KeyAnsi = (ANSICHAR*)TCHAR_TO_ANSI(KeyTChar); 
	uint32 Size = VarName.Len();
	Size = Size + (FAES::AESBlockSize - (Size % FAES::AESBlockSize));

	//create and hold binary daya  TODO try to relocate on stack but its okay i guess -> Research and ask Jed  
	uint8* Blob = new uint8[Size];

	if(StringToBytes(VarName, Blob, Size)) {

		FAES::EncryptData(Blob, Size, KeyAnsi);
		VarName = FString::FromHexBlob(Blob, Size);

		delete[] Blob;
		return VarName;		
	}

	delete[] Blob;
	return "";
}

FString UExWorldBlueprintFunctionLibrary::Decrypt(FString VarName)
{
	// Check inputs
	if (VarName.IsEmpty()) return ""; 
	
	
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	const FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()) + TEXT("/shared.txt");
	FString FileContent;
	if (FileManager.FileExists(*FilePath))
	{
		// We use the LoadFileToString to load the file into
		if(FFileHelper::LoadFileToString(FileContent,*FilePath,FFileHelper::EHashOptions::None))
		{
			UE_LOG(LogEWDecrypt, Log, TEXT("Success"), *FileContent);  
		}
		else
		{
			UE_LOG(LogEWDecrypt, Error, TEXT("Fail"));
		}
	}
	if (FileContent.IsEmpty()) return "";

	FString AddSymbol = "%@!L";

	// We need at least 32 symbols key
	FileContent = FMD5::HashAnsiString(*FileContent);
	TCHAR *KeyTChar = FileContent.GetCharArray().GetData();
	ANSICHAR *KeyAnsi = (ANSICHAR*)TCHAR_TO_ANSI(KeyTChar);
	
	uint32 Size = VarName.Len();
	Size = Size + (FAES::AESBlockSize - (Size % FAES::AESBlockSize));

	uint8* Blob = new uint8[Size]; 

	
	if (FString::ToHexBlob(VarName, Blob, Size)) {

		FAES::DecryptData(Blob, Size, KeyAnsi);		
		VarName = BytesToString(Blob, Size);

		FString LeftData;	
		FString RightData;	
		VarName.Split(AddSymbol, &LeftData, &RightData, ESearchCase::CaseSensitive, ESearchDir::FromStart);
		VarName = LeftData;

		delete[] Blob; 
		return VarName; 
	}

	delete[] Blob; 
	return ""; 
}
