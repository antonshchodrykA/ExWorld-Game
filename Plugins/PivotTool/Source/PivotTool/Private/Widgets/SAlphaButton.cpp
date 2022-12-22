// Copyright 2017-2019 marynate. All Rights Reserved.

#include "SAlphaButton.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Modules/ModuleManager.h"
#include "Misc/FileHelper.h"

SAlphaButton::SAlphaButton()
	: HitTexutre(NULL)
{
}

SAlphaButton::~SAlphaButton()
{
	if (HitTexutre && HitTexutre->IsValidLowLevel() && HitTexutre->IsRooted())
	{
		HitTexutre->RemoveFromRoot();
	}
}

FReply SAlphaButton::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!bIsHovered)
	{
		return FReply::Unhandled();
	}
	return SButton::OnMouseButtonDown(MyGeometry, MouseEvent);
}

FReply SAlphaButton::OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent)
{
	if (!bIsHovered)
	{
		return FReply::Unhandled();
	}
	return SButton::OnMouseButtonDoubleClick(InMyGeometry, InMouseEvent);
}

FReply SAlphaButton::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!bIsHovered)
	{
		return FReply::Unhandled();
	}
	return SButton::OnMouseButtonUp(MyGeometry, MouseEvent);
}

FReply SAlphaButton::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) 
{
	const float AlphaThreshold = 0.1f;
	UTexture2D* ButtonTexutre = GetHitTexture();
	if (ButtonTexutre)
	{
		const int32 TextureWidth = ButtonTexutre->PlatformData->SizeX;
		const int32 TextureHeight = ButtonTexutre->PlatformData->SizeY;
		FVector2D LocalPos = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
		//FPlatformMath::FloorToInt()
			
		const int32 X = FPlatformMath::FloorToInt(LocalPos.X / MyGeometry.GetLocalSize().X * TextureWidth);
		const int32 Y = FPlatformMath::FloorToInt(LocalPos.Y / MyGeometry.GetLocalSize().Y * TextureHeight);
			
		FColor* ImageData = static_cast<FColor*>((ButtonTexutre->PlatformData->Mips[0]).BulkData.Lock(LOCK_READ_ONLY));
		const int32 CurPos = Y * TextureWidth + X;
		bool bHoverCheck = ImageData && ImageData[CurPos].A > AlphaThreshold;
		ButtonTexutre->PlatformData->Mips[0].BulkData.Unlock();

		
		{
			bIsHovered = bHoverCheck;
			if (bIsHovered)
			{
				SButton::OnMouseEnter(MyGeometry, MouseEvent);
			}
			else
			{
				SButton::OnMouseLeave(MouseEvent);
			}
		}
	}

	return SButton::OnMouseMove(MyGeometry, MouseEvent);
}

FCursorReply SAlphaButton::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const 
{
	if (!bIsHovered)
	{
		return FCursorReply::Unhandled();
	}

// 	TOptional<EMouseCursor::Type> TheCursor = Cursor.Get();
// 	return (TheCursor.IsSet()) ? FCursorReply::Cursor(TheCursor.GetValue()) : FCursorReply::Unhandled();
	return SButton::OnCursorQuery(MyGeometry, CursorEvent);
}

TSharedPtr<IToolTip> SAlphaButton::GetToolTip()
{
	if (bIsHovered)
	{
		return SWidget::GetToolTip();
	}
	return NULL;
}

UTexture2D* SAlphaButton::GetHitTexture()
{
	if (HitTexutre)
	{
		return HitTexutre;
	}

	if (NormalImage)
	{
		{
			FString AlphaTexture = FPaths::GetBaseFilename(NormalImage->GetResourceName().ToString());
			FString HitTextureAsset = FString::Printf(TEXT("/PivotTool/%s.%s"), *AlphaTexture, *AlphaTexture);
			HitTexutre = LoadObject<UTexture2D>(NULL, *HitTextureAsset, NULL, LOAD_None, NULL);
		}

		if (!HitTexutre)
		{
			HitTexutre = LoadTexture(NormalImage->GetResourceName().ToString());
		}
	}
	return HitTexutre;
}

UTexture2D* SAlphaButton::LoadTexture(const FString& ImagePath)
{
	TArray<uint8> RawFileData;
	if (FFileHelper::LoadFileToArray(RawFileData, *ImagePath))
	{
		IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
		TSharedPtr<IImageWrapper> ImageWrappers[4] =
		{
			ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG),
			ImageWrapperModule.CreateImageWrapper(EImageFormat::BMP),
			ImageWrapperModule.CreateImageWrapper(EImageFormat::ICO),
			ImageWrapperModule.CreateImageWrapper(EImageFormat::ICNS),
		};

		struct Local
		{
			static void WriteRawToTexture(UTexture2D* NewTexture2D, const TArray<uint8>& RawData, bool bUseSRGB = true)
			{
				int32 Height = NewTexture2D->GetSizeY();
				int32 Width = NewTexture2D->GetSizeX();

				// Fill in the base mip for the texture we created
				uint8* MipData = (uint8*)NewTexture2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
				for (int32 y = 0; y < Height; y++)
				{
					uint8* DestPtr = &MipData[(Height - 1 - y) * Width * sizeof(FColor)];
					const FColor* SrcPtr = &((FColor*)(RawData.GetData()))[(Height - 1 - y) * Width];
					for (int32 x = 0; x < Width; x++)
					{
						*DestPtr++ = SrcPtr->B;
						*DestPtr++ = SrcPtr->G;
						*DestPtr++ = SrcPtr->R;
						*DestPtr++ = SrcPtr->A;
						SrcPtr++;
					}
				}
				NewTexture2D->PlatformData->Mips[0].BulkData.Unlock();

				// Set options
				NewTexture2D->SRGB = bUseSRGB;
#if WITH_EDITORONLY_DATA
				NewTexture2D->CompressionNone = true;
				NewTexture2D->MipGenSettings = TMGS_NoMipmaps;
#endif
				NewTexture2D->CompressionSettings = TC_EditorIcon;

				NewTexture2D->UpdateResource();
			}
		};

		for (auto ImageWrapper : ImageWrappers)
		{
			if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
			{
				TArray<uint8> *RawData = NULL;

				if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, *RawData))
				{
					if (UTexture2D* Texture = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight()))
					{
						Local::WriteRawToTexture(Texture, *RawData);
						Texture->AddToRoot();
						return Texture;
					}
				}
			}
		}
	}
	return nullptr;
}
