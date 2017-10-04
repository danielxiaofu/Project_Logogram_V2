// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldItemActor.generated.h"

class UItem;

// World representation of item object
UCLASS(Blueprintable)
class PROJECTLOGOGRAM_API AWorldItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldItemActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	TSubclassOf<UItem> Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Item)
	UItem* ItemReference;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
