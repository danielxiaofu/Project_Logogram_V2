// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CanBeFrozen.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCanBeFrozen : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTLOGOGRAM_API ICanBeFrozen
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnChill();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ExitChill();
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnFreeze();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ExitFreeze();
};
