// Fill out your copyright notice in the Description page of Project Settings.


#include "CCLoadingScreen.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACCLoadingScreen::ACCLoadingScreen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
}

// Called when the game starts or when spawned
void ACCLoadingScreen::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void ACCLoadingScreen::LoadCreationMap()
{
	LoadingScreenFuncs->HideEWLoadingScreen(this);

	if (CharacterCreationLoadingScreen)
	{
		CCWidgetReference = CreateWidget<UUserWidget>(GetGameInstance(), CharacterCreationLoadingScreen);
		if (CCWidgetReference)
		{
			LoadingScreenFuncs->SetTargetPackageForLoadingProgress(this, LevelToLoadIn);
			LoadingScreenFuncs->SetLoadingScreenWidget(CCWidgetReference);
			LoadingScreenFuncs->ShowEWLoadingScreen(this);
			UGameplayStatics::OpenLevel(this, LevelToLoadIn, false);

		}

	}
}
// Called every frame


