// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PatrolPoints.h"
#include "Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "NPC_CharacterBase.generated.h"

UCLASS()
class DEMOTEST_API ANPC_CharacterBase : public ACharacter 
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC_CharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	 APatrolPoints* GetPatrolPoints_Refer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld_NPC")
		bool NPC_IsMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld_NPC")
		bool IsAttackingChar;

	UFUNCTION(Reliable, NetMulticast)
	void NPC_MeleeAttack();

	void NPC_MeleeAttack_Implementation();

	const UAnimMontage* GetNPC_AnimMontage();

	


protected:
	void SetUp_AICharacter();
	virtual void AddHitPoints( int32 HitPointsCount , FName Collision1, FName Collision2);
	virtual void Attack_Start();
	virtual void Attack_End();
	//TODO Move this to tier 2 character
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld_NPC", meta = (AllowPrivateAccess = "true"))
		APatrolPoints* PatrolPoints_Refer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld_NPC", meta = (AllowPrivateAccess = "true"))
		UAnimMontage* MeleeAttackMontage;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld_NPC", meta = (AllowProtectedAccess = "true"))
		int32 NumberOfHitPoints = 2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld_NPC", meta = (AllowProtectedAccess = "true"))
	UBoxComponent* HitPoint1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EXWorld_NPC", meta = (AllowProtectedAccess = "true"))
	UBoxComponent* HitPoint2;

};
