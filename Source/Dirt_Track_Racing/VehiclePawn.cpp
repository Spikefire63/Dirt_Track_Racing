// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiclePawn.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "ChaosWheeledVehicleMovementComponent.h"


// Sets default values
AVehiclePawn::AVehiclePawn()
{
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

		// throttle 
		EnhancedInputComponent->BindAction(ThrottleAction, ETriggerEvent::Triggered, this, &AVehiclePawn::Throttle);

		// break 
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &AVehiclePawn::Brake);

		// handbrake 
		// EnhancedInputComponent->BindAction(HandBrakeAction, ETriggerEvent::Started, this, &AVehicalPawn::StartHandbrake);
		// EnhancedInputComponent->BindAction(HandBrakeAction, ETriggerEvent::Completed, this, &AVehicalPawn::StopHandbrake);
		// 
		// // look around 
		// EnhancedInputComponent->BindAction(CameraLookAction, ETriggerEvent::Triggered, this, &AVehicalPawn::LookAround);
		// 
		// // reset the vehicle 
		// EnhancedInputComponent->BindAction(ResetAction, ETriggerEvent::Triggered, this, &AVehicalPawn::ResetVehicle);
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
}

void AVehiclePawn::Brake(const FInputActionValue& Value)
{
	// get the input magnitude for the brakes
	float BreakValue = Value.Get<float>();

	// add the input
	ChaosVehicleMovement->SetBrakeInput(BreakValue);
}

