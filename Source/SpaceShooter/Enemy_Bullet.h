// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SS_Bullet.h"
#include "Enemy_Bullet.generated.h"

/**
 * 
 */
UCLASS()
class SPACESHOOTER_API AEnemy_Bullet : public ASS_Bullet
{
	GENERATED_BODY()
public:
    
    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

};
