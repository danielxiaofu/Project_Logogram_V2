// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatModifier.h"
#include "StatComponent.generated.h"

/* Any actor that uses this component has stat entries such as health, stamina
 * 
 */

class UCharStatusEntry;

 // A struct version of CharStatusEntry 
USTRUCT(BlueprintType)
struct FCharStatEntryStruct
{
	GENERATED_BODY()

	// Type of status, should be same as the key
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStat")
	ECharStatus StatType = ECharStatus::VE_Undefined;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStat")
	float MaxAmount = 100;

};

USTRUCT(BlueprintType)
struct FCharacterStat
{
	GENERATED_BODY()

	// Map of CharStatEntryStruct, exposed in blueprint for data-driven purpose
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterStat")
	TMap<ECharStatus, FCharStatEntryStruct> StatEntryMap;

	// Actual map that stores CharStat
	UPROPERTY()
	TMap<ECharStatus, UCharStatusEntry*> StatusMap;

	UPROPERTY()
	TArray<FCharStatModifier> Modifiers;

	// Copy every element from StatEntryMap to StatusMap
	void InitializeStatusObject();

	/** Add a modifier to actor
	* @param Modifier modifier to add
	* return reference to added modifier
	*/
	FCharStatModifier& AddModifier(FCharStatModifier Modifier);

	void UpdateModifiers(float Delta);

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTLOGOGRAM_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStat)
	FCharacterStat Stat;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "CharacterStat")
	float GetHealth() const;

	// Stat related function
	UFUNCTION(BlueprintCallable, Category = "CharacterStat")
	FCharStatModifier& AddStatModifier(FCharStatModifier Modifier);
	
	UFUNCTION(BlueprintCallable, Category = "CharacterStat")
	UCharStatusEntry* GetStatusEntry(ECharStatus CharStatus) const;
};