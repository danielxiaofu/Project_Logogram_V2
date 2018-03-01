// Fill out your copyright notice in the Description page of Project Settings.

#include "FreezeStatusComponent.h"


void UFreezeStatusComponent::TemperatureUpdate(float Value)
{
	if (Value <= ChillTemperature)
	{
		bIsChilling = true;
		// TODO: Activate chill effect
	}

	if (Value <= FreezeTemperature)
	{
		bIsFrozen = true;
		// TODO: Activate freeze effect
	}
	
	if (Value > ChillTemperature && bIsFrozen)
	{
		bIsFrozen = false;
		// TODO: Deactivate freeze effect
	}

	if (Value > ChillRecoverTemperature && bIsChilling)
	{
		bIsChilling = false;
		// TODO: Deactivate chill effect
	}

}
