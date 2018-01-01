// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeWeapon.h"

EItemType UMeleeWeapon::GetType()
{
	return EItemType::VE_Melee;
}

int32 UMeleeWeapon::GetTypeInt()
{
	return 3;
}
