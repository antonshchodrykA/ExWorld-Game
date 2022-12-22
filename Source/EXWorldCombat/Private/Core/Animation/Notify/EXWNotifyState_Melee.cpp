// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Animation/Notify/EXWNotifyState_Melee.h"
#include "Core/EXWCharacter.h"
#include "Core/EXWSingleton.h"
#include "Kismet/GameplayStatics.h"
#include "Library/EXWDataLibrary.h"
#include "Core/EXWCharacter.h"

UEXWNotifyState_Melee::UEXWNotifyState_Melee() : Super()
{
	bAffectOtherFactions = true;
}

void UEXWNotifyState_Melee::AffectCharacter(AEXWCharacter* TargetCharacter)
{
	if (TargetCharacter != OwnerCharacter)
	{
		TArray<AEXWCharacter*> Targets;
		// This can be changed to ability data effector if ever needed
		OwnerCharacter->Server_ApplyAttributeMultiEffects(OwnerCharacter, TargetCharacter, AttributeEffects);
		// Create reaction data and sending it
		FEXWReactionSendingParams ReactionParams;
		UEXWDataLibrary::MakeReactionSendingParams(ReactionParams, ReactionRowName, true, OwnerCharacter, TargetCharacter);
		OwnerCharacter->SendReaction(ReactionParams);
		//Targets.AddUnique(TargetCharacter);
		//OwnerCharacter->SetTargets(Targets);
		//if (bHighlightTarget)
		//{
		//	UEXWSingleton* EXWSingleton;	
		//	OwnerCharacter->HighlightCharacter(TargetCharacter, EXWSingleton->HighlightMaterialParamName, HighlightColor);
		//}
		AffectedCharacters.AddUnique(TargetCharacter);
	}
}

void UEXWNotifyState_Melee::AffectCharacterWithFactionCheck(AEXWCharacter* TargetCharacter)
{
	if (bAffectOwner && TargetCharacter == OwnerCharacter)
	{
		AffectCharacter(TargetCharacter);
	}
	if (bAffectOtherFactions && !OwnerCharacter->IsSameFaction(TargetCharacter))
	{ 
		AffectCharacter(TargetCharacter);
	}
	if (bAffectOwnerFaction && OwnerCharacter->IsSameFaction(TargetCharacter) && TargetCharacter != OwnerCharacter)
	{
		AffectCharacter(TargetCharacter);
	}
}

void UEXWNotifyState_Melee::NotifyBegin(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float TotalDuration)
{
	if (MeshComp->GetOwner())
	{
		OwnerCharacter = Cast<AEXWCharacter>(MeshComp->GetOwner());
		if (OwnerCharacter)
		{
			if (OwnerCharacter->IsLocallyControlled())
			{
				CollisionComponents = OwnerCharacter->GetComponentsByTag(UPrimitiveComponent::StaticClass(), CollisionComponentTag);
			}
		}
	}
	Received_NotifyBegin(MeshComp, Animation, TotalDuration);
}

void UEXWNotifyState_Melee::NotifyTick(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	// Quite heavy on a tick but this is the trick now until we find out a more optimized approach.
	if (OwnerCharacter)
	{
		if (OwnerCharacter->IsLocallyControlled())
		{
			for (UActorComponent* CollisionComponent : CollisionComponents)
			{
				if (UPrimitiveComponent* PrimComp = Cast<UPrimitiveComponent>(CollisionComponent))
				{
					TArray<AActor*> OverlappedActors;
					PrimComp->GetOverlappingActors(OverlappedActors);
					if (!bAffectOwner)
					{
						OverlappedActors.Remove(OwnerCharacter);
					}
					// If it will affect only the closest character or not
					if (bAffectClosestOnly && !bHasAffectedActor)
					{
						AActor* ClosestActor = UEXWDataLibrary::GetClosestActor(OwnerCharacter, OverlappedActors);
						if (ClosestActor)
						{
							if (AEXWCharacter* ClosestCharacter = Cast<AEXWCharacter>(ClosestActor))
							{
								AffectCharacterWithFactionCheck(ClosestCharacter);
								bHasAffectedActor = true;
							}
						}
					}
					else if (!bAffectClosestOnly)
					{
						for (AActor* OverlappedActor : OverlappedActors)
						{
							if (AEXWCharacter* OverlappedCharacter = Cast<AEXWCharacter>(OverlappedActor))
							{	
								if (!AffectedCharacters.Contains(OverlappedCharacter))
								{
									AffectCharacterWithFactionCheck(OverlappedCharacter);
								}
							}
						}
					}
				}
			}
		}
	}
	Received_NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UEXWNotifyState_Melee::NotifyEnd(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation)
{
	if (bHighlightTarget && OwnerCharacter)
	{
		if (OwnerCharacter->IsLocallyControlled())
		{
			//UEXWSingleton* EXWSingleton;
			//if (UEXWDataLibrary::GetSingleton(EXWSingleton))
			//{
			//	for (TWeakObjectPtr<AEXWCharacter> TargetCharacter : AffectedCharacters)
			//	{
			//		OwnerCharacter->UnhighlightCharacter(TargetCharacter.Get(), EXWSingleton->HighlightMaterialParamName);
			//	}
			//}
			OwnerCharacter->SetTargets(AffectedCharacters);
		}
	}

	AffectedCharacters.Empty();
	bHasAffectedActor = false;
	Received_NotifyEnd(MeshComp, Animation);
}
