// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "RangeWeapon.generated.h"

class UBullet;
class ACharacter;

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
	UPROPERTY(BlueprintReadWrite)
	UBullet* PreSpawnBullet;

	/* Bullets in the clip  */
	UPROPERTY(BlueprintReadOnly)
	TArray<UBullet*> Clip;

public:
	
	/* Type of bullet this range weapon support */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<TSubclassOf<UBullet>> SupportBulletType;

	/** Called when the character requests aim, child class can implement this to 
	 * perform different behavior.
	 * @param TargetAnimInstance the anim instance needed to play montage
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnAimRequested(UAnimInstance* TargetAnimInstance);
	
	/** Called when the character needs to load bullets into this weapon, 
	  * implement this event to perform different behavior with different weapon.
	  * @param WeaponOwner the character that owns the weapon
	  * return bool true if reload succeed
	  */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool OnReloadRequested(ACharacter* WeaponOwner);

	/** Called when the character fires the weapon,
	  * implement this event to perform different behavior with different weapon.
	  * @param WeaponOwner the character that owns the weapon
	  */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnFireRequested(ACharacter* WeaponOwner);

	/** Check whether there is any support bullet in the bullet bag of owner character 
	  * @param WeaponOwner the character that owns the weapon
	  * return bool true if there is bullets to use
	  */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool HasBulletToUse(ACharacter* WeaponOwner);

};
