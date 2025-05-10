#pragma once

#include "Factories/Factory.h"
#include "Misc/Paths.h"
#include "StyleSlateBrushAsset.h"
#include "StyleSlateBrushAssetFactory.generated.h"

UCLASS(HideCategories = Object)

class SPAGHETTITOOLS_API UStyleSlateBrushAssetFactory : public UFactory
{
	GENERATED_BODY()

	UStyleSlateBrushAssetFactory(const FObjectInitializer& ObjectInitializer)
		: Super(ObjectInitializer)
	{
		bCreateNew = true;
		SupportedClass = UStyleSlateBrushAsset::StaticClass();
	}

	//~ Begin UFactory Interface
	virtual FText GetDisplayName() const override
	{
		return NSLOCTEXT("SlateStyleBrushAssetFactoryDescription", "SlateStyleBrushAssetFactoryDescription", "Slate Style Brush");
	}

	// virtual bool ConfigureProperties() override;

	virtual UObject* FactoryCreateNew(
		UClass* Class,
		UObject* InParent,
		FName Name,
		EObjectFlags Flags,
		UObject* Context,
		FFeedbackContext* Warn
	) override
	{
		UStyleSlateBrushAsset* NewStyleSlateBrushAsset = NewObject<UStyleSlateBrushAsset>(InParent, Name, Flags);
		return NewStyleSlateBrushAsset;
	}

	//~ Begin UFactory Interface
};
