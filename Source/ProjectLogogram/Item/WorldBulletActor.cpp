// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldBulletActor.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"


AWorldBulletActor::AWorldBulletActor()
{
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	CalibrationFinished = false;
}

void AWorldBulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!ProjectileMovement->IsActive())
		return;
	if (CalibrationFinished)
		return;

	//Check whether the arrow has reached the center of the camera view
	FVector CameraToActor = GetActorLocation() - CameraLocation;
	CameraToActor.Normalize();
	if (FVector::DotProduct(CameraToActor, CameraFront) >= 1.0 - KINDA_SMALL_NUMBER)
	{
		// If reached to center, the arrow will be calibrated to fly straightforward
		FVector Velocity = GetVelocity();
		FVector Vertical = Velocity.ProjectOnTo(FVector(0.0, 0.0, -1.0));
		FVector CameraFrontXY = CameraFront;
		CameraFrontXY.Z = 0.0;
		FVector Forward = Velocity.ProjectOnTo(CameraFrontXY);
		ProjectileMovement->Velocity = Vertical + Forward;
		CalibrationFinished = true;
	}
}

void AWorldBulletActor::FireByPlayer(UCameraComponent * FollowCamera, AActor* _ItemOwner)
{
	CameraLocation = FollowCamera->GetComponentLocation();
	CameraFront = FollowCamera->GetForwardVector();
	FHitResult HitResult;
	ItemOwner = _ItemOwner;
	//Compute a trace that leads the arrow to the crosshair
	GetWorld()->LineTraceSingleByChannel(
		HitResult,
		CameraLocation,
		CameraFront * 1000 + CameraLocation,
		ECollisionChannel::ECC_Visibility
	);
	FVector EndLocation = HitResult.bBlockingHit ? HitResult.Location : HitResult.TraceEnd;
	
	FindVelocityTo(EndLocation);
	Launch();
	OnFireByPlayer();
}

void AWorldBulletActor::FireByAI(AActor* _ItemOwner)
{
	CalibrationFinished = true; // no need to calibrate when fired by ai
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	ItemOwner = _ItemOwner;
	Launch();
	OnFireByAI();
}

bool AWorldBulletActor::FindVelocityTo(FVector Destination)
{
	bool Result;

	FVector TossVelocity = FVector(0.0, 0.0, 0.0);
	Result = UGameplayStatics::SuggestProjectileVelocity(
		GetWorld(),
		TossVelocity,
		GetActorLocation(),
		Destination,
		LaunchSpeed,
		false,
		1.0f,
		0.0f,
		ESuggestProjVelocityTraceOption::DoNotTrace,
		FCollisionResponseParams::DefaultResponseParam,
		TArray<AActor*>(),
		false
	);

	ProjectileMovement->Velocity = TossVelocity;
	return Result;
}

void AWorldBulletActor::Launch()
{
	ProjectileMovement->Activate();
	// Activate hit volume collision
	DamageWindowOn = true;
}