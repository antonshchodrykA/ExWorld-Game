// Fill out your copyright notice in the Description page of Project Settings.

#include "EXWItem.h"

// Components dependencies
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/BillboardComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Niagara/Public/NiagaraComponent.h"


// Engine
#include "Net/UnrealNetwork.h"

// Inventory dependencies
#include "Library/Inventory/EXWInventoryLibrary.h"
#include "Core/EXWCharacter.h"

// Sets default values
AEXWItem::AEXWItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetReplicates(true);

	CollisionComp = CreateDefaultSubobject<UBoxComponent>("Root");
	if (CollisionComp)
	{
		SetRootComponent(CollisionComp);
		CollisionComp->SetBoxExtent(FVector(15.f));		
		// Overlap everything and block dynamic and static objects
		CollisionComp->SetCollisionObjectType(ECC_GameTraceChannel3);
		CollisionComp->SetGenerateOverlapEvents(true);
		CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
		CollisionComp->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
		CollisionComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
		CollisionComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
		CollisionComp->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
		// Physics setup
		CollisionComp->SetSimulatePhysics(true);
		CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	if (Mesh)
	{
		Mesh->SetupAttachment(CollisionComp);
		Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
		Mesh->SetIsReplicated(true);
	}
	Billboard = CreateDefaultSubobject<UBillboardComponent>("Billboard");
	if (Billboard)
	{
		Billboard->SetupAttachment(CollisionComp);
		Billboard->SetRelativeScale3D_Direct(FVector(.1f));
		Billboard->SetHiddenInGame(false);
		//Billboard->bIsScreenSizeScaled = true;
	}

	ParticleSystemComp = CreateDefaultSubobject<UParticleSystemComponent>("ParticleSystemComp");
	if (ParticleSystemComp)
	{
		ParticleSystemComp->SetupAttachment(CollisionComp);
	}

	NiagaraComp = CreateDefaultSubobject<UNiagaraComponent>("NiagaraComp");
	if (NiagaraComp)
	{
		NiagaraComp->SetupAttachment(CollisionComp);
	}

	bIsLootable = false;
	AvailableInteractionTypes = {EEXWInteractionType::IT_PickItem};
	InteractionMaxDistance = 150.f;
}

// Called when the game starts or when spawned
void AEXWItem::BeginPlay()
{
	Super::BeginPlay();
	StartTimers();
}

void AEXWItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AEXWItem, ItemID);
	DOREPLIFETIME(AEXWItem, Count);
	DOREPLIFETIME(AEXWItem, bIsLootable);
}

// Called every frame
void AEXWItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEXWItem::SetMesh(UStaticMesh* NewMesh)
{
	if (Mesh)
	{
		Mesh->SetStaticMesh(NewMesh);
	}
}

void AEXWItem::SetItemData(const FName NewItemID, const int32 NewCount /*= 1*/, const bool bForceLootable)
{
	ItemID = NewItemID;
	Count = NewCount;
	bIsLootable = bForceLootable;
	Multicast_UpdateItemData();
}

void AEXWItem::Server_SetItemData_Implementation(const FName NewItemID, const int32 NewCount /*= 1*/, const bool bForceLootable)
{
	Multicast_SetItemData(NewItemID, NewCount, bForceLootable);
}

void AEXWItem::Multicast_SetItemData_Implementation(const FName NewItemID, const int32 NewCount /*= 1*/, const bool bForceLootable)
{
	SetItemData(NewItemID, NewCount, bForceLootable);
}

void AEXWItem::Server_SetCount_Implementation(const int32 NewCount /*= 1*/)
{
	Count = NewCount;
}

void AEXWItem::Server_Destroy_Implementation()
{
	Destroy(true);
}

void AEXWItem::Server_SetIsLootable_Implementation(const bool bNewIsLootable)
{
	bIsLootable = bNewIsLootable;
}

void AEXWItem::UpdateItemData()
{
	FEXWItemData Item;
	if (UEXWInventoryLibrary::GetItemData(ItemID, Item))
	{
		SetMesh(Item.WorldMesh);
		if (CollisionComp)
		{
			CollisionComp->SetBoxExtent(Item.WorldCollisionSize);
		}
		if (Billboard)
		{
			if (Item.bUseBillboard)
			{
				Billboard->SetSprite((Item.WorldIconReplacement) ? Item.WorldIconReplacement : Item.Icon);
				Billboard->SetRelativeScale3D_Direct(Item.BillboardSize);
			}
			else
			{
				Billboard->SetSprite(nullptr);
				Billboard->SetHiddenInGame(true);
			}
		}
		if (Item.ParticleSystem && ParticleSystemComp)
		{
			ParticleSystemComp->SetTemplate(Item.ParticleSystem);
			ParticleSystemComp->Activate(true);
		}
		if (Item.NiagaraSystem && NiagaraComp)
		{
			NiagaraComp->SetAsset(Item.NiagaraSystem);
			NiagaraComp->Activate(true);
		}
	}
}

void AEXWItem::Multicast_UpdateItemData_Implementation()
{
	UpdateItemData();
}

void AEXWItem::Server_EnablePhysics_Implementation(const bool bNewCollisionState)
{
	Multicast_EnablePhysics(bNewCollisionState);
}

void AEXWItem::Multicast_EnablePhysics_Implementation(const bool bNewCollisionState)
{
	if (bNewCollisionState)
	{
		CollisionComp->SetSimulatePhysics(true);
		CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		CollisionComp->SetSimulatePhysics(false);
		CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
}

void AEXWItem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UpdateItemData();
}

void AEXWItem::OnReceiveInteraction(AEXWCharacter* SourceCharacter, EEXWInteractionType InteractionType)
{
	if (bIsLootable || SourceCharacter == GetOwner())
	{
		if (InteractionType == EEXWInteractionType::IT_PickItem)
		{
			int32 Rest = 0;
			if (SourceCharacter->TryAddingItemsToInventory(ItemID, Count, Rest))
			{
				if (Rest == 0)
				{
					Server_Destroy();
				}
				else
				{
					Server_SetCount(Rest);
				}
			}
		}
	}
}

void AEXWItem::OnReceiveClick(AEXWCharacter* SourceCharacter)
{
	
}

UWidgetComponent* AEXWItem::GetInteractionWidgetComponent()
{
	return MakeWeakObjectPtr<UWidgetComponent>(nullptr).Get();
}

void AEXWItem::SetInteractionWidgetVisibility(const bool bNewVisibility /*= true*/)
{
	if (UWidgetComponent* CurrWidgetComp = GetInteractionWidgetComponent())
	{
		CurrWidgetComp->SetVisibility(bNewVisibility);
	}
}

void AEXWItem::StartTimers()
{
	if (HasAuthority())
	{
		if (UWorld* World = GetWorld())
		{
			FEXWItemData Item;
			if (UEXWInventoryLibrary::GetItemData(ItemID, Item))
			{
				// Destroy timer
				World->GetTimerManager().SetTimer(DestroyTimer, this, &AEXWItem::Server_Destroy, .1f, false, Item.DestroyTime);
				// Loot timer
				if (!bIsLootable)
				{
					FTimerDelegate LootableTimerDelegate;
					LootableTimerDelegate.BindUFunction(this, "Server_SetIsLootable", true);
					World->GetTimerManager().SetTimer(LootTimer, LootableTimerDelegate, .1f, false, Item.LootTime);
				}
			}
			FTimerDelegate PhysicsDelegate;
			PhysicsDelegate.BindLambda([&]() {
					Multicast_EnablePhysics(false);
			});
			World->GetTimerManager().SetTimer(PhysicsTimer, PhysicsDelegate, .1f, false, 1.f);
		}
	}
}