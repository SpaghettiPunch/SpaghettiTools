#pragma once

#include "EditorUtilityWidget.h"
#include "UObject/ObjectPtr.h"
#include "DevNoteEditorUtilityWidgetItem.generated.h"

UCLASS()
class SPAGHETTITOOLS_API UDevNoteEditorUtilityWidgetItem : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:
	/* UUserWidget Interface */
	void SynchronizeProperties() override;

	UPROPERTY(BlueprintReadOnly, Category = Note, meta=(BindWidget))
	TObjectPtr<class UDetailsView> NoteDetailsView;

	UPROPERTY(BlueprintReadOnly, Category = Note, meta=(BindWidget))
	TObjectPtr<class USinglePropertyView> NoteDataPropertyView;

	UPROPERTY(BlueprintReadOnly, Category = Note, meta=(BindWidget))
	TObjectPtr<class UTextBlock> NoteTitle;

	UPROPERTY(BlueprintReadOnly, Category = Note, meta=(BindWidget))
	TObjectPtr<class UTextBlock> NoteText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Note)
    TObjectPtr<class UDevNoteDataAsset> NoteData;
};
