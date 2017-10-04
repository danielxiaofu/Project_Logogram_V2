// Fill out your copyright notice in the Description page of Project Settings.

#include "Consumable.h"
#include "ProjectLogogramCharacter.h"

void UConsumable::SetTarget(AProjectLogogramCharacter* TargetCharacter)
{
	Target = TargetCharacter;
}

void UConsumable::Use()
{
	if(!Target)
	{

	}
}

