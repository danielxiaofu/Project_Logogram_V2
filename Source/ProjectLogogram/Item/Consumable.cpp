// Fill out your copyright notice in the Description page of Project Settings.

#include "Consumable.h"
#include "ProjectLogogramCharacter.h"


void UConsumable::Use()
{
	if(!Target)
	{

	}
}

void UConsumable::Initialize(AProjectLogogramCharacter* TargetCharacter, FName ItemName, int32 ItemID, TArray<FCharStatModifier> Modifiers)
{
	Target = TargetCharacter;
	Name = ItemName;
	ID = ItemID;
	StatModifiers = Modifiers;
}

EItemType UConsumable::GetType()
{
	return EItemType::VE_Consumable;
}

