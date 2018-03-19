// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Laser.generated.h"

class UParticleSystemComponent;

UCLASS(BlueprintType, Blueprintable)
class PROJECTLOGOGRAM_API ALaser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaser();

	UPROPERTY(BlueprintReadWrite)
	ALaser* ReflectedLaser = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxReflectionDepth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ReflectionDepth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsActivate = false;

	// Surface of the reflection, should be ignored by ReflectedLaser
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AActor* ReflectionSurface;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* ParticleSystem;

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Recursively destroy reflection laser and its reflection laser
	UFUNCTION(BlueprintCallable)
	void ClearReflection();
	

};
