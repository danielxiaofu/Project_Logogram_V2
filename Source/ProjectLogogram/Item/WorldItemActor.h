// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldItemActor.generated.h"

class UItem;
class AProjectLogogramCharacter;

// World representation of item object
UCLASS(Blueprintable)
class PROJECTLOGOGRAM_API AWorldItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldItemActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemSystem)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemSystem)
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemSystem)
	int32 Type;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = ItemSystem)
	UItem* ItemReference;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Called when this item is picked by a character
	* @param NewOwner the character who picked up the item
	*/
	UFUNCTION()
	virtual void OnItemPickUp(AProjectLogogramCharacter* NewOwner);
	
	UFUNCTION(BlueprintCallable)
	void SetInfo(FName _Name, int32 _ID, int32 _Type);

};
