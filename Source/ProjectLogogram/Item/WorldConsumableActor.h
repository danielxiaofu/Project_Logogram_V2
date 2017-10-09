// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/WorldItemActor.h"
#include "Status/StatModifier.h"
#include "WorldConsumableActor.generated.h"

class AProjectLogogramCharacter;

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API AWorldConsumableActor : public AWorldItemActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemEffect)
	TArray<FCharStatModifier> StatModifiers;

	UFUNCTION()
	virtual void OnItemPickUp(AProjectLogogramCharacter* NewOwner) override;

protected:

	
	
};
