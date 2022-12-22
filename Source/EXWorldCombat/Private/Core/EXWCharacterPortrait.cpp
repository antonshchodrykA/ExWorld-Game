// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWCharacterPortrait.h"
#include "Core/EXWSkeletalMeshComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/SceneComponent.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Core/EXWCharacter.h"

// Sets default values
AEXWCharacterPortrait::AEXWCharacterPortrait()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	SceneComponent = CreateDefaultSubobject<USceneComponent>("RootScene");

	CharacterMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("CharacterMesh");
	CharacterMesh->SetupAttachment(SceneComponent);
	CharacterMesh->SetRenderCustomDepth(true);
	CharacterMesh->CustomDepthStencilValue = 1;

	HeadMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("HeadMesh");
	HeadMesh->SetupAttachment(CharacterMesh);
	HeadMesh->SetRenderCustomDepth(true);
	HeadMesh->CustomDepthStencilValue = 1;

	TorsoMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("TorsoMesh");
	TorsoMesh->SetupAttachment(CharacterMesh);
	TorsoMesh->SetRenderCustomDepth(true);
	TorsoMesh->CustomDepthStencilValue = 1;

	ArmsMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("ArmsMesh");
	ArmsMesh->SetupAttachment(CharacterMesh);
	ArmsMesh->SetRenderCustomDepth(true);
	ArmsMesh->CustomDepthStencilValue = 1;

	LegsMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("LegsMesh");
	LegsMesh->SetupAttachment(CharacterMesh);
	LegsMesh->SetRenderCustomDepth(true);
	LegsMesh->CustomDepthStencilValue = 1;

	FeetMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("FeetMesh");
	FeetMesh->SetupAttachment(CharacterMesh);
	FeetMesh->SetRenderCustomDepth(true);
	FeetMesh->CustomDepthStencilValue = 1;

	EyesMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("EyesMesh");
	EyesMesh->SetupAttachment(CharacterMesh);
	EyesMesh->SetRenderCustomDepth(true);
	EyesMesh->CustomDepthStencilValue = 1;

	EyebrowsMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("EyebrowsMesh");
	EyebrowsMesh->SetupAttachment(CharacterMesh);
	EyebrowsMesh->SetRenderCustomDepth(true);
	EyebrowsMesh->CustomDepthStencilValue = 1;

	TeethMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("TeethMesh");
	TeethMesh->SetupAttachment(CharacterMesh);
	TeethMesh->SetRenderCustomDepth(true);
	TeethMesh->CustomDepthStencilValue = 1;

	TongueMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("TongueMesh");
	TongueMesh->SetRenderCustomDepth(true);
	TongueMesh->SetupAttachment(CharacterMesh);
	TongueMesh->CustomDepthStencilValue = 1;

	HairMesh = CreateDefaultSubobject<UEXWSkeletalMeshComponent>("HairMesh");
	HairMesh->SetupAttachment(CharacterMesh, "head"); 
	HairMesh->AddRelativeRotation(FRotator(-90.f, 0.f, 0.f));
	HairMesh->SetRenderCustomDepth(true);
	HairMesh->CustomDepthStencilValue = 1;


	RootComponent = SceneComponent;

	SceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture2D"));
	SceneCapture->SetupAttachment(CharacterMesh, "head");
	SceneCapture->SetRelativeLocation(FVector(0.0f, 0.0f, 160.0f));
	
	SceneCapture->ProjectionType = ECameraProjectionMode::Perspective;
	SceneCapture->FOVAngle = 10.0f;
	//SceneCapture->OrthoWidth = 30.0f;
	SceneCapture->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_RenderScenePrimitives;
	SceneCapture->CaptureSource = ESceneCaptureSource::SCS_SceneColorSceneDepth;



}

// Called when the game starts or when spawned
void AEXWCharacterPortrait::BeginPlay()
{
	
	/*
	if (RenderTarget)
	{
		if (AEXWCharacter* Character = Cast<AEXWCharacter>(GetOwner()))
		{
			if (Character->IsLocallyControlled())
			{
				SceneCapture->TextureTarget = RenderTarget;
			}
		}
	}*/

	Super::BeginPlay();
}
