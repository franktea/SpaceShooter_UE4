// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_Bullet.h"
#include "SS_Ememy.h"

// Sets default values
ASS_Bullet::ASS_Bullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
    RootComponent = RootComp;
    BulletSM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletSM"));
    BulletSM->SetupAttachment(RootComp);
    ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
}

// Called when the game starts or when spawned
void ASS_Bullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASS_Bullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASS_Bullet::NotifyActorBeginOverlap(AActor* OtherActor)
{
    Super::NotifyActorBeginOverlap(OtherActor);
    
    UE_LOG(LogTemp, Warning, TEXT("collect with %s"), *OtherActor->GetFName().ToString());
    ASS_Ememy* Ememy = Cast<ASS_Ememy>(OtherActor);
    if(Ememy)
    {
        Ememy->ExplodeAndDestroy();
        this->Destroy();
    }
}

