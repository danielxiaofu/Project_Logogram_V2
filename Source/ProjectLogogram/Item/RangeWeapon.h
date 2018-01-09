// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "RangeWeapon.generated.h"

class UBullet;
class UAnimInstance;

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API URangeWeapon : public UItem
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	EItemType GetType() const override;
	
	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	int32 GetTypeInt() const override;

protected:

	/* Bullet spawned before the weapon fires (e.g. arrow) */
	UPROPERTY(BlueprintReadOnly)
	UBullet* PreSpawnBullet;

	/* Bullets in the clip  */
	UPROPERTY(BlueprintReadOnly)
	TArray<UBullet*> Clip;

public:
	
	/* Type of bullet this range weapon support */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<UBullet>> SupportBulletType;

	/** Called when the character requests aim, child class can implement this to 
	 * perform different behavior.
	 * @param TargetAnimInstance the anim instance needed to play montage
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void OnAimRequested(UAnimInstance* TargetAnimInstance);
	
	/** Call this to request aim
	 * @param TargetAnimInstance the anim instance needed to play montage
	 */
	UFUNCTION(BlueprintCallable)
	void RequestAim(UAnimInstance* TargetAnimInstance);

};
