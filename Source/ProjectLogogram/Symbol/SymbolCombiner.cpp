// Fill out your copyright notice in the Description page of Project Settings.

#include "SymbolCombiner.h"


// Sets default values for this component's properties
USymbolCombiner::USymbolCombiner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void USymbolCombiner::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USymbolCombiner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USymbolCombiner::OnButtonClicked(ESymbolType SymbolType, int32 ID)
{
	switch (SymbolType)
	{
	case ESymbolType::VE_Primitive:
		InsertPrimitive(ID);
		break;
	case ESymbolType::VE_Container:
		InsertContainer(ID);
		break;
	case ESymbolType::VE_LDecorator:
		InsertLDecorator(ID);
		break;
	case ESymbolType::VE_BDecorator:
		InsertBDecorator(ID);
		break;
	case ESymbolType::VE_RDecorator:
		InsertRDecorator(ID);
		break;
	case ESymbolType::VE_Undefined:
		break;
	default:
		break;
	}
}

void USymbolCombiner::InsertPrimitive(int32 ID)
{
	int32 Primitive = (FinalID & Primitive_Mask) >> Primitive_Pos;
	if (Primitive != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, primitive already exists, primitive=%d"), Primitive)
	else
		FinalID = FinalID | (ID << Primitive_Pos);

}

void USymbolCombiner::InsertContainer(int32 ID)
{
	int32 Container = (FinalID & Container_Mask) >> Container_Pos;
	int32 HasContainer = (FinalID & MakeContainer) >> HasContainer_Pos;
	
	if (HasContainer == 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, trying to insert container to a non-container symbol"))
	else if (Container != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, container already exists, container=%d"), Container)
	else
	{
		FinalID = FinalID | (ID << Container_Pos);
		FinalID = FinalID | MakeContainer;
	}
		
}

void USymbolCombiner::InsertLDecorator(int32 ID)
{
	int32 LDecorator = (FinalID & LDecorator_Mask) >> LDecorator_Pos;
	int32 HasContainer = (FinalID & MakeContainer) >> HasContainer_Pos;

	if(HasContainer != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, trying to insert decorator to a container symbol"))
	if(LDecorator != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, ldecorator already exists, ldecorator=%d"), LDecorator)
	else
	{
		FinalID = FinalID | (ID << LDecorator_Pos);
		FinalID = FinalID & MakeNonContainer;
	}
}

void USymbolCombiner::InsertBDecorator(int32 ID)
{
	int32 BDecorator = (FinalID & BDecorator_Mask) >> BDecorator_Pos;
	int32 HasContainer = (FinalID & MakeContainer) >> HasContainer_Pos;

	if (HasContainer != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, trying to insert decorator to a container symbol"))
	if (BDecorator != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, bdecorator already exists, bdecorator=%d"), BDecorator)
	else
	{
		FinalID = FinalID | (ID << BDecorator_Pos);
		FinalID = FinalID & MakeNonContainer;
	}
}

void USymbolCombiner::InsertRDecorator(int32 ID)
{
	int32 RDecorator = (FinalID & RDecorator_Mask) >> RDecorator_Pos;
	int32 HasContainer = (FinalID & MakeContainer) >> HasContainer_Pos;

	if (HasContainer != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, trying to insert decorator to a container symbol"))
	if (RDecorator != 0)
		UE_LOG(LogTemp, Warning, TEXT("Insert aborted, rdecorator already exists, rdecorator=%d"), RDecorator)
	else
	{
		FinalID = FinalID | (ID << RDecorator_Pos);
		FinalID = FinalID & MakeNonContainer;
	}
}