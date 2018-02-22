// Fill out your copyright notice in the Description page of Project Settings.

#include "Consumable.h"
#include "ProjectLogogramCharacter.h"


void UConsumable::Initialize(FName ItemName, int32 ItemID)
{
	Name = ItemName;
	ID = ItemID;
}

EItemType UConsumable::GetType() const
{
	return EItemType::VE_Consumable;
}

int32 UConsumable::GetTypeInt() const
{
	return 1;
}

