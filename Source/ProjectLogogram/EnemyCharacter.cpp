// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "Status/StatComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "AIController.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StatComponent = CreateDefaultSubobject<UStatComponent>(TEXT("StatComponent"));

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitializePerception();
}

void AEnemyCharacter::InitializePerception()
{
	FAISenseID Id = UAISense::GetSenseID(UAISense_Sight::StaticClass());
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController)
		return;
	auto Config = AIController->GetPerceptionComponent()->GetSenseConfig(Id);
	if (!Config)
		return;
	auto ConfigSight = Cast<UAISenseConfig_Sight>(Config);
	ConfigSight->SightRadius = SightRadius;
	ConfigSight->LoseSightRadius = LoseSightRadius;
	AIController->GetPerceptionComponent()->RequestStimuliListenerUpdate();
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TickDelegate.Broadcast(DeltaTime);
}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

