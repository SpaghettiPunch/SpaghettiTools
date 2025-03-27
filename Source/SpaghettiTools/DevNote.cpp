#include "DevNote.h"
#include "Blueprint/UserWidget.h"
#include "DevNoteData.h"

#include "Async/TaskGraphInterfaces.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "Components/WidgetComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Texture2D.h"

ADevNote::ADevNote()
{
	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	RootComponent = SceneComponent;
	RootComponent->Mobility = EComponentMobility::Static;

#if WITH_EDITORONLY_DATA
	ArrowComponent = CreateEditorOnlyDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	SpriteComponent = CreateEditorOnlyDefaultSubobject<UBillboardComponent>(TEXT("Sprite"));
	WidgetComponent = CreateEditorOnlyDefaultSubobject<UWidgetComponent>(TEXT("Widget"));

	if (!IsRunningCommandlet())
	{
		// Structure to hold one-time initialization
		struct FConstructorStatics
		{
			ConstructorHelpers::FObjectFinderOptional<UTexture2D> NoteTextureObject;
			UClass* NoteUserWidget;
			FName ID_Notes;
			FText NAME_Notes;
			FConstructorStatics()
				: NoteTextureObject(TEXT("/Engine/EditorResources/S_Note"))
				, NoteUserWidget(LoadClass<UUserWidget>(NULL, 
					TEXT("WidgetBlueprint'/SpaghettiTools/Notes/WP_WorldDevNote.WP_WorldDevNote_C'")))
				, ID_Notes(TEXT("Notes"))
				, NAME_Notes(NSLOCTEXT("SpriteCategory", "Notes", "Notes"))
			{
			}
		};
		static FConstructorStatics ConstructorStatics;

		if (ArrowComponent)
		{
			ArrowComponent->ArrowColor = FColor(150, 200, 255);

			ArrowComponent->ArrowSize = 0.5f;
			ArrowComponent->bTreatAsASprite = true;
			ArrowComponent->SpriteInfo.Category = ConstructorStatics.ID_Notes;
			ArrowComponent->SpriteInfo.DisplayName = ConstructorStatics.NAME_Notes;
			ArrowComponent->Mobility = EComponentMobility::Static;
			ArrowComponent->bIsScreenSizeScaled = true;
			ArrowComponent->SetupAttachment(RootComponent);
		}

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
			WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
			WidgetComponent->SetVisibility(true);
			WidgetComponent->SetWidgetClass(ConstructorStatics.NoteUserWidget);
		}
	}
#endif // WITH_EDITORONLY_DATA

	SetHidden(true);
	SetCanBeDamaged(false);
}

