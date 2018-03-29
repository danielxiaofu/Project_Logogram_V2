// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/ItemBag.h"
#include "SecondaryWeaponBag.generated.h"

class UItem;

/** This type of bag has an active type variable that allows only a 
 *  list of specific type of weapon to be returned when broadcasting event  
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateActiveDelegate, const TArray<FItemEntry>&, ItemArray);

UCLASS(BlueprintType)
class PROJECTLOGOGRAM_API USecondaryWeaponBag : public UItemBag
{
	GENERATED_BODY()

public:

	// Called when the active weapon list updates
	UPROPERTY(BlueprintAssignable, Category = "ItemBag")
	FUpdateActiveDelegate OnActiveListUpdate;

	UFUNCTION()
	void AddItem(UItem* Item) override;

	UFUNCTION(BlueprintCallable)
	void RemoveAllItems() override;
	
	/** Set the active type of the bag and fire an update event.
	  * @param ItemType type of the item to activate, pass 0 if no weapon will be active
	  */
	UFUNCTION(BlueprintCallable)
	void SetActiveType(int32 ItemType);

protected:

	// Specifies what type of weapon is stored in the active weapon array
	UPROPERTY(BlueprintReadOnly)
	int32 ActiveType;

	// An array that stores all weapons of type specified by ActiveType
	UPROPERTY()
	TArray<FItemEntry> ActiveWeapons;

	/* Update the active weapon list and fire an update event*/
	UFUNCTION()
	void UpdateActiveList();
};
