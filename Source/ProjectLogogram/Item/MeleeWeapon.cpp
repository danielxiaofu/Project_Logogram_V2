// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeWeapon.h"

EItemType UMeleeWeapon::GetType() const
{
	return EItemType::VE_Melee;
}

int32 UMeleeWeapon::GetTypeInt() const
{
	return 3;
}
