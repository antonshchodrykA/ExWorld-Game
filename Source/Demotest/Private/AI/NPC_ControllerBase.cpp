// Fill out your copyright notice in the Description page of Project Settings.


//#include "NPC_ControllerBase.h"
#include "..\..\Public\AI\NPC_ControllerBase.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "NPC_CharacterBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "DemotestCharacter.h"
#include "..\..\Public\AI\NPCBlackboardKeys.h"
#include "Perception//AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
#include "ExWorldLog.h"



ANPC_ControllerBase::ANPC_ControllerBase(const FObjectInitializer& ObjectInitializer)
{

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BehaviorTreeEditor(TEXT("BehaviorTree'/Game/NPC/NPC_BehaviourTable.NPC_BehaviourTable'"));
	if(BehaviorTreeEditor.Succeeded())
	{
		NPCBehaviorTree = BehaviorTreeEditor.Object;
	}

	NPCBehaviorTree_Component = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("NPC_BehaviorTreeComponent"));
	NPC_Blackboard = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("NPC_BlackboardComponent"));
	NPC_Senses_Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight_Sense_Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception_Component")));
	Senses_OnSetup(500.0f,50.0f,90.0f,5.0f,900.0f,true, true,true);


}
void ANPC_ControllerBase::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(NPCBehaviorTree);
	NPCBehaviorTree_Component->StartTree(*NPCBehaviorTree);

}

void ANPC_ControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(NPC_Blackboard)
	{
		NPC_Blackboard->InitializeBlackboard(*NPCBehaviorTree->BlackboardAsset);
	}

}

void ANPC_ControllerBase::OnUnPossess()
{
}

void ANPC_ControllerBase::SlowDownTheNPC()
{
	ANPC_CharacterBase* NPCChar = Cast<ANPC_CharacterBase>(this->GetCharacter());
	if(NPCChar)
	{
		NPCChar->GetCharacterMovement()->MaxWalkSpeed = 150.0f;
		NPCChar->NPC_IsMoving = false;
	}
}

UBlackboardComponent* ANPC_ControllerBase::GetBlackboardComponent() const
{
	return NPC_Blackboard;
}

void ANPC_ControllerBase::Senses_OnUpdated(const TArray<AActor*>& UpdatedActors)
{

}

void ANPC_ControllerBase::Senses_OnSetup(float SightRadius, float LooseSightRadius, float VisionAngle, float MaxAge, float LastSeenRange, bool DetectEnemies, bool DetectFriends, bool DetectNeutrals)
{
	
	NPC_Senses_Sight->SightRadius = SightRadius;
	NPC_Senses_Sight->LoseSightRadius = NPC_Senses_Sight->SightRadius + LooseSightRadius;
	NPC_Senses_Sight->PeripheralVisionAngleDegrees = VisionAngle;
	NPC_Senses_Sight->SetMaxAge(MaxAge);
	NPC_Senses_Sight->AutoSuccessRangeFromLastSeenLocation = LastSeenRange;
	NPC_Senses_Sight->DetectionByAffiliation.bDetectEnemies = DetectEnemies;
	NPC_Senses_Sight->DetectionByAffiliation.bDetectFriendlies = DetectFriends;
	NPC_Senses_Sight->DetectionByAffiliation.bDetectNeutrals = DetectNeutrals;
	GetPerceptionComponent()->SetDominantSense(*NPC_Senses_Sight->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ANPC_ControllerBase::Senses_OnTargetUpdated);
	GetPerceptionComponent()->ConfigureSense(*NPC_Senses_Sight);


}

void ANPC_ControllerBase::Senses_OnTargetUpdated(AActor* Target, const FAIStimulus Stimulus)
{
	//ANPC_CharacterBase* NPCChar = Cast<ANPC_CharacterBase>(this->GetCharacter());
	if (auto const Character = Cast<ADemotestCharacter>(Target)) {
		GetBlackboardComponent()->SetValueAsBool(ExWorldNPC_bbkeys::player_detected, Stimulus.WasSuccessfullySensed());
		EXWORLDLOG("Char detected")
	}
	}

