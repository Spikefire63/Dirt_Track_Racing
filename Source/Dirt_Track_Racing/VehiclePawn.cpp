// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiclePawn.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ChaosWheeledVehicleMovementComponent.h"


// Sets default values
AVehiclePawn::AVehiclePawn()
{
	// construct the back camera boom
	BackSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Back Spring Arm"));
	BackSpringArm->SetupAttachment(GetMesh());
	BackSpringArm->TargetArmLength = 650.0f;
	BackSpringArm->SocketOffset.Z = 150.0f;
	BackSpringArm->bDoCollisionTest = false;
	BackSpringArm->bInheritPitch = false;
	BackSpringArm->bInheritRoll = false;
	BackSpringArm->bEnableCameraRotationLag = true;
	BackSpringArm->CameraRotationLagSpeed = 2.0f;
	BackSpringArm->CameraLagMaxDistance = 50.0f;

	BackCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Back Camera"));
	BackCamera->SetupAttachment(BackSpringArm);

	//setting physics
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetCollisionProfileName(FName("Vehicle"));

	// get the Chaos Wheeled movement component
	ChaosVehicleMovement = CastChecked<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());
}

// Called every frame
void AVehiclePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVehiclePawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// steering 
		EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Triggered, this, &AVehiclePawn::Steering);
		EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Completed, this, &AVehiclePawn::Steering);

		// throttle 
		EnhancedInputComponent->BindAction(ThrottleAction, ETriggerEvent::Triggered, this, &AVehiclePawn::Throttle);
		
		// break 
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &AVehiclePawn::Brake);

		// reset the vehicle 
		// was not able to fully break this down to make it work. will do a later time
		//EnhancedInputComponent->BindAction(ResetAction, ETriggerEvent::Triggered, this, &AVehiclePawn::Reset);
	}

}

void AVehiclePawn::Steering(const FInputActionValue& Value)
{
	// get the input magnitude for steering
	float SteeringValue = Value.Get<float>();

	// add the input
	ChaosVehicleMovement->SetSteeringInput(SteeringValue);
}

void AVehiclePawn::Throttle(const FInputActionValue& Value)
{
	// get the input magnitude for the throttle
	float ThrottleValue = Value.Get<float>();

	// add the input
	ChaosVehicleMovement->SetThrottleInput(ThrottleValue);

	// was texting because vehicle was not moving at one point.
	//UE_LOG(LogTemp, Warning, TEXT("THROTTLE FIRED"));
}

void AVehiclePawn::Brake(const FInputActionValue& Value)
{
	// get the input magnitude for the brakes
	float BreakValue = Value.Get<float>();

	// add the input
	ChaosVehicleMovement->SetBrakeInput(BreakValue);
}

/*
void AVehiclePawn::Reset(const FInputActionValue& Value)
{
	// get the input magnitude for the brakes
	float ResetValue = Value.Get<float>();

	// add the input
	ChaosVehicleMovement->ResetVehicleState();
}
*/