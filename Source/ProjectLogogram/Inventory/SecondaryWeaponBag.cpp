// Fill out your copyright notice in the Description page of Project Settings.

#include "SecondaryWeaponBag.h"

void USecondaryWeaponBag::AddItem(UItem * Item)
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

		UpdateActiveList();
		UE_LOG(LogTemp, Warning, TEXT("Bullet added, name: %s"), *(Item->Name.ToString()))

	}
	else
		UE_LOG(LogTemp, Warning, TEXT("AddItem failed, Item is nullptr"))
}

void USecondaryWeaponBag::RemoveAllItems()
{
	Super::RemoveAllItems();
	UpdateActiveList();
}

void USecondaryWeaponBag::SetActiveType(int32 ItemType)
{
	ActiveType = ItemType;
	UpdateActiveList();
}

void USecondaryWeaponBag::UpdateActiveList()
{
	// clear current active list
	ActiveWeapons.Empty();

	for (FItemEntry ItemEntry : Items)
	{
		if (ItemEntry.Item->GetTypeInt() == ActiveType)
			ActiveWeapons.Add(ItemEntry);
	}

	OnActiveListUpdate.Broadcast(ActiveWeapons);
}