// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "SS_Ememy.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
    RootComponent = WhereToSpawn;
}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
    //SpawnClasses.Add(ASS_Ememy::StaticClass());
    //UE_LOG(LogTemp, Warning, TEXT("Box: %s"), *WhereToSpawn->GetScaledBoxExtent().ToString());
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if(SpawnClasses.Num() <= 0)
    {
        return;
    }
    const int Index = FMath::RandRange(0, SpawnClasses.Num()-1);
    
    SpawnCoolDown += DeltaTime;
    if(SpawnCoolDown >= NextSpawnCoolDown)
    {
        FVector Location = WhereToSpawn->GetComponentLocation();
        float Y = WhereToSpawn->GetScaledBoxExtent().Y;
        Location.Y = FMath::RandRange(Location.Y - Y, Location.Y + Y);
        UE_LOG(LogTemp, Warning, TEXT("Should Spawn at: %s"), *Location.ToString());
        SpawnCoolDown = 0.0f;
        FRotator Rotation = GetActorRotation();
        Rotation.Pitch = 180.0;
        GetWorld()->SpawnActor(SpawnClasses[Index], &Location, &Rotation);
    }
}

