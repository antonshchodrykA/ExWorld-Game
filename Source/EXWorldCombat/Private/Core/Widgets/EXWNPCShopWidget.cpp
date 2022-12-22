// Fill out your copyright notice in the Description page of Project Settings.


#include "EXWNPCShopWidget.h"
#include "Core/EXWPlayerController.h"
#include "Library/EXWDataLibrary.h"

void UEXWNPCShopWidget::LoadShopData()
{
	Shop = UEXWDataLibrary::GetNPCShopByID(ShopID);
}

void UEXWNPCShopWidget::ExitShop()
{
	if (AEXWPlayerController* PC = GetOwningPlayer<AEXWPlayerController>())
	{
		PC->NPCShopWidget->RemoveFromParent();
		PC->NPCShopWidget = nullptr;
	}
}
