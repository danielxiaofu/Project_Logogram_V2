// Fill out your copyright notice in the Description page of Project Settings.


#include "SymbolicItemLibrary.h"
#include "SymbolBitCombiner.h"

TMap<int32, FSymbolicItem> USymbolicItemLibrary::SymbolicItems;

void USymbolicItemLibrary::AddSymbolicItem(FSymbolicItemData ItemData, FString Name)
{
	FSymbolicItem Item;
	Item.Type = ItemData.Type;
	Item.Name = Name;

	int32 FinalID = 0;

	if (ItemData.HasContainer == 1)
	{
		USymbolBitCombiner::InsertPrimitive(FinalID, ItemData.Primitive);
		USymbolBitCombiner::MakeIDContainer(FinalID);
		USymbolBitCombiner::InsertContainer(FinalID, ItemData.Container);
	}
	else
	{
		USymbolBitCombiner::InsertPrimitive(FinalID, ItemData.Primitive);
		USymbolBitCombiner::InsertLDecorator(FinalID, ItemData.LDecorator);
		USymbolBitCombiner::InsertBDecorator(FinalID, ItemData.BDecorator);
	}

	Item.ID = FinalID;

	SymbolicItems.Add(Item.ID, Item);

	UE_LOG(LogTemp, Warning, TEXT("Item added, Name=%s, ID=%d"), *Name, Item.ID)
}

void USymbolicItemLibrary::ClearItemData()
{
	SymbolicItems.Empty();
}
