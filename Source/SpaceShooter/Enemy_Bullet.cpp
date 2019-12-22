// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Bullet.h"
#include "SS_Player.h"

void AEnemy_Bullet::NotifyActorBeginOverlap(AActor* OtherActor)
{
    UE_LOG(LogTemp, Warning, TEXT("collect with %s"), *OtherActor->GetFName().ToString());
    ASS_Player* player = Cast<ASS_Player>(OtherActor);
    if(player)
    {
        player->Destroy();
        this->Destroy();
    }
}
