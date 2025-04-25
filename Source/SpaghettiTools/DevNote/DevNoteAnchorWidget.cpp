#include "DevNoteAnchorWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "DevNoteDataAsset.h"
#include "Components/TextBlock.h"
#include "SpaghettiTools/WidgetUtilities.h"

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
	if (!NewNoteData)
	{
		return;
	}

	if (NoteData)
	{
		NoteData->OnChange().RemoveDynamic(this, &UDevNoteAnchorWidget::UpdateWidgetState);
	}

	NoteData = NewNoteData;
	NoteData->OnChange().AddUniqueDynamic(this, &UDevNoteAnchorWidget::UpdateWidgetState);
	UpdateWidgetState();
}

void UDevNoteAnchorWidget::UpdateWidgetState()
{
	WidgetUtilities::UpdateTextBlock(NoteTitle, NoteData->NoteData.Title);
	WidgetUtilities::UpdateTextBlock(NoteContent, NoteData->NoteData.Text);
}
