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
		UE_LOG(LogTemp, Warning, TEXT("Item added, name: %s"), *(Item->Name.ToString()))

	}	
	else
		UE_LOG(LogTemp, Warning, TEXT("AddItem failed, Item is nullptr"))


}

void UItemBag::RemoveItem(UItem * Item)
{
	if (Item)
	{
		if (Stackable)
		{
			for (int32 i = 0; i < Items.Num(); i++)
			{
				if (Items[i].Item->Equals(Item))
				{
					Items[i].Amount--;
					if (Items[i].Amount <= 0)
						Items.RemoveAt(i);
					UE_LOG(LogTemp, Warning, TEXT("Item removed, name: %s"), *(Item->Name.ToString()))
					break;
				}
			}
		}
		else
		{
			for (int32 i = 0; i < Items.Num(); i++)
			{
				if (Items[i].Item == Item)
				{
					Items.RemoveAt(i);
					UE_LOG(LogTemp, Warning, TEXT("Item removed, name: %s"), *(Item->Name.ToString()))
					break;
				}
			}
		}
		UpdateDelegate.Broadcast(Items);
	}
}

void UItemBag::RemoveAllItems()
{
	Items.Empty();
	UpdateDelegate.Broadcast(Items);
}

void UItemBag::RefreshBag()
{
	UpdateDelegate.Broadcast(Items);
}
