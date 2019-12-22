// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_Player.h"
#include "SS_Bullet.h"

// Sets default values
ASS_Player::ASS_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    BulletSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpawnPoint"));
    ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
    ExplosionFX = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ExplosionFX"));
    DeathExplosionSound = CreateDefaultSubobject<UAudioComponent>(TEXT("DeathExplosionSound"));
    
    BulletSpawnPoint->SetupAttachment(RootComponent);
    ShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
    ParticleSystem->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
    CollisionComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
    ExplosionFX->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
    DeathExplosionSound->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
    
}

// Called when the game starts or when spawned
void ASS_Player::BeginPlay()
{
	Super::BeginPlay();
	
    Current_Location = GetActorLocation();
    Current_Rotation = GetActorRotation();
    
    ExplosionFX->Deactivate();
    DeathExplosionSound->Deactivate();
    
    OnActorBeginOverlap.AddDynamic(this, &ASS_Player::OnBeginOverlap);
}

// Called every frame
void ASS_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    APlayerController* PC = Cast<APlayerController>(GetController());
    FVector MouseLocation, MouseDirection;
    PC->DeprojectMousePositionToWorld(MouseLocation,MouseDirection);
    FVector NewLocation = FVector(MouseLocation.X, MouseLocation.Y, GetActorLocation().Z);
    
    if(NewLocation.X > Field_Width)
    {
        NewLocation = FVector(Field_Width - 1.0f, NewLocation.Y, NewLocation.Z);
    }
    else if(NewLocation.X < -Field_Width)
    {
        NewLocation = FVector(-Field_Width + 1.0f, NewLocation.Y, NewLocation.Z);
    }
    
    if(NewLocation.Y > Field_Height)
    {
        NewLocation = FVector(NewLocation.X, Field_Height - 1.0f, NewLocation.Z);
    }
    else if(NewLocation.Y < -Field_Height)
    {
        NewLocation = FVector(NewLocation.X, -Field_Height + 1.0f, NewLocation.Z);
    }
    SetActorLocation(NewLocation);
    Current_Location = NewLocation;
   
    /*
    if(Current_Y_Velocity > 0.1f)
    {
        SetActorRotation(FRotator(Current_Rotation.Pitch + 45.f,
                                  Current_Rotation.Yaw,
                                  Current_Rotation.Roll));
    }
    else if(Current_Y_Velocity < -0.1f)
    {
        SetActorRotation(FRotator(Current_Rotation.Pitch - 45.f,
                                  Current_Rotation.Yaw,
                                  Current_Rotation.Roll));
    }*/
}

// Called to bind functionality to input
void ASS_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    //PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ASS_Player::MoveRight);
    //PlayerInputComponent->BindAxis(FName("MoveUp"), this, &ASS_Player::MoveUp);
    PlayerInputComponent->BindAction("Fire",IE_Pressed,this,&ASS_Player::FireWeapon);
    //PlayerInputComponent->BindAction("Fire",IE_Pressed,this,&ASS_Player::StartFiring);
    //PlayerInputComponent->BindAction("Fire", IE_Released, this, &ASS_Player::StopFiring);
}

void ASS_Player::OnBeginOverlap(AActor* PlayerActor, AActor* OtherActor)
{
    
}

void ASS_Player::MoveRight(float AxisValue)
{
    Current_X_Velocity = MaxVelocity * AxisValue;
}

void ASS_Player::MoveUp(float AxisValue)
{
    Current_Y_Velocity = MaxVelocity * AxisValue;
}

void ASS_Player::FireWeapon()
{
    if(Bullet_BP)
    {
        FVector Location = BulletSpawnPoint->GetComponentLocation();
        FRotator Rotation = BulletSpawnPoint->GetComponentRotation();
        GetWorld()->SpawnActor(Bullet_BP, &Location, &Rotation);
    }
}

void ASS_Player::StartFiring()
{
    
}

void ASS_Player::StopFiring()
{
    
}

void ASS_Player::CollectPickup()
{
    
}
