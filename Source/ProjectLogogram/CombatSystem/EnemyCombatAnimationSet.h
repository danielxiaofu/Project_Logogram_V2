// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatSystem/CombatAnimationSet.h"
#include "EnemyCombatAnimationSet.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API UEnemyCombatAnimationSet : public UCombatAnimationSet
{
	GENERATED_BODY()
	
public:

	// Played when the character needs to turn left with his foot
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	UAnimMontage* TurnLeft;
	
	// Played when the character needs to turn left with his foot
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CombatAnimation")
	UAnimMontage* TurnRight;
};
