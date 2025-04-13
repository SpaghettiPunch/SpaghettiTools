#include "DevNoteAnchorWidget.h"
#include "DevNoteDataAsset.h"

#include "Components/TextBlock.h"

void UDevNoteAnchorWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	UpdateWidgetContent();
}

void UDevNoteAnchorWidget::UpdateWidgetContent()
{
	if (NoteData && NoteContentLabel)
	{
		NoteContentLabel->SetText(FText::FromString(NoteData->noteData.Text));
	}
}
