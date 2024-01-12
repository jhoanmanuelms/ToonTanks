// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"

void AToonTanksGameMode::BeginPlay()
{
    Super::BeginPlay();
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
    if (DeadActor == Tank)
    {
        Tank->HandleDestruction();
        auto TankPlayerController = Tank->GetPlayerController();

        if (TankPlayerController)
        {
            Tank->DisableInput(TankPlayerController);
            TankPlayerController->bShowMouseCursor = false;
        }
        UE_LOG(LogTemp, Error, TEXT("Adios mundo crueeeel"));
    }
    else if (ATower* DeadTower = Cast<ATower>(DeadActor))
    {
        DeadTower->HandleDestruction();
        UE_LOG(LogTemp, Error, TEXT("Muere sabandijaaa"));
    }
}
