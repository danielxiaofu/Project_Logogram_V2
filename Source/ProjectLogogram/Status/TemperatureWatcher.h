// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Status/AbnormalStatusComponent.h"
#include "TemperatureWatcher.generated.h"

class UStatComponent;
class UStatModifier;

/**
 *  This component observes temperature and constantly recover temp towards 0 in a slow speed.
 *  If temp is too high or too low, abnormal behaviors will be added to the character until temp 
 *  goes back to normal
 */
UCLASS()
class PROJECTLOGOGRAM_API UTemperatureWatcher : public UAbnormalStatusComponent
{
	GENERATED_BODY()
	
public:

	// Recover speed of temperature per-seconds
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float RecoverSpeed = 5;
	
	// Minimum temp to trigger on fire
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float FireTemperature = 60;

	// Maximum temp to let fire extinguish
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float FireExtinguishTemperature = 35;

	// Maximum temp to trigger frozen
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float FreezeTemperature = -70;

	// Maximum temp to trigger chill, also minimum temp to recover from freeze
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float ChillTemperature = -60;

	// Maximum temp to recover from chill
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float ChillRecoverTemperature = -35;

	/* Begin watch temperature 
	 * @param StatComponent the StatComponent to watch temperature from, make sure it has a temperature stat entry
	 */
	UFUNCTION(BlueprintCallable)
	void BeginWatchTemperature(UStatComponent* TargetStatComponent);

	// Called when temperature is updated, bind this function to temperature stat update delegate
	UFUNCTION(BlueprintCallable)
	void TemperatureUpdate(float Value);

protected:

	UPROPERTY(BlueprintReadOnly, Category = Temperature)
	bool bIsOnFire;

	UPROPERTY(BlueprintReadOnly, Category = Temperature)
	bool bIsChilling;

	UPROPERTY(BlueprintReadOnly, Category = Temperature)
	bool bIsFrozen;

private:

	// The stat modifier to recover the temperature
	UPROPERTY()
	UStatModifier* TempStatModifier;


};
