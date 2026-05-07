// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceGameModeBase.h"
#include "VehiclePlayerController.h"
#include "OffroadPawn.h"

ARaceGameModeBase::ARaceGameModeBase()
{
	DefaultPawnClass = AOffroadPawn::StaticClass();
	PlayerControllerClass = AVehiclePlayerController::StaticClass();
}
