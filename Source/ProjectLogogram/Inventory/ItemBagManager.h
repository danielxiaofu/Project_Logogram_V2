// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemBagManager.generated.h"

class UItemBag;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTLOGOGRAM_API UItemBagManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemBagManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	UItemBag* BulletBag;

	UPROPERTY()
	UItemBag* MainWeaponBag;

	UPROPERTY()
	UItemBag* SecondaryWeaponBag;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Add a bullet item to bullet bag
	 * @param Bullet bullet to be added
	 */
	UFUNCTION()
	void AddToBulletBag(UItem* Bullet);
	
	/** Add a weapon item to main weapon bag
	* @param Weapon weapon to be added
	*/
	UFUNCTION()
	void AddToMainWeaponBag(UItem* Weapon);

	/** Add a weapon item to secondary weapon bag
	* @param Weapon weapon to be added
	*/
	UFUNCTION()
	void AddToSecondaryWeaponBag(UItem* Weapon);
};
