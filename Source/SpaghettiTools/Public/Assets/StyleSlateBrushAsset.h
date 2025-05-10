#pragma once

#include "SlateBrushAsset.h"
#include "UObject/Class.h"
#include "UObject/ObjectMacros.h"
#include "StyleSlateBrushAsset.generated.h"

UCLASS(BlueprintType)

class SPAGHETTITOOLS_API UStyleSlateBrushAsset : public USlateBrushAsset
{
	GENERATED_BODY()

public:
	/* */
	UPROPERTY(EditAnywhere, Category = Brush, meta = (GetOptions = "GetStyleBrushKeys"))
	FName StyleBrushKey;

#if WITH_EDITOR
	//~ Begin UObject Interface
	virtual void PostLoad() override;
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

protected:
	void InitBrushFromStyle();

	UFUNCTION()
	TArray<FName> GetStyleBrushKeys() const;

	//~ End UObject Interface
#endif
};
