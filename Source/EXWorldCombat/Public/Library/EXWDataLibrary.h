// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/PlayerStart.h"
#include "Library/EXWDataStruct.h"
#include "Library/EXWDataEnum.h"
#include "Library/EXWCharacterDataStruct.h"
#include "Library/Inventory/EXWInventoryStruct.h"
#include "EXWDataLibrary.generated.h"

class AEXWCharacter;
class UEXWSingleton;
class AEXWRespawnPoint;
class UWidgetComponent;
class UDataTable;
class UEXWSharedWidget;
class UEXWFloatingWidget;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWDataLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:


	/**
	 * General 
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|General", meta = (CompactNodeTitle = "Valid Get", ExpandEnumAsExecs = Result))
	static void GetValidName(TArray<FName> Array, const int32 Index, FName& ResultItem, EEXWValidityBranch &Result);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General")
	static EEXWActionDirection ConvertFloatToDirection(const float InValue);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General")
	static EEXWRelativePosition GetRelativePosition(AActor* MainActor, AActor* TargetActor, float& OutOrientationValue);

	static TArray<AEXWCharacter*> ConvertToCharacterArray(TArray<TWeakObjectPtr<AEXWCharacter>> CharacteWeakObjPtrrArray);

	static TArray<TWeakObjectPtr<AEXWCharacter>> ConvertToWeakObjPtrCharacterArray(TArray<AEXWCharacter*> CharacterArray);

	static bool ExistsInWeakObjPtrCharacterArray(TArray<TWeakObjectPtr<AEXWCharacter>> WeakObjPtrCharacterArray, AEXWCharacter* InCharacter);

	static bool AddUniqueWeakObjPtrCharacter(TArray<TWeakObjectPtr<AEXWCharacter>> &WeakObjPtrCharacterArray, AEXWCharacter* InCharacter);

	static bool RemoveWeakObjPtrCharacter(TArray<TWeakObjectPtr<AEXWCharacter>> &WeakObjPtrCharacterArray, AEXWCharacter* InCharacter);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Reaction")
	static AActor* GetClosestActor(AActor* TargetActor, TArray<AActor*> ActorsArray);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Reaction")
	static AEXWCharacter* GetClosestCharacter(AActor* TargetActor, TArray<AEXWCharacter*> CharactersArray);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Death")
	static bool GetClosestRespawnPoint(AEXWCharacter* Character, AEXWRespawnPoint*& RespawnPoint);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Death")
	static bool GetClosestRespawnPointLocationAndRotation(AEXWCharacter* Character, FVector& RespawnPointPosition, FRotator& RespawnPointRotation);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Teleport")
	static bool GetRespawnPointWithName(AEXWCharacter* Character, FString RespawnPointName, AEXWRespawnPoint*& RespawnPoint);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Teleport")
	static bool GetPlayerStartWithName(AEXWCharacter* Character, FName RespawnPointName, APlayerStart*& PlayerStart);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Faction")
	static void FilterByDeathState(TArray<AActor*>& OutActors,
									TArray<AActor*> InActors,
									bool bIsDead = false);

	/**
	 * Faction System
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Faction")
	static void RemoveCharactersWithDifferentFaction(int32 InFaction, TArray<AEXWCharacter*> InCharacterArray, TArray<AEXWCharacter*> &OutCharacterArray);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Faction")
	static void RemoveCharactersWithSameFaction(int32 InFaction, TArray<AEXWCharacter*> InCharacterArray, TArray<AEXWCharacter*>& OutCharacterArray);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Faction")
	static void RemoveCharactersWithDifferentFaction_Cast(int32 InFaction, TArray<AActor*> InCharacterArray, TArray<AActor*>& OutCharacterArray);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Faction")
	static void RemoveCharactersWithSameFaction_Cast(int32 InFaction, TArray<AActor*> InCharacterArray, TArray<AActor*>& OutCharacterArray);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Faction")
	static void FilterByFaction(TArray<AActor*>& OutActors,
								AEXWCharacter* TargetCharacter,
								TArray<AActor*> InActors,
								EEXWTargetFaction TargetFactionType = EEXWTargetFaction::TF_OtherFactionOnly);

	/**
	 * Attributes
	 */

	/** Get Attribute Effect Value by calculating the value to gain or lose later on */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Effect")
	static float GetAttributeEffectValue(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const EEXWValueType ValueType, const float StaticValue, const EEXWAttributeType ValueAttributeType, const float ValueAttributePrecentage);

	/** Apply effect from the given source to the target */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Effect")
	static bool ApplyAttributeEffect(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect &AttributeEffect);

	/** Apply multiple effects from the given source to the target */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Effect")
	static bool ApplyAttributeMultiEffects(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect> &AttributeEffects);

	/** Apply effect from the given source to the target */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Effect")
	static bool ApplyAttributeEffectByFactionCheck(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect& AttributeEffect);

	/** Apply multiple effects from the given source to the target */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Effect")
	static bool ApplyAttributeMultiEffectsByFactionCheck(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect>& AttributeEffects);

	/** Reverses Attribute Effect from the given source to the target */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Effect")
	static bool ReverseAttributeEffect(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const FEXWAttributeEffect& AttributeEffect);

	/** Reverses multiple Attribute Effects from the given source to the target */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Effect")
	static bool ReverseAttributeMultiEffects(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter, const TArray<FEXWAttributeEffect>& AttributeEffects);

	/** Get Attribute from the attributes list provided*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Effect")
	static bool GetAttribute(TArray<FEXWAttribute> Attributes, const EEXWAttributeType AttributeType, FEXWAttribute& OutAttribute);

	/** Get Attribute current value from the  from the attributes*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Effect")
	static bool GetAttributeCurrentValue(TArray<FEXWAttribute> Attributes, const EEXWAttributeType AttributeType, float& OutValue);

	/** Get Attribute percentage value from the  from the attributes*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Effect")
	static bool GetAttributePercentage(TArray<FEXWAttribute> Attributes, const EEXWAttributeType AttributeType, float& OutValue);

	/** Get Attribute maximum value from the  from the attributes*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Effect")
	static bool GetAttributeMaxValue(TArray<FEXWAttribute> Attributes, const EEXWAttributeType AttributeType, float& OutValue);

	/**
	 * Singleton / DT
	 */

	/** Returns the EXWorld singleton containing the main Data Tables. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General")
	static bool GetSingleton(UEXWSingleton* &OutSingleton);

	static UEXWSingleton* GetSingleton();

	/** Returns the Status Effect Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetStatusEffectDT(UDataTable* &OutDataTable);

	/** Returns the Spawnable Ability Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetSpawnableAbilityDT(UDataTable*& OutDataTable);

	/** Returns the Action Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetActionDT(UDataTable*& OutDataTable);

	/** Returns the Reaction Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetReactionDT(UDataTable*& OutDataTable);

	/** Returns the Item Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static UDataTable* GetItemDT();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static FEXWItemData GetItemByID(FName ItemID);

	/** Returns the CraftingOption Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static UDataTable* GetCraftingOptionsDT();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static float GetItemSpawnDistance();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static float GetItemSpawnDistanceVariance();

	/** Returns the Stat level modifier Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetStatLevelModifierDT(UDataTable*& OutDataTable);

	/** Returns the highlight material name during the targeting. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|Highlight")
	static FEXWHighlightData GetHighlightData();

	/**
	 * Widgets
	 */

	/** Returns the trade widget class. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|Widget")
	static TSubclassOf<UEXWSharedWidget> GetShopWidgetClass();

	/** Returns the trade widget class. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|Widget")
	static TSubclassOf<UEXWSharedWidget> GetTradeWidgetClass();

	/** Returns the Floating text widget class. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|Widget")
	static TSubclassOf<UEXWFloatingWidget> GetFloatingTextWidgetClass();

	/** Returns the floating text color depending on a given attribute effect type */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|Widget")
	static FLinearColor GetFloatingTextColor(const EEXWAttributeEffectType AttributeEffectType);

	/** Returns the screen message data from the given type into argument */
	static FEXWScreenMessageData* GetScreenMessageData(const EEXWScreenMessageType ScreenMessageType);



	/**
	 * DataTables
	 */
	
	/** Returns the RaceClassdata Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetRaceClassesDataDT(UDataTable*& OutDataTable);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetIKValueDT(UDataTable*& OutDataTable);

	/** Returns the HeadType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetHeadTypeDT(UDataTable*& OutDataTable);

	/** Returns the HairType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetHairTypeDT(UDataTable*& OutDataTable);

	/** Returns the HairColor Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetHairColorDT(UDataTable*& OutDataTable);

	/** Returns the ArmsType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetArmsTypeDT(UDataTable*& OutDataTable);

	/** Returns the BodyType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetBodyTypeDT(UDataTable*& OutDataTable);

	/** Returns the TorsoType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetTorsoTypeDT(UDataTable*& OutDataTable);

	/** Returns the EyesType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetEyesTypeDT(UDataTable*& OutDataTable);

	/** Returns the EyesColor Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetEyeColorDT(UDataTable*& OutDataTable);

	/** Returns the FaceType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetFaceTypeDT(UDataTable*& OutDataTable);

	/** Returns the FeetType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetFeetTypeDT(UDataTable*& OutDataTable);

	/** Returns the LegsType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetLegsTypeDT(UDataTable*& OutDataTable);

	/** Returns the SkinType Data Table. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static bool GetSkinTypeDT(UDataTable*& OutDataTable);

	/**
	 * Reactions
	 */

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Character|Reaction")
	static void MakeReactionSendingParams(UPARAM(ref) FEXWReactionSendingParams& ReactionSendingParams, const FName RowName, const bool bUseCharacterReactionDT, AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter);

	/**
	 * Experience
	 */

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Character|Level")
	static int32 CalculateExperienceOnKill(AEXWCharacter* KillerCharacter, AEXWCharacter* KilledCharacter);

	/**
	 * Interaction
	 */

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Interaction")
	static TArray<EEXWInteractionType> GetAvailableInteractionTypes(AActor* InteractableActor);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Interaction")
	static void SetAvailableInteractionTypes(AActor* InteractableActor, TArray<EEXWInteractionType> NewInteractionTypes);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Interaction")
	static void AddInteractionType(AActor* InteractableActor, EEXWInteractionType InteractionType);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Interaction")
	static void RemoveInteractionType(AActor* InteractableActor, EEXWInteractionType InteractionType);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Interaction")
	static UWidgetComponent* GetInteractionWidgetComponent(AActor* InteractableActor);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Interaction")
	static void SetInteractionWidgetVisibility(AActor* InteractableActor, const bool bNewVisibility = true);


	/**
	 * Status Effect
	 */


	UFUNCTION(BlueprintCallable, Category = "EXWorld|StatusEffect")
	static bool GetStatusEffectData(const FName StatusEffectID, FEXWStatusEffectData& OutStatusEffectData);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|StatusEffect")
	static FText GetStatusEffectAsText(const FName StatusEffectID);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|StatusEffect")
	static FText GetStatusEffectsAsText(const TArray<FName> StatusEffectIDs);


	/**
	 * Life Skills
	 */

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|LifeSkills", meta = (CompactNodeTitle = "ToText"))
	static FText GetLifeSkillAsText(const EEXWLifeSkillType LifeSkillType);

	/**
	 * Cosmetics
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static FEXWBaseSkeletalMeshes GetRaceBodyMeshData(TArray<FEXWClassVisualData> Classlist,EEXWClass Class, EEXWGender Gender);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetDeathAnimationByRaceAndGender(UAnimMontage*& DeathAnimation, TArray<FEXWClassVisualData> Classlist,EEXWClass Class, EEXWGender Gender);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	bool GetAnimBPFromDT(FName RowName, UAnimBlueprint*& OutAnimBPClass);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetRootMeshFromDT(FName RowName, USkeletalMesh*& OutMesh);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetHeadMeshFromDT(FName RowName, USkeletalMesh*& OutMesh);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetHairMeshFromDT(FName RowName, FEXWHairType& OutHairData);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetHairColorFromDT(FName RowName, FLinearColor& OutColor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetArmsMeshFromDT(FName RowName, USkeletalMesh*& OutMesh);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetBodyMorphsFromDT(FName RowName, USkeletalMesh*& OutMesh);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetTorsoMeshFromDT(FName RowName, USkeletalMesh*& OutMesh);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetEyesMeshFromDT(FName RowName, USkeletalMesh*& EyeMesh, USkeletalMesh*& EyeBrowMesh);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetEyeColorFromDT(FName RowName, FLinearColor& OutColor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetFaceMeshFromDT(FName RowName, USkeletalMesh*& OutMesh);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetFeetMeshFromDT(FName RowName, USkeletalMesh*& OutMesh);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetLegsMeshFromDT(FName RowName, USkeletalMesh*& OutMesh);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Cosmetics")
	static bool GetSkinTypeFromDT(FName RowName, FEXWSkinType& SkinTypeData);

	/**
	 * Display Ui
	 */

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Display", meta = (CompactNodeTitle = "AsText"))
	static FText AttributeTypeAsText(EEXWAttributeType Type);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Display", meta = (CompactNodeTitle = "AsText"))
	static FText StatTypeAsText(EEXWStatType Type);

	/**
	 * Abilities
	 */

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	static UDataTable* GetActionsDT();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Abilities")
	static TArray<FName> GetAvailableActions(TArray<FEXWClassVisualData> Classlist, EEXWClass Class);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Abilities")
	static TArray<FEXWAction> GetActions(TMap<FName, int32> ActionIDs);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Abilities")
	static TArray<FEXWAction> GetActionsByRaceAndClass(EEXWRace Race, EEXWClass Class);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Abilities")
	static TArray<FEXWAction> GetDefaultActionsByRaceAndClass(EEXWRace Race, EEXWClass Class);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Abilities")
	static TArray<FEXWAction> GetDefaultIFrameActionsByRaceAndClass(EEXWRace Race, EEXWClass Class);

	/**
	 * Quests
	 */

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	 static UDataTable* GetQuestsDT();

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|Quests")
	 static FEXWQuest GetQuestByID(FName QuestID);

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|Quests")
	 static TArray<FEXWQuest> GetQuestsByIDs(TArray<FName> QuestIDs);

	 /**
	  * Dialogue
	  */
	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	 static UDataTable* GetDialoguesDT();

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Dialogue")
	 static FEXWDialogue GetDialogueByID(FName DialogueID);

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	 static UDataTable* GetDialogueSpeakersDT();

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Dialogue")
	 static FEXWDialogueSpeaker GetDialogueSpeakerByID(FName SpeakerID);

	 /**
	  * Targeting
	  */
	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Targeting")
	 static bool GetDefaultTargetingByRaceAndClass(EEXWRace Race, EEXWClass Class);

	 /** UpdateLast Affected Character */
	UFUNCTION(BlueprintCallable, Category = "EXWorld|Targeting")
	static bool UpdateLastAffectedPlayer(AEXWCharacter* SourceCharacter, AEXWCharacter* TargetCharacter);

	 /**
	  * NPC Shop
	  */
	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	 static UDataTable* GetNPCShopsDT();

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|NPC Shop")
	 static FEXWShop GetNPCShopByID(FName NPCShopID);

	 /**
	  * Shop/ Player Vending
	  */
	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|NPC Shop")
	 static UAnimMontage* GetVendingAnimMontageByRaceAndClass(EEXWRace Race, EEXWClass Class);

	 /**
	  * Item Sets
	  */

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|General|DataTable")
	 static UDataTable* GetItemSetsDT();

	 UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Inventory")
	 static FEXWItemSet GetItemSetByID(FName ItemSetID);
};