#include "Components/StyleBrushImage.h"
#include "Brushes/SlateImageBrush.h"
#include "Util/WidgetUtilities.h"
#include "Styling/SlateBrush.h"

void UStyleBrushImage::ResetBrush()
{
	if (StyleBrushKey.IsValid())
	{
		const FSlateBrush* StyleBrush = FAppStyle::Get().GetBrush(StyleBrushKey);

		SetBrush(
			FSlateImageBrush(
				StyleBrush->GetResourceName(),
				StyleBrush->GetImageSize(),
				StyleBrush->TintColor,
				StyleBrush->GetTiling(),
				StyleBrush->GetImageType()
			)
		);
	}
}

void UStyleBrushImage::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FName Property = PropertyChangedEvent.Property->GetFName();
	if (Property == GET_MEMBER_NAME_CHECKED(UStyleBrushImage, StyleBrushKey))
	{
		ResetBrush();
	}
	else if (Property == TEXT("ResourceObject"))
	{
		StyleBrushKey = NAME_None;
	}
}

TArray<FName> UStyleBrushImage::GetStyleBrushKeys() const
{
	return WidgetUtilities::GetStyleBrushKeys().Array();
}
