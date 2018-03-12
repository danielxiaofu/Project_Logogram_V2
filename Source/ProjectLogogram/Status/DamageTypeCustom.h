// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageTypeCustom.generated.h"

class UDamageType;

USTRUCT(BlueprintType)
struct FDamageTypeStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageType")
	TSubclassOf<UDamageType> DamageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DamageType")
	float DamageValue;

};

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UDamageTypeCustom : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
