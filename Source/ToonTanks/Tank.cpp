// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->SetupAttachment(SpringArm);
	SpringArm->SetupAttachment(RootComponent);
}

void ATank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}

void ATank::Move(float Value)
{
	double DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = Value * Speed * DeltaTime;
	AddActorLocalOffset(DeltaLocation);
}
