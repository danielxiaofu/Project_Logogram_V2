// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "SymbolicItemLibrary.generated.h"


USTRUCT(BlueprintType)
struct FSymbolicItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FSymbolicItemData()
		: Type(0)
		, HasContainer(0)
		, Container(0)
		, BDecorator(0)
		, LDecorator(0)
		, Primitive(0)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SymbolicItem")
	int32 Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SymbolicItem")
	int32 HasContainer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SymbolicItem")
	int32 Container;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SymbolicItem")
	int32 BDecorator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SymbolicItem")
	int32 LDecorator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SymbolicItem")
	int32 Primitive;
};

USTRUCT(BlueprintType)
struct FSymbolicItem
{
	GENERATED_USTRUCT_BODY()

	FSymbolicItem()
		: ID(0)
		, Type(0)
		, Name("Undefined")
	{}

	UPROPERTY(BlueprintReadOnly)
	int32 ID;

	UPROPERTY(BlueprintReadOnly)
	int32 Type;

	UPROPERTY(BlueprintReadOnly)
	FString Name;

};

/** This class contains IDs of all items that can be created by combining symbols
 * 
 */
UCLASS()
class PROJECTLOGOGRAM_API USymbolicItemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:

	static TMap<int32, FSymbolicItem> SymbolicItems;
	
public:

	UFUNCTION(BlueprintCallable, Category = "SymbolicItem")
	static void AddSymbolicItem(FSymbolicItemData ItemData, FString Name);

	UFUNCTION(BlueprintCallable, Category = "SymbolicItem")
	static void ClearItemData();
	
};
