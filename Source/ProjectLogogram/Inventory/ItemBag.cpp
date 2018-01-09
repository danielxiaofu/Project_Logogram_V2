// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemBag.h"

void UItemBag::AddItem(UItem * Item)
{
	if (Item)
	{
		FItemEntry NewEntry = FItemEntry(Item);
		if (Stackable)
		{
			// check if same item is already in the bag
			int32 Index = Items.Find(NewEntry);
			if (Index == INDEX_NONE)
				Items.Add(NewEntry);
			else
				Items[Index].Amount++;
		}
		else
			Items.Add(NewEntry);

		UpdateDelegate.Broadcast(Items);
		UE_LOG(LogTemp, Warning, TEXT("Bullet added, name: %s"), *(Item->Name.ToString()))

	}	
	else
		UE_LOG(LogTemp, Warning, TEXT("AddItem failed, Item is nullptr"))


}

void UItemBag::RefreshBag()
{
	UpdateDelegate.Broadcast(Items);
}
