// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Status/StatModifier.h"
#include "Item/WeaponTypeEnum.h"
#include "Status/HasStatEntry.h"
#include "ProjectLogogramCharacter.generated.h"

class UCharStatusEntry;
class UCombatAnimationSet;
class AWorldWeaponActor;
class UItemBagManager;
class UStatComponent;

UENUM(BlueprintType)
enum class EJumpMode : uint8
{
	VE_JUMP UMETA(DisplayName = "Jump"),
	VE_DODGE UMETA(DisplayName ="Dodge")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFireWeaponDelegate);

UCLASS(config=Game)
class AProjectLogogramCharacter : public ACharacter, public IHasStatEntry
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** StatComponent */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CharacterStat, meta = (AllowPrivateAccess = "true"))
	UStatComponent* StatComponent;

public:
	AProjectLogogramCharacter();

	/** Called when the character fires a range weapon */
	UPROPERTY(BlueprintAssignable)
	FFireWeaponDelegate OnWeaponFire;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = CombatAnimationSet)
	TArray<TSubclassOf<UCombatAnimationSet>> CombatAnimationSetClasses;

	/* Self-rotation speed in special mode (degrees per second) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SelfRotation")
	float SpecialModeRotateSpeed;

	/** Current equiped main weapon*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	AWorldWeaponActor* ActiveMain = nullptr;

	/** Current equiped secondary weapon */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	AWorldWeaponActor* ActiveSecondary = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Jump")
	EJumpMode JumpMode;

	/** Whether to rotate character with camera in XY plane*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SelfRotation")
	bool bRotateWithCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Weapon")
	bool bDrawWeapon;

protected:

	/** Whether this character can process move input */
	UPROPERTY(BlueprintReadOnly, Category = CharacterMovement)
	bool CanMove;


	UPROPERTY(BlueprintReadOnly, Category = CombatAnimationSet)
	TMap<EWeaponType, UCombatAnimationSet*> CombatAnimationSets;

	UPROPERTY()
	UCombatAnimationSet* ActiveCombatAnimationSet;

	/* Total yaw input calculated by adding turn and turn-at-rate*/
	UPROPERTY()
	float TotalYawInput;

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** Called for jump input*/
	void RequestJump();

	/**
	* Called via input to turn.
	* @param Val	Value to add to the yaw input
	*/
	void Turn(float Val);

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

	/** Fire the range weapon if there is any. */
	UFUNCTION()
	void FireRangeWeapon();

	/* Rotate the character to match same forward rotation as the camera*/
	UFUNCTION()
	void RotateWithCamera();

	UFUNCTION(BlueprintImplementableEvent, Category = "SelfRotation")
	void OnYawInputRecieved(float Val);

	UFUNCTION(BlueprintImplementableEvent, Category = "SelfRotation")
	void OnPitchInputRecieved(float Val);

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

	/** Set whether this character can accept movement input */
	UFUNCTION(BlueprintCallable, Category = "CharacterMovement")
	void SetCanMove(bool CanCharacterMove) { CanMove = CanCharacterMove; }
	// End of Stat related function

	/** Handler for when an attack input fires. */
	UFUNCTION(BlueprintImplementableEvent, Category = "Attack")
	void OnAttack();

	/** return the combat animation set based on active weapon in right hand. */
	UFUNCTION(BlueprintCallable, Category = "CombatAnimationSet")
	UCombatAnimationSet* GetActiveAnimationSet();

	/** Called when the character enters special mode */
	UFUNCTION(BlueprintCallable, Category = "SpecialMode")
	void OnSpecialModeEnter();

	/** Called when the character finishes leaving special mode */
	UFUNCTION(BlueprintCallable, Category = "SpecialMode")
	void OnSpecialModeLeave();

	/* Called to set whether the character is in special mode rotation (rotate with camera) */
	UFUNCTION(BlueprintCallable, Category = "SelfRotation")
	void EnableSpecialModeRotation(bool Enable);

	/* Called when the initialization of item bag manager is finished, the finished bag manager is passed*/
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void OnBagInitializationFinished(UItemBagManager* ItemBagManager);
};

