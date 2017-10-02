// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Status/StatModifier.h"
#include "ProjectLogogramCharacter.generated.h"

class UCharStatusEntry;

// A struct version of CharStatusEntry 
USTRUCT(BlueprintType)
struct FCharStatEntryStruct
{
	GENERATED_BODY()

	// Type of status, should be same as the key
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStat")
	ECharStatus StatType = ECharStatus::VE_Undefined;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStat")
	float MaxAmount = 100;

};

USTRUCT(BlueprintType)
struct FCharacterStat
{
	GENERATED_BODY()

	// Map of CharStatEntryStruct, for data-driven initialization
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterStat")
	TMap<ECharStatus, FCharStatEntryStruct> StatEntryMap;

	// Actual map that stores CharStat
	UPROPERTY()
	TMap<ECharStatus, UCharStatusEntry*> StatusMap;

	UPROPERTY()
	TArray<FCharStatModifier> Modifiers;

	void InitializeStatusObject();

	FCharStatModifier& AddModifier(FCharStatModifier Modifier);
	
	void UpdateModifiers(float Delta);

};

UCLASS(config=Game)
class AProjectLogogramCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AProjectLogogramCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStat)
	FCharacterStat Stat;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// Stat related function
	

	// End of Stat related function

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable, Category = "CharacterStat")
	float GetHealth() const;

	// Stat related function
	UFUNCTION(BlueprintCallable, Category = "CharacterStat")
	FCharStatModifier& AddStatModifier(FCharStatModifier Modifier);


	// End of Stat related function
};

