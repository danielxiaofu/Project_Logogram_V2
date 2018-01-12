// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/WorldItemActor.h"
#include "WeaponTypeEnum.h"
#include "WorldWeaponActor.generated.h"

class ACharacter;

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API AWorldWeaponActor : public AWorldItemActor
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

	/** Called when this item is picked by a character
	 * @param NewOwner the character who picked up the item
	 */
	UFUNCTION()
	virtual void OnItemPickUp(AProjectLogogramCharacter* NewOwner);

	/** Called when this weapon actor is set as the active weapon
	 * @param Owner the character who activated this weapon
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnActivate(ACharacter* OwnerCharacter);

	/* Called when this weapon is no longer the active weapon 
	 * @param Owner the character who deactivated this weapon
	 */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDeactivate(ACharacter* OwnerCharacter);

};
