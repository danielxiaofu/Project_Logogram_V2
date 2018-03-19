// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanBeOnFire.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCanBeOnFire : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTLOGOGRAM_API ICanBeOnFire
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnFire();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnExtinct();
};
