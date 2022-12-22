// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Library/EXWDataStruct.h"
#include "EXWCharacterPose.generated.h"

UCLASS()
class EXWORLDCOMBAT_API AEXWCharacterPose : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEXWCharacterPose();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "EXWorld|Pose")
	class UPoseableMeshComponent* PoseableMesh;

public:

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Pose")
	void SetupMeshes(class AEXWCharacter* Character, UPARAM(ref) FEXWGhostTrailParams& NewGhostTrailParams);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	FEXWGhostTrailParams GhostTrailParams;
	FTimerHandle FadingTimerHandle;
};
