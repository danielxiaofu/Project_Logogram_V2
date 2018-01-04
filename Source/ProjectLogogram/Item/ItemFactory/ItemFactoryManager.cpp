// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemFactoryManager.h"
#include "BulletFactory.h"
#include "MeleeFactory.h"
#include "RangeFactory.h"
#include "../../Inventory/ItemBagManager.h"
#include "../Item.h"
#include "../Bullet.h"
#include "../MeleeWeapon.h"
#include "../RangeWeapon.h"

// Sets default values for this component's properties
UItemFactoryManager::UItemFactoryManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


// Called when the game starts
void UItemFactoryManager::BeginPlay()
{
	Super::BeginPlay();

	BulletFactory = NewObject<UBulletFactory>(this, BulletFactoryClass);
	MeleeFactory = NewObject<UMeleeFactory>(this, MeleeFactoryClass);
	RangeFactory = NewObject<URangeFactory>(this, RangeFactoryClass);
	// ...
	
}


// Called every frame
void UItemFactoryManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UItemFactoryManager::CreateItem(FSymbolicItem Item, UItemBagManager* ItemBagManager)
{

	switch (Item.Type)
	{
	case (3):
		ItemBagManager->AddToMainWeaponBag(MeleeFactory->CreateItem(Item.ID, Item.Name));
		break;
	case (4):
		ItemBagManager->AddToMainWeaponBag(RangeFactory->CreateItem(Item.ID, Item.Name));
		break;
	case (5):
		ItemBagManager->AddToBulletBag(BulletFactory->CreateItem(Item.ID, Item.Name));
		break;
	case (6):
		ItemBagManager->AddToSecondaryWeaponBag(MeleeFactory->CreateItem(Item.ID, Item.Name));

	}
}