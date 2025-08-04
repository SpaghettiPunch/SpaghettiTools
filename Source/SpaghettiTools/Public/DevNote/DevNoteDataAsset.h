// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Containers/Array.h"
#include "DevNoteAnchor.h"
#include "Editor.h"
#include "Engine/DataAsset.h"
#include "UObject/SoftObjectPtr.h"
#include "DevNoteDataAsset.generated.h"

USTRUCT(BlueprintType)

struct FDevNoteData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<ADevNoteAnchor> Anchor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSoftObjectPtr<AActor>> RelatedActors;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// UTexture2D* Screenshot;
};

/**
 *
 */
UCLASS(BlueprintType)

class SPAGHETTITOOLS_API UDevNoteDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/** Broadcasts whenever the data changes */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FChangedEventDelegate);
	/** Broadcasts whenever the data changes */
	FChangedEventDelegate OnChange;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Note")
	FDevNoteData NoteData;

	/** UObject Interface */
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);
		OnChange.Broadcast();
	}

#if WITH_EDITORONLY_DATA
	UFUNCTION(CallInEditor, BlueprintCallable, Category = "Note Actions")
	void SelectRelatedActors()
	{
		for (TSoftObjectPtr<AActor> RelatedActor : NoteData.RelatedActors)
		{
			if (RelatedActor.IsValid())
			{
				GEditor->SelectActor(RelatedActor.Get(), true, false);
			}
		}
	}

	UFUNCTION(CallInEditor, BlueprintCallable, Category = "Note Actions")
	void MoveCameraToNote()
	{
		TArray<AActor*> ActorGroup = {};

		for (TSoftObjectPtr<AActor> RelatedActor : NoteData.RelatedActors)
		{
			if (RelatedActor.IsValid())
			{
				ActorGroup.Add(RelatedActor.Get());
			}
		}

		if (NoteData.Anchor.IsValid())
		{
			ActorGroup.Add(NoteData.Anchor.Get());
		}

		GEditor->MoveViewportCamerasToActor(ActorGroup, true);
		SelectRelatedActors();
	}
#endif
};
