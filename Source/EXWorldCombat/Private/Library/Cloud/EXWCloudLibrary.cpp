// Fill out your copyright notice in the Description page of Project Settings.

#include "EXWCloudLibrary.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"


//TODO/ move online/cloud stuff from demotest to here


FEXWBaseSkeletalMeshes UEXWCloudLibrary::GetBaseCharaterSkeletalMeshes(EEXWRace Race, EEXWClass Class, EEXWGender Gender)
{
	FEXWBaseSkeletalMeshes Meshes;
	return Meshes;
}

EEXWRace UEXWCloudLibrary::StringToRaceEnum(FString race)
{

	return EEXWRace::R_Human;
}
