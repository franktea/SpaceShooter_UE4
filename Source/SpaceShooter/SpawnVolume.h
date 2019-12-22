// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class SPACESHOOTER_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, Category="Spawing")
    class UBoxComponent* WhereToSpawn;
    
    UPROPERTY(EditAnywhere, Category="Spawning")
    TArray<TSubclassOf<AActor>> SpawnClasses;
private:
    const float MinSpawnCoolDown = 2.0f;
    const float MaxSpawnCollDown = 4.0f;
    float NextSpawnCoolDown = 2.0f;
    float SpawnCoolDown = 0.0f;
};
