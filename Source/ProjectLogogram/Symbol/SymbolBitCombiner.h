// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SymbolBitCombiner.generated.h"

/** This class takes ID of symbols and combine them in one 16-bit int
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API USymbolBitCombiner : public UObject
{
	GENERATED_BODY()
	
private:
	static const int32 Primitive_Pos = 0;
	static const int32 Container_Pos = 5;
	static const int32 LDecorator_Pos = 5;
	static const int32 BDecorator_Pos = 9;
	static const int32 RDecorator_Pos = 13;
	static const int32 HasContainer_Pos = 15;

	static const int32 Primitive_Mask = 31 << Primitive_Pos; // 5 bits
	static const int32 Container_Mask = 1023 << Container_Pos; // 10 bits
	static const int32 LDecorator_Mask = 15 << LDecorator_Pos; // 4 bits
	static const int32 BDecorator_Mask = 15 << BDecorator_Pos; // 4 bits
	static const int32 RDecorator_Mask = 3 << RDecorator_Pos; // 2 bits

	static const int32 MakeContainer = 1 << HasContainer_Pos;
	static const int32 MakeNonContainer = ~MakeContainer;


public:
	static void InsertPrimitive(int32& FinalID, int32 PrimitiveID);
	
	static void InsertContainer(int32& FinalID, int32 ContainerID);

	static void InsertLDecorator(int32& FinalID, int32 DecoratorID);

	static void InsertBDecorator(int32& FinalID, int32 DecoratorID);

	static void InsertRDecorator(int32& FinalID, int32 DecoratorID);

	static void MakeIDContainer(int32& FinalID);
};
