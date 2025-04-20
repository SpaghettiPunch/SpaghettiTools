#include "DevNoteAnchorWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "DevNoteDataAsset.h"

#include "Components/TextBlock.h"

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
	UpdateTextBlock(NoteTitle, NoteData->NoteData.Title);
	UpdateTextBlock(NoteContent, NoteData->NoteData.Text);
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
