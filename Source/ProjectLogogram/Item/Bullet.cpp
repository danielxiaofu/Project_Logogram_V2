// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"

EItemType UBullet::GetType() const
{
	return EItemType::VE_Bullet;
}

int32 UBullet::GetTypeInt() const
{
	return 5;
}
