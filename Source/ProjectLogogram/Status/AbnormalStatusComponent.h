// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbnormalStatusComponent.generated.h"

class UStatComponent;

/* An AbnormalStatusComponent observes a stat entry of its owner character and 
 * does something to the owner based on the observed stat entry.
 */

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTLOGOGRAM_API UAbnormalStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAbnormalStatusComponent();

protected:
	UPROPERTY()
	UStatComponent* StatComponent;

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/* Bind this function to the update delegate in a stat entry */
	UFUNCTION(BlueprintCallable)
	void OnValueUpdate(float Value);
	
};
