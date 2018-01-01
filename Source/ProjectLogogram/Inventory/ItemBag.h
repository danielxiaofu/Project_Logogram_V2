// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemBag.generated.h"

class UItem;

USTRUCT(BlueprintType)
struct FItemEntry
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	UItem* Item;

	UPROPERTY(BlueprintReadOnly)
	int32 Amount;

	FItemEntry()
	{
		Item = nullptr;
		Amount = 0;
	}

	FItemEntry(UItem* Item_)
	{
		Item = Item_;
		Amount = 1;
	}

	bool operator== (const FItemEntry& Rhs) const {
		bool Result;
		if (Item)
			Result = Item->Equals(Rhs.Item);
		else
			Result = false;

		return Result;
	}

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdateDelegate, const TArray<FItemEntry>&, ItemArray);

/** Base class for all kinds of item bags
 * 
 */
UCLASS(BlueprintType)
class PROJECTLOGOGRAM_API UItemBag : public UObject
{
	GENERATED_BODY()
	
public:
	/** Whether same item can stack together 
	*/
	UPROPERTY(BlueprintReadOnly)
	bool Stackable;

	/** Called when the item array is updated
	 *  @param ItemArray a reference to the item array
	 */
	UPROPERTY(BlueprintAssignable, Category = "ItemBag")
	FUpdateDelegate UpdateDelegate;

	UFUNCTION()
	void AddItem(UItem* Item);

	UFUNCTION(BlueprintCallable)
	int32 ItemCount() { return Items.Num(); }

protected:

	UPROPERTY(BlueprintReadOnly)
	TArray<FItemEntry> Items;
	

	
};
