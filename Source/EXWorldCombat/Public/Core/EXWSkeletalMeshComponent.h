// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "EXWSkeletalMeshComponent.generated.h"

/**
 * 
 */
UCLASS()
class EXWORLDCOMBAT_API UEXWSkeletalMeshComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:

	UEXWSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void SetAllMaterials(UMaterialInterface* NewMaterial);

	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void Server_SetAllMaterials(UMaterialInterface* NewMaterial);

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void Multicast_SetAllMaterials(UMaterialInterface* NewMaterial);

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void CacheMaterials();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void CacheMaterialsLocal();

	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void Server_CacheMaterials();

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void Multicast_CacheMaterials();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void ApplyCachedMaterials();

	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void Server_ApplyCachedMaterials();

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void Multicast_ApplyCachedMaterials();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void ApplyDefaultMaterialsLocal();

	UFUNCTION(BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void ApplyDefaultMaterialsReplicated();

	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void Server_ApplyDefaultMaterials();

	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "EXWorld|Mesh|Material")
	void Multicast_ApplyDefaultMaterials();

protected:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EXWorld|Mesh")
	bool IsOwnerLocallyControlled();

	TArray<UMaterialInterface*> CachedMaterials;
};
