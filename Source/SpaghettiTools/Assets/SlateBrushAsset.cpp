#include "SlateBrushAsset.h"

/* Copied from SlateBrushAsset.h since it is a MinimalAPI class */
void USlateBrushAsset::PostLoad()
{
	Super::PostLoad();

	if (Brush.Tint_DEPRECATED != FLinearColor::White)
	{
		Brush.TintColor = FSlateColor( Brush.Tint_DEPRECATED );
	}
}