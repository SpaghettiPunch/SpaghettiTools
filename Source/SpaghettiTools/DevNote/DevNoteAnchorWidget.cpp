#include "DevNoteAnchorWidget.h"
#include "DevNoteDataAsset.h"

#include "Components/TextBlock.h"

void UDevNoteAnchorWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	UpdateWidgetState();
}

void UDevNoteAnchorWidget::UpdateWidgetState()
{
	if (NoteData && NoteContentLabel)
	{
		NoteContentLabel->SetText(FText::FromString(NoteData->noteData.Text));
	}
}
