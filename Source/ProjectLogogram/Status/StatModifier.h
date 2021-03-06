// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatusEnum.h"
#include "StatModifier.generated.h"

UENUM(BlueprintType)
enum class EModifierBias : uint8
{
	VE_Increase UMETA(DisplayName = "Increase"),
	VE_Decrease UMETA(DisplayName = "Decrease")
};

/** 
*/

class UDamageType;

USTRUCT(BlueprintType)
struct FBaseStatModifier
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	EModifierBias Bias;

	FBaseStatModifier()
	{
		Bias = EModifierBias::VE_Increase;
	
	}

};

USTRUCT(BlueprintType)
struct FCharStatModifier : public FBaseStatModifier
{
	GENERATED_BODY()

	// What kind of status does this modifier apply to
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	ECharStatus TargetStatus;

	// How long does it take to modify the stat, 0 means instant. Unit is sec.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	float LifeSpan;

	// How much amount does it modify by per second. If Instant is true, this will be the total amount that got modified  
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	float ModifyRate;

	// If is true, the modifier will last forever until someone call its kill function
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	bool NoLife;

	/** If is true, the modifier will immediatly apply its effect when it is added to a target.
	 * Amount of modification equals ModifyRate.
	 * Same behavior can be achieved by setting LifeSpan to 0.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	bool Instant;

	/* The DamageType object, if there is any, that owns this modifier */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatModifier)
	UDamageType* DamageType;

	UPROPERTY()
	bool IsAlive;

	FCharStatModifier()
	{
		TargetStatus = ECharStatus::VE_Undefined;
		LifeSpan = 0;
		ModifyRate = 0;
		IsAlive = true;
		NoLife = false;
		Instant = false;
		DamageType = nullptr;
	}

	FCharStatModifier(EModifierBias bias,
		ECharStatus _TargetStatus,
		float _LifeSpan,
		float _ModifyRate,
		bool _NoLife,
		bool _Instant,
		UDamageType* _DamageType)
	{
		Bias = bias;
		TargetStatus = _TargetStatus;
		LifeSpan = _LifeSpan;
		ModifyRate = _ModifyRate;
		IsAlive = true;
		NoLife = _NoLife;
		Instant = _Instant;
		DamageType = _DamageType;
	}

	void Kill()
	{
		IsAlive = false;
	}

};

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECTLOGOGRAM_API UStatModifier : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY()
	EModifierBias Bias;

	UPROPERTY()
	ECharStatus TargetStatus;

	UPROPERTY()
	float LifeSpan;

	UPROPERTY()
	float ModifyRate;

	UPROPERTY()
	bool NoLife;

	UPROPERTY()
	bool Instant;

	UPROPERTY()
	bool IsAlive;

	/* The DamageType object, if there is any, that owns this modifier */
	UPROPERTY()
	UDamageType* DamageType = nullptr;

	UStatModifier();

	UStatModifier(EModifierBias _Bias, ECharStatus _TargetStatus, float _LifeSpan, float _ModifyRate, bool _NoLife, bool _Instant, UDamageType* _DamageType);
	
	UFUNCTION()
	void Initialize(FCharStatModifier& StatModifierStruct);

	UFUNCTION()
	void Kill() { IsAlive = false; }


protected:
};
