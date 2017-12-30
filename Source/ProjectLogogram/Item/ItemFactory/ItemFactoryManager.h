// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../../Symbol/SymbolicItemLibrary.h"
#include "ItemFactoryManager.generated.h"

class UBulletFactory;
class UItemBagManager;

/** This actor component is responsible for recieving item creation event
  * and calls corresponding factory to create item objects
  */

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTLOGOGRAM_API UItemFactoryManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UItemFactoryManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "ItemFactory")
	TSubclassOf<UBulletFactory> BulletFactoryClass;

	UPROPERTY()
	UBulletFactory* BulletFactory;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Given a symbolic item from the stone plate, create the item object and store it in 
	  *  the item bag based on type
	  * @param Item the symbolic item to create based on
	  * @param ItemBagManager the manager of the bag to store the item in
	  */
	UFUNCTION(BlueprintCallable)
	void CreateItem(FSymbolicItem Item, UItemBagManager* ItemBagManager);

	
};
