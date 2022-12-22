// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EXWActorIndicator.generated.h"

UCLASS()
class EXWORLDCOMBAT_API AEXWActorIndicator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEXWActorIndicator();

	UPROPERTY(VisibleAnywhere, Category  = "EXWorld|Indicator|Mesh")
	class UStaticMeshComponent* StaticMesh;

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Indicator|Mesh")
	void SetStaticMesh(UStaticMesh* NewStaticMesh);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
