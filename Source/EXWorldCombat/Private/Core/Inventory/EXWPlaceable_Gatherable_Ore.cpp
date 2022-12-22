// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/Inventory/EXWPlaceable_Gatherable_Ore.h"

void AEXWPlaceable_Gatherable_Ore::UpdateMeshMaterials()
{
	if (StaticMesh)
	{
		StaticMesh->SetVectorParameterValueOnMaterials(VeinsColorParamName, FVector((bIsResourceAvailable) ? ResourceAvailabilityColor : ResourceUnavailabilityColor));
	}
}

void AEXWPlaceable_Gatherable_Ore::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UpdateMeshMaterials();
}

void AEXWPlaceable_Gatherable_Ore::OnUpdateResourceAvailablity_Native()
{
	UpdateMeshMaterials();
}
