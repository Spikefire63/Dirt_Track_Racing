// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "VehiclePawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
class UChaosWheeledVehicleMovementComponent;
struct FInputActionValue;

UCLASS(abstract)
class AVehiclePawn : public AWheeledVehiclePawn
{
	GENERATED_BODY()

	/** Spring Arm for the back camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* BackSpringArm;

	/** Back Camera component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* BackCamera;

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
	
	/*
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ResetAction;
	*/

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

	//void Reset(const FInputActionValue& Value);
	
public:	
	
	
	/** Returns the back spring arm subobject */
	FORCEINLINE USpringArmComponent* GetBackSpringArm() const { return BackSpringArm; }
	/** Returns the back camera subobject */
	FORCEINLINE UCameraComponent* GetBackCamera() const { return BackCamera; }

	/** Returns the cast Chaos Vehicle Movement subobject */
	FORCEINLINE const TObjectPtr<UChaosWheeledVehicleMovementComponent>& GetChaosVehicleMovement() const { return ChaosVehicleMovement; }

};
