// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperFlipbookActor.h"
#include "HitEffect_FB.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API AHitEffect_FB : public APaperFlipbookActor
{
	GENERATED_BODY()
	
	virtual void BeginPlay() override;
	

public:

	/* Play flipbook at location
	*/
	UFUNCTION(BlueprintCallable)
	void PlayAtLocation(FVector Location);
	
protected:

	FTimerHandle TimerHandle_PlayTimer;

	UFUNCTION()
	void TimerEnd();
};
