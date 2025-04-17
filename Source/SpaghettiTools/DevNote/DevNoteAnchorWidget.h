#pragma once

#include "Blueprint/UserWidget.h"
#include "DevNoteDataAsset.h"
#include "UObject/ObjectPtr.h"
#include "UObject/SoftObjectPtr.h"
#include "DevNoteAnchorWidget.generated.h"

UCLASS(Blueprintable, Abstract)
class SPAGHETTITOOLS_API UDevNoteAnchorWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/* UUserWidget Interface */
	void SynchronizeProperties() override;

	void UpdateWidgetState();

	UPROPERTY(BlueprintReadWrite, Category = Note, meta=(BindWidget))
	TObjectPtr<class UTextBlock> NoteContent;

	UPROPERTY(BlueprintReadWrite, Category = Note, meta=(BindWidget))
	TObjectPtr<class UTextBlock> NoteTitle;

	void SetNoteData(TObjectPtr<class UDevNoteDataAsset> NoteData);
	TSoftObjectPtr<class UDevNoteDataAsset> GetNoteData() { return NoteData; }

protected:
	static void UpdateTextBlock(TObjectPtr<UTextBlock> TextBlock, FString text);

private:
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Note)
    TObjectPtr<class UDevNoteDataAsset> NoteData;
	FDelegateHandle NoteDataUpdateHandle;	
};
