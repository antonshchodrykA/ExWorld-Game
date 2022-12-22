// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MetaDataComponent.generated.h"

USTRUCT(BlueprintType)
struct FEXMetaData {
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite)
		int32 PlayerIndex;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMetaDataUpdated, FEXMetaData, MetaData);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEMOTEST_API UMetaDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMetaDataComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	FORCEINLINE FEXMetaData GetMetaData() const
	{
		return MetaData;
	}

	FORCEINLINE bool IsMetaDataAvailable() const
	{
		return bMetaDataAvailable;
	}

	UFUNCTION(BlueprintCallable)
		void SetMetaData(FEXMetaData NewMetaData);

	UPROPERTY(BlueprintAssignable)
		FMetaDataUpdated MetaDataUpdated;

protected:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MetaData)
		FEXMetaData MetaData;

	UPROPERTY(BlueprintReadOnly, BlueprintReadOnly, Replicated)
		bool bMetaDataAvailable = false;

	UFUNCTION()
		void OnRep_MetaData();
};
