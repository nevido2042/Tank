// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn/TankController.h"
#include "TankPawn.h"

void ATankController::BeginPlay()
{
    Super::BeginPlay();

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(PlayerMappingContext, 1);
    }

    TankPawn = Cast<ATankPawn>(GetPawn());
}

void ATankController::Tick(float DeltaTime)
{
    TankPawn->CameraLineTrace();
}

void ATankController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ATankController::Look);
    }
}

void ATankController::Look(const FInputActionValue& Value)
{
    AddYawInput(Value.Get<FVector>().X * LookYawScale);
    AddPitchInput(Value.Get<FVector>().Y * LookPitchScale * -1.f);
}
