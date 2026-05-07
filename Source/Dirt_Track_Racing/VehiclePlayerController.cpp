// Fill out your copyright notice in the Description page of Project Settings.


#include "VehiclePlayerController.h"
#include "VehiclePawn.h"

void AVehiclePlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AVehiclePlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	Vehicle = CastChecked<AVehiclePawn>(InPawn);
}



