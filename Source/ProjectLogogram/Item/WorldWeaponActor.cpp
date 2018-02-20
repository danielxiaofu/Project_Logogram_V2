// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldWeaponActor.h"
#include "Classes/Components/StaticMeshComponent.h"

void AWorldWeaponActor::OnItemPickUp(AProjectLogogramCharacter* NewOwner)
{

}

void AWorldWeaponActor::EnablePhysicsSimulation()
{
	UStaticMeshComponent* Root = Cast<UStaticMeshComponent>(RootComponent);
	if (Root)
		Root->SetSimulatePhysics(true);
}


