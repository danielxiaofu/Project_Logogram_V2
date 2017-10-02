// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatModifier.h"
#include "CharStatusEntry.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UCharStatusEntry : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY()
	ECharStatus StatType = ECharStatus::VE_Undefined;

	UPROPERTY()
	float MaxAmount = 100;

	UPROPERTY()
	float Amount = 100;

	UFUNCTION()
	void ApplyModification(EModifierBias Bias, float ByAmount);

	UFUNCTION()
	void Initialize(ECharStatus Type, float Max);
	
};
