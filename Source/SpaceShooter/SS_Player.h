// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/AudioComponent.h"
#include "SS_Player.generated.h"

class ASS_Bullet;

UCLASS()
class SPACESHOOTER_API ASS_Player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASS_Player();
    
    UPROPERTY(EditAnywhere)
    USceneComponent* BulletSpawnPoint;
    
    UPROPERTY(EditAnywhere)
    UParticleSystemComponent* ParticleSystem;
    
    UPROPERTY(EditAnywhere)
    UParticleSystemComponent* ExplosionFX;
    
    UPROPERTY(EditAnywhere)
    UStaticMeshComponent* ShipMesh;
    
    UPROPERTY(EditAnywhere)
    UCapsuleComponent* CollisionComponent;
    
    UPROPERTY(EditAnywhere)
    UAudioComponent* DeathExplosionSound;
    
    UPROPERTY(EditAnywhere)
    float Field_Width; // 可移动区域的宽度
    
    UPROPERTY(EditAnywhere)
    float Field_Height; // 可移动区域高度
    
    UPROPERTY(BlueprintReadOnly)
    float Max_Health = 100.0f;
    
    UPROPERTY(BlueprintReadOnly)
    float Current_Health = 100.0f;
    
    UPROPERTY(BlueprintReadOnly)
    float Max_Armor = 100.0f;
    
    UPROPERTY(BlueprintReadOnly)
    float Current_Armor = 100.0f;
    
    UPROPERTY(EditAnywhere)
    float MaxVelocity = 250.0f;
    
    UPROPERTY(BlueprintReadOnly)
    float PlayerScore = 0.0f;
    
    bool bIsFiring = false;
    float WeaponFireRate = 0.25f;;
    float TimeSinceLastShot = 0.0f;;
    bool bHit = false;
    bool bDead = false;
    
    float Current_X_Velocity = 0.0f;
    float Current_Y_Velocity = 0.0f;
    
    FVector Current_Location;
    FRotator Current_Rotation;
    //FVector New_Locaiton;
    
    void MoveRight(float AxisValue);
    void MoveUp(float AxisValue);
    void FireWeapon();
    void StartFiring();
    void StopFiring();
    
    UFUNCTION()
    void OnBeginOverlap(AActor* PlayerActor, AActor* OtherActor);
    
    UPROPERTY(EditAnywhere)
    TSubclassOf<ASS_Bullet> Bullet_BP;

    void CollectPickup();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
