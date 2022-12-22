// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Inventory/EXWPlaceable_FireLog.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Niagara/Public/NiagaraComponent.h"
#include "Core/EXWCharacter.h"
#include "Net/UnrealNetwork.h"

AEXWPlaceable_FireLog::AEXWPlaceable_FireLog()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	if (StaticMesh)
	{
		StaticMesh->SetupAttachment(CollisionComp);
		StaticMesh->SetGenerateOverlapEvents(true);
		StaticMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
		StaticMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
		StaticMesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
		StaticMesh->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
		CollisionComp->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
		CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}

	ParticleSystemComp = CreateDefaultSubobject<UParticleSystemComponent>("Particle System Component");
	if (ParticleSystemComp)
	{
		ParticleSystemComp->SetupAttachment(CollisionComp);
		ParticleSystemComp->bAutoActivate = false;
		ParticleSystemComp->Deactivate();
	}

	NiagaraComp = CreateDefaultSubobject<UNiagaraComponent>("Niagara Component");
	if (NiagaraComp)
	{
		NiagaraComp->SetupAttachment(CollisionComp);
		ParticleSystemComp->bAutoActivate = false;
		NiagaraComp->Deactivate();
	}

	bIsActive = false;
	IgniteItems = { "TinderBox" };
	IgniteAbilities = { "DarkArts_IgniteFireLog" };

	Experiences.Add(EEXWLifeSkillType::LS_FireMaking, 30);
}

void AEXWPlaceable_FireLog::Server_SetIsActive_Implementation(const bool NewValue)
{
	bIsActive = NewValue;
	// Change effects, Server Side
	ActivateEffects(NewValue);
}

void AEXWPlaceable_FireLog::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	ActivateEffects(bIsActive);
}

void AEXWPlaceable_FireLog::OnRep_IsActive()
{
	// Change effects, all clients Side
	ActivateEffects(bIsActive);
}

void AEXWPlaceable_FireLog::ActivateEffects(const bool NewValue)
{
	if (NewValue)
	{
		ParticleSystemComp->Activate(true);
		NiagaraComp->Activate(true);
	}
	else
	{
		ParticleSystemComp->Deactivate();
		NiagaraComp->Deactivate();
	}
}

void AEXWPlaceable_FireLog::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AEXWPlaceable_FireLog, bIsActive);
}

void AEXWPlaceable_FireLog::OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType)
{
	if (SourceCharacter && InteractionType == EEXWInteractionType::IT_Use && !bIsActive)
	{
		if (CanCharacterIgnite(SourceCharacter))
		{
			Server_SetIsActive(true);

			// Give experience
			for (TPair<EEXWLifeSkillType, int32>& Experience : Experiences)
			{
				SourceCharacter->GainLifeSkillExperience(Experience.Key, Experience.Value);
			}
		}
		else
		{
			// Display Log that character can't ignite
		}
	}
	Super::OnReceiveInteraction(SourceCharacter, InteractionType);
}

bool AEXWPlaceable_FireLog::CanCharacterIgnite(AEXWCharacter* SourceCharacter)
{
	check(SourceCharacter);
	for (FName IgniteItem : IgniteItems)
	{
		if (SourceCharacter->HasItem(IgniteItem))
		{
			return true;
		}
	}
	for (FName IgniteAbility : IgniteAbilities)
	{
		// Find out if the ability is available
	}
	return false;
}
