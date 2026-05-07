// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VehiclePawn.h"
#include "GameFramework/PlayerController.h"
#include "VehiclePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class AVehiclePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	TObjectPtr<AVehiclePawn> Vehicle;
	
protected:

	virtual void BeginPlay() override;
	
	virtual void OnPossess(APawn* InPawn) override;
};
