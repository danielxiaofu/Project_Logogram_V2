// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseInventory.h"
#include "Item/Item.h"

// Sets default values for this component's properties
UBaseInventory::UBaseInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBaseInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBaseInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBaseInventory::AddItem(UItem * Item)
{
	if (Item->GetType() != ItemType)
	{
		UE_LOG(LogTemp, Warning, TEXT("Add item failed, item type does not match inventory type"))
		return;
	}

	FInventoryItem NewIventoryItem = FInventoryItem(Item);

	// check duplication if stackable
	if (Stackable)
	{
		int32 FindResult = StoredItem.Find(NewIventoryItem);
		if (FindResult == INDEX_NONE)
			StoredItem.Add(NewIventoryItem);
		else
			StoredItem[FindResult].Stack++;
	}
}

bool UBaseInventory::IsEmpty() const
{
	return StoredItem.Num() == 0;
}

FInventoryItem UBaseInventory::GetSelectedItem()
{
	if (IsEmpty())
		return FInventoryItem();
	return StoredItem[CurrentIndex];
}

FInventoryItem UBaseInventory::GetNextItem()
{
	if (IsEmpty())
		return FInventoryItem();
	// Wrap around
	int32 NextIndex = (CurrentIndex + 1) % StoredItem.Num();
	return StoredItem[NextIndex];
}

FInventoryItem UBaseInventory::GetSecondNextItem()
{
	if (IsEmpty())
		return FInventoryItem();
	// Wrap around
	int32 NextIndex = (CurrentIndex + 1) % StoredItem.Num();
	int32 SecondNext = (NextIndex + 1) % StoredItem.Num();
	return StoredItem[SecondNext];
}

FInventoryItem UBaseInventory::GetPreviousItem()
{
	if (IsEmpty())
		return FInventoryItem();
	// Wrap around
	int32 PreviousIndex = CurrentIndex - 1;
	if (PreviousIndex < 0)
		PreviousIndex = StoredItem.Num() - 1;

	return StoredItem[PreviousIndex];
}

FInventoryItem UBaseInventory::GetSecondPreviousItem()
{
	if (IsEmpty())
		return FInventoryItem();
	// Wrap around
	int32 PreviousIndex = CurrentIndex - 1;
	if (PreviousIndex < 0)
		PreviousIndex = StoredItem.Num() - 1;
	int32 SecondPrevious = PreviousIndex - 1;
	if (SecondPrevious < 0)
		SecondPrevious = StoredItem.Num() - 1;

	return StoredItem[SecondPrevious];
}

FInventoryItem UBaseInventory::SelectNextItem()
{
	if (IsEmpty())
		return FInventoryItem();
	// Wrap around
	CurrentIndex = (CurrentIndex + 1) % StoredItem.Num();
	return StoredItem[CurrentIndex];
}

FInventoryItem UBaseInventory::SelectPreviousItem()
{
	if (IsEmpty())
		return FInventoryItem();
	// Wrap around
	CurrentIndex--;
	if (CurrentIndex < 0)
		CurrentIndex = StoredItem.Num() - 1;

	return StoredItem[CurrentIndex];
}