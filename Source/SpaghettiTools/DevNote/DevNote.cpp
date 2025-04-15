#include "DevNote.h"
#include "Components/BillboardComponent.h"
#include "Components/WidgetComponent.h"
#include "DevNoteAnchorWidget.h"
#include "UObject/ConstructorHelpers.h"

ADevNote::ADevNote()
{
	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	RootComponent = SceneComponent;
	RootComponent->Mobility = EComponentMobility::Static;

#if WITH_EDITORONLY_DATA
	SpriteComponent = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	WidgetComponent = CreateEditorOnlyDefaultSubobject<UWidgetComponent>(TEXT("Widget"));

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
				// , NoteUserWidget(LoadClass<UUserWidget>(NULL,
				// 	TEXT("WidgetBlueprint'/SpaghettiTools/Notes/WP_WorldDevNote.WP_WorldDevNote_C'")))
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
			UpdateWidgetState();
		}
	}
#endif	  // WITH_EDITORONLY_DATA

	SetHidden(true);
	SetCanBeDamaged(false);
}

void ADevNote::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UpdateWidgetState();
}

void ADevNote::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	UpdateWidgetState();
}

void ADevNote::UpdateWidgetState()
{
	if (WidgetComponent)
	{
		UUserWidget* Widget = WidgetComponent->GetWidget();
		if (Widget)
		{
			UDevNoteAnchorWidget* const AnchorWidget = Cast<UDevNoteAnchorWidget>(Widget);
			if (AnchorWidget && NoteData)
			{
				AnchorWidget->NoteData = NoteData;
				AnchorWidget->UpdateWidgetState();
			}
		}
	}
}
