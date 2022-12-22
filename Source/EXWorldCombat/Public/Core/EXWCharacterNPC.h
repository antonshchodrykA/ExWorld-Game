// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/EXWCharacter.h"
//#include "Plugins/ALSV4_CPP/Public/Character/ALSBaseCharacter.h"
#include "Character/ALSBaseCharacter.h"
#include "EXWCharacterNPC.generated.h"


/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API AEXWCharacterNPC : public AEXWCharacter
{
	GENERATED_BODY()

		AEXWCharacterNPC(const FObjectInitializer& ObjectInitializer);
	
	virtual void  OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType) override;

	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|NPC")
	FName DialogueID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|NPC")
	FName ShopID;

};
