// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SymbolTypeEnum.h"
#include "SymbolCombiner.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemCreated, FString, Name);

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
	UPROPERTY(BlueprintAssignable, Category = "SymbolCombiner")
	FOnItemCreated OnItemCreated;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Called when a symbol button is clicked
	* @param SymbolType type of the symbol
	* @param ID id of the symbol
	*/
	void OnButtonClicked(ESymbolType SymbolType, int32 ID);

	// Reset ID back to 0
	UFUNCTION(BlueprintCallable, Category = "SymbolCombiner")
	void ResetID();

private:

	UPROPERTY()
	int32 FinalID = 0;


};
