// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemFactoryManager.h"
#include "BulletFactory.h"

// Sets default values for this component's properties
UItemFactoryManager::UItemFactoryManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	BulletFactory = NewObject<UBulletFactory>();
	

	// ...
}


// Called when the game starts
void UItemFactoryManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UItemFactoryManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

