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

	/* The secondary weapon that this weapon supports,
	 * ignore this variable if this weapon is considered to be a secondary.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32  SupportedSecondaryWeaponType;

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	virtual EItemType GetType() const override;
	
	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	virtual int32 GetTypeInt() const override;
};
