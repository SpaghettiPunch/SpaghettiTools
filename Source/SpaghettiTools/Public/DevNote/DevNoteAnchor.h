// Copyright Epic Games, Inc. All Rights Reserved.

/**
 * A better note than ANote
 */

#pragma once

#include "GameFramework/Actor.h"
#include "DevNoteAnchor.generated.h"

class UBillboardComponent;
class UScalableWidgetComponent;

UCLASS(BlueprintType, Blueprintable)

class SPAGHETTITOOLS_API ADevNoteAnchor : public AActor
{
	GENERATED_BODY()

#if WITH_EDITORONLY_DATA
protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBillboardComponent> SpriteComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UScalableWidgetComponent> WidgetComponent;

public:
	ADevNoteAnchor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Note)
	TObjectPtr<class UDevNoteDataAsset> NoteData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Note)
	bool bAutoUpdateNoteContent;

	UFUNCTION(CallInEditor, Category = Note)
	void UpdateWidgetState();

	/* AActor Interface */
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	void OnConstruction(const FTransform& Transform) override;

	UBillboardComponent* GetSpriteComponent() const
	{
		return SpriteComponent;
	}

	UScalableWidgetComponent* GetWidgetComponent() const
	{
		return WidgetComponent;
	}
#endif	  // WITH_EDITORONLY_DATA
};
