#pragma once

#include "UMG/StyleSlateBrushAsset.h"
#include "UMG/WidgetUtilities.h"

#include "Brushes/SlateImageBrush.h"
#include "Logging/LogVerbosity.h"
#include "Rendering/SlateRenderer.h"
#include "Styling/AppStyle.h"
#include "Styling/SlateBrush.h"
#include "UObject/UnrealNames.h"

#if WITH_EDITOR
void UStyleSlateBrushAsset::PostLoad()
{
	InitBrushFromStyle();
	Super::PostLoad();
}

void UStyleSlateBrushAsset::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	const FName Property = PropertyChangedEvent.Property->GetFName();
	if (Property == GET_MEMBER_NAME_CHECKED(UStyleSlateBrushAsset, StyleBrushKey))
	{
		InitBrushFromStyle();
	}
	else if (Property == TEXT("ResourceObject"))
	{
		StyleBrushKey = NAME_None;
	}
}

void UStyleSlateBrushAsset::InitBrushFromStyle()
{
	if (!StyleBrushKey.IsNone())
	{
		const FSlateBrush* StyleBrush = FAppStyle::Get().GetBrush(StyleBrushKey);

		Brush = FSlateImageBrush(
			StyleBrush->GetResourceName(),
			Brush.GetImageSize(),
			Brush.TintColor,
			Brush.GetTiling(),
			StyleBrush->GetImageType()
		);
	}
}

TArray<FName> UStyleSlateBrushAsset::GetStyleBrushKeys() const
{
	return WidgetUtilities::GetStyleBrushKeys().Array();
}

// WITH_EDITOR
#endif
