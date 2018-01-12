// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "RangeWeapon.generated.h"

class UBullet;
class UAnimInstance;
class UItemBag;

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
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnAimRequested(UAnimInstance* TargetAnimInstance);
	
	/** Called when the character needs to load bullets into this weapon, 
	  * implement this event to perform different behavior with different weapon.
	  * @param BulletBag the bulletbag to retrieve bullets from
	  * return bool true if reload succeed
	  */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool OnReloadRequested(UItemBag* BulletBag);
};
