// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicalPawn.h"
#include "ChaosWheeledVehicleMovementComponent.h"

// Sets default values
AVehicalPawn::AVehicalPawn()
{
 	
	// get the Chaos Wheeled movement component
	ChaosVehicleMovement = CastChecked<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());
}

void AVehicalPawn::SetupPlayerInputComponent(UInputComponent* PlayerInput)
{
	Super::SetupPlayerInputComponent(PlayerInput);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInput))
	{
		// steering 
		EnhancedInputComponent->BindAction(SteeringAction, ETriggerEvent::Triggered, this, &AcarPawn::Steering);
	}
}

// Called every frame
void AVehicalPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVehicalPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

