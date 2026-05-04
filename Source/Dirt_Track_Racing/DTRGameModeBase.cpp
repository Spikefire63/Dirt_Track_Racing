// Fill out your copyright notice in the Description page of Project Settings.


#include "dtrGameModeBase.h"
#include "vehiclePlayerController.h"

AdtrGameMode :: AdtrGameMode() 
{
	PlayerControllerClass = VehiclePlayerController::StaticClass();
}


