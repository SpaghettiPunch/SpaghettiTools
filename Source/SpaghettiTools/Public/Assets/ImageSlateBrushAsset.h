#pragma once

#include "SlateBrushAsset.h"
#include "UObject/ObjectMacros.h"
#include "ImageSlateBrushAsset.generated.h"

UCLASS(BlueprintType)
class SPAGHETTITOOLS_API UImageSlateBrushAsset : public USlateBrushAsset
{
	GENERATED_BODY()

public:
	/* */
	UPROPERTY(EditAnywhere, Category = Brush)
	FString ResourceName;

#if WITH_EDITOR
	//~ Begin UObject Interface
	virtual void PostLoad() override;
	virtual void PostEditChangeProperty( struct FPropertyChangedEvent& PropertyChangedEvent) override;

protected:
	void InitBrushFromResource();

	//~ End UObject Interface
#endif
};