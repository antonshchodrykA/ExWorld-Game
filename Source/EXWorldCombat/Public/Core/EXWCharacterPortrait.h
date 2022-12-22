// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EXWCharacterPortrait.generated.h"

class USceneCaptureComponent;
class UEXWSkeletalMeshComponent;
class USceneCaptureComponent2D;
class UTextureRenderTarget2D;

UCLASS()
class EXWORLDCOMBAT_API AEXWCharacterPortrait : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEXWCharacterPortrait();

protected:
	/**
	 * Meshes list
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* CharacterMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* HeadMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* TorsoMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* ArmsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* LegsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* FeetMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* EyesMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* EyebrowsMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* TeethMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* TongueMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "EXWorld|Mesh")
	UEXWSkeletalMeshComponent* HairMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneCaptureComponent2D* SceneCapture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portrait")
	UTextureRenderTarget2D* RenderTarget;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
