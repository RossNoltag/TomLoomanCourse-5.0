// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFrameWork/ProjectileMovementComponent.h"
#include "particles/ParticleSystemComponent.h"

// Sets default values
ASProjectile::ASProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SpereComponet");
	SphereComp->SetCollisionProfileName("Projectile");

	RootComponent = SphereComp;


	ParticleSysComp = CreateDefaultSubobject<UParticleSystemComponent>("Particle Effect Component");
	ParticleSysComp->SetupAttachment(SphereComp);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Movement Componet");
	MovementComponent->InitialSpeed = 1000.0f;
	MovementComponent->bRotationFollowsVelocity = true;
	MovementComponent->bInitialVelocityInLocalSpace = true;
}

// Called when the game starts or when spawned
void ASProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

