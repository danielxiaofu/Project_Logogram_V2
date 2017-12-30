// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ItemFactory/ItemFactory.h"
#include "MeleeFactory.generated.h"

class UMeleeWeapon;

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UMeleeFactory : public UItemFactory
{
	GENERATED_BODY()
	
public:
	/** List of melee classes that can be created by this factory
	*
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemFactory")
	TMap<int32, TSubclassOf<UMeleeWeapon>> MeleeList;
	
	/** create melee item based on given ID
	* @param ID ID of the melee item
	* @param Name name to be assigned to the new item
	* return melee pointer, null if ID doesn't exist
	*/
	UFUNCTION(BlueprintCallable, Category = "ItemFactory")
	UMeleeWeapon* CreateItem(int32 ID, FString Name);
	
};
