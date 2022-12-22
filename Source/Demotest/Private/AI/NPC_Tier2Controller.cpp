// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Tier2Controller.h"
#include "BehaviorTree/BehaviorTree.h"
#include "ExWorldLog.h"
#include "NPC_CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "..\..\Public\AI\NPCBlackboardKeys.h"
#include "DemotestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANPC_Tier2Controller::ANPC_Tier2Controller(const FObjectInitializer& ObjectInitializer)
{
	/*static ConstructorHelpers::FObjectFinder<UBehaviorTree> BehaviorTreeEditor(TEXT("BehaviorTree'/Game/NPC/Tier2Mob/Scripts/NPC_Tier2_BehaviorTree.NPC_Tier2_BehaviorTree'"));
	if (BehaviorTreeEditor.Succeeded())
	{
		NPCBehaviorTree = BehaviorTreeEditor.Object;
		UE_LOG(LogTemp,Warning,TEXT("NPC TIER 2 Behavior tree detected"))
	}*/
	Senses_OnSetup(600.0f,25.0f,120.0f,5.0f,520.0f,true,true,true);

}



void ANPC_Tier2Controller::Senses_OnTargetUpdated(AActor* Target, const FAIStimulus Stimulus)
{
	
		
		if (auto const Character = Cast<ADemotestCharacter>(Target)) {
			GetBlackboardComponent()->SetValueAsBool(ExWorldNPC_bbkeys::player_detected, Stimulus.WasSuccessfullySensed());
			
			EXWORLDLOG("Char detected")
		}
	}

