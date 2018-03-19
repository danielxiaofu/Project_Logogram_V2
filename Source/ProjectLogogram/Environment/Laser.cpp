// Fill out your copyright notice in the Description page of Project Settings.

#include "Laser.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("LaserBeam"));
}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALaser::ClearReflection()
{
	if (ReflectedLaser)
	{
		ReflectedLaser->ClearReflection();
		ReflectedLaser->Destroy();
		ReflectedLaser->ParticleSystem->SetFloatParameter(TEXT("Distance"), 0.0f);
		ReflectedLaser = nullptr;
	}
}

