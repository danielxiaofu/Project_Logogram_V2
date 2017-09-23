// Fill out your copyright notice in the Description page of Project Settings.

#include "FCustomButtonStyle.h"
#include "SlateGameResources.h"

TSharedPtr<FSlateStyleSet> FCustomButtonStyle::ButtonStyleInstance = NULL;

FCustomButtonStyle::FCustomButtonStyle()
{
}

FCustomButtonStyle::~FCustomButtonStyle()
{
}

void FCustomButtonStyle::Initialize()
{
	if (!ButtonStyleInstance.IsValid())
	{
		ButtonStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*ButtonStyleInstance);
	}
}

void FCustomButtonStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*ButtonStyleInstance);
	ensure(ButtonStyleInstance.IsUnique());
	ButtonStyleInstance.Reset();

}

FName FCustomButtonStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("ButtonStyles"));
	return StyleSetName;
}

TSharedRef<class FSlateStyleSet> FCustomButtonStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FCustomButtonStyle::GetStyleSetName(), "/Game/UI/Styles", "/Game/UI/Styles");

	return StyleRef;
}

const ISlateStyle& FCustomButtonStyle::Get()
{
	return *ButtonStyleInstance;
}


