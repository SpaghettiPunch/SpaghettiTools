#include "SlateBrushAssetImage.h"
#include "Slate/SlateBrushAsset.h"


void USlateBrushAssetImage::ResetBrush()
{
	if (SlateBrushAsset.IsValid())
	{
		SetBrush(SlateBrushAsset->Brush);
	}
}

void USlateBrushAssetImage::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(USlateBrushAssetImage, SlateBrushAsset))
	{
		ResetBrush();
	}
}
