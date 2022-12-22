// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/EXWInteractable.h"
#include "Library/EXWDataStruct.h"
#include "Library/Inventory/EXWInventoryStruct.h"

#include "EXWCharacter.generated.h"

//General Character Log
DECLARE_LOG_CATEGORY_EXTERN(EXWCharLog, Log, All);

class UDataTable;
class UUserWidget;
class UEXWProgressionLevelDA;
class UEXWSkillProgressionLevelDA;
class UEXWSkeletalMeshComponent;
struct FEXWParty;
struct FEXWItemSet;

////Delegates
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterDataLoaded);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActiveStatusEffectsUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAvailableActionsSet);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIFrameActionsSet);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStatesCleared);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMeshUpdated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShopStarted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShopStopped);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterLoaded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterRespawn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateAdded, EEXWState, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStateRemoved, EEXWState, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityAdded, FEXWAction, Ability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityRemoved, FEXWAction, Ability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStatusEffectAdded, FEXWStatusEffectData, StatusEffect);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStatusEffectRemoved, FEXWStatusEffectData, StatusEffect);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterKill, AEXWCharacter*, Killed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEquipItem, FName, ItemID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUnEquipItem, FName, ItemID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCraftingComplete, FName, CraftID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCharacterDeath, AEXWCharacter*, DeadCharacter, AEXWCharacter*, Killer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCharacterGatherComplete, FName, ItemID, int32, ItemCount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReceiveInteraction, AEXWCharacter*, SourceCharacter, EEXWInteractionType, InteractionType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInteract, AActor*, TargetActor, EEXWInteractionType, InteractionType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGainAttribute, EEXWAttributeType, AttributeType, float, Value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLoseAttribute, EEXWAttributeType, AttributeType, float, Value);

DECLARE_DELEGATE_OneParam(FInputExecuteActionDelegate, const int32);
DECLARE_DELEGATE_OneParam(FInputTargetingDelegate, const FEXWTargetingParams);
DECLARE_DELEGATE_OneParam(FInputTargetingStopDelegate, const bool);
/**
 * The game's character base class
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWCharacter : public ACharacter, public IEXWInteractable
{
	GENERATED_BODY()
	
public:

	/** Character Name */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|General")
	FText Name = FText::FromString(FString("Character_Name"));

	/** Character Race */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|General")
	EEXWRace Race;

	/** Character Class */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|General")
	EEXWClass Class = EEXWClass::C_Other;

	/** Character Gender */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|General")
	EEXWGender Gender;

	/** Character Main Attribute */
	UPROPERTY(Replicated, BlueprintReadOnly, EditAnywhere, Category = "EXWorld|Character|General")
	EEXWAttributeType MainAttribute = EEXWAttributeType::Mana;

	/** Character Portrait*/
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|General")
	UTexture2D* Portrait;

	/** Character Faction */
	UPROPERTY(Replicated, BlueprintGetter=GetFaction, BlueprintSetter=SetFaction, EditAnywhere, Category = "EXWorld|Character|General")
	int32  Faction;

	/** General Character Progression level */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Level")
	int32 ProgressionLevel = 1;

	/** General Character Progression current experience */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Level")
	int32 ProgressionExperience = 0;

	/** General Character Progression */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Level")
	UEXWProgressionLevelDA* ExperiencePerLevel;

	/** Character Gear Item Level */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Level")
	int32 ItemLevel=0;

	/** Effects To Play On Level up*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Level|ParticleSystem")
	UParticleSystem* ParticleSystemOnLevelUp;

	/** Effects To Play On Level up*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Level|ParticleSystem")
	FVector ParticleSystemOnLevelUpOffset = FVector(0, 0, 0);

	/** Sound To Play On Level up*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Level|Sound")
	USoundBase* SoundOnLevelUp;

	/** General Character Progression */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Level")
	uint8 bCanGainExperience : 1;

	/** General Character Progression */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Level")
	FEXWExperienceOnKill ExperienceOnKill;

	/** Unspent Character Level points for stats */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Stats")
	int32 UnspentLevelPoints = 0;

	/** Unspent Character Level points for stats */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Stats")
	int32 UnspentAbilityPoints = 0;

	/** Level points for each stat */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Stats")
	TArray<FEXWStatLevelPoint> StatLevelPoints;

	/** Attributes values of the character */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Attributes")
	TArray<FEXWAttribute> Attributes;

	/** Stats values of the character */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Stats")
	TArray<FEXWStat> Stats;

	/** Damage reduction of the character */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Damage Reduction")
	TArray<FEXWDamageReduction> DamageReductions;

	/** Damage reduction of the character */
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Damage Absorption")
	TArray<FEXWDamageAbsorption> DamageAbsorptions;

	/** A custom reaction data table specific for this character */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Reaction")
	UDataTable* ReactionDataTable = nullptr;

	/** Stat level modifier data table row name to use on every level up. (Make sure the DataTable is set in the EXWSingleton and the singleton is added to the project settings).*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Stats")
	FName StatLevelModifierRowName = "None";

	/** Stat level modifier data table row name to use on every level up. */
	UPROPERTY(ReplicatedUsing = OnRep_ActiveStatusEffects, BlueprintReadWrite, Category = "EXWorld|Character|StatusEffect")
	TArray<FEXWStatusEffectData> ActiveStatusEffects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Death")
	bool bAutoSetDeadState = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Death")
	UAnimMontage* DeathMontage = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Death")
	bool bDisableInputOnDeath = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Death")
	bool bStopRegenOnDeath = true;

	/** Stats values of the character */
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|State")
	TArray<EEXWState> States = {};

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|State")
	TArray<EEXWStateOverrider> StateOverriders = {};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|State")
	float RespawnInvulnerabilityDuration = 5.0f;

	/**
	 * Abilities and Actions
	 */

	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Actions")
	TArray<FEXWAction> AvailableActions;

	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Actions")
	TArray<FEXWAction> IFrameActions;

	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Actions")
	FEXWAction LastActiveAction;

	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Actions")
	int32 AbilityPoints;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Actions")
	int32 AbilityPointsPerLevel = 2;

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|Actions")
	bool bWeaponEquipped = false;

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|Actions")
	bool bIsInCombat = false;

	/**
	 * Inventory
	 */

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|Inventory")
	FEXWInventory Inventory= FEXWInventory(40);

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|Inventory")
	FEXWInventory InventoryEquipment;

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|Inventory")
	FEXWInventory InventoryCosmeticEquipment;

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|Inventory")
	FEXWInventory InventoryShop;

	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|Inventory")
	FEXWInventory InventoryTrade;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Inventory")
	TArray<FEXWItemDropRate> ItemsDropRatesOnDeath;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Inventory")
	TArray<FEXWItemDropRate> SingleDropItemsDropRatesOnDeath;

	UPROPERTY(ReplicatedUsing = OnRep_LifeSkills, BlueprintReadWrite, Category = "EXWorld|Character|LifeSkill")
	TArray<FEXWLifeSkill> LifeSkills;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|LifeSkill")
	UEXWSkillProgressionLevelDA* LifeSkillExperiencePerLevel = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Character|Interaction")
	UWidgetComponent* InteractionWidgetComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Interaction")
	TArray<EEXWInteractionType> DefaultInteractionTypes = { EEXWInteractionType::IT_TradeRequest, EEXWInteractionType::IT_DuelRequest, EEXWInteractionType::IT_InviteToParty };

	/**
	 * Meshes list
	 */

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* HeadMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* TorsoMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* ArmsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* LegsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* FeetMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* EyesMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* EyebrowsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* TeethMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* TongueMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* HairMesh;

	//weapons

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* RightHandWeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* LeftHandWeaponMesh;

	/**
	* Cosmetics/Meshes Replication
	*/

	UPROPERTY(ReplicatedUsing = OnRep_Head, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName HeadName;

	UPROPERTY(ReplicatedUsing = OnRep_Hair, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName HairName;

	UPROPERTY(ReplicatedUsing = OnRep_HairColor, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName HairColorName;

	UPROPERTY(ReplicatedUsing = OnRep_ArmsMesh, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName ArmsName;

	UPROPERTY(ReplicatedUsing = OnRep_Body, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName BodyName;

	UPROPERTY(ReplicatedUsing = OnRep_TorsoMesh, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName TorsoName;

	UPROPERTY(ReplicatedUsing = OnRep_Eyes, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName EyesName;

	UPROPERTY(ReplicatedUsing = OnRep_EyeColor, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName EyeColorName;

	UPROPERTY(ReplicatedUsing = OnRep_Face, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName FaceName;

	UPROPERTY(ReplicatedUsing = OnRep_Legs, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName LegsName;

	UPROPERTY(ReplicatedUsing = OnRep_Feet, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName FeetName;

	UPROPERTY(ReplicatedUsing = OnRep_Skin, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FName SkinName;

	UPROPERTY(ReplicatedUsing = OnRep_RightHandWeapon, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	USkeletalMesh* RightHandWeapon;

	UPROPERTY(ReplicatedUsing = OnRep_LeftHandWeapon, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	USkeletalMesh* LeftHandWeapon;

	UPROPERTY(ReplicatedUsing = OnRep_RightHandWeaponOffset, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FVector RightHandWeaponOffset;

	UPROPERTY(ReplicatedUsing = OnRep_LeftHandWeaponOffset, BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Mesh|Replication")
	FTransform LeftHandWeaponOffset;

	/**
	 * Shop
	 */
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "EXWorld|Character|Shop")
	bool bIsVending = false;

	/**
	 * General
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Respawn")
	float RotateCharacterTowardsCameraDirectionSpeed = 20.0f;

	AEXWCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void BeginPlay() override;

	void BindDelegates();

	virtual void Tick(float DeltaSeconds) override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void UnPossessed() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/**
	 * This function is extremely important, it will parse all the data related to the character and initialize it.
	 * Don't call this out of the blue and make sure you don't mess around with it unless you know what you're doing. 	   
	 */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|General")
	virtual void InitializeCharacterData();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|General")
	void Server_InitializeCharacterData();

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|General")
	void OnInitializeCharacterData();
	virtual void OnInitializeCharacterData_Native();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Character|General")
	void Multicast_DisableInput();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Character|General")
	void Multicast_EnableInput();

	/*
	* Respawn/Revive
	*/

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Respawn")
	void Respawn(const FVector NewLocation = FVector::ZeroVector, const FRotator NewRotation = FRotator(ForceInit),bool bUseRespawnPoint=false);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Character|Respawn")
	void Multicast_Respawn(const FVector NewLocation = FVector::ZeroVector, const FRotator NewRotation = FRotator(ForceInit), bool bUseRespawnPoint = false);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Respawn")
	void Server_OnRespawn(bool bUseRespawnPoint);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Respawn")
	void OnRespawn();
	virtual void OnRespawn_Native();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Respawn|ParticleSystem")
	UNiagaraSystem* ParticleSystemOnRespawn;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Character|Respawn|ParticleSystem")
	UNiagaraSystem* ParticleSystemOnRevive;

	bool ExistsInWeakObjPtrCharacterArray(TArray<TWeakObjectPtr<AEXWCharacter>> CharacterArray);
	
	/*
	* Data
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "EXWorld|Character|Data")
	void OnCharacterDataLoaded();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Load")
	void OnCharacterLoadComplete();

	/**
	 * Transforms and Locations
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|General")
	void Replicated_SetActorLocationAndRotation(const FVector NewLocation = FVector::ZeroVector, const FRotator NewRotation = FRotator(ForceInit));

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|General")
	void Server_SetActorLocationAndRotation(const FVector NewLocation = FVector::ZeroVector, const FRotator NewRotation = FRotator(ForceInit));

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Character|General")
	void Multicast_SetActorLocationAndRotation(const FVector NewLocation = FVector::ZeroVector, const FRotator NewRotation = FRotator(ForceInit));

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|General")
	void Client_SetActorLocationAndRotation(const FVector NewLocation = FVector::ZeroVector, const FRotator NewRotation = FRotator(ForceInit));

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|General")
	FTransform GetSocketTransform(const FName SocketName = "spine_02");

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|General")
	FVector GetClosestGroundToCrosshair(const float Distance = 2000.f, const bool bDebug = false);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|General")
	FVector GetClosestGroundToCharacter(const float Distance = 2000.f, const bool bDebug = false);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|General")
	AEXWCharacter* GetTargetFromCrosshair(const float Distance = 800.f, const bool bDebug = false);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|General")
	AEXWCharacter* GetTargetFromCrosshairWithFaction(const float Distance = 800.f, const bool bDebug = false, const bool bTargetOtherFaction = true, const bool bTargetOwnerFaction = false);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|General")
	TArray<AEXWCharacter*> GetAimedCharacters(UPARAM(ref) FEXWTargetingParams &InTargetingParams);


	/** Traces from the cross-hair (middle of the screen to a certain range passed into the arguments). Does not replicate.
	 * @param OutHit - Is the output HitResult when the trace hits.
	 * @param Direction - Is the direction of the screen.
	 * @param CollisionChannel - Is the collision channel to be able to hit in the trace.
	 * @param Distance - Is the Distance of the trace to accept (Range).
	 * @param bDebug - Whether display the trace or not (for debug purpose).
	 * @return Whether it has hit or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|General")
	bool CrosshairTrace(FHitResult& OutHit, FVector& ScreenDirection, const TArray <TEnumAsByte<ECollisionChannel>> CollisionChannels, const float Distance = 2000.f, const bool bDebug = false);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|General")
	FVector GetProjectileDirection(FVector SpawnLocation);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|General")
	EEXWActionDirection GetCharacterDirection(const EEXWDirectionMode DirectionMode, float& OutDirectionValue);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|General")
	void RotateCharacterTowardsCameraDirection();
	/**
	 * Montages and Animations and Particles
	 */

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "EXWorld|Animation")
	void Replicated_PlayMontage(UAnimMontage* montage, float track);
	virtual void Replicated_PlayMontage_Implementation(UAnimMontage* montage, float track);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Animation")
	void Server_PlayMontage(UAnimMontage* montage, float track);

	/** Plays the montage on everyone besides the owning client */
	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Animation")
	void Multicast_PlayMontage(UAnimMontage* montage, float track);

	UFUNCTION(Client, Unreliable, BlueprintCallable, Category = "EXWorld|Animation")
	void Client_PlayMontage(UAnimMontage* montage, float track);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Animation")
	void Server_PlayMontageSection(UAnimMontage* montage, float track, FName Section);

	/** Plays the montage on everyone besides the owning client */
	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Animation")
	void Multicast_PlayMontageSection(UAnimMontage* montage, float track, FName Section);

	UFUNCTION(Client, Unreliable, BlueprintCallable, Category = "EXWorld|Animation")
	void Client_PlayMontageSection(UAnimMontage* montage, float track, FName Section);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Animation")
	void Server_StopMontage(UAnimMontage* montage);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Animation")
	void Multicast_StopMontage(UAnimMontage* montage);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Animation")
	UAnimMontage* GetCurrentActiveMontage();

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Particles")
	void Multicast_PlayParticles(UParticleSystem* Particles, FName BoneName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Particles")
	UParticleSystemComponent* SprintParticle;

	/**
	 * Faction
	 */

	UFUNCTION(Server, Reliable, Category = "EXWorld|Character|Faction")
	void Server_SetFaction(int32 NewFaction = 0);

	/** Set the faction of the character on the Server (No need to RPC on this one, it is already a custom setter) */
	UFUNCTION(BlueprintSetter, Category = "EXWorld|Character|Faction")
	void SetFaction(int32 NewFaction = 0);

	UFUNCTION(BlueprintGetter, Category = "EXWorld|Character|Faction")
	int32 GetFaction() {return Faction;};

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Faction")
	bool IsSameFaction(AEXWCharacter * OtherCharacter);

	UFUNCTION(Client, Reliable, Category = "EXWorld|Character|Faction")
	void Client_SetTargetFaction(AEXWCharacter* TargetCharacter, int32 NewFaction = 0);


	/**
	 * Attributes
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void SetAttributeCurrentValue(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Server_SetAttributeCurrentValue(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void SetAttributeMaxValue(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Server_SetAttributeMaxValue(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void GainAttribute(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Server_GainAttribute(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Replicated_GainAttribute(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void LoseAttribute(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Server_LoseAttribute(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Replicated_LoseAttribute(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Attribute")
	bool GetAttribute(const EEXWAttributeType AttributeType, FEXWAttribute &OutAttribute);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Attribute")
	bool GetAttributeCurrentValue(const EEXWAttributeType AttributeType, float &OutValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Attribute")
	bool GetAttributePercentage(const EEXWAttributeType AttributeType, float &OutValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Attribute")
	bool GetAttributeMaxValue(const EEXWAttributeType AttributeType, float& OutValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Attribute")
	bool GetMainAttribute(FEXWAttribute& OutAttribute);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Attribute")
	bool GetMainAttributeCurrentValue(float& OutValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Attribute")
	bool GetMainAttributePercentage(float& OutValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Attribute")
	bool HasEnoughAttribute(EEXWAttributeType AttributeType, float Value);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Attribute")
	void OnGainAttribute(const EEXWAttributeType AttributeType, const float Value);
	virtual void OnGainAttribute_Native(const EEXWAttributeType AttributeType, const float Value);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Attribute")
	FOnGainAttribute OnAttributeGained;

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Attribute")
	void OnLoseAttribute(const EEXWAttributeType AttributeType, const float Value);
	virtual void OnLoseAttribute_Native(const EEXWAttributeType AttributeType, const float Value);
	
	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Attribute")
	FOnLoseAttribute OnAttributeLost;

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Attribute")
	void OnUpdateAttribute(const FEXWAttribute& Attribute);
	virtual void OnUpdateAttribute_Native(const FEXWAttribute& Attribute);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void UpdateRegen(UPARAM(ref) FEXWAttribute &Attribute);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void AddRegen(const EEXWAttributeType AttributeType, const float Value = 1.f, const float TickingRate = 1.f);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void StopRegen(const EEXWAttributeType AttributeType);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void StopAllRegens();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void RemoveRegen(const EEXWAttributeType AttributeType);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void RemoveAllRegens();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Server_RemoveAllRegens();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Multicast_StopAllRegens();

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Multicast_RemoveAllRegens();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void UpdateAllRegens();

	UFUNCTION()
	void ApplyRegen(const FEXWAttribute Attribute);

	UFUNCTION()
	void UpdateAttributesFromStats();

	UFUNCTION()
	void UpdateAttributesFromItems();

	UFUNCTION()
	void CreateDefaultAttributes();

	/**
	 * Damage
	 */

	/** Apply damage to an Actor server side (replicated).*/
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Attribute")
	void Server_ApplyDamage(AActor* Target, const float Damage, TSubclassOf<UDamageType> DamageType);

	virtual float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintNativeEvent, Category = "EXWorld|Character|Attribute")
	float ModifyDamageTaken(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);

	/**
	 * Stats
	 */

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Stat")
	void Server_GainStat(EEXWStatType StatType, float Value);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Stat")
	void Server_LoseStat(EEXWStatType StatType, float Value);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Stat")
	void SetStatValue(EEXWStatType StatType, float Value);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Stat")
	void Server_SetStatValue(EEXWStatType StatType, float Value);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Stat")
	bool GetStat(const EEXWStatType StatType, FEXWStat& OutStat);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Stat")
	void OnUpdateStat(const FEXWStat& Stat);
	virtual void OnUpdateStat_Native(const FEXWStat& Stat);

	UFUNCTION()
	void UpdateStatsFromLevelModifier();

	UFUNCTION()
	void UpdateStatsFromItems();

	UFUNCTION()
	void CreateDefaultStats();

	/**
	 * Stat Level Points
	 */

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Stat")
	void Server_AddStatLevelPoint(EEXWStatType StatType, int32 ValueToAdd);

	/**
	 * Damage Reduction
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Damage reduction")
	void CreateDefaultDamageReductions();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Damage reduction")
	float GetDamageReductionValue(TSubclassOf<UDamageType> DamageType);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Damage reduction")
	void GainDamageReduction(TSubclassOf<UDamageType> DamageType, const float InValue);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Damage reduction")
	void Server_GainDamageReduction(TSubclassOf<UDamageType> DamageType, const float InValue);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Damage reduction")
	void LoseDamageReduction(TSubclassOf<UDamageType> DamageType, const float InValue);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Damage reduction")
	void Server_LoseDamageReduction(TSubclassOf<UDamageType> DamageType, const float InValue);

	/**
	 * Damage Reduction
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Damage Absorption")
	void CreateDefaultDamageAbsorptions();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Damage Absorption")
	float GetDamageAbsorptionValue(TSubclassOf<UDamageType> DamageType, float Damage);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Damage Absorption")
	void GainDamageAbsorption(TSubclassOf<UDamageType> DamageType, const float InValue);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Damage Absorption")
	void Server_GainDamageAbsorption(TSubclassOf<UDamageType> DamageType, const float InValue);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Damage Absorption")
	void LoseDamageAbsorption(TSubclassOf<UDamageType> DamageType, const float InValue);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Damage Absorption")
	void Server_LoseDamageAbsorption(TSubclassOf<UDamageType> DamageType, const float InValue);

	/**
	* Spawnable Ability
	*/

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Spawnable Ability")
	bool MakeSpawnableAbility(const FName RowName = "Spawnable_Ability_Row_Name");

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Spawnable Ability")
	bool CreateSpawnableAbilityParams(FEXWSpawnableAbilitySpawnParams& SpawnParams, const FName RowName =  "Spawnable_Ability_Row_Name");

	/**
	 * Constructs on the server the data needed to spawn the spawnable ability, don't use this unless you know what you're doing. 
	 * For making a spawn-able ability, use "MakeSpawnableAbility()" instead
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Spawnable Ability")
	void Server_ConstructSpawnableAbility(FEXWSpawnableAbilitySpawnParams SpawnParams);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Spawnable Ability")
	AEXWSpawnableAbility* SpawnSpawnableAbilityActor(UPARAM(ref) FEXWSpawnableAbilitySpawnParams& SpawnParams);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Spawnable Ability")
	void Server_SpawnAiCharacter(TSubclassOf<AEXWCharacter> CharacterClass, UBehaviorTree* BehaviorTree, float MinSpawnLocation, float MaxSpawnLocation, int32 Level, float RoamRadius);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Spawnable Ability")
	void SpawnAiCharacter(TSubclassOf<AEXWCharacter> CharacterClass, UBehaviorTree* BehaviorTree, float MinSpawnLocation, float MaxSpawnLocation, int32 Level, float RoamRadius);

	/**
	* Status Effect
	*/

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Status Effect")
	bool FindActiveStatusEffect(FName InID, FEXWStatusEffectData &OutStatusEffect);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Status Effect")
	void Server_ConstructStatusEffect(FName RowName, AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter);

	UFUNCTION(Category = "EXWorld|Character|Status Effect")
	AEXWStatusEffect* SpawnStatusEffectActor(FEXWStatusEffectData& StatusEffect);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|StatusEffect")
	void Server_AddStatusEffect(FEXWStatusEffectData StatusEffect);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|StatusEffect")
	void Client_AddStatusEffect(FEXWStatusEffectData StatusEffect);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|StatusEffect")
	void OnStatusEffectAdded(FEXWStatusEffectData StatusEffect);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Status Effect")
	void Server_RemoveActiveStatusEffect(FEXWStatusEffectData StatusEffect);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|StatusEffect")
	void Client_RemoveActiveStatusEffect(FEXWStatusEffectData StatusEffect);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|StatusEffect")
	void OnStatusEffectRemoved(FEXWStatusEffectData StatusEffect);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Status Effect")
	void RemoveAllActiveStatusEffects();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Status Effect")
	void Server_TickStatusEffect(FEXWStatusEffectData StatusEffect);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Status Effect")
	void Server_SetCustomTimeDilation(const float NewTimeDilation = 1.f);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Character|Status Effect")
	void Multicast_SetCustomTimeDilation(const float NewTimeDilation = 1.f);

	UFUNCTION()
	void OnRep_ActiveStatusEffects();

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|StatusEffect")
	FOnActiveStatusEffectsUpdated OnActiveStatusEffectsUpdated;

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|StatusEffect")
	FOnStatusEffectAdded StatusEffectAdded;

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|StatusEffect")
	FOnStatusEffectRemoved StatusEffectRemoved;

	/**
	 * Level
	 */

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Level")
	void Server_LevelUp();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Level")
	void Server_SetLevel(const int32 NewLevel = 1);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Level")
	void OnCharacterLevelUp(const int32 NewLevel);
	void OnCharacterLevelUp_Native(const int32 NewLevel);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Level")
	void OnCharacterChangeLevel(const int32 NewLevel);
	void OnCharacterChangeLevel_Native(const int32 NewLevel);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Level")
	void Server_SetExperience(const int32 NewExperience);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Level")
	void GainExperience(const int32 ExperienceToGain);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Level")
	void OnGainExperience(const int32 GainedExperience);
	void OnGainExperience_Native(const int32 GainedExperience);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Level")
	int GetTotalRequiredExperience();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Level")
	float GetExperiencePercentage();

	UFUNCTION(BlueprintCallable,Category = "EXWorld|Character|Level")
	void UpdateGearItemLevel();

	/**
	 * States
	 */

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure, Category = "EXWorld|Character|State")
	bool CanAddState(const EEXWState StateToAdd);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|State")
	void AddState(const EEXWState StateToAdd);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|State")
	void Server_AddState(const EEXWState StateToAdd);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|State")
	void OnAddState(const EEXWState &AddedState);
	void OnAddState_Native(const EEXWState& AddedState);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|State")
	FOnStateAdded OnStateAdded;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|State")
	void RemoveState(const EEXWState StateToRemove);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|State")
	void Server_RemoveState(const EEXWState StateToRemove);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|State")
	void OnRemoveState(const EEXWState& RemovedState);
	void OnRemoveState_Native(const EEXWState& RemovedState);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|State")
	FOnStateRemoved OnStateRemoved;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|State")
	void ClearStates();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|State")
	void Server_ClearStates();

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|State")
	FOnStatesCleared OnStatesCleared;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|State")
	bool IsValidState(const EEXWState InState);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|State")
	bool OneStateIsValid(const TArray<EEXWState> InStates);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|State")
	bool AllStatesAreValid(const TArray<EEXWState> InStates);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|State")
	bool IsDead();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|State")
	bool IsCrowdControlled();

	/**
	 * States Overriders
	 */

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure, Category = "EXWorld|Character|State")
	bool CanAddStateOverrider(const EEXWStateOverrider StateOverriderToAdd);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|StateOverriders")
	void AddStateOverrider(const EEXWStateOverrider StateOverriderToAdd);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|StateOverriders")
	void Server_AddStateOverrider(const EEXWStateOverrider StateOverriderToAdd);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|StateOverriders")
	void OnAddStateOverrider(const EEXWStateOverrider& AddedStateOverrider);
	void OnAddStateOverrider_Native(const EEXWStateOverrider& AddedStateOverrider);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|State")
	void RemoveStateOverrider(const EEXWStateOverrider StateOverriderToRemove);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|State")
	void Server_RemoveStateOverrider(const EEXWStateOverrider StateOverriderToRemove);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|State")
	void OnRemoveStateOverrider(const EEXWStateOverrider& RemovedStateOverrider);
	void OnRemoveStateOverrider_Native(const EEXWStateOverrider& RemovedStateOverrider);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|State")
	void ClearStateOverriders();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|State")
	void Server_ClearStateOverriders();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|State|Combat")
	void SetInCombat();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|State|Combat")
	bool CheckHostilesNearby();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|State|Combat")
	void UpdateIsInCombat();

	/**
	 * Cooldown
	 */

	/**
	 * Starts a given Cooldown in the parameter by adding it to the stack. This Cooldown is accessible by its ID
	 * @param Cooldown The Cooldown to start (constructing it is possible via "Make Cooldown" Blueprints)
	 */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Cooldown")
	bool StartCooldown(UPARAM(ref) FEXWCooldown& Cooldown);

	/**
	 * Ends a given Cooldown in the parameter and removing it from the Cooldown stack.
	 * Can be used in order to clear a Cooldown (The action of this Cooldown will be available for usage again).
	 * @param CooldownID The ID of the Cooldown to remove
	 */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Cooldown")
	void EndCooldown(const FName CooldownID);

	/**
	 * Event called when the cooldown ends
	 * @param Cooldown the Cooldown struct that has ended
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Cooldown", meta = (Keywords = "Ready"))
	void OnEndCooldown(const FEXWCooldown& Cooldown);
	void OnEndCooldown_Native(const FEXWCooldown& Cooldown);

	/**
	 * Get a Cooldown from a given ID
	 * @param InID ID of the Cooldown
	 * @param OutCooldown Resulting Cooldown
	 * @return Returns if the Cooldown exists in the Cooldown stack
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Cooldown")
	bool GetCooldown(const FName InID, FEXWCooldown& OutCooldown);

	/**
	 * Returns if the cooldown is ready.
	 * The cooldown is ready means that the cooldown isn't available in the Cooldown stack.
	 * @Param InID The ID of the Cooldown to look for
	 * @return Returns if the cooldown is ready or not
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Cooldown")
	bool IsCooldownReady(const FName InID);

	/**
	 * Gets the Cooldown timers with a given ID (the elapsed and remaining time of the Cooldown)
	 * @param InCooldownID The ID of the Cooldown to look for its Data
	 * @param Elapsed The elapsed time of the Cooldown
	 * @param Remaining The remaining time of the Cooldown
	 * @return Returns if the Cooldown has been found
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Cooldown")
	bool GetCooldownTimer(const FName InCooldownID, float& Elapsed, float& Remaining);

	/**
	 * Event called when an Action is executed and its Cooldown is still in the Cooldown stack.
	 * If this event is called, it means that the actions is still unavailable and wasn't executed.
	 * @param CooldownID The ID of the Cooldown that has been found
	 * @param Elapsed The time elapsed since the Cooldown has been existing in the stack;:
	 * @param Remaining the remaining time until this Cooldown will end
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Cooldown")
	void OnNotifyCooldown(const FName& CooldownID, const float& Elapsed, const float& Remaining);
	void OnNotifyCooldown_Native(const FName& CooldownID, const float& Elapsed, const float& Remaining);

	void AddCooldownToStack(UPARAM(ref) FEXWCooldown& Cooldown);

	UFUNCTION(Server, Reliable)
	void Server_AddCooldownToStack(FEXWCooldown Cooldown);

	void RemoveCooldownFromStack(const FName CooldownID);

	UFUNCTION(Server, Reliable)
	void Server_RemoveCooldownFromStack(const FName CooldownID);

	/**
	 * Action
	*/

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Action")
	void Server_SetActiveAbilities(const TArray<FEXWAction>& Actions);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Action")
	void SetActiveAbilities(const TArray<FEXWAction>& Actions);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Action")
	void OnSetActiveAbilitiesEvent(const TArray<FEXWAction>& Actions);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Action")
	FOnAvailableActionsSet OnAvailableActionsSet;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Action")
	void Server_SetIFrameActions(const TArray<FEXWAction>& Actions);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Action")
	void SetIFrameActions(const TArray<FEXWAction>& Actions);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Action")
	void OnSetIFrameActionsEvent(const TArray<FEXWAction>& Actions);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Action")
	FOnIFrameActionsSet OnIFrameActionsSet;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Action")
	void Server_AddAbility(FEXWAction Action);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Action")
	void AddAbility(FEXWAction Action);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Action")
	void OnAddAbilityEvent(FEXWAction Action);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Action")
	FOnAbilityAdded OnAbilityAdded;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Action")
	void Server_RemoveAbility(FEXWAction Action);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Action")
	void RemoveAbility(FEXWAction Action);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Action")
	void OnRemoveAbilityEvent(FEXWAction Action);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Action")
	FOnAbilityRemoved OnAbilityRemoved;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Action")
	EEXWActionExecutionResult ExecuteActionFull(const FName RowName = "Row_Name_Here");

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Action")
	EEXWActionExecutionResult ExecuteActionFullByAction(FEXWAction Action);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Action")
	void ExecuteActionFullByIndex(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Action")
	void ExecuteIFrameActionFullByIndex(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Action")
	EEXWActionExecutionResult ExecuteActionByDT(const FName RowName = "Row_Name_Here");

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Action")
	EEXWActionExecutionResult ExecuteAction(const FEXWAction& InAction);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Action")
	EEXWActionExecutionResult CanExecuteAction(const FEXWAction& InAction);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Action")
	TArray<FEXWMontageData> GetValidMontagesDataForAction(const FEXWAction& InAction);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Action")
	void CleanUpActionExecution(const bool bStopTargeting = false);

	/**
	 * Reaction
	 */

	/* Sends a reaction to a target character, make sure to use "MakeReactionSendingParams()" before "SendReaction()" in order to set up the proper values for sending. */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Reaction")
	void SendReaction(UPARAM(ref) FEXWReactionSendingParams& ReactionSendingParams);
	 
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Reaction")
	void Server_SendReaction(const FEXWReactionSendingParams& ReactionSendingParams);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Character|Reaction")
	void Multicast_SendReaction(const FEXWReactionSendingParams& ReactionSendingParams);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Reaction")
	void OnReceiveReaction(const FEXWReactionSendingParams& ReactionSendingParams);
	virtual void OnReceiveReaction_Native(const FEXWReactionSendingParams& ReactionSendingParams);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Reaction")
	void ExecuteReaction(const FEXWReactionSendingParams& ReactionSendingParams);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Reaction")
	TArray<FEXWReactionMontage> GetValidMontagesDataForReaction(const FEXWReaction& InReaction, AEXWCharacter* SourceCharacter);
	
	/**
	 * Indicator
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Indicator")
	bool SpawnAbilityIndicator(TSubclassOf<AEXWSpawnableAbilityIndicator> IndicatorClass = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Indicator")
	bool DestroyAbilityIndicator();

	/**
	 * Effect Application
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Effects")
	void Replicated_ApplyAttributeMultiEffects(AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect>& AttributeEffects);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Effects")
	void Server_ApplyAttributeMultiEffects(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect>& AttributeEffects);

	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "EXWorld|Character|Effects")
	void Server_ApplyAttributeNotify(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect AttributeEffect);

	UFUNCTION(Client, Unreliable, BlueprintCallable, Category = "EXWorld|Character|Effects")
	void Client_ApplyAttributeNotify(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect AttributeEffect);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Effects")
	void OnClientApplyAttribute(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect AttributeEffects);
	virtual void OnClientApplyAttribute_Native(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect AttributeEffects);

	/**
	 * Targeting system
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Targeting")
	FEXWTargetingParams DefaultTargetingParams = FEXWTargetingParams(3657.6f, 100.0f, EEXWTargetingType::TT_Crosshair, EEXWTargetFaction::TF_ALLFactions, 0, 0, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Targeting")
	float DefaultLockOnTargetingDistance = 3657.6f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Targeting")
	bool bCanUseTargeting = false;

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void SetCanUseTargeting(bool NewTargeting);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Targeting")
	TArray<AEXWCharacter*> GetAllTargets();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void StartTargeting(const FEXWTargetingParams &NewTargetingParams);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void StartDefaultTargeting();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void StopTargeting();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void ProcessTargeting();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void SetPrimaryTarget(AEXWCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void SetTargets(TArray<AEXWCharacter*> NewTargetCharacters);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	bool AddTarget(AEXWCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	bool RemoveTarget(AEXWCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void ClearTargets();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Action")
	void Server_UpdateLastAffectedPlayer(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Targeting")
	void OnStartTargeting(const FEXWTargetingParams &NewTargetingParams);
	virtual void OnStartTargeting_Native(const FEXWTargetingParams &NewTargetingParams);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Targeting")
	void OnStopTargeting(const FEXWTargetingParams &StoppedTargetingParams);
	virtual void OnStopTargeting_Native(const FEXWTargetingParams& StoppedTargetingParams);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Targeting")
	void OnSetPrimaryTarget(AEXWCharacter* TargetCharacter);
	virtual void OnSetPrimaryTarget_Native(AEXWCharacter* TargetCharacter);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Targeting")
	void OnSetTargets(const TArray<AEXWCharacter*>& NewTargetCharacters);
	virtual void OnSetTargets_Native(const TArray<AEXWCharacter*>& NewTargetCharacters);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Targeting")
	void OnAddTarget(AEXWCharacter* TargetCharacter);
	virtual void OnAddTarget_Native(AEXWCharacter* TargetCharacter);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Targeting")
	void OnRemoveTarget(AEXWCharacter* TargetCharacter);
	virtual void OnRemoveTarget_Native(AEXWCharacter* TargetCharacter);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Targeting")
	void OnClearTargets(const TArray<AEXWCharacter*>& ClearedTargets);
	virtual void OnClearTargets_Native(const TArray<AEXWCharacter*>& ClearedTargets);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Targeting")
	void OnProcessTargeting(const FEXWTargetingParams& CurrentTargetingParams, const TArray<AEXWCharacter*>& FoundTargets);
	virtual void OnProcessTargeting_Native(const FEXWTargetingParams& CurrentTargetingParams, const TArray<AEXWCharacter*>& FoundTargets);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void HighlightCharacter(AEXWCharacter* TargetCharacter, FName ParamName = "HighlightColor", FLinearColor Color = FLinearColor::Red);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void UnhighlightCharacter(AEXWCharacter* TargetCharacter, FName ParamName = "HighlightColor");

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void HighlightAllTargets(FName ParamName = "HighlightColor", FLinearColor Color = FLinearColor::Red);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Targeting")
	void UnhighlightAllTargets(FName ParamName = "HighlightColor");

	/**
	 * Death events
	 */

	// This event is called on the server only
	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Death")
	void OnDeathEvent();
	virtual void OnDeathEvent_Native();

	// The replication of the OnDeathEvent
	UFUNCTION(NetMulticast, Reliable, Category = "EXWorld|Character|Death")
	void Multicast_DeathEvent();

	// This event is called on all clients
	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Death")
	void OnDeathEventMulticast();
	virtual void OnDeathEventMulticast_Native();

	// This event is called on owner client
	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Death")
	void OnDeathEventClient();
	virtual void OnDeathEventClient_Native();

	/**
	 * Sound and VFX
	 */

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|ParticleSystems")
	void Server_SpawnEmitterAtLocation(UParticleSystem* EmitterTemplate, FVector SpawnLocation, FRotator SpawnRotation);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Character|ParticleSystems")
	void Multicast_SpawnEmitterAtLocation(UParticleSystem* EmitterTemplate, FVector SpawnLocation, FRotator SpawnRotation);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|ParticleSystems")
	void Server_SpawnEmitterAttached(UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Character|ParticleSystems")
	void Multicast_SpawnEmitterAttached(UParticleSystem* EmitterTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Character|ParticleSystems")
	void Multicast_SpawnNiagraAttached(UNiagaraSystem* NiagraTemplate, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, EAttachLocation::Type LocationType);
	
	/**
	 * Inventory
	 * TODO : Add an anti-cheating argument in the future that checks whether or not you can add the item on the server OR on the client side
	 * As for now, everything is being processed on the server.
	 */

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_SetInventory(const FEXWInventory NewInventory);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_SetInventoryShop(const FEXWInventory NewInventoryShop);

	/**
	 * Adds an item to the inventory. This function does not call "OnInventoryUpdate"
	 * @param ItemID : The itemID to add to the inventory (has to be similar to the one in the DataTable)
	 * @param Count : The number of items to add
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_AddItemsToInventory(const FName ItemID, const int32 Count = 1);

	/**
	 * This function will try adding items to the inventory regardless to the fact that there is no enough space for the count passed into params.
	 * It will add as much as possible and return the rest that couldn't be added
	 */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Inventory")
	bool TryAddingItemsToInventory(const FName ItemID, const int32 Count, int32& Rest);

	/**
	 * Adds an item to the inventory shop
	 * @param ItemID : The itemID to add to the inventory shop (has to be similar to the one in the DataTable)
	 * @param Count : The number of items to add
	 */
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_AddItemsToInventoryShop(const FName ItemID, const int32 Count = 1);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_RemoveItemsFromInventory(const FName ItemID, const int32 Count = 1);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_RemoveItemCountFromInventoryByIndex(const int32 ItemCountToRemove, const int32 SlotIndex);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_RemoveItemSlotFromInventory(const int32 SlotIndex);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_RemoveItemsFromInventoryShop(const FName ItemID, const int32 Count = 1);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_MoveInventorySlots(const int32 SourceIndex, const int32 TargetIndex);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_SwapInventoryAndShopItems(const int32 InventoryIndex, const int32 InventoryShopIndex);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_ReturnItemsToInventoryFromShop();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_MoveInventoryShopSlots(const int32 SourceIndex, const int32 TargetIndex);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_BuyItemsFromShop(const FName ItemID, const int32 Count, AEXWCharacter* ShopOwner);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_BuyItemSlotFromShop(const FEXWInventorySlot ItemSlot, const int32 Count, AEXWCharacter* ShopOwner);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_DropItems(const int32 InventorySlotIndex);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_SetShopItemSlotPrice(const FEXWInventorySlot ItemSlot, const int32 PriceGold, const int32 PriceSilver);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Client_CallOnInventoryUpdate(const FEXWInventory &NewInventory);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Inventory")
	void OnInventoryUpdate();
	virtual void OnInventoryUpdate_Native();

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Client_CallOnInventoryShopUpdate(const FEXWInventory& NewInventoryShop);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Inventory")
	void OnInventoryShopUpdate();
	virtual void OnInventoryShopUpdate_Native();

	UFUNCTION()
	void SpawnItem(const FName ItemID, const int32 Count = 1, const bool bForceLootable = false);

	UFUNCTION()
	void DropOnDeathItems();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Inventory")
	bool Replicated_UseItem(const int32 InventorySlotIndex);
	
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_SpawnPlaceable(TSubclassOf<class AEXWPlaceable> PlaceableClass, FVector Location);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Inventory")
	bool HasItem(const FName ItemID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Inventory")
	bool HasItemByType(const EEXWEquipmentType EquipmentType);

	UFUNCTION(Client, Reliable)
	void Client_CallOnAddItemsToInventory(const FName ItemID, const int32 ItemCount);

	virtual void OnAddItemsToInventory_Native(const FName ItemID, const int32 ItemCount);

	UFUNCTION(Client, Reliable)
	void Client_CallOnRemoveItemsFromInventory(const FName ItemID, const int32 ItemCount);

	virtual void OnRemoveItemsFromInventory_Native(const FName ItemID, const int32 ItemCount);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Inventory")
	EEXWItemUseResult CanUseItem(const FEXWItemData& InItem);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_GainSilver(int32 Quantity);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_GainGold(int32 Quantity);

	/**
	 * Shop
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Shop")
	bool CanOpenShop();

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Shop")
	void Server_StartShop();

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Shop")
	void Client_StartShop();

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Shop")
	void OnShopStart();

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Shop")
	FOnShopStarted OnShopStarted;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Shop")
	void Server_StopShop();

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Shop")
	void Client_StopShop();

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Shop")
	void OnShopStop();
	
	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Shop")
	FOnShopStopped OnShopStopped;

	/**
	 * Equipment
	 */

	UFUNCTION(Server, BlueprintCallable, Reliable, Category = "EXWorld|Character|Equipment")
	void Server_SwapInventoryAndEquipmentItems(const int32 InventorySlotIndex, const int32 EquipmentSlotIndex);

	UFUNCTION(Server, BlueprintCallable, Reliable, Category = "EXWorld|Character|Equipment|Cosmetic")
	void Server_SwapInventoryAndCosmeticItems(const int32 InventorySlotIndex, const int32 CosmeticSlotIndex);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Client_CallOnInventoryEquipmentUpdate(const FEXWInventory& NewInventoryEquipment);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory|Cosmetic")
	void Client_CallOnInventoryCosmeticEquipmentUpdate(const FEXWInventory& NewInventoryEquipment);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Inventory")
	void OnInventoryEquipmentUpdate();
	virtual void OnInventoryEquipmentUpdate_Native();

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Inventory|Cosmetic")
	void OnInventoryCosmeticEquipmentUpdate();
	virtual void OnInventoryCosmeticEquipmentUpdate_Native();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void CreateDefaultInventoryEquipment();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void CreateDefaultInventoryCosmeticEquipment();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Inventory")
	bool IsEquippedByID(const FName ItemID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Inventory")
	bool IsEquippedByType(const EEXWEquipmentType EquipmentType);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Gathering")
	bool Gather_Toggle(bool isStart, FName ItemID);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Inventory")
	bool EquipItem(const int32 InventoryItemIndex);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Inventory")
	bool UnequipItem(const int32 InventoryEquipmentItemIndex,bool CosmeticItem);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Inventory")
	void OnEquipItem(const FName& ItemID);
	virtual void OnEquipItem_Native(const FName& ItemID);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Delegates")
	FOnEquipItem OnItemEquipped;

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Inventory")
	void OnUnequipItem(const FName& ItemID);
	virtual void OnUnequipItem_Native(const FName& ItemID);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Delegates")
	FOnUnEquipItem OnItemUnEquipped;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Inventory")
	bool bHasItemSetEquipped = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Inventory")
	FEXWItemSet CurrentItemSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Inventory")
	bool bCanPlayParticles = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Character|Inventory")
	float ItemSetParticlesDelay = 3.f;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_HandleItemSetEquipment(FName ItemSetID);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Inventory")
	void Server_HandleItemSetUnEquipment(FName ItemSetID);

	/**
	 * Interactions
	 */

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Server_Interact(AActor* TargetActor, EEXWInteractionType InteractionType);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Client_Interact(AActor* TargetActor, EEXWInteractionType InteractionType);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Multicast_CreateShopWidget(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Multicast_CreateNPCShopWidget(AEXWCharacter* SourceCharacter, AEXWCharacter* ShopOwner, FName ShopID);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Multicast_CreateTradeWidget(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Multicast_CreateDialogueWidget(AEXWCharacter* SourceCharacter, FName DialogueID);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Multicast_CreateCraftWidget(AEXWCharacter* SourceCharacter, class AEXWPlaceableCraftStation* CraftStation, EEXWCraftCategory Category);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Interaction", meta = (DisplayName = "On Receive Interaction"))
	void OnReceiveInteraction_ImpEvent(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType);
	virtual void  OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Interaction", meta = (DisplayName = "On Receive Click"))
	void OnReceiveClick_ImpEvent(AEXWCharacter* SourceCharacter);
	virtual void OnReceiveClick(AEXWCharacter* SourceCharacter) override;

	void SetInteractionWidgetVisibility(const bool bNewVisibility = true) override;

	virtual UWidgetComponent* GetInteractionWidgetComponent() override;
	 
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Server_SetAvailableInteractions(const TArray<EEXWInteractionType> &NewAvailableInteractionTypes);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Multicast_SetAvailableInteractions(const TArray<EEXWInteractionType> &NewAvailableInteractionTypes);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Server_AddAvailableInteractions(const EEXWInteractionType InAvailableInteractionType);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Multicast_AddAvailableInteractions(const EEXWInteractionType InAvailableInteractionType);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Server_RemoveAvailableInteractions(const EEXWInteractionType InAvailableInteractionType);

	UFUNCTION(NetMulticast, Reliable, BlueprintCallable, Category = "EXWorld|Interaction")
	void Multicast_RemoveAvailableInteractions(const EEXWInteractionType InAvailableInteractionType);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Interaction|Duel")
	void Server_RequestDuel(AEXWCharacter* TargetToDuel);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Interaction|Duel")
	void Client_RequestDuel(AEXWCharacter* TargetToDuel);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Interaction|Duel")
	void Server_RespondDuel(AEXWCharacter* TargetToDuel, bool IsAccepted);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Interaction|Duel")
	void Server_StartDuel(AEXWCharacter* OtherCharacter);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Interaction|Duel")
	void Client_StartDuelTimer(AEXWCharacter* OtherCharacter);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Interaction|Duel")
	void Client_StartDuel(AEXWCharacter* OtherCharacter);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Interaction|Duel")
	void Server_EndDuel(AEXWCharacter* OtherCharacter);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Interaction")
	void OnEndDuel(AEXWCharacter* OtherCharacter, bool bHasWon);
	virtual void OnEndDuel_Native(AEXWCharacter* OtherCharacter, bool bHasWon);

	/**
	* Crafting
	*/
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Crafting")
	bool Replicated_ExecuteCraft(const FName CraftID = "None");

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Crafting")
	void OnCraftComplete(FName CraftID);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Crafting")
	FOnCraftingComplete OnCraftingComplete;

	/**
	 * Life Skills
	 */

	UFUNCTION()
	void CreateDefaultLifeSkills();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|LifeSkill")
	bool GetLifeSkill(const EEXWLifeSkillType LifeSkillType, FEXWLifeSkill& OutLifeSkill);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|LifeSkill")
	void LevelUpLifeSkill(const EEXWLifeSkillType LifeSkillType);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|LifeSkill")
	void Server_SetLifeSkillLevel(const EEXWLifeSkillType LifeSkillType, const int32 NewLevel);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|LifeSkill")
	void GainLifeSkillExperience(const EEXWLifeSkillType LifeSkillType, const int32 ExperienceValue);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|LifeSkill")
	void Server_SetLifeSkillExperience(const EEXWLifeSkillType LifeSkillType, const int32 ExperienceValue);

	UFUNCTION()
	void OnRep_LifeSkills();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|LifeSkill")
	void OnUpdateLifeSkills();
	virtual void OnUpdateLifeSkills_Native();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|LifeSkills")
	int32 GetExperienceLifeSkillPerLevel(const EEXWLifeSkillType InLifeSkillType, const int32 InLevel);

	/**
	 * Meshes/Materials
	 */
	
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Mesh")
	void Server_SetSkeletalMesh(USkeletalMeshComponent* SkeletalMeshComponent, USkeletalMesh* NewSkeletalMesh);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Character|Mesh")
	void Multicast_SetSkeletalMesh(USkeletalMeshComponent* SkeletalMeshComponent, USkeletalMesh* NewSkeletalMesh);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Mesh")
	void SetAllMeshVisibility(bool bHide);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Material")
	TArray<UEXWSkeletalMeshComponent*> GetAllSkeletalMeshes();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Material")
	void SetMaterialOnAllMeshes(UMaterialInterface *NewMaterial);

	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "EXWorld|Material")
	void Server_SetMaterialOnAllMeshes(UMaterialInterface* NewMaterial);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Material")
	void Multicast_SetMaterialOnAllMeshes(UMaterialInterface* NewMaterial);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Material")
	void SetMaterialOnAllMeshesForDuration(UMaterialInterface* NewMaterial, const float Duration = 1.f);

	/**
	 * Screen Message
	 */

	UFUNCTION(Client, Unreliable, BlueprintCallable, Category = "EXWorld|Character|ScreenMessage")
	void Client_DisplayScreenMessage(const EEXWScreenMessageType ScreenMessageType);

	UFUNCTION(BlueprintCallable, Category = "EWorld|Character|ScreenMessage")
	void DisplayScreenMessage(const EEXWScreenMessageType ScreenMessageType);

	UFUNCTION(Client, Unreliable)
	void Client_CallOnRequestNotification(const FText& NotificationText);

	UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Notification")
	void OnRequestNotification(const FText &NotificationText);

	/**
	* Gathering
	*/

	UFUNCTION(Client, reliable, BlueprintCallable, Category = "EXWorld|Character|Gathering")
	void Client_Gathering(EEXWLifeSkillType Type,float Duration);

	/**
	 * GhostTrail
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Material")
	void ActivateGhostTrail(FEXWGhostTrailParams NewGhostTrailParams);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Material")
	void ProcessGhostTrail();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Material")
	void DeactivateGhostTrail();

	/**
	 * Ability Learning
	 */
	 UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 void Server_LearnAbility(FEXWAction Ability, bool bIsFromItem = false);

	 UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 void RequestLearnAbility(FEXWAction Ability);

	 UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 void Server_LearnAbilityFromItem(FEXWItemData Item);

	 UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 void Server_LevelAbility(FEXWAction Ability, bool bIsFromItem = false);

	 UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 void RequestLevelAbility(FEXWAction Ability);

	 UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 void Server_LevelAbilityAttribute(FEXWAction Ability, EEXWActionAttribute Attribute);

	 UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 void RequestLevelAbilityAttribute(FEXWAction Ability, EEXWActionAttribute Attribute);

	 UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 FEXWActionAttributeLevel GetAttributeData(FEXWAction Ability, EEXWActionAttribute Attribute);

	 UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 bool CanLearnAbility(FEXWItemData Item);

	 UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Abilities")
	 virtual void Client_AbilityLearned(FEXWAction Ability);

	 UFUNCTION(BlueprintImplementableEvent, Category = "EXWorld|Character|Abilities")
	 void OnAbilityLearned(FEXWAction Ability);

	/**
	 * AnimationBP data
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Animation")
	void UpdateAnimBP();

	/**
	 * Mesh data 
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateWeaponAttachmentSockets();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	bool UpdateEquipmentMesh(USkeletalMeshComponent* SkeletalMeshComponent, EEXWSlotType CosmeticSlot, EEXWSlotType EquipmentSlot);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateWeapons();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateHead(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateHair();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateHairColor(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateArms(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateBody(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateTorso(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateEyes(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateEyeColor(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateFace(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateLegs(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateFeet(FName id);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh")
	void UpdateSkin(FName id);

	 /**
	  * Mesh onRep Functions
	  */

	UFUNCTION()
	void OnRep_Head();

	UFUNCTION()
	void OnRep_Hair();

	UFUNCTION()
	void OnRep_HairColor();

	UFUNCTION()
	void OnRep_ArmsMesh();

	UFUNCTION()
	void OnRep_Body();

	UFUNCTION()
	void OnRep_TorsoMesh();

	UFUNCTION()
	void OnRep_Eyes();

	UFUNCTION()
	void OnRep_EyeColor();

	UFUNCTION()
	void OnRep_Face();

	UFUNCTION()
	void OnRep_Legs();

	UFUNCTION()
	void OnRep_Feet();

	UFUNCTION()
	void OnRep_Skin();

	UFUNCTION()
	void OnRep_RightHandWeapon();

	UFUNCTION()
	void OnRep_LeftHandWeapon();

	UFUNCTION()
	void OnRep_RightHandWeaponOffset();

	UFUNCTION()
	void OnRep_LeftHandWeaponOffset();

	/**
	 * Temporary values (Automatically Managed)
	 */

	UPROPERTY()
	TArray<AEXWCharacter*> TargetCharacters; // Should be TWeakObjPtr

	UPROPERTY(Replicated)
	TArray<FEXWCooldown> CooldownStack;

	UPROPERTY(Replicated)
	uint8 bIsDueling : 1;

	UPROPERTY(Replicated)
	uint8 bIsTrading : 1;

	UPROPERTY(Replicated, BlueprintReadWrite)
	AEXWCharacter* DuelingCharacter = nullptr;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Gatherable")
	FTimerHandle DuelTimerHandle;

	UPROPERTY(BlueprintReadOnly, Category = "EXWorld|Timers")
	FTimerHandle InvulnerabilityTimerHandle;

	int32 DuelCountdown = 3;

	UPROPERTY(Replicated, BlueprintReadWrite)
	AEXWCharacter* LastCharacterAffectedBy = nullptr; // Should be TWeakObjPtr

	UPROPERTY(Replicated, BlueprintReadWrite)
	AEXWCharacter* LastCharacterAffected = nullptr; // Should be TWeakObjPtr

	UPROPERTY()
	FEXWGhostTrailParams GhostTrailParams;

	UPROPERTY()
	uint8 bIsGhostTrailActive : 1;

	// This is automatically handled by "ExecuteAction()" in order to edit it, please refer to there
	UPROPERTY()
	int32 ComboCounter;

	UPROPERTY(BlueprintReadOnly)
	uint8 bIsTargeting : 1;
	
	UPROPERTY(BlueprintReadOnly)
	FEXWTargetingParams TargetingParams;

	UPROPERTY()
	FEXWAction ActionToExecute;

	UPROPERTY()
	TWeakObjectPtr<AEXWSpawnableAbilityIndicator> ActiveAbilityIndicator;


	/**
	 * Timer handles
	 */

	FTimerHandle TargetingTimerHandle;

	FTimerHandle MaterialTimerHandle;

	FTimerHandle InCombatTimerHandle;


	/**
	 * Party System
	 */

	UPROPERTY(Replicated, BlueprintGetter = GetHasPartyInvite, BlueprintSetter = SetHasPartyInvite, EditAnywhere, Category = "EXWorld|Character|Party")
	bool bHasPartyInvite = false;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Controller|Party")
	void RequestCreateParty(const FName& PartyID, const FText& PartyName, const TArray<AEXWCharacter*>& PartyMembers);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Controller|Party")
	void RequestInviteToParty(FEXWParty Party, const FText& CharacterName);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Controller|Party")
	void RequestInviteCharacterToParty(FEXWParty Party, AEXWCharacter* Character);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Controller|Party")
	void RequestJoinParty(FEXWParty Party);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Controller|Party")
	void RequestRemoveParty(FEXWParty Party);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Controller|Party")
	void RequestPromoteMember(FEXWParty Party, AEXWCharacter* CharacterToPromote);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Controller|Party")
	void RequestKickMember(FEXWParty Party, AEXWCharacter* CharacterToKick);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Controller|Party")
	void RequestLeaveParty(FEXWParty Party);

	UFUNCTION(Server, Reliable, Category = "EXWorld|Character|Party")
	void Server_SetHasPartyInvite(bool NewValue = false);

	UFUNCTION(BlueprintSetter, Category = "EXWorld|Character|Party")
	void SetHasPartyInvite(bool NewValue = false);

	UFUNCTION(BlueprintGetter, Category = "EXWorld|Character|Party")
	bool GetHasPartyInvite() { return bHasPartyInvite; };
	
	
	/**
	 * Delegates
	 */

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Kill")
	void Client_OnCharacterKill(AEXWCharacter* Victim);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Kill")
	FOnCharacterKill OnCharacterKill;

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Death")
	void Client_OnCharacterDeath(AEXWCharacter* Killer);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Death")
	FOnCharacterDeath OnCharacterDeath;
	
	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Character|Gathering")
	void Client_OnCharacterGatherComplete(FName ItemID, int32 ItemCount);

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Load")
	FOnCharacterLoaded OnCharacterLoaded;

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Respawn")
	FOnCharacterRespawn OnCharacterRespawn;
	
	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Character|Gathering")
	FOnCharacterGatherComplete OnCharacterGatherComplete;

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Interaction")
	FOnReceiveInteraction OnReceiveInteractionDelegate;

	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Interaction")
	FOnInteract OnInteract;
	
	UPROPERTY(BlueprintAssignable, Category = "EXWorld|Mesh")
	FOnMeshUpdated OnMeshUpdated;
	
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Delegates")
	void Server_HandleOnItemEquipped(FName ItemID);
	
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "EXWorld|Delegates")
	void Server_HandleOnItemUnEquipped(FName ItemID);

	UFUNCTION(Client, Reliable, BlueprintCallable, Category = "EXWorld|Delegates")
	void Client_OnCraftingComplete(FName CraftID);
};