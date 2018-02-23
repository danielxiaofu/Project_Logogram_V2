// Fill out your copyright notice in the Description page of Project Settings.

#include "ConsumableFactory.h"
#include "../Consumable.h"

UConsumable * UConsumableFactory::CreateItem(int32 ID, FString Name)
{
	if (ConsumableList.Contains(ID))
	{
		TSubclassOf<UConsumable> ConsumableClass = ConsumableList[ID];
		UConsumable* NewMelee = NewObject<UConsumable>(this, ConsumableClass);
		NewMelee->ID = ID;
		NewMelee->Name = FName(*Name);
		return NewMelee;
	}
	else
	{
		return nullptr;
	}

}
