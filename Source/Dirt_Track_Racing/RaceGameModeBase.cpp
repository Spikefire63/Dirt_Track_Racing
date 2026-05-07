// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceGameModeBase.h"
#include "VehiclePlayerController.h"

ARaceGameModeBase::ARaceGameModeBase()
{
	PlayerControllerClass = AVehiclePlayerController::StaticClass();
}
