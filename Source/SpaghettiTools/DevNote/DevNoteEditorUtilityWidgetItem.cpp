#include "DevNoteEditorUtilityWidgetItem.h"
#include "DevNoteDataAsset.h"
#include "Components/DetailsView.h"
#include "Components/SinglePropertyView.h"
#include "Components/TextBlock.h"
#include "SpaghettiTools/WidgetUtilities.h"

void UDevNoteEditorUtilityWidgetItem::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	if (NoteData)
	{
		if (NoteDetailsView)
		{
			NoteDetailsView->SetObject(NoteData);
		}

		if (NoteDataPropertyView)
		{
			NoteDataPropertyView->SetObject(this);
			NoteDataPropertyView->SetPropertyName("NoteData");
		}

		WidgetUtilities::UpdateTextBlock(NoteTitle, NoteData->NoteData.Title);
		WidgetUtilities::UpdateTextBlock(NoteText, NoteData->NoteData.Text);
	}
}
