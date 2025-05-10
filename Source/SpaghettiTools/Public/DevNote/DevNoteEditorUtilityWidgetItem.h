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

	UPROPERTY(BlueprintReadOnly, Category = Note, meta = (BindWidget))
	TObjectPtr<class UDetailsView> NoteDetailsView;

	UPROPERTY(BlueprintReadOnly, Category = Note, meta = (BindWidget))
	TObjectPtr<class UTextBlock> NoteText;

	UPROPERTY(BlueprintReadOnly, Category = Note, meta = (BindWidget))
	TObjectPtr<class UCommonVisibilitySwitcher> VisibilitySwitcher;

	UFUNCTION(BlueprintCallable)
	void SetEditMode(bool bMode);

	UFUNCTION(BlueprintCallable)
	void ToggleEditMode();

	UFUNCTION(BlueprintCallable)

	bool IsEditMode() const
	{
		return bEditMode;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Note)
	TObjectPtr<class UDevNoteDataAsset> NoteData;

private:
	bool bEditMode;
	void UpdateWidget();
};
