
#pragma once

#include "Components/Image.h"
#include "StyleBrushImage.generated.h"

/**
 * UMG Image component that references a Slate Style Brush
 */
UCLASS()
class SPAGHETTITOOLS_API UStyleBrushImage : public UImage
{
	GENERATED_BODY()
	
public:
	/* Brush asset to use as a foundation for appearance */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Appearance, meta=(GetOptions="GetStyleBrushKeys"))
	FName StyleBrushKey;

	/* Reset local brush state to asset state */
	UFUNCTION(BlueprintCallable, CallInEditor, DisplayName="Reset Brush", Category="Appearance")
	void ResetBrush();

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

protected:
	UFUNCTION()
	TArray<FName> GetStyleBrushKeys() const;
};
