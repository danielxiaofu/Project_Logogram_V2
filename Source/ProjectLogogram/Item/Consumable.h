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
	void Initialize(AProjectLogogramCharacter* TargetCharacter, FName ItemName, int32 ItemID, TArray<FCharStatModifier> Modifiers);

	UFUNCTION(BlueprintCallable, Category = Consumable)
	void Use();

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	EItemType GetType() const override;

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	int32 GetTypeInt() const override;

protected:


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Consumable)
	AProjectLogogramCharacter* Target = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Consumable)
	TArray<FCharStatModifier> StatModifiers;
};
