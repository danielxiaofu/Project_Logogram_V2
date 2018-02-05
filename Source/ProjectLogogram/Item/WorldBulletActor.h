// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/WorldWeaponActor.h"
#include "WorldBulletActor.generated.h"

class UProjectileMovementComponent;
class UCameraComponent;
class AActor;

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

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LaunchSpeed;

	AWorldBulletActor();

	/** Called when this bullet is launched by a player character.
	* Velocity is calculated in this function.
	* @param FollowCamera the camera component of the player, useful in calibrating bullet path
	*/
	UFUNCTION(BlueprintCallable)
	void FireByPlayer(UCameraComponent* FollowCamera, AActor* _ItemOwner);

	/* Event called when this bullet is launched by a player character.
	*/
	UFUNCTION(BlueprintImplementableEvent)
	void OnFireByPlayer();

	/**
	* Called when this bullet is launched by a character controlled by AI.
	* Velocity is not calculated, should call FindVelocityTo to suggest a velocity.
	*/
	UFUNCTION(BlueprintCallable)
	void FireByAI(AActor* _ItemOwner);

	/**
	 * Called when this bullet is launched by a character controlled by AI.
	 * Velocity is not calculated, should call OnVelocitySet to provide a velocity before calling this function.
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void OnFireByAI();

	/** Activate the projectile component and enable hit collision
	*/
	UFUNCTION()
	void Launch();

	/** Suggest a projectile velocity to given location and set the velocity to suggested velocity 
	 * @param Destination destination location
	 * return true if there is a solution, otherwise false
	 */
	UFUNCTION(BlueprintCallable)
	bool FindVelocityTo(FVector Destination);

protected:

	UPROPERTY(BlueprintReadWrite)
	FVector LaunchVelocity;

	UPROPERTY(BlueprintReadOnly)
	bool CalibrationFinished;

	UPROPERTY(BlueprintReadOnly)
	bool DamageWindowOn;

	UPROPERTY()
	FVector CameraLocation;

	UPROPERTY()
	FVector CameraFront;
};
