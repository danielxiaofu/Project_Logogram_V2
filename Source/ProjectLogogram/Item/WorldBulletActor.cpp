// Fill out your copyright notice in the Description page of Project Settings.

#include "WorldBulletActor.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"

AWorldBulletActor::AWorldBulletActor()
{
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
}
