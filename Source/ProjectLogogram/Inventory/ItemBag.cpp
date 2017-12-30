// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemBag.h"

void UItemBag::AddItem(UItem * Item)
{
	// TODO: Check if the item is bullet type
	UE_LOG(LogTemp, Warning, TEXT("Bullet added, name: %s"), *(Item->Name.ToString()))
}
