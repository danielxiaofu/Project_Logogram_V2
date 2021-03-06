// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CombatUtility.generated.h"

UENUM(BlueprintType)
enum class EHitStrength : uint8
{
	VE_Light UMETA(DisplayName = "Light"),
	VE_Medium UMETA(DisplayName = "Medium"),
	VE_Heavy UMETA(DisplayName = "Heavy")
};

UENUM(BlueprintType)
enum class ELocalHitDirection : uint8
{
	VE_Undefined UMETA(DisplayName = "Undefined"),
	VE_Left UMETA(DisplayName = "Left"),
	VE_Right UMETA(DisplayName = "Right"),
	VE_Straight UMETA(DisplayName = "Straight")
};

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UCombatUtility : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
