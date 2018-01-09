// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/ItemBag.h"
#include "BulletBag.generated.h"

class UItem;
class UBullet;

/** A bullet bag maintains a list of support classes that only allow specific 
 *  type of bullet to be displayed
 */
UCLASS()
class PROJECTLOGOGRAM_API UBulletBag : public UItemBag
{
	GENERATED_BODY()
	
public:


protected:

	/* The list of support bullet classes */
	UPROPERTY(BlueprintReadOnly)
	TArray<TSubclassOf<UBullet>> SupportBullets;
	
	
};
