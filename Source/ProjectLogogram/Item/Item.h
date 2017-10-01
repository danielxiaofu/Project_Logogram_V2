// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PROJECTLOGOGRAM_API UItem : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemSystem)
	FName Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemSystem)
	int32 ID;


};
