// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "SymbolTypeEnum.h"
#include "SymbolButton.generated.h"

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
	
private:

	UFUNCTION()
	void OnSelfClicked();
};
