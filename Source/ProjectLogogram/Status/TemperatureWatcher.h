// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Status/AbnormalStatusComponent.h"
#include "TemperatureWatcher.generated.h"

class UStatComponent;
class UStatModifier;

/**
 *  This component observes temperature and constantly recover temp towards 0 in a slow speed.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTLOGOGRAM_API UTemperatureWatcher : public UAbnormalStatusComponent
{
	GENERATED_BODY()
	
public:

	// Recover speed of temperature per-seconds
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float RecoverSpeed = 5;

	/* Begin watch temperature 
	 * @param StatComponent the StatComponent to watch temperature from, make sure it has a temperature stat entry
	 */
	UFUNCTION(BlueprintCallable)
	void BeginWatchTemperature(UStatComponent* TargetStatComponent);

	// Called when temperature is updated, bind this function to temperature stat update delegate
	UFUNCTION(BlueprintCallable)
	void TemperatureUpdate(float Value);

protected:


private:

	// The stat modifier to recover the temperature
	UPROPERTY()
	TWeakObjectPtr<UStatModifier> TempStatModifier;


};
