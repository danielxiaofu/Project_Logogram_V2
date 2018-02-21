// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DecalActor.h"
#include "SymbolDecalActor.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API ASymbolDecalActor : public ADecalActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Info")
	int32 ID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Info")
	int32 Type;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item Info")
	FName Name;

	// Time to activate the symbol
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Decal Info")
	float ActivateTime;

	UFUNCTION(BlueprintCallable)
	void BeginActivate();

private:

	bool ActivateBegin;
};
