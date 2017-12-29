// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/ItemFactory/ItemFactory.h"
#include "BulletFactory.generated.h"

class UBullet;

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class PROJECTLOGOGRAM_API UBulletFactory : public UItemFactory
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemFactory")
	TMap<int32, TSubclassOf<UBullet>> BulletList;

	/** create bullet item based on given ID
	 * @param ID ID of the bullet item
	 * @param Name name to be assigned to the new item
	 * return bullet pointer, null if ID doesn't exist
	 */
	UFUNCTION(BlueprintCallable, Category = "ItemFactory")
	UBullet* CreateItem(int32 ID, FName Name);
	
};
