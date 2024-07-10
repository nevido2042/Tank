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

	AimToTarget();
}

void UTankPawnAnim::AimToTarget()
{
	if (TankPawn == nullptr) return;

	FVector TurretJntLocation = TankPawn->GetMesh()->GetSocketLocation(TEXT("turret_jnt"));
	FVector TargetLocation = TankPawn->GetTargetLocation();
	FTransform PawnTransform = TankPawn->GetActorTransform();

	FVector Direction = TargetLocation - TurretJntLocation;
	FVector Result = UKismetMathLibrary::InverseTransformDirection(PawnTransform, Direction);
	TurretJntRot = Result.Rotation();
}
