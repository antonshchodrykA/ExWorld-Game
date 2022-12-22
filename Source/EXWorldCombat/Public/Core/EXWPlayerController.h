// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "GameFramework/PlayerController.h"
#include "Library/Cloud/EXWCloudStruct.h"
#include "Library/EXWDataEnum.h"
#include "EXWPlayerController.generated.h"

//General Character Log
DECLARE_LOG_CATEGORY_EXTERN(EXWCtrlLog, Log, All);

class AALSBaseCharacter;
class AEXWCharacter;
class UEXWSharedWidget;
class UEXWFloatingWidget;
class UEXWScreenMessageWidget;
class UEXWDialogueWidget;
class UEXWQuestPanelWidget;
class UEXWNPCShopWidget;
class UEXWCraftWidget;
class UChatComponent;

/**
 * 
 */


UCLASS()
class EXWORLDCOMBAT_API AEXWPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	AEXWPlayerController();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Controller")
	bool GetInteractableUnderCursor(AActor* &OutInteractableActor, const float Distance = 500.f);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller")
	bool GetNearestInteractable(const float Radius = 500.f);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller")
	void ClickOnInteractable(const float Distance = 500.f, const bool bIgnoreSelf = true);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void CheckIfNoUIOpen();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	bool CheckIfAnyUIHovered();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	UEXWSharedWidget* CreateSharedWidget(TSubclassOf<UEXWSharedWidget> SharedWidgetClass, AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const bool bInitialize = true);
	
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	UEXWSharedWidget* CreateShopWidget(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	UEXWSharedWidget* CreateTradeWidget(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter); 

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	UEXWFloatingWidget* CreateFloatingWidget(TSubclassOf<UEXWFloatingWidget> FloatingWidgetClass);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	UEXWFloatingWidget* CreateFloatingTextWidget(AEXWCharacter* TargetCharacter, const float Value, const EEXWAttributeEffectType AttributeEffectType, const bool bIsCritical = false);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	UEXWScreenMessageWidget* CreateScreenMessageWidget(const EEXWScreenMessageType ScreenMessageType);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Controller|Widget")
	//UFUNCTION(Client, Reliable, BlueprintImplementableEvent, Category = "EXWorld|Controller|Widget")
	void CreateRequestDuelWidget(AEXWCharacter* SourceCharacter);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void RequestRespawnPawn(bool UseRespawnPoint);

	void OnRestartPawn(APawn* NewPawn);

	//ChatSystem
	UPROPERTY()
	UChatComponent* ChatComponent;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Chat")
	UChatComponent* GetChatComponent();

	//Spatial OS
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type Reason) override;
	
	FString LatestPIToken;
	const char* LatestPITokenData;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|SpatialOS")
	void JoinSpatialDeployment(const FString& LoginToken, const FString& PIT);
	
	UFUNCTION(BlueprintCallable,  Category = "EXWorld|Controller|Widget")
	void DisplayScreenMessage(const EEXWScreenMessageType ScreenMessageType);

	UFUNCTION(BlueprintNativeEvent, Category = "EXWorld|Controller|Widget")
	void DisplayToggleGatheringProgress(bool Isstart, EEXWLifeSkillType Type, float Timer);

	
	// UI
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> HUDLayoutWidgetClass;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* HUDLayoutWidget;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> ChatWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D ChatWidgetPosition;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D ChatWidgetSize;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* ChatWidget;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> NotificationsWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D NotificationsWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* NotificationsWidget;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> LifeSkillProgressWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D LifeSkillProgressWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* LifeSkillProgressWidget;
	
	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION(Client, Reliable, Category = "EXWorld|Controller|UI")
	void Client_Initialize();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> PartyMenuWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D PartyMenuWidgetPosition;
	
	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* PartyMenuWidget;
	
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void TogglePartyMenu();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UEXWSharedWidget> InteractionWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D InteractWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UEXWSharedWidget* InteractionWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleInteractMenu(AActor* InteractableActor);

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> AbilitiesMenuWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D AbilitiesMenuWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* AbilitiesMenuWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleAbilitiesMenu();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> AbilityTreeMenuWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D AbilityTreeMenuWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* AbilityTreeMenuWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleAbilityTreeMenu();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> StatsMenuWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D StatsMenuWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* StatsMenuWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleStatsMenu();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UEXWCraftWidget> CraftMenuWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D CraftMenuWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UEXWCraftWidget* CraftMenuWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleCraftMenu();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void CreateCraftMenu(AEXWPlaceableCraftStation* CraftStation, EEXWCraftCategory Category = EEXWCraftCategory::CC_Alchemy);

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> LifeSkillMenuWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D LifeSkillMenuWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* LifeSkillMenuWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleLifeSkillMenu();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> InventoryMenuWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D InventoryMenuWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* InventoryMenuWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleInventoryMenu();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> ShopMenuWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D ShopMenuWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* ShopMenuWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleShopMenu();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> CreatePartyWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D CreatePartyWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* CreatePartyWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleCreateParty();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> InviteToPartyWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D InviteToPartyWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* InviteToPartyWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleInviteToParty();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> RemovePartyWidgetClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D RemovePartyWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* RemovePartyWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleRemoveParty();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> LeavePartyWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D LeavePartyWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* LeavePartyWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleLeaveParty();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> KickPartyWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D KickPartyWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* KickPartyWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleKickParty();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> PartyInfoWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D PartyInfoWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* PartyInfoWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void TogglePartyInfo();
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UEXWDialogueWidget> DialogueWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D DialogueWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UEXWDialogueWidget* DialogueWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void DisplayDialogueUI(FName DialogueID);

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UEXWNPCShopWidget> NPCShopWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D NPCShopWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UEXWNPCShopWidget* NPCShopWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void DisplayNPCShopUI(FName NPCShopID, AEXWCharacter* ShopOwner);

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UEXWQuestPanelWidget> QuestPanelWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D QuestPanelWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UEXWQuestPanelWidget* QuestPanelWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void DisplayQuestPanelUI(FName QuestID);

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "EXWorld|Controller|Widget")
	TSubclassOf<UUserWidget> QuestJournalWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Controller|Widget")
	FVector2D QuestJournalWidgetPosition;

	UPROPERTY(BlueprintReadWrite, Category = "EXWorld|Controller|Widget")
	UUserWidget* QuestJournalWidget;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Controller|Widget")
	void ToggleQuestJournalUI();

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Controller|Widget")
	void OnToggleCasting(FName ActionID, bool IsToggleOn, float Duration );


	//Key Bindings
	virtual void SetupInputComponent() override;

protected:

	AALSBaseCharacter* PossessedCharacter;

};
