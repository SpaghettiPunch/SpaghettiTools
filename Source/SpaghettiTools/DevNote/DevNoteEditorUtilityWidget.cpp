
#include "DevNoteEditorUtilityWidget.h"
#include "Blueprint/UserWidget.h"
#include "DevNoteDataAsset.h"
#include "Modules/ModuleManager.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Templates/Casts.h"
#include "Components/PanelWidget.h"

void UDevNoteEditorUtilityWidget::SynchronizeProperties()
{
	if (!NotesList) {
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
				if (NoteWidgetClass)
				{
					NoteWidgetClass.GetClass()* NoteWidget = CreateWidget<NoteWidgetClass>(GetWorld(), NoteWidgetClass);

					NotesList->AddChild(NoteWidget);
				}
			{
		}
	}
}
