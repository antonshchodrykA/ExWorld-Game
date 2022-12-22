// Copyright 2017-2019 marynate. All Rights Reserved.

#pragma once

#include "PivotToolUtil.h"

#include "Input/Reply.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Layout/SWrapBox.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Styling/SlateTypes.h"

#include "SPivotAlign.generated.h"

UENUM()
enum class EPivotAlignCoord : uint8
{
	Auto,
	Local,
	World
};

class SPivotAlign : public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SPivotAlign)
	{}
	SLATE_END_ARGS()

	SPivotAlign();

public:
	void Construct(const FArguments& InArgs);

	void SetWrapWidth(float InWrapWidth);

private:
	FText GetAlignActorsText() const;

	// Align - Loc
	FReply OnAlignSelectedActorsLocButtonClicked();
	FReply OnAlignSelectedActorsLocXButtonClicked();
	FReply OnAlignSelectedActorsLocYButtonClicked();
	FReply OnAlignSelectedActorsLocZButtonClicked();

	FReply OnAlignSelectedActorsLocMirrorXButtonClicked();
	FReply OnAlignSelectedActorsLocMirrorYButtonClicked();
	FReply OnAlignSelectedActorsLocMirrorZButtonClicked();

	void DoAlignSelectedActorsLoc(EAxis::Type InAxis, bool bMirrored = false) const;

	// Align - Rot
	FReply OnAlignSelectedActorsRotButtonClicked();
	FReply OnAlignSelectedActorsRotXButtonClicked();
	FReply OnAlignSelectedActorsRotYButtonClicked();
	FReply OnAlignSelectedActorsRotZButtonClicked();

private:
	TSharedPtr<SWrapBox> AlignBox;
	float WidthLastFrame;
};
