// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

class AWorldWeaponActor;
class ICanPerformAttack;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTickDelegate, float, T);

UCLASS()
class PROJECTLOGOGRAM_API AEnemyCharacter : public ACharacter, public ICanPerformAttack
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	// Called every frame
	UPROPERTY(BlueprintAssignable)
	FTickDelegate TickDelegate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// The weapon this character will hold when spawned
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	TSubclassOf<AWorldWeaponActor> StartMainWeapon;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};