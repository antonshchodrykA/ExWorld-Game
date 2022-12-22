// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "Widgets/Input/SButton.h"
#include "Engine/Texture2D.h"

class SAlphaButton : public SButton 
{
public:

	SAlphaButton();
	~SAlphaButton();

	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	
	virtual FReply OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent) override;

	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const override;

	virtual TSharedPtr<IToolTip> GetToolTip() override;

protected:
	UTexture2D* GetHitTexture(); 
	UTexture2D* LoadTexture(const FString& ImagePath);
private:
	UTexture2D* HitTexutre;
};
