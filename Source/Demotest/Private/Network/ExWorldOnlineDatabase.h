
#pragma once

#include "ExWorldOnlineDatabase.generated.h"


UENUM(BlueprintType)
enum class ERoleType : uint8
{
	GuildMaster  UMETA(DisplayName = "GuildMaster"),
	ViceCaptain  UMETA(DisplayName = "ViceCaptain"),
	Council      UMETA(DisplayName = "Council"),
	Members      UMETA(DisplayName = "Members"),
	Recruits     UMETA(DisplayName = "Recruits"),
	PartyMembers UMETA(DisplayName = "PartyMembers")
};


USTRUCT(BlueprintType)
struct DEMOTEST_API FPlayerCurrency
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	int32 Gold;

	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	int32 Silver;

	
	int32 ItemCount; //Incase required
	int32 Bronze; //Incase required
	
};

USTRUCT(BlueprintType)
struct DEMOTEST_API FPlayerInventory_S
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	TArray<FString> ItemName;

};
USTRUCT(BlueprintType)
struct DEMOTEST_API FPlayerStats_S
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FString Strength;

	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FString Intelligence;

	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FString Dexterity;

	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FString Stamina;

	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FString Endurance;

	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FString Luck;
	
};

USTRUCT(BlueprintType)
struct DEMOTEST_API FCharacterCreationStats_S
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreationResult")
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreationResult")
	FString PlayerClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreationResult")
	FString Race;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreationResult")
	FString Gender;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreationResult")
	FString Face;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreationResult")
	FString Eyes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreationResult")
	FString BodyType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreationResult")
	FString SkinColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterCreationResult")
	FString Hair;
	
};
USTRUCT(BlueprintType)
struct DEMOTEST_API FPlayerLoginInfo_S                                       // S denotes for Struct
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FPlayerCurrency Currency;

	UPROPERTY(BlueprintReadOnly, Category="ExWorldPlayer Info")
	FString PlayerUniqueId;

	UPROPERTY(BlueprintReadOnly, Category="ExWorldPlayer Info")
	FString AccountCreationTime;

	UPROPERTY(BlueprintReadOnly, Category="ExWorldPlayer Info")
	FString LastLogin;

	UPROPERTY(BlueprintReadOnly, Category="ExWorldPlayer Info")
	FString AccountType;

	UPROPERTY(BlueprintReadOnly, Category="ExWorldPlayer Info")
	bool IsBanned;

	UPROPERTY(BlueprintReadOnly, Category="ExWorldPlayer Info")
	FString LoginPlatform;

	UPROPERTY(BlueprintReadOnly, Category="ExWorldPlayer Info")
	FString DisplayName;

};
USTRUCT(BlueprintType)
struct DEMOTEST_API FCharacterInfo_S                                       // S denotes for Struct
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	TArray<FString> CharacterName;

	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	TArray<FString> CharacterClass;
};

USTRUCT(BlueprintType)
struct DEMOTEST_API FExWorldPlayerInfo_S                                       // S denotes for Struct
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FPlayerLoginInfo_S PlayerLoginInfo;
	
	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FPlayerInventory_S PlayerInventory;

	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FPlayerStats_S PlayerStats;

	UPROPERTY(BlueprintReadWrite, Category="ExWorldPlayer Info")
	FCharacterCreationStats_S CharacterCreationStats;
	
};

USTRUCT(BlueprintType)
struct DEMOTEST_API FEXWCharacterAppearance_Info
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Gender;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Face;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Eyes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString BodyType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString SkinColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Hair;

};

USTRUCT(BlueprintType)
struct FEXWCharacterPosition_Info
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Transform")
		FVector Location;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Transform")
		FRotator Rotation;

};

USTRUCT(BlueprintType)
struct DEMOTEST_API FExWorldCharacterInfo_S
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString characterId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Race;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FString Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		int32 ProgressionLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FEXWCharacterAppearance_Info Appearance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FEXWCharacterPosition_Info Transform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FEXWCharacterStat_Info Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ExWorldPlayer Info")
		FEXWCharacterInventory_Info Inventory;

};

USTRUCT(BlueprintType)
struct DEMOTEST_API FGuildInfo_S
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite, Category="ExWorld Guild Info")
	FString GuildName;

	UPROPERTY(BlueprintReadOnly, Category="ExWorld Guild Info")
	FString GuildID;

	UPROPERTY(BlueprintReadOnly, Category="ExWorld Guild Info")
	FDateTime GuildCreatedTime;

	UPROPERTY(BlueprintReadOnly, Category="ExWorld Guild Info")
	TMap<FString,FString> GuildRoles;

	UPROPERTY(BlueprintReadOnly, Category="ExWorld Guild Info")
	FString AdminRoleId;

	UPROPERTY(BlueprintReadOnly, Category="ExWorld Guild Info")
	FString MemberRoleId;
};

USTRUCT(BlueprintType)
struct DEMOTEST_API FPartyInfo_S
{
	GENERATED_BODY()
	public:
	UPROPERTY(BlueprintReadWrite, Category="ExWorld Party Info")
	FString PartyName;

	UPROPERTY(BlueprintReadOnly, Category="ExWorld Party Info")
	FString PartyID;

	UPROPERTY(BlueprintReadOnly, Category="ExWorld Party Info")
	FDateTime PartyCreatedTime;

	UPROPERTY(BlueprintReadOnly, Category="ExWorld Party Info")
	TMap<FString,FString> PartyRoles;

};



