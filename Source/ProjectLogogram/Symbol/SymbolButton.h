// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "SymbolTypeEnum.h"
#include "SymbolButton.generated.h"

class USymbolCombiner;

/**
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API USymbolButton : public UButton
{
	GENERATED_BODY()

	USymbolButton();

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESymbolType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsLocked;
	
	/** Bind a SymbolCombiner to this button so that the symbol combiner will recieve its click event
	 * @param Combiner the SymbolCombiner to bind with
	 */
	UFUNCTION(BlueprintCallable, Category = "SymbolButton")
	void BindSymbolCombiner(USymbolCombiner* Combiner);

	UFUNCTION(BlueprintCallable, Category = "SymbolButton")
	void BindLockDelegate();

	// Reset button to its original lock status
	UFUNCTION(BlueprintCallable, Category = "SymbolButton")
	void Reset();

private:

	/** Keep a reference of the SymbolCombiner in order to call its click event listener
	*/
	UPROPERTY()
	USymbolCombiner* SymbolCombiner;

	UFUNCTION()
	void OnSelfClicked();

	UFUNCTION()
	void OnLockCommandRecieved(ESymbolType SymbolType, bool IsLock);
	
};
