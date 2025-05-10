#pragma once

#include "AssetDefinitionDefault.h"
#include "ImageSlateBrushAsset.h"

#include "AssetDefinition_ImageSlateBrush.generated.h"

UCLASS()

class SPAGHETTITOOLS_API UAssetDefinition_ImageSlateBrush : public UAssetDefinitionDefault
{
	GENERATED_BODY()

public:
	// UAssetDefinition Begin
	virtual FText GetAssetDisplayName() const override
	{
		return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_ImageSlateBrush", "Image Slate Brush");
	}

	virtual FLinearColor GetAssetColor() const override
	{
		return FLinearColor(FColor(105, 165, 60));
	}

	virtual TSoftClassPtr<UObject> GetAssetClass() const override
	{
		return UImageSlateBrushAsset::StaticClass();
	}

	virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override
	{
		static const auto Categories = {EAssetCategoryPaths::UI};
		return Categories;
	}
};
