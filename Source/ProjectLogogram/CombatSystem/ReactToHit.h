// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatUtility.h"
#include "ReactToHit.generated.h"

/** This interface defines some functions that determine an actor's visual reaction to hit.
  *
  */

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UReactToHit : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTLOGOGRAM_API IReactToHit
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	/** Called when this actor should be hit by a physical body. This event should only be implemented
	  * to create visual hit reaction. Do not use this to change actor's stat.
	  * @param HitDirection direction of the hit
	  * @param SourceActorLocation location of the actor who dealt the hit
	  * @param HitStrength strength of the hit
	  */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "HitReaction")
	void ReactToPhysicalHit(FVector HitDirection, FVector SourceActorLocation, EHitStrength HitStrength, ELocalHitDirection LocalHitDirection);
	
	/** Called when this actor parried an attack. This event should only be implemented
	  * to create visual hit reaction. Do not use this to change actor's stat.
	  * @param HitDirection direction of the hit
	  * @param SourceActorLocation location of the actor who dealt the hit
	  * @param HitStrength strength of the hit
	  */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "HitReaction")
	void ReactToParry(FVector HitDirection, FVector SourceActorLocation, EHitStrength HitStrength, ELocalHitDirection LocalHitDirection);
};
