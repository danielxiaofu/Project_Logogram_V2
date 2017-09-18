// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SymbolTypeEnum.h"
#include "Symbol.generated.h"

/** Basic class for all symbols
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API USymbol : public UObject
{
	GENERATED_BODY()
	
public:

	USymbol();

	USymbol(ESymbolType SymbolType, int32 SymbolId);
	
	
private:

	UPROPERTY()
	ESymbolType Type;

	int32 ID;

};
