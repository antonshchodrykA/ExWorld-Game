// Fill out your copyright notice in the Description page of Project Settings.


#include "MetaDataComponent.h"
#include "Net/UnrealNetwork.h"

UMetaDataComponent::UMetaDataComponent()
{
	SetIsReplicatedByDefault(true);
}

void UMetaDataComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UMetaDataComponent, MetaData);
	DOREPLIFETIME(UMetaDataComponent, bMetaDataAvailable);
}

void UMetaDataComponent::SetMetaData(FEXMetaData NewMetaData)
{
	MetaData = NewMetaData;
	bMetaDataAvailable = true;
	MetaDataUpdated.Broadcast(MetaData);
}

void UMetaDataComponent::OnRep_MetaData()
{
	MetaDataUpdated.Broadcast(MetaData);
}