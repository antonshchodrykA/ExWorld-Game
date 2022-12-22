// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Inventory/EXWPlaceable.h"
#include "Core/EXWCharacter.h"
#include "Components/WidgetComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AEXWPlaceable::AEXWPlaceable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
	AvailableInteractionTypes = { EEXWInteractionType::IT_Use };
	InteractionMaxDistance=InteractDistance;

	CollisionComp = CreateDefaultSubobject<UBoxComponent>("Root");
	if (CollisionComp)
	{
		SetRootComponent(CollisionComp);
		CollisionComp->SetBoxExtent(FVector(15.f));
		// Overlap everything and block dynamic and static objects
		CollisionComp->SetCollisionObjectType(ECC_GameTraceChannel3);
		CollisionComp->SetGenerateOverlapEvents(true);
		CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
		CollisionComp->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
		CollisionComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
		CollisionComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
		CollisionComp->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
		// Physics setup
		CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
}

// Called when the game starts or when spawned
void AEXWPlaceable::BeginPlay()
{
	Super::BeginPlay();
	InteractionMaxDistance=InteractDistance;
}

void AEXWPlaceable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

// Called every frame
void AEXWPlaceable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEXWPlaceable::OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType)
{

	if (SourceCharacter)
	{
		FEXWLifeSkill LifeSkill;
		SourceCharacter->GetLifeSkill(LifeSkillType, LifeSkill);

		if (SourceCharacter->ProgressionLevel < MinimumPlayerRequiredLevel)
		{
			UE_LOG(LogTemp, Warning, TEXT("Player Level Requirement unmet"));
			SourceCharacter->Client_DisplayScreenMessage(EEXWScreenMessageType::SM_GatheringPlayerLevelRequirementUnmet);
			return;
		}
		else if (LifeSkill.Level < MinimumLifeSkillRequiredLevel)
		{
			UE_LOG(LogTemp, Warning, TEXT("Life Skill Level Requirement unmet"));
			SourceCharacter->Client_DisplayScreenMessage(EEXWScreenMessageType::SM_GatheringLifeSkillLevelRequirementUnmet);
			return;
		}
	}

}

void AEXWPlaceable::OnReceiveClick(AEXWCharacter* SourceCharacter)
{

}

UWidgetComponent* AEXWPlaceable::GetInteractionWidgetComponent()
{
	return MakeWeakObjectPtr<UWidgetComponent>(nullptr).Get();
}

void AEXWPlaceable::SetInteractionWidgetVisibility(const bool bNewVisibility /*= true*/)
{
	if (UWidgetComponent* CurrWidgetComp = GetInteractionWidgetComponent())
	{
		CurrWidgetComp->SetVisibility(bNewVisibility);
	}
}

