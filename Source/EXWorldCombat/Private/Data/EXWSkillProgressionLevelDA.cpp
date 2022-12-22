// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWSkillProgressionLevelDA.h"

UEXWSkillProgressionLevelDA::UEXWSkillProgressionLevelDA(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Experiences.Add(EEXWLifeSkillType::LS_Mining, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_Cooking, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_FireMaking, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_WoodCutting, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_Gathering, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_Fishing, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_Alchemy, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_Smiting, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_Crafting, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_Tailoring, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_Farming, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_Breeding, FEXWLifeSkillExperienceData());
	Experiences.Add(EEXWLifeSkillType::LS_BountyHunting, FEXWLifeSkillExperienceData());
}

int32 UEXWSkillProgressionLevelDA::GetExperience(const EEXWLifeSkillType LifeSkillType, const int32 Level)
{
	if (FEXWLifeSkillExperienceData* ExperienceData = Experiences.Find(LifeSkillType))
	{
		if (int32* ResultValue = ExperienceData->ExperiencePerLevel.Find(Level))
		{
			return *ResultValue;
		}
	}
	return -1;
}
