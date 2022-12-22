// Fill out your copyright notice in the Description page of Project Settings.


#include "EXW_BTService_LookForTarget.h"
// BT
#include "BehaviorTree/BTFunctionLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"

// Dependencies
#include "Library/EXWDataLibrary.h"
#include "Core/Ai/EXWAiController.h"
#include "Perception/AIPerceptionComponent.h"

void UEXW_BTService_LookForTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	
	if (FBTNodeBPImplementationHelper::AISpecific)
	{
		if (AEXWCharacter* ControlledCharacter = GetAiCharacter(&OwnerComp))
		{
			if (AEXWAiController* Controller = GetAiController(&OwnerComp))
			{
				TArray<AActor*> DetectedActors;
				Controller->GetPerceptionComponent()->GetCurrentlyPerceivedActors(Controller->GetPerceptionComponent()->GetDominantSense(), DetectedActors);
				TArray<AActor*> DetectedActors_FactionFilter;
				TArray<AActor*> DetectedActors_DeathFilter;

				// Get values from the BB
				EEXWTargetFaction TargetFactionType = static_cast<EEXWTargetFaction>(OwnerComp.GetBlackboardComponent()->GetValueAsEnum(TargetFactionTypeKey.SelectedKeyName));
				bool bCanTargetDead = OwnerComp.GetBlackboardComponent()->GetValueAsBool(CanTargetDeadKey.SelectedKeyName);

				// Filter by faction
				UEXWDataLibrary::FilterByFaction(DetectedActors_FactionFilter, ControlledCharacter, DetectedActors, TargetFactionType);

				// Filter by death state
				UEXWDataLibrary::FilterByDeathState(DetectedActors_DeathFilter, DetectedActors_FactionFilter, bCanTargetDead);

				if (AActor* TargetTemp = Controller->ChooseTarget(DetectedActors_DeathFilter))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(TargetKey.SelectedKeyName, TargetTemp);
				}
				else
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsObject(TargetKey.SelectedKeyName, nullptr);
				}
			}
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
