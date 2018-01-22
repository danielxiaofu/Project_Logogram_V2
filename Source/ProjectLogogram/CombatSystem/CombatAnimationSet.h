// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Item/WeaponTypeEnum.h"
#include "CombatAnimationSet.generated.h"

class UAnimMontage;
class UBlendSpace1D;

/** This class stores the combat animation montages for one type of weapon
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class PROJECTLOGOGRAM_API UCombatAnimationSet : public UObject
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	FString Name = "Default";

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	EWeaponType WeaponType;
	
	/** Animation played when the character draws weapon
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	UAnimMontage* DrawAnimation;

	/** Animation played when the character sheath weapon
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	UAnimMontage* SheathAnimation;

	/** Animation played when the character enters special mode, only applies to melee weapon
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	UAnimMontage* EnterHold;

	/** Animation played when the weapon needs to reload, only apply to gun and crossbow
	 *
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	UAnimMontage* Reload;

	/** Combination of reload and aim, only apply to bow and slingshot
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	UAnimMontage* LoadAndAim;

	/* Aim weapon, only apply to range weapon */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	UAnimMontage* Aim;

	/* Play fire animation, only apply to range weapon */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	UAnimMontage* Fire;

	/** Animation played when the character performs attack combo
	*/
	UPROPERTY(EditDefaultsOnly, Category = "CombatAnimation")
	TArray<UAnimMontage*> AttackSequence;

	/** Played when the character is hit towards left 
	 */
	UPROPERTY(EditDefaultsOnly, Category = "CombatAnimation")
	UAnimMontage* HitLeft;

	/** Played when the character is hit towards right
	*/
	UPROPERTY(EditDefaultsOnly, Category = "CombatAnimation")
	UAnimMontage* HitRight;

	/** Played when the character is hit towards left
	*/
	UPROPERTY(EditDefaultsOnly, Category = "CombatAnimation")
	UAnimMontage* HitFront;

	/** Played when the character is hit towards back
	*/
	UPROPERTY(EditDefaultsOnly, Category = "CombatAnimation")
	UAnimMontage* HitBack;

	/** Return the number of animations in AttackSequence
	*/
	UFUNCTION(BlueprintCallable, Category = "CombatAnimation")
	int32 GetComboCount() { return AttackSequence.Num(); }

	/** Given index, return the attack animation in AttackSequence
	*/
	UFUNCTION(BlueprintCallable, Category = "CombatAnimation")
	UAnimMontage* GetAttackAnimation(int32 Index);
};
