// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaghettiTools.h"
#include "SpaghettiToolsCommands.h"
#include "SpaghettiToolsStyle.h"

#include "Editor/UnrealEdEngine.h"

static const FName NotesTabName("Notes");

#define LOCTEXT_NAMESPACE "FSpaghettiToolsModule"

void FSpaghettiToolsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FSpaghettiToolsStyle::Initialize();
	FSpaghettiToolsStyle::ReloadTextures();

	FSpaghettiToolsCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FSpaghettiToolsCommands::Get().OpenNotesWindow,
		FExecuteAction::CreateRaw(this, &FSpaghettiToolsModule::NotesButtonClicked),
		FCanExecuteAction()
	);

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FSpaghettiToolsModule::RegisterMenus));

	FGlobalTabmanager::Get()
		->RegisterNomadTabSpawner(NotesTabName, FOnSpawnTab::CreateRaw(this, &FSpaghettiToolsModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FSpaghettiToolsNotesTabTitle", "Notes"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FSpaghettiToolsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FSpaghettiToolsStyle::Shutdown();

	FSpaghettiToolsCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(NotesTabName);
}

TSharedRef<SDockTab> FSpaghettiToolsModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FSpaghettiToolsModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("SpaghettiTools.cpp"))
	);

	return SNew(SDockTab).TabRole(ETabRole::NomadTab)[
		// Put your tab content here!
		SNew(SBox).HAlign(HAlign_Center).VAlign(VAlign_Center)[SNew(STextBlock).Text(WidgetText)]];
}

void FSpaghettiToolsModule::NotesButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(NotesTabName);
}

void FSpaghettiToolsModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools");
		{
			FToolMenuSection& Section = Menu->AddSection("SpaghettiTools", LOCTEXT("ToolsMenuSection", "SpaghettiTools"));
			Section.AddMenuEntryWithCommandList(FSpaghettiToolsCommands::Get().OpenNotesWindow, PluginCommands);
		}
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FSpaghettiToolsModule, SpaghettiTools)
