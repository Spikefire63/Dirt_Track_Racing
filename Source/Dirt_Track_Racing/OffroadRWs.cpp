// This file handles the rear wheels of the vehicle


#include "OffroadRWs.h"

UOffroadRWs::UOffroadRWs() {

	AxleType = EAxleType::Rear;
	bAffectedByBrake = true;
	bAffectedByEngine = true;

	//wheel behavior
	WheelRadius = 50.0f;
	CorneringStiffness = 700.0f;
	FrictionForceMultiplier = 4.0f;

	//break behavior
	MaxBrakeTorque = 2000.0f;
	MaxHandBrakeTorque = 4000.0f;

	//suspension
	//will add if it causes problems
	

}