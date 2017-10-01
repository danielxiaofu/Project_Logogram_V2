// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Status/StatModifier.h"
#include "ProjectLogogramCharacter.generated.h"

USTRUCT(BlueprintType)
struct FCharStatEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStat")
	float MaxAmount = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharacterStat")
	float Amount = 100;

	void Modify(EModifierBias Bias, float ByAmount) {
		switch (Bias)
		{
		case EModifierBias::VE_Increase:
			Amount += ByAmount;
			Amount = Amount > MaxAmount ? MaxAmount : Amount;
			break;
		case EModifierBias::VE_Decrease:
			Amount -= ByAmount;
			Amount = Amount < 0 ? 0 : Amount;
			break;
		default:
			break;
		}
	}

	void Initialize() {
		Amount = MaxAmount;
	}
};

USTRUCT(BlueprintType)
struct FCharacterStat
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterStat")
	TMap<ECharStatus, FCharStatEntry> StatusMap;

	UPROPERTY()
	TArray<FCharStatModifier> Modifiers;

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

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// Stat related function
	UFUNCTION(BlueprintCallable, Category = "CharacterStat")
	FCharStatModifier& AddModifier(FCharStatModifier Modifier);


	// End of Stat related function
};

