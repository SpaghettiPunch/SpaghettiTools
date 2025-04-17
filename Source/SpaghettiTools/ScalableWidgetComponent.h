#pragma once

#include "Components/WidgetComponent.h"
#include "ScalableWidgetComponent.generated.h"

UCLASS()
class SPAGHETTITOOLS_API UScalableWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	/** Resolution scale for UI elements */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UserInterface)
	float DrawScale = 1.0f;

	/** Automatically update component transform scale to the inverse of widget render scale */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UserInterface)
	bool bAutoCompensateWidgetScale = true;

protected:
	virtual void DrawWidgetToRenderTarget(float DeltaTime) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

};