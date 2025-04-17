#include "DevNoteAnchorWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "DevNoteDataAsset.h"

#include "Components/TextBlock.h"

void UDevNoteAnchorWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	UpdateWidgetState();
}

void UDevNoteAnchorWidget::SetNoteData(TObjectPtr<class UDevNoteDataAsset> NewNoteData)
{
	if (!NewNoteData)
	{
		return;
	}

	if (NoteData && NoteDataUpdateHandle.IsValid())
	{
		NoteData->OnChanged().Remove(NoteDataUpdateHandle);
	}

	NoteData = NewNoteData;
	NoteDataUpdateHandle = NoteData->OnChanged().AddUObject(this, &UDevNoteAnchorWidget::UpdateWidgetState);
	UpdateWidgetState();
}

void UDevNoteAnchorWidget::UpdateWidgetState()
{
	UpdateTextBlock(NoteTitle, NoteData->noteData.Title);
	UpdateTextBlock(NoteContent, NoteData->noteData.Text);
}

void UDevNoteAnchorWidget::UpdateTextBlock(TObjectPtr<UTextBlock> TextBlock, FString Text)
{
	if (!TextBlock)
	{
		return;
	}

	if (Text.IsEmpty())
	{
		TextBlock->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		TextBlock->SetText(FText::FromString(Text));
		TextBlock->SetVisibility(ESlateVisibility::Visible);
	}
};
