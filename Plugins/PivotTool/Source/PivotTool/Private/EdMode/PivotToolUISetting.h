// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "PivotToolUISetting.generated.h"

UCLASS()
class UPivotToolUISetting : public UObject 
{

	GENERATED_UCLASS_BODY()
	
public:

public:
	void Load();
	void Save();
	void Reset();

	void SetParent(class FPivotToolEdMode* EditMode);

private:
	class FPivotToolEdMode* ParentMode;
};
