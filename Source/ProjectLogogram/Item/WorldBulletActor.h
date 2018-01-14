// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/WorldWeaponActor.h"
#include "WorldBulletActor.generated.h"

class UProjectileMovementComponent;

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
	AWorldBulletActor();

};
