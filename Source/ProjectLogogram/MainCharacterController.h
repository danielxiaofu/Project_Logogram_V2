// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainCharacterController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScrollLeftDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScrollRightDelegate);

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API AMainCharacterController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintAssignable)
	FScrollLeftDelegate OnMenuScrollLeft;

	UPROPERTY(BlueprintAssignable)
	FScrollRightDelegate OnMenuScrollRight;

	/* Fire an event to scroll the menu left */
	UFUNCTION(BlueprintCallable)
	void MenuScrollLeft();

	/* Fire an event to scroll the menu right */
	UFUNCTION(BlueprintCallable)
	void MenuScrollRight();
	
};
