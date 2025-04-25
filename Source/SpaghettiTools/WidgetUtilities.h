#include "Components/TextBlock.h"

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
};