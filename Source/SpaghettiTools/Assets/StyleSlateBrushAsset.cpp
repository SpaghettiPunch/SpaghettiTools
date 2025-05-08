#pragma once

#include "StyleSlateBrushAsset.h"
#include "Brushes/SlateImageBrush.h"
#include "Rendering/SlateRenderer.h"
#include "SpaghettiTools/Util/WidgetUtilities.h"
#include "Styling/SlateBrush.h"

#if WITH_EDITOR
void UStyleSlateBrushAsset::PostLoad()
{
	InitBrushFromStyle();
	Super::PostLoad();
}

void UStyleSlateBrushAsset::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName Property = PropertyChangedEvent.MemberProperty->GetFName();
	if (Property == GET_MEMBER_NAME_CHECKED(UStyleSlateBrushAsset, StyleBrushKey))
	{
		InitBrushFromStyle();
	}
}

void UStyleSlateBrushAsset::InitBrushFromStyle()
{
	if (!StyleBrushKey.IsNone())
	{
		auto StyleBrush = FAppStyle::Get().GetBrush(StyleBrushKey);
		Brush = FSlateImageBrush(StyleBrush->GetResourceName(), Brush.GetImageSize(), Brush.TintColor, Brush.GetTiling(), Brush.GetImageType());
	}
}

TArray<FName> UStyleSlateBrushAsset::GetStyleBrushKeys() const
{
	return WidgetUtilities::GetStyleBrushKeys().Array();
}

// WITH_EDITOR
#endif
