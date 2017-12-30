// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "RangeWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API URangeWeapon : public UItem
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	EItemType GetType() override;
	
	
};
