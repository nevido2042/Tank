// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn/TankHUD.h"
#include "Engine/Canvas.h"
#include "TankPawn.h"
#include "Kismet/GameplayStatics.h"

void ATankHUD::DrawHUD()
{
    Super::DrawHUD();

    FollowGunAim();
}

void ATankHUD::BeginPlay()
{
    TankPawn = Cast<ATankPawn>(GetOwningPawn());
}

void ATankHUD::FollowGunAim()
{
    FVector WorldPos = TankPawn->GunAimWorldLocation;
    FVector2d ScreenPos;

    UGameplayStatics::ProjectWorldToScreen(GetOwningPlayerController(), WorldPos, ScreenPos);

    DrawDebugCanvas2DCircle(Canvas, ScreenPos, 20.f, 50, FLinearColor::Green);
}
