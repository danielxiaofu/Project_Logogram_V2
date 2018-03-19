// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Status/AbnormalStatusComponent.h"
#include "StatModifier.h"
#include "FireStatusComponent.generated.h"

class UStatComponent;
class UStatModifier;
class UMaterialInterface;

/**	This AbnormalStatusComponent observes the character's temperature and 
  * set him on fire if the temp is too high.
  */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTLOGOGRAM_API UFireStatusComponent : public UAbnormalStatusComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = FireSprite)
	int32 NumberOfFireSprites;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = FireSprite)
	UMaterialInterface* FireMaterial;

	// Called when temperature is updated, bind this function to temperature stat update delegate
	UFUNCTION(BlueprintCallable)
	void TemperatureUpdate(float Value);

protected:

	UPROPERTY(BlueprintReadOnly, Category = Temperature)
	bool bIsOnFire = false;

	// Minimum temp to trigger on fire
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float FireTemperature = 60;

	// Maximum temp to let fire extinguish
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float FireExtinguishTemperature = 35;

	// How many health points does the character lose per second
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Temperature)
	float FireDamage = 2;



private:

	// The stat modifier to recover the temperature
	UPROPERTY()
	TWeakObjectPtr<UStatModifier> HealthModifier;

};
