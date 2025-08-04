#include "DevNote/DevNoteAnchor.h"
#include "DevNote/DevNoteAnchorWidget.h"
#include "ScalableWidgetComponent.h"

#include "Components/BillboardComponent.h"
#include "UObject/ConstructorHelpers.h"

ADevNoteAnchor::ADevNoteAnchor()
{
	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	RootComponent = SceneComponent;
	RootComponent->Mobility = EComponentMobility::Static;

#if WITH_EDITORONLY_DATA
	SpriteComponent = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	WidgetComponent = CreateEditorOnlyDefaultSubobject<UScalableWidgetComponent>(TEXT("Widget"));

	if (!IsRunningCommandlet())
	{
		// Structure to hold one-time initialization
		struct FConstructorStatics
		{
			ConstructorHelpers::FObjectFinderOptional<UTexture2D> NoteTextureObject;
			// UClass* NoteUserWidget;
			FName ID_Notes;
			FText NAME_Notes;

			FConstructorStatics()
				: NoteTextureObject(TEXT("/Engine/EditorResources/S_Note"))
				, ID_Notes(TEXT("Notes"))
				, NAME_Notes(NSLOCTEXT("SpriteCategory", "Notes", "Notes"))
			{
			}
		};

		static FConstructorStatics ConstructorStatics;

		if (SpriteComponent)
		{
			SpriteComponent->Sprite = ConstructorStatics.NoteTextureObject.Get();
			SpriteComponent->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
			SpriteComponent->SpriteInfo.Category = ConstructorStatics.ID_Notes;
			SpriteComponent->SpriteInfo.DisplayName = ConstructorStatics.NAME_Notes;
			SpriteComponent->SetupAttachment(RootComponent);
			SpriteComponent->Mobility = EComponentMobility::Static;
		}

		if (WidgetComponent)
		{
			WidgetComponent->SetupAttachment(RootComponent);
			WidgetComponent->SetWidgetSpace(EWidgetSpace::World);
			WidgetComponent->SetVisibility(true);
			WidgetComponent->SetCastShadow(false);

			if (bAutoUpdateNoteContent)
			{
				UpdateWidgetState();
			}
		}
	}
#endif	  // WITH_EDITORONLY_DATA

	SetHidden(false);
	SetCanBeDamaged(false);
}

void ADevNoteAnchor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (bAutoUpdateNoteContent)
	{
		UpdateWidgetState();
	}
}

void ADevNoteAnchor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (bAutoUpdateNoteContent)
	{
		UpdateWidgetState();
	}
}

void ADevNoteAnchor::UpdateWidgetState()
{
	if (WidgetComponent)
	{
		UUserWidget* Widget = WidgetComponent->GetWidget();
		if (Widget)
		{
			UDevNoteAnchorWidget* const AnchorWidget = Cast<UDevNoteAnchorWidget>(Widget);
			if (AnchorWidget && NoteData)
			{
				AnchorWidget->SetNoteData(NoteData);
				AnchorWidget->bAutoUpdateNoteContent = bAutoUpdateNoteContent;
			}
		}
	}
}
