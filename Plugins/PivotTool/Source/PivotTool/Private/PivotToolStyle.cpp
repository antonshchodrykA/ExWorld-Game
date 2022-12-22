// Copyright 2017-2019 marynate. All Rights Reserved.

#include "PivotToolStyle.h"

#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateTypes.h"
#include "Framework/Application/SlateApplication.h"

#define IMAGE_BRUSH( RelativePath, ... ) FSlateImageBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BOX_BRUSH( RelativePath, ... ) FSlateBoxBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define BORDER_BRUSH( RelativePath, ... ) FSlateBorderBrush( Style->RootToContentDir( RelativePath, TEXT(".png") ), __VA_ARGS__ )
#define DEFAULT_FONT(...) FCoreStyle::GetDefaultFontStyle(__VA_ARGS__)
#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )
#define OTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToContentDir( RelativePath, TEXT(".otf") ), __VA_ARGS__ )
#define CORE_TTF_FONT( RelativePath, ... ) FSlateFontInfo( Style->RootToCoreContentDir( RelativePath, TEXT(".ttf") ), __VA_ARGS__ )

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon40x40(40.0f, 40.0f);
const FVector2D Image30x30(30.0f, 30.0f);
const FVector2D Image160x160(160.0f, 160.0f);
const FVector2D Image200x200(200.0f, 200.0f); 

#define HOVER_COLOR(Color) Color + FLinearColor(0.05f, 0.05f, 0.05f, 0.f)
#define PRESS_COLOR( Color ) Color + FLinearColor(0.1f, 0.1f, 0.1f, 0.f)

TSharedPtr< FSlateStyleSet > FPivotToolStyle::StyleInstance = NULL;

void FPivotToolStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FPivotToolStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FPivotToolStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("PivotToolStyle"));
	return StyleSetName;
}

void FPivotToolStyle::SetupStyles(FSlateStyleSet* Style)
{
	// Colors
	const FLinearColor ColorWhite(1.f, 1.f, 1.f, 1.f);
	const FLinearColor ColorBlack(0.f, 0.f, 0.f, 1.f);
	const FLinearColor ColorGray(0.5f, 0.5f, 0.5f, 1.0f);
	const FLinearColor ColorDarkerGray(0.3f, 0.3f, 0.3f, 1.0f);
	const FLinearColor ColorDarkGray(0.05f, 0.05f, 0.05f, 1.0f);
	const FLinearColor ColorRed(0.48195f, 0.02899f, 0.19752f);
	const FLinearColor ColorGreen(0.02899f, 0.48195f, 0.19752f);
	const FLinearColor ColorBlue(0.02899f, 0.19752f, 0.48195f);
	const FLinearColor ColorYellow(0.55f, 0.52f, 0.107f);

	const FLinearColor ColorPivotBoundCenter(1.f, 1.f, 1.f, 1.f);
	const FLinearColor ColorPivotCenter(1.f, 1.f, 1.f, .6f);
	const FLinearColor ColorPivotCorner(1.f, 1.f, 1.f, 1.f);
	const FLinearColor ColorPivotEdge(1.f, 1.f, 1.f, 1.f);

	const FLinearColor SelectionColor(0.81f, 0.378f, 0.f);

	const FLinearColor ColorX(0.594f, 0.0197f, 0.0f);
	const FLinearColor ColorY(0.1349f, 0.3959f, 0.0f);
	const FLinearColor ColorZ(0.0251f, 0.207f, 0.85f);

	// TextStyle
	{
		const FTextBlockStyle DefaultNormalTextStyle = FCoreStyle::Get().GetWidgetStyle<FTextBlockStyle>("NormalText");

		Style->Set("PivotTool.NormalText.Red", FTextBlockStyle()
			.SetFont(TTF_FONT("Fonts/DroidSansMono", 8))
			.SetColorAndOpacity(FLinearColor(1.0f, .0f, .0f))
			.SetHighlightColor(FLinearColor(1.0f, .0f, .0f)));

		Style->Set("PivotTool.NormalText.Green", FTextBlockStyle()
			.SetFont(TTF_FONT("Fonts/DroidSansMono", 8))
			.SetColorAndOpacity(FLinearColor(.0f, 1.0f, .0f))
			.SetHighlightColor(FLinearColor(.0f, 1.0f, .0f)));

		Style->Set("PivotTool.NormalText.Blue", FTextBlockStyle()
			.SetFont(TTF_FONT("Fonts/DroidSansMono", 8))
			.SetColorAndOpacity(FLinearColor(.0f, .0f, 1.0f))
			.SetHighlightColor(FLinearColor(.0f, .0f, 1.0f)));

		Style->Set("PivotTool.ButtonText.Roboto", FTextBlockStyle()
			.SetFont(TTF_FONT("Fonts/Roboto-Regular", 8))
			.SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f))
			.SetHighlightColor(FLinearColor(1.0f, 1.0f, 1.0f)));

		Style->Set("PivotTool.ButtonText", FTextBlockStyle(DefaultNormalTextStyle)
			.SetFontSize(8)
			.SetColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f))
			.SetHighlightColor(FLinearColor(1.0f, 1.0f, 1.0f)));

		Style->Set("PivotTool.ButtonText.Black", FTextBlockStyle()
			.SetFont(TTF_FONT("Fonts/DroidSansMono", 8))
			.SetColorAndOpacity(FLinearColor(0.f, 0.f, 0.f))
			.SetHighlightColor(FLinearColor(0.f, 0.f, 0.f))
			);

		Style->Set("PivotTool.CheckboxText", FTextBlockStyle(DefaultNormalTextStyle)
			.SetColorAndOpacity(ColorWhite)
			.SetFontSize(8));

		Style->Set("PivotTool.CheckboxText.Small", FTextBlockStyle(DefaultNormalTextStyle)
			.SetColorAndOpacity(ColorWhite)
			.SetFontSize(7));

		Style->Set("PivotTool.CheckboxText.Gray", FTextBlockStyle(DefaultNormalTextStyle)
			.SetColorAndOpacity(ColorGray)
			.SetFontSize(8));

		Style->Set("PivotTool.VersionText", FTextBlockStyle(DefaultNormalTextStyle)
			.SetColorAndOpacity(ColorDarkerGray)
			.SetFontSize(8));
	}

	// Icons
	{
		Style->Set("PivotTool.OpenPivotTool", new IMAGE_BRUSH(TEXT("Images/icon_PivotTool_dark_40x"), Icon40x40));
		Style->Set("PivotTool.OpenPivotTool.Small", new IMAGE_BRUSH(TEXT("Images/icon_PivotTool_dark_40x"), Icon20x20));
		Style->Set("PivotTool.OpenPivotTool.Selected", new IMAGE_BRUSH(TEXT("Images/icon_PivotTool_dark_selected_40x"), Icon40x40));
		Style->Set("PivotTool.PivotToolMode", new IMAGE_BRUSH(TEXT("Images/icon_PivotTool_dark_40x"), Icon40x40));
		Style->Set("PivotTool.PivotToolMode.Small", new IMAGE_BRUSH(TEXT("Images/icon_PivotTool_dark_40x"), Icon20x20));
	}

	// Images
	{
		Style->Set("PivotTool.PivotPresetBackground.BoundCenter", new IMAGE_BRUSH(TEXT("Images/bg_cube_center"), Image160x160));
		Style->Set("PivotTool.PivotPresetBackground.Center", new IMAGE_BRUSH(TEXT("Images/bg_cube_corner"), Image160x160));
		Style->Set("PivotTool.PivotPresetBackground.Corner", new IMAGE_BRUSH(TEXT("Images/bg_cube_corner"), Image160x160));
		Style->Set("PivotTool.PivotPresetBackground.Edge", new IMAGE_BRUSH(TEXT("Images/bg_cube_edge"), Image160x160));
		Style->Set("PivotTool.DividingLine", new IMAGE_BRUSH(TEXT("Images/dividing_line"), FVector2D(1, 19))); 
		Style->Set("PivotTool.PivotToolText", new IMAGE_BRUSH(TEXT("Images/pivot_tool_text"), FVector2D(90, 8)));
	}

	// Button Style
	{
		Style->Set("PivotTool.ButtonStyle.Normal", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_normal", FMargin(4 / 16.0f), ColorGray))
			.SetHovered(BOX_BRUSH("Images/button_normal", FMargin(4 / 16.0f), HOVER_COLOR(ColorGray)))
			.SetPressed(BOX_BRUSH("Images/button_normal", FMargin(4 / 16.0f), PRESS_COLOR(ColorGray))));

		Style->Set("PivotTool.ButtonStyle.Normal.DarkGray", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_normal", FMargin(4 / 16.0f), ColorDarkGray))
			.SetHovered(BOX_BRUSH("Images/button_normal", FMargin(4 / 16.0f), HOVER_COLOR(ColorDarkGray)))
			.SetPressed(BOX_BRUSH("Images/button_normal", FMargin(4 / 16.0f), PRESS_COLOR(ColorDarkGray))));

		Style->Set("PivotTool.ButtonStyle.Normal.Black", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_normal", FMargin(4 / 16.0f), ColorBlack))
			.SetHovered(BOX_BRUSH("Images/button_normal", FMargin(4 / 16.0f), HOVER_COLOR(ColorBlack)))
			.SetPressed(BOX_BRUSH("Images/button_normal", FMargin(4 / 16.0f), PRESS_COLOR(ColorBlack))));

		Style->Set("PivotTool.ButtonStyle.Round.Gray", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), ColorGray))
			.SetHovered(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), HOVER_COLOR(ColorGray)))
			.SetPressed(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), PRESS_COLOR(ColorGray))));

		Style->Set("PivotTool.ButtonStyle.Round.DarkGray", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), ColorDarkGray))
			.SetHovered(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), HOVER_COLOR(ColorDarkGray)))
			.SetPressed(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), PRESS_COLOR(ColorDarkGray))));

		Style->Set("PivotTool.ButtonStyle.Round.Black", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), ColorBlack))
			.SetHovered(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), HOVER_COLOR(ColorBlack)))
			.SetPressed(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), PRESS_COLOR(ColorBlack))));

		Style->Set("PivotTool.ButtonStyle.Round.Red", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), ColorRed))
			.SetHovered(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), HOVER_COLOR(ColorRed)))
			.SetPressed(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), PRESS_COLOR(ColorRed))));

		Style->Set("PivotTool.ButtonStyle.Round.ColorX", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), ColorX))
			.SetHovered(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), HOVER_COLOR(ColorX)))
			.SetPressed(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), PRESS_COLOR(ColorX))));

		Style->Set("PivotTool.ButtonStyle.Round.ColorY", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), ColorY))
			.SetHovered(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), HOVER_COLOR(ColorY)))
			.SetPressed(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), PRESS_COLOR(ColorY))));

		Style->Set("PivotTool.ButtonStyle.Round.ColorZ", FButtonStyle()
			.SetNormal(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), ColorZ))
			.SetHovered(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), HOVER_COLOR(ColorZ)))
			.SetPressed(BOX_BRUSH("Images/button_small_round", FMargin(7 / 16.0f), PRESS_COLOR(ColorZ))));

		SetupFlatButtonStyles(Style, "PivotTool.ButtonStyle.Flat", ColorDarkGray);
		SetupFlatButtonStyles(Style, "PivotTool.ButtonStyle.Flat.Red", ColorRed);
		SetupFlatButtonStyles(Style, "PivotTool.ButtonStyle.Flat.Green", ColorGreen);
		SetupFlatButtonStyles(Style, "PivotTool.ButtonStyle.Flat.Blue", ColorBlue);
		SetupFlatButtonStyles(Style, "PivotTool.ButtonStyle.Flat.Yellow", ColorYellow);

		Style->Set("PivotTool.ButtonStyle.PivotBoundCenter", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_bound_center", Image30x30, ColorPivotBoundCenter))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_corner_h", Image30x30, ColorPivotBoundCenter))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_corner_h", Image30x30, PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotCenterFront", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_center_front", Image30x30, ColorPivotCenter * 0.65))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_center_front_h", Image30x30, ColorPivotCenter))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_center_front_h", Image30x30, PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotCenterBack", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_center_front", Image30x30, ColorPivotCenter))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_center_front_h", Image30x30, ColorPivotCenter))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_center_front_h", Image30x30, PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotCenterLeft", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_center_left", Image30x30, ColorPivotCenter * 0.65))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_center_left_h", Image30x30, ColorPivotCenter))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_center_left_h", Image30x30, PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotCenterRight", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_center_left", Image30x30, ColorPivotCenter))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_center_left_h", Image30x30, ColorPivotCenter))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_center_left_h", Image30x30, PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotCenterTop", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_center_top", Image30x30, ColorPivotCenter))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_center_top_h", Image30x30, ColorPivotCenter))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_center_top_h", Image30x30, PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotCenterBottom", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_center_top", Image30x30, ColorPivotCenter * 0.65))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_center_top_h", Image30x30, ColorPivotCenter))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_center_top_h", Image30x30, PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotCorner", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_corner", Image30x30, ColorPivotCorner * 0.5))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_corner_h", Image30x30, ColorPivotCorner))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_corner_h", Image30x30, PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Top1", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_top1", FVector2D(52, 40), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_top1h", FVector2D(52, 40), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_top1h", FVector2D(52, 40), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Top2", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_top2", FVector2D(84, 22), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_top2h", FVector2D(84, 22), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_top2h", FVector2D(84, 22), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Top3", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_top3", FVector2D(46, 42), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_top3h", FVector2D(46, 42), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_top3h", FVector2D(46, 42), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Top4", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_top4", FVector2D(90, 26), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_top4h", FVector2D(90, 26), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_top4h", FVector2D(90, 26), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Mid1", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_mid1", FVector2D(16, 88), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_mid1h", FVector2D(16, 88), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_mid1h", FVector2D(16, 88), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Mid2", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_mid2", FVector2D(18, 82), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_mid2h", FVector2D(18, 82), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_mid2h", FVector2D(18, 82), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Mid3", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_mid3", FVector2D(16, 86), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_mid3h", FVector2D(16, 86), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_mid3h", FVector2D(16, 86), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Mid4", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_mid4", FVector2D(18, 92), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_mid4h", FVector2D(18, 92), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_mid4h", FVector2D(18, 92), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Bottom1", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_bottom1", FVector2D(52, 44), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_bottom1h", FVector2D(52, 44), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_bottom1h", FVector2D(44, 44), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Bottom2", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_bottom2", FVector2D(84, 26), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_bottom2h", FVector2D(84, 26), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_bottom2h", FVector2D(84, 26), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Bottom3", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_bottom3", FVector2D(46, 48), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_bottom3h", FVector2D(46, 48), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_bottom3h", FVector2D(46, 48), PRESS_COLOR(SelectionColor))));

		Style->Set("PivotTool.ButtonStyle.PivotEdge.Bottom4", FButtonStyle()
			.SetNormal(IMAGE_BRUSH("Images/button_pivot_edge_bottom4", FVector2D(90, 30), ColorPivotEdge))
			.SetHovered(IMAGE_BRUSH("Images/button_pivot_edge_bottom4h", FVector2D(90, 30), ColorPivotEdge))
			.SetPressed(IMAGE_BRUSH("Images/button_pivot_edge_bottom4h", FVector2D(90, 30), PRESS_COLOR(SelectionColor))));

	}

	// Checkbox Style
	{
		// @SlateEditorStyle
		const FString SmallRoundedButton(TEXT("Images/button_small_round"));
		const FString SmallRoundedButtonStart(TEXT("Images/button_small_round_left"));
		const FString SmallRoundedButtonMiddle(TEXT("Images/button_small_round_center"));
		const FString SmallRoundedButtonEnd(TEXT("Images/button_small_round_right"));

		const FLinearColor NormalColor(0.15, 0.15, 0.15, 1);
		const FLinearColor SelectionColor_Pressed = SelectionColor * 0.75f;

		Style->Set("PivotTool.ToggleButton", FCheckBoxStyle()
			.SetCheckBoxType(ESlateCheckBoxType::ToggleButton)
			.SetUncheckedImage(BOX_BRUSH(*SmallRoundedButton, FMargin(7.f / 16.f), NormalColor))
			.SetUncheckedPressedImage(BOX_BRUSH(*SmallRoundedButton, FMargin(7.f / 16.f), SelectionColor_Pressed))
			.SetUncheckedHoveredImage(BOX_BRUSH(*SmallRoundedButton, FMargin(7.f / 16.f), SelectionColor_Pressed))
			.SetCheckedHoveredImage(BOX_BRUSH(*SmallRoundedButton, FMargin(7.f / 16.f), SelectionColor))
			.SetCheckedPressedImage(BOX_BRUSH(*SmallRoundedButton, FMargin(7.f / 16.f), SelectionColor))
			.SetCheckedImage(BOX_BRUSH(*SmallRoundedButton, FMargin(7.f / 16.f), SelectionColor)));

		Style->Set("PivotTool.ToggleButton.Start", FCheckBoxStyle()
			.SetCheckBoxType(ESlateCheckBoxType::ToggleButton)
			.SetUncheckedImage(BOX_BRUSH(*SmallRoundedButtonStart, FMargin(7.f / 16.f), NormalColor))
			.SetUncheckedPressedImage(BOX_BRUSH(*SmallRoundedButtonStart, FMargin(7.f / 16.f), SelectionColor_Pressed))
			.SetUncheckedHoveredImage(BOX_BRUSH(*SmallRoundedButtonStart, FMargin(7.f / 16.f), SelectionColor_Pressed))
			.SetCheckedHoveredImage(BOX_BRUSH(*SmallRoundedButtonStart, FMargin(7.f / 16.f), SelectionColor))
			.SetCheckedPressedImage(BOX_BRUSH(*SmallRoundedButtonStart, FMargin(7.f / 16.f), SelectionColor))
			.SetCheckedImage(BOX_BRUSH(*SmallRoundedButtonStart, FMargin(7.f / 16.f), SelectionColor)));

		Style->Set("PivotTool.ToggleButton.Middle", FCheckBoxStyle()
			.SetCheckBoxType(ESlateCheckBoxType::ToggleButton)
			.SetUncheckedImage(BOX_BRUSH(*SmallRoundedButtonMiddle, FMargin(7.f / 16.f), NormalColor))
			.SetUncheckedPressedImage(BOX_BRUSH(*SmallRoundedButtonMiddle, FMargin(7.f / 16.f), SelectionColor_Pressed))
			.SetUncheckedHoveredImage(BOX_BRUSH(*SmallRoundedButtonMiddle, FMargin(7.f / 16.f), SelectionColor_Pressed))
			.SetCheckedHoveredImage(BOX_BRUSH(*SmallRoundedButtonMiddle, FMargin(7.f / 16.f), SelectionColor))
			.SetCheckedPressedImage(BOX_BRUSH(*SmallRoundedButtonMiddle, FMargin(7.f / 16.f), SelectionColor))
			.SetCheckedImage(BOX_BRUSH(*SmallRoundedButtonMiddle, FMargin(7.f / 16.f), SelectionColor)));

		Style->Set("PivotTool.ToggleButton.End", FCheckBoxStyle()
			.SetCheckBoxType(ESlateCheckBoxType::ToggleButton)
			.SetUncheckedImage(BOX_BRUSH(*SmallRoundedButtonEnd, FMargin(7.f / 16.f), NormalColor))
			.SetUncheckedPressedImage(BOX_BRUSH(*SmallRoundedButtonEnd, FMargin(7.f / 16.f), SelectionColor_Pressed))
			.SetUncheckedHoveredImage(BOX_BRUSH(*SmallRoundedButtonEnd, FMargin(7.f / 16.f), SelectionColor_Pressed))
			.SetCheckedHoveredImage(BOX_BRUSH(*SmallRoundedButtonEnd, FMargin(7.f / 16.f), SelectionColor))
			.SetCheckedPressedImage(BOX_BRUSH(*SmallRoundedButtonEnd, FMargin(7.f / 16.f), SelectionColor))
			.SetCheckedImage(BOX_BRUSH(*SmallRoundedButtonEnd, FMargin(7.f / 16.f), SelectionColor)));

		const FCheckBoxStyle DefaultToggleButtonStyle = FCoreStyle::Get().GetWidgetStyle<FCheckBoxStyle>("ToggleButtonCheckbox");
		Style->Set("PivotTool.ToggleButtonCheckbox", FCheckBoxStyle(DefaultToggleButtonStyle));
	}
}

void FPivotToolStyle::SetupFlatButtonStyles(FSlateStyleSet* Style, const FName Name, const FLinearColor& Color)
{
	Style->Set(Name, FButtonStyle()
		.SetNormal(BOX_BRUSH("Images/button_flat", FMargin(4 / 16.0f), Color))
		.SetHovered(BOX_BRUSH("Images/button_flat", FMargin(4 / 16.0f), HOVER_COLOR(Color)))
		.SetPressed(BOX_BRUSH("Images/button_flat", FMargin(4 / 16.0f), PRESS_COLOR(Color))));
}

TSharedRef< FSlateStyleSet > FPivotToolStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("PivotToolStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("PivotTool")->GetBaseDir() / TEXT("Resources"));
	
	SetupStyles(&Style.Get());

	return Style;
}

void FPivotToolStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FPivotToolStyle::Get()
{
	return *StyleInstance;
}

#undef IMAGE_BRUSH
#undef BOX_BRUSH
#undef BORDER_BRUSH
#undef TTF_FONT
#undef OTF_FONT
#undef CORE_TTF_FONT
