// Fill out your copyright notice in the Description page of Project Settings.

#include "FreezeStatusComponent.h"
#include "GameFramework/Actor.h"
#include "CanBeFrozen.h"

void UFreezeStatusComponent::TemperatureUpdate(float Value)
{
	if (Value <= ChillTemperature && !bIsChilling)
	{
		bIsChilling = true;

		ICanBeFrozen* CanBeFrozen = Cast<ICanBeFrozen>(GetOwner());
		if(CanBeFrozen)
			CanBeFrozen->Execute_OnChill(GetOwner());
	}

	if (Value <= FreezeTemperature && !bIsFrozen)
	{
		bIsFrozen = true;
		
		ICanBeFrozen* CanBeFrozen = Cast<ICanBeFrozen>(GetOwner());
		if (CanBeFrozen)
			CanBeFrozen->Execute_OnFreeze(GetOwner());
	}
	
	if (Value > ChillTemperature && bIsFrozen)
	{
		bIsFrozen = false;
	
		ICanBeFrozen* CanBeFrozen = Cast<ICanBeFrozen>(GetOwner());
		if (CanBeFrozen)
			CanBeFrozen->Execute_ExitFreeze(GetOwner());
	}

	if (Value > ChillRecoverTemperature && bIsChilling)
	{
		bIsChilling = false;

		ICanBeFrozen* CanBeFrozen = Cast<ICanBeFrozen>(GetOwner());
		if (CanBeFrozen)
			CanBeFrozen->Execute_ExitChill(GetOwner());
	}

}
