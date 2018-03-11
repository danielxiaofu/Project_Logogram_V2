// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "PainCausingVolumeComponent.generated.h"

class UDamageType;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTLOGOGRAM_API UPainCausingVolumeComponent : public UPrimitiveComponent
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

	/** Damage overlapping actors if pain-causing. */
	void PainTimer();

public:

	void BeginPlay() override;

};
