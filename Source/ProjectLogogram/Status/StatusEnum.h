// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatusEnum.generated.h"

UENUM(BlurprintTyle)
enum class EStatus : uint8
{
	VE_Health	UMETA(DisplayName = "Health"),
	VE_Stamina	UMETA(DisplayName = "Stamina"),
};

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UStatusEnum : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
