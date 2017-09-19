// Fill out your copyright notice in the Description page of Project Settings.

#include "SymbolCombiner.h"
#include "SymbolBitCombiner.h"

// Sets default values for this component's properties
USymbolCombiner::USymbolCombiner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void USymbolCombiner::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USymbolCombiner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USymbolCombiner::OnButtonClicked(ESymbolType SymbolType, int32 ID)
{
	switch (SymbolType)
	{
	case ESymbolType::VE_Primitive:
		USymbolBitCombiner::InsertPrimitive(FinalID, ID);
		break;
	case ESymbolType::VE_Container:
		USymbolBitCombiner::InsertContainer(FinalID, ID);
		break;
	case ESymbolType::VE_LDecorator:
		USymbolBitCombiner::InsertLDecorator(FinalID, ID);
		break;
	case ESymbolType::VE_BDecorator:
		USymbolBitCombiner::InsertBDecorator(FinalID, ID);
		break;
	case ESymbolType::VE_RDecorator:
		USymbolBitCombiner::InsertRDecorator(FinalID, ID);
		break;
	case ESymbolType::VE_Undefined:
		break;
	default:
		break;
	}
}
