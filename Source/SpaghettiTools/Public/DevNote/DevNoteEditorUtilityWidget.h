#pragma once

#include "EditorUtilityWidget.h"
#include "UObject/ObjectPtr.h"
#include "DevNoteEditorUtilityWidget.generated.h"

UCLASS()

class SPAGHETTITOOLS_API UDevNoteEditorUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:
	/* UUserWidget Interface */
	void SynchronizeProperties() override;

	UFUNCTION(CallInEditor, Category = Debug)
	void UpdateWidget();

	UPROPERTY(EditAnywhere, Category = Debug)
	bool bAutoUpdateWidgetOnSynchronizeProperties = true;

	UPROPERTY(BlueprintReadOnly, Category = Notes, meta = (BindWidget))
	TObjectPtr<class UPanelWidget> NotesList;

	UPROPERTY(EditAnywhere, Category = Notes)
	TSubclassOf<class UDevNoteEditorUtilityWidgetItem> NoteItemWidgetClass;
};
