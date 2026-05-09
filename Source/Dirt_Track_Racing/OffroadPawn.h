//h file creating properties for the vehicle.

#pragma once

#include "CoreMinimal.h"
#include "VehiclePawn.h"
#include "OffroadPawn.generated.h"

UCLASS()
class DIRT_TRACK_RACING_API AOffroadPawn : public AVehiclePawn
{
	GENERATED_BODY()

	//Properties for creating the vehicle
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Chassis;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TireFrontRight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TireFrontLeft;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TireRearRight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Meshes, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TireRearLeft;

	//speed boost function
	UFUNCTION(BlueprintCallable)
	void ActivateSpeedBoost();

	UFUNCTION(BlueprintCallable)
	void DeactivateSpeedBoost();

public:
	// Sets default values for this pawn's properties
	AOffroadPawn();

};
