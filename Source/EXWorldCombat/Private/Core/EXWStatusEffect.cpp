// Project:         EXWorld
// Copyright:       Copyright (C) 2021 ZhouseStudios
// Author :         Jed Fakhfekh

#include "Core/EXWStatusEffect.h"
#include "Core/EXWCharacter.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AEXWStatusEffect::AEXWStatusEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;
}

// Called when the game starts or when spawned
void AEXWStatusEffect::BeginPlay()
{
	Super::BeginPlay();
	
	// Attach on Server here
}

// Called every frame
void AEXWStatusEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEXWStatusEffect::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AEXWStatusEffect, StatusEffectData);
}

void AEXWStatusEffect::Server_SetStatusEffectData_Implementation(FEXWStatusEffectData InData)
{
	StatusEffectData = InData;
	SetLifeSpan(StatusEffectData.Duration);
}

AEXWCharacter* AEXWStatusEffect::GetSourceCharacter()
{
	if (StatusEffectData.SourceCharacter.IsValid())
	{
		return StatusEffectData.SourceCharacter.Get();
	}
	return nullptr;
}

AEXWCharacter* AEXWStatusEffect::GetTargetCharacter()
{
	if (StatusEffectData.TargetCharacter.IsValid())
	{
		return StatusEffectData.TargetCharacter.Get();
	}
	return nullptr;
}

void AEXWStatusEffect::Server_AttachToTarget_Implementation()
{
	MulticastAttachToTarget();
}

void AEXWStatusEffect::MulticastAttachToTarget_Implementation()
{
	AttachToTarget();
}

void AEXWStatusEffect::AttachToTarget()
{
	if (StatusEffectData.TargetCharacter.IsValid())
	{
		if (USkeletalMeshComponent* MeshComp = StatusEffectData.TargetCharacter.Get()->GetMesh())
		{
			AttachToComponent(MeshComp, FAttachmentTransformRules::KeepWorldTransform, MeshComp->DoesSocketExist(StatusEffectData.SocketName) ? StatusEffectData.SocketName : "None");
		}
	}
}
