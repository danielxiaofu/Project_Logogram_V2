// Fill out your copyright notice in the Description page of Project Settings.

#include "StatModifier.h"

UStatModifier::UStatModifier() {
	Bias = EModifierBias::VE_Decrease;
	TargetStatus = ECharStatus::VE_Undefined;
	LifeSpan = 0;
	ModifyRate = 0;
	IsAlive = true;
	NoLife = false;
	Instant = false;
}

UStatModifier::UStatModifier(EModifierBias _Bias, ECharStatus _TargetStatus, float _LifeSpan, float _ModifyRate, bool _NoLife, bool _Instant)
{
	Bias = _Bias;
	TargetStatus = _TargetStatus;
	LifeSpan = _LifeSpan;
	ModifyRate = _ModifyRate;
	IsAlive = true;
	NoLife = _NoLife;
	Instant = _Instant;
}

void UStatModifier::Initialize(FCharStatModifier& StatModifierStruct)
{
	Bias = StatModifierStruct.Bias;
	TargetStatus = StatModifierStruct.TargetStatus;
	LifeSpan = StatModifierStruct.LifeSpan;
	ModifyRate = StatModifierStruct.ModifyRate;
	IsAlive = true;
	NoLife = StatModifierStruct.NoLife;
	Instant = StatModifierStruct.Instant;
}


