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

	UPROPERTY(BlueprintReadOnly, Category = "Notes", meta=(BindWidget))
	TObjectPtr<class UPanelWidget> NotesList;

	UPROPERTY(EditAnywhere, Category=Notes)
	TSubclassOf<UUserWidget> NoteWidgetClass;
};
