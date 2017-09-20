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
	VE_Material UMETA(DisplayName = "Material"),
	VE_Element UMETA(DisplayName = "Element"),
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
