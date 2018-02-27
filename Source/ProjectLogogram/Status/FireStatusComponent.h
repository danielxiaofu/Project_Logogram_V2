// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Status/AbnormalStatusComponent.h"
#include "StatModifier.h"
#include "FireStatusComponent.generated.h"

/**	This AbnormalStatusComponent observes the character's temperature and 
  * set him on fire if the temp is too high.
  */
UCLASS()
class PROJECTLOGOGRAM_API UFireStatusComponent : public UAbnormalStatusComponent
{
	GENERATED_BODY()
	
public:

	void ValueUpdate(float Value) override;
	
protected:

	UStatModifier* HealthStatModifierObj = nullptr;

	/* The temperature that causes the character to be on fire */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float FireTemperature;

};
