#pragma once

#include "Components/TextBlock.h"
#include "Styling/AppStyle.h"
#include "Styling/SlateBrush.h"

class WidgetUtilities {
public:
	static void UpdateTextBlock(TObjectPtr<UTextBlock> TextBlock, FString Text)
	{
		if (!TextBlock)
		{
			return;
		}

		if (Text.IsEmpty())
		{
			TextBlock->SetVisibility(ESlateVisibility::Collapsed);
		}
		else
		{
			TextBlock->SetText(FText::FromString(Text));
			TextBlock->SetVisibility(ESlateVisibility::Visible);
		}
	}

	static TSet<FName> GetStyleBrushKeys()
	{
		TSet<FName> BrushKeys = TSet<FName>();
		TSet<FName> Keys = FAppStyle::Get().GetStyleKeys();
		for (const FName Key : Keys)
		{
			const struct FSlateBrush* Brush = FAppStyle::Get().GetBrush(Key);
			if (Brush != FAppStyle::Get().GetDefaultBrush())
			{
				BrushKeys.Add(Key);
			}
		}
		return BrushKeys;
	}
};