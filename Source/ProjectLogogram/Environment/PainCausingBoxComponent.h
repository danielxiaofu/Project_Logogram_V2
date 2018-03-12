// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "PainCausingBoxComponent.generated.h"

class AActor;
class UDamageType;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTLOGOGRAM_API UPainCausingBoxComponent : public UBoxComponent
{
	GENERATED_BODY()
	
protected:

	/** Whether volume currently causes damage. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PainCausingVolume)
	uint32 bPainCausing : 1;

	/** Damage done per second to actors in this volume when bPainCausing=true */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PainCausingVolume)
	float DamagePerSec;

	/** Type of damage done */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PainCausingVolume)
	TArray<TSubclassOf<UDamageType>> DamageTypes;

	/** If pain causing, time between damage applications. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PainCausingVolume)
	float PainInterval;

	/** if bPainCausing, cause pain when something enters the volume in addition to damage each second */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PainCausingVolume)
	uint32 bEntryPain : 1;

	/** Handle for efficient management of OnTimerTick timer */
	FTimerHandle TimerHandle_PainTimer;

	UFUNCTION()
	void OwnerEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void ActorEnter(UPrimitiveComponent* OtherComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep,
		const FHitResult &SweepResult);

	/** damage overlapping actors if pain causing. */
	virtual void CausePainTo(AActor* Other);

	/** Damage overlapping actors if pain-causing. */
	void PainTimer();

public:

	void BeginPlay() override;
	
};
