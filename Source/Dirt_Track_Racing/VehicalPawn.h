// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VehicalPawn.generated.h"

class UInputAction;
class UChaosWheeledVehicleMovementComponent;

UCLASS()
class DIRT_TRACK_RACING_API AVehicalPawn : public APawn
{
	GENERATED_BODY()


protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* Sterring;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* Throttle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* Brake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* HandBrake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* CameraLook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* Reset;

public:
	// Sets default values for this pawn's properties
	AVehicalPawn();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
