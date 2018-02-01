// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/WorldWeaponActor.h"
#include "WorldBulletActor.generated.h"

class UProjectileMovementComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API AWorldBulletActor : public AWorldWeaponActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LaunchSpeed;

	AWorldBulletActor();

	/** Set the launch velocity, no need to call this if the bullet is launched by the player
	*/
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnVelocitySet(FVector Velocity);

	/** Called when this bullet is launched by a player character.
	 * Velocity is calculated in this function.
	 * @param FollowCamera the camera component of the player, useful in calibrating bullet path
	 */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnFireByPlayer(UCameraComponent* FollowCamera);

	/**
	 * Called when this bullet is launched by a character controlled by AI.
	 * Velocity is not calculated, should call OnVelocitySet to provide a velocity before calling this function.
	 */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnFireByAI();
};
