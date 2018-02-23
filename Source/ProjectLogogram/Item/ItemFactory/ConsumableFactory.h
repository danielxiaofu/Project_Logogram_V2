// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ItemFactory/ItemFactory.h"
#include "ConsumableFactory.generated.h"

class UConsumable;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class PROJECTLOGOGRAM_API UConsumableFactory : public UItemFactory
{
	GENERATED_BODY()

public:
	/** List of consumable classes that can be created
	*
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemFactory")
	TMap<int32,TSubclassOf<UConsumable>> ConsumableList;
	
	/** create consumable item based on given ID
	* @param ID ID of the consumable item
	* @param Name name to be assigned to the new item
	* return consumable pointer, null if ID doesn't exist
	*/
	UFUNCTION(BlueprintCallable, Category = "ItemFactory")
	UConsumable* CreateItem(int32 ID, FString Name);
	
};
