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

	UPROPERTY()
	UItem* Item;

	UPROPERTY()
	int32 Number;

	bool operator== (const FItemEntry& Rhs) const {
		bool Result;
		if (Item)
			Result = Item->Equals(Rhs.Item);
		else
			Result = false;

		return Result;
	}

};

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

	UFUNCTION()
	void AddItem(UItem* Item);

protected:

	UPROPERTY(BlueprintReadOnly)
	TArray<FItemEntry> Items;
	
	
};
