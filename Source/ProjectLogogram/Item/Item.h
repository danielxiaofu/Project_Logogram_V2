// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemTypeEnum.h"
#include "Item.generated.h"

class AWorldItemActor;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PROJECTLOGOGRAM_API UItem : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ItemSystem)
	FName Name;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ItemSystem)
	int32 ID;

	/** The actor class that will be spawned if this item needs to be in the world
	*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ItemSystem)
	TSubclassOf<AWorldItemActor> WorldActor;

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	bool Equals(UItem* Rhs);

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	virtual EItemType GetType();

	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	virtual int32 GetTypeInt();

	/** Spawn the actor of this item using WorldActor property.
	 * If WorldActor is not specified, a nullptr will be returned.
	 */
	UFUNCTION(BlueprintCallable, Category = ItemSystem)
	AWorldItemActor* SpawnActor();
};

