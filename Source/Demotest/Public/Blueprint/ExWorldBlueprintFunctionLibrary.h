// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExWorldBlueprintFunctionLibrary.generated.h"


class FEWLoadingScreenSystem : public FTickableGameObject
{
	TSharedPtr<SWidget>	LoadingScreenWidget;
	bool bShowing = false;
	UGameInstance* GameInstance;
	double LastTickTime = 0.0;
	void OnAsyncLoadingFlushUpdate();
	FName PackageName;
	float Progress = 0.0f;
public:
	FEWLoadingScreenSystem(UGameInstance* InGameInstance);
	~FEWLoadingScreenSystem();
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(FSimpleLoadingScreenSystem, STATGROUP_Tickables); }
	virtual void Tick(float DeltaTime) override;

	void SetWidget(TSharedPtr<SWidget> InWidget);
	void SetPackageNameForLoadingProgress(FName InPackageName) { PackageName = InPackageName; }
	float GetLoadingProgress();
	void ShowLoadingScreen();
	void HideLoadingScreen();

};

UCLASS()
class DEMOTEST_API UExWorldBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	public:

		UExWorldBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "ExWorldLoadingScreen")
    static void PlayExWorldLoadingScreen(bool bPlayUntilStopped, float PlayTime,const FString& MapName);

	UFUNCTION(BlueprintCallable, Category = "ExWorldLoadingScreen")
    static void StopLoadingScreen();

	UFUNCTION(BlueprintCallable)
	static void SetLoadingScreenWidget(UUserWidget* InWidget);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void SetTargetPackageForLoadingProgress(const UObject* WorldContextObject, FName InPackageName);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static float GetLoadingProgress(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void ShowEWLoadingScreen(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
	static void HideEWLoadingScreen(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "ExWorldPlayerInfo")
	static FString GetPlayerUniqueID();

	UFUNCTION(BlueprintPure, Category = "ExWorldPlayerInfo")
    static FString GetPlayerDisplayName();

	UFUNCTION(BlueprintPure, Category = "ExWorldPlayerInfo")
    static FString GetFriendsUniqueId();
	
	UFUNCTION()
	static void SaveVar(FString VarName, FString Data, bool Encrypt);

	UFUNCTION()
    static FString RetrieveVar(FString VarName, FString Data, bool Decrypt);

	UFUNCTION()
    static FString Encrypt(FString VarName, FString Data);

	UFUNCTION()
    static FString Decrypt(FString VarName);

};



