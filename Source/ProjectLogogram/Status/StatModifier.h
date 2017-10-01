// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatusEnum.h"
#include "StatModifier.generated.h"

UENUM(BlueprintType)
enum class EModifierBias : uint8
{
	VE_Increase UMETA(DisplayName = "Increase"),
	VE_Decrease UMETA(DisplayName = "Decrease")
};

USTRUCT(BlueprintType)
struct FBaseStatModifier
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	EModifierBias Bias;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	float Amount;

	FBaseStatModifier()
	{
		Bias = EModifierBias::VE_Increase;
		Amount = 0;
	}

};

USTRUCT(BlueprintType)
struct FCharStatModifier : public FBaseStatModifier
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	ECharStatus TargetStatus;

	// How long does it take to modify the stat by amount, 0 means instant. Unit is sec.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	float LifeSpan;

	UPROPERTY()
	float ModifyRate;

	UPROPERTY()
	bool IsAlive;

	FCharStatModifier()
	{
		TargetStatus = ECharStatus::VE_Undefined;
		LifeSpan = 0;
		ModifyRate = 0;
		IsAlive = true;
	}

	void Activate()
	{
		IsAlive = true;
	}

	void Kill()
	{
		IsAlive = false;
	}

	void Initialize()
	{
		if (LifeSpan != 0)
			ModifyRate = Amount / LifeSpan;
	}

};




/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UStatModifier : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
