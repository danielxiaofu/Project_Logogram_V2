// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/WorldWeaponActor.h"
#include "WorldRangeWeaponActor.generated.h"

class UBullet;
class AWorldBulletActor;

/**
 * Base actor for all range weapons
 */
UCLASS()
class PROJECTLOGOGRAM_API AWorldRangeWeaponActor : public AWorldWeaponActor
{
	GENERATED_BODY()

	
protected:
	// Number of bullets this weapon can load 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Clip")
	int32 ClipSize;
	
	// Array that stores bullets in the clip
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Clip")
	TArray<UBullet*> Clip;

	// Bullet spawned before launch 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Clip")
	AWorldBulletActor* PreSpawnedBullet;
};
