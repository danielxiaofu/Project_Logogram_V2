// Fill out your copyright notice in the Description page of Project Settings.

#include "CharStatusEntry.h"
#include "GameFramework/DamageType.h"

void UCharStatusEntry::ApplyModification(EModifierBias Bias, float ByAmount, UDamageType* DamageType){
	float NewAmount;
	switch (Bias)
		{
		case EModifierBias::VE_Increase:
			NewAmount = Amount + ByAmount;
			Amount = NewAmount > MaxAmount ? MaxAmount : NewAmount;
			break;
		case EModifierBias::VE_Decrease:
			NewAmount = Amount - ByAmount;
			Amount = NewAmount < MinAmount ? MinAmount : NewAmount;
			break;
		default:
			break;
		}
	StatUpdateDelegate.Broadcast(Amount, DamageType);
}

void UCharStatusEntry::Initialize(ECharStatus Type, float Max, float Min, float StartAmount){
	StatType = Type;
	MaxAmount = Max;
	MinAmount = Min;
	Amount = StartAmount;
}


