// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeFactory.h"
#include "../MeleeWeapon.h"

UMeleeWeapon * UMeleeFactory::CreateItem(int32 ID, FString Name)
{
	if (MeleeList.Contains(ID))
	{
		TSubclassOf<UMeleeWeapon> MeleeClass = MeleeList[ID];
		UMeleeWeapon* NewMelee = NewObject<UMeleeWeapon>(this, MeleeClass);
		NewMelee->ID = ID;
		NewMelee->Name = FName(*Name);
		return NewMelee;
	}
	else
	{
		return nullptr;
	}
}
