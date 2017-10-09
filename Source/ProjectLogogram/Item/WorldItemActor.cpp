// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldItemActor.h"


// Sets default values
AWorldItemActor::AWorldItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorldItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWorldItemActor::OnItemPickUp(AProjectLogogramCharacter * NewOwner)
{
	check(0 && "Must override this");
}

