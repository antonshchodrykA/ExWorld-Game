// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Library/EXWDataStruct.h"
#include "EXWNotifyState_Melee.generated.h"

class AEXWCharacter;

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWNotifyState_Melee : public UAnimNotifyState
{
	GENERATED_BODY()

public:

	UEXWNotifyState_Melee();

protected:

	virtual void AffectCharacter(AEXWCharacter* TargetCharacter);
	virtual void AffectCharacterWithFactionCheck(AEXWCharacter* TargetCharacter);

	virtual void NotifyBegin(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime) override;
	virtual void NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation) override;

public:

	/** Tag of the collision component to trace from in order to deal damage. This component should have a Primitive Component as a parent */
	UPROPERTY(EditAnywhere, Category = Base, meta = (Tooltip = "Tag of the collision component to trace from in order to deal damage"))
	FName CollisionComponentTag = "Damage";

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Effect) 
	TArray<FEXWAttributeEffect> AttributeEffects;

	/** Damage Type */
	UPROPERTY(EditAnywhere, Category = Damage, meta = (Tooltip = "Damage Type"))
	TSubclassOf<UDamageType> DamageType;

	/** Reaction data to send to the EXWCharacter to affect. */
	UPROPERTY(EditAnywhere, Category = Reaction, meta = (Tooltip = "Reaction data to send to the EXWCharacter to affect"))
	FName ReactionRowName = "None";

	/** This boolean defines whether the melee is an AOE or not. */
	UPROPERTY(EditAnywhere, Category = Reaction, meta = (Tooltip = "This boolean defines whether the melee is an AOE or not."))
	uint8 bAffectClosestOnly : 1;

	/** Whether or not it shall highlight affected targets*/
	UPROPERTY(EditAnywhere, Category = Highlight)
	uint8 bHighlightTarget : 1;

	/** Main Highlight Color when targeting a character to affect */
	UPROPERTY(EditAnywhere, Category = Highlight, meta = (EditCondition = "bHighlightTarget"))
	FLinearColor HighlightColor = FLinearColor::Red;

	UPROPERTY(EditAnywhere, Category = Effect)
	uint8 bAffectOwner : 1;

	UPROPERTY(EditAnywhere, Category = Effect)
	uint8 bAffectOtherFactions : 1;

	UPROPERTY(EditAnywhere, Category = Effect)
	uint8 bAffectOwnerFaction : 1;

	/**
	 * Temp values 
	 */

	UPROPERTY()
	TArray<AEXWCharacter*> AffectedCharacters;
	
	UPROPERTY()
	TArray<UActorComponent*> CollisionComponents;
	
	UPROPERTY()
	AEXWCharacter* OwnerCharacter;

	UPROPERTY()
	uint8 bHasAffectedActor: 1;
};
