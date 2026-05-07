// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "VehiclePawn.generated.h"

class UInputAction;
class UChaosWheeledVehicleMovementComponent;
struct FInputActionValue;

UCLASS(abstract)
class AVehiclePawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()

	TObjectPtr<UChaosWheeledVehicleMovementComponent> ChaosVehicleMovement;
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* SteeringAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ThrottleAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* BrakeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* HandBrakeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* CameraLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ResetAction;

public:
	// Sets default values for this pawn's properties
	AVehiclePawn();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaTime) override;

protected:

	// sterring input
	void Steering(const FInputActionValue& Value);

	// throttle input
	void Throttle(const FInputActionValue& Value);

	// break input
	void Brake(const FInputActionValue& Value);

public:	
	// Called every frame
	

	/** Returns the cast Chaos Vehicle Movement subobject */
	FORCEINLINE const TObjectPtr<UChaosWheeledVehicleMovementComponent>& GetChaosVehicleMovement() const { return ChaosVehicleMovement; }

};
