#include "DevNoteEditorUtilityWidgetItem.h"
#include "DevNoteDataAsset.h"
#include "Components/DetailsView.h"
#include "Components/SinglePropertyView.h"
#include "Components/TextBlock.h"
#include "CommonVisibilitySwitcher.h"
#include "SpaghettiTools/Util/WidgetUtilities.h"

#include "Interfaces/IPluginManager.h"

#include "Brushes/SlateBoxBrush.h"
#include "Misc/Paths.h"
#include "Styling/SlateStyleMacros.h"
#include "Styling/SlateStyle.h"
#include "Styling/CoreStyle.h"
#include "Styling/StyleColors.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateTypes.h"


void UDevNoteEditorUtilityWidgetItem::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	UpdateWidget();
}

void UDevNoteEditorUtilityWidgetItem::ToggleEditMode()
{
	SetEditMode(!bEditMode);
}

void UDevNoteEditorUtilityWidgetItem::SetEditMode(bool bMode)
{
	bEditMode = bMode;
	UpdateWidget();
}

void UDevNoteEditorUtilityWidgetItem::UpdateWidget()
{
	if (NoteData)
	{
		if (NoteDetailsView)
		{
			NoteDetailsView->SetObject(NoteData);
		}

		WidgetUtilities::UpdateTextBlock(NoteText, NoteData->NoteData.Text);
	}

	if (VisibilitySwitcher)
	{
		VisibilitySwitcher->SetActiveWidgetIndex(bEditMode);
	}

	if (TestIconImage)
	{
		TestIconImage->SetBrush(*FAppStyle::Get().GetBrush("Icons.Star"));

		FString IconFolder = IPluginManager::Get().FindPlugin(TEXT("SpaghettiTools"))->GetBaseDir();
		TestIconImage->SetBrush(FSlateVectorImageBrush(IconFolder + TEXT("/Resources/Icons/locate.svg"), FVector2D(16.f, 16.f)));

	}
}