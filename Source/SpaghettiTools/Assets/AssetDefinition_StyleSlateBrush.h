#pragma once

#include "StyleSlateBrushAsset.h"
#include "AssetDefinitionDefault.h"

#include "AssetDefinition_StyleSlateBrush.generated.h"


UCLASS()
class SPAGHETTITOOLS_API UAssetDefinition_StyleSlateBrush : public UAssetDefinitionDefault
{
	GENERATED_BODY()

public:
	// UAssetDefinition Begin
	virtual FText GetAssetDisplayName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_StyleSlateBrush", "Style Slate Brush"); }
	virtual FLinearColor GetAssetColor() const override { return FLinearColor(FColor(105, 165, 60)); }
	virtual TSoftClassPtr<UObject> GetAssetClass() const override { return UStyleSlateBrushAsset::StaticClass(); }
	virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override
	{
		static const auto Categories = { EAssetCategoryPaths::UI };
		return Categories;
	}
};