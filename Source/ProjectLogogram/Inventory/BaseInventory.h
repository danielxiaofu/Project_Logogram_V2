// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item/ItemTypeEnum.h"
#include "BaseInventory.generated.h"

class UItem;

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	UPROPERTY()
	UItem* ItemObject;

	UPROPERTY()
	int32 Stack;

	UPROPERTY()
	bool Stackable;

	FInventoryItem() {
		ItemObject = nullptr;
		Stack = 1;
		Stackable = false;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTLOGOGRAM_API UBaseInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	EItemType ItemType = EItemType::VE_Undefined;
	

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
