// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemBagManager.generated.h"

class UItemBag;
class USecondaryWeaponBag;

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

	UPROPERTY(BlueprintReadOnly)
	UItemBag* BulletBag = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UItemBag* MainWeaponBag = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UItemBag* ConsumableBag = nullptr;

	UPROPERTY(BlueprintReadOnly)
	USecondaryWeaponBag* SecondaryWeaponBag = nullptr;

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

	/** Add a consumable item to consumable bag
	* @param Consumable consumable to be added
	*/
	UFUNCTION()
	void AddToConsumableBag(UItem* Consumable);

	/** Add a weapon item to secondary weapon bag
	* @param Weapon weapon to be added
	*/
	UFUNCTION()
	void AddToSecondaryWeaponBag(UItem* Weapon);

	/** Remove a bullet item from bullet bag 
	 *  @param Bullet bullet to be removed 
	 */
	UFUNCTION(BlueprintCallable)
	void RemoveFromBulletBag(UItem* Bullet);

	/** Remove a consumable item from consumable bag
	*  @param Consumable consumable to be removed
	*/
	UFUNCTION(BlueprintCallable)
	void RemoveFromConsumableBag(UItem* Consumable);

	/** Explicitly set bags, warning: calling this function will wipe original bag objects in this manager
	*/
	UFUNCTION(BlueprintCallable)
	void SetBags(UItemBag* _BulletBag, UItemBag* _MainWeaponBag, UItemBag* _ConsumableBag, USecondaryWeaponBag* _SecondaryWeaponBag);
};
