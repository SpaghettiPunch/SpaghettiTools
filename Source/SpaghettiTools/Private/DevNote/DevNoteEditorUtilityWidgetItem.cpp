#include "DevNote/DevNoteEditorUtilityWidgetItem.h"
#include "DevNote/DevNoteDataAsset.h"
#include "Util/WidgetUtilities.h"

#include "Brushes/SlateImageBrush.h"
#include "CommonVisibilitySwitcher.h"
#include "Components/DetailsView.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"

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
}
