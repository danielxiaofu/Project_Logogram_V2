// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WeaponTypeEnum.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	VE_Undefined UMETA(DisplayName = "Undefined"),
	VE_SwordShield UMETA(DisplayName = "SwordShield"),
	VE_Bow UMETA(DisplayName = "Bow")
};

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UWeaponTypeEnum : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
