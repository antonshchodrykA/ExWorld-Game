// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/Inventory/EXWPlaceable_Gatherable.h"
#include "EXWPlaceable_Gatherable_Ore.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class EXWORLDCOMBAT_API AEXWPlaceable_Gatherable_Ore : public AEXWPlaceable_Gatherable
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Ore")
	FName VeinsColorParamName = "VeinsColor";

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Ore")
	FLinearColor ResourceAvailabilityColor = FLinearColor(0.f, .5f, 1.f);

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "EXWorld|Ore")
	FLinearColor ResourceUnavailabilityColor = FLinearColor(0.f, 0.f, 0.f);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Ore")
	void UpdateMeshMaterials();

protected:

	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void OnUpdateResourceAvailablity_Native() override;
};
