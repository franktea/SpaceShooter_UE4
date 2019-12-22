// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SS_Ememy.generated.h"

UCLASS()
class SPACESHOOTER_API ASS_Ememy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASS_Ememy();

    UPROPERTY(EditAnywhere)
    USceneComponent* BulletSpawnPoint;
    
    UPROPERTY(EditAnywhere, Category = "Component")
    class USphereComponent* CollisionComp;
    
    UPROPERTY(EditAnywhere, Category="Component")
    class UStaticMeshComponent* ShipSM;
    
    UPROPERTY(EditAnywhere, Category="Component")
    class UProjectileMovementComponent* ProjectileMove;
    
    UPROPERTY(EditAnywhere, Category="Component")
    TSubclassOf<class ASS_Bullet> Bullet_BP;
    
    float Speed = 300.0f;
    
    UPROPERTY(EditAnywhere, Category="Particle")
    class UParticleSystem* ExplosionParticle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    void ExplodeAndDestroy();
private:
    const float MaxShootCoolDown = 2.0f;
    float ShootCoolDown = 0.0f;
};
