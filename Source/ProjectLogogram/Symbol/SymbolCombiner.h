// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SymbolTypeEnum.h"
#include "SymbolCombiner.generated.h"

/** This class is responsible for recieving click events from symbol button 
* and combine those symbols' ID together to determine the item they represent
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTLOGOGRAM_API USymbolCombiner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USymbolCombiner();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Called when a symbol button is clicked
	* @param SymbolType type of the symbol
	* @param ID id of the symbol
	*/
	void OnButtonClicked(ESymbolType SymbolType, int32 ID);

private:

	/** This 16-bit int represents the combination of all symbols of chosen, ID of each type is stored
	 * in the following two formats (order starts from least significant bit)
	 * for container symbols, 1~5th: PrimitiveID, 6~15th: ContainerID, 16th: 1(indicating this is a container symbol)
	 * for non-container symbols, 1~5th: PrimitiveID, 6~9th: LDecoratorID, 10~13th: BDecoratorID, 14~15th: RDecoratorID, 16th: 0(indicating this is a non-container symbol)
	 * In addition, the 5th bit(which is the last bit of PrimitiveID) indicates if this is an elemental primitive, 1 for elemental, 0 for non-elemental 
	 */
	UPROPERTY()
	int32 FinalID = 0;

	const int32 Primitive_Pos = 0;
	const int32 Container_Pos = 5;
	const int32 LDecorator_Pos = 5;
	const int32 BDecorator_Pos = 9;
	const int32 RDecorator_Pos = 13;
	const int32 HasContainer_Pos = 15;

	const int32 Primitive_Mask = 31 << Primitive_Pos; // 5 bits
	const int32 Container_Mask = 1023 << Container_Pos; // 10 bits
	const int32 LDecorator_Mask = 15 << LDecorator_Pos; // 4 bits
	const int32 BDecorator_Mask = 15 << BDecorator_Pos; // 4 bits
	const int32 RDecorator_Mask = 3 << RDecorator_Pos; // 2 bits

	const int32 MakeContainer = 1 << HasContainer_Pos;
	const int32 MakeNonContainer = !MakeContainer;
	
	void InsertPrimitive(int32 ID);

	void InsertContainer(int32 ID);

	void InsertLDecorator(int32 ID);

	void InsertBDecorator(int32 ID);

	void InsertRDecorator(int32 ID);

};
