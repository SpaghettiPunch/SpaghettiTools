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
	TObjectPtr<class UArrowComponent> ArrowComponent;

	// UPROPERTY(BlueprintReadWrite, EditAnywhere)
	// TObjectPtr<class UWidgetComponent> WidgetComponent;

public:
	ADevNote();

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = Note)
    TObjectPtr<class UDevNoteDataAsset> noteData;

	class UBillboardComponent* GetSpriteComponent() const { return SpriteComponent; }
	class UArrowComponent* GetArrowComponent() const { return ArrowComponent; }
	// class UWidgetComponent* GetWidgetComponent() const { return WidgetComponent; }

#endif // WITH_EDITORONLY_DATA
};
