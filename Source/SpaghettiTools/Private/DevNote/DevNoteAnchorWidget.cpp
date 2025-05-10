#include "DevNote/DevNoteAnchorWidget.h"
#include "DevNote/DevNoteDataAsset.h"
#include "Util/WidgetUtilities.h"

void UDevNoteAnchorWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (bAutoUpdateNoteContent)
	{
		UpdateWidgetState();
	}
}

void UDevNoteAnchorWidget::SetNoteData(TObjectPtr<class UDevNoteDataAsset> NewNoteData)
{
	if (!NewNoteData || NoteData == NewNoteData)
	{
		return;
	}

	if (NoteData)
	{
		NoteData->OnChange.RemoveDynamic(this, &ThisClass::UpdateWidgetState);
	}

	NoteData = NewNoteData;
	NoteData->OnChange.AddUniqueDynamic(this, &ThisClass::UpdateWidgetState);
	UpdateWidgetState();
}

void UDevNoteAnchorWidget::UpdateWidgetState()
{
	WidgetUtilities::UpdateTextBlock(NoteContent, NoteData->NoteData.Text);
}
