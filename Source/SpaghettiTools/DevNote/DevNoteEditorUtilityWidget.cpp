
#include "DevNoteEditorUtilityWidget.h"
#include "DevNoteDataAsset.h"
#include "Modules/ModuleManager.h"
#include "AssetRegistry/AssetRegistryModule.h"

void UDevNoteEditorUtilityWidget::SynchronizeProperties()
{
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::Get().LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	TArray<FAssetData> AssetData;
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();
	AssetRegistry.GetAssetsByClass(UDevNoteDataAsset::StaticClass()->GetClassPathName(), AssetData, false);
}
