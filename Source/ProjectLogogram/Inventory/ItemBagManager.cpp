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
	//UE_LOG(LogTemp, Warning, TEXT("ItemBags start initialization"))	
	// ...
	
}

void UItemBagManager::InitializeBags()
{
	if (!BulletBag) BulletBag = NewObject<UItemBag>();
	if (!MainWeaponBag) MainWeaponBag = NewObject<UItemBag>();
	if (!ConsumableBag) ConsumableBag = NewObject<UItemBag>();
	if (!SecondaryWeaponBag) SecondaryWeaponBag = NewObject<USecondaryWeaponBag>();

	BulletBag->Stackable = true;
	MainWeaponBag->Stackable = false;
	ConsumableBag->Stackable = true;
	SecondaryWeaponBag->Stackable = false;

	AProjectLogogramCharacter* Owner = dynamic_cast<AProjectLogogramCharacter*>(GetOwner());

	if (Owner)
	{
		Owner->OnBagInitializationFinished(this);
	}
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

void UItemBagManager::AddToConsumableBag(UItem * Consumable)
{
	check(ConsumableBag && "Instantiate ConsumableBag before adding items");
	
	if (!Consumable)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail to add to main weapon bag, item does not exist"))
		return;
	}
	if (Consumable->GetTypeInt() == 1)
		ConsumableBag->AddItem(Consumable);
	else
		UE_LOG(LogTemp, Warning, TEXT("Fail to add to consumable bag, incorrect item type"))

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
		UE_LOG(LogTemp, Warning, TEXT("Fail to remove from BulletBag, incorrect item type"))
}

void UItemBagManager::RemoveFromConsumableBag(UItem * Consumable)
{
	check(ConsumableBag && "Instantiate ConsumableBag before removing items");

	if (Consumable->GetTypeInt() == 1)
		ConsumableBag->RemoveItem(Consumable);
	else
		UE_LOG(LogTemp, Warning, TEXT("Fail to remove from consumable bag, incorrect item type"))
}

void UItemBagManager::RemoveAllItems()
{
	BulletBag->RemoveAllItems();
	MainWeaponBag->RemoveAllItems();
	SecondaryWeaponBag->RemoveAllItems();
	ConsumableBag->RemoveAllItems();
}

void UItemBagManager::SetBags(UItemBag* _BulletBag, UItemBag* _MainWeaponBag, UItemBag* _ConsumableBag, USecondaryWeaponBag* _SecondaryWeaponBag)
{
	BulletBag = _BulletBag;
	MainWeaponBag = _MainWeaponBag;
	SecondaryWeaponBag = _SecondaryWeaponBag;
	ConsumableBag = _ConsumableBag;
	if(BulletBag) BulletBag->RefreshBag();
	if(MainWeaponBag) MainWeaponBag->RefreshBag();
	if(ConsumableBag) ConsumableBag->RefreshBag();
	if(SecondaryWeaponBag) SecondaryWeaponBag->RefreshBag();
}

