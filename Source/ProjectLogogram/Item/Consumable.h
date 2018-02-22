// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "Status/StatModifier.h"
#include "Consumable.generated.h"

class AProjectLogogramCharacter;

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UConsumable : public UItem
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = Consumable)
	void Initialize(FName ItemName, int32 ItemID);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = Consumable)
	void OnUse();

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	EItemType GetType() const override;

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	int32 GetTypeInt() const override;

};
