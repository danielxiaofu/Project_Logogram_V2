// Fill out your copyright notice in the Description page of Project Settings.


#include "SymbolButton.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Slate/Public/Widgets/Input/SButton.h"
#include "SymbolBitCombiner.h"
#include "SymbolCombiner.h"

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
	SetIsEnabled(!IsLocked);
}

#if WITH_EDITOR
const FText USymbolButton::GetPaletteCategory()
{
	return LOCTEXT("", "My Custom Widget");
}
#endif

void USymbolButton::BindSymbolCombiner(USymbolCombiner * Combiner)
{
	SymbolCombiner = Combiner;
}

void USymbolButton::BindLockDelegate()
{
	USymbolBitCombiner::LockDelegate.AddDynamic(this, &USymbolButton::OnLockCommandRecieved);
}

void USymbolButton::Reset()
{
	switch (Type)
	{
	case ESymbolType::VE_Primitive:
		SetIsEnabled(true);
		break;
	case ESymbolType::VE_Container:
		SetIsEnabled(true);
		break;
	case ESymbolType::VE_Material:
		SetIsEnabled(false);
		break;
	case ESymbolType::VE_Element:
		SetIsEnabled(false);
		break;
	case ESymbolType::VE_Undefined:
		break;
	default:
		break;
	}
}

void USymbolButton::OnSelfClicked()
{
	//UE_LOG(LogTemp, Warning, TEXT("Button clicked, ID: %d"), ID)
	check(SymbolCombiner && "Bind SymbolCombiner before calling click event");
	SymbolCombiner->OnButtonClicked(Type, ID);
}

void USymbolButton::OnLockCommandRecieved(ESymbolType SymbolType, bool IsLock)
{
	if (SymbolType != Type)
		return; // Not for this type, ignore the command

	IsLocked = IsLock;
	SetIsEnabled(!IsLocked);
}

#undef LOCTEXT_NAMESPACE