#pragma once

#include "EditorUtilityWidget.h"
#include "DevNoteEditorUtilityWidget.generated.h"

UCLASS()
class SPAGHETTITOOLS_API UDevNoteEditorUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()
public:
	/* UUserWidget Interface */
	void SynchronizeProperties() override;

    TArray<TSoftObjectPtr<class UDevNoteDataAsset>> Notes;
};
