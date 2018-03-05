// Fill out your copyright notice in the Description page of Project Settings.

#include "CharStatusEntry.h"
#include "GameFramework/DamageType.h"

void UCharStatusEntry::ApplyModification(EModifierBias Bias, float ByAmount, UDamageType* DamageType){
	switch (Bias)
		{
		case EModifierBias::VE_Increase:
			Amount += ByAmount;
			Amount = Amount > MaxAmount ? MaxAmount : Amount;
			break;
		case EModifierBias::VE_Decrease:
			Amount -= ByAmount;
			Amount = Amount < MinAmount ? MinAmount : Amount;
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


