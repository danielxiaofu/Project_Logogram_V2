// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SymbolBitCombiner.generated.h"

/** This class takes ID of symbols and combine them in one 16-bit int
 * This 16-bit int represents the combination of all symbols of chosen, ID of each type is stored
 * in the following two formats (order starts from LSB)
 * 1~4th: PrimitiveID, 5~8th: MaterialID, 9~12th: ElementID, 13~16th Container.
 * Each type has 4bits, the 4th bit (MSB) being 1 means this type portion is locked.
 * If a type is locked, this ID will not accept insertion of that type
 * Rules of lock (RoL):
 * 1. When a type insertion is requested, if it's locked, reject request, otherwise accept request and lock this type.
 * 2. Element and material are locked by default, container and primitive are unlocked by default
 * 3. When a container is inserted: unlock element; Lock material; If primitive is locked, lock element (all locked).
 * 4. When a primitive is inserted: if container is not locked, unlock element and material, otherwise lock material and element (all locked).
 * 5. When an element is inserted: if container is locked, lock primitive (all locked); if primitive is locked, lock container.
 * 6. When a material is inserted: lock container.
 * These rules are just for the programmer, players don't have to memorize.
 */
UCLASS()
class PROJECTLOGOGRAM_API USymbolBitCombiner : public UObject
{
	GENERATED_BODY()
	
private:
	// Define starting positions for each symbol type, index starts from zero at least significant bit
	static const int32 Primitive_Pos = 0;
	static const int32 Container_Pos = 12;
	static const int32 Material_Pos = 4;
	static const int32 Element_Pos =8;

	static const int32 Primitive_Mask = 15 << Primitive_Pos;
	static const int32 Container_Mask = 15 << Container_Pos;
	static const int32 Material_Mask = 15 << Material_Pos;
	static const int32 Element_Mask = 15 << Element_Pos;
	
	/** Lock a specific type by making the 4th bit of that type 1
	 * @param TargetID the ID to perform lock
	 * @param TypePosition starting position of the type
	 */
	static void Lock(int32& TargetID, int32 TypePosition);

	/** UnkLock a specific type by making the 4th bit of that type 0
	 * @param TargetID the ID to perform unlock
	 * @param TypePosition starting position of the type
	 */
	static void UnLock(int32& TargetID, int32 TypePosition);

	/** Check if a given type is locked
	 * @param TargetID the ID to check lock
	 * @param TypePosition the starting position of the type
	 * @return true if locked, otherwise false
	 */
	static bool IsLocked(int32& TargetID, int32 TypePosition);

public:
	static void InsertPrimitive(int32& FinalID, int32 PrimitiveID, bool PerformLock);
	
	static void InsertContainer(int32& FinalID, int32 ContainerID, bool PerformLock);

	static void InsertMaterial(int32& FinalID, int32 MaterialID, bool PerformLock);

	static void InsertElement(int32& FinalID, int32 ElementID, bool PerformLock);

};
