// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	VE_Undefined UMETA(DisplayName = "Undefined"),
	VE_Consumable UMETA(DisplayName = "Consumable"),
	VE_Spell UMETA(DisplayName = "Spell"),
	VE_Melee UMETA(DisplayName = "Melee"),
	VE_Range UMETA(DisplayName = "Range"),
	VE_Ammo UMETA(DisplayName = "Ammo"),
	VE_Throwable UMETA(DisplayName = "Throwable"),
	VE_Shield UMETA(DisplayName = "Shield")
};

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UItemTypeEnum : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
