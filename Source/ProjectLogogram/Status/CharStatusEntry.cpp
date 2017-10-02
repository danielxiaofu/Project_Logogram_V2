// Fill out your copyright notice in the Description page of Project Settings.

#include "CharStatusEntry.h"

void UCharStatusEntry::ApplyModification(EModifierBias Bias, float ByAmount){
	switch (Bias)
		{
		case EModifierBias::VE_Increase:
			Amount += ByAmount;
			Amount = Amount > MaxAmount ? MaxAmount : Amount;
			break;
		case EModifierBias::VE_Decrease:
			Amount -= ByAmount;
			Amount = Amount < 0 ? 0 : Amount;
			break;
		default:
			break;
		}
}

void UCharStatusEntry::Initialize(ECharStatus Type, float Max){
	StatType = Type;
	MaxAmount = Max;
	Amount = MaxAmount;
}


