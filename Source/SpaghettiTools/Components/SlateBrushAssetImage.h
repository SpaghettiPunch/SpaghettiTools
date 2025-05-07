
#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "UObject/SoftObjectPtr.h"
#include "SlateBrushAssetImage.generated.h"

/**
 * 
 */
UCLASS()
class SPAGHETTITOOLS_API USlateBrushAssetImage : public UImage
{
	GENERATED_BODY()
	
public:
	/* Brush asset to use as a foundation for appearance */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	TSoftObjectPtr<class USlateBrushAsset> SlateBrushAsset;

	/* Reset local brush state to asset state */
	UFUNCTION(BlueprintCallable, CallInEditor, DisplayName="Reset Brush", Category="Appearance")
	void ResetBrush();

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
};
