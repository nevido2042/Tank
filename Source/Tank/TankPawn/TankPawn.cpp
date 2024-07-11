// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn/TankPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ATankPawn::ATankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BodyCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BodyCollision"));
	SetRootComponent(BodyCollision);

	SKMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SKMeshComp"));
	SKMeshComp->SetupAttachment(BodyCollision);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(SKMeshComp);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATankPawn::CameraLineTrace()
{
	float LineLength = 9999999.f;
	FVector LineStart = FollowCamera->GetComponentLocation();
	FVector LineEnd = LineStart + FollowCamera->GetComponentRotation().Vector() * LineLength;
	DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Green);

	FHitResult HitResult;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, LineStart, LineEnd, ECollisionChannel::ECC_Visibility);
	if (bHit)
	{
		GunLookLocation = HitResult.Location;

		DrawDebugLine(
			GetWorld(),
			LineStart,
			HitResult.Location,
			FColor::Green,
			false, 0.1f, 0, 0.1f
		);


		DrawDebugSphere(
			GetWorld(),
			HitResult.Location,
			12.0f,
			24,
			FColor::Green,
			false, 0.1f
		);
	}
}

void ATankPawn::GunLineTrace()
{
	float LineLength = 9999999.f;
	FVector LineStart = GetMesh()->GetSocketLocation(TEXT("gun_1_jntSocket"));
	FVector LineEnd = LineStart + GetMesh()->GetSocketRotation(TEXT("gun_1_jntSocket")).Vector() * LineLength;
	DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Red);

	FHitResult HitResult;
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, LineStart, LineEnd, ECollisionChannel::ECC_Visibility);
	if (bHit)
	{
		GunAimWorldLocation = HitResult.Location;

		DrawDebugLine(
			GetWorld(),
			LineStart,
			HitResult.Location,
			FColor::Red,
			false, 0.1f, 0, 0.1f
		);


		DrawDebugSphere(
			GetWorld(),
			HitResult.Location,
			12.0f,
			24,
			FColor::Red,
			false, 0.1f
		);
	}
}

