// Copyright 2017-2019 marynate. All Rights Reserved.

#include "PivotToolUISettingCustomization.h"
#include "PivotToolUISetting.h"


#include "IDetailsView.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "IDetailPropertyRow.h"
#include "DetailWidgetRow.h"
#include "IDetailGroup.h"
#include "PropertyCustomizationHelpers.h"

#define LOCTEXT_NAMESPACE "PivotToolUISettingCustomization"

FPivotToolEdMode* FPivotToolUISettingCustomization::EditMode = nullptr;

TSharedRef<IDetailCustomization> FPivotToolUISettingCustomization::MakeInstance(class FPivotToolEdMode* InEditMode)
{
	auto Instance = MakeShareable(new FPivotToolUISettingCustomization());
	EditMode = InEditMode;
	return Instance;
}

void FPivotToolUISettingCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
}
#undef LOCTEXT_NAMESPACE