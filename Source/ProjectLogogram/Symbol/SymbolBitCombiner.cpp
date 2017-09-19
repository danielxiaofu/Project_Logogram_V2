// Fill out your copyright notice in the Description page of Project Settings.

#include "SymbolBitCombiner.h"

void USymbolBitCombiner::InsertPrimitive(int32& FinalID, int32 PrimitiveID)
{
	int32 Primitive = (FinalID & Primitive_Mask) >> Primitive_Pos;

	if (Primitive != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, primitive already exists, primitive=%d"), Primitive)
	else
		FinalID = FinalID | (PrimitiveID << Primitive_Pos);

}

void USymbolBitCombiner::InsertContainer(int32 & FinalID, int32 ContainerID)
{
	int32 Container = (FinalID & Container_Mask) >> Container_Pos;
	int32 HasContainer = (FinalID & MakeContainer) >> HasContainer_Pos;

	if (HasContainer == 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, trying to insert container to a non-container symbol"))
	else if (Container != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, container already exists, container=%d"), Container)
	else
	{
		FinalID = FinalID | (ContainerID << Container_Pos);
		FinalID = FinalID | MakeContainer;
	}
}

void USymbolBitCombiner::InsertLDecorator(int32 & FinalID, int32 DecoratorID)
{
	int32 LDecorator = (FinalID & LDecorator_Mask) >> LDecorator_Pos;
	int32 HasContainer = (FinalID & MakeContainer) >> HasContainer_Pos;

	if (HasContainer != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, trying to insert decorator to a container symbol"))

	else if (LDecorator != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, ldecorator already exists, ldecorator=%d"), LDecorator)
	else
		{
			FinalID = FinalID | (DecoratorID << LDecorator_Pos);
			
			FinalID = FinalID & MakeNonContainer;
		}
}

void USymbolBitCombiner::InsertBDecorator(int32 & FinalID, int32 DecoratorID)
{
	int32 BDecorator = (FinalID & BDecorator_Mask) >> BDecorator_Pos;
	int32 HasContainer = (FinalID & MakeContainer) >> HasContainer_Pos;

	if (HasContainer != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, trying to insert decorator to a container symbol"))
		if (BDecorator != 0)
			UE_LOG(LogTemp, Warning, TEXT("Insert aborted, bdecorator already exists, bdecorator=%d"), BDecorator)
		else
		{
			FinalID = FinalID | (DecoratorID << BDecorator_Pos);
			FinalID = FinalID & MakeNonContainer;
		}
}

void USymbolBitCombiner::InsertRDecorator(int32 & FinalID, int32 DecoratorID)
{
	int32 RDecorator = (FinalID & RDecorator_Mask) >> RDecorator_Pos;
	int32 HasContainer = (FinalID & MakeContainer) >> HasContainer_Pos;

	if (HasContainer != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, trying to insert decorator to a container symbol"))
		if (RDecorator != 0)
			UE_LOG(LogTemp, Warning, TEXT("Insert aborted, rdecorator already exists, rdecorator=%d"), RDecorator)
		else
		{
			FinalID = FinalID | (DecoratorID << RDecorator_Pos);
			FinalID = FinalID & MakeNonContainer;
		}
}

void USymbolBitCombiner::MakeIDContainer(int32 & FinalID)
{
	FinalID = FinalID | MakeContainer;
}


