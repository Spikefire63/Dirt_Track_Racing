// Fill out your copyright notice in the Description page of Project Settings.


#include "OffroadFWs.h"

UOffroadFWs::UOffroadFWs() {

	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	bAffectedByEngine = true;

	//wheel behavior
	WheelRadius = 50.0f;
	CorneringStiffness = 700.0f;
	FrictionForceMultiplier = 4.0f;
	MaxSteerAngle = 40.0f;

	//break behavior
	MaxBrakeTorque = 2000.0f;
	MaxHandBrakeTorque = 4000.0f;

	//suspension
	SuspensionMaxRaise = 20.0f;
	SuspensionMaxDrop = 20.0f;
	WheelLoadRatio = 1.0f;
	SpringRate = 100.0f;
	SpringPreload = 100.0f;
	SweepShape = ESweepShape::Shapecast;


}