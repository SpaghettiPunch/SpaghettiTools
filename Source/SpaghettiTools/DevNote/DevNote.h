// Copyright Epic Games, Inc. All Rights Reserved.

/**
 * A better note than ANote
 */

#pragma once

#include "GameFramework/Actor.h"
#include "DevNote.generated.h"

UCLASS()
class SPAGHETTITOOLS_API ADevNote: public AActor
{
	GENERATED_BODY()

#if WITH_EDITORONLY_DATA
protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UBillboardComponent> SpriteComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<class UScalableWidgetComponent> WidgetComponent;

public:
	ADevNote();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Note)
    TObjectPtr<class UDevNoteDataAsset> NoteData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Debug)
    bool bAutoUpdateNoteContent;

	/* AActor Interface */
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	void OnConstruction(const FTransform& Transform) override;

	void UpdateWidgetState();

	class UBillboardComponent* GetSpriteComponent() const { return SpriteComponent; }
	class UScalableWidgetComponent* GetWidgetComponent() const { return WidgetComponent; }
#endif // WITH_EDITORONLY_DATA
};
