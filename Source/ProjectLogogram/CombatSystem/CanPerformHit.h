// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanPerformHit.generated.h"

/** This interface defines functions that allows an actor to send
  * hit events to other actors that are hit by this actor
  */

class ICanPerformAttack;

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UCanPerformHit : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTLOGOGRAM_API ICanPerformHit
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	/** Called when the hit window of this actor is turn on
	 * @param EventCaller the UCanPerformAttack interface who called this event
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CanPerformHit")
	void OnHitWindowOn(const TScriptInterface<ICanPerformAttack>& EventCaller);

	/** Called when the hit window of this actor is turn off
	 *
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CanPerformHit")
	void OnHitWindowOff();

	/** Tick when hit window is on 
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CanPerformHit")
	void OnHitWindowTick();

	/** Called when hits an actor and hit window is on
	*/
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CanPerformHit")
	void OnOtherActorHit(AActor* OtherActor);
};
