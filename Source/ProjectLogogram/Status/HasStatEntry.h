// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HasStatEntry.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHasStatEntry : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTLOGOGRAM_API IHasStatEntry
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	// Called when the StatComponent of the actor has finished initializing stat entry
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnStatEntryInitialized();


};
