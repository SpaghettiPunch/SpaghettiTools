#pragma once

#include "ImageSlateBrushAsset.h"
#include "Brushes/SlateImageBrush.h"
#include "Rendering/SlateRenderer.h"
#include "Misc/Paths.h"

#if WITH_EDITOR
void UImageSlateBrushAsset::PostLoad()
{
	InitBrushFromResource();
	Super::PostLoad();
}

void UImageSlateBrushAsset::PostEditChangeProperty( struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName Property = PropertyChangedEvent.MemberProperty->GetFName();
	if (Property == GET_MEMBER_NAME_CHECKED(UImageSlateBrushAsset, ResourceName))
	{
		InitBrushFromResource();
	}
}

void UImageSlateBrushAsset::InitBrushFromResource() {
	if (!ResourceName.IsEmpty() && Brush.ImageSize.X != 0.0f && Brush.ImageSize.Y != 0.0f)
	{
		// Create a new brush so that it resolves the path automaticall
		// There is a way to set the resource of an existing brush, but not using a path
		Brush = FSlateVectorImageBrush(FPaths::ProjectDir() + ResourceName, Brush.ImageSize, Brush.TintColor, Brush.Tiling);
	}
}

// WITH_EDITOR
#endif