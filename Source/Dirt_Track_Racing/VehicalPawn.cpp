// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicalPawn.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "ChaosWheeledVehicleMovementComponent.h"


// Sets default values
AVehicalPawn::AVehicalPawn()
{
	// get the Chaos Wheeled movement component
	ChaosVehicleMovement = CastChecked<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());
}

// Called every frame
void AVehicalPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVehicalPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// steering 
		EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Triggered, this, &AVehicalPawn::Steering);

		// throttle 
		EnhancedInputComponent->BindAction(ThrottleAction, ETriggerEvent::Triggered, this, &AVehicalPawn::Throttle);

		// break 
		EnhancedInputComponent->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &AVehicalPawn::Brake);

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

void AVehicalPawn::Steering(const FInputActionValue& Value)
{
	// get the input magnitude for steering
	float SteeringValue = Value.Get<float>();

	// add the input
	ChaosVehicleMovement->SetSteeringInput(SteeringValue);
}

void AVehicalPawn::Throttle(const FInputActionValue& Value)
{
	// get the input magnitude for the throttle
	float ThrottleValue = Value.Get<float>();

	// add the input
	ChaosVehicleMovement->SetThrottleInput(ThrottleValue);
}

void AVehicalPawn::Brake(const FInputActionValue& Value)
{
	// get the input magnitude for the brakes
	float BreakValue = Value.Get<float>();

	// add the input
	ChaosVehicleMovement->SetBrakeInput(BreakValue);
}

