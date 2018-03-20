// Fill out your copyright notice in the Description page of Project Settings.

#include "FireStatusComponent.h"
#include "GameFramework/Actor.h"
#include "StatComponent.h"
#include "Components/MaterialBillboardComponent.h"
#include "Components/StaticMeshComponent.h"
#include "CanBeOnFire.h"

void UFireStatusComponent::TemperatureUpdate(float Value)
{
	if (Value >= FireTemperature && !bIsOnFire)
	{
		if (StatComponent)
		{
			FCharStatModifier  HealthModifierStruct = FCharStatModifier(EModifierBias::VE_Decrease,
				ECharStatus::VE_Health,
				0.0,
				FireDamage,
				true,
				false,
				nullptr);
			if (HealthModifier.IsValid() && HealthModifier->IsValidLowLevel())
				HealthModifier.Reset();
			HealthModifier = StatComponent->AddStatModifier(HealthModifierStruct);
			bIsOnFire = true;

			ICanBeOnFire* CanBeOnFire = Cast<ICanBeOnFire>(GetOwner());
			if (CanBeOnFire)
				CanBeOnFire->Execute_OnFire(GetOwner());
				
		}
	}
	else if (Value <= FireExtinguishTemperature && bIsOnFire)
	{
		if (HealthModifier.IsValid() && HealthModifier->IsValidLowLevel())
		{
			HealthModifier->Kill();
			HealthModifier.Reset();
			bIsOnFire = false;
			ICanBeOnFire* CanBeOnFire = Cast<ICanBeOnFire>(GetOwner());
			if (CanBeOnFire)
				CanBeOnFire->Execute_OnExtinct(GetOwner());
		}

	}
}

