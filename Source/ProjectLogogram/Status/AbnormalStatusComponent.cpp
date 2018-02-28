// Fill out your copyright notice in the Description page of Project Settings.

#include "AbnormalStatusComponent.h"
#include "StatComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UAbnormalStatusComponent::UAbnormalStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbnormalStatusComponent::BeginPlay()
{
	Super::BeginPlay();
	StatComponent = GetOwner()->FindComponentByClass<UStatComponent>();
	// ...
	
}


// Called every frame
void UAbnormalStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAbnormalStatusComponent::ValueUpdate(float Value)
{
}

void UAbnormalStatusComponent::OnValueUpdate(float Value)
{
	ValueUpdate(Value);
}

