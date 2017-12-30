// Fill out your copyright notice in the Description page of Project Settings.

#include "RangeFactory.h"
#include "../RangeWeapon.h"

URangeWeapon * URangeFactory::CreateItem(int32 ID, FString Name)
{
	if (RangeList.Contains(ID))
	{
		TSubclassOf<URangeWeapon> RangeClass = RangeList[ID];
		URangeWeapon* NewRange = NewObject<URangeWeapon>(this, RangeClass);
		NewRange->ID = ID;
		NewRange->Name = FName(*Name);
		return NewRange;
	}
	else
	{
		return nullptr;
	}
}



