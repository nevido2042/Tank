// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn/TankPawnAnim.h"
#include "TankPawn.h"
#include "Kismet/KismetMathLibrary.h"

void UTankPawnAnim::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	TankPawn = Cast<ATankPawn>(TryGetPawnOwner());
}

void UTankPawnAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	AimToTarget(DeltaSeconds);
}

void UTankPawnAnim::AimToTarget(float DeltaSeconds)
{
	if (TankPawn == nullptr) return;

	const FVector TargetLocation = TankPawn->GetGunLookLocation();
	const FTransform PawnTransform = TankPawn->GetActorTransform();

	{
		FVector TurretJntLocation = TankPawn->GetMesh()->GetSocketLocation(TEXT("turret_jnt"));
		FVector Direction = TargetLocation - TurretJntLocation;
		FVector Result = UKismetMathLibrary::InverseTransformDirection(PawnTransform, Direction);
		FRotator NewRotator = Result.Rotation();

		TurretJntRot = UKismetMathLibrary::RLerp(TurretJntRot, NewRotator, DeltaSeconds* TankPawn->TurretRotateScale, true);
	}

	{
		FVector GunJntLocation = TankPawn->GetMesh()->GetSocketLocation(TEXT("gun_jnt"));
		FVector Direction = TargetLocation - GunJntLocation;
		FVector Result = UKismetMathLibrary::InverseTransformDirection(PawnTransform, Direction);
		FRotator NewRotator = Result.Rotation();

		GunJntRot = UKismetMathLibrary::RLerp(GunJntRot, NewRotator, DeltaSeconds * TankPawn->GunUpDownScale, true);

		GunJntRot.Pitch = FMath::ClampAngle(GunJntRot.Pitch, TankPawn->GunPitchMin, TankPawn->GunPitchMax);
	}
}
