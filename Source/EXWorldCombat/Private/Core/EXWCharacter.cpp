// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

// Base Class
#include "Core/EXWCharacter.h"
// Kismet Libs
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
// General Engine Tools
#include "Widgets/EXWFloatingWidget.h"
#include "Net/UnrealNetwork.h"
#include "Engine/DataTable.h"
#include "DrawDebugHelpers.h"
#include "TimerManager.h"
#include "MeshReductionInterface/Public/IMeshReductionInterfaces.h"
#include "NiagaraFunctionLibrary.h"
// Components
#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
//Dependencies
#include "Core/EXWSkeletalMeshComponent.h"
#include "Core/EXWStatusEffect.h"
#include "Core/EXWSpawnableAbility.h"
#include "Core/EXWSpawnableAbilityIndicator.h"
#include "Core/EXWPlayerController.h"
#include "Core/Animation/EXWCharacterPose.h"
#include "Data/EXWProgressionLevelDA.h"
#include "Data/EXWSkillProgressionLevelDA.h"
#include "Library/EXWDataLibrary.h"
#include "Library/Inventory/EXWInventoryLibrary.h"
#include "Inventory/EXWItem.h"
#include "Inventory/EXWPlaceable.h"
#include "Inventory/EXWPlaceable_Gatherable.h"
#include "EXWorldCombatPlayerState.h"
// Damage Types
#include "Core/DamageTypes/EXWPhysicalDamageType.h"
#include "Core/DamageTypes/EXWMagicalDamageType.h"

#include "../../Public/Network/ExWorldGameState.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Placeables/EXWPlaceableCraftStation.h"

#define DUEL_FACTION 600

//General Character Log
DEFINE_LOG_CATEGORY(EXWCharLog);

AEXWCharacter::AEXWCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;
	bCanGainExperience = true;

	CreateDefaultAttributes();
	CreateDefaultStats();
	CreateDefaultDamageReductions();
	CreateDefaultDamageAbsorptions();
	CreateDefaultLifeSkills();
	CreateDefaultInventoryEquipment();
	CreateDefaultInventoryCosmeticEquipment();


	// Interaction widget details
	AvailableInteractionTypes = DefaultInteractionTypes;
	InteractionMaxDistance = 300.f;

	InteractionWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("Interaction Widget Component");
	if (InteractionWidgetComponent)
	{
		InteractionWidgetComponent->SetupAttachment(GetCapsuleComponent());
		InteractionWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
		InteractionWidgetComponent->SetVisibility(false, true);
		InteractionWidgetComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	}
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->CustomDepthStencilValue = 1;
	HeadMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("HeadMesh");
	if (HeadMesh)
	{
		HeadMesh->SetupAttachment(GetMesh());
		HeadMesh->SetMasterPoseComponent(GetMesh(), true);
		HeadMesh->SetRenderCustomDepth(true);
		HeadMesh->CustomDepthStencilValue = 1;
		HeadMesh->SetIsReplicated(true);
	}
	TorsoMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("TorsoMesh");
	if (TorsoMesh)
	{
		TorsoMesh->SetupAttachment(GetMesh());
		TorsoMesh->SetMasterPoseComponent(GetMesh(), true);
		TorsoMesh->SetRenderCustomDepth(true);
		TorsoMesh->CustomDepthStencilValue = 1;
		TorsoMesh->SetIsReplicated(true);
	}
	ArmsMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("ArmsMesh");
	if (ArmsMesh)
	{
		ArmsMesh->SetupAttachment(GetMesh());
		ArmsMesh->SetMasterPoseComponent(GetMesh(), true);
		ArmsMesh->SetRenderCustomDepth(true);
		ArmsMesh->CustomDepthStencilValue = 1;
		ArmsMesh->SetIsReplicated(true);
	}
	LegsMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("LegsMesh");
	if (LegsMesh)
	{
		LegsMesh->SetupAttachment(GetMesh());
		LegsMesh->SetMasterPoseComponent(GetMesh(), true);
		LegsMesh->SetRenderCustomDepth(true);
		LegsMesh->CustomDepthStencilValue = 1;
		LegsMesh->SetIsReplicated(true);
	}
	FeetMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("FeetMesh");
	if (FeetMesh)
	{
		FeetMesh->SetupAttachment(GetMesh());
		FeetMesh->SetMasterPoseComponent(GetMesh(), true);
		FeetMesh->SetRenderCustomDepth(true);
		FeetMesh->CustomDepthStencilValue = 1;
		FeetMesh->SetIsReplicated(true);
	}
	EyesMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("EyesMesh");
	if (EyesMesh)
	{
		EyesMesh->SetupAttachment(GetMesh());
		EyesMesh->SetMasterPoseComponent(GetMesh(), true);
		EyesMesh->SetRenderCustomDepth(true);
		EyesMesh->CustomDepthStencilValue = 1;
		EyesMesh->SetIsReplicated(true);
	}
	EyebrowsMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("EyebrowsMesh");
	if (EyebrowsMesh)
	{
		EyebrowsMesh->SetupAttachment(GetMesh());
		EyebrowsMesh->SetMasterPoseComponent(GetMesh(), true);
		EyebrowsMesh->SetRenderCustomDepth(true);
		EyebrowsMesh->CustomDepthStencilValue = 1;
		EyebrowsMesh->SetIsReplicated(true);
	}
	TeethMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("TeethMesh");
	if (TeethMesh)
	{
		TeethMesh->SetupAttachment(GetMesh());
		TeethMesh->SetMasterPoseComponent(GetMesh(), true);
		TeethMesh->SetRenderCustomDepth(true);
		TeethMesh->CustomDepthStencilValue = 1;
		TeethMesh->SetIsReplicated(true);
	}
	TongueMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("TongueMesh");
	if (TongueMesh)
	{
		TongueMesh->SetupAttachment(GetMesh());
		TongueMesh->SetMasterPoseComponent(GetMesh(), true);
		TongueMesh->SetRenderCustomDepth(true);
		TongueMesh->CustomDepthStencilValue = 1;
		TongueMesh->SetIsReplicated(true);
	}
	HairMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("HairMesh");
	if (HairMesh)
	{
		HairMesh->SetupAttachment(GetMesh(), "head");
		HairMesh->AddRelativeRotation(FRotator(-90.f, 0.f, 0.f));
		HairMesh->SetRenderCustomDepth(true);
		HairMesh->CustomDepthStencilValue = 1;
		HairMesh->SetIsReplicated(true);
	}
	RightHandWeaponMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("RightHandWeaponMesh");
	if (RightHandWeaponMesh)
	{
		RightHandWeaponMesh->SetupAttachment(GetMesh(), "WeaponAttachPoint_Hand_R");
		RightHandWeaponMesh->SetRenderCustomDepth(true);
		RightHandWeaponMesh->CustomDepthStencilValue = 1;
		RightHandWeaponMesh->SetIsReplicated(true);
	}
	LeftHandWeaponMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("LeftHandWeaponMesh");
	if (LeftHandWeaponMesh)
	{
		LeftHandWeaponMesh->SetupAttachment(GetMesh(), "WeaponAttachPoint_Hand_L");
		//LeftHandWeaponMesh->SetRelativeRotation(FRotator(-14.946011 ,-176.242401,176.450928));
		LeftHandWeaponMesh->SetRenderCustomDepth(true);
		LeftHandWeaponMesh->CustomDepthStencilValue = 1;
		LeftHandWeaponMesh->SetIsReplicated(true);
	}
}

void AEXWCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	InitializeCharacterData();
}

void AEXWCharacter::BeginPlay()
{
	Super::BeginPlay();
	// Initialize all the regeneration timer handles
	UpdateAllRegens();

	//Bind Required Delegates
	BindDelegates();

	// Interaction widget details
	AvailableInteractionTypes = DefaultInteractionTypes;
}

void AEXWCharacter::BindDelegates()
{
	this->OnItemEquipped.AddDynamic(this, &AEXWCharacter::Server_HandleOnItemEquipped);
	this->OnItemUnEquipped.AddDynamic(this, &AEXWCharacter::Server_HandleOnItemUnEquipped);
}

void AEXWCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// visual for player
	ProcessTargeting();
	ProcessGhostTrail();
}

void AEXWCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	/**
	 * General variables
	 */
	DOREPLIFETIME(AEXWCharacter, Name);
	DOREPLIFETIME(AEXWCharacter, Class);
	DOREPLIFETIME(AEXWCharacter, Race);
	DOREPLIFETIME(AEXWCharacter, Gender);
	DOREPLIFETIME(AEXWCharacter, MainAttribute);
	//DOREPLIFETIME_CONDITION(AEXWCharacter, Portrait, COND_SkipOwner);
	DOREPLIFETIME(AEXWCharacter, Portrait);
	DOREPLIFETIME(AEXWCharacter, UnspentLevelPoints);
	DOREPLIFETIME(AEXWCharacter, StatLevelPoints);
	DOREPLIFETIME(AEXWCharacter, Attributes);
	DOREPLIFETIME(AEXWCharacter, Stats);
	DOREPLIFETIME(AEXWCharacter, StateOverriders);
	DOREPLIFETIME(AEXWCharacter, AvailableActions);
	DOREPLIFETIME(AEXWCharacter, IFrameActions);
	DOREPLIFETIME_CONDITION(AEXWCharacter, LastActiveAction, COND_SkipOwner);
	DOREPLIFETIME(AEXWCharacter, AbilityPoints);
	DOREPLIFETIME(AEXWCharacter, DamageReductions);
	DOREPLIFETIME_CONDITION(AEXWCharacter, States, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(AEXWCharacter, CooldownStack, COND_SkipOwner);
	DOREPLIFETIME(AEXWCharacter, Faction);
	DOREPLIFETIME(AEXWCharacter, LifeSkills);
	DOREPLIFETIME(AEXWCharacter, ItemLevel);
	DOREPLIFETIME(AEXWCharacter, bWeaponEquipped);
	DOREPLIFETIME(AEXWCharacter, bIsInCombat);

	/**
	 * Level variables
	 */
	DOREPLIFETIME(AEXWCharacter, ProgressionLevel);
	DOREPLIFETIME(AEXWCharacter, ProgressionExperience);

	/**
	 * Status effect variables
	 */

	DOREPLIFETIME(AEXWCharacter, ActiveStatusEffects);

	/**
	 * Inventory
	 */
	DOREPLIFETIME(AEXWCharacter, Inventory);
	DOREPLIFETIME(AEXWCharacter, InventoryEquipment);
	DOREPLIFETIME(AEXWCharacter, InventoryCosmeticEquipment);
	DOREPLIFETIME(AEXWCharacter, InventoryShop);
	DOREPLIFETIME(AEXWCharacter, InventoryTrade);

	/**
	 * Interaction
	 */
	DOREPLIFETIME(AEXWCharacter, bIsDueling);
	DOREPLIFETIME(AEXWCharacter, bIsTrading);

	/**
	 * Cosmetics
	 */
	DOREPLIFETIME(AEXWCharacter, HeadName);
	DOREPLIFETIME(AEXWCharacter, HairName);
	DOREPLIFETIME(AEXWCharacter, HairColorName);
	DOREPLIFETIME(AEXWCharacter, ArmsName);
	DOREPLIFETIME(AEXWCharacter, BodyName);
	DOREPLIFETIME(AEXWCharacter, TorsoName);
	DOREPLIFETIME(AEXWCharacter, EyesName);
	DOREPLIFETIME(AEXWCharacter, EyeColorName);
	DOREPLIFETIME(AEXWCharacter, FaceName);
	DOREPLIFETIME(AEXWCharacter, LegsName);
	DOREPLIFETIME(AEXWCharacter, FeetName);
	DOREPLIFETIME(AEXWCharacter, SkinName);
	DOREPLIFETIME(AEXWCharacter, RightHandWeapon);
	DOREPLIFETIME(AEXWCharacter, RightHandWeaponOffset);
	DOREPLIFETIME(AEXWCharacter, LeftHandWeapon);
	DOREPLIFETIME(AEXWCharacter, LeftHandWeaponOffset);

	/**
	 * Affected Characters
	 */
	 DOREPLIFETIME(AEXWCharacter, LastCharacterAffected);
	 DOREPLIFETIME(AEXWCharacter, LastCharacterAffectedBy);

	 /**
	  * Shop
	  */
	DOREPLIFETIME(AEXWCharacter, bIsVending);

}

void AEXWCharacter::UnPossessed()
{
	if (UWorld* World = GetWorld())
	{
		GetWorldTimerManager().ClearTimer(InCombatTimerHandle);
	}
	Super::UnPossessed();
}


void AEXWCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_1", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 0);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_2", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 1);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_3", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 2);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_4", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 3);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_5", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 4);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_6", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 5);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_7", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 6);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_8", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 7);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_9", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 8);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_10", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 9);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_11", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 10);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("Ability_12", IE_Pressed, this, &AEXWCharacter::ExecuteActionFullByIndex, 11);

	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("IFrameAbility_1", IE_Pressed, this, &AEXWCharacter::ExecuteIFrameActionFullByIndex, 0);
	PlayerInputComponent->BindAction<FInputExecuteActionDelegate>("IFrameAbility_2", IE_Pressed, this, &AEXWCharacter::ExecuteIFrameActionFullByIndex, 1);

	
	PlayerInputComponent->BindAction("StartTargeting", IE_Pressed, this, &AEXWCharacter::StartDefaultTargeting);
	PlayerInputComponent->BindAction<FInputTargetingStopDelegate>("StartTargeting", IE_Released, this, &AEXWCharacter::CleanUpActionExecution, true);
}

void AEXWCharacter::InitializeCharacterData()
{
	// Update Stats (Base from level -> Items -> Passives -> Buffs (from cached stack))
	UpdateStatsFromLevelModifier();
	UpdateStatsFromItems();

	// Calculate and Update Attributes
	UpdateAttributesFromStats();
	UpdateAttributesFromItems();

	// Calling event
	OnInitializeCharacterData_Native();
}

void AEXWCharacter::Server_InitializeCharacterData_Implementation()
{
	InitializeCharacterData();
}

void AEXWCharacter::OnInitializeCharacterData_Native()
{
	OnInitializeCharacterData();
}

void AEXWCharacter::Multicast_DisableInput_Implementation()
{
	DisableInput(UGameplayStatics::GetPlayerController(this, 0));
}

void AEXWCharacter::Multicast_EnableInput_Implementation()
{
	EnableInput(UGameplayStatics::GetPlayerController(this, 0));
}

void AEXWCharacter::Respawn(const FVector NewLocation /*= FVector::ZeroVector*/, const FRotator NewRotation /*= FRotator(ForceInit)*/, bool bUseRespawnPoint)
{
	Replicated_SetActorLocationAndRotation(NewLocation, NewRotation);
	Server_OnRespawn(bUseRespawnPoint);
	ClearStates();
	ClearStateOverriders();
	OnRespawn_Native();
	AddState(EEXWState::S_Invulnerable);
	RemoveState(EEXWState::S_Dead);

	FTimerDelegate InvulnerabilityTimerDelegate; 
	InvulnerabilityTimerDelegate.BindUFunction(this, "RemoveState", EEXWState::S_Invulnerable);
	GetWorld()->GetTimerManager().SetTimer(InvulnerabilityTimerHandle, InvulnerabilityTimerDelegate, RespawnInvulnerabilityDuration, false);
	
	OnCharacterRespawn.Broadcast();

	if (CurrentItemSet.ID != "None")
	{
		FEXWItemSetEventEffect* OnRespawnParticles = CurrentItemSet.EventEffects.Find(EEXWItemSetEvent::ISE_OnRespawn);
		if (OnRespawnParticles)
		{
			Multicast_PlayParticles(OnRespawnParticles->Effect, OnRespawnParticles->BoneName);
		}

	}
}

void AEXWCharacter::Multicast_Respawn_Implementation(const FVector NewLocation /*= FVector::ZeroVector*/, const FRotator NewRotation /*= FRotator(ForceInit)*/, bool bUseRespawnPoint /*= false*/)
{
	Respawn(NewLocation, NewRotation, bUseRespawnPoint);
}

void AEXWCharacter::Server_OnRespawn_Implementation(bool bUseRespawnPoint)
{
	Server_InitializeCharacterData();
	if (GetMesh() && ParticleSystemOnRespawn && bUseRespawnPoint)
	{
		Multicast_SpawnNiagraAttached(ParticleSystemOnRespawn, GetMesh(), "None", FVector(0, 0, 0), FRotator(0, 0, 0), EAttachLocation::KeepRelativeOffset);
	}
	else if (GetMesh() && ParticleSystemOnRevive && !bUseRespawnPoint)
	{
		Multicast_SpawnNiagraAttached(ParticleSystemOnRevive, GetMesh(), "None", FVector(0, 0, 0), FRotator(0, 0, 0), EAttachLocation::KeepRelativeOffset);
	}
	//TODO: Move this into its proper function
	for (FEXWAction Action : AvailableActions)
	{
		if (Action.bIsPassive)
		{
			Server_ConstructStatusEffect(Action.StatusEffect, this, this);
		}
	}
}

void AEXWCharacter::OnRespawn_Native()
{
	UpdateAllRegens();
	OnRespawn();
}

bool AEXWCharacter::ExistsInWeakObjPtrCharacterArray(TArray<TWeakObjectPtr<AEXWCharacter>> CharacterArray)
{
	return UEXWDataLibrary::ExistsInWeakObjPtrCharacterArray(CharacterArray, this);
}

void AEXWCharacter::OnCharacterDataLoaded_Implementation()
{
}

void AEXWCharacter::OnCharacterLoadComplete()
{
	OnCharacterLoaded.Broadcast();
	if (CurrentItemSet.ID != "None")
	{
		FEXWItemSetEventEffect* OnCharacterLoadParticles = CurrentItemSet.EventEffects.Find(EEXWItemSetEvent::ISE_OnLogin);
		if (OnCharacterLoadParticles)
		{
			Multicast_PlayParticles(OnCharacterLoadParticles->Effect, OnCharacterLoadParticles->BoneName);
		}

	}
}

void AEXWCharacter::Replicated_SetActorLocationAndRotation(const FVector NewLocation /*= FVector::ZeroVector*/, const FRotator NewRotation /*= FRotator(ForceInit)*/)
{
	if (IsLocallyControlled())
	{
		SetActorLocationAndRotation(NewLocation, NewRotation);
	}
	Server_SetActorLocationAndRotation(NewLocation, NewRotation);
}

void AEXWCharacter::Server_SetActorLocationAndRotation_Implementation(const FVector NewLocation /*= FVector::ZeroVector*/, const FRotator NewRotation /*= FRotator(ForceInit)*/)
{
	Multicast_SetActorLocationAndRotation(NewLocation, NewRotation);
}

void AEXWCharacter::Multicast_SetActorLocationAndRotation_Implementation(const FVector NewLocation /*= FVector::ZeroVector*/, const FRotator NewRotation /*= FRotator(ForceInit)*/)
{
	if (!IsLocallyControlled())
	{
		SetActorLocationAndRotation(NewLocation, NewRotation);
	}
}

void AEXWCharacter::Client_SetActorLocationAndRotation_Implementation(const FVector NewLocation /*= FVector::ZeroVector*/, const FRotator NewRotation /*= FRotator(ForceInit)*/)
{
	SetActorLocationAndRotation(NewLocation, NewRotation);
}

FTransform AEXWCharacter::GetSocketTransform(const FName SocketName /*= "spine_02"*/)
{
	if (USkeletalMeshComponent* MeshComp = GetMesh())
	{
		return (MeshComp->DoesSocketExist(SocketName)) ? MeshComp->GetSocketTransform(SocketName) : MeshComp->GetComponentTransform();
	}
	return GetActorTransform();
}

FVector AEXWCharacter::GetClosestGroundToCrosshair(const float Distance /*= 2000.f*/, const bool bDebug /*= false*/)
{
	FHitResult CrosshairOutHit;
	FVector Direction;

	TArray <TEnumAsByte<ECollisionChannel>> CollisionChannels = { ECC_WorldStatic };
	if (CrosshairTrace(CrosshairOutHit, Direction, CollisionChannels, Distance, bDebug))
	{
		if (CrosshairOutHit.ImpactPoint.Z < GetActorLocation().Z + GetCapsuleComponent()->GetScaledCapsuleHalfHeight())
		{
			return CrosshairOutHit.ImpactPoint;
		}

	}
	else if (UWorld* World = GetWorld())
	{
		FHitResult GroundOutHit;
		FVector GroundPosition = FVector(CrosshairOutHit.TraceEnd.X, CrosshairOutHit.TraceEnd.Y, CrosshairOutHit.TraceEnd.Z - 3500);
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
		if (World->LineTraceSingleByObjectType(GroundOutHit, CrosshairOutHit.TraceEnd, GroundPosition, ECC_WorldStatic, CollisionParams))
		{

			if (bDebug)
				DrawDebugLine(World, CrosshairOutHit.TraceEnd, GroundPosition, FColor::Red, false, 1, 0, 1);
			if (GroundOutHit.ImpactPoint.Z < GetActorLocation().Z + GetCapsuleComponent()->GetScaledCapsuleHalfHeight())
			{
				return GroundOutHit.ImpactPoint;
			}
			return GroundOutHit.ImpactPoint;
		}
	}
	return GetActorLocation();
}

FVector AEXWCharacter::GetClosestGroundToCharacter(const float Distance /*= 2000.f*/, const bool bDebug /*= false*/)
{
	if (UWorld* World = GetWorld())
	{
		FHitResult ForwardOutHit;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
		FVector StartPos = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 80.f);
		FVector EndPos = GetActorForwardVector() * Distance + StartPos;
		if (World->LineTraceSingleByObjectType(ForwardOutHit, StartPos, EndPos, ECC_WorldStatic, CollisionParams))
		{
			if (bDebug)
			{
				DrawDebugLine(World, StartPos, EndPos, FColor::Red, false, 1, 0, 1);
			}
			return ForwardOutHit.ImpactPoint;
		}
		else
		{
			FHitResult GroundOutHit;
			FVector GroundPosition = FVector(ForwardOutHit.TraceEnd.X, ForwardOutHit.TraceEnd.Y, ForwardOutHit.TraceEnd.Z - 3500);
			CollisionParams.AddIgnoredActor(this);
			if (World->LineTraceSingleByObjectType(GroundOutHit, ForwardOutHit.TraceEnd, GroundPosition, ECC_WorldStatic, CollisionParams))
			{
				if (bDebug)
				{
					DrawDebugLine(World, ForwardOutHit.TraceEnd, GroundPosition, FColor::Red, false, 1, 0, 1);
				}
				return GroundOutHit.ImpactPoint;
			}
		}
	}
	return GetActorLocation();
}

AEXWCharacter* AEXWCharacter::GetTargetFromCrosshair(const float Distance /*= 2000.f*/, const bool bDebug /*= false*/)
{
	FHitResult CrosshairOutHit;
	FVector Direction;
	
	TArray <TEnumAsByte<ECollisionChannel>> CollisionChannels = { ECC_Pawn, ECC_PhysicsBody };
	if (CrosshairTrace(CrosshairOutHit, Direction, CollisionChannels, Distance, bDebug))
	{
		//UE_LOG(EXWCharLog, Error, TEXT("GetTargetFromCrosshair: %s"), *CrosshairOutHit.GetActor()->GetHumanReadableName());
		// Check whether or not it's a child of AEXWCharacter
		if (AEXWCharacter* TargetCharacter = Cast<AEXWCharacter>(CrosshairOutHit.GetActor()))
		{
			return TargetCharacter;
		}
	}
	return nullptr;
}

AEXWCharacter* AEXWCharacter::GetTargetFromCrosshairWithFaction(const float Distance, const bool bDebug, const bool bTargetOtherFaction, const bool bTargetOwnerFaction)
{
	if (AEXWCharacter* TargetCharacter = GetTargetFromCrosshair(Distance, bDebug))
	{
		// Is an Enemy
		if (bTargetOtherFaction && !IsSameFaction(TargetCharacter))
		{
			return TargetCharacter;
		}
		// Is an ally
		if (bTargetOwnerFaction && IsSameFaction(TargetCharacter))
		{
			return TargetCharacter;
		}
	}
	return nullptr;
}

TArray<AEXWCharacter*> AEXWCharacter::GetAimedCharacters(FEXWTargetingParams& InTargetingParams)
{
	TArray<AEXWCharacter*> Characters;

	if (UWorld* World = GetWorld())
	{
		// Using Crosshair
		if (TargetingParams.TargetingType == EEXWTargetingType::TT_Crosshair)
		{
			if (AEXWCharacter* CharacterFound = GetTargetFromCrosshair(TargetingParams.Distance, TargetingParams.bDebug))
			{
				if (IsSameFaction(CharacterFound) && TargetingParams.TargetFaction == EEXWTargetFaction::TF_OwnerFactionOnly)
				{
					Characters.AddUnique(CharacterFound);
				}
				else if (!IsSameFaction(CharacterFound) && TargetingParams.TargetFaction == EEXWTargetFaction::TF_OtherFactionOnly)
				{
					Characters.AddUnique(CharacterFound);
				}
				else if (TargetingParams.TargetFaction == EEXWTargetFaction::TF_ALLFactions)
				{
					Characters.AddUnique(CharacterFound);
				}
				return Characters;
			}
			else return Characters;
		}

		// Using Character Aim
		// Set up the location / points
		FVector FirstPoint = GetActorLocation();
		FirstPoint.Z += BaseEyeHeight;
		FRotator AimRotation = GetBaseAimRotation();
		if (TargetingParams.TargetingType == EEXWTargetingType::TT_AimWithoutPitch)
		{
			AimRotation.Pitch = 0.f;
		}
		FVector LastPoint = ((AimRotation.Vector() * TargetingParams.Distance) + FirstPoint);

		// Shape
		FCollisionShape CollisionShape;
		CollisionShape.ShapeType = ECollisionShape::Sphere;
		CollisionShape.SetSphere(TargetingParams.Width);

		// Collision params
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);

		// Trace
		TArray<FHitResult> OutHits;
		World->SweepMultiByObjectType(OutHits, FirstPoint, LastPoint, FQuat(0, 0, 0, 0),
			FCollisionObjectQueryParams::AllObjects, CollisionShape, CollisionParams);

		// Parse the data
		for (FHitResult OutHit : OutHits)
		{
			if (AEXWCharacter* TempCharacter = Cast<AEXWCharacter>(OutHit.GetActor()))
			{
				if (IsSameFaction(TempCharacter) && TargetingParams.TargetFaction == EEXWTargetFaction::TF_OwnerFactionOnly)
				{
					Characters.AddUnique(TempCharacter);
				}
				else if (!IsSameFaction(TempCharacter) && TargetingParams.TargetFaction == EEXWTargetFaction::TF_OtherFactionOnly)
				{
					Characters.AddUnique(TempCharacter);
				}
				else if (TargetingParams.TargetFaction == EEXWTargetFaction::TF_ALLFactions)
				{
					Characters.AddUnique(TempCharacter);
				}
			}
		}

		// Debug
		if (TargetingParams.bDebug)
		{
			DrawDebugCylinder(World, FirstPoint, LastPoint, TargetingParams.Width, 50, FColor::Red, false, .2f, 0, 1);
		}
	}
	return Characters;
}

bool AEXWCharacter::CrosshairTrace(FHitResult& OutHit, FVector& ScreenDirection, const TArray<TEnumAsByte<ECollisionChannel>> CollisionChannels, const float Distance, const bool bDebug)
{
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		// Get viewport size
		int32 ViewportSizeX;
		int32 ViewportSizeY;
		PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);
		// Get the position in the middle of the screen (Cross-hair position in the 3D scene)
		FVector CrosshairLocation_Start;
		PlayerController->DeprojectScreenPositionToWorld(ViewportSizeX / 2.f, ViewportSizeY / 2.f, CrosshairLocation_Start, ScreenDirection);
		// Calculate the end position where the cross-hair is pointing at by a given distance
		FVector CrosshairLocation_End = ((GetBaseAimRotation().Vector() * Distance) + CrosshairLocation_Start);
		if (bDebug)
		{
			DrawDebugLine(GetWorld(), CrosshairLocation_Start, CrosshairLocation_End, FColor::Red, false, 1, 0, 1);
		}
		if (UWorld* World = GetWorld())
		{
			FCollisionQueryParams CollisionParams;
			CollisionParams.AddIgnoredActor(this);
			
			FCollisionObjectQueryParams ObjectParams;
			for (ECollisionChannel CollisionChannel : CollisionChannels)
			{
				ObjectParams.AddObjectTypesToQuery(CollisionChannel);
			}
			
			return World->LineTraceSingleByObjectType(OutHit, CrosshairLocation_Start, CrosshairLocation_End, ObjectParams, CollisionParams);
		}
	}
	return false;
}

FVector AEXWCharacter::GetProjectileDirection(FVector SpawnLocation)
{
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		// Get viewport size
		int32 ViewportSizeX;
		int32 ViewportSizeY;
		FVector ScreenDirection;
		PlayerController->GetViewportSize(ViewportSizeX, ViewportSizeY);
		// Get the position in the middle of the screen (Cross-hair position in the 3D scene)
		FVector CrosshairLocation_Start;
		PlayerController->DeprojectScreenPositionToWorld(ViewportSizeX / 2.f, ViewportSizeY / 2.f, CrosshairLocation_Start, ScreenDirection);
		// Calculate the end position where the cross-hair is pointing at by a given distance
		FVector AimRotationVector = GetBaseAimRotation().Vector();
		FVector CrosshairLocation_End = ((AimRotationVector * 100000.f) + CrosshairLocation_Start);
		if (UWorld* World = GetWorld())
		{
			FCollisionQueryParams CollisionParams;
			FHitResult OutHit;
			CollisionParams.AddIgnoredActor(this);
			if (World->LineTraceSingleByChannel(OutHit, CrosshairLocation_Start, CrosshairLocation_End, ECC_Visibility, CollisionParams))
			{
				return UKismetMathLibrary::GetDirectionUnitVector(SpawnLocation, OutHit.ImpactPoint);
			}
		}
		return ScreenDirection;
	}
	return GetActorForwardVector();
}

EEXWActionDirection AEXWCharacter::GetCharacterDirection(const EEXWDirectionMode DirectionMode, float& OutDirectionValue)
{
	if (GetMesh())
	{
		if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
		{
			if (APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0))
			{
				FRotator BaseRotation(FRotator::ZeroRotator);
				BaseRotation.Yaw = (DirectionMode == EEXWDirectionMode::CameraRotation) ? CameraManager->GetCameraRotation().Yaw : GetActorRotation().Yaw;
				OutDirectionValue = AnimInstance->CalculateDirection(GetVelocity(), BaseRotation);
				return UEXWDataLibrary::ConvertFloatToDirection(OutDirectionValue);
			}
			else
			{
				UE_LOG(EXWCharLog, Warning, TEXT("Camera Manager not found for this controller, cannot check character Direction."));
			}
		}
	}
	return EEXWActionDirection::AD_Any;
}

void AEXWCharacter::RotateCharacterTowardsCameraDirection()
{
	if (GetMesh())
	{
		if (UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance())
		{
			if (APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(this, 0))
			{
				FRotator TargetRotation(FRotator::ZeroRotator);
				TargetRotation.Yaw = CameraManager->GetCameraRotation().Yaw;
				
				SetActorRotation(FMath::RInterpTo(GetActorRotation(), TargetRotation, GetWorld()->GetDeltaSeconds(), RotateCharacterTowardsCameraDirectionSpeed));
				
			}
			else
			{
				UE_LOG(EXWCharLog, Warning, TEXT("Camera Manager not found for this controller, cannot check character Direction."));
			}
		}
	}
}

void AEXWCharacter::Replicated_PlayMontage_Implementation(UAnimMontage* montage, float track)
{
	if (GetMesh())
	{
		if (UAnimInstance* AnimInst = GetMesh()->GetAnimInstance())
		{
			AnimInst->Montage_Play(montage, track);

		}
	}
	Server_PlayMontage(montage, track);
}

void AEXWCharacter::Server_PlayMontage_Implementation(UAnimMontage* montage, float track)
{
	Multicast_PlayMontage(montage, track);
}

void AEXWCharacter::Multicast_PlayMontage_Implementation(UAnimMontage* montage, float track)
{
	if (!IsLocallyControlled())
	{
		if (GetMesh())
		{
			if (UAnimInstance* AnimInst = GetMesh()->GetAnimInstance())
			{
				AnimInst->Montage_Play(montage, track);
			}
		}
	}
}

void AEXWCharacter::Client_PlayMontage_Implementation(UAnimMontage* montage, float track)
{
	if (GetMesh())
	{
		if (UAnimInstance* AnimInst = GetMesh()->GetAnimInstance())
		{
			AnimInst->Montage_Play(montage, track);
		}
	}
}

void AEXWCharacter::Server_PlayMontageSection_Implementation(UAnimMontage* montage, float track, FName Section)
{
	Multicast_PlayMontageSection(montage, track, Section);
}

void AEXWCharacter::Multicast_PlayMontageSection_Implementation(UAnimMontage* montage, float track, FName Section)
{
	if (!IsLocallyControlled())
	{
		if (GetMesh())
		{
			if (UAnimInstance* AnimInst = GetMesh()->GetAnimInstance())
			{
				AnimInst->Montage_Play(montage, track);
				AnimInst->Montage_JumpToSection(Section, montage);
			}
		}
	}
}

void AEXWCharacter::Client_PlayMontageSection_Implementation(UAnimMontage* montage, float track, FName Section)
{
	if (GetMesh())
	{
		if (UAnimInstance* AnimInst = GetMesh()->GetAnimInstance())
		{
			AnimInst->Montage_Play(montage, track);
			AnimInst->Montage_JumpToSection(Section, montage);
		}
	}
}

void AEXWCharacter::Server_StopMontage_Implementation(UAnimMontage* montage)
{
	Multicast_StopMontage(montage);
}

void AEXWCharacter::Multicast_StopMontage_Implementation(UAnimMontage* montage)
{
	if (GetMesh())
	{
		if (UAnimInstance* AnimInst = GetMesh()->GetAnimInstance())
		{
			AnimInst->Montage_Stop(.15f, montage);
		}
	}
}

UAnimMontage* AEXWCharacter::GetCurrentActiveMontage()
{
	if (GetMesh())
	{
		if (GetMesh()->GetAnimInstance())
		{
			return GetMesh()->GetAnimInstance()->GetCurrentActiveMontage();
		}
	}
	return nullptr;
}

void AEXWCharacter::Multicast_PlayParticles_Implementation(UParticleSystem* Particles, FName BoneName)
{
	if (Particles && bCanPlayParticles)
	{
		
		UGameplayStatics::SpawnEmitterAttached(Particles, GetMesh(), BoneName);
		//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particles, SpawnTransform);
		bCanPlayParticles = false;

		FTimerHandle ParticlesTimerHandle;
		FTimerDelegate ParticlesTimerDel;
		ParticlesTimerDel.BindLambda([&] { bCanPlayParticles = true; });
		GetWorld()->GetTimerManager().SetTimer(ParticlesTimerHandle, ParticlesTimerDel, ItemSetParticlesDelay, false);
	}
}

void AEXWCharacter::Server_SetFaction_Implementation(int32 NewFaction /*= 0*/)
{
	UE_LOG(EXWCharLog, Log, TEXT("Faction of <%s> changed from %d to %d"), *Name.ToString(), Faction, NewFaction);
	Faction = NewFaction;
}

void AEXWCharacter::SetFaction(int32 NewFaction /*= 0*/)
{
	Server_SetFaction(NewFaction);
}

bool AEXWCharacter::IsSameFaction(AEXWCharacter* OtherCharacter)
{
	if (OtherCharacter) {
		return OtherCharacter->GetFaction() == GetFaction();
	}
	return false;
}

void AEXWCharacter::Client_SetTargetFaction_Implementation(AEXWCharacter* TargetCharacter, int32 NewFaction /*= 0*/)
{
	TargetCharacter->Faction = NewFaction;
}

void AEXWCharacter::SetAttributeCurrentValue(EEXWAttributeType AttributeType, float Value)
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		if (Attribute.AttributeType == AttributeType)
		{
			Attribute.CurrentValue = Value;
			OnUpdateAttribute_Native(Attribute);
		}
	}
}

void AEXWCharacter::Server_SetAttributeCurrentValue_Implementation(EEXWAttributeType AttributeType, float Value)
{
	SetAttributeCurrentValue(AttributeType, Value);
}

void AEXWCharacter::SetAttributeMaxValue(EEXWAttributeType AttributeType, float Value)
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		if (Attribute.AttributeType == AttributeType)
		{
			Attribute.MaxValue = Value;
			OnUpdateAttribute_Native(Attribute);
		}
	}
}

void AEXWCharacter::Server_SetAttributeMaxValue_Implementation(EEXWAttributeType AttributeType, float Value)
{
	SetAttributeMaxValue(AttributeType, Value);
}

void AEXWCharacter::GainAttribute(EEXWAttributeType AttributeType, float Value)
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		if (Attribute.AttributeType == AttributeType)
		{
			Attribute.GainAttribute(Value);
			OnUpdateAttribute_Native(Attribute);
			OnGainAttribute_Native(AttributeType, Value);
		}
	}
}

void AEXWCharacter::Server_GainAttribute_Implementation(EEXWAttributeType AttributeType, float Value)
{
	GainAttribute(AttributeType, Value);
}

void AEXWCharacter::Replicated_GainAttribute(EEXWAttributeType AttributeType, float Value)
{
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		Server_GainAttribute_Implementation(AttributeType, Value);
	}
	else
	{
		GainAttribute(AttributeType, Value);
	}
}

void AEXWCharacter::LoseAttribute(EEXWAttributeType AttributeType, float Value)
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		if (Attribute.AttributeType == AttributeType)
		{
			Attribute.LoseAttribute(Value);
			if(AttributeType== EEXWAttributeType::Health)
			{
				UE_LOG(LogTemp, Warning, TEXT("LoseAttribute : %s"), *FString::SanitizeFloat(Value));
			}
			OnUpdateAttribute_Native(Attribute);
			OnLoseAttribute_Native(AttributeType, Value);

		}
	}
}

void AEXWCharacter::Server_LoseAttribute_Implementation(EEXWAttributeType AttributeType, float Value)
{
	LoseAttribute(AttributeType, Value);
}

void AEXWCharacter::Replicated_LoseAttribute(EEXWAttributeType AttributeType, float Value)
{
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		Server_LoseAttribute_Implementation(AttributeType, Value);
	}
	else
	{
		LoseAttribute(AttributeType, Value);
	}
}

bool AEXWCharacter::GetAttribute(const EEXWAttributeType AttributeType, FEXWAttribute& OutAttribute)
{
	for (FEXWAttribute& Attribute : Attributes)  // Check if it is actually having the right value or not due to ref
	{
		if (Attribute.AttributeType == AttributeType)
		{
			OutAttribute = Attribute;
			return true;
		}
	}
	return false;
}

bool AEXWCharacter::GetAttributeCurrentValue(const EEXWAttributeType AttributeType, float& OutValue)
{
	FEXWAttribute OutAttribute;
	if (GetAttribute(AttributeType, OutAttribute))
	{
		OutValue = OutAttribute.CurrentValue;
		return true;
	}
	return false;
}

bool AEXWCharacter::GetAttributePercentage(const EEXWAttributeType AttributeType, float& OutValue)
{
	FEXWAttribute OutAttribute;
	if (GetAttribute(AttributeType, OutAttribute))
	{
		OutValue = OutAttribute.CurrentValue / OutAttribute.MaxValue;
		return true;
	}
	return false;
}

bool AEXWCharacter::GetAttributeMaxValue(const EEXWAttributeType AttributeType, float& OutValue)
{
	FEXWAttribute OutAttribute;
	if (GetAttribute(AttributeType, OutAttribute))
	{
		OutValue = OutAttribute.MaxValue;
		return true;
	}
	return false;
}

bool AEXWCharacter::GetMainAttribute(FEXWAttribute& OutAttribute)
{
	return GetAttribute(MainAttribute, OutAttribute);
}

bool AEXWCharacter::GetMainAttributeCurrentValue(float& OutValue)
{
	return GetAttributeCurrentValue(MainAttribute, OutValue);
}

bool AEXWCharacter::GetMainAttributePercentage(float& OutValue)
{
	return GetAttributePercentage(MainAttribute, OutValue);
}

bool AEXWCharacter::HasEnoughAttribute(EEXWAttributeType AttributeType, float Value)
{
	FEXWAttribute OutAttribute;
	if (GetAttribute(AttributeType, OutAttribute))
	{
		return OutAttribute.CurrentValue >= Value;
	}
	return false;
}

void AEXWCharacter::OnGainAttribute_Native(const EEXWAttributeType AttributeType, const float Value)
{
	OnGainAttribute(AttributeType, Value);
	OnAttributeGained.Broadcast(AttributeType, Value);
}

void AEXWCharacter::OnLoseAttribute_Native(const EEXWAttributeType AttributeType, const float Value)
{
	float AttributeValue = 100.f;
	if (GetAttributeCurrentValue(AttributeType, AttributeValue))
	{
		if (AttributeValue <= 0.f && AttributeType == EEXWAttributeType::Health)
		{
			if (bIsDueling)
			{
				Server_EndDuel(LastCharacterAffectedBy);
			}
			else
			{
				OnDeathEvent_Native();
			}
		}
	}
	OnLoseAttribute(AttributeType, Value);
	OnAttributeLost.Broadcast(AttributeType, Value);
}

void AEXWCharacter::OnUpdateAttribute_Native(const FEXWAttribute& Attribute)
{
	OnUpdateAttribute(Attribute);
}

void AEXWCharacter::UpdateRegen(FEXWAttribute& Attribute)
{
	if (IsLocallyControlled() && Attribute.bApplyRegen)
	{
		FTimerDelegate RegenTimerDelegate;
		RegenTimerDelegate.BindUFunction(this, FName("ApplyRegen"), Attribute);

		if (UWorld* World = GetWorld())
		{
			World->GetTimerManager().ClearTimer(Attribute.RegenTimerHandle);
			World->GetTimerManager().SetTimer(Attribute.RegenTimerHandle, RegenTimerDelegate, Attribute.RegenTickingRate, true, 0.f);
		}
	}
}

void AEXWCharacter::AddRegen(const EEXWAttributeType AttributeType, const float Value, const float TickingRate)
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		if (Attribute.AttributeType == AttributeType)
		{
			Attribute.bApplyRegen = true;
			Attribute.RegenTickingRate = TickingRate;
			Attribute.RegenValue = Value;
			UpdateRegen(Attribute);
		}
	}
}

void AEXWCharacter::StopRegen(const EEXWAttributeType AttributeType)
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		if (Attribute.AttributeType == AttributeType)
		{
			if (UWorld* World = GetWorld())
			{
				World->GetTimerManager().ClearTimer(Attribute.RegenTimerHandle);
			}
		}
	}
}

void AEXWCharacter::StopAllRegens()
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		StopRegen(Attribute.AttributeType);
	}
}

void AEXWCharacter::RemoveRegen(const EEXWAttributeType AttributeType)
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		if (Attribute.AttributeType == AttributeType)
		{
			Attributes.Remove(Attribute);
			return;
		}
	}
}

void AEXWCharacter::RemoveAllRegens()
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		RemoveRegen(Attribute.AttributeType);
	}
}

void AEXWCharacter::Server_RemoveAllRegens_Implementation()
{
	RemoveAllRegens();
}

void AEXWCharacter::Multicast_StopAllRegens_Implementation()
{
	StopAllRegens();
}

void AEXWCharacter::Multicast_RemoveAllRegens_Implementation()
{
	RemoveAllRegens();
}

void AEXWCharacter::UpdateAllRegens()
{
	for (FEXWAttribute& Attribute : Attributes)
	{
		UpdateRegen(Attribute);
	}
}

void AEXWCharacter::ApplyRegen(const FEXWAttribute Attribute)
{
	Server_GainAttribute(Attribute.AttributeType, Attribute.RegenValue);
}

void AEXWCharacter::UpdateAttributesFromStats()
{
	for (FEXWAttribute Attribute : Attributes)
	{
		for (FEXWStat Stat : Stats)
		{
			if (Attribute.StatType == Stat.StatType)
			{
				SetAttributeMaxValue(Attribute.AttributeType, Stat.Value * Attribute.StatModifier);
				if (Attribute.bDefaultCurrentValueZero)
				{
					SetAttributeCurrentValue(Attribute.AttributeType, 0);
				}
				else
				{
					SetAttributeCurrentValue(Attribute.AttributeType, Stat.Value * Attribute.StatModifier);
				}
			}
		}
	}
}

void AEXWCharacter::UpdateAttributesFromItems()
{
	TMap<EEXWAttributeType, float> FinalAttributeValues;

	for (FEXWInventorySlot InventorySlot : InventoryEquipment.ItemSlots)
	{
		FEXWItemData ItemData;
		if (UEXWInventoryLibrary::GetItemData(InventorySlot.ItemID, ItemData))
		{
			for (TPair<EEXWAttributeType, float>& AttributeData : ItemData.AttributeEffectsOnEquip)
			{
				if (AttributeData.Value != 0.f)
				{
					float Value;
					if (FinalAttributeValues.Find(AttributeData.Key))
					{
						Value = *FinalAttributeValues.Find(AttributeData.Key) + AttributeData.Value;
						FinalAttributeValues.FindOrAdd(AttributeData.Key) = Value;
					}
					else
					{
						Value = AttributeData.Value;
						FinalAttributeValues.FindOrAdd(AttributeData.Key) = Value;
					}
				}
			}
		}
	}
	for (TPair<EEXWAttributeType, float>& AttributeData : FinalAttributeValues)
	{
		FEXWAttribute CurrentAttributeValue;
		if (AttributeData.Value != 0.f && GetAttribute(AttributeData.Key, CurrentAttributeValue))
		{
			SetAttributeMaxValue(AttributeData.Key, CurrentAttributeValue.MaxValue + AttributeData.Value);

			if (CurrentAttributeValue.bDefaultCurrentValueZero)
			{
				SetAttributeCurrentValue(CurrentAttributeValue.AttributeType, 0);
			}
			else
			{
				SetAttributeCurrentValue(CurrentAttributeValue.AttributeType, CurrentAttributeValue.MaxValue + AttributeData.Value);
			}
		}
	}
}

void AEXWCharacter::CreateDefaultAttributes()
{
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::Health, true, false, EEXWStatType::Endurance, 10.f, true, 1.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::Mana, true, false, EEXWStatType::Intelligence, 10.f, true, 1.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::Stamina, true, false, EEXWStatType::Endurance, 5.f, true, 2.f, .5f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::Rage, true, false, EEXWStatType::Strength, 2.f, true, -.5f, .5f, true));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::Damage, false, false, EEXWStatType::Strength, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::MagicDamage, false, false, EEXWStatType::Intelligence, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::Defense, false, false, EEXWStatType::Endurance, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::MagicDefense, false, false, EEXWStatType::Intelligence, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::AttackSpeed, false, false, EEXWStatType::Agility, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::Aim, false, false, EEXWStatType::Agility, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::Evasion, false, false, EEXWStatType::Agility, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::CriticalHitRate, false, false, EEXWStatType::Luck, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::CriticalDamage, false, false, EEXWStatType::Luck, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::CriticalNullifier, false, false, EEXWStatType::Luck, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::CriticalDamageNullifier, false, false, EEXWStatType::Luck, 5.f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::ArmorPenetration, false, false, EEXWStatType::Strength, .5f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::MagicArmorPenetration, false, false, EEXWStatType::Intelligence, .5f));
	Attributes.AddUnique(FEXWAttribute(EEXWAttributeType::CastSpeed, true, false, EEXWStatType::Intelligence, 1.f));
}

void AEXWCharacter::Server_ApplyDamage_Implementation(AActor* Target, const float Damage, TSubclassOf<UDamageType> DamageType)
{

	UGameplayStatics::ApplyDamage(Target, Damage, GetController(), this, DamageType);
}

float AEXWCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (!IsValidState(EEXWState::S_Invulnerable))
	{
		SetInCombat();
		//UE_LOG(LogTemp, Warning, TEXT("DamageBefore : %s"), *FString::SanitizeFloat(Damage));
		Damage = ModifyDamageTaken(Damage, DamageEvent, EventInstigator, DamageCauser);
		//UE_LOG(LogTemp, Warning, TEXT("DamageAfter : %s"), *FString::SanitizeFloat(Damage));
		Replicated_LoseAttribute(EEXWAttributeType::Health, Damage);
	}
	return Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
}

float AEXWCharacter::ModifyDamageTaken_Implementation(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	// Modify the damage taken here depending on some armor or resistance or position compared to the character.
	float ResultRotationValue = 0;
	bool bDamageCauserIsFront = UEXWDataLibrary::GetRelativePosition(this, DamageCauser, ResultRotationValue) == EEXWRelativePosition::RP_Front;
	if (IsValidState(EEXWState::S_Blocking) && bDamageCauserIsFront)
	{
		return 0;
	}

	//Defense and Magic Defense Mechanics
	if (DamageEvent.DamageTypeClass == UEXWMagicalDamageType::StaticClass())
	{
		float MagicDefenseValue;
		GetAttributeCurrentValue(EEXWAttributeType::MagicDefense, MagicDefenseValue);

		Damage = Damage - (Damage * (FMath::LogX(2, MagicDefenseValue + 15) * 10 - 13.5) / 100);
	}
	else if (DamageEvent.DamageTypeClass == UEXWPhysicalDamageType::StaticClass())
	{
		float PhysicalDefenseValue;
		GetAttributeCurrentValue(EEXWAttributeType::Defense, PhysicalDefenseValue);

		Damage = Damage - (Damage * (FMath::LogX(2, PhysicalDefenseValue + 15) * 10 -13.5) / 100);
	}

	//Damage Absorption Mechanic
	Damage = GetDamageAbsorptionValue(DamageEvent.DamageTypeClass, Damage);

	float DamageReductionValue = GetDamageReductionValue(DamageEvent.DamageTypeClass);
	if (DamageReductionValue > 0.f)
	{
		//Clamp it to zero so it doesn't go below it and cause the reverse of the wanted effect
		Damage = FMath::Max(0.f, Damage - ((DamageReductionValue / 100) * Damage));
	}

	return Damage;
}

void AEXWCharacter::Server_GainStat_Implementation(EEXWStatType StatType, float Value)
{
	for (FEXWStat& Stat : Stats)
	{
		if (Stat.StatType == StatType)
		{
			Stat.GainStat(Value);
			OnUpdateStat_Native(Stat);
		}
	}
}

void AEXWCharacter::Server_LoseStat_Implementation(EEXWStatType StatType, float Value)
{
	for (FEXWStat& Stat : Stats)
	{
		if (Stat.StatType == StatType)
		{
			Stat.LoseStat(Value);
			OnUpdateStat_Native(Stat);
		}
	}
}

void AEXWCharacter::SetStatValue(EEXWStatType StatType, float Value)
{
	for (FEXWStat& Stat : Stats)
	{
		if (Stat.StatType == StatType)
		{
			Stat.Value = Value;
			OnUpdateStat_Native(Stat);
		}
	}
}

void AEXWCharacter::Server_SetStatValue_Implementation(EEXWStatType StatType, float Value)
{
	SetStatValue(StatType, Value);
}

bool AEXWCharacter::GetStat(const EEXWStatType StatType, FEXWStat& OutStat)
{
	for (FEXWStat& Stat : Stats) { // Check if it is actually having the right value or not due to ref
		if (Stat.StatType == StatType)
		{
			OutStat = Stat;
			return true;
		}
	}
	return false;
}

void AEXWCharacter::OnUpdateStat_Native(const FEXWStat& Stat)
{
	OnUpdateStat(Stat);
}

void AEXWCharacter::UpdateStatsFromLevelModifier()
{
	UDataTable* LevelModifierDT;
	if (UEXWDataLibrary::GetStatLevelModifierDT(LevelModifierDT))
	{
		static const FString ContextString(TEXT("LevelModifierDT"));
		FEXWStatLevelModifierData* StatLevelModifierData = LevelModifierDT->FindRow<FEXWStatLevelModifierData>(StatLevelModifierRowName, ContextString, true);

		if (StatLevelModifierData)
		{
			// Parse all the stats
			for (FEXWStatLevelModifier StatLevelModifier : StatLevelModifierData->LevelModifiers)
			{
				float TotalStatValue = 0.f;
				// Parse all the levels for each stat
				for (int32 TempLevel = 0; TempLevel < StatLevelModifier.LevelModifiers.Num(); TempLevel++)
				{
					if (TempLevel < ProgressionLevel)
					{
						TotalStatValue = TotalStatValue + StatLevelModifier.LevelModifiers[TempLevel];
					}
				}
				//if (UKismetSystemLibrary::IsStandalone(this))
				//{
				SetStatValue(StatLevelModifier.StatType, TotalStatValue);
				//}
				//else if (IsLocallyControlled())
				//{
				//	Server_SetStatValue(StatLevelModifier.StatType, TotalStatValue); // Needs to be managed via async system.
				//}
			}
		}
	}
}

void AEXWCharacter::UpdateStatsFromItems()
{
	TMap<EEXWStatType, float> FinalStatValues;
	FinalStatValues.Add(EEXWStatType::Agility, 0.f); // index 0
	FinalStatValues.Add(EEXWStatType::Endurance, 0.f); // index 1
	FinalStatValues.Add(EEXWStatType::Intelligence, 0.f); // index 2
	FinalStatValues.Add(EEXWStatType::Luck, 0.f); // index 3
	FinalStatValues.Add(EEXWStatType::Stamina, 0.f); // index 4
	FinalStatValues.Add(EEXWStatType::Strength, 0.f); // index 5

	for (FEXWInventorySlot InventorySlot : InventoryEquipment.ItemSlots)
	{
		FEXWItemData ItemData;
		if (UEXWInventoryLibrary::GetItemData(InventorySlot.ItemID, ItemData))
		{
			for (TPair<EEXWStatType, float>& StatData : ItemData.StatEffectsOnEquip)
			{
				if (StatData.Value != 0.f)
				{
					float Value = *FinalStatValues.Find(StatData.Key) + StatData.Value;
					FinalStatValues.FindOrAdd(StatData.Key) = Value;
				}
			}
		}
	}
	for (TPair<EEXWStatType, float>& StatData : FinalStatValues)
	{
		FEXWStat CurrentStatValue;
		if (StatData.Value != 0.f && GetStat(StatData.Key, CurrentStatValue))
		{
			SetStatValue(StatData.Key, StatData.Value + CurrentStatValue.Value);
		}
	}
}

void AEXWCharacter::CreateDefaultStats()
{
	Stats.AddUnique(FEXWStat(EEXWStatType::Strength));
	Stats.AddUnique(FEXWStat(EEXWStatType::Agility));
	Stats.AddUnique(FEXWStat(EEXWStatType::Endurance));
	Stats.AddUnique(FEXWStat(EEXWStatType::Intelligence));
	Stats.AddUnique(FEXWStat(EEXWStatType::Luck));
}

void AEXWCharacter::Server_AddStatLevelPoint_Implementation(EEXWStatType StatType, int32 ValueToAdd)
{
	for (FEXWStatLevelPoint& StatLevelPoint : StatLevelPoints)
	{
		if (StatLevelPoint.StatType == StatType)
		{
			StatLevelPoint.Level += ValueToAdd;
		}
	}
}

void AEXWCharacter::CreateDefaultDamageReductions()
{
	DamageReductions = {
		FEXWDamageReduction(UEXWPhysicalDamageType::StaticClass(), 0.f),
		FEXWDamageReduction(UEXWMagicalDamageType::StaticClass(), 0.f)
	};
}

float AEXWCharacter::GetDamageReductionValue(TSubclassOf<UDamageType> DamageType)
{
	for (FEXWDamageReduction& DamageReduction : DamageReductions)
	{
		if (DamageReduction.DamageType == DamageType)
		{
			return DamageReduction.Value;
		}
	}
	return 0.f;
}

void AEXWCharacter::GainDamageReduction(TSubclassOf<UDamageType> DamageType, const float InValue)
{
	for (FEXWDamageReduction& DamageReduction : DamageReductions)
	{
		if (DamageReduction.DamageType == DamageType)
		{
			DamageReduction.Value += InValue;
		}
	}
}

void AEXWCharacter::Server_GainDamageReduction_Implementation(TSubclassOf<UDamageType> DamageType, const float InValue)
{
	GainDamageReduction(DamageType, InValue);
}

void AEXWCharacter::LoseDamageReduction(TSubclassOf<UDamageType> DamageType, const float InValue)
{
	for (FEXWDamageReduction& DamageReduction : DamageReductions)
	{
		if (DamageReduction.DamageType == DamageType)
		{
			DamageReduction.Value -= InValue;
		}
	}
}

void AEXWCharacter::Server_LoseDamageReduction_Implementation(TSubclassOf<UDamageType> DamageType, const float InValue)
{
	LoseDamageReduction(DamageType, InValue);
}

void AEXWCharacter::CreateDefaultDamageAbsorptions()
{
	DamageAbsorptions = {
		FEXWDamageAbsorption(UEXWPhysicalDamageType::StaticClass(), 0.f),
		FEXWDamageAbsorption(UEXWMagicalDamageType::StaticClass(), 0.f)
	};
}

float AEXWCharacter::GetDamageAbsorptionValue(TSubclassOf<UDamageType> DamageType, float Damage)
{
	for (FEXWDamageAbsorption& DamageAbsorption : DamageAbsorptions)
	{
		if (DamageAbsorption.DamageType == DamageType)
		{
			Damage = FMath::Max(0.f, Damage - DamageAbsorption.Value);
			DamageAbsorption.Value = FMath::Max(0.f, DamageAbsorption.Value - Damage);
			return Damage;
		}
	}
	return Damage;
}


void AEXWCharacter::GainDamageAbsorption(TSubclassOf<UDamageType> DamageType, const float InValue)
{
	if (!HasAuthority())
	{
		return;
	}
	for (FEXWDamageAbsorption& DamageAbsorption : DamageAbsorptions)
	{
		if (DamageAbsorption.DamageType == DamageType)
		{
			DamageAbsorption.Value += InValue;
		}
	}
}

void AEXWCharacter::Server_GainDamageAbsorption_Implementation(TSubclassOf<UDamageType> DamageType, const float InValue)
{
	GainDamageAbsorption(DamageType, InValue);
}


void AEXWCharacter::LoseDamageAbsorption(TSubclassOf<UDamageType> DamageType, const float InValue)
{
	if (!HasAuthority())
	{
		return;
	}
	for (FEXWDamageAbsorption& DamageAbsorption : DamageAbsorptions)
	{
		if (DamageAbsorption.DamageType == DamageType)
		{
			DamageAbsorption.Value -= InValue;
		}
	}
}

void AEXWCharacter::Server_LoseDamageAbsorption_Implementation(TSubclassOf<UDamageType> DamageType, const float InValue)
{
	LoseDamageAbsorption(DamageType, InValue);
}

bool AEXWCharacter::MakeSpawnableAbility(const FName RowName /*= "Spawnable_Ability_Row_Name"*/)
{
	FEXWSpawnableAbilitySpawnParams SpawnParams;
	if (CreateSpawnableAbilityParams(SpawnParams, RowName))
	{
		Server_ConstructSpawnableAbility(SpawnParams);
		return true;
	}
	else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Could not create spawnabale ability params for the ID [%s]"), *Name.ToString(), *RowName.ToString());
	return false;
}

bool AEXWCharacter::CreateSpawnableAbilityParams(FEXWSpawnableAbilitySpawnParams& SpawnParams, const FName RowName /*= "Spawnable_Ability_Row_Name"*/)
{
	// Find data table
	UDataTable* SpawnableAbilityDT;
	if (UEXWDataLibrary::GetSpawnableAbilityDT(SpawnableAbilityDT))
	{
		static const FString ContextString(TEXT("SpawnableAbilityDT"));
		FEXWSpawnableAbilityData* SpawnableAbilityData = SpawnableAbilityDT->FindRow<FEXWSpawnableAbilityData>(RowName, ContextString, true);

		// Check if the the row data was found.
		if (SpawnableAbilityData) {

			SpawnParams.SpawnableAbilityData = *SpawnableAbilityData;
			SpawnParams.SourceCharacter = this;
			if (SpawnParams.SpawnableAbilityData.SpawnableAbilityType == EEXWSpawnableAbilityType::InstantAtTarget)
			{
				AEXWCharacter* TargetCharacter = nullptr;
				if (SpawnParams.SpawnableAbilityData.TargetingType == EEXWTargetingType::TT_Crosshair)
				{
					TargetCharacter = GetTargetFromCrosshairWithFaction(SpawnParams.SpawnableAbilityData.DistanceRange, false,
						SpawnParams.SpawnableAbilityData.bTargetOtherFaction,
						SpawnParams.SpawnableAbilityData.bTargetOwnerFaction);
				}
				else
				{
					TargetCharacter = (TargetCharacters.IsValidIndex(0) ? TargetCharacters[0] : this);
				}

				if (TargetCharacter)
				{
					if (!SpawnableAbilityData->bTargetDead && TargetCharacter->States.Contains(EEXWState::S_Dead))
					{
						TargetCharacter=nullptr;
					}
				}
				
				SpawnParams.TargetCharacter = TargetCharacter;
				SpawnParams.SpawnTransform = (TargetCharacter ? TargetCharacter->GetSocketTransform(SpawnParams.SpawnableAbilityData.TargetSocketName) : FTransform());
				return true;
			}
			else if (SpawnParams.SpawnableAbilityData.SpawnableAbilityType == EEXWSpawnableAbilityType::InstantAtCrosshair)
			{
				SpawnParams.SpawnTransform = FTransform(GetClosestGroundToCrosshair(SpawnParams.SpawnableAbilityData.DistanceRange));
				return true;
			}
			else if (SpawnParams.SpawnableAbilityData.SpawnableAbilityType == EEXWSpawnableAbilityType::Projectile)
			{
				// Set up spawn transform
				FTransform SpawnTransform;
				if (SpawnParams.SpawnableAbilityData.bUseCharacterRotation)
				{
					SpawnTransform.SetLocation(GetSocketTransform(SpawnParams.SpawnableAbilityData.SourceSocketName).GetLocation());
					SpawnTransform.SetScale3D(GetSocketTransform(SpawnParams.SpawnableAbilityData.SourceSocketName).GetScale3D());
					SpawnTransform.SetRotation(GetActorRotation().Quaternion());
				}
				else
				{
					SpawnTransform = GetSocketTransform(SpawnParams.SpawnableAbilityData.SourceSocketName);
				}
				SpawnParams.SpawnTransform = SpawnTransform;
				// Set target if it's valid (default)
				if (SpawnParams.SpawnableAbilityData.bIsHomingProjectile)
				{
					if (TargetCharacters.IsValidIndex(0))
					{
						if (SpawnableAbilityData->bTargetDead && TargetCharacters[0]->States.Contains(EEXWState::S_Dead))
						{
							SpawnParams.TargetCharacter = (TargetCharacters.IsValidIndex(0)) ? TargetCharacters[0] : nullptr;
						}
						else if (!SpawnableAbilityData->bTargetDead && !TargetCharacters[0]->States.Contains(EEXWState::S_Dead))
						{
							SpawnParams.TargetCharacter = (TargetCharacters.IsValidIndex(0)) ? TargetCharacters[0] : nullptr;
						}
						
					}
					
					//SpawnParams.TargetCharacter = (TargetCharacters.IsValidIndex(0)) ? TargetCharacters[0] : nullptr;
				}

				// Look up the type of the projectile
				if (SpawnParams.SpawnableAbilityData.TargetingType == EEXWTargetingType::TT_AimWithPitch)
				{
					SpawnParams.Direction = GetProjectileDirection(SpawnParams.SpawnTransform.GetLocation());
				}
				else if (SpawnParams.SpawnableAbilityData.TargetingType == EEXWTargetingType::TT_AimWithoutPitch)
				{
					SpawnParams.Direction = GetBaseAimRotation().Vector();
					SpawnParams.Direction.Z = 0.f; // Cancel the pitch
				}
				else if (SpawnParams.SpawnableAbilityData.TargetingType == EEXWTargetingType::TT_Crosshair)
				{
					SpawnParams.Direction = GetProjectileDirection(SpawnParams.SpawnTransform.GetLocation());
					if (AEXWCharacter* TargetCharacter = GetTargetFromCrosshairWithFaction(SpawnParams.SpawnableAbilityData.DistanceRange, false,
						SpawnParams.SpawnableAbilityData.bTargetOtherFaction,
						SpawnParams.SpawnableAbilityData.bTargetOwnerFaction))
					{
						SpawnParams.TargetCharacter = TargetCharacter;
					}
				}
				return true;
			}
			else if (SpawnParams.SpawnableAbilityData.SpawnableAbilityType == EEXWSpawnableAbilityType::InstantAtSelf)
			{
				SpawnParams.TargetCharacter = this;
				SpawnParams.SpawnTransform = SpawnParams.SourceCharacter->GetSocketTransform(SpawnParams.SpawnableAbilityData.SourceSocketName);
				return true;
			}
		}
		else
		{
			UE_LOG(EXWCharLog, Warning, TEXT("<%s> Spawnable Ability with Data Table Row [%s] not found."), *Name.ToString(), *RowName.ToString());
		}
	}
	else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Error Creating Spawnable Ability Param with ID [%s] due to a missing Data table reference in the Singleton"), *Name.ToString(), *RowName.ToString());
	return false;
}

void AEXWCharacter::Server_ConstructSpawnableAbility_Implementation(FEXWSpawnableAbilitySpawnParams SpawnParams)
{

	// Setting up all the TWeakObjPtr refs
	SpawnParams.SpawnableAbilityData.SourceCharacter = MakeWeakObjectPtr<AEXWCharacter>(SpawnParams.SourceCharacter);
	if (SpawnParams.TargetCharacter)// && !(SpawnParams.TargetCharacter->States.Contains(EEXWState::S_Dead)))
	{
		SpawnParams.SpawnableAbilityData.TargetCharacter = MakeWeakObjectPtr<AEXWCharacter>(SpawnParams.TargetCharacter);
	}
	// Spawn Actor
	if (SpawnParams.SpawnableAbilityData.SpawnableAbilityClass)
	{
		SpawnParams.SpawnableAbilityData.SpawnableAbilityActor = MakeWeakObjectPtr<AEXWSpawnableAbility>(SpawnSpawnableAbilityActor(SpawnParams));
	}
	else
	{
		UE_LOG(EXWCharLog, Warning, TEXT("<%s> Error constructing as no class to spawn for the ID [%s]."), *Name.ToString(), *SpawnParams.SpawnableAbilityData.ID.ToString());
	}
	// Add it to the Stack
	//Server_AddStatusEffect(SpawnableAbilityDataTemp);

}

AEXWSpawnableAbility* AEXWCharacter::SpawnSpawnableAbilityActor(FEXWSpawnableAbilitySpawnParams& SpawnParams)
{
	AEXWSpawnableAbility* SpawnableAbilityActor = nullptr;

	if (HasAuthority() && SpawnParams.SpawnableAbilityData.SourceCharacter.IsValid() && SpawnParams.SpawnableAbilityData.SpawnableAbilityClass) {
		if (UWorld* World = GetWorld()) {

			// Start spawning the actor
			SpawnableAbilityActor = World->SpawnActorDeferred<AEXWSpawnableAbility>(SpawnParams.SpawnableAbilityData.SpawnableAbilityClass,
				SpawnParams.SpawnTransform,
				SpawnParams.SpawnableAbilityData.SourceCharacter.Get(),
				SpawnParams.SpawnableAbilityData.SourceCharacter.Get());

			// Set the actor values
			if (SpawnableAbilityActor) {
				SpawnParams.SpawnableAbilityData.SpawnableAbilityActor = MakeWeakObjectPtr<AEXWSpawnableAbility>(SpawnableAbilityActor);
				SpawnableAbilityActor->SetSpawnableAbilityData(SpawnParams.SpawnableAbilityData);
				// Initialize Movement if projectile
				UGameplayStatics::FinishSpawningActor(SpawnableAbilityActor, SpawnParams.SpawnTransform);
				if (SpawnParams.SpawnableAbilityData.SpawnableAbilityType == EEXWSpawnableAbilityType::Projectile)
				{
					SpawnableAbilityActor->InitializeMovement(SpawnParams.Direction, SpawnParams.TargetCharacter);
					SpawnableAbilityActor->Multicast_InitializeMovement(SpawnParams.Direction, SpawnParams.TargetCharacter);
				}
				if (SpawnParams.SpawnableAbilityData.bAttachToSource)
				{
					SpawnableAbilityActor->GetRootComponent()->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepWorldTransform, SpawnParams.SpawnableAbilityData.SourceSocketName);
				}
			}
			else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Error Spawning Spawnable Ability of ID [%s]."), *Name.ToString(), *SpawnParams.SpawnableAbilityData.ID.ToString());
		}
	}
	else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Error Spawning Spawnable Ability of ID [%s] due to invalid reference."), *Name.ToString(), *SpawnParams.SpawnableAbilityData.ID.ToString());
	return SpawnableAbilityActor;
}

void AEXWCharacter::Server_SpawnAiCharacter_Implementation(TSubclassOf<AEXWCharacter> CharacterClass, UBehaviorTree* BehaviorTree, float MinSpawnLocation, float MaxSpawnLocation, int32 Level, float RoamRadius)
{
	SpawnAiCharacter(CharacterClass, BehaviorTree, MinSpawnLocation, MaxSpawnLocation, Level, RoamRadius);
}

void AEXWCharacter::SpawnAiCharacter(TSubclassOf<AEXWCharacter> CharacterClass, UBehaviorTree* BehaviorTree, float MinSpawnLocation, float MaxSpawnLocation, int32 Level, float RoamRadius)
{
	if (!HasAuthority())
	{
		Server_SpawnAiCharacter(CharacterClass, BehaviorTree, MinSpawnLocation, MaxSpawnLocation, Level, RoamRadius);
		return;
	}

	FVector SpawnLocation = GetActorLocation() + FVector(FMath::FRandRange(MinSpawnLocation, MaxSpawnLocation), FMath::FRandRange(MinSpawnLocation, MaxSpawnLocation), 0.0f);

	if (APawn* AiPawnPtr = UAIBlueprintHelperLibrary::SpawnAIFromClass(GetWorld(), CharacterClass, BehaviorTree, SpawnLocation, GetActorRotation(), true, this))
	{
		if (AEXWCharacter* AiCharacterPtr = Cast<AEXWCharacter>(AiPawnPtr))
		{
			AiCharacterPtr->Server_SetLevel(Level);
			AAIController* AIController = AiCharacterPtr->GetController<AAIController>();

			AIController->GetBlackboardComponent()->SetValueAsVector("SpawnLocation", SpawnLocation);
			AIController->GetBlackboardComponent()->SetValueAsFloat("RoamRadius", RoamRadius);

		}
	}
}

/*
void AEXWCharacter::Server_SpawnCharacter_Implementation(TSubclassOf<AEXWCharacter> CharacterClass)
{
	SpawnCharacter(CharacterClass);
}

void AEXWCharacter::SpawnCharacter(TSubclassOf<AEXWCharacter> CharacterClass)
{
	if (!HasAuthority())
	{
		Server_SpawnCharacter(CharacterClass);
	}
	if (UWorld* const World = GetWorld())
	{
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.Instigator = this;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		FTransform SpawnTransform = FTransform(GetActorRotation(), GetActorLocation());
		World->SpawnActor<AEXWCharacter>(CharacterClass, SpawnTransform, ActorSpawnParams);
		UAIBlueprintHelperLibrary::SpawnAIFromClass(World, CharacterClass, )

	}
}*/

bool AEXWCharacter::FindActiveStatusEffect(FName InID, FEXWStatusEffectData& OutStatusEffect)
{
	for (FEXWStatusEffectData& TempStatusEffect : ActiveStatusEffects) {
		if (TempStatusEffect.ID == InID)
		{
			OutStatusEffect = TempStatusEffect;
			return true;
		}
	}
	return false;
}

void AEXWCharacter::Server_ConstructStatusEffect_Implementation(FName RowName, AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter)
{
	// Find data table
	UDataTable* StatusEffectsDT;
	if (UEXWDataLibrary::GetStatusEffectDT(StatusEffectsDT) && SourceCharacter && TargetCharacter) {
		static const FString ContextString(TEXT("StatusEffectsDT"));
		FEXWStatusEffectData* StatusEffectData = StatusEffectsDT->FindRow<FEXWStatusEffectData>(RowName, ContextString, true);

		// Check if the the row data was found.
		if (StatusEffectData) {

			// Creating a copy to save it
			FEXWStatusEffectData StatusEffectDataTemp = *StatusEffectData;

			// Setting up all the TWeakObjPtr refs
			StatusEffectDataTemp.SourceCharacter = MakeWeakObjectPtr<AEXWCharacter>(SourceCharacter);
			StatusEffectDataTemp.TargetCharacter = MakeWeakObjectPtr<AEXWCharacter>(TargetCharacter);

			// Spawn Actor
			if (StatusEffectDataTemp.StatusEffectClass)
			{
				StatusEffectDataTemp.StatusEffectActor = MakeWeakObjectPtr<AEXWStatusEffect>(SpawnStatusEffectActor(StatusEffectDataTemp));
			}

			// Add it to the Stack
			Server_AddStatusEffect(StatusEffectDataTemp);

			return;
		}
		else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Status Effect with Data Table Row [%s] not found."), *Name.ToString(), *RowName.ToString());
	}
	else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Error constructing Status Effect with ID [%s] due to a missing reference"), *Name.ToString(), *RowName.ToString());
}

AEXWStatusEffect* AEXWCharacter::SpawnStatusEffectActor(FEXWStatusEffectData& StatusEffect)
{
	AEXWStatusEffect* StatusEffectActor = nullptr;
	if (HasAuthority() && StatusEffect.SourceCharacter.IsValid() && StatusEffect.TargetCharacter.IsValid() && StatusEffect.StatusEffectClass) {
		if (UWorld* World = GetWorld()) {
			// Start spawning the actor
			FTransform SpawnTransform = StatusEffect.TargetCharacter.Get()->GetSocketTransform(StatusEffect.SocketName);
			StatusEffectActor = World->SpawnActorDeferred<AEXWStatusEffect>(StatusEffect.StatusEffectClass,
				SpawnTransform,
				StatusEffect.SourceCharacter.Get(),
				StatusEffect.SourceCharacter.Get());
			// Set the actor values
			if (StatusEffectActor) {
				StatusEffect.StatusEffectActor = MakeWeakObjectPtr<AEXWStatusEffect>(StatusEffectActor);
				StatusEffectActor->Server_SetStatusEffectData(StatusEffect);
				UGameplayStatics::FinishSpawningActor(StatusEffectActor, SpawnTransform);
				if (StatusEffect.bAttachToTargetActor)
				{
					StatusEffectActor->AttachToTarget();
					StatusEffectActor->Server_AttachToTarget();
				}
			}
			else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Error Spawning Status Effect of ID [%s]."), *Name.ToString(), *StatusEffect.ID.ToString());
		}
	}
	else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Error Spawning Status Effect of ID [%s] due to invalid reference."), *Name.ToString(), *StatusEffect.ID.ToString());
	return StatusEffectActor;
}

void AEXWCharacter::Server_AddStatusEffect_Implementation(FEXWStatusEffectData StatusEffect)
{
	// return if StatusEffect isn't stackable
	if (StatusEffect.TargetCharacter.IsValid())
	{
		if (StatusEffect.TargetCharacter.Get()->ActiveStatusEffects.Contains(StatusEffect))
		{
			if (!StatusEffect.bCanStack)
			{
				return;
			}
		}
	}
	if (UWorld* World = GetWorld()) {

		FTimerDelegate TimerDel;
		TimerDel.BindUFunction(this, FName("Server_TickStatusEffect"), StatusEffect);
		World->GetTimerManager().SetTimer(StatusEffect.TickingTimerHandle, TimerDel, StatusEffect.TickingRate, true, StatusEffect.TickingDelay);

		//Handle Passives case
		if (StatusEffect.Duration != -1.0f)
		{
			TimerDel.BindUFunction(this, FName("Server_RemoveActiveStatusEffect"), StatusEffect);
			World->GetTimerManager().SetTimer(StatusEffect.DurationHandle, TimerDel, .1f, true, StatusEffect.Duration);
		}


		if (StatusEffect.TargetCharacter.IsValid())
		{
			// Apply time dilation
			if (StatusEffect.MovementModifierValue != 1.f)
			{
				StatusEffect.TargetCharacter.Get()->Multicast_SetCustomTimeDilation(StatusEffect.MovementModifierValue);
			}
			StatusEffect.TargetCharacter.Get()->ActiveStatusEffects.Add(StatusEffect);
			StatusEffect.TargetCharacter.Get()->Client_AddStatusEffect(StatusEffect);
			StatusEffect.TargetCharacter.Get()->OnStatusEffectAdded(StatusEffect);
			StatusEffect.TargetCharacter.Get()->OnActiveStatusEffectsUpdated.Broadcast();
		}
	}
}

void AEXWCharacter::Client_AddStatusEffect_Implementation(FEXWStatusEffectData StatusEffect)
{
	StatusEffectAdded.Broadcast(StatusEffect);
	if (UWorld* World = GetWorld())
	{
		FTimerDelegate TimerDel;
		World->GetTimerManager().SetTimer(StatusEffect.CountdownHandle, TimerDel, StatusEffect.TickingRate, true, StatusEffect.Duration);
	}

}

void AEXWCharacter::Server_RemoveActiveStatusEffect_Implementation(FEXWStatusEffectData StatusEffect)
{
	FEXWStatusEffectData OutStatusEffect;
	if (StatusEffect.TargetCharacter.IsValid())
	{
		AEXWCharacter* TargetCharacter = StatusEffect.TargetCharacter.Get();
		if (TargetCharacter->FindActiveStatusEffect(StatusEffect.ID, OutStatusEffect))
		{
			GetWorld()->GetTimerManager().ClearTimer(OutStatusEffect.TickingTimerHandle);
			GetWorld()->GetTimerManager().ClearTimer(OutStatusEffect.DurationHandle);

			if (OutStatusEffect.StatusEffectActor.IsValid())
			{
				OutStatusEffect.StatusEffectActor.Get()->Destroy(true);
			}
			TargetCharacter->ActiveStatusEffects.RemoveSingle(OutStatusEffect);
			TargetCharacter->Client_RemoveActiveStatusEffect(OutStatusEffect);
			TargetCharacter->OnStatusEffectRemoved(OutStatusEffect);
			StatusEffect.TargetCharacter.Get()->OnActiveStatusEffectsUpdated.Broadcast();
		}

		// Remove time dilation
		if (StatusEffect.MovementModifierValue != 1.f)
		{
			//TargetCharacter->Multicast_SetCustomTimeDilation(1.f);
			TargetCharacter->Multicast_SetCustomTimeDilation(-StatusEffect.MovementModifierValue);
		}
	}
}

void AEXWCharacter::Client_RemoveActiveStatusEffect_Implementation(FEXWStatusEffectData StatusEffect)
{
	StatusEffectRemoved.Broadcast(StatusEffect);
	OnActiveStatusEffectsUpdated.Broadcast();
	GetWorld()->GetTimerManager().ClearTimer(StatusEffect.CountdownHandle);
}

void AEXWCharacter::RemoveAllActiveStatusEffects()
{
	TArray<FEXWStatusEffectData> TempActiveStatusEffects = ActiveStatusEffects; // Avoid dynamic change during access
	for (FEXWStatusEffectData& StatusEffect : TempActiveStatusEffects)
	{
		Server_RemoveActiveStatusEffect(StatusEffect);
	}
	OnActiveStatusEffectsUpdated.Broadcast();
}

void AEXWCharacter::Server_TickStatusEffect_Implementation(FEXWStatusEffectData StatusEffect)
{
	UEXWDataLibrary::ApplyAttributeMultiEffects(StatusEffect.SourceCharacter.Get(), StatusEffect.TargetCharacter.Get(), StatusEffect.AttributeEffects);
}

void AEXWCharacter::Server_SetCustomTimeDilation_Implementation(const float NewTimeDilation /*= 1.f*/)
{
	Multicast_SetCustomTimeDilation(NewTimeDilation);
}

void AEXWCharacter::Multicast_SetCustomTimeDilation_Implementation(const float NewTimeDilation /*= 1.f*/)
{
	//CustomTimeDilation = NewTimeDilation;
	CustomTimeDilation = FMath::Max(1.f, CustomTimeDilation + NewTimeDilation - 1.0f);
}

void AEXWCharacter::OnRep_ActiveStatusEffects()
{
	OnActiveStatusEffectsUpdated.Broadcast();
}

void AEXWCharacter::Server_LevelUp_Implementation()
{
	ProgressionLevel++;
	OnCharacterChangeLevel_Native(ProgressionLevel);
	OnCharacterLevelUp_Native(ProgressionLevel);
}

void AEXWCharacter::Server_SetLevel_Implementation(const int32 NewLevel /*= 1*/)
{
	ProgressionLevel = NewLevel;
	OnCharacterChangeLevel_Native(ProgressionLevel);
}

void AEXWCharacter::OnCharacterLevelUp_Native(const int32 NewLevel)
{
	if (GetMesh() && ParticleSystemOnLevelUp)
	{
		Multicast_SpawnEmitterAttached(ParticleSystemOnLevelUp, GetMesh(), "None", ParticleSystemOnLevelUpOffset, FRotator(0, 0, 0), EAttachLocation::KeepRelativeOffset);
	}
	Client_CallOnRequestNotification(FText::FromString("You are level " + FString::FromInt(NewLevel) + "!"));
	OnCharacterLevelUp(NewLevel);
}

void AEXWCharacter::OnCharacterChangeLevel_Native(const int32 NewLevel)
{
	AbilityPoints += AbilityPointsPerLevel * NewLevel;
	InitializeCharacterData();
	OnCharacterChangeLevel(NewLevel);
}

void AEXWCharacter::Server_SetExperience_Implementation(const int32 NewExperience)
{
	ProgressionExperience = NewExperience;
}

void AEXWCharacter::GainExperience(const int32 ExperienceToGain)
{
	if (ExperiencePerLevel)
	{
		int32 TotalRequiredExperience = ExperiencePerLevel->GetExperience(ProgressionLevel);
		int32 RequiredExperienceToLevelUp = TotalRequiredExperience - ProgressionExperience;
		if (TotalRequiredExperience != -1)
		{
			int32 NewExperience = ProgressionExperience + ExperienceToGain;
			if (NewExperience >= TotalRequiredExperience)
			{
				Server_LevelUp();
				Server_SetExperience(ExperienceToGain - RequiredExperienceToLevelUp);
			}
			else
			{
				Server_SetExperience(ProgressionExperience + ExperienceToGain);
			}
		}
	}
	OnGainExperience_Native(ExperienceToGain);
}

void AEXWCharacter::OnGainExperience_Native(const int32 GainedExperience)
{
	Client_CallOnRequestNotification(FText::FromString("<experienceXP>Obtained " + FString::FromInt(GainedExperience) + " Experience</>"));
	OnGainExperience(GainedExperience);
}

int AEXWCharacter::GetTotalRequiredExperience()
{
	return ExperiencePerLevel->GetExperience(ProgressionLevel);
}

float AEXWCharacter::GetExperiencePercentage()
{
	float TotalRequiredExperience = GetTotalRequiredExperience();
	return ProgressionExperience / TotalRequiredExperience;
}

void AEXWCharacter::UpdateGearItemLevel()
{
	ItemLevel = 0;
	//FTet localItemID;
	int32 localItemLevel;
	TArray<FString> RNG;
	for (FEXWInventorySlot EquipmentItem : InventoryEquipment.ItemSlots)
	{
		UEXWInventoryLibrary::SplitItemGeneratedData(EquipmentItem.ItemID, /*localItemID,*/ localItemLevel, RNG);
		ItemLevel += localItemLevel;
	}
}

bool AEXWCharacter::CanAddState_Implementation(const EEXWState StateToAdd)
{
	// Initialize the variables
	bool bExists = States.Contains(StateToAdd);
	bool bIsNewStateDead = StateToAdd == EEXWState::S_Dead;
	bool bIsNewStateCC = (StateToAdd == EEXWState::S_Stunned ||
		StateToAdd == EEXWState::S_Feared ||
		StateToAdd == EEXWState::S_Silenced ||
		StateToAdd == EEXWState::S_Rooted ||
		StateToAdd == EEXWState::S_KnockedDown ||
		StateToAdd == EEXWState::S_KnockedBack ||
		StateToAdd == EEXWState::S_Disarmed);

	// Super Armor Cancel all CC
	if (StateOverriders.Contains(EEXWStateOverrider::SO_SuperArmor) && bIsNewStateCC)
	{
		return false;
	}

	// Cannot be killed when invincible
	if (StateOverriders.Contains(EEXWStateOverrider::SO_Invincible) && bIsNewStateDead)
	{
		return false;
	}

	// Return true in case everything is okay
	if (!bExists && !IsDead())
	{
		return true;
	}

	return false;
}

void AEXWCharacter::AddState(const EEXWState StateToAdd)
{
	if (!States.Contains(StateToAdd) && !States.Contains(EEXWState::S_Dead))
	{
		// Clear all previous states before adding the death one
		if (StateToAdd == EEXWState::S_Dead)
		{
			States.Empty();
		}

		// Adding the state
		States.AddUnique(StateToAdd);
		OnAddState_Native(StateToAdd);
		if (GetLocalRole() == ROLE_AutonomousProxy)
		{
			Server_AddState(StateToAdd);
		}
	}
}

void AEXWCharacter::Server_AddState_Implementation(const EEXWState StateToAdd)
{
	AddState(StateToAdd);
}

void AEXWCharacter::OnAddState_Native(const EEXWState& AddedState)
{
	OnAddState(AddedState);
	OnStateAdded.Broadcast(AddedState);
}

void AEXWCharacter::RemoveState(const EEXWState StateToRemove)
{
	States.Remove(StateToRemove);
	OnRemoveState_Native(StateToRemove);
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		Server_RemoveState(StateToRemove);
	}
}

void AEXWCharacter::Server_RemoveState_Implementation(const EEXWState StateToRemove)
{
	RemoveState(StateToRemove);
}

void AEXWCharacter::OnRemoveState_Native(const EEXWState& RemovedState)
{
	OnRemoveState(RemovedState);
	OnStateRemoved.Broadcast(RemovedState);
}

void AEXWCharacter::ClearStates()
{
	States.Empty();
	OnStatesCleared.Broadcast();
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		Server_ClearStates();
	}
}

void AEXWCharacter::Server_ClearStates_Implementation()
{
	ClearStates();
}

bool AEXWCharacter::IsValidState(const EEXWState InState)
{
	for (EEXWState& State : States)
	{
		if (State == InState)
		{
			return true;
		}
	}
	return false;
}

bool AEXWCharacter::OneStateIsValid(const TArray<EEXWState> InStates)
{
	for (EEXWState State : InStates)
	{
		if (IsValidState(State))
		{
			return true;
		}
	}
	return false;
}

bool AEXWCharacter::AllStatesAreValid(const TArray<EEXWState> InStates)
{
	for (EEXWState State : InStates)
	{
		if (!IsValidState(State))
		{
			return false;
		}
	}
	return true;
}

bool AEXWCharacter::IsDead()
{
	return States.Contains(EEXWState::S_Dead);
}

bool AEXWCharacter::IsCrowdControlled()
{
	return (States.Contains(EEXWState::S_Stunned) ||
		States.Contains(EEXWState::S_Feared) ||
		States.Contains(EEXWState::S_Silenced) ||
		States.Contains(EEXWState::S_Rooted) ||
		States.Contains(EEXWState::S_KnockedDown) ||
		States.Contains(EEXWState::S_KnockedBack) ||
		States.Contains(EEXWState::S_Disarmed));
}


bool AEXWCharacter::CanAddStateOverrider_Implementation(const EEXWStateOverrider StateOverriderToAdd)
{
	bool bExists = StateOverriders.Contains(StateOverriderToAdd);

	if (!bExists && !IsDead())
	{
		return true;
	}
	return false;
}

void AEXWCharacter::AddStateOverrider(const EEXWStateOverrider StateOverriderToAdd)
{
	if (CanAddStateOverrider(StateOverriderToAdd))
	{
		StateOverriders.AddUnique(StateOverriderToAdd);
		OnAddStateOverrider_Native(StateOverriderToAdd);
		if (GetLocalRole() == ROLE_AutonomousProxy)
		{
			Server_AddStateOverrider(StateOverriderToAdd);
		}
	}
}

void AEXWCharacter::Server_AddStateOverrider_Implementation(const EEXWStateOverrider StateOverriderToAdd)
{
	AddStateOverrider(StateOverriderToAdd);
}

void AEXWCharacter::OnAddStateOverrider_Native(const EEXWStateOverrider& AddedStateOverrider)
{
	OnAddStateOverrider(AddedStateOverrider);
}

void AEXWCharacter::RemoveStateOverrider(const EEXWStateOverrider StateOverriderToRemove)
{
	StateOverriders.Remove(StateOverriderToRemove);
	OnRemoveStateOverrider_Native(StateOverriderToRemove);
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		Server_RemoveStateOverrider(StateOverriderToRemove);
	}
}

void AEXWCharacter::Server_RemoveStateOverrider_Implementation(const EEXWStateOverrider StateOverriderToRemove)
{
	RemoveStateOverrider(StateOverriderToRemove);
}

void AEXWCharacter::OnRemoveStateOverrider_Native(const EEXWStateOverrider& RemovedStateOverrider)
{
	OnRemoveStateOverrider(RemovedStateOverrider);
}

void AEXWCharacter::ClearStateOverriders()
{
	StateOverriders.Empty();
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		Server_ClearStateOverriders();
	}
}

void AEXWCharacter::SetInCombat()
{
	if (UWorld* World = GetWorld())
	{
		if (!bIsInCombat)//&& is in cobat zone?)
		{

			bIsInCombat = true;
			if (CheckHostilesNearby())
			{
				//check after some time if stil in combat
				GetWorldTimerManager().SetTimer(
					InCombatTimerHandle, this, &AEXWCharacter::UpdateIsInCombat, 7.0f, true, 5.0f);
			}
			else
			{
				//check after some time if stil in combat
				GetWorldTimerManager().SetTimer(
					InCombatTimerHandle, this, &AEXWCharacter::UpdateIsInCombat, 5.0f, true, 5.0f);
			}
		}
	}
}

bool AEXWCharacter::CheckHostilesNearby()
{
	const FVector Start = GetActorLocation();
	const FVector End = Start;

	float Radius = 1500.0f;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypeQuery;
	ObjectTypeQuery.Add(UEngineTypes::ConvertToObjectType(ECC_Pawn));

	TArray<AActor*> IgnoreActors;
	IgnoreActors.Add(this);

	TArray<FHitResult> HitResults;

	bool isHit = UKismetSystemLibrary::SphereTraceMultiForObjects
	(GetWorld(),
		Start, End, Radius,
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
	if (isHit)
	{
		for (FHitResult Hit : HitResults)
		{
			if (Hit.Actor->ActorHasTag(FName("Mob")))
			{
				return true;
			}
		}
	}
	return false;
}
void AEXWCharacter::UpdateIsInCombat()
{
	
	if (!CheckHostilesNearby())
	{
		GetWorldTimerManager().ClearTimer(InCombatTimerHandle);
		bIsInCombat = false;
		
	}
	else
	{

	}
}

void AEXWCharacter::Server_ClearStateOverriders_Implementation()
{
	ClearStateOverriders();
}

bool AEXWCharacter::StartCooldown(FEXWCooldown& Cooldown)
{
	if (UWorld* World = GetWorld()) {
		FTimerDelegate TimerDel;
		TimerDel.BindUFunction(this, FName("EndCooldown"), Cooldown.ID);
		World->GetTimerManager().SetTimer(Cooldown.TimerHandle, TimerDel, 1.f, true, Cooldown.Duration);
		AddCooldownToStack(Cooldown);
		return true;
	}
	return false;
}

void AEXWCharacter::EndCooldown(const FName CooldownID)
{
	FEXWCooldown Cooldown(CooldownID);
	if (GetCooldown(CooldownID, Cooldown))
	{
		if (UWorld* World = GetWorld())
			World->GetTimerManager().ClearTimer(Cooldown.TimerHandle);
		RemoveCooldownFromStack(CooldownID);
		OnEndCooldown_Native(Cooldown);
	}
}

void AEXWCharacter::OnEndCooldown_Native(const FEXWCooldown& Cooldown)
{
	OnEndCooldown(Cooldown);
}

bool AEXWCharacter::GetCooldown(const FName InID, FEXWCooldown& OutCooldown)
{
	for (FEXWCooldown Cooldown : CooldownStack)
	{
		if (Cooldown.ID == InID)
		{
			OutCooldown = Cooldown;
			return true;
		}
	}
	return false;
}

bool AEXWCharacter::IsCooldownReady(const FName InID)
{
	FEXWCooldown Cooldown;
	return !GetCooldown(InID, Cooldown);
}

bool AEXWCharacter::GetCooldownTimer(const FName InCooldownID, float& Elapsed, float& Remaining)
{
	FEXWCooldown Cooldown;
	if (GetCooldown(InCooldownID, Cooldown))
	{
		if (UWorld* World = GetWorld()) {
			Elapsed = World->GetTimerManager().GetTimerElapsed(Cooldown.TimerHandle);
			Remaining = World->GetTimerManager().GetTimerRemaining(Cooldown.TimerHandle);
			return true;
		}
	}
	Elapsed = -1;
	Remaining = -1;
	return false;
}

void AEXWCharacter::OnNotifyCooldown_Native(const FName& CooldownID, const float& Elapsed, const float& Remaining)
{
	OnNotifyCooldown(CooldownID, Elapsed, Remaining);
}

void AEXWCharacter::AddCooldownToStack(FEXWCooldown& Cooldown)
{
	CooldownStack.AddUnique(Cooldown);
	if (GetLocalRole() == ROLE_AutonomousProxy)
	{
		Server_AddCooldownToStack(Cooldown);
	}
}

void AEXWCharacter::Server_AddCooldownToStack_Implementation(FEXWCooldown Cooldown)
{
	AddCooldownToStack(Cooldown);
}

void AEXWCharacter::RemoveCooldownFromStack(const FName CooldownID)
{
	for (FEXWCooldown& Cooldown : CooldownStack)
	{
		if (Cooldown.ID == CooldownID)
		{
			CooldownStack.RemoveSingle(Cooldown);
			if (GetLocalRole() == ROLE_AutonomousProxy)
			{
				Server_AddCooldownToStack(Cooldown);
			}
			return;
		}
	}

}

void AEXWCharacter::Server_RemoveCooldownFromStack_Implementation(const FName CooldownID)
{
	RemoveCooldownFromStack(CooldownID);
}

void AEXWCharacter::Server_SetActiveAbilities_Implementation(const TArray<FEXWAction>& Actions)
{
	AvailableActions = Actions;
	for (FEXWAction Action : AvailableActions)
	{
		if (Action.bIsPassive)
		{
			Server_ConstructStatusEffect(Action.StatusEffect, this, this);
		}
	}
}

void AEXWCharacter::SetActiveAbilities_Implementation(const TArray<FEXWAction>& Actions)
{
	Server_SetActiveAbilities(Actions);
	OnSetActiveAbilitiesEvent(Actions);
	OnAvailableActionsSet.Broadcast();
}

void AEXWCharacter::Server_SetIFrameActions_Implementation(const TArray<FEXWAction>& Actions)
{
	IFrameActions = Actions;
}

void AEXWCharacter::SetIFrameActions_Implementation(const TArray<FEXWAction>& Actions)
{
	Server_SetIFrameActions(Actions);
	OnSetIFrameActionsEvent(Actions);
	OnIFrameActionsSet.Broadcast();
}

void AEXWCharacter::Server_AddAbility_Implementation(FEXWAction Action)
{
	AvailableActions.Add(Action);
	if (Action.bIsPassive)
	{
		Server_ConstructStatusEffect(Action.StatusEffect, this, this);
	}
}

void AEXWCharacter::AddAbility_Implementation(FEXWAction Action)
{
	Server_AddAbility(Action);
	OnAddAbilityEvent(Action);
	OnAbilityAdded.Broadcast(Action);
}

void AEXWCharacter::Server_RemoveAbility_Implementation(FEXWAction Action)
{
	AvailableActions.Remove(Action);
	if (Action.bIsPassive)
	{
		FEXWStatusEffectData StatusEffect;
		UEXWDataLibrary::GetStatusEffectData(Action.StatusEffect, StatusEffect);
		Server_RemoveActiveStatusEffect(StatusEffect);
	}


}

void AEXWCharacter::RemoveAbility_Implementation(FEXWAction Action)
{
	Server_RemoveAbility(Action);
	OnRemoveAbilityEvent(Action);
	OnAbilityRemoved.Broadcast(Action);
}

EEXWActionExecutionResult AEXWCharacter::ExecuteActionFull(const FName RowName /*= "Row_Name_Here"*/)
{
	// Find data table
	UDataTable* ActionDT;
	if (UEXWDataLibrary::GetActionDT(ActionDT))
	{
		static const FString ContextString(TEXT("ActionDT"));
		FEXWAction* Action = ActionDT->FindRow<FEXWAction>(RowName, ContextString, true);

		// Check if the the row data was found.
		if (Action)
		{
			if (Action->bEnableTargeting && ActionToExecute.ID != Action->ID)
			{
				if ((*Action).bEnableTargeting)
				{
					StartTargeting((*Action).TargetingParams);
				}
				ActionToExecute = *Action;
				SpawnAbilityIndicator(ActionToExecute.IndicatorClass);
				return EEXWActionExecutionResult::AER_IsTargeting;

			}
			else
			{
				// Ability is already ready, so clean the temp values and execute the actions
				if ((*Action).bEnableTargeting)
				{
					CleanUpActionExecution(true);
					//CleanUpActionExecution(false);
				}
				return ExecuteAction(*Action);
			}
		}
		else
		{
			UE_LOG(EXWCharLog, Warning, TEXT("<%s> Action with Data Table Row [%s] not found."), *Name.ToString(), *RowName.ToString());
		}
	}
	else
	{
		UE_LOG(EXWCharLog, Warning, TEXT("<%s> Error Executing Action with ID [%s] due to a missing Data table reference in the Singleton"), *Name.ToString(), *RowName.ToString());
	}
	return EEXWActionExecutionResult::AER_DataTableNotFound;
}

EEXWActionExecutionResult AEXWCharacter::ExecuteActionFullByAction(FEXWAction Action)
{
	if (Action.bEnableTargeting && ActionToExecute.ID != Action.ID)
	{
		if (Action.bEnableTargeting)
		{
			StartTargeting(Action.TargetingParams);
		}
		ActionToExecute = Action;
		SpawnAbilityIndicator(ActionToExecute.IndicatorClass);
		return EEXWActionExecutionResult::AER_IsTargeting;
	}
	else
	{
		// Ability is already ready, so clean the temp values and execute the actions
		if (Action.bEnableTargeting)
		{
			CleanUpActionExecution(true);
		}
		return ExecuteAction(Action);
	}


	return EEXWActionExecutionResult::AER_UnknownError;
}

void AEXWCharacter::ExecuteActionFullByIndex(int32 Index)
{
	if (AvailableActions.IsValidIndex(Index))
	{
		if (Index == 0)
		{
			if (bIsTargeting && !ActionToExecute.ID.IsNone())
			{
				
				FEXWAction TempAction = ActionToExecute;
				// Ability is already ready, so clean the temp values and execute the actions
				if (TempAction.bEnableTargeting)
				{
					CleanUpActionExecution(true);
				}
				ExecuteAction(TempAction);
				return;
			}
			if (AEXWPlayerController* PlayerController = Cast<AEXWPlayerController>(GetController())) 
			{
				if (!PlayerController->bShowMouseCursor)
				{
					ExecuteActionFullByAction(AvailableActions[Index]);
				}
				else 
				{
					AActor* InteractableActor;
					if(PlayerController->GetInteractableUnderCursor(InteractableActor,1000))
					{
						if (AEXWCharacter* InteractablePawn = Cast<AEXWCharacter>(InteractableActor))
						{
							UEXWDataLibrary::UpdateLastAffectedPlayer(this,InteractablePawn);
							Server_UpdateLastAffectedPlayer(this,InteractablePawn);
							//LastCharacterAffected=InteractablePawn;
							//InteractablePawn->LastCharacterAffectedBy=this;
						}
					}
					PlayerController->ToggleInteractMenu(nullptr);
				}
			}
		}
		else {
			ExecuteActionFullByAction(AvailableActions[Index]);
		}

	}
	else {
		UE_LOG(EXWCharLog, Warning, TEXT("Ability doesn't exist"));
	}

}

void AEXWCharacter::ExecuteIFrameActionFullByIndex(int32 Index)
{
	if (IFrameActions.IsValidIndex(Index))
	{
		ExecuteActionFullByAction(IFrameActions[Index]);
	}
	else {
		UE_LOG(EXWCharLog, Warning, TEXT("IFrame Ability doesn't exist"));
	}
}

EEXWActionExecutionResult AEXWCharacter::ExecuteActionByDT(const FName RowName /*= "Row_Name_Here"*/)
{
	// Find data table
	UDataTable* ActionDT;
	if (UEXWDataLibrary::GetActionDT(ActionDT))
	{
		static const FString ContextString(TEXT("ActionDT"));
		FEXWAction* Action = ActionDT->FindRow<FEXWAction>(RowName, ContextString, true);

		// Check if the the row data was found.
		if (Action)
		{
			// Execute action
			FEXWAction ActionTemp = *Action;
			return ExecuteAction(ActionTemp);
		}
		else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Action with Data Table Row [%s] not found."), *Name.ToString(), *RowName.ToString());
	}
	else UE_LOG(EXWCharLog, Warning, TEXT("<%s> Error Executing Action with ID [%s] due to a missing Data table reference in the Singleton"), *Name.ToString(), *RowName.ToString());
	return EEXWActionExecutionResult::AER_DataTableNotFound;
}

EEXWActionExecutionResult AEXWCharacter::ExecuteAction(const FEXWAction& InAction)
{
	EEXWActionExecutionResult ExecResult = CanExecuteAction(InAction);
	if (ExecResult == EEXWActionExecutionResult::AER_Success)
	{
		LastActiveAction = InAction;

		TArray<FEXWMontageData> MontagesData = GetValidMontagesDataForAction(InAction);

		if (MontagesData.Num() == 0)
		{
			UE_LOG(EXWCharLog, Log, TEXT("<%s> No montages data were found fitting the current direction and states. Canot execute the action with ID [%s]."), *Name.ToString(), *InAction.ID.ToString());
			return EEXWActionExecutionResult::AER_NoValidMontageData;
		}

		// Consume the attributes required
		Server_LoseAttribute(InAction.Attribute, InAction.Value);

		// Add to the cooldown stack
		if (InAction.Cooldown > 0.f) {
			FEXWCooldown Cooldown = FEXWCooldown(InAction.ID, InAction.Cooldown);
			StartCooldown(Cooldown);
		}

		// Check if the ComboCounter is exceeding the combo count in the current action.
		if (ComboCounter >= MontagesData.Num() || !MontagesData.IsValidIndex(ComboCounter))
		{
			ComboCounter = 0;
		}

		// Play the resulting montage
		if (MontagesData[ComboCounter].AnimMontage)
		{
			float CastSpeed = 1.f;
			if(!ActorHasTag(FName("Mob")))
			{
				GetAttributeCurrentValue(EEXWAttributeType::CastSpeed, CastSpeed);
			}
			
			if (MontagesData[ComboCounter].DirectionMode==EEXWDirectionMode::CameraRotation)
			{
				RotateCharacterTowardsCameraDirection();
			}
			Replicated_PlayMontage(MontagesData[ComboCounter].AnimMontage,CastSpeed);
		}
		else
		{
			ComboCounter = 0;
			UE_LOG(EXWCharLog, Warning, TEXT("<%s> Montage is Invalid with the Action ID [%s]."), *Name.ToString(), *InAction.ID.ToString());
			return EEXWActionExecutionResult::AER_NoAnimMontage;
		}

		// Move to the next montage if available, next time we perform an action
		ComboCounter++;
		SetInCombat();
	}
	else
	{
		UE_LOG(EXWCharLog, Log, TEXT("<%s> Cannot execute action with ID [%s]."), *Name.ToString(), *InAction.ID.ToString());
	}
	return ExecResult;
}

EEXWActionExecutionResult AEXWCharacter::CanExecuteAction(const FEXWAction& InAction)
{
	// Check Cooldown
	bool bIsCooldownValid = true;
	FEXWCooldown Cooldown;
	float TimeElapsed;
	float TimeRemaining;
	if (GetCooldownTimer(InAction.ID, TimeElapsed, TimeRemaining) && InAction.Cooldown > 0.f) {
		OnNotifyCooldown_Native(InAction.ID, TimeElapsed, TimeRemaining);
		bIsCooldownValid = false;
	}

	// Check Attribute
	bool bHasEnoughAttribute = HasEnoughAttribute(InAction.Attribute, InAction.Value);

	//Check States
	bool bIsSilenced = IsValidState(EEXWState::S_Silenced);// && AvailableActions.Contains(InAction); Only disable abilities and not auto attacks
	bool bIsDisarmed = IsValidState(EEXWState::S_Disarmed);// && DefaultActions.Contains(InAction); Only Disable Auto Attacks and IFrame Abilities
	bool bIsGathering = IsValidState(EEXWState::S_Gathering);// && DefaultActions.Contains(InAction); Only Disable Auto Attacks and IFrame Abilities when gathering

	if (bIsCooldownValid && bHasEnoughAttribute && bWeaponEquipped && !bIsSilenced && !bIsDisarmed && !InAction.bIsPassive && !bIsGathering)//Player
	{
		return EEXWActionExecutionResult::AER_Success;
	}
	else if (bIsCooldownValid && bHasEnoughAttribute && !bWeaponEquipped && !IsPlayerControlled() && !bIsSilenced && !bIsDisarmed && !InAction.bIsPassive) //AI
	{
		return EEXWActionExecutionResult::AER_Success;
	}
	else if (!bIsCooldownValid)
	{
		if (!(InAction.ID.ToString().Contains("Light_Auto", ESearchCase::IgnoreCase) || InAction.ID.ToString().Contains("LightAuto", ESearchCase::IgnoreCase)))
		{
			Client_CallOnRequestNotification(FText::FromString("This ability is on cooldown"));
		}
		return EEXWActionExecutionResult::AER_OnCooldown;
	}
	else if (!bHasEnoughAttribute)
	{
		Client_CallOnRequestNotification(FText::FromString("Not enough mana/rage")); // TODO : Create a converter to text from the display name and use InAction.Attribute
		return EEXWActionExecutionResult::AER_NotEnoughAttribute;
	}
	else if (!bWeaponEquipped && IsPlayerControlled()) {
		Client_CallOnRequestNotification(FText::FromString("No weapon equipped"));
		return EEXWActionExecutionResult::AER_NoWeapon;
	}
	else if (bIsSilenced)
	{
		Client_CallOnRequestNotification(FText::FromString("Silenced"));
		return EEXWActionExecutionResult::AER_IsSilenced;
	}
	else if (bIsDisarmed)
	{
		Client_CallOnRequestNotification(FText::FromString("Disarmed"));
		return EEXWActionExecutionResult::AER_Disarmed;
	}
	else if (InAction.bIsPassive)
	{
		Client_CallOnRequestNotification(FText::FromString("Passive Ability"));
		return EEXWActionExecutionResult::AER_IsPassive;
	}
		else if (bIsGathering)
	{
		//Client_CallOnRequestNotification(FText::FromString("Gathering"));
		return EEXWActionExecutionResult::AER_InvalidState;
	}

	return EEXWActionExecutionResult::AER_UnknownError;
}

TArray<FEXWMontageData> AEXWCharacter::GetValidMontagesDataForAction(const FEXWAction& InAction)
{
	// Check for valid montages data
	TArray<FEXWMontageData> ValidMontages;

	//get required montage data from DT based on gender
	TArray<FEXWMontageData> MontagesData;
	if (InAction.bIsGenderFree)
	{
		MontagesData = InAction.MontagesData;
	}
	else
	{
		if (Gender == EEXWGender::G_Female)
		{
			MontagesData = InAction.FemaleMontagesData;
		}
		else
		{
			MontagesData = InAction.MaleMontagesData;
		}
	}

	for (FEXWMontageData MontageData : MontagesData)
	{
		bool bIsValidDirection = false;
		bool bIsValidState = false;

		// Set the Direction bool
		float CharacterDirection = 0;
		if (MontageData.Direction == EEXWActionDirection::AD_Any || MontageData.Direction == GetCharacterDirection(MontageData.DirectionMode, CharacterDirection))
		{
			bIsValidDirection = true;
		}
		// Set the valid state bool
		if (MontageData.bIsStateFree)
		{
			if (States.Num() == 0)
			{
				bIsValidState = true;
			}
		}
		else if (OneStateIsValid(MontageData.ValidStates))
		{
			bIsValidState = true;
		}

		// Check both booleans
		if (bIsValidState && bIsValidDirection)
		{
			ValidMontages.Add(MontageData);
		}
	}
	return ValidMontages;
}

void AEXWCharacter::CleanUpActionExecution(const bool bStopTargeting)
{
	
	ActionToExecute = FEXWAction();
	DestroyAbilityIndicator();
	if (bStopTargeting)
	{
		StopTargeting();
	}
}

void AEXWCharacter::SendReaction(FEXWReactionSendingParams& ReactionSendingParams)
{
	if (ReactionSendingParams.SourceCharacter && ReactionSendingParams.TargetCharacter)
	{
		if (IsLocallyControlled())
		{
			ReactionSendingParams.TargetCharacter->OnReceiveReaction_Native(ReactionSendingParams);
		}
		if (HasAuthority())
		{
			Multicast_SendReaction(ReactionSendingParams);
		}
		else
		{
			Server_SendReaction(ReactionSendingParams);
		}
	}
}

void AEXWCharacter::Server_SendReaction_Implementation(const FEXWReactionSendingParams& ReactionSendingParams)
{
	Multicast_SendReaction(ReactionSendingParams);
}

void AEXWCharacter::Multicast_SendReaction_Implementation(const FEXWReactionSendingParams& ReactionSendingParams)
{
	if (ReactionSendingParams.SourceCharacter && ReactionSendingParams.TargetCharacter) // As this may take time to be processed due to latency, the characters may get destroyed and cause a null ptr 
	{
		if (!ReactionSendingParams.SourceCharacter->IsLocallyControlled())
		{
			ReactionSendingParams.TargetCharacter->OnReceiveReaction_Native(ReactionSendingParams);
		}
	}
}

void AEXWCharacter::OnReceiveReaction_Native(const FEXWReactionSendingParams& ReactionSendingParams)
{
	ExecuteReaction(ReactionSendingParams);
	OnReceiveReaction(ReactionSendingParams);
}

void AEXWCharacter::ExecuteReaction(const FEXWReactionSendingParams& ReactionSendingParams)
{
	if (ReactionSendingParams.SourceCharacter && ReactionDataTable)
	{
		static const FString ContextString(TEXT("ReactionDataTable"));
		FEXWReaction* ReactionData = NULL;
		ReactionData = ReactionDataTable->FindRow<FEXWReaction>(FName(ReactionSendingParams.RowName), ContextString, true);
		if (ReactionData)
		{
			TArray<FEXWReactionMontage> MontagesData = GetValidMontagesDataForReaction(*ReactionData, ReactionSendingParams.SourceCharacter);
			if (MontagesData.Num() == 0)
			{
				UE_LOG(EXWCharLog, Log, TEXT("<%s> No montages data were found fitting the states for the ID [%s] for Reaction execution."), *Name.ToString(), *ReactionSendingParams.RowName.ToString());
				return;
			}
			// Play the resulting montage (with 1.f speed, which can differ later depending on some other vars)
			int32 RandomMontageIndex = UKismetMathLibrary::RandomInteger(MontagesData.Num());
			if (MontagesData.IsValidIndex(RandomMontageIndex))
			{
				if (MontagesData[RandomMontageIndex].AnimMontage && GetMesh()->GetAnimInstance())
				{
					GetMesh()->GetAnimInstance()->Montage_Play(MontagesData[RandomMontageIndex].AnimMontage, 1.f);
				}
				else
				{
					UE_LOG(EXWCharLog, Log, TEXT("<%s> No Anim montage was found in the ID [%s] for Reaction execution."), *Name.ToString(), *ReactionSendingParams.RowName.ToString());
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("<%s> Unable to find row in order to execute the received reaction."), *Name.ToString());
		}
	}
}

TArray<FEXWReactionMontage> AEXWCharacter::GetValidMontagesDataForReaction(const FEXWReaction& InReaction, AEXWCharacter* SourceCharacter)
{
	//get required montage data from DT based on gender
	TArray<FEXWReactionMontage> MontagesData;
	if (InReaction.bIsGenderFree)
	{
		MontagesData = InReaction.MontagesData;
	}
	else
	{
		if (Gender == EEXWGender::G_Female)
		{
			MontagesData = InReaction.FemaleMontagesData;
		}
		else
		{
			MontagesData = InReaction.MaleMontagesData;
		}
	}
	// Check for valid montages data
	TArray<FEXWReactionMontage> ValidMontages;
	for (FEXWReactionMontage ReactionMontage : MontagesData)
	{
		bool bIsValidRelativePosition = false;
		bool bIsValidState = false;

		float OutRelativePosValue = 0;
		if (UEXWDataLibrary::GetRelativePosition(this, SourceCharacter, OutRelativePosValue) == ReactionMontage.RelativePosition)
		{
			bIsValidRelativePosition = true;
		}
		if (States.Num() == 0 && ReactionMontage.bIsStateFree)
		{
			bIsValidState = true;
		}
		/*if (OneStateIsValid(ReactionMontage.ValidStates))
		{
			bIsValidState = true; / To put this back like the action system
		}*/
		if (bIsValidState && bIsValidRelativePosition)
		{
			ValidMontages.Add(ReactionMontage);
		}
	}
	// In case no accurate montage was found
	if (ValidMontages.Num() == 0)
	{
		for (FEXWReactionMontage ReactionMontage : MontagesData)
		{
			if (OneStateIsValid(ReactionMontage.ValidStates))
			{
				ValidMontages.Add(ReactionMontage);
			}
		}
	}
	return ValidMontages;
}

bool AEXWCharacter::SpawnAbilityIndicator(TSubclassOf<AEXWSpawnableAbilityIndicator> IndicatorClass)
{
	if (UWorld* World = GetWorld())
	{
		if (IndicatorClass)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = this;
			ActiveAbilityIndicator = MakeWeakObjectPtr<AEXWSpawnableAbilityIndicator>
				(World->SpawnActor<AEXWSpawnableAbilityIndicator>(IndicatorClass, FVector::ZeroVector, FRotator(0, 0, 0), SpawnParams));
			if (ActiveAbilityIndicator.IsValid())
			{
				ActiveAbilityIndicator.Get()->SetOwnerCharacter(this);
				return true;
			}
		}
	}
	return false;
}

bool AEXWCharacter::DestroyAbilityIndicator()
{
	if (ActiveAbilityIndicator.IsValid())
	{
		ActiveAbilityIndicator.Get()->Destroy();
		ActiveAbilityIndicator.Reset();
		return true;
	}
	return false;
}

void AEXWCharacter::Replicated_ApplyAttributeMultiEffects(AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect>& AttributeEffects)
{
	if (HasAuthority())
	{
		UEXWDataLibrary::ApplyAttributeMultiEffects(this, TargetCharacter, AttributeEffects);
	}
	else
	{
		Server_ApplyAttributeMultiEffects(this, TargetCharacter, AttributeEffects);
	}
}

void AEXWCharacter::Server_ApplyAttributeMultiEffects_Implementation(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect>& AttributeEffects)
{
	UEXWDataLibrary::ApplyAttributeMultiEffects(SourceCharacter, TargetCharacter, AttributeEffects);
}

void AEXWCharacter::Server_ApplyAttributeNotify_Implementation(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect AttributeEffect)
{
	SourceCharacter->Client_ApplyAttributeNotify(SourceCharacter, TargetCharacter, AttributeEffect);
	TargetCharacter->Client_ApplyAttributeNotify(SourceCharacter, TargetCharacter, AttributeEffect);
}

void AEXWCharacter::Client_ApplyAttributeNotify_Implementation(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect AttributeEffect)
{
	OnClientApplyAttribute_Native(SourceCharacter, TargetCharacter, AttributeEffect);
}

void AEXWCharacter::OnClientApplyAttribute_Native(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect AttributeEffect)
{
	if (AEXWPlayerController* PlayerController = Cast<AEXWPlayerController>(GetController()))
	{
		EEXWAttributeEffectType AttributeEffectType = EEXWAttributeEffectType::AET_PhysicalDamage;
		if (AttributeEffect.AttributeType == EEXWAttributeType::Health)
		{
			float AttributeValue;
			float Value = UEXWDataLibrary::GetAttributeEffectValue(SourceCharacter, TargetCharacter, AttributeEffect.ValueType, AttributeEffect.StaticValue, AttributeEffect.ValueAttributeType, AttributeEffect.ValueAttributePrecentage);
			if (AttributeEffect.EffectType == EEXWEffectType::Gain)
			{
				AttributeEffectType = EEXWAttributeEffectType::AET_Heal;
			}
			else
			{
						// Modify the damage taken here depending on some armor or resistance or position compared to the character.
				float ResultRotationValue = 0;
				bool bDamageCauserIsFront = UEXWDataLibrary::GetRelativePosition(this, SourceCharacter, ResultRotationValue) == EEXWRelativePosition::RP_Front;
				if (IsValidState(EEXWState::S_Blocking) && bDamageCauserIsFront)
				{
					Value = 0;
				}
				else if (AttributeEffect.DamageType == UEXWPhysicalDamageType::StaticClass())
				{
					AttributeEffectType = EEXWAttributeEffectType::AET_PhysicalDamage;
					
					TargetCharacter->GetAttributeCurrentValue(EEXWAttributeType::Defense, AttributeValue);

					Value = Value - (Value * (FMath::LogX(2, AttributeValue + 15) * 10 - 13.5) / 100);
				}
				else if (AttributeEffect.DamageType == UEXWMagicalDamageType::StaticClass())
				{
					AttributeEffectType = EEXWAttributeEffectType::AET_MagicalDamage;

					TargetCharacter->GetAttributeCurrentValue(EEXWAttributeType::MagicDefense, AttributeValue);
					Value = Value - (Value * (FMath::LogX(2, AttributeValue + 15) * 10 - 13.5) / 100);
				}

				//Damage Absorption Mechanic
				Value = TargetCharacter->GetDamageAbsorptionValue(AttributeEffect.DamageType, Value);

				//Damage Reduction Mechanic
				float DamageReductionValue = TargetCharacter->GetDamageReductionValue(AttributeEffect.DamageType);
				if (DamageReductionValue > 0.f)
				{
					//Clamp it to zero so it doesn't go below it and cause the reverse of the wanted effect
					Value = FMath::Max(0.f, Value - ((DamageReductionValue / 100) * Value));

				}
			}
			//UE_LOG(LogTemp, Warning, TEXT("ClientAttributeLoss : %s"), *FString::SanitizeFloat(Value));
			//UE_LOG(LogTemp, Warning, TEXT("ClientAttribute : %s"), AttributeEffect.DamageType);

			// TODO : Add critical checker



			if (Value > 0.f)
			{
				if (UEXWFloatingWidget* FloatingTextWidget = PlayerController->CreateFloatingTextWidget(TargetCharacter, Value, AttributeEffectType, false))
				{
					FloatingTextWidget->AddToViewport();
				}
			}
		}
	}
	OnClientApplyAttribute(SourceCharacter, TargetCharacter, AttributeEffect);
}

void AEXWCharacter::SetCanUseTargeting_Implementation(bool NewTargeting)
{
	bCanUseTargeting = NewTargeting;
}

TArray<AEXWCharacter*> AEXWCharacter::GetAllTargets()
{
	return TargetCharacters;
}

void AEXWCharacter::StartTargeting(const FEXWTargetingParams& NewTargetingParams)
{
	// Stop targeting
	if (bIsTargeting)
	{
		CleanUpActionExecution(false);
	}

	TargetingParams = NewTargetingParams;
	bIsTargeting = true;
	OnStartTargeting_Native(TargetingParams);
}


void AEXWCharacter::StartDefaultTargeting()
{
	if (AEXWPlayerController* PlayerController = Cast<AEXWPlayerController>(GetController())) {
		if (PlayerController->bShowMouseCursor)
		{
			PlayerController->ClickOnInteractable();
		}
		else if (bCanUseTargeting && !PlayerController->bShowMouseCursor) StartTargeting(DefaultTargetingParams);
	}

}

void AEXWCharacter::StopTargeting()
{
	if (UWorld* World = GetWorld())
	{
		FTimerDelegate TimerDelegate;
		TWeakObjectPtr<AEXWCharacter> WeakObjPtr = MakeWeakObjectPtr<AEXWCharacter>(this);
		TimerDelegate.BindLambda([WeakObjPtr] {
			// Using TWeakObjPtr because this can lead to a crash when switching from a level to another while the timer is active
			// or during any change to the pointer
			if (WeakObjPtr.IsValid())
			{
				WeakObjPtr.Get()->bIsTargeting = false;
				WeakObjPtr.Get()->ClearTargets();
				//WeakObjPtr.Get()->GetWorld()->GetTimerManager().ClearTimer(WeakObjPtr.Get()->TargetingTimerHandle);
				WeakObjPtr.Get()->OnStopTargeting_Native(WeakObjPtr.Get()->TargetingParams);
			}
			});
		World->GetTimerManager().SetTimer(TargetingTimerHandle, TimerDelegate, .1f, false, TargetingParams.StopTargetingDelay);
	}
}

void AEXWCharacter::ProcessTargeting()
{
	if (bIsTargeting)
	{
		// This is going to be for single targeting
		TArray<AEXWCharacter*> CharactersFound = GetAimedCharacters(TargetingParams);
		SetTargets(CharactersFound);
		OnProcessTargeting_Native(TargetingParams, CharactersFound);
	}
	else if (TargetCharacters.Num() > 0)
	{
		ClearTargets();
	}
	// Lock On Abilities
	// Using Crosshair
	/*else if (AEXWCharacter* CharacterFound = GetTargetFromCrosshair(DefaultLockOnTargetingDistance, false))
	{
		TArray<AEXWCharacter*> Characters;
		Characters.AddUnique(CharacterFound);
		SetTargets(Characters);
	}*/
	

	
}

void AEXWCharacter::SetPrimaryTarget(AEXWCharacter* TargetCharacter)
{
	if (TargetCharacter)
	{
		if (TargetCharacters.IsValidIndex(0))
		{
			if (TargetCharacters[0] != TargetCharacter)
			{
				UE_LOG(EXWCharLog, Log, TEXT("Target Wasn't stored"));
				ClearTargets();
				AddTarget(TargetCharacter);
				OnSetPrimaryTarget_Native(TargetCharacter);
			}
		}
		else
		{
			AddTarget(TargetCharacter);
		}
	}
}

void AEXWCharacter::SetTargets(TArray<AEXWCharacter*> NewTargetCharacters)
{
	if (TargetCharacters != NewTargetCharacters)
	{
		ClearTargets();
		TargetCharacters = NewTargetCharacters;

		// Highlighting process
		if (TargetingParams.bHighlightTarget)
		{
			FEXWHighlightData HighlightData = UEXWDataLibrary::GetHighlightData();
			FLinearColor HighlightColor;
			if (TargetingParams.TargetFaction == EEXWTargetFaction::TF_OtherFactionOnly)
			{
				HighlightColor = HighlightData.HighlightEnemyColor;
			}
			else if (TargetingParams.TargetFaction == EEXWTargetFaction::TF_OwnerFactionOnly)
			{
				HighlightColor = HighlightData.HighlightAllyColor;
			}
			else if (TargetingParams.TargetFaction == EEXWTargetFaction::TF_ALLFactions)
			{
				HighlightColor = HighlightData.HighlightNeutralColor;
			}
			HighlightAllTargets(HighlightData.HighlightMaterialParamName, HighlightColor);
		}
		OnSetTargets_Native(NewTargetCharacters);
	}
}

bool AEXWCharacter::AddTarget(AEXWCharacter* TargetCharacter)
{
	if (TargetCharacter)
	{
		if (!TargetCharacters.Contains(TargetCharacter))
		{
			TargetCharacters.AddUnique(TargetCharacter);
			OnAddTarget_Native(TargetCharacter);
			return true;
		}
	}
	return false;
}

bool AEXWCharacter::RemoveTarget(AEXWCharacter* TargetCharacter)
{
	if (TargetCharacter)
	{
		if (TargetCharacters.Contains(TargetCharacter))
		{
			TargetCharacters.Remove(TargetCharacter);
			OnRemoveTarget_Native(TargetCharacter);
			return true;
		}
	}
	return false;
}

void AEXWCharacter::ClearTargets()
{
	UnhighlightAllTargets(UEXWDataLibrary::GetHighlightData().HighlightMaterialParamName);
	OnClearTargets_Native(TargetCharacters);
	TargetCharacters.Empty();
}

void AEXWCharacter::Server_UpdateLastAffectedPlayer_Implementation(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter)
{
	UEXWDataLibrary::UpdateLastAffectedPlayer(SourceCharacter,TargetCharacter);
}

void AEXWCharacter::OnStartTargeting_Native(const FEXWTargetingParams& NewTargetingParams)
{
	OnStartTargeting(NewTargetingParams);
}

void AEXWCharacter::OnStopTargeting_Native(const FEXWTargetingParams& RemovedTargetingParams)
{
	OnStopTargeting(RemovedTargetingParams);
}

void AEXWCharacter::OnSetPrimaryTarget_Native(AEXWCharacter* TargetCharacter)
{
	OnSetPrimaryTarget(TargetCharacter);
}

void AEXWCharacter::OnSetTargets_Native(const TArray<AEXWCharacter*>& NewTargetCharacters)
{
	OnSetTargets(NewTargetCharacters);
}

void AEXWCharacter::OnAddTarget_Native(AEXWCharacter* TargetCharacter)
{
	OnAddTarget(TargetCharacter);
}

void AEXWCharacter::OnRemoveTarget_Native(AEXWCharacter* TargetCharacter)
{
	OnRemoveTarget(TargetCharacter);
}

void AEXWCharacter::OnClearTargets_Native(const TArray<AEXWCharacter*>& ClearedTargets)
{
	OnClearTargets(ClearedTargets);
}

void AEXWCharacter::OnProcessTargeting_Native(const FEXWTargetingParams& CurrentTargetingParams, const TArray<AEXWCharacter*>& FoundTargets)
{
	FRotator TargetRotation;
	if (FoundTargets.Num() > 0)
	{
		AEXWCharacter* TargetCharacter = UEXWDataLibrary::GetClosestCharacter(this, FoundTargets);
		TargetRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetCharacter->GetActorLocation());
	}
	else
	{
		TargetRotation = GetBaseAimRotation();
	}
	TargetRotation = FRotator(GetActorRotation().Pitch, TargetRotation.Yaw, GetActorRotation().Roll);
	TargetRotation = UKismetMathLibrary::RInterpTo(GetActorRotation(), TargetRotation, UGameplayStatics::GetWorldDeltaSeconds(this), 5.f);
	Replicated_SetActorLocationAndRotation(GetActorLocation(), TargetRotation);

	OnProcessTargeting(CurrentTargetingParams, FoundTargets);
}

void AEXWCharacter::HighlightCharacter(AEXWCharacter* TargetCharacter, FName ParamName /*= "HighlightColor"*/, FLinearColor Color /*= FColor::Red*/)
{
	if (TargetCharacter)
	{
		TArray<UActorComponent*> ComponentsFound;
		TargetCharacter->GetComponents(USkeletalMeshComponent::StaticClass(), ComponentsFound);
		for (UActorComponent* TempComp : ComponentsFound)
		{
			if (USkeletalMeshComponent* MeshComp = Cast<USkeletalMeshComponent>(TempComp))
			{
				MeshComp->SetVectorParameterValueOnMaterials(ParamName, FVector(Color));
				MeshComp->SetScalarParameterValueOnMaterials("ExponentIn", -0.05f);
			}
		}
	}
}

void AEXWCharacter::UnhighlightCharacter(AEXWCharacter* TargetCharacter, FName ParamName /*= "HighlightColor"*/)
{
	if (TargetCharacter)
	{
		TArray<UActorComponent*> ComponentsFound;
		TargetCharacter->GetComponents(USkeletalMeshComponent::StaticClass(), ComponentsFound);
		for (UActorComponent* TempComp : ComponentsFound)
		{
			if (UEXWSkeletalMeshComponent* MeshComp = Cast<UEXWSkeletalMeshComponent>(TempComp))
			{
				MeshComp->ApplyDefaultMaterialsLocal();			
			}
		}
		TargetCharacter->OnRep_EyeColor();
		TargetCharacter->OnRep_HairColor();
		TargetCharacter->OnRep_Skin();
	}
}

void AEXWCharacter::HighlightAllTargets(FName ParamName /*= "Color"*/, FLinearColor Color /*= FLinearColor::Red*/)
{
	for (AEXWCharacter* TempCharacter : TargetCharacters)
	{
		if (TempCharacter)
		{
			HighlightCharacter(TempCharacter, ParamName, Color);
		}
	}
}

void AEXWCharacter::UnhighlightAllTargets(FName ParamName /*= "Color"*/)
{
	for (AEXWCharacter* TempCharacter : TargetCharacters)
	{
		if (TempCharacter)
		{
			UnhighlightCharacter(TempCharacter, ParamName);
		}
	}
}

void AEXWCharacter::OnDeathEvent_Native()
{
	if (bDisableInputOnDeath)
	{
		Multicast_DisableInput();
	}
	if (DeathMontage)
	{
		if (!IsLocallyControlled())
		{
			Client_PlayMontage(DeathMontage, 1.f);
		}
		Multicast_PlayMontage(DeathMontage, 1.f);
	}
	if (bAutoSetDeadState)
	{
		AddState(EEXWState::S_Dead);
	}
	if (bStopRegenOnDeath)
	{
		Multicast_StopAllRegens();
	}
	if (LastCharacterAffectedBy)
	{
		if (!LastCharacterAffectedBy->IsDead())
		{
			UE_LOG(EXWCharLog, Log, TEXT("<%s> was killed by <%s>"), *this->GetName(), *LastCharacterAffectedBy->GetName());
			Client_OnCharacterDeath(LastCharacterAffectedBy);
			LastCharacterAffectedBy->Client_OnCharacterKill(this);
			if (ExperienceOnKill.bGiveExperienceOnKill && LastCharacterAffectedBy->bCanGainExperience)
			{
				LastCharacterAffectedBy->GainExperience(UEXWDataLibrary::CalculateExperienceOnKill(LastCharacterAffectedBy, this));
			}
			LastCharacterAffectedBy->LastCharacterAffected = nullptr; // Should be replicated
			LastCharacterAffectedBy = nullptr;
		}
	}
	DropOnDeathItems();
	RemoveAllActiveStatusEffects();
	Multicast_DeathEvent();
	OnDeathEvent();
}

void AEXWCharacter::Multicast_DeathEvent_Implementation()
{
	OnDeathEventMulticast_Native();
}

void AEXWCharacter::OnDeathEventMulticast_Native()
{
	if (IsLocallyControlled())
	{
		OnDeathEventClient_Native();
	}
	OnDeathEventMulticast();
}

void AEXWCharacter::OnDeathEventClient_Native()
{
	OnDeathEventClient();
}

void AEXWCharacter::Server_SpawnEmitterAtLocation_Implementation(UParticleSystem* EmitterTemplate, FVector SpawnLocation, FRotator SpawnRotation)
{
	Multicast_SpawnEmitterAtLocation(EmitterTemplate, SpawnLocation, SpawnRotation);
}

void AEXWCharacter::Multicast_SpawnEmitterAtLocation_Implementation(UParticleSystem* EmitterTemplate, FVector SpawnLocation, FRotator SpawnRotation)
{
	UGameplayStatics::SpawnEmitterAtLocation(this, EmitterTemplate, SpawnLocation, SpawnRotation, true);
}

void AEXWCharacter::Server_SpawnEmitterAttached_Implementation(UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType)
{
	Multicast_SpawnEmitterAttached(EmitterTemplate, AttachToComponent, AttachPointName, Location, Rotation, LocationType);
}

void AEXWCharacter::Multicast_SpawnEmitterAttached_Implementation(UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType)
{
	UGameplayStatics::SpawnEmitterAttached(EmitterTemplate, AttachToComponent, AttachPointName, Location, Rotation, LocationType, true);
}

void AEXWCharacter::Multicast_SpawnNiagraAttached_Implementation(UNiagaraSystem* NiagraTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType)
{
	UNiagaraFunctionLibrary::SpawnSystemAttached(NiagraTemplate, AttachToComponent, AttachPointName, Location, Rotation, LocationType, true);
}

void AEXWCharacter::Server_SetInventory_Implementation(const FEXWInventory NewInventory)
{
	Inventory = NewInventory;
	Client_CallOnInventoryUpdate(Inventory);
}

void AEXWCharacter::Server_SetInventoryShop_Implementation(const FEXWInventory NewInventoryShop)
{
	InventoryShop = NewInventoryShop;
	Client_CallOnInventoryShopUpdate(NewInventoryShop);
}

void AEXWCharacter::Server_AddItemsToInventory_Implementation(const FName ItemID, const int32 Count /*= 1*/)
{
	if (UEXWInventoryLibrary::AddItems(ItemID, Count, Inventory))
	{
		Client_CallOnInventoryUpdate(Inventory);
		Client_CallOnAddItemsToInventory(ItemID, Count);
	}
}

bool AEXWCharacter::TryAddingItemsToInventory(const FName ItemID, const int32 Count, int32& Rest)
{
	if (UEXWInventoryLibrary::CanAddItems(ItemID, Count, Inventory) != -1)
	{
		Server_AddItemsToInventory(ItemID, Count);
		Rest = 0;
		return true;
	}
	else
	{
		ForceNetUpdate(); // Force update to get the very current data and make sure everything is client/server synced
		int32 ItemCount = UEXWInventoryLibrary::GetItemCount(ItemID, Inventory);
		FEXWItemData ItemData;
		if (UEXWInventoryLibrary::GetItemData(ItemID, ItemData) && ItemCount > 0)
		{
			int32 CanBeAdded = ItemData.MaxStackSize - Count;
			if (CanBeAdded > 0)
			{
				Server_AddItemsToInventory(ItemID, CanBeAdded);
				Rest = Count - CanBeAdded;
				return true;
			}
		}
		else
		{
			Rest = Count;
		}
	}
	//DisplayScreenMessage(EEXWScreenMessageType::SM_InventorySpaceError);
	Client_CallOnRequestNotification(FText::FromString("Inventory full"));
	return false;
}

void AEXWCharacter::Server_AddItemsToInventoryShop_Implementation(const FName ItemID, const int32 Count /*= 1*/)
{
	if (UEXWInventoryLibrary::AddItems(ItemID, Count, InventoryShop))
	{
		Client_CallOnInventoryUpdate(Inventory);
		Client_CallOnInventoryShopUpdate(InventoryShop);
	}
}

void AEXWCharacter::Server_RemoveItemsFromInventory_Implementation(const FName ItemID, const int32 Count /*= 1*/)
{
	if (UEXWInventoryLibrary::RemoveItems(ItemID, Count, Inventory))
	{
		Client_CallOnInventoryUpdate(Inventory);
	}
}

void AEXWCharacter::Server_RemoveItemCountFromInventoryByIndex_Implementation(const int32 ItemCountToRemove, const int32 SlotIndex)
{
	if (UEXWInventoryLibrary::RemoveItemCountFromSlotByIndex(ItemCountToRemove, SlotIndex, Inventory))
	{
		Client_CallOnInventoryUpdate(Inventory);
	}
}

void AEXWCharacter::Server_RemoveItemSlotFromInventory_Implementation(const int32 SlotIndex)
{
	if (UEXWInventoryLibrary::RemoveItemsFromSlot(SlotIndex, Inventory))
	{
		Client_CallOnInventoryUpdate(Inventory);
	}
}

void AEXWCharacter::Server_RemoveItemsFromInventoryShop_Implementation(const FName ItemID, const int32 Count /*= 1*/)
{
	if (UEXWInventoryLibrary::RemoveItems(ItemID, Count, InventoryShop))
	{
		Client_CallOnInventoryUpdate(Inventory);
		Client_CallOnInventoryShopUpdate(InventoryShop);
	}
}

void AEXWCharacter::Server_MoveInventorySlots_Implementation(const int32 SourceIndex, const int32 TargetIndex)
{
	if (UEXWInventoryLibrary::MoveInventorySlot(SourceIndex, TargetIndex, Inventory))
	{
		Client_CallOnInventoryUpdate(Inventory);
	}
}

void AEXWCharacter::Server_SwapInventoryAndShopItems_Implementation(const int32 InventoryIndex, const int32 InventoryShopIndex)
{
	if (UEXWInventoryLibrary::SwapDifferentInventorySlots(InventoryIndex, InventoryShopIndex, Inventory, InventoryShop))
	{
		Client_CallOnInventoryUpdate(Inventory);
		Client_CallOnInventoryShopUpdate(InventoryShop);
		UpdateGearItemLevel();
	}
}

void AEXWCharacter::Server_ReturnItemsToInventoryFromShop_Implementation()
{
	if (UEXWInventoryLibrary::MoveInventorySlotsToInventory(InventoryShop, Inventory))
	{
		UEXWInventoryLibrary::MoveCoins(InventoryShop, Inventory);
		Client_CallOnInventoryUpdate(Inventory);
		Client_CallOnInventoryShopUpdate(InventoryShop);
		UpdateGearItemLevel();
	}
}

void AEXWCharacter::Server_MoveInventoryShopSlots_Implementation(const int32 SourceIndex, const int32 TargetIndex)
{
	if (UEXWInventoryLibrary::MoveInventorySlot(SourceIndex, TargetIndex, InventoryShop))
	{
		Client_CallOnInventoryShopUpdate(InventoryShop);
	}
}

void AEXWCharacter::Server_BuyItemsFromShop_Implementation(const FName ItemID, const int32 Count, AEXWCharacter* ShopOwner)
{
	EEXWBuyResult BuyResult = UEXWInventoryLibrary::BuyItems(ItemID, Count, Inventory, ShopOwner->InventoryShop);
	switch (BuyResult)
	{
	case EEXWBuyResult::BR_UnvalidItem:
		Client_CallOnRequestNotification(FText::FromString("Invalid Item"));
		break;
	case EEXWBuyResult::BR_SellerHasNoItem:
		Client_CallOnRequestNotification(FText::FromString("Shop doesn't have Item"));
		break;
	case EEXWBuyResult::BR_NotEnoughCoins:
		Client_CallOnRequestNotification(FText::FromString("Not enough Silver/Gold coins"));
		break;
	case EEXWBuyResult::BR_NotEnoughSpace:
		Client_CallOnRequestNotification(FText::FromString("Not enough space in Inventory"));
		break;
	case EEXWBuyResult::BR_Success:
		Client_CallOnInventoryUpdate(Inventory);
		ShopOwner->Client_CallOnInventoryShopUpdate(ShopOwner->InventoryShop);
		Client_CallOnRequestNotification(FText::FromString("Purchase Success!"));
		break;
	default:
		break;
	}
	
}

void AEXWCharacter::Server_BuyItemSlotFromShop_Implementation(const FEXWInventorySlot ItemSlot, const int32 Count, AEXWCharacter* ShopOwner)
{
	EEXWBuyResult BuyResult = UEXWInventoryLibrary::BuyItemFromSlot(ItemSlot, Count, Inventory, ShopOwner->InventoryShop);
	switch (BuyResult)
	{
	case EEXWBuyResult::BR_UnvalidItem:
		Client_CallOnRequestNotification(FText::FromString("Invalid Item"));
		break;
	case EEXWBuyResult::BR_SellerHasNoItem:
		Client_CallOnRequestNotification(FText::FromString("Shop doesn't have Item"));
		break;
	case EEXWBuyResult::BR_NotEnoughCoins:
		Client_CallOnRequestNotification(FText::FromString("Not enough Silver/Gold coins"));
		break;
	case EEXWBuyResult::BR_NotEnoughSpace:
		Client_CallOnRequestNotification(FText::FromString("Not enough space in Inventory"));
		break;
	case EEXWBuyResult::BR_Success:
		Client_CallOnInventoryUpdate(Inventory);
		ShopOwner->Client_CallOnInventoryShopUpdate(ShopOwner->InventoryShop);
		Client_CallOnRequestNotification(FText::FromString("Purchase Success!"));
		break;
	default:
		break;
	}
}

void AEXWCharacter::Server_DropItems_Implementation(const int32 InventorySlotIndex)
{
	if (Inventory.ItemSlots.IsValidIndex(InventorySlotIndex))
	{
		FName ItemID = Inventory.GetItemID(InventorySlotIndex);
		int32 Count = Inventory.GetItemCount(InventorySlotIndex);
		if (UEXWInventoryLibrary::RemoveItemsFromSlot(InventorySlotIndex, Inventory))
		{
			Client_CallOnInventoryUpdate(Inventory);
			if (UWorld* World = GetWorld()) {
				FTransform SpawnTransform = UEXWInventoryLibrary::GetItemSpawnTransform(this);
				AEXWItem* Item = World->SpawnActorDeferred<AEXWItem>(AEXWItem::StaticClass(), SpawnTransform, this, this);
				if (Item)
				{
					Item->SetItemData(ItemID, Count);
					UGameplayStatics::FinishSpawningActor(Item, SpawnTransform);
				}
			}
		}
	}
}

void AEXWCharacter::Server_SetShopItemSlotPrice_Implementation(const FEXWInventorySlot ItemSlot, const int32 PriceGold, const int32 PriceSilver)
{
	UEXWInventoryLibrary::SetItemSlotPrice(ItemSlot, PriceSilver, PriceGold, InventoryShop);
}

void AEXWCharacter::Client_CallOnInventoryUpdate_Implementation(const FEXWInventory& NewInventory)
{
	// Override the current inventory for fast update (example : Ui)
	Inventory = NewInventory;
	// Call virtual event to send info
	OnInventoryUpdate_Native();
}

void AEXWCharacter::OnInventoryUpdate_Native()
{
	OnInventoryUpdate();
}

void AEXWCharacter::Client_CallOnInventoryShopUpdate_Implementation(const FEXWInventory& NewInventoryShop)
{
	// Override the current inventory for fast update (example : Ui)
	InventoryShop = NewInventoryShop;
	// Call virtual event to send info
	OnInventoryShopUpdate_Native();
}

void AEXWCharacter::OnInventoryShopUpdate_Native()
{
	OnInventoryShopUpdate();
}

void AEXWCharacter::SpawnItem(const FName ItemID, const int32 Count /*= 1*/, const bool bForceLootable)
{
	if (UWorld* World = GetWorld()) {
		FTransform SpawnTransform = UEXWInventoryLibrary::GetItemSpawnTransform(this);
		AEXWItem* Item = World->SpawnActorDeferred<AEXWItem>(AEXWItem::StaticClass(), SpawnTransform, this, this);
		if (Item)
		{
			Item->SetItemData(ItemID, Count, bForceLootable);
			UGameplayStatics::FinishSpawningActor(Item, SpawnTransform);
		}
	}
}

void AEXWCharacter::DropOnDeathItems()
{
	for (FEXWItemDropRate& ItemDropRate : ItemsDropRatesOnDeath)
	{
		float RandomValue = UKismetMathLibrary::RandomFloat();
		if (RandomValue < ItemDropRate.DropRate)
		{
			int32 ItemCount = UKismetMathLibrary::RandomIntegerInRange(ItemDropRate.Count - ItemDropRate.CountVariation, ItemDropRate.Count + ItemDropRate.CountVariation);
			if (ItemCount == 0)
			{
				ItemCount = 1;
			}
			SpawnItem(ItemDropRate.ItemID, ItemCount, true);
		}
	}
	if (SingleDropItemsDropRatesOnDeath.Num()>0)
	{
		int32 RandomValue = UKismetMathLibrary::RandomIntegerInRange(0,SingleDropItemsDropRatesOnDeath.Num()-1);
		int32 ItemCount = UKismetMathLibrary::RandomIntegerInRange(SingleDropItemsDropRatesOnDeath[RandomValue].Count - SingleDropItemsDropRatesOnDeath[RandomValue].CountVariation, SingleDropItemsDropRatesOnDeath[RandomValue].Count + SingleDropItemsDropRatesOnDeath[RandomValue].CountVariation);
		
		ItemCount = FMath::Max(1, ItemCount);
		SpawnItem(SingleDropItemsDropRatesOnDeath[RandomValue].ItemID, ItemCount, true);
	}
}

bool AEXWCharacter::Replicated_UseItem(const int32 InventorySlotIndex)
{
	if (UEXWInventoryLibrary::HasItems(Inventory.GetItemID(InventorySlotIndex), 1, Inventory))
	{
		FEXWItemData ItemData;
		if (UEXWInventoryLibrary::GetItemData(Inventory.GetItemID(InventorySlotIndex), ItemData))
		{
			bool bRemoveItem = false;

			if (ItemData.ItemType == EEXWItemType::IT_Consumable)
			{
				EEXWItemUseResult UseResult = CanUseItem(ItemData);
				if (UseResult == EEXWItemUseResult::IUR_Success)
				{
					for (FName& StatusEffectRowName : ItemData.StatusEffectsOnUse)
					{
						Server_ConstructStatusEffect(StatusEffectRowName, this, this);
					}
					// Add to the cooldown stack
					if (ItemData.Cooldown > 0.f) {
						FEXWCooldown Cooldown = FEXWCooldown(ItemData.ID, ItemData.Cooldown);
						StartCooldown(Cooldown);
					}
					bRemoveItem = true;
				}
				else {
					UE_LOG(EXWCharLog, Log, TEXT("<%s> Cannot use item with ID [%s]."), *Name.ToString(), *ItemData.ID.ToString());
					return false;
				}
			}
			if (ItemData.ItemType == EEXWItemType::IT_Placeable)
			{
					FVector SpawnLocation = GetClosestGroundToCharacter(100.f, false);
					Server_SpawnPlaceable(ItemData.PlaceableClass, SpawnLocation);
					bRemoveItem = true;	
			}
			if (ItemData.ItemType == EEXWItemType::IT_Equip)
			{
				EquipItem(InventorySlotIndex);
			}
			if (ItemData.ItemType == EEXWItemType::IT_Cosmetic)
			{
				EquipItem(InventorySlotIndex);
			}
			if (ItemData.ItemType == EEXWItemType::IT_Ability)
			{
				EEXWItemUseResult UseResult = CanUseItem(ItemData);
				if (UseResult == EEXWItemUseResult::IUR_Success && CanLearnAbility(ItemData))
				{
					Server_LearnAbilityFromItem(ItemData);

					// Add to the cooldown stack
					if (ItemData.Cooldown > 0.f) {
						FEXWCooldown Cooldown = FEXWCooldown(ItemData.ID, ItemData.Cooldown);
						StartCooldown(Cooldown);
					}
					bRemoveItem = true;
				}
				else {
					UE_LOG(EXWCharLog, Log, TEXT("<%s> Cannot use item with ID [%s]."), *Name.ToString(), *ItemData.ID.ToString());
					return false;
				}
			}

			if (bRemoveItem)
			{
				Server_RemoveItemCountFromInventoryByIndex(1, InventorySlotIndex);
			}
			return true;
		}
	}
	else
	{
		UE_LOG(EXWCharLog, Warning, TEXT("Cannot use a non owned item."));
	}
	return false;
}

void AEXWCharacter::Server_SpawnPlaceable_Implementation(TSubclassOf<class AEXWPlaceable> PlaceableClass, FVector Location)
{
	if (UWorld* World = GetWorld())
	{
		FTransform SpawnTransform = FTransform(GetActorRotation(), Location, FVector(1.f));
		AEXWPlaceable* PlaceableActor = World->SpawnActorDeferred<AEXWPlaceable>(PlaceableClass, SpawnTransform, this, this);
		if (PlaceableActor)
		{
			PlaceableActor->SetOwner(this);
			UGameplayStatics::FinishSpawningActor(PlaceableActor, SpawnTransform);
		}
	}
}

bool AEXWCharacter::HasItem(const FName ItemID)
{
	return UEXWInventoryLibrary::HasItems(ItemID, 1, Inventory);
}

bool AEXWCharacter::HasItemByType(const EEXWEquipmentType EquipmentType)
{
	for (FEXWInventorySlot EquipmentSlot : Inventory.ItemSlots)
	{
		FEXWItemData ItemData;
		if (UEXWInventoryLibrary::GetItemData(EquipmentSlot.ItemID, ItemData))
		{
			if (ItemData.EquipmentType == EquipmentType)
			{
				return true;
			}
		}
	}
	return false;
}

void AEXWCharacter::Client_CallOnAddItemsToInventory_Implementation(const FName ItemID, const int32 ItemCount)
{
	OnAddItemsToInventory_Native(ItemID, ItemCount);
}

void AEXWCharacter::OnAddItemsToInventory_Native(const FName ItemID, const int32 ItemCount)
{
	FEXWItemData ItemData;
	FString LeftSide;
	FString Rarirty;

	if (UEXWInventoryLibrary::GetItemData(ItemID, ItemData))
	{
		FString StringEnum = StaticEnum<EEXWItemRarety>()->GetValueAsString(ItemData.ItemRarity);
		StringEnum.Split("IR_", &LeftSide, &Rarirty, ESearchCase::IgnoreCase, ESearchDir::FromStart);

		OnRequestNotification(FText::FromString("(" + FString::FromInt(ItemCount) + ")<" + Rarirty+ ">[" + ItemData.ItemName.ToString() + "]</> were added to the inventory"));
	}
}

void AEXWCharacter::Client_CallOnRemoveItemsFromInventory_Implementation(const FName ItemID, const int32 ItemCount)
{
	OnRemoveItemsFromInventory_Native(ItemID, ItemCount);
}

void AEXWCharacter::OnRemoveItemsFromInventory_Native(const FName ItemID, const int32 ItemCount)
{
	FEXWItemData ItemData;
	if (UEXWInventoryLibrary::GetItemData(ItemID, ItemData))
	{
		OnRequestNotification(FText::FromString(FString::FromInt(ItemCount) + "x[" + ItemData.ItemName.ToString() + "] were removed from the inventory"));
	}
}

EEXWItemUseResult AEXWCharacter::CanUseItem(const FEXWItemData& InItem)
{
	// Check Cooldown
	bool bIsCooldownValid = true;
	FEXWCooldown Cooldown;
	float TimeElapsed;
	float TimeRemaining;
	if (GetCooldownTimer(InItem.ID, TimeElapsed, TimeRemaining) && InItem.Cooldown > 0.f) {
		OnNotifyCooldown_Native(InItem.ID, TimeElapsed, TimeRemaining);
		bIsCooldownValid = false;
	}

	if (bIsCooldownValid)
	{
		return EEXWItemUseResult::IUR_Success;
	}
	else if (!bIsCooldownValid)
	{
		Client_CallOnRequestNotification(FText::FromString("This Item is on cooldown"));
		return EEXWItemUseResult::IUR_OnCooldown;
	}

	return EEXWItemUseResult::IUR_UnknownError;
}

void AEXWCharacter::Server_GainSilver_Implementation(int32 Quantity)
{
	// TODO Security check here maybe?
	if (UEXWInventoryLibrary::AddSilver(Quantity, Inventory))
	{
		Client_CallOnRequestNotification(FText::FromString("Obtained " + FString::FromInt(Quantity) + " Silver!"));
		Client_CallOnInventoryUpdate(Inventory);
	}
}

void AEXWCharacter::Server_GainGold_Implementation(int32 Quantity)
{
	// TODO Security check here maybe?
	if (UEXWInventoryLibrary::AddGold(Quantity, Inventory))
	{
		Client_CallOnRequestNotification(FText::FromString("Obtained " + FString::FromInt(Quantity) + " Gold!"));
		Client_CallOnInventoryUpdate(Inventory);
	}
}

bool AEXWCharacter::CanOpenShop()
{
	if (!bIsVending && !bIsInCombat && !bIsDueling && !bIsTrading)  // TODO: && InSafeRegion
	{
		return true;
	}
	return false;
}

void AEXWCharacter::Server_StartShop_Implementation()
{
	if (CanOpenShop())
	{
		Replicated_PlayMontage(UEXWDataLibrary::GetVendingAnimMontageByRaceAndClass(Race, Class), 1.f);
		Server_SetAvailableInteractions({EEXWInteractionType::IT_Shop});
		Multicast_DisableInput();
		bIsVending = true;
		Client_StartShop();

	}
	else {
		Client_CallOnRequestNotification(FText::FromString("Can't Open Shop!")); // TODO: Add comprehensive messages to the player.
	}
}

void AEXWCharacter::Client_StartShop_Implementation()
{
	OnShopStart();
	OnShopStarted.Broadcast();
}

void AEXWCharacter::Server_StopShop_Implementation()
{
	/*if (bIsVending)
	{*/
		Server_StopMontage(UEXWDataLibrary::GetVendingAnimMontageByRaceAndClass(Race, Class));
		Server_SetAvailableInteractions(DefaultInteractionTypes);
		Server_ReturnItemsToInventoryFromShop();
		/* For Some reason this crashes.
		if (AEXWPlayerController* PC = Cast<AEXWPlayerController>(GetController()))
		{
			PC->ToggleShopMenu();
		}*/
		Multicast_EnableInput();
		bIsVending = false;
		Client_StopShop();
	/* }
	else {
		Client_CallOnRequestNotification(FText::FromString("Not Vending!")); // TODO: Add comprehensive messages to the player.
	}*/
}

void AEXWCharacter::Client_StopShop_Implementation()
{
	OnShopStop();
	OnShopStopped.Broadcast();
}

void AEXWCharacter::Server_SwapInventoryAndEquipmentItems_Implementation(const int32 InventorySlotIndex, const int32 EquipmentSlotIndex)
{
	if (UEXWInventoryLibrary::SwapDifferentInventorySlots(InventorySlotIndex, EquipmentSlotIndex, Inventory, InventoryEquipment))
	{
		InitializeCharacterData();

		Client_CallOnInventoryUpdate(Inventory);
		Client_CallOnInventoryEquipmentUpdate(InventoryEquipment);
	}
}

void AEXWCharacter::Server_SwapInventoryAndCosmeticItems_Implementation(const int32 InventorySlotIndex, const int32 CosmeticSlotIndex)
{
	if (UEXWInventoryLibrary::SwapDifferentInventorySlots(InventorySlotIndex, CosmeticSlotIndex, Inventory, InventoryCosmeticEquipment))
	{
		Client_CallOnInventoryUpdate(Inventory);
		Client_CallOnInventoryCosmeticEquipmentUpdate(InventoryCosmeticEquipment);
	}
}

void AEXWCharacter::Client_CallOnInventoryEquipmentUpdate_Implementation(const FEXWInventory& NewInventoryEquipment)
{
	InventoryEquipment = NewInventoryEquipment;
	InitializeCharacterData();
	OnInventoryEquipmentUpdate_Native();
}

void AEXWCharacter::OnInventoryEquipmentUpdate_Native()
{
	OnInventoryEquipmentUpdate();
}

void AEXWCharacter::Client_CallOnInventoryCosmeticEquipmentUpdate_Implementation(const FEXWInventory& NewInventoryCosmeticEquipment)
{
	InventoryCosmeticEquipment = NewInventoryCosmeticEquipment;
	InitializeCharacterData();
	OnInventoryCosmeticEquipmentUpdate_Native();
}

void AEXWCharacter::OnInventoryCosmeticEquipmentUpdate_Native()
{
	OnInventoryCosmeticEquipmentUpdate();
}

void AEXWCharacter::CreateDefaultInventoryEquipment()
{
	InventoryEquipment.ItemSlots =
	{
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Head}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Torso}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Arms}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Legs}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Feet}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Ring}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Ring}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Belt}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Necklace}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_Earring}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_RightHand}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Equipment_LeftHand})
	};
}

void AEXWCharacter::CreateDefaultInventoryCosmeticEquipment()
{
	InventoryCosmeticEquipment.ItemSlots =
	{
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Head}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Torso}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Arms}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Legs}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Feet}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Ring}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Ring}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Belt}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Necklace}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Earring}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_RightHand}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_LeftHand}),
		FEXWInventorySlot("None", 0, {EEXWSlotType::ST_Cosmetic_Cape})
	};
}

bool AEXWCharacter::IsEquippedByID(const FName ItemID)
{
	return UEXWInventoryLibrary::HasItems(ItemID, 1, InventoryEquipment) || UEXWInventoryLibrary::HasItems(ItemID, 1, InventoryCosmeticEquipment);
}

bool AEXWCharacter::IsEquippedByType(const EEXWEquipmentType EquipmentType)
{
	for (FEXWInventorySlot EquipmentSlot : InventoryEquipment.ItemSlots)
	{
		FEXWItemData ItemData;
		if (UEXWInventoryLibrary::GetItemData(EquipmentSlot.ItemID, ItemData))
		{
			if (ItemData.EquipmentType == EquipmentType)
			{
				return true;
			}
		}
	}
	return false;
}

bool AEXWCharacter::Gather_Toggle(bool isStart, FName ItemID)
{
	FEXWItemData ItemData;
	if (UEXWInventoryLibrary::GetItemData(ItemID, ItemData) && isStart == true)
	{
		OnEquipItem_Native(ItemID);
		Server_SetSkeletalMesh(LeftHandWeaponMesh, nullptr);
		return true;
	}
	if (isStart == false)
	{
		USkeletalMesh* Mesh = nullptr;
		int32 slotid;
		if (UEXWInventoryLibrary::GetSlotIndexByType(slotid, InventoryEquipment, EEXWSlotType::ST_Equipment_RightHand))	//equipment on slot?
		{
			if (InventoryEquipment.ItemSlots[slotid].ItemID.IsValid())
			{
				FName itemname = InventoryEquipment.ItemSlots[slotid].ItemID;
				FEXWItemData ItemData;
				if (UEXWInventoryLibrary::GetItemData(itemname, ItemData))
				{
					//RightHandWeaponMesh->SetSkeletalMesh(*ItemData.SkeletalMeshes.Find(Gender));
					OnEquipItem_Native(itemname);
					//return true;
				}
				else
				{
					Server_SetSkeletalMesh(RightHandWeaponMesh, nullptr);
					//return true;
				}
			}

		}
		if (UEXWInventoryLibrary::GetSlotIndexByType(slotid, InventoryEquipment, EEXWSlotType::ST_Equipment_LeftHand))	//equipment on slot?
		{
			if (InventoryEquipment.ItemSlots[slotid].ItemID.IsValid())
			{
				FName itemname = InventoryEquipment.ItemSlots[slotid].ItemID;
				FEXWItemData ItemData;
				if (UEXWInventoryLibrary::GetItemData(itemname, ItemData))
				{
					//RightHandWeaponMesh->SetSkeletalMesh(*ItemData.SkeletalMeshes.Find(Gender));
					OnEquipItem_Native(itemname);

				}
				else
				{
					Server_SetSkeletalMesh(LeftHandWeaponMesh, nullptr);
					return true;
				}
			}

		}
		return true;
	}
	return false;
}

bool AEXWCharacter::EquipItem(const int32 InventoryItemIndex)
{
	FEXWItemData ItemData;
	if (UEXWInventoryLibrary::GetItemData(Inventory.GetItemID(InventoryItemIndex), ItemData))
	{
		if (!ItemData.RequiredClasses.Contains(Class))
		{
			DisplayScreenMessage(EEXWScreenMessageType::SM_EquipmentClassError);
			return false;
		}
		else if (ItemData.RequiredLevel > ProgressionLevel)
		{
			DisplayScreenMessage(EEXWScreenMessageType::SM_EquipmentLevelError);
			return false;
		}
		else
		{
			int32 ValidSlotIndex;
			if (UEXWInventoryLibrary::GetSlotIndexByType(ValidSlotIndex, InventoryEquipment, ItemData.SlotType))
			{
				Server_SwapInventoryAndEquipmentItems(InventoryItemIndex, ValidSlotIndex);

				if (InventoryCosmeticEquipment.ItemSlots[ValidSlotIndex].ItemID == FName("None"))
				{
					OnEquipItem_Native(Inventory.GetItemID(InventoryItemIndex));
				}

				return true;
			}
			if (UEXWInventoryLibrary::GetSlotIndexByType(ValidSlotIndex, InventoryCosmeticEquipment, ItemData.SlotType))
			{
				Server_SwapInventoryAndCosmeticItems(InventoryItemIndex, ValidSlotIndex);
				OnEquipItem_Native(Inventory.GetItemID(InventoryItemIndex));
				return true;
			}
		}
	}
	return false;
}

bool AEXWCharacter::UnequipItem(const int32 InventoryEquipmentItemIndex, bool CosmeticItem)
{
	int32 EmptySlotIndex = UEXWInventoryLibrary::HasEmptySlot(Inventory);
	if (EmptySlotIndex > -1)
	{
		if (!CosmeticItem)
		{
			Server_SwapInventoryAndEquipmentItems(EmptySlotIndex, InventoryEquipmentItemIndex);
			if (InventoryCosmeticEquipment.ItemSlots[InventoryEquipmentItemIndex].ItemID == FName("None"))
			{
				OnUnequipItem_Native(InventoryEquipment.GetItemID(InventoryEquipmentItemIndex));
			}
			return true;
		}
		else
		{
			Server_SwapInventoryAndCosmeticItems(EmptySlotIndex, InventoryEquipmentItemIndex);
			if (InventoryEquipment.ItemSlots[InventoryEquipmentItemIndex].ItemID == FName("None"))
			{
				OnUnequipItem_Native(InventoryCosmeticEquipment.GetItemID(InventoryEquipmentItemIndex));
			}
			else
			{
				OnEquipItem_Native(InventoryEquipment.GetItemID(InventoryEquipmentItemIndex));
			}
			return true;
		}
		//OnUnequipItem_Native(InventoryEquipment.GetItemID(InventoryEquipmentItemIndex));
		return true;
	}
	return false; // ADD LOGS
}

void AEXWCharacter::OnEquipItem_Native(const FName& ItemID)
{
	FEXWItemData ItemData;
	if (UEXWInventoryLibrary::GetItemData(ItemID, ItemData))
	{
		USkeletalMesh* SkeletalMeshToEquip = nullptr;
		if (ItemData.MultiRace)
		{
			for (auto obj : ItemData.RacialSkeletalMeshes)
			{
				if (obj.Race == Race)
				{
					SkeletalMeshToEquip = *obj.SkeletalMeshes.Find(Gender);
					break;
				}
			}
		}
		else
		{
			SkeletalMeshToEquip = *ItemData.SkeletalMeshes.Find(Gender);
		}

		if (SkeletalMeshToEquip)
		{
			switch (ItemData.SlotType)
			{
			case EEXWSlotType::ST_Equipment_Head:
				Server_SetSkeletalMesh(HeadMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Equipment_Torso:
				Server_SetSkeletalMesh(TorsoMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Equipment_Arms:
				Server_SetSkeletalMesh(ArmsMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Equipment_Legs:
				Server_SetSkeletalMesh(LegsMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Equipment_Feet:
				Server_SetSkeletalMesh(FeetMesh, SkeletalMeshToEquip);
				break;
				//cosmetics
			case EEXWSlotType::ST_Cosmetic_Head:
				Server_SetSkeletalMesh(HeadMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Cosmetic_Torso:
				Server_SetSkeletalMesh(TorsoMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Cosmetic_Arms:
				Server_SetSkeletalMesh(ArmsMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Cosmetic_Legs:
				Server_SetSkeletalMesh(LegsMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Cosmetic_Feet:
				Server_SetSkeletalMesh(FeetMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Equipment_RightHand:
				bWeaponEquipped = true;
				Server_SetSkeletalMesh(RightHandWeaponMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Equipment_LeftHand:
				bWeaponEquipped = true;
				Server_SetSkeletalMesh(LeftHandWeaponMesh, SkeletalMeshToEquip);
				break;
			case EEXWSlotType::ST_Ability:
				bWeaponEquipped = true;
				Server_SetSkeletalMesh(RightHandWeaponMesh, SkeletalMeshToEquip);
				break;
			}
		}
		else
		{
			OnUnequipItem_Native(ItemID);
		}
	}
	OnEquipItem(ItemID);
	OnItemEquipped.Broadcast(ItemID);
}

void AEXWCharacter::OnUnequipItem_Native(const FName& ItemID)
{
	FEXWItemData ItemData;
	USkeletalMesh* Mesh;
	if (UEXWInventoryLibrary::GetItemData(ItemID, ItemData))
	{
		switch (ItemData.SlotType)
		{
		case EEXWSlotType::ST_Equipment_Head:
			UEXWDataLibrary::GetHeadMeshFromDT(HeadName, Mesh);
			Server_SetSkeletalMesh(HeadMesh, nullptr);
			break;
		case EEXWSlotType::ST_Equipment_Torso:
			UEXWDataLibrary::GetTorsoMeshFromDT(TorsoName, Mesh);
			Server_SetSkeletalMesh(TorsoMesh, Mesh != nullptr ? Mesh : nullptr);
			break;
		case EEXWSlotType::ST_Equipment_Arms:
			UEXWDataLibrary::GetArmsMeshFromDT(ArmsName, Mesh);
			Server_SetSkeletalMesh(ArmsMesh, Mesh != nullptr ? Mesh : nullptr);
			break;
		case EEXWSlotType::ST_Equipment_Legs:
			UEXWDataLibrary::GetLegsMeshFromDT(LegsName, Mesh);
			Server_SetSkeletalMesh(LegsMesh, Mesh != nullptr ? Mesh : nullptr);
			break;
		case EEXWSlotType::ST_Equipment_Feet:
			UEXWDataLibrary::GetFeetMeshFromDT(FeetName, Mesh);
			Server_SetSkeletalMesh(FeetMesh, Mesh != nullptr ? Mesh : nullptr);
			break;
		case EEXWSlotType::ST_Cosmetic_Head:
			UEXWDataLibrary::GetHeadMeshFromDT(HeadName, Mesh);
			Server_SetSkeletalMesh(HeadMesh, Mesh != nullptr ? Mesh : nullptr);
			break;
		case EEXWSlotType::ST_Cosmetic_Torso:
			UEXWDataLibrary::GetTorsoMeshFromDT(TorsoName, Mesh);
			Server_SetSkeletalMesh(TorsoMesh, Mesh != nullptr ? Mesh : nullptr);
			break;
		case EEXWSlotType::ST_Cosmetic_Arms:
			UEXWDataLibrary::GetArmsMeshFromDT(ArmsName, Mesh);
			Server_SetSkeletalMesh(ArmsMesh, Mesh != nullptr ? Mesh : nullptr);
			break;
		case EEXWSlotType::ST_Cosmetic_Legs:
			UEXWDataLibrary::GetLegsMeshFromDT(LegsName, Mesh);
			Server_SetSkeletalMesh(LegsMesh, Mesh != nullptr ? Mesh : nullptr);
			break;
		case EEXWSlotType::ST_Cosmetic_Feet:
			UEXWDataLibrary::GetFeetMeshFromDT(FeetName, Mesh);
			Server_SetSkeletalMesh(FeetMesh, Mesh != nullptr ? Mesh : nullptr);
			break;
		case EEXWSlotType::ST_Equipment_RightHand:
			bWeaponEquipped = false;
			Server_SetSkeletalMesh(RightHandWeaponMesh, nullptr);
			break;
		case EEXWSlotType::ST_Equipment_LeftHand:
			bWeaponEquipped = false;
			Server_SetSkeletalMesh(LeftHandWeaponMesh, nullptr);
			break;
		case EEXWSlotType::ST_Ability:
			bWeaponEquipped = false;
			Server_SetSkeletalMesh(RightHandWeaponMesh, nullptr);
			break;
		}
	}
	OnUnequipItem(ItemID);
	OnItemUnEquipped.Broadcast(ItemID);
}

void AEXWCharacter::Server_HandleItemSetEquipment_Implementation(FName ItemSetID)
{
	
	FEXWItemSet ItemSet = UEXWDataLibrary::GetItemSetByID(ItemSetID);
	if (ItemSet.ID != "None")
	{
		for (FName ItemID : ItemSet.SetItems) {
			if (IsEquippedByID(ItemID))
			{
				bHasItemSetEquipped = true;
			}
			else {
				bHasItemSetEquipped = false;
				break;
			}
		}

		if (bHasItemSetEquipped)
		{
		
			for (const TPair<EEXWStatType, float>& Stat : ItemSet.StatEffectsOnFullAssembly) {
				Server_GainStat(Stat.Key, Stat.Value);
			}
			FEXWItemSetEventEffect* OnEquipParticles = ItemSet.EventEffects.Find(EEXWItemSetEvent::ISE_OnEquip);
			if (OnEquipParticles)
			{
				Multicast_PlayParticles(OnEquipParticles->Effect, OnEquipParticles->BoneName);
			}
			

			CurrentItemSet = ItemSet;
		}
	}
	
}

void AEXWCharacter::Server_HandleItemSetUnEquipment_Implementation(FName ItemSetID)
{
	FEXWItemSet ItemSet = UEXWDataLibrary::GetItemSetByID(ItemSetID);
	if (ItemSet.ID != "None")
	{
		for (const TPair<EEXWStatType, float>& Stat : ItemSet.StatEffectsOnFullAssembly) {
			Server_LoseStat(Stat.Key, Stat.Value);
		}
		
		FEXWItemSetEventEffect* UnEquipParticles = ItemSet.EventEffects.Find(EEXWItemSetEvent::ISE_OnUnEquip);
		if (UnEquipParticles)
		{
			Multicast_PlayParticles(UnEquipParticles->Effect, UnEquipParticles->BoneName);
		}
		
		CurrentItemSet = FEXWItemSet();
		bHasItemSetEquipped = false;
	}
	

}

void AEXWCharacter::Server_Interact_Implementation(AActor* TargetActor, EEXWInteractionType InteractionType)
{
	if (IEXWInteractable* InteractableActor = Cast<IEXWInteractable>(TargetActor))
	{
		InteractableActor->OnReceiveInteraction(this, InteractionType);
		Client_Interact(TargetActor, InteractionType);
	}
}

void AEXWCharacter::Client_Interact_Implementation(AActor* TargetActor, EEXWInteractionType InteractionType)
{
	OnInteract.Broadcast(TargetActor, InteractionType);
}

void AEXWCharacter::Multicast_CreateShopWidget_Implementation(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter)
{
	if (SourceCharacter->IsLocallyControlled())
	{
		if (AEXWPlayerController* PlayerController = Cast<AEXWPlayerController>(SourceCharacter->GetController()))
		{
			PlayerController->CreateShopWidget(SourceCharacter, TargetCharacter);
		}
	}
}

void AEXWCharacter::Multicast_CreateNPCShopWidget_Implementation(AEXWCharacter* SourceCharacter, AEXWCharacter* ShopOwner, FName ShopID)
{
	if (SourceCharacter->IsLocallyControlled())
	{
		if (AEXWPlayerController* PlayerController = SourceCharacter->GetController<AEXWPlayerController>())
		{
			PlayerController->DisplayNPCShopUI(ShopID, ShopOwner);
		}
	}
}

void AEXWCharacter::Multicast_CreateTradeWidget_Implementation(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter)
{
	AEXWPlayerController* PlayerController = nullptr;
	if (SourceCharacter->IsLocallyControlled())
	{
		PlayerController = Cast<AEXWPlayerController>(SourceCharacter->GetController());
	}
	else if (TargetCharacter->IsLocallyControlled())
	{
		PlayerController = Cast<AEXWPlayerController>(TargetCharacter->GetController());
	}
	if (PlayerController)
	{
		PlayerController->CreateTradeWidget(SourceCharacter, TargetCharacter);
	}
}

void AEXWCharacter::Multicast_CreateDialogueWidget_Implementation(AEXWCharacter* SourceCharacter, FName DialogueID)
{
	if (SourceCharacter->IsLocallyControlled())
	{
		if (AEXWPlayerController* PlayerController = SourceCharacter->GetController<AEXWPlayerController>())
		{
			PlayerController->DisplayDialogueUI(DialogueID);
		}
	}
}

void AEXWCharacter::Multicast_CreateCraftWidget_Implementation(AEXWCharacter* SourceCharacter, AEXWPlaceableCraftStation* CraftStation, EEXWCraftCategory Category)
{
	if (SourceCharacter->IsLocallyControlled())
	{
		if (AEXWPlayerController* PlayerController = SourceCharacter->GetController<AEXWPlayerController>())
		{
			PlayerController->CreateCraftMenu(CraftStation, Category);
		}
	}
}

void AEXWCharacter::OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType)
{
	if (InteractionType == EEXWInteractionType::IT_TradeRequest)
	{
		Multicast_CreateTradeWidget(SourceCharacter, this);
		// Trade UI
	}
	else if (InteractionType == EEXWInteractionType::IT_DuelRequest)
	{
		// Supposedly duel request UI
		Server_RequestDuel(SourceCharacter);
	}
	else if (InteractionType == EEXWInteractionType::IT_Shop)
	{
		Multicast_CreateShopWidget(SourceCharacter, this);
	}
	else if (InteractionType == EEXWInteractionType::IT_InviteToParty) {

		if (!(GetPlayerState<AEXWorldCombatPlayerState>()->CurrentParty.ID =="-1"))
		{
			SourceCharacter->Client_CallOnRequestNotification(FText::FromString(Name.ToString() + " is already in a party" ));	
		}
		else if (SourceCharacter->GetPlayerState<AEXWorldCombatPlayerState>()->CurrentParty.Members.Num()>=5)
		{
			SourceCharacter->Client_CallOnRequestNotification(FText::FromString("Party is currently full"));	
		}
		else
		{
			FEXWParty Party = SourceCharacter->GetPlayerState<AEXWorldCombatPlayerState>()->CurrentParty;
			//Check if Party exists
			if (Party.ID == "-1")
			{
				//Create Party
				FName PartyID = FName(*FString::SanitizeFloat(FMath::FRandRange(0.f, 20000.f)));
				FString PartyName = SourceCharacter->Name.ToString();
				PartyName.Append("'s Party");
				TArray<AEXWCharacter*> PartyMembers;
				PartyMembers.Add(this);
				SourceCharacter->RequestCreateParty(PartyID, FText::FromString(PartyName), PartyMembers);
			}
			else {
				SourceCharacter->RequestInviteCharacterToParty(Party, this);
			}
		}

	}
	OnReceiveInteraction_ImpEvent(SourceCharacter, InteractionType);
	OnReceiveInteractionDelegate.Broadcast(SourceCharacter, InteractionType);
}

void AEXWCharacter::OnReceiveClick(AEXWCharacter* SourceCharacter)
{
	OnReceiveClick_ImpEvent(SourceCharacter);
}

void AEXWCharacter::SetInteractionWidgetVisibility(const bool bNewVisibility /*= true*/)
{
	if (InteractionWidgetComponent)
	{
		InteractionWidgetComponent->SetVisibility(bNewVisibility, true);
	}
}

UWidgetComponent* AEXWCharacter::GetInteractionWidgetComponent()
{
	return MakeWeakObjectPtr<UWidgetComponent>(InteractionWidgetComponent).Get();
}

void AEXWCharacter::Server_SetAvailableInteractions_Implementation(const TArray<EEXWInteractionType>& NewAvailableInteractionTypes)
{
	Multicast_SetAvailableInteractions(NewAvailableInteractionTypes);
}

void AEXWCharacter::Multicast_SetAvailableInteractions_Implementation(const TArray<EEXWInteractionType>& NewAvailableInteractionTypes)
{
	AvailableInteractionTypes = NewAvailableInteractionTypes;
}

void AEXWCharacter::Server_AddAvailableInteractions_Implementation(const EEXWInteractionType InAvailableInteractionType)
{
	Multicast_AddAvailableInteractions(InAvailableInteractionType);
}

void AEXWCharacter::Multicast_AddAvailableInteractions_Implementation(const EEXWInteractionType InAvailableInteractionType)
{
	AvailableInteractionTypes.AddUnique(InAvailableInteractionType);
}

void AEXWCharacter::Server_RemoveAvailableInteractions_Implementation(const EEXWInteractionType InAvailableInteractionType)
{
	Multicast_RemoveAvailableInteractions(InAvailableInteractionType);
}

void AEXWCharacter::Multicast_RemoveAvailableInteractions_Implementation(const EEXWInteractionType InAvailableInteractionType)
{
	AvailableInteractionTypes.Remove(InAvailableInteractionType);
}

void AEXWCharacter::Server_RequestDuel_Implementation(AEXWCharacter* TargetToDuel)
{
	if (!TargetToDuel->bIsDueling && !bIsDueling)
	{
		Client_RequestDuel(TargetToDuel);

	}
	else
	{
		TargetToDuel->Client_CallOnRequestNotification(FText::FromString(Name.ToString() + " is already in a Duel"));
		UE_LOG(EXWCharLog, Log, TEXT("%s tried to duel %s but one of them is already dueling."), *Name.ToString(), *TargetToDuel->GetName());
	}
}

void AEXWCharacter::Server_RespondDuel_Implementation(AEXWCharacter* TargetToDuel, bool IsAccepted)
{
	if (IsAccepted)
	{
		bIsDueling = true;
		TargetToDuel->bIsDueling = true;

		//set dueling character references
		DuelingCharacter = TargetToDuel;
		TargetToDuel->DuelingCharacter = this;
		
		//server timer
		FTimerDelegate DuelTimerDel;
		DuelTimerDel.BindLambda([&] { Server_StartDuel(DuelingCharacter);});
		GetWorld()->GetTimerManager().SetTimer(DuelTimerHandle, DuelTimerDel, 3.0f, false, -1.0f);

		//client timers and countdown
		Client_StartDuelTimer(TargetToDuel);
		TargetToDuel->Client_StartDuelTimer(this);

		Client_CallOnRequestNotification(FText::FromString(" You Accepted to Duel " + TargetToDuel->Name.ToString()));
		TargetToDuel->Client_CallOnRequestNotification(FText::FromString(Name.ToString() + " Accepted the Duel"));
	}
	else
	{
		Client_CallOnRequestNotification(FText::FromString(" You Declined to Duel " + TargetToDuel->Name.ToString()));
		TargetToDuel->Client_CallOnRequestNotification(FText::FromString(Name.ToString() + " Declined the Duel"));
	}
}

void AEXWCharacter::Client_RequestDuel_Implementation(AEXWCharacter* TargetToDuel)
{
	if (AEXWPlayerController* PlayerController = Cast<AEXWPlayerController>(GetController()))
		PlayerController->CreateRequestDuelWidget(TargetToDuel);
}

void AEXWCharacter::Server_StartDuel_Implementation(AEXWCharacter* OtherCharacter)
{
	Client_StartDuel(OtherCharacter);
	OtherCharacter->Client_StartDuel(this);

	UE_LOG(EXWCharLog, Log, TEXT("Duel will start between %s and %s."), *Name.ToString(), *OtherCharacter->GetName());
}

void AEXWCharacter::Client_StartDuelTimer_Implementation(AEXWCharacter* OtherCharacter)
{
	DuelCountdown=3;
	FTimerDelegate DuelTimerDel;
	DuelTimerDel.BindLambda([&]
	{
		OnRequestNotification(FText::FromString("Duel will start in "+ FString::FromInt(DuelCountdown)));
		DuelCountdown--;
		
		if (GetWorld()->GetTimerManager().IsTimerActive(DuelTimerHandle) && DuelCountdown <= 0 )
		{
			GetWorld()->GetTimerManager().ClearTimer(DuelTimerHandle);
		}
	});
	GetWorld()->GetTimerManager().SetTimer(DuelTimerHandle, DuelTimerDel, 1.0f, true, -1.0f);
}

void AEXWCharacter::Client_StartDuel_Implementation(AEXWCharacter* OtherCharacter)
{
	OtherCharacter->Faction = DUEL_FACTION;
}

void AEXWCharacter::Server_EndDuel_Implementation(AEXWCharacter* OtherCharacter)
{
	if (!bIsDueling)
		return;
	Client_SetTargetFaction(OtherCharacter, OtherCharacter->Faction);
	OtherCharacter->Client_SetTargetFaction(this, Faction);

	bIsDueling = false;
	OtherCharacter->bIsDueling = false;
	DuelingCharacter = nullptr;
	OtherCharacter->DuelingCharacter = nullptr;

	OnEndDuel_Native(OtherCharacter, false); // Default loss will be fixed later
}

void AEXWCharacter::OnEndDuel_Native(AEXWCharacter* OtherCharacter, bool bHasWon)
{
	if (bHasWon)
	{
		Client_CallOnRequestNotification(FText::FromString(" You Won Duel Against " + OtherCharacter->Name.ToString()));
		OtherCharacter->Client_CallOnRequestNotification(FText::FromString("You Lost the Duel against " + Name.ToString()));
	}
	else
	{
		Client_CallOnRequestNotification(FText::FromString(" You Lost Duel with " + OtherCharacter->Name.ToString()));
		OtherCharacter->Client_CallOnRequestNotification(FText::FromString("You won the Duel against " + Name.ToString()));
	}
}

bool AEXWCharacter::Replicated_ExecuteCraft(const FName CraftID /*= "None"*/)
{
	if (UEXWInventoryLibrary::CanExecuteCrafting(CraftID, Inventory))
	{
		FEXWCraftingOption CraftingOption;
		if (UEXWInventoryLibrary::GetCraftingOptionData(CraftID, CraftingOption))
		{

			FEXWLifeSkill LifeSkill;
			//FEXWItemData ItemData;
			//if (UEXWInventoryLibrary::UEXWInventoryLibrary::GetItemData(ItemID, ItemData))
			//{
			//	GetLifeSkill(ItemData.LifeSkillType, LifeSkill);
			//}

			if (ProgressionLevel < CraftingOption.RequiredPlayerLevel)
			{
				UE_LOG(LogTemp, Warning, TEXT("Player Level Requirement unmet"));
				Client_DisplayScreenMessage(EEXWScreenMessageType::SM_GatheringPlayerLevelRequirementUnmet);
				return false;
			}
			else if (LifeSkill.Level < CraftingOption.RequiredLevel)
			{
				UE_LOG(LogTemp, Warning, TEXT("Life Skill Level Requirement unmet"));
				Client_DisplayScreenMessage(EEXWScreenMessageType::SM_GatheringLifeSkillLevelRequirementUnmet);
				return false;
			}
			for (TPair<FName, int32> Item : CraftingOption.ItemsToUse)
			{
				Server_RemoveItemsFromInventory(Item.Key, Item.Value);
			}
			for (TPair<FName, int32> Item : CraftingOption.ItemsToCreate)
			{
				Server_AddItemsToInventory(Item.Key, Item.Value);
			}
			OnCraftComplete(CraftID);
			Client_OnCraftingComplete(CraftID);
			return true;
		}
	}
	return false;
}

void AEXWCharacter::CreateDefaultLifeSkills()
{
	LifeSkills = {
		FEXWLifeSkill(EEXWLifeSkillType::LS_Mining),
		FEXWLifeSkill(EEXWLifeSkillType::LS_Cooking),
		FEXWLifeSkill(EEXWLifeSkillType::LS_FireMaking),
		FEXWLifeSkill(EEXWLifeSkillType::LS_WoodCutting),
		FEXWLifeSkill(EEXWLifeSkillType::LS_Gathering),
		FEXWLifeSkill(EEXWLifeSkillType::LS_Fishing),
		FEXWLifeSkill(EEXWLifeSkillType::LS_Alchemy),
		FEXWLifeSkill(EEXWLifeSkillType::LS_Smiting),
		FEXWLifeSkill(EEXWLifeSkillType::LS_Crafting),
		FEXWLifeSkill(EEXWLifeSkillType::LS_Tailoring),
		FEXWLifeSkill(EEXWLifeSkillType::LS_Farming),
		FEXWLifeSkill(EEXWLifeSkillType::LS_Breeding),
		FEXWLifeSkill(EEXWLifeSkillType::LS_BountyHunting)
	};
}

bool AEXWCharacter::GetLifeSkill(const EEXWLifeSkillType LifeSkillType, FEXWLifeSkill& OutLifeSkill)
{
	for (FEXWLifeSkill& LifeSkill : LifeSkills)
	{
		if (LifeSkill.Type == LifeSkillType)
		{
			OutLifeSkill = LifeSkill;
			return true;
		}
	}
	return false;
}

void AEXWCharacter::LevelUpLifeSkill(const EEXWLifeSkillType LifeSkillType)
{
	FEXWLifeSkill LifeSkill;
	if (GetLifeSkill(LifeSkillType, LifeSkill))
	{
		Server_SetLifeSkillLevel(LifeSkillType, LifeSkill.Level + 1);
	}
}

void AEXWCharacter::Server_SetLifeSkillLevel_Implementation(const EEXWLifeSkillType LifeSkillType, const int32 NewLevel)
{
	for (FEXWLifeSkill& LifeSkill : LifeSkills)
	{
		if (LifeSkill.Type == LifeSkillType)
		{
			LifeSkill.Level = NewLevel;
		}
	}
}

void AEXWCharacter::GainLifeSkillExperience(const EEXWLifeSkillType LifeSkillType, const int32 ExperienceValue)
{
	FEXWLifeSkill LifeSkill;
	if (GetLifeSkill(LifeSkillType, LifeSkill))
	{
		if (LifeSkillExperiencePerLevel)
		{
			int32 FinalValue = 0;
			int32 NeededExperience = LifeSkillExperiencePerLevel->GetExperience(LifeSkillType, LifeSkill.Level);
			if (LifeSkill.Experience + ExperienceValue > NeededExperience)
			{
				FinalValue = ExperienceValue - NeededExperience + LifeSkill.Experience;
				LevelUpLifeSkill(LifeSkillType);
			}
			else if (LifeSkill.Experience + ExperienceValue == NeededExperience)
			{
				FinalValue = 0;
				LevelUpLifeSkill(LifeSkillType);
			}
			else
			{
				FinalValue = LifeSkill.Experience + ExperienceValue;
			}
			Server_SetLifeSkillExperience(LifeSkillType, FinalValue);
		}
	}
	else
	{
		UE_LOG(EXWCharLog, Warning, TEXT("Life Skill Experience per level progression data asset is NULL."));
	}
}

void AEXWCharacter::Server_SetLifeSkillExperience_Implementation(const EEXWLifeSkillType LifeSkillType, const int32 ExperienceValue)
{
	for (FEXWLifeSkill& LifeSkill : LifeSkills)
	{
		if (LifeSkill.Type == LifeSkillType)
		{
			LifeSkill.Experience = ExperienceValue;
		}
	}
}

void AEXWCharacter::OnRep_LifeSkills()
{
	OnUpdateLifeSkills_Native();
}

void AEXWCharacter::OnUpdateLifeSkills_Native()
{
	OnUpdateLifeSkills();
}

int32 AEXWCharacter::GetExperienceLifeSkillPerLevel(const EEXWLifeSkillType InLifeSkillType, const int32 InLevel)
{
	if (LifeSkillExperiencePerLevel)
	{
		return LifeSkillExperiencePerLevel->GetExperience(InLifeSkillType, InLevel);
	}
	else
	{
		UE_LOG(EXWCharLog, Warning, TEXT("Life skill experience per level data asset is NULL"));
	}
	return -1;
}

void AEXWCharacter::Server_SetSkeletalMesh_Implementation(USkeletalMeshComponent* SkeletalMeshComponent, USkeletalMesh* NewSkeletalMesh)
{
	Multicast_SetSkeletalMesh(SkeletalMeshComponent, NewSkeletalMesh);
	Cast<UEXWSkeletalMeshComponent>(SkeletalMeshComponent)->ApplyDefaultMaterialsLocal();
	OnRep_Skin();
}

void AEXWCharacter::Multicast_SetSkeletalMesh_Implementation(USkeletalMeshComponent* SkeletalMeshComponent, USkeletalMesh* NewSkeletalMesh)
{
	if (SkeletalMeshComponent)
	{
		SkeletalMeshComponent->SetSkeletalMesh(NewSkeletalMesh);
		Cast<UEXWSkeletalMeshComponent>(SkeletalMeshComponent)->ApplyDefaultMaterialsLocal();
		OnRep_Skin();
		OnMeshUpdated.Broadcast();
	}
}

void AEXWCharacter::SetAllMeshVisibility(bool bHide)
{
	if (UWorld* World = GetWorld())
	{
		//Set desired visibility on the skeletal meshes
		for (UEXWSkeletalMeshComponent* SkeletalMeshComp : GetAllSkeletalMeshes())
		{
			SkeletalMeshComp->SetVisibility(bHide, false);
		}
	}
}

TArray<UEXWSkeletalMeshComponent*> AEXWCharacter::GetAllSkeletalMeshes()
{

	TArray<UEXWSkeletalMeshComponent*> ResultArray;
	TArray<UActorComponent*> ActorComps = GetComponentsByClass(UEXWSkeletalMeshComponent::StaticClass());
	for (UActorComponent* ActorComp : ActorComps)
	{
		if (UEXWSkeletalMeshComponent* SkeletalMeshComp = Cast<UEXWSkeletalMeshComponent>(ActorComp))
		{
			ResultArray.Add(SkeletalMeshComp);
		}
	}
	return ResultArray;
}

void AEXWCharacter::SetMaterialOnAllMeshes(UMaterialInterface* NewMaterial)
{
	for (UEXWSkeletalMeshComponent* SkeletalMeshComp : GetAllSkeletalMeshes())
	{
		SkeletalMeshComp->SetAllMaterials(NewMaterial);
	}
}

void AEXWCharacter::Server_SetMaterialOnAllMeshes_Implementation(UMaterialInterface* NewMaterial)
{
	Multicast_SetMaterialOnAllMeshes(NewMaterial);
}

void AEXWCharacter::Multicast_SetMaterialOnAllMeshes_Implementation(UMaterialInterface* NewMaterial)
{
	SetMaterialOnAllMeshes(NewMaterial);
}

void AEXWCharacter::SetMaterialOnAllMeshesForDuration(UMaterialInterface* NewMaterial, const float Duration)
{
	if (UWorld* World = GetWorld())
	{
		// Cache current materials and set all materials for the meshes
		for (UEXWSkeletalMeshComponent* SkeletalMeshComp : GetAllSkeletalMeshes())
		{
			SkeletalMeshComp->CacheMaterials();
			SkeletalMeshComp->SetAllMaterials(NewMaterial);
		}
		// Setup a Delegate that reverts back to the previous materials
		FTimerDelegate MaterialTimerDelegate;
		MaterialTimerDelegate.BindLambda([&]()
			{
				for (UEXWSkeletalMeshComponent* SkeletalMeshComp : GetAllSkeletalMeshes())
				{
					SkeletalMeshComp->ApplyCachedMaterials();
				}
			});
		// Start timer
		World->GetTimerManager().SetTimer(MaterialTimerHandle, MaterialTimerDelegate, .1f, false, Duration);
	}
}

void AEXWCharacter::Client_DisplayScreenMessage_Implementation(const EEXWScreenMessageType ScreenMessageType)
{
	DisplayScreenMessage(ScreenMessageType);
}

void AEXWCharacter::DisplayScreenMessage(const EEXWScreenMessageType ScreenMessageType)
{
	if (AEXWPlayerController* PC = Cast<AEXWPlayerController>(GetController()))
	{
		PC->DisplayScreenMessage(ScreenMessageType);
	}
}

void AEXWCharacter::Client_CallOnRequestNotification_Implementation(const FText& NotificationText)
{
	OnRequestNotification(NotificationText);
}

void AEXWCharacter::Client_Gathering_Implementation(EEXWLifeSkillType Type, float Duration)
{
	if (AEXWPlayerController* PC = Cast<AEXWPlayerController>(GetController()))
	{
		PC->DisplayToggleGatheringProgress(true, Type, Duration);
	}
}

void AEXWCharacter::ActivateGhostTrail(FEXWGhostTrailParams NewGhostTrailParams)
{
	GhostTrailParams = NewGhostTrailParams;
	bIsGhostTrailActive = true;
}

void AEXWCharacter::ProcessGhostTrail()
{
	if (bIsGhostTrailActive)
	{
		if (UWorld* World = GetWorld())
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = this;
			AEXWCharacterPose* CharacterPose = World->SpawnActor<AEXWCharacterPose>(
				AEXWCharacterPose::StaticClass(),
				GetMesh()->GetComponentTransform(),
				SpawnParams);
			if (CharacterPose)
			{
				CharacterPose->SetupMeshes(this, GhostTrailParams);
			}
		}
	}
}

void AEXWCharacter::DeactivateGhostTrail()
{
	bIsGhostTrailActive = false;
}

void AEXWCharacter::Server_LearnAbility_Implementation(FEXWAction Ability, bool bIsFromItem /*= false*/)
{
	if (AbilityPoints > 0 || bIsFromItem)
	{
		bool bAbilityFound = false;
		for (FEXWAction Action : AvailableActions)
		{
			if (Action.ID == Ability.ID)
			{
				Server_LevelAbility(Ability, bIsFromItem);
				bAbilityFound = true;
				break;
			}
		}
		if (!bAbilityFound)
		{
			//AvailableActions.AddUnique(Ability);
			AddAbility(Ability);
			--AbilityPoints;
		}
		Client_AbilityLearned(Ability);
	}

}

void AEXWCharacter::RequestLearnAbility_Implementation(FEXWAction Ability)
{
	Server_LearnAbility(Ability);
}

void AEXWCharacter::Server_LearnAbilityFromItem_Implementation(FEXWItemData Item)
{
	//TODO optimize this tomorrow *wink wink*
	TArray<FEXWAction> PossibleActions = UEXWDataLibrary::GetActionsByRaceAndClass(Race, Class);

	bool bActionFound = false;

	for (FEXWAction Action : PossibleActions)
	{
		if (Action.ID == Item.AbilityName)
		{
			Server_LearnAbility(Action, true);
			bActionFound = true;
			break;
		}

	}
	if (!bActionFound)
	{
		UE_LOG(EXWCharLog, Error, TEXT("Class Doesn't have %s as Ability"), *Item.AbilityName.ToString());
	}
}

void AEXWCharacter::Server_LevelAbility_Implementation(FEXWAction Ability, bool bIsFromItem/* = false*/)
{
	if (AbilityPoints > 0 || bIsFromItem)
	{
		for (FEXWAction& Action : AvailableActions)
		{
			if (Action.ID == Ability.ID)
			{
				Action.Level += 1;
				for (FEXWActionLevel LevelUpgrade : Action.LevelUpgrades)
				{
					if (LevelUpgrade.RequiredLevel == Action.Level)
					{
						Action.Value = LevelUpgrade.AttributeValue;
						Action.Cooldown = LevelUpgrade.Cooldown;
						Action.LevelModifier = LevelUpgrade.LevelModifier;
						break;
					}
				}
				--AbilityPoints;
				break;
			}
		}
	}
	else {
		UE_LOG(EXWCharLog, Log, TEXT("Not enough Ability Points"));
	}

}

void AEXWCharacter::RequestLevelAbility_Implementation(FEXWAction Ability)
{
	Server_LevelAbility(Ability);
}

void AEXWCharacter::Server_LevelAbilityAttribute_Implementation(FEXWAction Ability, EEXWActionAttribute Attribute)
{
	if (AbilityPoints > 0)
	{
		bool bActionFound = false;
		for (FEXWAction& Action : AvailableActions)
		{
			if (Action.ID == Ability.ID)
			{
				bActionFound = true;
				for (FEXWActionAttributeLevel& AttributeLevel : Ability.AttributeLevelUpgrades)
				{
					if (AttributeLevel.Attribute == Attribute)
					{
						if (AttributeLevel.CurrentLevel == AttributeLevel.MaxLevel)
						{
							UE_LOG(EXWCharLog, Log, TEXT("Ability Attribute is at Max Level!"));
							return;
						}

						++AttributeLevel.CurrentLevel; //AttributeLevel.CurrentLevel += 1;
						for (FEXWActionAttributeLevelUpgrades Level : AttributeLevel.Levels)
						{
							if (Level.RequiredLevel == AttributeLevel.CurrentLevel)
							{
								switch (Attribute)
								{
								case EEXWActionAttribute::AA_Cooldown:
									Action.Cooldown = Level.AttributeValue;
									break;
								case EEXWActionAttribute::AA_AttributeValue:
									Action.Value = Level.AttributeValue;
									break;
								case EEXWActionAttribute::AA_LevelModifier:
									Action.LevelModifier = Level.AttributeValue;
									break;
								case EEXWActionAttribute::AA_Damage:
									break;
								default:
									break;
								}
								break;
							}
						}
						break;
					}
				}
				break;
			}
		}
		if (!bActionFound)
		{
			UE_LOG(EXWCharLog, Log, TEXT("Ability not found!"));
		}
	}
	else {
		UE_LOG(EXWCharLog, Log, TEXT("No Ability Points!"));
	}
}

void AEXWCharacter::RequestLevelAbilityAttribute_Implementation(FEXWAction Ability, EEXWActionAttribute Attribute)
{
	Server_LevelAbilityAttribute(Ability, Attribute);
}

FEXWActionAttributeLevel AEXWCharacter::GetAttributeData(FEXWAction Ability, EEXWActionAttribute Attribute)
{
	FEXWActionAttributeLevel OutAttributeLevel = FEXWActionAttributeLevel();
	for (FEXWActionAttributeLevel& AttributeLevel : Ability.AttributeLevelUpgrades)
	{
		if (AttributeLevel.Attribute == Attribute)
		{
			return AttributeLevel;
			break;
		}
	}
	return OutAttributeLevel;
}

bool AEXWCharacter::CanLearnAbility(FEXWItemData Item)
{
	TArray<FEXWAction> PossibleActions = UEXWDataLibrary::GetActionsByRaceAndClass(Race, Class);

	bool bActionFound = false;

	for (FEXWAction Action : PossibleActions)
	{
		if (Action.ID == Item.AbilityName)
		{
			bActionFound = true;
			break;
		}

	}
	if (!bActionFound)
	{
		UE_LOG(EXWCharLog, Log, TEXT("Class Doesn't have %s as Ability"), *Item.AbilityName.ToString());
	}
	return bActionFound;
}

void AEXWCharacter::Client_AbilityLearned_Implementation(FEXWAction Ability)
{
	OnAbilityLearned(Ability);
}

void AEXWCharacter::UpdateAnimBP()
{
}

void AEXWCharacter::UpdateWeaponAttachmentSockets()
{
	if (Gender == EEXWGender::G_Female)
	{
		RightHandWeaponMesh->AttachTo(GetMesh(), "WeaponAttachPoint_Hand_R_F");
		LeftHandWeaponMesh->AttachTo(GetMesh(), "WeaponAttachPoint_Hand_L_F");
	}
}

bool AEXWCharacter::UpdateEquipmentMesh(USkeletalMeshComponent* SkeletalMeshComponent, EEXWSlotType CosmeticSlot, EEXWSlotType EquipmentSlot)
{
	USkeletalMesh* SkeletalMeshToEquip = nullptr;
	int32 slotid;
	if (UEXWInventoryLibrary::GetSlotIndexByType(slotid, InventoryCosmeticEquipment, CosmeticSlot)) //Cosmetic on slot?
	{
		FEXWItemData ItemData;
		if (UEXWInventoryLibrary::GetItemData(InventoryCosmeticEquipment.ItemSlots[slotid].ItemID, ItemData))
		{
			if (ItemData.MultiRace)
			{
				for (auto obj : ItemData.RacialSkeletalMeshes)
				{
					if (obj.Race == Race)
					{
						SkeletalMeshToEquip = *obj.SkeletalMeshes.Find(Gender);
						break;
					}
				}
			}
			else
			{
				SkeletalMeshToEquip = *ItemData.SkeletalMeshes.Find(Gender);
			}

			if (SkeletalMeshToEquip)
			{
				SkeletalMeshComponent->SetSkeletalMesh(SkeletalMeshToEquip);
				Cast<UEXWSkeletalMeshComponent>(SkeletalMeshComponent)->CacheMaterialsLocal();
				return true;
			}
		}
	}
	if (UEXWInventoryLibrary::GetSlotIndexByType(slotid, InventoryEquipment, EquipmentSlot)) //equipment on slot?
	{
		FEXWItemData ItemData;
		if (UEXWInventoryLibrary::GetItemData(InventoryEquipment.ItemSlots[slotid].ItemID, ItemData))
		{
			if (ItemData.MultiRace)
			{
				for (auto obj : ItemData.RacialSkeletalMeshes)
				{
					if (obj.Race == Race)
					{
						SkeletalMeshToEquip = *obj.SkeletalMeshes.Find(Gender);
						break;
					}
				}
			}
			else
			{
				SkeletalMeshToEquip = *ItemData.SkeletalMeshes.Find(Gender);
			}

			if (SkeletalMeshToEquip)
			{
				SkeletalMeshComponent->SetSkeletalMesh(SkeletalMeshToEquip);
				Cast<UEXWSkeletalMeshComponent>(SkeletalMeshComponent)->CacheMaterialsLocal();
				return true;
			}
		}
	}
	return false;
}

void AEXWCharacter::UpdateWeapons()
{
	USkeletalMesh* Mesh = nullptr;

	if (!UpdateEquipmentMesh(RightHandWeaponMesh, EEXWSlotType::ST_Cosmetic_RightHand, EEXWSlotType::ST_Equipment_RightHand))//update right hand weapon mesh with equipment or cosmetic
	{
		RightHandWeaponMesh->SetSkeletalMesh(nullptr);
	}

	if (UpdateEquipmentMesh(LeftHandWeaponMesh, EEXWSlotType::ST_Cosmetic_LeftHand, EEXWSlotType::ST_Equipment_LeftHand))//update left hand weapon offset
	{
		OnRep_LeftHandWeaponOffset();
	}
	else  //update left hand weapon mesh with equipment or cosmetic
	{
		LeftHandWeaponMesh->SetSkeletalMesh(nullptr);
	}
	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::UpdateHead(FName id)
{
	if (id==FName("None"))
	{
		return;
	}
	USkeletalMesh* Mesh = nullptr;

	if (UpdateEquipmentMesh(HeadMesh, EEXWSlotType::ST_Cosmetic_Head, EEXWSlotType::ST_Equipment_Head))//update mesh with equipment or cosmetic
	{
		return;
	}
	else if (UEXWDataLibrary::GetHeadMeshFromDT(HeadName, Mesh)) // Root body mesh and body mesh
	{
		HeadMesh->SetSkeletalMesh(Mesh);

	}
	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::UpdateHair()//cosmetic
{
	FEXWHairType HairData;
	USkeletalMesh* Mesh = nullptr;
	FVector Offset;

	if (UEXWDataLibrary::GetHairMeshFromDT(HairName, HairData))
	{
		HairMesh->SetSkeletalMesh(HairData.SkeletalMesh);
		switch (Race)
		{
		case EEXWRace::R_Human:
			HairMesh->SetRelativeLocation(HairData.HumanOffset);
			break;
		case EEXWRace::R_Vampire:
			HairMesh->SetRelativeLocation(HairData.VampireOffset);
			break;
		case EEXWRace::R_Werewolf:
			HairMesh->SetRelativeLocation(HairData.WerewolfOffset);
			break;
		default:
			HairMesh->SetRelativeLocation(HairData.HumanOffset);
			break;
		}
		OnMeshUpdated.Broadcast();
	}
}

void AEXWCharacter::UpdateHairColor(FName id) //cosmetic
{
	if (id==FName("None"))
	{
		return;
	}
	FLinearColor Color;

	if (UEXWDataLibrary::GetHairColorFromDT(HairColorName, Color))
	{
		UMaterialInstanceDynamic* DynamicHairMaterial = UMaterialInstanceDynamic::Create(HairMesh->GetMaterial(0), this);
		DynamicHairMaterial->SetVectorParameterValue(TEXT("Color"), Color);

		UMaterialInstanceDynamic* DynamicFaceMaterial = UMaterialInstanceDynamic::Create(EyebrowsMesh->GetMaterial(0), this);
		DynamicFaceMaterial->SetVectorParameterValue(TEXT("BaseColorTextureMultiplier_White"), Color);

		EyebrowsMesh->SetMaterial(0, DynamicFaceMaterial);

		HairMesh->SetMaterial(0, DynamicHairMaterial);
		OnMeshUpdated.Broadcast();
	}
}

void AEXWCharacter::UpdateArms(FName id)
{
	if (id==FName("None"))
	{
		return;
	}
	USkeletalMesh* Mesh = nullptr;

	if (UpdateEquipmentMesh(ArmsMesh, EEXWSlotType::ST_Cosmetic_Arms, EEXWSlotType::ST_Equipment_Arms))//update mesh with equipment or cosmetic
	{
		return;
	}
	else if (UEXWDataLibrary::GetArmsMeshFromDT(ArmsName, Mesh)) // Root body mesh and body mesh
	{
		ArmsMesh->SetSkeletalMesh(Mesh);
	}
	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::UpdateBody(FName id) //cosmetic
{
}

void AEXWCharacter::UpdateTorso(FName id)
{
	if (id==FName("None"))
	{
		return;
	}
	USkeletalMesh* Mesh = nullptr;

	if (UpdateEquipmentMesh(TorsoMesh, EEXWSlotType::ST_Cosmetic_Torso, EEXWSlotType::ST_Equipment_Torso))//update torso mesh with equipment or cosmetic
	{
		if (UEXWDataLibrary::GetTorsoMeshFromDT(TorsoName, Mesh)) // Root body mesh
		{
			GetMesh()->SetSkeletalMesh(Mesh);
		}
	}
	else if (UEXWDataLibrary::GetTorsoMeshFromDT(TorsoName, Mesh)) // Root body mesh and torso body mesh
	{
		TorsoMesh->SetSkeletalMesh(Mesh);
		GetMesh()->SetSkeletalMesh(Mesh);
	}

	UpdateWeapons();
	FTimerHandle RepHandle;
	GetWorldTimerManager().SetTimer(
		RepHandle, this, &AEXWCharacter::UpdateWeapons, 1.0f, false);

	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::UpdateEyes(FName id)
{
	if (id==FName("None"))
	{
		return;
	}
	USkeletalMesh* Mesh = nullptr;
	USkeletalMesh* EbMesh = nullptr;

	if (UEXWDataLibrary::GetEyesMeshFromDT(EyesName, Mesh, EbMesh))
	{
		EyesMesh->SetSkeletalMesh(Mesh);
		EyebrowsMesh->SetSkeletalMesh(EbMesh);
	}
	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::UpdateEyeColor(FName id)
{
	if (id==FName("None"))
	{
		return;
	}
	FLinearColor Color;
	if (UEXWDataLibrary::GetEyeColorFromDT(EyeColorName, Color))
	{
		UMaterialInstanceDynamic* DynamicEyeMaterial = UMaterialInstanceDynamic::Create(EyesMesh->GetMaterial(0), this);
		DynamicEyeMaterial->SetVectorParameterValue(TEXT("BaseColorTextureMultiplier_White"), Color);
		//DynamicEyeMaterial->SetVectorParameterValue(TEXT("BaseColorTextureMultiplier_Black"), Color);
		
		FEXWSkinType SkinTypeData;
		if (UEXWDataLibrary::GetSkinTypeFromDT(id, SkinTypeData))
		{
			DynamicEyeMaterial->SetVectorParameterValue(TEXT("BaseColorTextureMultiplier_Black"),SkinTypeData.Color);
		}
		EyesMesh->SetMaterial(0, DynamicEyeMaterial);
	}
	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::UpdateFace(FName id)
{
}

void AEXWCharacter::UpdateLegs(FName id)
{
	if (id==FName("None"))
	{
		return;
	}
	USkeletalMesh* Mesh = nullptr;

	if (UpdateEquipmentMesh(LegsMesh, EEXWSlotType::ST_Cosmetic_Legs, EEXWSlotType::ST_Equipment_Legs))//update mesh with equipment or cosmetic
	{
		return;
	}
	else if (UEXWDataLibrary::GetLegsMeshFromDT(LegsName, Mesh)) // Root body mesh and body mesh
	{
		LegsMesh->SetSkeletalMesh(Mesh);
	}
	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::UpdateFeet(FName id)
{
	if (id==FName("None"))
	{
		return;
	}
	USkeletalMesh* Mesh = nullptr;

	if (UpdateEquipmentMesh(FeetMesh, EEXWSlotType::ST_Cosmetic_Feet, EEXWSlotType::ST_Equipment_Feet))//update mesh with equipment or cosmetic
	{
		return;
	}
	else if (UEXWDataLibrary::GetFeetMeshFromDT(FeetName, Mesh)) // Root body mesh and body mesh
	{
		FeetMesh->SetSkeletalMesh(Mesh);
	}
	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::UpdateSkin(FName id)
{
	if (id==FName("None"))
	{
		return;
	}
	FEXWSkinType SkinTypeData;
	if (UEXWDataLibrary::GetSkinTypeFromDT(id, SkinTypeData))
	{
		UMaterialInstanceDynamic* HeadMaterial = nullptr;
		FName HeadSkinSlotName;
		if (HeadMesh->IsMaterialSlotNameValid(FName("skin_body")))
		{
			HeadSkinSlotName = FName("skin_body");
			HeadMaterial = UMaterialInstanceDynamic::Create(HeadMesh->SkeletalMesh->Materials[(HeadMesh->GetMaterialIndex(FName("skin_body")))].MaterialInterface,this);
		}
		else if(HeadMesh->IsMaterialSlotNameValid(FName("skin_head_V3")))
		{
			HeadSkinSlotName = FName("skin_head_V3");
			HeadMaterial = UMaterialInstanceDynamic::Create(HeadMesh->SkeletalMesh->Materials[(HeadMesh->GetMaterialIndex(FName("skin_head_V3")))].MaterialInterface,this);	
		}
		else if(HeadMesh->IsMaterialSlotNameValid(FName("map_head")))
		{
			HeadSkinSlotName = FName("map_head");
			HeadMaterial = UMaterialInstanceDynamic::Create(HeadMesh->SkeletalMesh->Materials[(HeadMesh->GetMaterialIndex(FName("map_head")))].MaterialInterface,this);	
		}



		if(HeadMaterial!=nullptr)
		{
			HeadMaterial->SetVectorParameterValue(FName("BaseColorTextureMultiplier_Black"),FVector(SkinTypeData.Color));
			HeadMaterial->SetVectorParameterValue(FName("HighlightColor"),FVector(SkinTypeData.HighlightColor));
			HeadMesh->SetMaterialByName(HeadSkinSlotName,HeadMaterial);
		}


		if (EyesMesh->IsMaterialSlotNameValid(FName("skin_head_V3")))
		{
			UMaterialInstanceDynamic* EyeMaterial = UMaterialInstanceDynamic::Create(EyesMesh->SkeletalMesh->Materials[(EyesMesh->GetMaterialIndex(FName("skin_head_V3")))].MaterialInterface,this);
			
			FLinearColor Color;
			if (UEXWDataLibrary::GetEyeColorFromDT(EyeColorName, Color))
			{
				EyeMaterial->SetVectorParameterValue(FName("BaseColorTextureMultiplier_White"), Color);
			}
			EyeMaterial->SetVectorParameterValue(FName("BaseColorTextureMultiplier_Black"),FVector(SkinTypeData.Color));
			EyeMaterial->SetVectorParameterValue(FName("HighlightColor"),FVector(SkinTypeData.HighlightColor));
			EyesMesh->SetMaterialByName(FName("skin_head_V3"),EyeMaterial);
		}

		if (TorsoMesh->IsMaterialSlotNameValid(FName("skin_body")))
		{
			UMaterialInstanceDynamic* TorsoMaterial = UMaterialInstanceDynamic::Create(TorsoMesh->SkeletalMesh->Materials[(TorsoMesh->GetMaterialIndex(FName("skin_body")))].MaterialInterface,this);
			TorsoMaterial->SetVectorParameterValue(FName("BaseColorTextureMultiplier"),FVector(SkinTypeData.Color));
			TorsoMaterial->SetVectorParameterValue(FName("HighlightColor"),FVector(SkinTypeData.HighlightColor));
			TorsoMesh->SetMaterialByName(FName("skin_body"),TorsoMaterial);
		}
		
		if (ArmsMesh->IsMaterialSlotNameValid(FName("skin_body")))
		{
			UMaterialInstanceDynamic* ArmsMaterial = UMaterialInstanceDynamic::Create(ArmsMesh->SkeletalMesh->Materials[(ArmsMesh->GetMaterialIndex(FName("skin_body")))].MaterialInterface,this);
			ArmsMaterial->SetVectorParameterValue(FName("BaseColorTextureMultiplier"),FVector(SkinTypeData.Color));
			ArmsMaterial->SetVectorParameterValue(FName("HighlightColor"),FVector(SkinTypeData.HighlightColor));
			ArmsMesh->SetMaterialByName(FName("skin_body"),ArmsMaterial);
		}

		if (LegsMesh->IsMaterialSlotNameValid(FName("skin_body")))
		{
			UMaterialInstanceDynamic* LegsMaterial = UMaterialInstanceDynamic::Create(LegsMesh->SkeletalMesh->Materials[(LegsMesh->GetMaterialIndex(FName("skin_body")))].MaterialInterface,this);
			LegsMaterial->SetVectorParameterValue(FName("BaseColorTextureMultiplier"),FVector(SkinTypeData.Color));
			LegsMaterial->SetVectorParameterValue(FName("HighlightColor"),FVector(SkinTypeData.HighlightColor));
			LegsMesh->SetMaterialByName(FName("skin_body"),LegsMaterial);
		}

		if (FeetMesh->IsMaterialSlotNameValid(FName("skin_body")))
		{
			UMaterialInstanceDynamic* FeetMaterial = UMaterialInstanceDynamic::Create(FeetMesh->SkeletalMesh->Materials[(FeetMesh->GetMaterialIndex(FName("skin_body")))].MaterialInterface,this);
			FeetMaterial->SetVectorParameterValue(FName("BaseColorTextureMultiplier"),FVector(SkinTypeData.Color));
			FeetMaterial->SetVectorParameterValue(FName("HighlightColor"),FVector(SkinTypeData.HighlightColor));
			FeetMesh->SetMaterialByName(FName("skin_body"),FeetMaterial);
		}		
	}
}

void AEXWCharacter::OnRep_Head()
{
	UpdateHead(HeadName);
	if (HairName != FName("None"))
	{
		UpdateHair();
	}
	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::OnRep_Hair()
{
	FTimerHandle RepHandle;
	GetWorldTimerManager().SetTimer(
		RepHandle, this, &AEXWCharacter::UpdateHair, 1.0f, false);

	OnMeshUpdated.Broadcast();
}

void AEXWCharacter::OnRep_HairColor()
{
	UpdateHairColor(HairColorName);
}

void AEXWCharacter::OnRep_ArmsMesh()
{
	UpdateArms(ArmsName);
}

void AEXWCharacter::OnRep_Body()
{
	UpdateBody(BodyName);
}

void AEXWCharacter::OnRep_TorsoMesh()
{
	UpdateTorso(TorsoName);
}

void AEXWCharacter::OnRep_Eyes()
{
	UpdateEyes(EyesName);
}

void AEXWCharacter::OnRep_EyeColor()
{
	UpdateEyeColor(EyeColorName);
}

void AEXWCharacter::OnRep_Face()
{
	UpdateFace(FaceName);
}

void AEXWCharacter::OnRep_Legs()
{
	UpdateLegs(LegsName);
}

void AEXWCharacter::OnRep_Feet()
{
	UpdateFeet(FeetName);
}

void AEXWCharacter::OnRep_Skin()
{
	UpdateSkin(SkinName);
}

void AEXWCharacter::OnRep_RightHandWeapon()
{
	if (RightHandWeapon != nullptr)
	{
		RightHandWeaponMesh->SetSkeletalMesh(RightHandWeapon);
		if (Class == EEXWClass::C_DarkArts)
		{
			RightHandWeaponMesh->AttachTo(GetMesh(), "WeaponAttachPoint_Floating");
		}
		else
		{
			if (Gender == EEXWGender::G_Female)
			{
				RightHandWeaponMesh->AttachTo(GetMesh(), "WeaponAttachPoint_Hand_R_F");
			}
			else
			{
				RightHandWeaponMesh->AttachTo(GetMesh(), "WeaponAttachPoint_Hand_R");
			}
			
		}
	}
}

void AEXWCharacter::OnRep_LeftHandWeapon()
{
	if (LeftHandWeapon != nullptr)
	{
		LeftHandWeaponMesh->SetSkeletalMesh(LeftHandWeapon);
	}
}

void AEXWCharacter::OnRep_RightHandWeaponOffset()
{
}

void AEXWCharacter::OnRep_LeftHandWeaponOffset()
{
	LeftHandWeaponMesh->SetRelativeTransform(LeftHandWeaponOffset);
}

void AEXWCharacter::RequestCreateParty_Implementation(const FName& PartyID, const FText& PartyName, const TArray<AEXWCharacter*>& PartyMembers)
{
	if (AExWorldGameState* GameState = GetWorld()->GetGameState<AExWorldGameState>())
	{
		GameState->CreateParty(PartyID, PartyName, this, PartyMembers);
	}
}

void AEXWCharacter::RequestInviteToParty_Implementation(FEXWParty Party, const FText& CharacterName)
{
	if (AExWorldGameState* GameState = GetWorld()->GetGameState<AExWorldGameState>())
	{
		GameState->InviteToParty(Party, CharacterName);
	}
}

void AEXWCharacter::RequestInviteCharacterToParty_Implementation(FEXWParty Party, AEXWCharacter* Character)
{
	if (AExWorldGameState* GameState = GetWorld()->GetGameState<AExWorldGameState>())
	{
		GameState->InviteToPartyCharacter(Party, Character);
	}
}

void AEXWCharacter::RequestJoinParty_Implementation(FEXWParty Party)
{
	if (AExWorldGameState* GameState = GetWorld()->GetGameState<AExWorldGameState>())
	{
		GameState->JoinParty(Party, this);
	}
}

void AEXWCharacter::RequestRemoveParty_Implementation(FEXWParty Party)
{
	if (AExWorldGameState* GameState = GetWorld()->GetGameState<AExWorldGameState>())
	{
		GameState->RemoveParty(Party, this);
	}
}

void AEXWCharacter::RequestPromoteMember_Implementation(FEXWParty Party, AEXWCharacter* CharacterToPromote)
{
	if (AExWorldGameState* GameState = GetWorld()->GetGameState<AExWorldGameState>())
	{
		GameState->PromoteMember(Party, this, CharacterToPromote);
	}
}

void AEXWCharacter::RequestKickMember_Implementation(FEXWParty Party, AEXWCharacter* CharacterToKick)
{
	if (AExWorldGameState* GameState = GetWorld()->GetGameState<AExWorldGameState>())
	{
		GameState->KickMember(Party, this, CharacterToKick);
	}
}

void AEXWCharacter::RequestLeaveParty_Implementation(FEXWParty Party)
{
	if (AExWorldGameState* GameState = GetWorld()->GetGameState<AExWorldGameState>())
	{
		GameState->LeaveParty(Party, this);
	}
}

void AEXWCharacter::Server_SetHasPartyInvite_Implementation(bool NewValue /*= false*/)
{
	bHasPartyInvite = NewValue;
}

void AEXWCharacter::SetHasPartyInvite(bool NewValue /*= false*/)
{
	Server_SetHasPartyInvite(NewValue);
}

void AEXWCharacter::Client_OnCharacterKill_Implementation(AEXWCharacter* Victim)
{
	OnCharacterKill.Broadcast(Victim);
	if (CurrentItemSet.ID != "None")
	{
		FEXWItemSetEventEffect* OnKillParticles = CurrentItemSet.EventEffects.Find(EEXWItemSetEvent::ISE_OnKill);
		if (OnKillParticles)
		{
			Multicast_PlayParticles(OnKillParticles->Effect, OnKillParticles->BoneName);
		}
	}
	
}

void AEXWCharacter::Client_OnCharacterDeath_Implementation(AEXWCharacter* Killer)
{
	OnCharacterDeath.Broadcast(this, Killer);
	if (CurrentItemSet.ID != "None")
	{
		FEXWItemSetEventEffect* OnDeathParticles = CurrentItemSet.EventEffects.Find(EEXWItemSetEvent::ISE_OnDeath);
		if (OnDeathParticles)
		{
			Multicast_PlayParticles(OnDeathParticles->Effect, OnDeathParticles->BoneName);
		}
		
	}
	
}

void AEXWCharacter::Client_OnCharacterGatherComplete_Implementation(FName ItemID, int32 ItemCount)
{
	OnCharacterGatherComplete.Broadcast(ItemID, ItemCount);
	if (CurrentItemSet.ID != "None")
	{
		FEXWItemSetEventEffect* OnGatherParticles = CurrentItemSet.EventEffects.Find(EEXWItemSetEvent::ISE_OnGatherComplete);
		if (OnGatherParticles)
		{
			Multicast_PlayParticles(OnGatherParticles->Effect, OnGatherParticles->BoneName);
		}
		
	}
	
}

void AEXWCharacter::Server_HandleOnItemEquipped_Implementation(FName ItemID)
{
	FEXWItemData Item;
	if (UEXWInventoryLibrary::GetItemData(ItemID, Item))
	{
		Server_HandleItemSetEquipment(Item.ItemSetID);
	}
	
}

void AEXWCharacter::Server_HandleOnItemUnEquipped_Implementation(FName ItemID)
{
	FEXWItemData Item;
	if (UEXWInventoryLibrary::GetItemData(ItemID, Item))
	{
		FEXWItemSet ItemSet = UEXWDataLibrary::GetItemSetByID(Item.ItemSetID);
		if (ItemSet == CurrentItemSet)
		{
			Server_HandleItemSetUnEquipment(Item.ItemSetID);
		}
		
	}
}

void AEXWCharacter::Client_OnCraftingComplete_Implementation(FName CraftID)
{
	OnCraftingComplete.Broadcast(CraftID);
	if (CurrentItemSet.ID != "None")
	{
		FEXWItemSetEventEffect* OnCraftParticles = CurrentItemSet.EventEffects.Find(EEXWItemSetEvent::ISE_OnCraftComplete);
		if (OnCraftParticles)
		{
			Multicast_PlayParticles(OnCraftParticles->Effect, OnCraftParticles->BoneName);
		}
		
	}
	
}

