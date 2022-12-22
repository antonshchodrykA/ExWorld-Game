
#include "ExWorldLoadingScreen.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "UObject/UObjectGlobals.h"
#include "MoviePlayer.h"
#include "Blueprint/UserWidget.h"


struct FExWorldLoadingScreenBrush : public FSlateDynamicImageBrush, public FGCObject
{
	FExWorldLoadingScreenBrush(const FName InTextureName, const FVector2D& InImageSize)
		: FSlateDynamicImageBrush(InTextureName, InImageSize)
	{
		SetResourceObject(LoadObject<UObject>(NULL, *InTextureName.ToString()));
	}

	virtual void AddReferencedObjects(FReferenceCollector& Collector)
	{
		if (UObject* CachedResourceObject = GetResourceObject())
		{
			Collector.AddReferencedObject(CachedResourceObject);
		}
	}
};

class SExWorldLoadingScreen : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SExWorldLoadingScreen)
	{}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs)
	{
		//MapName = InArgs._InMap;
		static const FName LoadingScreenName(TEXT("Texture2D'/Game/ExWorldUI_Main/Assets/ExWorldSplashScreen.ExWorldSplashScreen'"));
		static const FName ProgressBarName(TEXT("Texture2D'/Game/ExWorldUI_Main/Assets/LoadingScreen/Full-Loading.Full-Loading'"));

		LoadingScreenBrush = MakeShareable(new FExWorldLoadingScreenBrush(LoadingScreenName, FVector2D(1024, 256)));
		ProgressBarBrush = MakeShareable(new FExWorldLoadingScreenBrush(ProgressBarName, FVector2D(800, 60)));
		FSlateBrush *BGBrush = new FSlateBrush();
		BGBrush->TintColor = FLinearColor(0.213542f, 0.213542f, 0.213542f, 1.0f);
		BGBrush->DrawAs = ESlateBrushDrawType::Image;
		BGBrush->SetResourceObject(LoadObject<UObject>(NULL, *ProgressBarName.ToString()));
		
		FProgressBarStyle *PBStyle = new FProgressBarStyle();
		PBStyle->SetBackgroundImage(*BGBrush);

		ChildSlot
			[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(LoadingScreenBrush.Get())
			]
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SVerticalBox)
				+SVerticalBox::Slot()
				.VAlign(VAlign_Bottom)
				.HAlign(HAlign_Center)
				.Padding(FMargin(10.0f))
				//.Padding(FMargin(250.0f,650.0f,250.0f,5.0f))
				[
					SNew(SThrobber)
					.Visibility(this, &SExWorldLoadingScreen::GetLoadIndicatorVisibility)
					.NumPieces(1)
					.PieceImage(ProgressBarBrush.Get())
					.Animate(SThrobber::EAnimation::Opacity)
					
					
				]
			]
		];
	}

private:

	EVisibility GetLoadIndicatorVisibility() const
	{
		bool Vis =  GetMoviePlayer()->IsLoadingFinished();
		return GetMoviePlayer()->IsLoadingFinished() ? EVisibility::Collapsed : EVisibility::Visible;
	}
	
	FName MapName;
	
	FText GetMessage() const
	{
		float LoadPercentage = GetAsyncLoadPercentage(MapName);

		if (LoadPercentage < 0)
		{
			LoadPercentage = 100.f;
		}

		return FText::FromString(FString::Printf(TEXT("%d%%"), FMath::TruncToInt(LoadPercentage)));
	}

	
	TSharedPtr<FSlateDynamicImageBrush> LoadingScreenBrush;
	TSharedPtr<FSlateDynamicImageBrush> ProgressBarBrush;
};

class FExWorldLoadingScreenModule : public IExWorldLoadingScreenModule
{
public:
	virtual void StartupModule() override
	{
		// Force load for cooker reference
		LoadObject<UObject>(nullptr, TEXT("Texture2D'/Game/ExWorldUI_Main/Assets/ExWorldSplashScreen.ExWorldSplashScreen'") );
		LoadObject<UObject>(nullptr, TEXT("Texture2D'/Game/ExWorldUI_Main/Assets/LoadingScreen/Full-Loading.Full-Loading'") );
		
		if (IsMoviePlayerEnabled())
		{
			CreateScreen();
		}
	}
	
	virtual bool IsGameModule() const override
	{
		return true;
	}
	//Wont be using for now
	virtual void StartInGameLoadingScreen(bool bPlayUntilStopped, float PlayTime,const FString& MapName) override
	{
		FLoadingScreenAttributes LoadingScreen;
		
		/*if (LoadingWidget)
		{
			const TSharedPtr<SWidget> WidgetPtr = LoadingWidget->TakeWidget();
			LoadingScreen.WidgetLoadingScreen = WidgetPtr;
			LoadingScreen.bAutoCompleteWhenLoadingCompletes = !bPlayUntilStopped;
			LoadingScreen.bWaitForManualStop = bPlayUntilStopped;
			LoadingScreen.bAllowEngineTick = bPlayUntilStopped;
			LoadingScreen.MinimumLoadingScreenDisplayTime = PlayTime;
			GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
		}*/
		
			LoadingScreen.bAutoCompleteWhenLoadingCompletes = !bPlayUntilStopped;
			LoadingScreen.bWaitForManualStop = bPlayUntilStopped;
			LoadingScreen.bAllowEngineTick = bPlayUntilStopped;
			LoadingScreen.MinimumLoadingScreenDisplayTime = PlayTime;
			LoadingScreen.WidgetLoadingScreen = SNew(SExWorldLoadingScreen);
			GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
		
	}

	virtual void StopInGameLoadingScreen() override
	{
		GetMoviePlayer()->StopMovie();
	}

	virtual void CreateScreen()
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = true;
		LoadingScreen.MinimumLoadingScreenDisplayTime = 3.f;
		LoadingScreen.WidgetLoadingScreen = SNew(SExWorldLoadingScreen);
		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}

};

IMPLEMENT_GAME_MODULE(FExWorldLoadingScreenModule, ExWorldLoadingScreen);
