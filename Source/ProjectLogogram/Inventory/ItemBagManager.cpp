// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemBagManager.h"
#include "ItemBag.h"
#include "../ProjectLogogramCharacter.h"

// Sets default values for this component's properties
UItemBagManager::UItemBagManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	// ...
}


// Called when the game starts
void UItemBagManager::BeginPlay()
{
	Super::BeginPlay();
	BulletBag = NewObject<UItemBag>();
	WeaponBag = NewObject<UItemBag>();

	BulletBag->Stackable = true;
	WeaponBag->Stackable = false;

	AProjectLogogramCharacter* Owner = dynamic_cast<AProjectLogogramCharacter*>(GetOwner());
	if (Owner)
		Owner->OnBagInitializationFinished(BulletBag, WeaponBag);
	// ...
	
}


// Called every frame
void UItemBagManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UItemBagManager::AddToBulletBag(UItem * Bullet)
{
	check(BulletBag && "Instantiate BulletBag before adding items");
	// TODO: check if the item is bullet
	BulletBag->AddItem(Bullet);

}

void UItemBagManager::AddToWeaponBag(UItem * Weapon)
{
	check(WeaponBag && "Instantiate WeaponBag before adding items");
	// TODO: check if the item is melee, range or shield
	WeaponBag->AddItem(Weapon);
}

