
#include "DevNoteEditorUtilityWidget.h"
#include "DevNoteEditorUtilityWidgetItem.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Blueprint/UserWidget.h"
#include "Components/PanelWidget.h"
#include "DevNoteDataAsset.h"
#include "Modules/ModuleManager.h"
#include "Templates/Casts.h"

void UDevNoteEditorUtilityWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (bAutoUpdateWidgetOnSynchronizeProperties)
	{
		UpdateWidget();
	}
}

void UDevNoteEditorUtilityWidget::UpdateWidget()
{
	if (!NotesList)
	{
		return;
	}

	NotesList->ClearChildren();

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	TArray<FAssetData> Assets;
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
	AssetRegistry.GetAssetsByClass(UDevNoteDataAsset::StaticClass()->GetClassPathName(), Assets, false);

	for (FAssetData Asset : Assets)
	{
		if (UObject* AssetObject = Asset.FastGetAsset())
		{
			if (UDevNoteDataAsset* NoteDataAsset = CastChecked<UDevNoteDataAsset>(AssetObject))
			{
				if (NoteItemWidgetClass)
				{
					UUserWidget* NewWidget = CreateWidget(GetWorld(), NoteItemWidgetClass);
					if (UDevNoteEditorUtilityWidgetItem* ItemWidget = CastChecked<UDevNoteEditorUtilityWidgetItem>(NewWidget)) 
					{
						ItemWidget->NoteData = NoteDataAsset;
						NotesList->AddChild(NewWidget);
					}
				}
			}
		}
	}
}
