#pragma once

#include "ImageSlateBrushAsset.h"
#include "Factories/Factory.h"
#include "Misc/Paths.h"
#include "ImageSlateBrushAssetFactory.generated.h"

UCLASS(HideCategories = Object)
class SPAGHETTITOOLS_API UImageSlateBrushAssetFactory : public UFactory
{
	GENERATED_BODY()


	UImageSlateBrushAssetFactory(const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
	{
		bCreateNew = false;
		bEditorImport = true;
		bEditAfterNew = true;
		SupportedClass = UImageSlateBrushAsset::StaticClass();
		Formats.Add(TEXT("svg;SVG File"));
	}

	//~ Begin UFactory Interface
	virtual FText GetDisplayName() const override
	{
		return NSLOCTEXT("SlateImageBrushAssetFactoryDescription", "SlateImageBrushAssetFactoryDescription", "Slate Image Brush");
	}

	virtual UObject* FactoryCreateNew(UClass* Class,UObject* InParent,FName Name,EObjectFlags Flags,UObject* Context,FFeedbackContext* Warn) override
	{
		UImageSlateBrushAsset* NewImageSlateBrushAsset = NewObject<UImageSlateBrushAsset>(InParent, Name, Flags);
		return NewImageSlateBrushAsset;
	}

	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled)
	{
		UImageSlateBrushAsset* Asset = NewObject<UImageSlateBrushAsset>(InParent, InClass, InName, Flags);
		
		FString RelativePath = Filename;
		if (FPaths::MakePathRelativeTo(RelativePath, *FPaths::ProjectDir()))
		{
			Asset->ResourceName = RelativePath;
		}
		return Asset;
	}

	//~ Begin UFactory Interface
};