// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Status/AbnormalStatusComponent.h"
#include "FreezeStatusComponent.generated.h"

class UStatComponent;
class UStatModifier;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTLOGOGRAM_API UFreezeStatusComponent : public UAbnormalStatusComponent
{
	GENERATED_BODY()
	
public:

	// Called when temperature is updated, bind this function to temperature stat update delegate
	UFUNCTION(BlueprintCallable)
	void TemperatureUpdate(float Value);
	
protected:

	UPROPERTY(BlueprintReadOnly, Category = Temperature)
	bool bIsChilling;

	UPROPERTY(BlueprintReadOnly, Category = Temperature)
	bool bIsFrozen;

	// Maximum temp to trigger chill, also minimum temp to recover from frozen
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float ChillTemperature = -20;

	// Maximum temp to trigger frozen
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float FreezeTemperature = -30;

	// Minimum temp to recover from chill
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float ChillRecoverTemperature = -10;

	
};
