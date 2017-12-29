// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemFactoryManager.generated.h"

class UBulletFactory;

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

	UPROPERTY()
	UBulletFactory* BulletFactory;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

	
};
