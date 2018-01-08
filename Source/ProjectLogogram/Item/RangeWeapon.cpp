// Fill out your copyright notice in the Description page of Project Settings.

#include "RangeWeapon.h"

EItemType URangeWeapon::GetType() const
{
	return EItemType::VE_Range;
}

int32 URangeWeapon::GetTypeInt() const
{
	return 4;
}

void URangeWeapon::RequestAim(UAnimInstance * TargetAnimInstance)
{
	OnAimRequested(TargetAnimInstance);
}

