// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatModifier.h"
#include "CharStatusEntry.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FStatUpdateDelegate, float, Value);

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTLOGOGRAM_API UCharStatusEntry : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly)
	ECharStatus StatType = ECharStatus::VE_Undefined;

	UPROPERTY(BlueprintReadOnly)
	float MaxAmount = 100;

	UPROPERTY(BlueprintReadOnly)
	float Amount = 100;

	// Called when the stat is updated
	UPROPERTY(BlueprintAssignable)
	FStatUpdateDelegate StatUpdateDelegate;

	UFUNCTION()
	void ApplyModification(EModifierBias Bias, float ByAmount);

	UFUNCTION()
	void Initialize(ECharStatus Type, float Max);

	
};
