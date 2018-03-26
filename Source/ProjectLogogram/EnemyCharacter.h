// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Status/HasStatEntry.h"
#include "Status/CanBeOnFire.h"
#include "Status/CanBeFrozen.h"
#include "EnemyCharacter.generated.h"

class AWorldWeaponActor;
class UStatComponent;
class ICanPerformAttack;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTickDelegate, float, T);

UCLASS()
class PROJECTLOGOGRAM_API AEnemyCharacter : public ACharacter, public ICanPerformAttack, public IHasStatEntry, public ICanBeOnFire, public ICanBeFrozen
{
	GENERATED_BODY()

	/** StatComponent */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CharacterStat, meta = (AllowPrivateAccess = "true"))
	UStatComponent* StatComponent;

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	// Called every frame
	UPROPERTY(BlueprintAssignable)
	FTickDelegate TickDelegate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void InitializePerception();

public:	

	// The weapon this character will hold when spawned
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
	TSubclassOf<AWorldWeaponActor> StartMainWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception")
	float SightRadius = 3000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception")
	float LoseSightRadius = 3600;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
