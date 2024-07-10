// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankPawn.generated.h"

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
	FVector GetTargetLocation() { return TargetLocation; }

protected:
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* SKMeshComp = nullptr;

	UPROPERTY(EditAnywhere)
	AActor* TargetActor = nullptr;

	FVector TargetLocation;

};