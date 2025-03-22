// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DevNoteData.generated.h"

USTRUCT(BlueprintType)
struct FDevNoteData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Text;

	UPROPERTY(EditAnywhere)
	UTexture2D* Screenshot;
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
};
