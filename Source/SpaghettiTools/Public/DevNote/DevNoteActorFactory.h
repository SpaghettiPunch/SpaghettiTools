#pragma once

#include "ActorFactories\ActorFactory.h"
#include "DevNoteActorFactory.generated.h"

UCLASS()

class SPAGHETTITOOLS_API UDevNoteActorFactory : public UActorFactory
{
	GENERATED_BODY()
public:
	virtual bool CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg) override;
	virtual UClass* GetDefaultActorClass(const FAssetData& AssetData) override;
	virtual void PostSpawnActor( UObject* Asset, AActor* NewActor ) override;
};
