// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemFactoryManager.h"
#include "BulletFactory.h"
#include "../../Inventory/ItemBagManager.h"
#include "../Item.h"

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
	UItem* NewItem = BulletFactory->CreateItem(Item.ID, Item.Name);
	if (!NewItem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Item creation failed, ID does not exist in the factory"))
		return;
	}

	switch (Item.Type)
	{
	case (5):
		
		ItemBagManager->AddToBulletBag(NewItem);
		break;
	}
}