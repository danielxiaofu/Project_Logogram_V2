// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ProjectLogogramCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "CombatSystem/CombatAnimationSet.h"
#include "Item/WorldWeaponActor.h"
#include "Status/StatComponent.h"


//////////////////////////////////////////////////////////////////////////
// AProjectLogogramCharacter

AProjectLogogramCharacter::AProjectLogogramCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	StatComponent = CreateDefaultSubobject<UStatComponent>(TEXT("StatComponent"));

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	bRotateWithCamera = false;
	ActiveMain = nullptr;
	ActiveSecondary = nullptr;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AProjectLogogramCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AProjectLogogramCharacter::RequestJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AProjectLogogramCharacter::OnAttack);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AProjectLogogramCharacter::FireRangeWeapon);

	PlayerInputComponent->BindAxis("MoveForward", this, &AProjectLogogramCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AProjectLogogramCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &AProjectLogogramCharacter::Turn);
	PlayerInputComponent->BindAxis("TurnRate", this, &AProjectLogogramCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AProjectLogogramCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AProjectLogogramCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AProjectLogogramCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AProjectLogogramCharacter::OnResetVR);
}

void AProjectLogogramCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bRotateWithCamera)
		RotateWithCamera();

	OnYawInputRecieved(TotalYawInput);
	TotalYawInput = 0.0;

	float CameraPitch = FollowCamera->GetForwardVector().Rotation().Pitch;
	OnPitchInputRecieved(CameraPitch);
	OnPitchUpdate.Broadcast(CameraPitch);
}

void AProjectLogogramCharacter::BeginPlay()
{
	// Instantiate CombatAnimSet classes
	for (TSubclassOf<UCombatAnimationSet> AnimSet : CombatAnimationSetClasses)
	{
		UCombatAnimationSet* NewAnimSet = NewObject<UCombatAnimationSet>(this, AnimSet);
		CombatAnimationSets.Add(NewAnimSet->WeaponType, NewAnimSet);
		FString Name = NewAnimSet->Name;
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Name)
	}

	Super::BeginPlay();
	CanMove = true;

}

UCombatAnimationSet * AProjectLogogramCharacter::GetActiveAnimationSet()
{
	if (ActiveMain)
	{
		ActiveCombatAnimationSet = CombatAnimationSets[ActiveMain->WeaponType];
	}
	else
	{
		ActiveCombatAnimationSet = CombatAnimationSets[EWeaponType::VE_Undefined];

	}
	return ActiveCombatAnimationSet;
}


void AProjectLogogramCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AProjectLogogramCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AProjectLogogramCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AProjectLogogramCharacter::FireRangeWeapon()
{
	OnWeaponFire.Broadcast();
}

void AProjectLogogramCharacter::EnableSpecialModeRotation(bool Enable)
{
	GetCharacterMovement()->bOrientRotationToMovement = !Enable;
	bRotateWithCamera = Enable;
}

void AProjectLogogramCharacter::RotateWithCamera()
{
	FVector ActorForward = GetActorForwardVector();
	ActorForward.Z = 0.0;
	ActorForward.Normalize();
	float ActorYaw = ActorForward.Rotation().Yaw + 180.0;
	FVector CameraForward = FollowCamera->GetForwardVector();
	CameraForward.Z = 0.0;
	CameraForward.Normalize();
	float CameraYaw = CameraForward.Rotation().Yaw + 180.0;
	float Difference1 = CameraYaw - ActorYaw;
	float Difference2 = 360.0 - fabsf(Difference1);
	Difference2 *= (Difference1 > 0.0 ? -1.0 : 1.0);
	float MinDifference = fabs(Difference1) < fabs(Difference2) ? Difference1 : Difference2;
	float ResultYaw;
	if (fabs(MinDifference) < GetWorld()->GetDeltaSeconds() * SpecialModeRotateSpeed)
		ResultYaw = CameraYaw;
	else
	{
		ResultYaw = ActorYaw += (GetWorld()->GetDeltaSeconds() * SpecialModeRotateSpeed * (MinDifference > 0.0 ? 1.0 : -1.0));
		if (ResultYaw < 0.0)
			ResultYaw += 360.0;
		else if (ResultYaw >= 360.0)
			ResultYaw -= 360.0;
	}
		
	ResultYaw -= 180.0;
	SetActorRotation(FRotator(GetActorRotation().Pitch, ResultYaw, GetActorRotation().Roll));
}

void AProjectLogogramCharacter::OnSpecialModeEnter()
{
	JumpMode = EJumpMode::VE_DODGE;
	if (bDrawWeapon)
	{
		if (ActiveMain)
			ActiveMain->OnSpecialModeEnter(this);
		if (ActiveSecondary)
			ActiveSecondary->OnSpecialModeEnter(this);
	}
	
}

void AProjectLogogramCharacter::OnSpecialModeLeave()
{
	JumpMode = EJumpMode::VE_JUMP;
	if (bDrawWeapon)
	{
		if (ActiveMain)
			ActiveMain->OnSpecialModeExit(this);
		if (ActiveSecondary)
			ActiveSecondary->OnSpecialModeExit(this);
	}
	
}

void AProjectLogogramCharacter::Turn(float Val)
{
	AddControllerYawInput(Val);
	TotalYawInput += Val;
}

void AProjectLogogramCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
	TotalYawInput += Rate;
}

void AProjectLogogramCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AProjectLogogramCharacter::MoveForward(float Value)
{
	if (!CanMove)
		return;

	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AProjectLogogramCharacter::MoveRight(float Value)
{
	if (!CanMove)
		return;

	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AProjectLogogramCharacter::RequestJump()
{
	if (!CanMove)
		return;

	switch (JumpMode)
	{
	case EJumpMode::VE_JUMP:
		Jump();
		break;
	case EJumpMode::VE_DODGE:
		break;
	default:
		break;
	}

	
}
