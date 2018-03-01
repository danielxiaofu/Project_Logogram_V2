// Fill out your copyright notice in the Description page of Project Settings.

#include "StatComponent.h"
#include "HasStatEntry.h"
#include "CharStatusEntry.h"
#include "GameFramework/Actor.h"

void FCharacterStat::InitializeStatusObject()
{
	for (auto& Elem : StatEntryMap)
	{
		FCharStatEntryStruct CharStat = Elem.Value;
		UCharStatusEntry* NewStatEntry = NewObject<UCharStatusEntry>();
		NewStatEntry->Initialize(CharStat.StatType, CharStat.MaxAmount, CharStat.MinAmount, CharStat.StartAmount);
		StatusMap.Add(NewStatEntry->StatType, NewStatEntry);
	}
}

UStatModifier* FCharacterStat::AddModifier(FCharStatModifier Modifier)
{
	// If a 0 life modifier is added, instantly apply its effect and kill

	UStatModifier* NewStatModifier = NewObject<UStatModifier>();
	NewStatModifier->Initialize(Modifier);

	UCharStatusEntry* StatusEntry = StatusMap.FindRef(NewStatModifier->TargetStatus);
	if (!StatusEntry)
		return nullptr;

	if (NewStatModifier->Instant)
	{
		StatusEntry->ApplyModification(NewStatModifier->Bias, NewStatModifier->ModifyRate);
		NewStatModifier->Kill();
	}

	Modifiers.Add(NewStatModifier);
	return NewStatModifier;
}

void FCharacterStat::UpdateModifiers(float Delta)
{

	// Remove dead modifiers
	for (int32 i = Modifiers.Num() - 1; i >= 0; i--)
	{
		if (!Modifiers[i]->IsAlive)
		{
			Modifiers[i]->ConditionalBeginDestroy();
			Modifiers.RemoveAt(i);
		}

	}

	for (UStatModifier* Modifier : Modifiers)
	{
		if (Modifier->IsAlive)
		{
			UCharStatusEntry* TargetStatus = StatusMap.FindRef(Modifier->TargetStatus);
			if(TargetStatus)
				TargetStatus->ApplyModification(Modifier->Bias, Modifier->ModifyRate * Delta);
			
			Modifier->LifeSpan -= Delta;
			if (Modifier->LifeSpan <= 0 && !Modifier->NoLife)
				Modifier->Kill();
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
	IHasStatEntry* OwnerCharacter = Cast<IHasStatEntry>(GetOwner());
	if (OwnerCharacter)
		OwnerCharacter->Execute_OnStatEntryInitialized(GetOwner());
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

UStatModifier* UStatComponent::AddStatModifier(FCharStatModifier Modifier)
{
	UStatModifier* AddedModifier = Stat.AddModifier(Modifier);

	return AddedModifier;
}

UCharStatusEntry* UStatComponent::GetStatusEntry(ECharStatus CharStatus) const
{
	return Stat.StatusMap.FindRef(CharStatus);
}
