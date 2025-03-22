// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpaghettiToolsCommands.h"

#define LOCTEXT_NAMESPACE "FSpaghettiToolsModule"

void FSpaghettiToolsCommands::RegisterCommands()
{
	UI_COMMAND(OpenNotesWindow, "Notes", "Bring up Notes window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
