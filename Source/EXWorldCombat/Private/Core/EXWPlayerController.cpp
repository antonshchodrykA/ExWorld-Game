// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWPlayerController.h"
#include "Interface/EXWInteractable.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
// ALS
#include "Character/ALSBaseCharacter.h"
#include "Character/ALSPlayerCameraManager.h"
// Core
#include "Core/EXWCharacter.h"
#include "Core/Inventory/EXWItem.h"
#include "Library/EXWDataLibrary.h"
// Widgets
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Widgets/EXWSharedWidget.h"
#include "Widgets/EXWFloatingWidget.h"
#include "Widgets/EXWScreenMessageWidget.h"
#include "Widgets/EXWDialogueWidget.h"
#include "Widgets/EXWQuestPanelWidget.h"
#include "Widgets/EXWNPCShopWidget.h"
#include "Widgets/EXWCraftWidget.h"
// Components
#include "Chat/Components/ChatComponent.h"
// Spatial OS
#include <WorkerSDK/improbable/c_worker.h>
#include "SpatialGameInstance.h"
#include "SpatialWorkerConnection.h"
// Kismet
#include "Blueprint/WidgetBlueprintLibrary.h"

#include "Placeables/EXWPlaceableCraftStation.h"
#include "../EXWorldCombatPlayerState.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "Runtime/Engine/Classes/Engine/UserInterfaceSettings.h"



//General Character Log
DEFINE_LOG_CATEGORY(EXWCtrlLog);

AEXWPlayerController::AEXWPlayerController()
{
	ChatComponent = CreateDefaultSubobject<UChatComponent>("Chat Component");
}



bool AEXWPlayerController::GetInteractableUnderCursor(AActor*& OutInteractableActor, float Distance /*= 500.f*/)
{
	if(CheckIfAnyUIHovered())
	{
		return false;
	}
	FHitResult HitResult;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypeQuery;
	ObjectTypeQuery.Add(UEngineTypes::ConvertToObjectType(ECC_GameTraceChannel3));
	if (GetHitResultUnderCursorForObjects(ObjectTypeQuery, true, HitResult))
	{
		if (HitResult.GetActor() && GetPawn())
		{
			if (HitResult.GetActor()->GetClass()->ImplementsInterface(UEXWInteractable::StaticClass()))
			{
				if (GetPawn()->GetDistanceTo(HitResult.GetActor()) <= Distance)
				{
					OutInteractableActor = HitResult.GetActor();
					return true;
				}
			}
		}
	}
	return false;
}

bool AEXWPlayerController::GetNearestInteractable(const float Radius)
{
	if (GetPawn())
	{
		const FVector Start = GetPawn()->GetRootComponent()->GetComponentTransform().GetLocation();
		const FVector End = Start;

		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypeQuery;
		ObjectTypeQuery.Add(UEngineTypes::ConvertToObjectType(ECC_GameTraceChannel3));

		TArray<AActor*> IgnoreActors;
		IgnoreActors.Add(GetPawn());

		TArray<FHitResult> HitResults;

		bool isHit = UKismetSystemLibrary::SphereTraceMultiForObjects
		(	GetWorld(),
			Start,
			End, 
			Radius, 
			ObjectTypeQuery,
			true, 
			IgnoreActors, 
			EDrawDebugTrace::None, 
			HitResults, 
			true, 
			FLinearColor::Red, 
			FLinearColor::Green, 
			5.0f
		);

		if (isHit && HitResults.Num()>0)
		{
			float ClosestDistance= Radius;
			AActor* ClosestActor= nullptr;
			for (FHitResult Hit: HitResults)
			{
				if (GetPawn()->GetDistanceTo(Hit.GetActor()) <= ClosestDistance && Hit.GetActor()->GetClass()->ImplementsInterface(UEXWInteractable::StaticClass()))
				{
					ClosestDistance = GetPawn()->GetDistanceTo(Hit.GetActor());
					ClosestActor = Hit.GetActor();
				}
			}

			if (ClosestActor!=nullptr)
			{
				if (IEXWInteractable* ResultInteractable = Cast<IEXWInteractable>(ClosestActor))
					{

						if (ResultInteractable->InteractionMaxDistance < GetPawn()->GetDistanceTo(ClosestActor))
						{
							DisplayScreenMessage(EEXWScreenMessageType::SM_InteractionRangeError);
							UE_LOG(EXWCtrlLog, Warning, TEXT("Cannot interact with the actor, too far away."));
							return false;
						}
						if (ResultInteractable->AvailableInteractionTypes.Num() == 1)
						{
							AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(GetPawn());
							OwnerCharacter->Server_Interact(ClosestActor, ResultInteractable->AvailableInteractionTypes[0]);
						}
						else if (ResultInteractable->AvailableInteractionTypes.Num() > 1)
						{
							if (AActor* InteractableActor=Cast<AActor>(ResultInteractable))
							{
								FVector2D ViewportSize;
								GEngine->GameViewport->GetViewportSize(ViewportSize);
						
								const FVector2D  ViewportCenter =  FVector2D(ViewportSize.X/2, ViewportSize.Y/2);

								UGameplayStatics::ProjectWorldToScreen(this,InteractableActor->GetActorLocation(),InteractWidgetPosition,true);

								if (ViewportCenter.X - InteractWidgetPosition.X < 0)
								{
									InteractWidgetPosition.X -= 150;
								}
								else
								{
									InteractWidgetPosition.X += 150;
								}
								ToggleInteractMenu(InteractableActor);
							}
						}
					}
					return true;
			}
		}
	}
	return false;
}

void AEXWPlayerController::ClickOnInteractable(const float Distance, const bool bIgnoreSelf)
{
	// Leave if the mouse cursor is not shown
	if (!bShowMouseCursor)
	{
		return;
	}
	AActor* ResultActor;
	if (GetInteractableUnderCursor(ResultActor, Distance))
	{
		// Check if clicked on self
		if (ResultActor == GetPawn() && bIgnoreSelf)
		{
			return;
		}
		if (AEXWCharacter* OwnerCharacter = Cast<AEXWCharacter>(GetPawn()))
		{
			// Check if it is an item, and pick it if yes
			if (IEXWInteractable* ResultInteractable = Cast<IEXWInteractable>(ResultActor))
			{
				if (ResultInteractable->InteractionMaxDistance < OwnerCharacter->GetDistanceTo(ResultActor))
				{
					DisplayScreenMessage(EEXWScreenMessageType::SM_InteractionRangeError);
					UE_LOG(EXWCtrlLog, Warning, TEXT("Cannot interact with the actor, too far away."));
					return;
				}
				if (ResultInteractable->AvailableInteractionTypes.Num() == 1)
				{
					OwnerCharacter->Server_Interact(ResultActor, ResultInteractable->AvailableInteractionTypes[0]);
				}
				else if (ResultInteractable->AvailableInteractionTypes.Num() > 1)
				{
					if (AActor* InteractableActor=Cast<AActor>(ResultInteractable))
					{
						FVector2D ViewportSize;
						GEngine->GameViewport->GetViewportSize(ViewportSize);
						
						const FVector2D  ViewportCenter =  FVector2D(ViewportSize.X/2, ViewportSize.Y/2);

						UGameplayStatics::ProjectWorldToScreen(this,InteractableActor->GetActorLocation(),InteractWidgetPosition,true);

						if (ViewportCenter.X - InteractWidgetPosition.X < 0)
						{
							InteractWidgetPosition.X -= 150;
						}
						else
						{
							InteractWidgetPosition.X += 150;
						}
						ToggleInteractMenu(InteractableActor);
					}
				}
			}
		}
	}
}

void AEXWPlayerController::CheckIfNoUIOpen()
{
	if (
		IsValid(InventoryMenuWidget) 
		|| IsValid(ShopMenuWidget) 
		|| IsValid(CraftMenuWidget)
		|| IsValid(LifeSkillMenuWidget) 
		|| IsValid(StatsMenuWidget)
		|| IsValid(PartyInfoWidget)
		|| IsValid(PartyMenuWidget)
		|| IsValid(AbilitiesMenuWidget)
		|| IsValid(AbilityTreeMenuWidget)
		|| IsValid(InteractionWidget)
		)
	{
		if (bShowMouseCursor==false)
		{
			//ToggleCursorandFocus(true);
			bShowMouseCursor = true;
			UWidgetBlueprintLibrary::SetInputMode_GameAndUI(this, nullptr, false, false);
		}
	}
	else
	{
		if (bShowMouseCursor == true)
		{
			bShowMouseCursor = false;
			UWidgetBlueprintLibrary::SetInputMode_GameOnly(this);
		}		
	}
}

bool AEXWPlayerController::CheckIfAnyUIHovered()
{
	if (
		(IsValid(InventoryMenuWidget) && InventoryMenuWidget->IsHovered())
		|| (IsValid(ShopMenuWidget) && ShopMenuWidget->IsHovered())
		|| (IsValid(CraftMenuWidget) && CraftMenuWidget->IsHovered())
		|| (IsValid(LifeSkillMenuWidget) && LifeSkillMenuWidget->IsHovered())
		|| (IsValid(StatsMenuWidget) && StatsMenuWidget->IsHovered())
		|| (IsValid(PartyInfoWidget) && PartyInfoWidget->IsHovered())
		|| (IsValid(PartyMenuWidget) && PartyMenuWidget->IsHovered())
		|| (IsValid(AbilitiesMenuWidget) && AbilitiesMenuWidget->IsHovered())
		|| (IsValid(AbilityTreeMenuWidget) && AbilitiesMenuWidget->IsHovered())
		|| (IsValid(InteractionWidget) && InteractionWidget->IsHovered())
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

UEXWSharedWidget* AEXWPlayerController::CreateSharedWidget(TSubclassOf<UEXWSharedWidget> SharedWidgetClass, AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const bool bInitialize /*= true*/)
{
	if (SharedWidgetClass && SourceCharacter && TargetCharacter)
	{
		if (UEXWSharedWidget* SharedWidgetInstance = CreateWidget<UEXWSharedWidget>(this, SharedWidgetClass))
		{
			if (bInitialize)
			{
				SharedWidgetInstance->InitializeWidget(SourceCharacter, TargetCharacter);
			}
			return SharedWidgetInstance;
		}
	}
	UE_LOG(EXWCtrlLog, Warning, TEXT("Error Creating Shared Widget. Could be the class or one of the characters is null."));
	return nullptr;
}

UEXWSharedWidget* AEXWPlayerController::CreateShopWidget(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter)
{
	if (TSubclassOf<UEXWSharedWidget> ShopWidgetClass = UEXWDataLibrary::GetShopWidgetClass())
	{
		return	CreateSharedWidget(ShopWidgetClass, SourceCharacter, TargetCharacter, true);
	}
	UE_LOG(EXWCtrlLog, Warning, TEXT("Error creating shop widget, make sure you the TradeWidgetClass is set in the singleton."));
	return nullptr;
}

UEXWSharedWidget* AEXWPlayerController::CreateTradeWidget(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter)
{
	if (TSubclassOf<UEXWSharedWidget> TradeWidgetClass = UEXWDataLibrary::GetTradeWidgetClass())
	{
		return	CreateSharedWidget(TradeWidgetClass, SourceCharacter, TargetCharacter, true);
	}
	UE_LOG(EXWCtrlLog, Warning, TEXT("Error creating trade widget, make sure you the TradeWidgetClass is set in the singleton."));
	return nullptr;
}


UEXWFloatingWidget* AEXWPlayerController::CreateFloatingWidget(TSubclassOf<UEXWFloatingWidget> FloatingWidgetClass)
{
	if (FloatingWidgetClass)
	{
		if (UEXWFloatingWidget* FloatingWidget = CreateWidget<UEXWFloatingWidget>(this, FloatingWidgetClass))
		{
			return FloatingWidget;
		}
	}
	UE_LOG(EXWCtrlLog, Warning, TEXT("Error Creating Shared Widget (Class NULL)."));
	return nullptr;
}

UEXWFloatingWidget* AEXWPlayerController::CreateFloatingTextWidget(AEXWCharacter* TargetCharacter, const float Value, const EEXWAttributeEffectType AttributeEffectType, const bool bIsCritical /*= false*/)
{
	if (TSubclassOf<UEXWFloatingWidget> FloatingWidgetClass = UEXWDataLibrary::GetFloatingTextWidgetClass())
	{
		if (UEXWFloatingWidget* FloatingWidget = CreateFloatingWidget(FloatingWidgetClass))
		{
			FVector2D OutScreenPosition;
			if (UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition(this, TargetCharacter->GetActorLocation(), OutScreenPosition, false))
			{
				FloatingWidget->TextToDisplay = FText::FromString(FString::SanitizeFloat(Value));
				FloatingWidget->TextColor = UEXWDataLibrary::GetFloatingTextColor(AttributeEffectType);
				UE_LOG(LogTemp, Warning, TEXT("%s"), *FloatingWidget->TextColor.ToString());
				FloatingWidget->SetPositionInViewport(FVector2D(OutScreenPosition.X, OutScreenPosition.Y - 100.f), false);
				return FloatingWidget;
			}
		}
	}
	UE_LOG(EXWCtrlLog, Warning, TEXT("Error creating floating text widget, make sure you the FloatingTextWidgetClass is set in the singleton."));
	return nullptr;
}

UEXWScreenMessageWidget* AEXWPlayerController::CreateScreenMessageWidget(const EEXWScreenMessageType ScreenMessageType)
{
	if (FEXWScreenMessageData* ScreenMessageData = UEXWDataLibrary::GetScreenMessageData(ScreenMessageType))
	{
		if (UEXWScreenMessageWidget* ScreenMessageWidgetObj = CreateWidget<UEXWScreenMessageWidget>(this, ScreenMessageData->ScreenMessageWidgetClass))
		{
			ScreenMessageWidgetObj->ScreenMessageData = *ScreenMessageData;
			return ScreenMessageWidgetObj;
		}
	}
	return nullptr;
}



void AEXWPlayerController::OnRestartPawn(APawn* NewPawn)
{
	PossessedCharacter = Cast<AALSBaseCharacter>(NewPawn);
	check(PossessedCharacter);

	//Call "OnPossess" in Player Camera Manager when possessing a pawn
	AALSPlayerCameraManager* CastedMgr = Cast<AALSPlayerCameraManager>(PlayerCameraManager);
	if (CastedMgr)
	{
		CastedMgr->OnPossess(PossessedCharacter);
	}
}


void AEXWPlayerController::RequestRespawnPawn(bool UseRespawnPoint)
{
	PossessedCharacter->ReplicatedRagdollEnd();

	FVector Location;
	FRotator Rotation;
	UEXWDataLibrary::GetClosestRespawnPointLocationAndRotation(PossessedCharacter,Location, Rotation );
	PossessedCharacter->Respawn(Location, Rotation);
	EnableInput(this);

}


//chat
UChatComponent* AEXWPlayerController::GetChatComponent()
{
	return ChatComponent;
}

//SpatialOS
void AEXWPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;

}

void AEXWPlayerController::EndPlay(const EEndPlayReason::Type Reason)
{
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	Super::EndPlay(Reason);
}



void AEXWPlayerController::JoinSpatialDeployment(const FString& LoginToken, const FString& PIT)
{
	FURL TravelURL;
	TravelURL.Host = TEXT("locator.improbable.io");
	TravelURL.AddOption(TEXT("locator"));
	TravelURL.AddOption(*FString::Printf(TEXT("playeridentity=%s"), *PIT));
	TravelURL.AddOption(*FString::Printf(TEXT("login=%s"), *LoginToken));

	//OnLoadingStarted.Broadcast();

	ClientTravel(TravelURL.ToString(), TRAVEL_Absolute, false);
}

void AEXWPlayerController::DisplayScreenMessage(const EEXWScreenMessageType ScreenMessageType)
{
	TArray<UUserWidget*> PreviousWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(this, PreviousWidgets, UEXWScreenMessageWidget::StaticClass(), false);
	for (UUserWidget* Widget : PreviousWidgets)
	{
		Widget->RemoveFromParent();
	}
	if (UEXWScreenMessageWidget* ScreenMessageWidgetObj = CreateScreenMessageWidget(ScreenMessageType))
	{
		ScreenMessageWidgetObj->AddToViewport();
	}
}

void AEXWPlayerController::DisplayToggleGatheringProgress_Implementation(bool Isstart, EEXWLifeSkillType Type, float Timer)
{
}

void AEXWPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	Client_Initialize();
	bShowMouseCursor = true;
	SetInputMode(FInputModeGameAndUI());
}

void AEXWPlayerController::Client_Initialize_Implementation()
{
	//First create the HUD
	if (IsValid(HUDLayoutWidgetClass))
	{
		HUDLayoutWidget = CreateWidget(this, HUDLayoutWidgetClass);
		HUDLayoutWidget->AddToViewport();
	}

	// CHAT UI
	if (IsValid(ChatWidgetClass))
	{
		ChatWidget = CreateWidget(this, ChatWidgetClass);
		ChatWidget->AddToViewport();
		ChatWidget->SetPositionInViewport(ChatWidgetPosition, false);
		ChatWidget->SetDesiredSizeInViewport(ChatWidgetSize);
	}

	// Create Notifications UI
	if (IsValid(NotificationsWidgetClass))
	{
		NotificationsWidget = CreateWidget(this, NotificationsWidgetClass);
		NotificationsWidget->AddToViewport();
		NotificationsWidget->SetPositionInViewport(NotificationsWidgetPosition, false);
	}
	// Life Skill Progression UI
	if (IsValid(LifeSkillProgressWidgetClass))
	{
		LifeSkillProgressWidget = CreateWidget(this, LifeSkillProgressWidgetClass);
		LifeSkillProgressWidget->AddToViewport();
		LifeSkillProgressWidget->SetPositionInViewport(LifeSkillProgressWidgetPosition, false);
	}
}

void AEXWPlayerController::TogglePartyMenu()
{
	if (IsValid(PartyMenuWidgetClass))
	{
		if (IsValid(PartyMenuWidget))
		{
			PartyMenuWidget->RemoveFromParent();
			PartyMenuWidget = nullptr;
		}
		else {
			PartyMenuWidget = CreateWidget(this, PartyMenuWidgetClass);
			PartyMenuWidget->AddToViewport();
			PartyMenuWidget->SetPositionInViewport(PartyMenuWidgetPosition, false);
		}
		CheckIfNoUIOpen();
	}
	
}

void AEXWPlayerController::ToggleInteractMenu(AActor* InteractableActor)
{
	if (CheckIfAnyUIHovered())
	{
		return;
	}
	if (IsValid(InteractionWidgetClass))
	{
		if (IsValid(InteractionWidget))
		{
			InteractionWidget->RemoveFromParent();
			InteractionWidget = nullptr;

			if (InteractableActor!=nullptr)
			{
				InteractionWidget = Cast<UEXWSharedWidget>(CreateWidget(this, InteractionWidgetClass));
				InteractionWidget->SetPositionInViewport(InteractWidgetPosition, false);
				InteractionWidget->Interactable=InteractableActor;
				InteractionWidget->AddToViewport();
			}
		}
		else 
		{
			if (InteractableActor!=nullptr)
			{
				InteractionWidget = Cast<UEXWSharedWidget>(CreateWidget(this, InteractionWidgetClass));
				InteractionWidget->SetPositionInViewport(InteractWidgetPosition, true);
				InteractionWidget->Interactable=InteractableActor;
				InteractionWidget->AddToViewport();
			}
		}
		CheckIfNoUIOpen();
	}
}

void AEXWPlayerController::ToggleAbilitiesMenu()
{
	if (IsValid(AbilitiesMenuWidgetClass))
	{
		if (IsValid(AbilitiesMenuWidget))
		{
			AbilitiesMenuWidget->RemoveFromParent();
			AbilitiesMenuWidget = nullptr;
		}
		else {
			AbilitiesMenuWidget = CreateWidget(this, AbilitiesMenuWidgetClass);
			AbilitiesMenuWidget->AddToViewport();
			AbilitiesMenuWidget->SetPositionInViewport(AbilitiesMenuWidgetPosition, false);
		}
		CheckIfNoUIOpen();
	}
}

void AEXWPlayerController::ToggleAbilityTreeMenu()
{
	if (IsValid(AbilityTreeMenuWidgetClass))
	{
		if (IsValid(AbilityTreeMenuWidget))
		{
			AbilityTreeMenuWidget->RemoveFromParent();
			AbilityTreeMenuWidget = nullptr;
		}
		else {
			AbilityTreeMenuWidget = CreateWidget(this, AbilityTreeMenuWidgetClass);
			AbilityTreeMenuWidget->AddToViewport();
			AbilityTreeMenuWidget->SetPositionInViewport(AbilityTreeMenuWidgetPosition, false);
		}
		CheckIfNoUIOpen();
	}
}

void AEXWPlayerController::ToggleStatsMenu()
{
	if (IsValid(StatsMenuWidgetClass))
	{
		if (IsValid(StatsMenuWidget))
		{
			StatsMenuWidget->RemoveFromParent();
			StatsMenuWidget = nullptr;
		} 
		else
		{
			StatsMenuWidget = CreateWidget(this, StatsMenuWidgetClass);
			StatsMenuWidget->AddToViewport();
			StatsMenuWidget->SetPositionInViewport(StatsMenuWidgetPosition, false);
		}
		CheckIfNoUIOpen();
	}
}

void AEXWPlayerController::ToggleCraftMenu()
{
	if (IsValid(CraftMenuWidgetClass))
	{
		if (IsValid(CraftMenuWidget))
		{
			CraftMenuWidget->RemoveFromParent();
			CraftMenuWidget = nullptr;
		} 
		else
		{
			CraftMenuWidget = CreateWidget<UEXWCraftWidget>(this, CraftMenuWidgetClass);
			CraftMenuWidget->AddToViewport();
			CraftMenuWidget->SetPositionInViewport(CraftMenuWidgetPosition, false);
		}
		CheckIfNoUIOpen();
	}
}

void AEXWPlayerController::CreateCraftMenu(AEXWPlaceableCraftStation* CraftStation, EEXWCraftCategory Category /*= EEXWCraftCategory::CC_Alchemy*/)
{
	if (IsValid(CraftMenuWidgetClass))
	{
		if (IsValid(CraftMenuWidget))
		{
			CraftMenuWidget->RemoveFromParent();
			CraftMenuWidget = nullptr;
		}
		else
		{
			CraftMenuWidget = CreateWidget<UEXWCraftWidget>(this, CraftMenuWidgetClass);
			CraftMenuWidget->CraftCategory = Category;
			CraftMenuWidget->CraftStation = CraftStation;

			CraftMenuWidget->AddToViewport();
			CraftMenuWidget->SetPositionInViewport(CraftMenuWidgetPosition, false);
			CraftMenuWidget->InitCraftWidget();
		}
		CheckIfNoUIOpen();
	}
}

void AEXWPlayerController::ToggleLifeSkillMenu()
{
	if (IsValid(LifeSkillMenuWidgetClass))
	{
		if (IsValid(LifeSkillMenuWidget))
		{
			LifeSkillMenuWidget->RemoveFromParent();
			LifeSkillMenuWidget = nullptr;
		}
		else
		{
			LifeSkillMenuWidget = CreateWidget(this, LifeSkillMenuWidgetClass);
			LifeSkillMenuWidget->AddToViewport();
			LifeSkillMenuWidget->SetPositionInViewport(LifeSkillMenuWidgetPosition, false);
		}
		CheckIfNoUIOpen();
	}
}

void AEXWPlayerController::ToggleInventoryMenu()
{
	if (IsValid(InventoryMenuWidgetClass))
	{
		if (IsValid(InventoryMenuWidget))
		{
			InventoryMenuWidget->RemoveFromParent();
			InventoryMenuWidget = nullptr;
		}
		else
		{
			InventoryMenuWidget = CreateWidget(this, InventoryMenuWidgetClass);
			InventoryMenuWidget->AddToViewport();
			InventoryMenuWidget->SetPositionInViewport(InventoryMenuWidgetPosition, false);
		}
		CheckIfNoUIOpen();
	}
}

void AEXWPlayerController::ToggleShopMenu()
{
	if (IsValid(ShopMenuWidgetClass))
	{
		if (IsValid(ShopMenuWidget))
		{
			ShopMenuWidget->RemoveFromParent();
			ShopMenuWidget = nullptr;
		}
		else
		{
			ShopMenuWidget = CreateWidget(this, ShopMenuWidgetClass);
			ShopMenuWidget->AddToViewport();
			ShopMenuWidget->SetPositionInViewport(ShopMenuWidgetPosition, false);
		}
		CheckIfNoUIOpen();
	}
}

void AEXWPlayerController::ToggleCreateParty()
{
	if (AEXWorldCombatPlayerState* PlayerState = GetPlayerState<AEXWorldCombatPlayerState>())
	{
		if (PlayerState->CurrentParty.ID != "-1")
		{
			UE_LOG(EXWCtrlLog, Warning, TEXT("Already in Party!"));

			if (IsValid(CreatePartyWidget))
			{
				CreatePartyWidget->RemoveFromParent();
				CreatePartyWidget = nullptr;
				CheckIfNoUIOpen();
			}

			return;
		}
		if (IsValid(CreatePartyWidgetClass))
		{
			if (IsValid(CreatePartyWidget))
			{
				CreatePartyWidget->RemoveFromParent();
				CreatePartyWidget = nullptr;
			}
			else
			{
				CreatePartyWidget = CreateWidget(this, CreatePartyWidgetClass);
				CreatePartyWidget->AddToViewport();
				CreatePartyWidget->SetPositionInViewport(CreatePartyWidgetPosition, false);
			}
			CheckIfNoUIOpen();
		}
	}
}

void AEXWPlayerController::ToggleInviteToParty()
{
	if (AEXWorldCombatPlayerState* PlayerState = GetPlayerState<AEXWorldCombatPlayerState>())
	{
		if (PlayerState->CurrentParty.ID == "-1")
		{
			UE_LOG(EXWCtrlLog, Warning, TEXT("No Party!"));
			
			if (IsValid(InviteToPartyWidget))
			{
				InviteToPartyWidget->RemoveFromParent();
				InviteToPartyWidget = nullptr;
				CheckIfNoUIOpen();
			}

			return;
		}
		bool bIsAdmin = false;

		if (AEXWCharacter* PlayerPawn = GetPawn<AEXWCharacter>())
		{
			for (FEXWPartyMember Member : PlayerState->CurrentParty.Members)
			{
				if (Member.Role == EEXWPartyMemberRoles::PMR_Admin && Member.Character == PlayerPawn)
				{
					bIsAdmin = true;
				}
			}
		}

		if (bIsAdmin)
		{
			if (IsValid(InviteToPartyWidgetClass))
			{
				if (IsValid(InviteToPartyWidget))
				{
					InviteToPartyWidget->RemoveFromParent();
					InviteToPartyWidget = nullptr;
				}
				else
				{
					InviteToPartyWidget = CreateWidget(this, InviteToPartyWidgetClass);
					InviteToPartyWidget->AddToViewport();
					InviteToPartyWidget->SetPositionInViewport(InviteToPartyWidgetPosition, false);
				}
				CheckIfNoUIOpen();
			}
		}
	}
}

void AEXWPlayerController::ToggleRemoveParty()
{
	if (AEXWorldCombatPlayerState* PlayerState = GetPlayerState<AEXWorldCombatPlayerState>())
	{
		if (PlayerState->CurrentParty.ID == "-1")
		{
			UE_LOG(EXWCtrlLog, Warning, TEXT("No Party!"));
			
			if (IsValid(RemovePartyWidget))
			{
				RemovePartyWidget->RemoveFromParent();
				RemovePartyWidget = nullptr;
				CheckIfNoUIOpen();
			}
			
			return;
		}
		bool bIsAdmin = false;

		if (AEXWCharacter* PlayerPawn = GetPawn<AEXWCharacter>())
		{
			for (FEXWPartyMember Member : PlayerState->CurrentParty.Members)
			{
				if (Member.Role == EEXWPartyMemberRoles::PMR_Admin && Member.Character == PlayerPawn)
				{
					bIsAdmin = true;
				}
			}
		}

		if (bIsAdmin)
		{
			if (IsValid(RemovePartyWidgetClass))
			{
				if (IsValid(RemovePartyWidget))
				{
					RemovePartyWidget->RemoveFromParent();
					RemovePartyWidget = nullptr;
				}
				else
				{
					RemovePartyWidget = CreateWidget(this, RemovePartyWidgetClass);
					RemovePartyWidget->AddToViewport();
					RemovePartyWidget->SetPositionInViewport(RemovePartyWidgetPosition, false);
				}
				CheckIfNoUIOpen();
			}
		}
	}
}

void AEXWPlayerController::ToggleLeaveParty()
{
	if (AEXWorldCombatPlayerState* PlayerState = GetPlayerState<AEXWorldCombatPlayerState>())
	{
		if (PlayerState->CurrentParty.ID == "-1")
		{
			UE_LOG(EXWCtrlLog, Warning, TEXT("No Party!"));

			if (IsValid(LeavePartyWidget))
			{
				LeavePartyWidget->RemoveFromParent();
				LeavePartyWidget = nullptr;
				CheckIfNoUIOpen();
			}

			return;
		}
		if (IsValid(LeavePartyWidgetClass))
		{
			if (IsValid(LeavePartyWidget))
			{
				LeavePartyWidget->RemoveFromParent();
				LeavePartyWidget = nullptr;
			}
			else
			{
				LeavePartyWidget = CreateWidget(this, LeavePartyWidgetClass);
				LeavePartyWidget->AddToViewport();
				LeavePartyWidget->SetPositionInViewport(LeavePartyWidgetPosition, false);
			}
			CheckIfNoUIOpen();
		}
	}
}

void AEXWPlayerController::ToggleKickParty()
{
	if (AEXWorldCombatPlayerState* PlayerState = GetPlayerState<AEXWorldCombatPlayerState>())
	{
		if (PlayerState->CurrentParty.ID == "-1")
		{
			UE_LOG(EXWCtrlLog, Warning, TEXT("No Party!"));

			if (IsValid(KickPartyWidget))
			{
				KickPartyWidget->RemoveFromParent();
				KickPartyWidget = nullptr;
				CheckIfNoUIOpen();
			}

			return;
		}
		bool bIsAdmin = false;

		if (AEXWCharacter* PlayerPawn = GetPawn<AEXWCharacter>())
		{
			for (FEXWPartyMember Member : PlayerState->CurrentParty.Members)
			{
				if (Member.Role == EEXWPartyMemberRoles::PMR_Admin && Member.Character == PlayerPawn)
				{
					bIsAdmin = true;
				}
			}
		}

		if (bIsAdmin)
		{
			if (IsValid(KickPartyWidgetClass))
			{
				if (IsValid(KickPartyWidget))
				{
					KickPartyWidget->RemoveFromParent();
					KickPartyWidget = nullptr;
				}
				else
				{
					KickPartyWidget = CreateWidget(this, KickPartyWidgetClass);
					KickPartyWidget->AddToViewport();
					KickPartyWidget->SetPositionInViewport(KickPartyWidgetPosition, false);
				}
				CheckIfNoUIOpen();
			}
		}
	}
}

void AEXWPlayerController::TogglePartyInfo()
{
	if (IsValid(PartyInfoWidgetClass))
	{
		if (IsValid(PartyInfoWidget))
		{
			PartyInfoWidget->RemoveFromParent();
			PartyInfoWidget = nullptr;
		}
		else
		{
			PartyInfoWidget = CreateWidget(this, PartyInfoWidgetClass);
			PartyInfoWidget->AddToViewport();
			PartyInfoWidget->SetPositionInViewport(PartyInfoWidgetPosition, false);
		}
		CheckIfNoUIOpen();
	}
}


void AEXWPlayerController::DisplayDialogueUI(FName DialogueID)
{
	if (IsValid(DialogueWidgetClass))
	{
		if (IsValid(DialogueWidget))
		{
			DialogueWidget->RemoveFromParent();
			DialogueWidget = nullptr;
		}

		DialogueWidget = CreateWidget<UEXWDialogueWidget>(this, DialogueWidgetClass);
		DialogueWidget->DialogueID = DialogueID;
		
		DialogueWidget->AddToViewport();
		DialogueWidget->SetPositionInViewport(DialogueWidgetPosition);
		DialogueWidget->InitDialogue();
		//TODO SetInputTypeMode
	}
}

void AEXWPlayerController::DisplayNPCShopUI(FName NPCShopID, AEXWCharacter* ShopOwner)
{
	if (IsValid(NPCShopWidgetClass))
	{
		if (IsValid(NPCShopWidget))
		{
			NPCShopWidget->RemoveFromParent();
			NPCShopWidget = nullptr;
		}

		NPCShopWidget = CreateWidget<UEXWNPCShopWidget>(this, NPCShopWidgetClass);
		NPCShopWidget->ShopID = NPCShopID;
		NPCShopWidget->ShopOwner = ShopOwner;

		NPCShopWidget->AddToViewport();
		NPCShopWidget->SetPositionInViewport(NPCShopWidgetPosition);
		NPCShopWidget->InitShop();
		//TODO SetInputTypeMode
	}
}

void AEXWPlayerController::DisplayQuestPanelUI(FName QuestID)
{
	if (IsValid(QuestPanelWidgetClass))
	{
		if (IsValid(QuestPanelWidget))
		{
			QuestPanelWidget->RemoveFromParent();
			QuestPanelWidget = nullptr;
		}

		QuestPanelWidget = CreateWidget<UEXWQuestPanelWidget>(this, QuestPanelWidgetClass);
		QuestPanelWidget->QuestID = QuestID;

		QuestPanelWidget->AddToViewport();
		QuestPanelWidget->SetPositionInViewport(QuestPanelWidgetPosition);
		QuestPanelWidget->InitQuestPanel();
		//TODO SetInputTypeMode
	}
}

void AEXWPlayerController::ToggleQuestJournalUI()
{
	if (IsValid(QuestJournalWidgetClass))
	{
		if (IsValid(QuestJournalWidget))
		{
			QuestJournalWidget->RemoveFromParent();
			QuestJournalWidget = nullptr;
		}
		else {
			QuestJournalWidget = CreateWidget(this, QuestJournalWidgetClass);
			QuestJournalWidget->AddToViewport();
			QuestJournalWidget->SetPositionInViewport(QuestJournalWidgetPosition);
		}
		
		
	}
}

void AEXWPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("TogglePartyMenu", IE_Pressed, this, &AEXWPlayerController::TogglePartyMenu);
	InputComponent->BindAction("ToggleAbilitiesMenu", IE_Pressed, this, &AEXWPlayerController::ToggleAbilitiesMenu);
	InputComponent->BindAction("ToggleAbilityTreeMenu", IE_Pressed, this, &AEXWPlayerController::ToggleAbilityTreeMenu);
	InputComponent->BindAction("ToggleStatsMenu", IE_Pressed, this, &AEXWPlayerController::ToggleStatsMenu);
	InputComponent->BindAction("ToggleCraftMenu", IE_Pressed, this, &AEXWPlayerController::ToggleCraftMenu);
	InputComponent->BindAction("ToggleLifeSkillsMenu", IE_Pressed, this, &AEXWPlayerController::ToggleLifeSkillMenu);
	InputComponent->BindAction("ToggleInventoryMenu", IE_Pressed, this, &AEXWPlayerController::ToggleInventoryMenu);
	InputComponent->BindAction("ToggleShopMenu", IE_Pressed, this, &AEXWPlayerController::ToggleShopMenu);
	InputComponent->BindAction("ToggleQuestJournal", IE_Pressed, this, &AEXWPlayerController::ToggleQuestJournalUI);
}

