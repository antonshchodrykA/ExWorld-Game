// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interface/EXWInteractable.h"
#include "EXWPlaceable.generated.h"

class AEXWCharacter;
class UBoxComponent;

UCLASS(Abstract)
class EXWORLDCOMBAT_API AEXWPlaceable : public AActor, public IEXWInteractable
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AEXWPlaceable();

	UPROPERTY(Category = Item, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* CollisionComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType) override;

	virtual void OnReceiveClick(AEXWCharacter* SourceCharacter) override;

	virtual UWidgetComponent* GetInteractionWidgetComponent() override;

	virtual void SetInteractionWidgetVisibility(const bool bNewVisibility = true) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Placeable")
	float InteractDistance = 200.f;

	//minimum required levels

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EXWorld|Placeable")
	EEXWLifeSkillType LifeSkillType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Placeable")
	int32 MinimumPlayerRequiredLevel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld|Placeable")
	int32 MinimumLifeSkillRequiredLevel = 1;

	
};
