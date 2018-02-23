// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HitReactionComponent.generated.h"

class UCombatAnimationSet;
class UAnimInstance;

/* This component processes hit direction and plays hit reaction animation based on it
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTLOGOGRAM_API UHitReactionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHitReactionComponent();

protected:

	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintReadWrite)
	bool bIsGuarding;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Plays a four-direction based hit reaction animation based on hit direction. The result react direction is returned in world space.
	 * @param HitDirection direction of the hit
	 * @param ActorLeftDirection actor's left direction
	 * @param ActorFrontDirection actor's front direction
	 * @param ActiveAnimationSet character's active animation set
	 * @param AnimationBlueprint character's animation blueprint
	 * return FVector direction of the hit reaction
	 */
	UFUNCTION(BlueprintCallable)
	FVector PlayFourDirectionHitAnimation(FVector HitDirection, FVector ActorLeftDirection, FVector ActorFrontDirection, UCombatAnimationSet* ActiveAnimationSet, UAnimInstance* AnimationBlueprint);

};
