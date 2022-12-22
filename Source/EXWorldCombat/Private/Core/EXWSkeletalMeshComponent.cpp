// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/EXWSkeletalMeshComponent.h"
#include "GameFramework/Pawn.h"

UEXWSkeletalMeshComponent::UEXWSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//SetIsReplicated(true);
}

void UEXWSkeletalMeshComponent::SetAllMaterials(UMaterialInterface* NewMaterial)
{
	for (int32 i = 0; i < GetNumMaterials(); i++)
	{
		SetMaterial(i, NewMaterial);
	}
	Server_SetAllMaterials(NewMaterial);
}

void UEXWSkeletalMeshComponent::Server_SetAllMaterials_Implementation(UMaterialInterface* NewMaterial)
{
	Multicast_SetAllMaterials(NewMaterial);
}

void UEXWSkeletalMeshComponent::Multicast_SetAllMaterials_Implementation(UMaterialInterface* NewMaterial)
{
	if (!IsOwnerLocallyControlled())
	{
		for (int32 i = 0; i < GetNumMaterials(); i++)
		{
			SetMaterial(i, NewMaterial);
		}
	}
}

void UEXWSkeletalMeshComponent::CacheMaterials()
{
	CachedMaterials = GetMaterials();
	Server_CacheMaterials();
}

void UEXWSkeletalMeshComponent::CacheMaterialsLocal()
{
	CachedMaterials = GetMaterials();
}

void UEXWSkeletalMeshComponent::Server_CacheMaterials_Implementation()
{
	Multicast_CacheMaterials();
}

void UEXWSkeletalMeshComponent::Multicast_CacheMaterials_Implementation()
{
	if (!IsOwnerLocallyControlled())
	{
		CachedMaterials = GetMaterials();
	}
}

void UEXWSkeletalMeshComponent::ApplyCachedMaterials()
{
	for (uint16 i = 0; i < GetNumMaterials(); i++)
	{
		if (CachedMaterials.IsValidIndex(i))
		{
			SetMaterial(i, CachedMaterials[i]);
		}
	}
	Server_ApplyCachedMaterials();
}

void UEXWSkeletalMeshComponent::Server_ApplyCachedMaterials_Implementation()
{
	Multicast_ApplyCachedMaterials();
}

void UEXWSkeletalMeshComponent::Multicast_ApplyCachedMaterials_Implementation()
{
	if (!IsOwnerLocallyControlled())
	{
		for (uint16 i = 0; i < GetNumMaterials(); i++)
		{
			if (CachedMaterials.IsValidIndex(i))
			{
				SetMaterial(i, CachedMaterials[i]);
			}
		}
	}
}

void UEXWSkeletalMeshComponent::ApplyDefaultMaterialsLocal()
{
	for (uint16 i = 0; i < GetNumMaterials(); i++)
	{
		if (SkeletalMesh->Materials.IsValidIndex(i))
		{
			SetMaterial(i, SkeletalMesh->Materials[i].MaterialInterface);
		}
	}
}

void UEXWSkeletalMeshComponent::ApplyDefaultMaterialsReplicated()
{
	ApplyDefaultMaterialsLocal();
	Server_ApplyDefaultMaterials();
}

void UEXWSkeletalMeshComponent::Server_ApplyDefaultMaterials_Implementation()
{
	Multicast_ApplyDefaultMaterials();
}

void UEXWSkeletalMeshComponent::Multicast_ApplyDefaultMaterials_Implementation()
{
	if (!IsOwnerLocallyControlled())
	{
		ApplyDefaultMaterialsLocal();
	}
}


bool UEXWSkeletalMeshComponent::IsOwnerLocallyControlled()
{
	if (APawn* OwnerPawn = Cast<APawn>(GetOwner()))
	{
		return OwnerPawn->IsLocallyControlled();
	}
	return false;
}

