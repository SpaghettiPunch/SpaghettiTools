// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Containers/Array.h"
#include "DevNote.h"
#include "Engine/DataAsset.h"
#include "DevNoteDataAsset.generated.h"

USTRUCT(BlueprintType)
struct FDevNoteData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Note")
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Note")
	FString Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Note")
	TArray<ADevNote*> anchors;

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
		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Note")
		FDevNoteData noteData;

		/** UObject Interface */
		void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};		
