// Fill out your copyright notice in the Description page of Project Settings.

#include "Shield.h"

EItemType UShield::GetType() const
{
	return EItemType::VE_Shield;
}

int32 UShield::GetTypeInt() const
{
	return 6;
}


