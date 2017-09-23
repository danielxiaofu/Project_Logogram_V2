// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ProjectLogogram.h"
#include "Modules/ModuleManager.h"
#include "FCustomButtonStyle.h"

//Custom implementation of the Default Game Module. 
class FProjectLogogramGameModule : public FDefaultGameModuleImpl
{
	// Called whenever the module is starting up. In here, we unregister any style sets 
	// (which may have been added by other modules) sharing our 
	// style set's name, then initialize our style set. 
	virtual void StartupModule() override
	{
		//Hot reload hack
		FSlateStyleRegistry::UnRegisterSlateStyle(FCustomButtonStyle::GetStyleSetName());
		FCustomButtonStyle::Initialize();
	}

	// Called whenever the module is shutting down. Here, we simply tell our MenuStyles to shut down
	virtual void ShutdownModule() override
	{
		FCustomButtonStyle::Shutdown();
	}



};

IMPLEMENT_PRIMARY_GAME_MODULE(FProjectLogogramGameModule, ProjectLogogram, "ProjectLogogram" );
 