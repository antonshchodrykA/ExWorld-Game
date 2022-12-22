
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "CharacterData.generated.h"

USTRUCT(BlueprintType)
struct DEMOTEST_API FPlayerClassInfo : public FTableRowBase
{

	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere)
		int32 Index;

	UPROPERTY(EditAnywhere)
		FString ClassName;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> PlayerSpawnedClass;

};
