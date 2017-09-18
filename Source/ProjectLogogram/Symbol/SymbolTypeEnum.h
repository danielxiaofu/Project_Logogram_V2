// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SymbolTypeEnum.generated.h"

UENUM(BlueprintType)
enum class ESymbolType : uint8
{
	VE_Primitive UMETA(DisplayName = "Primitive"),
	VE_Container UMETA(DisplayName = "Container"),
	VE_LDecorator UMETA(DisplayName = "LDecorator"),
	VE_BDecorator UMETA(DisplayName = "BDecorator"),
	VE_RDecorator UMETA(DisplayName = "RDecorator"),
	VE_Undefined UMETA(DisplayName = "Undefined")

};

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API USymbolTypeEnum : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
