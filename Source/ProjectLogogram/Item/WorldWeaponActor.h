// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/WorldItemActor.h"
#include "WeaponTypeEnum.h"
#include "Status/DamageTypeCustom.h"
#include "WorldWeaponActor.generated.h"

class ACharacter;
class AHitEffect_FB;
class UDamageType;
class ICanPerformHit;

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API AWorldWeaponActor : public AWorldItemActor, public ICanPerformHit
{
	GENERATED_BODY()
	
public:

	/* Type of the weapon actor, this property determines the animation set played during combat*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponProperty")
	EWeaponType WeaponType;

	/* Name of the socket this weapon will attach to in sheath mode */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponProperty")
	FName SheathSocket;

	/* Name of the socket this weapon will attach to in draw mode */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "WeaponProperty")
	FName DrawSocket;

	/* The hit effect played when this weapon hits others */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HitEffect")
	TSubclassOf<AHitEffect_FB> HitEffectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "DamageType")
	TArray<FDamageTypeStruct> DamageTypes;

	virtual void K2_DestroyActor() override;

	/** Called when this item is picked by a character
	 * @param NewOwner the character who picked up the item
	 */
	UFUNCTION()
	virtual void OnItemPickUp(AProjectLogogramCharacter* NewOwner);

	/** Called when this weapon actor is set as the active weapon
	 * @param OwnerCharacter the character who activated this weapon
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnActivate(ACharacter* OwnerCharacter);

	/* Called when this weapon is no longer the active weapon 
	 * @param OwnerCharacter the character who deactivated this weapon
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDeactivate(ACharacter* OwnerCharacter);

	/* Called when this weapon is sheathed
	 * @param OwnerCharacter the character who deactivated this weapon
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSheath(ACharacter* OwnerCharacter);

	/* Called when enters special mode
	 * @param OwnerCharacter the character who deactivated this weapon
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSpecialModeEnter(ACharacter* OwnerCharacter);

	/* Called when exits special mode
	* @param OwnerCharacter the character who deactivated this weapon
	*/
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSpecialModeExit(ACharacter* OwnerCharacter);

	/* Enable physics simulation of the root static mesh component, nothing
	 * happen if the root is not a static mesh
	 */
	UFUNCTION(BlueprintCallable)
	void EnablePhysicsSimulation();

protected:

	UPROPERTY(BlueprintReadWrite, Category = "HitEffect")
	AHitEffect_FB* HitEffect = nullptr;
};
