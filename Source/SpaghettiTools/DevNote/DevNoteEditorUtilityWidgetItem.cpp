#include "DevNoteEditorUtilityWidgetItem.h"
#include "DevNoteDataAsset.h"
#include "SpaghettiTools/Util/WidgetUtilities.h"

#include "Brushes/SlateImageBrush.h"
#include "Components/DetailsView.h"
#include "CommonVisibilitySwitcher.h"
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