// Fill out your copyright notice in the Description page of Project Settings.

#include "StatComponent.h"
#include "CharStatusEntry.h"

void FCharacterStat::InitializeStatusObject()
{
	for (auto& Elem : StatEntryMap)
	{
		FCharStatEntryStruct CharStat = Elem.Value;
		UCharStatusEntry* NewStatEntry = NewObject<UCharStatusEntry>();
		NewStatEntry->Initialize(CharStat.StatType, CharStat.MaxAmount);
		StatusMap.Add(NewStatEntry->StatType, NewStatEntry);
	}
}

FCharStatModifier& FCharacterStat::AddModifier(FCharStatModifier Modifier)
{
	// If a 0 life modifier is added, instantly apply its effect and kill
	if (Modifier.LifeSpan == 0)
	{
		StatusMap.FindRef(Modifier.TargetStatus)->ApplyModification(Modifier.Bias, Modifier.ModifyRate);
		Modifier.Kill();
	}

	int32 index = Modifiers.Add(Modifier);
	return Modifiers[index];
}

void FCharacterStat::UpdateModifiers(float Delta)
{

	// Remove dead modifiers
	for (int32 i = Modifiers.Num() - 1; i >= 0; i--)
	{
		if (!Modifiers[i].IsAlive)
			Modifiers.RemoveAt(i);
	}

	for (FCharStatModifier& Modifier : Modifiers)
	{
		if (Modifier.IsAlive)
		{
			StatusMap.FindRef(Modifier.TargetStatus)->ApplyModification(Modifier.Bias, Modifier.ModifyRate * Delta);
			
			Modifier.LifeSpan -= Delta;
			if (Modifier.LifeSpan <= 0)
				Modifier.Kill();
		}
	}
}

// Sets default values for this component's properties
UStatComponent::UStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UStatComponent::BeginPlay()
{
	Super::BeginPlay();
	Stat.InitializeStatusObject();
	// ...
	
}


// Called every frame
void UStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Stat.UpdateModifiers(DeltaTime);
	// ...
}

float UStatComponent::GetHealth() const
{
	Stat.StatusMap.FindRef(ECharStatus::VE_Health);
	return Stat.StatusMap.FindRef(ECharStatus::VE_Health)->Amount;
}

FCharStatModifier & UStatComponent::AddStatModifier(FCharStatModifier Modifier)
{
	return Stat.AddModifier(Modifier);
}
