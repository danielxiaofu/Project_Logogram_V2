// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatAnimationSet.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"

UAnimMontage * UCombatAnimationSet::GetAttackAnimation(int32 Index)
{
	if (Index >= AttackSequence.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("Index out of bound when accessing AttackSequence, nullptr returned"))
			return nullptr;
	}
	return AttackSequence[Index];
}
