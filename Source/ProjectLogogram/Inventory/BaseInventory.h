// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item/ItemTypeEnum.h"
#include "Item/Item.h"
#include "BaseInventory.generated.h"

// TODO: This class is no longer used, consider delete it in the future

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	UPROPERTY()
	UItem* ItemObject;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item System")
	int32 Stack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item System")
	FName Name;

	FInventoryItem() {
		ItemObject = nullptr;
		Stack = 0;
		Name = FName("");
	}

	FInventoryItem(UItem* ItemObj) {
		ItemObject = ItemObj;
		Stack = 1;
		Name = ItemObj->Name;
	}

	bool operator== (const FInventoryItem& Rhs) const {
		bool Result;
		if (ItemObject)
			Result = ItemObject->Equals(Rhs.ItemObject);
		else
			Result = false;

		return Result;
	}

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTLOGOGRAM_API UBaseInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBaseInventory();

	// Type of item in this inventory
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemSystem)
	EItemType ItemType = EItemType::VE_Undefined;

	// If item can be stacked together
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemSystem)
	bool Stackable;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly, Category = ItemSystem)
	TArray<FInventoryItem> StoredItem;

	// Index of current selected item
	UPROPERTY()
	int32 CurrentIndex = 0;

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	bool IsEmpty() const;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	void AddItem(UItem* Item);
	
	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	FInventoryItem GetSelectedItem();

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	FInventoryItem GetNextItem();

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	FInventoryItem GetSecondNextItem();

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	FInventoryItem GetPreviousItem();

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	FInventoryItem GetSecondPreviousItem();

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	FInventoryItem SelectNextItem();

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	FInventoryItem SelectPreviousItem();

};
