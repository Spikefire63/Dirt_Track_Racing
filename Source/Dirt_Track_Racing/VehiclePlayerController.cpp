// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiclePlayerController.h"
#include "VehiclePawn.h"
#include "EnhancedInputSubsystems.h"

void AVehiclePlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AVehiclePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

//allows the player to posses the vehicle
void AVehiclePlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	Vehicle = CastChecked<AVehiclePawn>(InPawn);
}



