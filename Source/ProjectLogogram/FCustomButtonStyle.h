// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"

/**
 * 
 */
class PROJECTLOGOGRAM_API FCustomButtonStyle
{
public:
	FCustomButtonStyle();
	~FCustomButtonStyle();

	static void Initialize();

	static void Shutdown();

	static const class ISlateStyle& Get();

	static FName GetStyleSetName();

private:
	static TSharedRef<class FSlateStyleSet> Create();

	static TSharedPtr<class FSlateStyleSet> ButtonStyleInstance;
};
