#pragma once

#include "Blueprint/UserWidget.h"
#include "DevNoteDataAsset.h"
#include "UObject/ObjectPtr.h"
#include "DevNoteAnchorWidget.generated.h"

UCLASS(Blueprintable, Abstract)
class SPAGHETTITOOLS_API UDevNoteAnchorWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/* UUserWidget Interface */
	void SynchronizeProperties() override;
	
	UFUNCTION()
	void UpdateWidgetState();

	UPROPERTY(BlueprintReadWrite, Category = Note, meta=(BindWidget))
	TObjectPtr<class UTextBlock> NoteContent;

	UPROPERTY(BlueprintReadWrite, Category = Note, meta=(BindWidget))
	TObjectPtr<class UTextBlock> NoteTitle;

	void SetNoteData(TObjectPtr<class UDevNoteDataAsset> NoteData);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Note)
    bool bAutoUpdateNoteContent;


protected:
	static void UpdateTextBlock(TObjectPtr<UTextBlock> TextBlock, FString text);

private:
	// UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintSetter="SetNoteData", Category = Note)
    TObjectPtr<class UDevNoteDataAsset> NoteData;
};
