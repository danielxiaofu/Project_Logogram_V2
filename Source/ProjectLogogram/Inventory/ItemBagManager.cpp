// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemBagManager.h"
#include "ItemBag.h"
#include "SecondaryWeaponBag.h"
#include "Item/Item.h"
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
	MainWeaponBag = NewObject<UItemBag>();
	SecondaryWeaponBag = NewObject<USecondaryWeaponBag>();

	BulletBag->Stackable = true;
	MainWeaponBag->Stackable = false;
	SecondaryWeaponBag->Stackable = false;

	AProjectLogogramCharacter* Owner = dynamic_cast<AProjectLogogramCharacter*>(GetOwner());

	if (Owner)
		Owner->OnBagInitializationFinished(this);
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

	if (!Bullet)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail to add to bullet bag, item does not exist"))
			return;
	}

	if (Bullet->GetTypeInt() == 5)
		BulletBag->AddItem(Bullet);
	else
		UE_LOG(LogTemp, Warning, TEXT("Fail to add to bullet bag, incorrect item type"))
}

void UItemBagManager::AddToMainWeaponBag(UItem * MainWeapon)
{
	check(MainWeaponBag && "Instantiate MainWeaponBag before adding items");

	if (!MainWeapon)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail to add to main weapon bag, item does not exist"))
		return;
	}

	if (MainWeapon->GetTypeInt() == 3 || MainWeapon->GetTypeInt() == 4)
		MainWeaponBag->AddItem(MainWeapon);
	else
		UE_LOG(LogTemp, Warning, TEXT("Fail to add to main weapon bag, incorrect item type"))
}

void UItemBagManager::AddToSecondaryWeaponBag(UItem * SecondaryWeapon)
{
	check(SecondaryWeaponBag && "Instantiate SecondaryWeaponBag before adding items");

	if (!SecondaryWeapon)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail to add to secondary weapon bag, item does not exist"))
			return;
	}

	if (SecondaryWeapon->GetTypeInt() == 6)
		SecondaryWeaponBag->AddItem(SecondaryWeapon);
	else
		UE_LOG(LogTemp, Warning, TEXT("Fail to add to secondary weapon bag, incorrect item type"))
}

void UItemBagManager::RemoveFromBulletBag(UItem * Bullet)
{
	check(BulletBag && "Instantiate BulletBag before removing items");

	if (Bullet->GetTypeInt() == 5)
		BulletBag->RemoveItem(Bullet);
	else
		UE_LOG(LogTemp, Warning, TEXT("Fail to remove from bullet bag, incorrect item type"))
}

