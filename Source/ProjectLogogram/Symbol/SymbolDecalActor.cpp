// Fill out your copyright notice in the Description page of Project Settings.

#include "SymbolDecalActor.h"

ASymbolDecalActor::ASymbolDecalActor()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ASymbolDecalActor::BeginPlay()
{
	Super::BeginPlay();

	bActivateBegin = false;
	bActivateFinished = false;
	RemainTime = ActivateTime;
	
}

void ASymbolDecalActor::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	if (bActivateBegin && !bActivateFinished)
	{
		RemainTime -= DeltaTime;
		
		if (RemainTime <= 0.0)
		{
			bActivateFinished = true;
			OnActivateFinish();
		}
	}
}

void ASymbolDecalActor::BeginActivate()
{
	bActivateBegin = true;
}

void ASymbolDecalActor::StopActivate()
{
	bActivateBegin = false;
	RemainTime = ActivateTime;
}


