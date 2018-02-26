// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatusEnum.generated.h"

UENUM(BlueprintType)
enum class ECharStatus : uint8
{
	VE_Undefined UMETA(DisplayName = "Undefined"),
	VE_Health	UMETA(DisplayName = "Health"),
	VE_Stamina	UMETA(DisplayName = "Stamina"),
	VE_Temperature		UMETA(DisplayName = "Temperature")
};

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UStatusEnum : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
