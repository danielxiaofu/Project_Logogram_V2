// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/MeleeWeapon.h"
#include "Shield.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UShield : public UMeleeWeapon
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	EItemType GetType() const override;

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	int32 GetTypeInt() const override;
	
	
};
