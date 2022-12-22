// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Inventory/EXWPlaceable_Gatherable.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Core/EXWCharacter.h"
#include "Net/UnrealNetwork.h"

AEXWPlaceable_Gatherable::AEXWPlaceable_Gatherable()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	if (StaticMesh)
	{
		StaticMesh->SetupAttachment(CollisionComp);
	}

	AvailableInteractionTypes = { EEXWInteractionType::IT_Gather };
	GatheringItemRates = {};
	Experiences.Add(EEXWLifeSkillType::LS_Gathering, 30);
	GatheringDuration = 2.f;
	bIsResourceAvailable = true;
	RespawnTime = 20.f;
}

void AEXWPlaceable_Gatherable::Server_DropItems_Implementation(AEXWCharacter* SourceCharacter)
{
	for (FEXWGatheringRate& GatheringItemRate : GatheringItemRates)
	{
		float RandomValue = UKismetMathLibrary::RandomFloat();
		if (RandomValue < GatheringItemRate.DropRate)
		{
			int32 ItemCount = UKismetMathLibrary::RandomIntegerInRange(GatheringItemRate.Count - GatheringItemRate.CountVariation, GatheringItemRate.Count + GatheringItemRate.CountVariation);
			int32 RemainingCount=0; 
			SourceCharacter->TryAddingItemsToInventory(GatheringItemRate.ItemID, ItemCount,RemainingCount);
			SourceCharacter->Client_OnCharacterGatherComplete(GatheringItemRate.ItemID, ItemCount);
			if (RemainingCount>0)
			{
				SourceCharacter->SpawnItem(GatheringItemRate.ItemID, RemainingCount);
			}
		}
	}
}

void AEXWPlaceable_Gatherable::Server_Respawn_Implementation()
{
	SetIsResourceAvailable(true);
}

void AEXWPlaceable_Gatherable::SetIsResourceAvailable(const bool bNewValue)
{
	bIsResourceAvailable = bNewValue;
	OnUpdateResourceAvailablity_Native();
}

void AEXWPlaceable_Gatherable::OnUpdateResourceAvailablity_Native()
{
	OnUpdateResourceAvailablity();
}

void AEXWPlaceable_Gatherable::StartGathering(AEXWCharacter* SourceCharacter)
{
	if (SourceCharacter)
	{
		// Create weak obj ptr
		GatheringCharacter = MakeWeakObjectPtr<AEXWCharacter>(SourceCharacter);

		// Play gathering montage
		GatheringMontage=*GatheringMontages.Find(SourceCharacter->Gender);
		SourceCharacter->Client_PlayMontage(GatheringMontage, 1.f);
		SourceCharacter->Multicast_PlayMontage(GatheringMontage, 1.f);
		switch (RequiredTool)
		{
		case EEXWEquipmentType::ET_Pickaxe:
			SourceCharacter->Gather_Toggle(true, FName("WoodPickAxe"));
			break;
		case EEXWEquipmentType::ET_Axe:
			SourceCharacter->Gather_Toggle(true, FName("WoodCuttingAxe"));
			break;
			

		default: break;
		}
		//Server_SetSkeletalMesh(SourceCharacter->GetMesh(RightHandWeaponMesh),)

		// Setup and apply look at direction
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(SourceCharacter->GetActorLocation(), GetActorLocation());
		LookAtRotation.Roll = SourceCharacter->GetActorRotation().Roll;
		LookAtRotation.Pitch = SourceCharacter->GetActorRotation().Pitch;
		SourceCharacter->Client_SetActorLocationAndRotation(SourceCharacter->GetActorLocation(), LookAtRotation);
		SourceCharacter->Multicast_SetActorLocationAndRotation(SourceCharacter->GetActorLocation(), LookAtRotation);
	}
}

void AEXWPlaceable_Gatherable::StopGathering()
{
	if (GatheringCharacter.IsValid())
	{
		GatheringCharacter->Gather_Toggle(false, FName("None"));
		GatheringMontage=*GatheringMontages.Find(GatheringCharacter->Gender);
		if (GatheringCharacter.Get()->GetCurrentActiveMontage() == GatheringMontage)
		{
			Server_DropItems(GatheringCharacter.Get());
			SetIsResourceAvailable(false);
			if (GatheringMontage->IsValidSectionName(MontageEndSectionName))
			{
				// Play end section of gathering montage
				GatheringCharacter->Client_PlayMontageSection(GatheringMontage, 1.f,MontageEndSectionName);
				GatheringCharacter->Multicast_PlayMontageSection(GatheringMontage, 1.f,MontageEndSectionName);
			}
			else
			{
				GatheringCharacter.Get()->Multicast_StopMontage(GatheringMontage);
			}

			// Give experience
			for (TPair<EEXWLifeSkillType, int32> &Experience : Experiences)
			{
				GatheringCharacter.Get()->GainLifeSkillExperience(Experience.Key, Experience.Value);
			}
			
			if (GetWorld())
			{
				FTimerDelegate RespawnTimerDel;
				RespawnTimerDel.BindLambda([&]() {
					Server_Respawn();
					});
				GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, RespawnTimerDel, .1f, false, RespawnTime);
			}
		}
		GatheringCharacter.Reset();
	}
}

void AEXWPlaceable_Gatherable::OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType)
{
	if (SourceCharacter)
	{
		FEXWLifeSkill LifeSkill;
		SourceCharacter->GetLifeSkill(LifeSkillType, LifeSkill);
		if (GatheringCharacter.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Somebody is already gathering this resource")); // TODO : Add custom logs category
			SourceCharacter->Client_DisplayScreenMessage(EEXWScreenMessageType::SM_ResourceBeingGatheredError);
			return;
		}
		else if (!bIsResourceAvailable)
		{
			UE_LOG(LogTemp, Warning, TEXT("No resource to gather"));
			SourceCharacter->Client_DisplayScreenMessage(EEXWScreenMessageType::SM_NoResourceToGatherError);
			return;
		}
		else if (!GatheringMontages.Find(SourceCharacter->Gender))
		{
			UE_LOG(LogTemp, Warning, TEXT("No Gathering montage set in the class default."));
			return;
		} else if (SourceCharacter->ProgressionLevel < MinimumPlayerRequiredLevel)
		{
			UE_LOG(LogTemp, Warning, TEXT("Player Level Requirement unmet"));
			SourceCharacter->Client_DisplayScreenMessage(EEXWScreenMessageType::SM_GatheringPlayerLevelRequirementUnmet);
			return;
		} else if (LifeSkill.Level < MinimumLifeSkillRequiredLevel)
		{
			UE_LOG(LogTemp, Warning, TEXT("Life Skill Level Requirement unmet"));
			SourceCharacter->Client_DisplayScreenMessage(EEXWScreenMessageType::SM_GatheringLifeSkillLevelRequirementUnmet);
			return;
		}
		else if (GetWorld() && InteractionType == EEXWInteractionType::IT_Gather)
		{
			if (!SourceCharacter->HasItemByType(RequiredTool))
			{
				SourceCharacter->Client_DisplayScreenMessage(EEXWScreenMessageType::SM_GatheringNoToolError);
				return;
			}
			StartGathering(SourceCharacter);

			FTimerDelegate GatheringTimerDel;
			GatheringTimerDel.BindLambda([&] { StopGathering(); });
			GetWorld()->GetTimerManager().SetTimer(GatheringTimerHandle, GatheringTimerDel, .1f, false, GatheringDuration);
			
			//client timer
			TArray<EEXWLifeSkillType> keyarray;
			Experiences.GenerateKeyArray(keyarray);
			SourceCharacter->Client_Gathering(LifeSkillType,GatheringDuration);
		}
	}
}

void AEXWPlaceable_Gatherable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AEXWPlaceable_Gatherable, GatheringCharacter);
	DOREPLIFETIME(AEXWPlaceable_Gatherable, bIsResourceAvailable);
}

void AEXWPlaceable_Gatherable::OnRep_IsResourceAvailable()
{
	OnUpdateResourceAvailablity_Native();
}
