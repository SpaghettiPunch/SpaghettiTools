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

protected:
	virtual void DrawWidgetToRenderTarget(float DeltaTime) override;

};