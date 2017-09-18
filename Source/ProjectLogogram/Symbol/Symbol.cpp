// Fill out your copyright notice in the Description page of Project Settings.

#include "Symbol.h"

USymbol::USymbol()
{
	Type = ESymbolType::VE_Undefined;
	ID = 0;
}

USymbol::USymbol(ESymbolType SymbolType, int32 SymbolId)
{
	Type = SymbolType;
	ID = SymbolId;
}

