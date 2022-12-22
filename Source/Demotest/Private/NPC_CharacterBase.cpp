// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"


// Sets default values
ANPC_CharacterBase::ANPC_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetUp_AICharacter();
	

}

// Called when the game starts or when spawned
void ANPC_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ANPC_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

APatrolPoints* ANPC_CharacterBase::GetPatrolPoints_Refer()
{
	return PatrolPoints_Refer;
}


void ANPC_CharacterBase::NPC_MeleeAttack_Implementation()
{
	if (MeleeAttackMontage)
	{
		PlayAnimMontage(MeleeAttackMontage);
	}
}

const UAnimMontage* ANPC_CharacterBase::GetNPC_AnimMontage()
{
	return MeleeAttackMontage;
}

void ANPC_CharacterBase::Attack_Start()
{
	HitPoint1->SetCollisionProfileName("NoCollision");
	if (HitPoint2)
	{
		HitPoint2->SetCollisionProfileName("NoCollision");
	}
}

void ANPC_CharacterBase::Attack_End()
{
	HitPoint1->SetCollisionProfileName("NoCollision");
	if (HitPoint2)
	{
		HitPoint2->SetCollisionProfileName("NoCollision");
	}
}

void ANPC_CharacterBase::SetUp_AICharacter()
{
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
}

// TODO Modify this function for all derive classes to use
void ANPC_CharacterBase::AddHitPoints(int32 HitPointsCount, FName Collision1, FName Collision2)
{
	if (HitPointsCount == 1) {
		HitPoint1 = CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Point"));
		HitPoint1->SetCollisionProfileName(Collision1);
	}
	else if (HitPointsCount == 2)
	{
		 HitPoint1= CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Point Left"));
		 HitPoint2 = CreateDefaultSubobject<UBoxComponent>(TEXT("Hit Point Right"));

			HitPoint1->SetCollisionProfileName(Collision1);
			HitPoint2->SetCollisionProfileName(Collision2);

	}
}

