// Fill out your copyright notice in the Description page of Project Settings.


#include "SymbolButton.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Slate/Public/Widgets/Input/SButton.h"

#define LOCTEXT_NAMESPACE "UMG"

USymbolButton::USymbolButton()
{
	//SlateWidgetStyleAsset'/Game/StonePlateUI/UI/ButtonSlates/SymbolButtonWidgetStyle.SymbolButtonWidgetStyle'
	ConstructorHelpers::FObjectFinder<USlateWidgetStyleAsset> SymbolStyle(TEXT("/Game/StonePlate/UI/ButtonSlates/SymbolButtonWidgetStyle.SymbolButtonWidgetStyle"));

	SButton::FArguments ButtonDefaults;

	ButtonDefaults.ButtonStyle(SymbolStyle.Object);
	if(ButtonDefaults._ButtonStyle)
		WidgetStyle = *ButtonDefaults._ButtonStyle;

	OnClicked.AddDynamic(this, &USymbolButton::OnSelfClicked);
}

#if WITH_EDITOR
const FText USymbolButton::GetPaletteCategory()
{
	return LOCTEXT("", "My Custom Widget");
}

void USymbolButton::OnSelfClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Button clicked, ID: %d"), ID)
}
#endif

#undef LOCTEXT_NAMESPACE