// Fill out your copyright notice in the Description page of Project Settings.

#include "PainCausingBoxComponent.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/Pawn.h"

void UPainCausingBoxComponent::BeginPlay()
{
	Super::BeginPlay();
	GetOwner()->OnEndPlay.AddDynamic(this, &UPainCausingBoxComponent::OwnerEndPlay);
	OnComponentBeginOverlap.AddDynamic(this, &UPainCausingBoxComponent::ActorEnter);
}

void UPainCausingBoxComponent::OwnerEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
	GetOwner()->GetWorldTimerManager().ClearTimer(TimerHandle_PainTimer);
}

void UPainCausingBoxComponent::ActorEnter(UPrimitiveComponent* OtherComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	if (bPainCausing && bEntryPain && OtherActor->bCanBeDamaged)
	{
		CausePainTo(OtherActor);
	}
	// Start timer if none is active
	if (!GetOwner()->GetWorldTimerManager().IsTimerActive(TimerHandle_PainTimer))
	{
		GetOwner()->GetWorldTimerManager().SetTimer(TimerHandle_PainTimer, this, &UPainCausingBoxComponent::PainTimer, PainInterval, true);
	}
}

void UPainCausingBoxComponent::CausePainTo(AActor * Other)
{
	for (FDamageTypeStruct DamageTypeStruct : DamageTypes)
	{
		Other->TakeDamage(DamageTypeStruct.DamageValue * PainInterval, FDamageEvent(DamageTypeStruct.DamageType), nullptr, GetOwner());
	}
}

void UPainCausingBoxComponent::PainTimer()
{
	if (bPainCausing)
	{
		TArray<AActor*> OverlappingActors;
		GetOverlappingActors(OverlappingActors, APawn::StaticClass());

		for (AActor * const A : OverlappingActors)
		{
			if (A && A->bCanBeDamaged && !A->IsPendingKill())
			{
				CausePainTo(A);
			}
		}

		if (OverlappingActors.Num() == 0)
		{
			GetOwner()->GetWorldTimerManager().ClearTimer(TimerHandle_PainTimer);
		}
	}
}


