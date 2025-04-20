// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Containers/Array.h"
#include "DevNote.h"
#include "Editor.h"
#include "Engine/DataAsset.h"
#include "UObject/ObjectPtr.h"
#include "UObject/SoftObjectPtr.h"
#include "DevNoteDataAsset.generated.h"

USTRUCT(BlueprintType)

struct FDevNoteData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Note")
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Note")
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Note")
	TSoftObjectPtr<ADevNote> Anchor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Note")
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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Note")
	FDevNoteData NoteData;

	/** UObject Interface */
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override 
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);
		BroadcastChangedEvent();
	}


#if WITH_EDITORONLY_DATA
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

	UFUNCTION(CallInEditor, Category = "Note")
	void MoveCameraToNote()
	{
		TArray<AActor*> ActorGroup = {};

		for (TSoftObjectPtr<AActor> RelatedActor: NoteData.RelatedActors)
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

	/** Broadcasts whenever the data changes */
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FChangedEventDelegate);
	/** Broadcasts whenever the data changes */
	FChangedEventDelegate OnChange() {
		return OnChangeDelegate;
	}

protected:
	/** Broadcasts whenever the data changes */
	FChangedEventDelegate OnChangeDelegate;

	void BroadcastChangedEvent()
	{
		OnChangeDelegate.Broadcast();
	}
};
