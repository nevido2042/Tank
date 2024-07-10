// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TankPawnAnim.generated.h"

/**
 * 
 */
class ATankPawn;

UCLASS()
class TANK_API UTankPawnAnim : public UAnimInstance
{
	GENERATED_BODY()

protected:
	virtual void NativeInitializeAnimation();
	virtual void NativeUpdateAnimation(float DeltaSeconds);

	ATankPawn* TankPawn = nullptr;

	void AimToTarget();

	UPROPERTY(BlueprintReadOnly)
	FRotator TurretJntRot;

	UPROPERTY(BlueprintReadOnly)
	FRotator GunJntRot;
};
