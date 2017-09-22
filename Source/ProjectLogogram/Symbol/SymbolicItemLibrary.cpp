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

	USymbolBitCombiner::InsertPrimitive(FinalID, ItemData.Primitive, false);
	USymbolBitCombiner::InsertContainer(FinalID, ItemData.Container, false);
	USymbolBitCombiner::InsertMaterial(FinalID, ItemData.Material, false);
	USymbolBitCombiner::InsertElement(FinalID, ItemData.Element, false);

	Item.ID = FinalID;

	FSymbolicItem AddedItem = SymbolicItems.Emplace(Item.ID, Item);

	UE_LOG(LogTemp, Warning, TEXT("Item added, Name=%s, ID=%d, MapSize=%d"), *(AddedItem.Name), AddedItem.ID, SymbolicItems.Num())

}

FSymbolicItem USymbolicItemLibrary::GetSymbolicItem(int32 ID)
{
	FSymbolicItem Result = SymbolicItems.FindRef(ID);
	
	return Result;
}

void USymbolicItemLibrary::ClearItemData()
{
	SymbolicItems.Empty();
}
