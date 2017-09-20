// Fill out your copyright notice in the Description page of Project Settings.

#include "SymbolBitCombiner.h"

void USymbolBitCombiner::Lock(int32& TargetID, int32 TypePosition)
{
	int32 LockBit = 1 << (TypePosition + 3);
	TargetID = TargetID | LockBit;
}

void USymbolBitCombiner::UnLock(int32& TargetID, int32 TypePosition)
{
	int32 UnLockBit = ~(1 << (TypePosition + 3));
	TargetID = TargetID & UnLockBit;
}

bool USymbolBitCombiner::IsLocked(int32& TargetID, int32 TypePosition)
{
	int32 CheckBit = 1 << (TypePosition + 3);
	int32 Result = TargetID & CheckBit;

	return Result == 0 ? false : true;
}

void USymbolBitCombiner::InsertPrimitive(int32& FinalID, int32 PrimitiveID, bool PerformLock)
{
	if (PerformLock)
	{
		// RoL 1. When a type insertion is requested, if it's locked, reject request, otherwise accept request and lock this type.
		if (IsLocked(FinalID, Primitive_Pos))
		{
			int32 Primitive = (FinalID & Primitive_Mask) >> Primitive_Pos;
			UE_LOG(LogTemp, Warning, TEXT("Insert primitive rejected, primitive exists, primitive=%d"), Primitive)
		}
		else
		{
			FinalID = FinalID | (PrimitiveID << Primitive_Pos);
			Lock(FinalID, Primitive_Pos);
			// RoL 4. When a primitive is inserted: if container is not locked, unlock element and material, otherwise lock material and element (all locked).
			if (!IsLocked(FinalID, Container_Pos))
			{
				UnLock(FinalID, Element_Pos);
				UnLock(FinalID, Material_Pos);
			}
			else
			{
				Lock(FinalID, Element_Pos);
				Lock(FinalID, Material_Pos);
			}
		}
	}
	else
		FinalID = FinalID | (PrimitiveID << Primitive_Pos);
	
}

void USymbolBitCombiner::InsertContainer(int32 & FinalID, int32 ContainerID, bool PerformLock)
{
	if (PerformLock)
	{
		// RoL 1.
		if (IsLocked(FinalID, Container_Pos))
		{
			int32 Container = (FinalID & Container_Mask) >> Container_Pos;
			UE_LOG(LogTemp, Warning, TEXT("Insert container rejected, container exists, container=%d"), Container)
		}
		else
		{
			FinalID = FinalID | (ContainerID << Container_Pos);
			Lock(FinalID, Container_Pos);
			// RoL 3. When a container is inserted: unlock element; Lock material; If primitive is locked, lock element (all locked).
			UnLock(FinalID, Element_Pos);
			Lock(FinalID, Material_Pos);
			if (IsLocked(FinalID, Primitive_Pos))
				Lock(FinalID, Element_Pos);
		}
	}
	else
		FinalID = FinalID | (ContainerID << Container_Pos);
	
}

void USymbolBitCombiner::InsertMaterial(int32 & FinalID, int32 MaterialID, bool PerformLock)
{
	if (PerformLock)
	{
		// RoL 1.
		if (IsLocked(FinalID, MaterialID))
		{
			int32 Material = (FinalID & Material_Mask) >> Material_Pos;
			UE_LOG(LogTemp, Warning, TEXT("Insert material rejected, material exists, material=%d"), Material)
		}
		else
		{
			FinalID = FinalID | (MaterialID << Material_Pos);
			Lock(FinalID, Material_Pos);
			// RoL 6. When a material is inserted: lock container.
			Lock(FinalID, Material_Pos);
		}	
	}
	else
		FinalID = FinalID | (MaterialID << Material_Pos);
	
}

void USymbolBitCombiner::InsertElement(int32 & FinalID, int32 ElementID, bool PerformLock)
{
	if (PerformLock)
	{
		// RoL 1.
		if (IsLocked(FinalID, Element_Pos))
		{
			int32 Element = (FinalID & Element_Mask) >> Element_Pos;
			UE_LOG(LogTemp, Warning, TEXT("Insert element rejected, element exists, element=%d"), Element)
		}
		else
		{
			FinalID = FinalID | (ElementID << Element_Pos);
			Lock(FinalID, Element_Pos);
			// RoL 5. When an element is inserted: if container is locked, lock primitive (all locked); if primitive is locked, lock container.
			if (IsLocked(FinalID, Container_Pos))
				Lock(FinalID, Primitive_Pos);
			if (IsLocked(FinalID, Primitive_Pos))
				Lock(FinalID, Container_Pos);
		}
	}
	else
		FinalID = FinalID | (ElementID << Element_Pos);

}



