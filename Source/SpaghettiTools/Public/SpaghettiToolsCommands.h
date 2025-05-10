// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Framework/Commands/Commands.h"
#include "SpaghettiToolsStyle.h"

class FSpaghettiToolsCommands : public TCommands<FSpaghettiToolsCommands>
{
public:

	FSpaghettiToolsCommands()
		: TCommands<FSpaghettiToolsCommands>(
			  TEXT("SpaghettiTools"),
			  NSLOCTEXT("Contexts", "SpaghettiTools", "SpaghettiTools Plugin"),
			  NAME_None,
			  FSpaghettiToolsStyle::GetStyleSetName()
		  )
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr<FUICommandInfo> OpenNotesWindow;
};
