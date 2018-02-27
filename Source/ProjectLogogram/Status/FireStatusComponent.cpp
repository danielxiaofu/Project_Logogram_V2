// Fill out your copyright notice in the Description page of Project Settings.

#include "FireStatusComponent.h"
#include "GameFramework/Actor.h"
#include "StatComponent.h"

void UFireStatusComponent::ValueUpdate(float Value)
{
	if (Value > FireTemperature)
	{
		UStatComponent* StatComponent = GetOwner()->FindComponentByClass<UStatComponent>();
		if (StatComponent)
		{
			FCharStatModifier HealthStatModifier = FCharStatModifier(EModifierBias::VE_Decrease, 
				ECharStatus::VE_Health, 
				0.0, 
				5, 
				true, 
				false);
			HealthStatModifierObj = StatComponent->AddStatModifier(HealthStatModifier);
		}
	}
}


