// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_Ememy.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Enemy_Bullet.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASS_Ememy::ASS_Ememy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComp"));
    RootComponent = CollisionComp;
    
    ShipSM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipSM"));
    ShipSM->SetupAttachment(RootComponent);
    
    BulletSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpawnPoint"));
    BulletSpawnPoint->SetupAttachment(RootComponent);
    
    ProjectileMove = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMove"));
    //FloatingMove->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASS_Ememy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASS_Ememy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    ShootCoolDown += DeltaTime;
    if(ShootCoolDown >= MaxShootCoolDown)
    {
        ShootCoolDown = 0.0f;
        if(Bullet_BP)
        {
            FVector Location = BulletSpawnPoint->GetComponentLocation();
            FRotator Rotation = BulletSpawnPoint->GetComponentRotation();
            GetWorld()->SpawnActor(Bullet_BP, &Location, &Rotation);
        }
    }
}

// Called to bind functionality to input
void ASS_Ememy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASS_Ememy::ExplodeAndDestroy()
{
    if(ExplosionParticle)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, GetActorTransform());
    }
    
    Destroy();
}

