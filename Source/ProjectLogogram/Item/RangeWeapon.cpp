// Fill out your copyright notice in the Description page of Project Settings.

#include "RangeWeapon.h"

EItemType URangeWeapon::GetType()
{
	return EItemType::VE_Range;
}

int32 URangeWeapon::GetTypeInt()
{
	return 4;
}
