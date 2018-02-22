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

	ActivateBegin = false;
	ActivateFinished = false;
	RemainTime = ActivateTime;
	
}

void ASymbolDecalActor::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	if (ActivateBegin && !ActivateFinished)
	{
		RemainTime -= DeltaTime;
		
		if (RemainTime <= 0.0)
		{
			ActivateFinished = true;
			OnActivateFinish();
		}
	}
}

void ASymbolDecalActor::BeginActivate()
{
	ActivateBegin = true;
}

void ASymbolDecalActor::StopActivate()
{
	ActivateBegin = false;
	RemainTime = ActivateTime;
}


