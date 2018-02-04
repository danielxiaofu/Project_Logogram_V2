// Fill out your copyright notice in the Description page of Project Settings.

#include "HitEffect_FB.h"
#include "PaperFlipbookComponent.h"
#include "ProjectLogogramCharacter.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void AHitEffect_FB::BeginPlay()
{
	Super::BeginPlay();
	GetRenderComponent()->Stop();
	GetRenderComponent()->SetLooping(false);
}

void AHitEffect_FB::PlayAtLocation(FVector Location)
{
	AProjectLogogramCharacter* PlayerCharacter = dynamic_cast<AProjectLogogramCharacter*>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (!PlayerCharacter)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerCharacter cast failed in function PlayAtLocation in HitEffect"))
		return;
	}
	// Rotate the actor to face the camera
	FVector CameraLocation = PlayerCharacter->GetFollowCamera()->GetComponentLocation();
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(CameraLocation, Location);
	LookAtRotation.Yaw += 90;
	SetActorLocation(Location);
	SetActorRotation(LookAtRotation);

	GetRenderComponent()->PlayFromStart();
}
