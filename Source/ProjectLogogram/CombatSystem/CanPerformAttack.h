// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatUtility.h"
#include "CanPerformAttack.generated.h"

/** All actors that can perform attack should implement this interface in order to recieve 
  * attack notifies from animation
  */

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UCanPerformAttack : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTLOGOGRAM_API ICanPerformAttack
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	/** Called when current animation triggers an attack notify state
	 * @param AttackStrength the hit strength of this attack
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CanPerformAttack")
	void AnimNotify_AttackBegin(EHitStrength AttackStrength);

	/** Called when current attack notify state ends
	 * 
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "CanPerformAttack")
	void AnimNotify_AttackEnd();

};
