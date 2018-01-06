// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"

bool UItem::Equals(UItem * Rhs)
{
	return ID == Rhs->ID;
}

EItemType UItem::GetType() const
{
	return EItemType::VE_Undefined;
}

int32 UItem::GetTypeInt() const
{
	return 0;
}

AWorldItemActor * UItem::SpawnActor()
{
	AWorldItemActor* ItemActor = NewObject<AWorldItemActor>(this, WorldActor);

	return ItemActor;
}
