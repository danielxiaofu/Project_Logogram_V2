// Fill out your copyright notice in the Description page of Project Settings.

#include "HitReactionComponent.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "CombatAnimationSet.h"

// Sets default values for this component's properties
UHitReactionComponent::UHitReactionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHitReactionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHitReactionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector UHitReactionComponent::PlayFourDirectionHitAnimation(FVector HitDirection, FVector ActorLeftDirection, FVector ActorFrontDirection, UCombatAnimationSet * ActiveAnimationSet, UAnimInstance * AnimationBlueprint)
{
	// Project the hit direction on unit Y and X vector and pick the larger one
	FVector ReactionDirection = FVector(0, 0, 0);

	float LeftDot = FVector::DotProduct(HitDirection, ActorLeftDirection);
	float FrontDot = FVector::DotProduct(HitDirection, ActorFrontDirection);
	bool MoreLeft = fabs(LeftDot) >= fabs(FrontDot);
	float SelectedDot = MoreLeft ? LeftDot : FrontDot;

	FVector LeftProject = HitDirection.ProjectOnTo(ActorLeftDirection);
	FVector FrontProject = HitDirection.ProjectOnTo(ActorFrontDirection);
	FVector SelectProject = MoreLeft ? LeftProject : FrontProject;
	ReactionDirection = SelectProject;

	// Play hit animation base on the direction of the projected vector
	UAnimMontage* PositiveDir = MoreLeft ? ActiveAnimationSet->HitLeft : ActiveAnimationSet->HitFront;
	UAnimMontage* NegativeDir = MoreLeft ? ActiveAnimationSet->HitRight : ActiveAnimationSet->HitBack;
	UAnimMontage* MontageToPlay = SelectedDot >= 0 ? PositiveDir : NegativeDir;
	if(MontageToPlay)
		AnimationBlueprint->Montage_Play(MontageToPlay);

	return ReactionDirection;
}

