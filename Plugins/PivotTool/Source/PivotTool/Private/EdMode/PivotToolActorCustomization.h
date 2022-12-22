// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "IDetailCustomization.h"

class IPropertyHandle;
class FPivotToolEdMode;

class FPivotToolActorCustomization : public IDetailCustomization
{
public:
	static TSharedRef<IDetailCustomization> MakeInstance(FPivotToolEdMode* InEditMode);

	void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

private:
	FPivotToolActorCustomization();

	static FPivotToolEdMode* EditMode;
};