// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWCharacterPose.h"
#include "Components/SceneComponent.h"
#include "Components/PoseableMeshComponent.h"
#include "Core/EXWCharacter.h"
#include "Core/EXWSkeletalMeshComponent.h"
#include "Engine/SkeletalMesh.h"

// Sets default values
AEXWCharacterPose::AEXWCharacterPose()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	USceneComponent* SceneComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	SetRootComponent(SceneComp);

	PoseableMesh = CreateDefaultSubobject<UPoseableMeshComponent>("PoseableMesh");
	if (PoseableMesh)
	{
		PoseableMesh->SetupAttachment(SceneComp);
		PoseableMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
		PoseableMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AEXWCharacterPose::SetupMeshes(AEXWCharacter* Character, FEXWGhostTrailParams& NewGhostTrailParams)
{
	GhostTrailParams = NewGhostTrailParams;
	if (Character && GetWorld() && PoseableMesh)
	{
		PoseableMesh->SetSkeletalMesh(NewGhostTrailParams.SkeletalMesh);
		PoseableMesh->CopyPoseFromSkeletalComponent(Character->GetMesh());
		for (uint16 i = 0; i < PoseableMesh->GetNumMaterials(); i++)
		{
			PoseableMesh->SetMaterial(i, NewGhostTrailParams.Material);
		}
		FTimerDelegate FadingDelegate;
		FadingDelegate.BindLambda([&](){
			if (PoseableMesh->SkeletalMesh)
			{
				//GetWorld()->GetTimerManager().ClearTimer(FadingTimerHandle);
				SetLifeSpan(.1f);
			}
		});
		GetWorld()->GetTimerManager().SetTimer(FadingTimerHandle, FadingDelegate, .1f, false, GhostTrailParams.Duration);
	}
}

// Called when the game starts or when spawned
void AEXWCharacterPose::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEXWCharacterPose::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PoseableMesh->SkeletalMesh && GetWorld() && GetWorld()->GetTimerManager().IsTimerActive(FadingTimerHandle))
	{
		float RemainingTime = GetWorld()->GetTimerManager().GetTimerRemaining(FadingTimerHandle);
		PoseableMesh->SetScalarParameterValueOnMaterials(GhostTrailParams.OpacityParamName, RemainingTime / GhostTrailParams.Duration);
	}
}

