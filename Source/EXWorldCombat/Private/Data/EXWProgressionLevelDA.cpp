// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/EXWProgressionLevelDA.h"

int32 UEXWProgressionLevelDA::GetExperience(const int32 Level)
{
	if (ExperiencePerLevel.IsValidIndex(Level - 1))
	{
		return ExperiencePerLevel[Level -1];
	}
	return -1;
}
