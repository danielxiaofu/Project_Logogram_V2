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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Consumable)
	TArray<FCharStatModifier> StatModifiers;

	UFUNCTION(BlueprintCallable, Category = Consumable)
	void SetTarget(AProjectLogogramCharacter* TargetCharacter);

	UFUNCTION(BlueprintCallable, Category = Consumable)
	void Use();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Consumable)
	AProjectLogogramCharacter* Target = nullptr;

	
};
