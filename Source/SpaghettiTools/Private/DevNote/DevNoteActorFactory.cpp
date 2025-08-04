#include "DevNote/DevNoteActorFactory.h"

#include "AssetRegistry/AssetData.h"
#include "DevNote/DevNoteAnchor.h"
#include "DevNote/DevNoteDataAsset.h"

bool UDevNoteActorFactory::CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg)
{
	if (AssetData.IsValid() && AssetData.GetClass() == UDevNoteDataAsset::StaticClass())
	{
		return true;
	}

	OutErrorMsg = NSLOCTEXT(
		"DevNoteActorFactory",
		"NoDevNoteDataAsset",
		"A DevNote Anchor Actor can only be created from a DevNoteDataAsset."
	);
	return false;
}

UClass* UDevNoteActorFactory::GetDefaultActorClass(const FAssetData& AssetData)
{
	return LoadClass<AActor>(NULL, TEXT("/SpaghettiTools/Notes/BP_DevNoteAnchor.BP_DevNoteAnchor_C"));
}

void UDevNoteActorFactory::PostSpawnActor(UObject* Asset, AActor* NewActor)
{
	Super::PostSpawnActor(Asset, NewActor);
	if (ADevNoteAnchor* DevNoteActor = Cast<ADevNoteAnchor>(NewActor))
	{
		DevNoteActor->NoteData = Cast<UDevNoteDataAsset>(Asset);
		DevNoteActor->UpdateWidgetState();

		if (UDevNoteDataAsset* DevNoteDataAsset = Cast<UDevNoteDataAsset>(Asset))
		{
			 // Note - overrides previous target anchor.
			 // May not be desired functionality, but simplest way to resolve this case.
			DevNoteDataAsset->NoteData.Anchor = DevNoteActor;
		}
	}
}
