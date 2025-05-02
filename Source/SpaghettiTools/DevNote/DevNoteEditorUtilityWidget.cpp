
#include "DevNoteEditorUtilityWidget.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Blueprint/UserWidget.h"
#include "Components/PanelWidget.h"
#include "DevNoteDataAsset.h"
#include "DevNoteEditorUtilityWidgetItem.h"
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
	if (!NotesList || !NoteItemWidgetClass)
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
				UDevNoteEditorUtilityWidgetItem* ItemWidget = CreateWidget<UDevNoteEditorUtilityWidgetItem>(GetWorld(), NoteItemWidgetClass, Asset.AssetName);
				if (ItemWidget)
				{
					ItemWidget->NoteData = NoteDataAsset;
					NotesList->AddChild(ItemWidget);
				}
			}
		}
	}
}
