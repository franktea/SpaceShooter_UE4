// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SS_Bullet.generated.h"

UCLASS()
class SPACESHOOTER_API ASS_Bullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASS_Bullet();

    UPROPERTY(VisibleAnywhere, Category="Component")
    USceneComponent* RootComp;
    
    UPROPERTY(VisibleAnywhere, Category="Component")
    UStaticMeshComponent* BulletSM;
    
    UPROPERTY(VisibleAnywhere, Category="Component")
    UProjectileMovementComponent* ProjectileMovementComp;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
