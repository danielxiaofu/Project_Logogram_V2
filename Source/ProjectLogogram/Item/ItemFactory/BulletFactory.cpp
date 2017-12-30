// Fill out your copyright notice in the Description page of Project Settings.

#include "BulletFactory.h"
#include "../Bullet.h"

UBullet* UBulletFactory::CreateItem(int32 ID, FString Name)
{
	if(BulletList.Contains(ID))
	{
		TSubclassOf<UBullet> BulletClass = BulletList[ID];
		UBullet* NewBullet = NewObject<UBullet>(this, BulletClass);
		NewBullet->ID = ID;
		NewBullet->Name = FName(*Name);
		return NewBullet;
	}
	else
	{
		return nullptr;
	}
	
}


