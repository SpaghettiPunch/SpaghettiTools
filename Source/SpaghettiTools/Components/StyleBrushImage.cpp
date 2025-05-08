#include "StyleBrushImage.h"
#include "Brushes/SlateImageBrush.h"
#include "SpaghettiTools/Util/WidgetUtilities.h"


void UStyleBrushImage::ResetBrush()
{
	if (StyleBrushKey.IsValid())
	{
		auto StyleBrush = FAppStyle::Get().GetBrush(StyleBrushKey);
		SetBrush(FSlateImageBrush(StyleBrush->GetResourceName(), StyleBrush->GetImageSize(), StyleBrush->TintColor, StyleBrush->GetTiling(), StyleBrush->GetImageType()));
	}
}

void UStyleBrushImage::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UStyleBrushImage, StyleBrushKey))
	{
		ResetBrush();
	}
}

TArray<FName> UStyleBrushImage::GetStyleBrushKeys() const
{
	return WidgetUtilities::GetStyleBrushKeys().Array();
}
