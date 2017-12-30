// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ItemFactory/ItemFactory.h"
#include "RangeFactory.generated.h"

class URangeWeapon;

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API URangeFactory : public UItemFactory
{
	GENERATED_BODY()
	
public:
	/** List of range classes that can be created by this factory
	*
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemFactory")
	TMap<int32, TSubclassOf<URangeWeapon>> RangeList;
	
	/** create range item based on given ID
	* @param ID ID of the range item
	* @param Name name to be assigned to the new item
	* return range pointer, null if ID doesn't exist
	*/
	UFUNCTION(BlueprintCallable, Category = "ItemFactory")
	URangeWeapon* CreateItem(int32 ID, FString Name);
};
