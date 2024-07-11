// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UBoxComponent;
class UTankPawnMovementComponent;

UCLASS()
class TANK_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATankPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	USkeletalMeshComponent* GetMesh() { return SKMeshComp; }
	FVector GetGunLookLocation() { return GunLookLocation; }
	void CameraLineTrace();
	void GunLineTrace();

	UPROPERTY(EditAnywhere)
	float GunPitchMin = -10.f;

	UPROPERTY(EditAnywhere)
	float GunPitchMax = 35.f;

	UPROPERTY(EditAnywhere)
	float TurretRotateScale = 1.f;

	UPROPERTY(EditAnywhere)
	float GunUpDownScale = 0.5f;

	FVector GunAimWorldLocation;
protected:
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* SKMeshComp = nullptr;

	FVector GunLookLocation;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(EditAnywhere)
	UCameraComponent* FollowCamera = nullptr;

	UPROPERTY(EditAnywhere)
	UBoxComponent* BodyCollision = nullptr;

	UPROPERTY(EditAnywhere)
	UTankPawnMovementComponent* TankPawnMovementComponent = nullptr;
};
