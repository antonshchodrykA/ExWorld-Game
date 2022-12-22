// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Tier1Mob.h"
#include "Components/SkeletalMeshComponent.h"

ANPC_Tier1Mob::ANPC_Tier1Mob(const FObjectInitializer& ObjectInitializer)
{
	AddHitPoints(1, "NoCollision", "NoCollision");
}

void ANPC_Tier1Mob::BeginPlay()
{
	Super::BeginPlay();

	if (HitPoint1)
	{
		const FAttachmentTransformRules AttachmentR(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, false);
		HitPoint1->AttachToComponent(GetMesh(), AttachmentR, "AnimalBite");
		
	}
}