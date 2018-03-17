// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldWeaponActor.h"
#include "Classes/Components/StaticMeshComponent.h"
#include "Effect/HitEffect_FB.h"

void AWorldWeaponActor::K2_DestroyActor()
{
	//if(HitEffect)
		//HitEffect->K2_DestroyActor();
	Super::K2_DestroyActor();
}

void AWorldWeaponActor::OnItemPickUp(AProjectLogogramCharacter* NewOwner)
{

}

void AWorldWeaponActor::EnablePhysicsSimulation()
{
	UStaticMeshComponent* Root = Cast<UStaticMeshComponent>(RootComponent);
	if (Root)
		Root->SetSimulatePhysics(true);
}


