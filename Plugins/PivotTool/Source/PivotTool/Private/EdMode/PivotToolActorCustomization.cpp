// Copyright 2017-2019 marynate. All Rights Reserved.

#include "PivotToolActorCustomization.h"

#include "IDetailsView.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "IDetailPropertyRow.h"
#include "DetailWidgetRow.h"
#include "IDetailGroup.h"

#define LOCTEXT_NAMESPACE "PivotToolActorCustomization"

FPivotToolEdMode* FPivotToolActorCustomization::EditMode = nullptr;

TSharedRef<IDetailCustomization> FPivotToolActorCustomization::MakeInstance(class FPivotToolEdMode* InEditMode)
{
	auto Instance = MakeShareable(new FPivotToolActorCustomization());
	EditMode = InEditMode;
	return Instance;
}

void FPivotToolActorCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& ActorCategory = DetailBuilder.EditCategory("Actor", LOCTEXT("ActorCategoryName", "Actor"));
	ActorCategory.AddProperty(DetailBuilder.GetProperty(TEXT("PivotOffset")));
}

FPivotToolActorCustomization::FPivotToolActorCustomization()
{
}

#undef LOCTEXT_NAMESPACE