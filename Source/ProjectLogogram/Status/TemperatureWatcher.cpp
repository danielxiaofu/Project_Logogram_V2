// Fill out your copyright notice in the Description page of Project Settings.

#include "TemperatureWatcher.h"
#include "StatComponent.h"
#include "StatModifier.h"
#include "GameFramework/Actor.h"

void UTemperatureWatcher::BeginWatchTemperature(UStatComponent * TargetStatComponent)
{

	FCharStatModifier TempStatModifierStruct = FCharStatModifier(EModifierBias::VE_Increase,
		ECharStatus::VE_Temperature,
		0.0,
		RecoverSpeed,
		true,
		false,
		nullptr);
	TempStatModifier = TargetStatComponent->AddStatModifier(TempStatModifierStruct);

	if(!TempStatModifier.IsValid())
		UE_LOG(LogTemp, Warning, TEXT("BeginWatchTemperature failed in %s. Temperature stat not found in target StatComponent"), *(GetOwner()->GetName()))
}

void UTemperatureWatcher::TemperatureUpdate(float Value)
{
	if (!TempStatModifier.IsValid())
		return;
	if (Value > 0)
		TempStatModifier->Bias = EModifierBias::VE_Decrease;
	else
		TempStatModifier->Bias = EModifierBias::VE_Increase;
}
