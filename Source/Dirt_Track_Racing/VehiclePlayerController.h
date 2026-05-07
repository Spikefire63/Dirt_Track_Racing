//This is the player controller that allows the player to be spawned inside the vehicle and drive.

#pragma once

#include "CoreMinimal.h"
#include "VehiclePawn.h"
#include "GameFramework/PlayerController.h"
#include "VehiclePlayerController.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class AVehiclePlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	
	// creates the mapping of inputs for player input
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	TObjectPtr<AVehiclePawn> Vehicle;
	
protected:

	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;
};
