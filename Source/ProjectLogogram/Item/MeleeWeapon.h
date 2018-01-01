// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "MeleeWeapon.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UMeleeWeapon : public UItem
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	EItemType GetType() override;
	
	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	int32 GetTypeInt() override;
};