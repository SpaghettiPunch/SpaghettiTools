#pragma once

#include "Blueprint/UserWidget.h"
#include "DevNoteAnchorWidget.generated.h"

UCLASS(Blueprintable, Abstract)
class SPAGHETTITOOLS_API UDevNoteAnchorWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	/* UUserWidget Interface */
	void SynchronizeProperties() override;

	void UpdateWidgetState();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Note)
    TObjectPtr<class UDevNoteDataAsset> NoteData;

	UPROPERTY(BlueprintReadWrite, Category = Note, meta=(BindWidget))
	TObjectPtr<class UTextBlock> NoteContentLabel;
};
