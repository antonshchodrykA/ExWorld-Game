// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_Tier2Mob.h"
#include "Components/SkeletalMeshComponent.h"
#include "DemotestCharacter.h"
#include "ExWorldLog.h"


ANPC_Tier2Mob::ANPC_Tier2Mob(const FObjectInitializer& ObjectInitializer)
{
	AddHitPoints(2, "NoCollision", "NoCollision");

	if(HitPoint1 && HitPoint2)
	{
	
		HitPoint1->OnComponentBeginOverlap.AddDynamic(this, &ANPC_Tier2Mob::OnAttackBeginOverlap);
		HitPoint1->OnComponentEndOverlap.AddDynamic(this, &ANPC_Tier2Mob::OnAttackEndOverlap);
		/*HitPoint2->OnComponentBeginOverlap.AddDynamic(this, &ANPC_Tier2Mob::OnAttackBeginOverlap);
		HitPoint2->OnComponentEndOverlap.AddDynamic(this, &ANPC_Tier2Mob::OnAttackEndOverlap);
		*/
	}
}

void ANPC_Tier2Mob::BeginPlay()
{
	Super::BeginPlay();

	if (HitPoint1 && HitPoint2)
	{
		const FAttachmentTransformRules AttachmentR(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, false);
		HitPoint1->AttachToComponent(GetMesh(), AttachmentR, "PunchLeft");
		HitPoint2->AttachToComponent(GetMesh(), AttachmentR, "PunchRight");
	}
}

void ANPC_Tier2Mob::Attack_Start()
{
	HitPoint1->SetCollisionProfileName("EnemyAttack");
	HitPoint1->SetNotifyRigidBodyCollision(true);
	HitPoint2->SetCollisionProfileName("EnemyAttack");
	HitPoint2->SetNotifyRigidBodyCollision(true);
}

void ANPC_Tier2Mob::Attack_End()
{
	HitPoint1->SetCollisionProfileName("NoCollision");
	HitPoint1->SetNotifyRigidBodyCollision(false);
	HitPoint2->SetCollisionProfileName("NoCollision");
	HitPoint2->SetNotifyRigidBodyCollision(false);
}

void ANPC_Tier2Mob::OnAttackBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int OtherBodyIndex, bool bSweep, const FHitResult& SweepResult)
{
	EXWORLDLOG("DETECTEDDDDD!!")
		if(ADemotestCharacter* MainCharacter = Cast<ADemotestCharacter>(OtherActor))
		{
			float NewHealth = MainCharacter->PlayerHealth - 10.0f;
			MainCharacter->PlayerHealth = NewHealth;
			MainCharacter->SetHealth(NewHealth);
		}
}

void ANPC_Tier2Mob::OnAttackEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int OtherBodyIndex)
{
}

