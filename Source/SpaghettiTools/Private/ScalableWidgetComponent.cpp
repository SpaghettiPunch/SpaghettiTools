#include "ScalableWidgetComponent.h"

#include "Slate/WidgetRenderer.h"
#include "Widgets/SVirtualWindow.h"

/* Copy of WidgetComponent method, but uses DrawScale property variable instad of constant */
void UScalableWidgetComponent::DrawWidgetToRenderTarget(float DeltaTime)
{
	if (GUsingNullRHI)
	{
		return;
	}

	if (!SlateWindow.IsValid())
	{
		return;
	}

	if (!WidgetRenderer)
	{
		return;
	}

	const int32 MaxAllowedDrawSize = GetMax2DTextureDimension();
	if (DrawSize.X <= 0 || DrawSize.Y <= 0 || DrawSize.X > MaxAllowedDrawSize || DrawSize.Y > MaxAllowedDrawSize)
	{
		return;
	}

	const FIntPoint PreviousDrawSize = CurrentDrawSize;
	CurrentDrawSize = DrawSize;

	if (bUseInvalidationInWorldSpace)
	{
		SlateWindow->ProcessWindowInvalidation();
		SlateWindow->SlatePrepass(DrawScale);
		WidgetRenderer->SetIsPrepassNeeded(false);
	}
	else if (bDrawAtDesiredSize)
	{
		SlateWindow->SlatePrepass(DrawScale);
		WidgetRenderer->SetIsPrepassNeeded(false);
	}
	else
	{
		WidgetRenderer->SetIsPrepassNeeded(true);
	}

	bool bHasValidSize = true;
	if (bDrawAtDesiredSize)
	{
		FVector2D DesiredSize = SlateWindow->GetDesiredSize();
		DesiredSize.X = FMath::RoundToDouble(DesiredSize.X) * DrawScale;
		DesiredSize.Y = FMath::RoundToDouble(DesiredSize.Y) * DrawScale;
		CurrentDrawSize = DesiredSize.IntPoint();

		if (DesiredSize.X <= 0 || DesiredSize.Y <= 0)
		{
			bHasValidSize = false;
		}
	}

	if (CurrentDrawSize != PreviousDrawSize)
	{
		if (bHasValidSize)
		{
			UpdateBodySetup(true);
			RecreatePhysicsState();
		}
		else
		{
			DestroyPhysicsState();
		}
	}

	UpdateRenderTarget(CurrentDrawSize);

	// The render target could be null if the current draw size is zero
	if (RenderTarget)
	{
		bRedrawRequested = false;

		if (bUseInvalidationInWorldSpace)
		{
			static IConsoleVariable* CVar = IConsoleManager::Get().FindConsoleVariable(TEXT("Slate.DeferRetainedRenderingRenderThread"));
			ensure(CVar);
			bool bDeferRetainedRenderingRenderThread = CVar ? CVar->GetInt() != 0 : false;

			FPaintArgs PaintArgs(nullptr, SlateWindow->GetHittestGrid(), FVector2D::ZeroVector, FApp::GetCurrentTime(), DeltaTime);
			TSharedRef<SVirtualWindow> WindowToDraw = SlateWindow.ToSharedRef();

			WidgetRenderer->DrawInvalidationRoot(
				WindowToDraw,
				RenderTarget,
				PaintArgs,
				DrawScale,
				CurrentDrawSize,
				bDeferRetainedRenderingRenderThread
			);
		}
		else
		{
			WidgetRenderer
				->DrawWindow(RenderTarget, SlateWindow->GetHittestGrid(), SlateWindow.ToSharedRef(), DrawScale, CurrentDrawSize, DeltaTime);
		}

		LastWidgetRenderTime = GetCurrentTime();

		if (TickMode == ETickMode::Disabled && IsComponentTickEnabled())
		{
			SetComponentTickEnabled(false);
		}
	}
}

void UScalableWidgetComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (bAutoCompensateWidgetScale)
	{
		SetRelativeScale3D(FVector(1.0f / DrawScale));
	}
};
