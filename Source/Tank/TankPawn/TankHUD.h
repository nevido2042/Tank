// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TankHUD.generated.h"

/**
 * 
 */

class ATankPawn;
UCLASS()
class TANK_API ATankHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	void FollowGunAim();

private:
	ATankPawn* TankPawn = nullptr;
	
};
