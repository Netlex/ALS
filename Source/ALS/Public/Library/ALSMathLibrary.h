// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2020 Netlex Studio
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/Netlex/ALS
// Original Author: Netlex Studio
    


#pragma once

#include "ALSCharacterEnumLibrary.h"
#include "CoreMinimal.h"
#include "ALSMathLibrary.generated.h"

struct FALSComponentAndTransform;
class UCapsuleComponent;

/**
 * Math library functions for ALS
 */
UCLASS()
class ALS_API UALSMathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static FTransform MantleComponentLocalToWorld(const FALSComponentAndTransform& CompAndTransform);

	static TPair<float, float> FixDiagonalGamepadValues(float Y, float X);

	UFUNCTION(BlueprintCallable)
	static FTransform TransfromSub(const FTransform& T1, const FTransform& T2)
	{
		return FTransform(T1.GetRotation().Rotator() - T2.GetRotation().Rotator(),
		                  T1.GetLocation() - T2.GetLocation(), T1.GetScale3D() - T2.GetScale3D());
	}

	UFUNCTION(BlueprintCallable)
	static FTransform TransfromAdd(const FTransform& T1, const FTransform& T2)
	{
		return FTransform(T1.GetRotation().Rotator() + T2.GetRotation().Rotator(),
		                  T1.GetLocation() + T2.GetLocation(), T1.GetScale3D() + T2.GetScale3D());
	}

	UFUNCTION(BlueprintCallable)
	static FVector GetCapsuleBaseLocation(float ZOffset, UCapsuleComponent* Capsule);

	UFUNCTION(BlueprintCallable)
	static FVector GetCapsuleLocationFromBase(FVector BaseLocation, float ZOffset, UCapsuleComponent* Capsule);

	UFUNCTION(BlueprintCallable)
	static bool CapsuleHasRoomCheck(UCapsuleComponent* Capsule, FVector TargetLocation, float HeightOffset,
	                                float RadiusOffset);

	UFUNCTION(BlueprintCallable)
	static bool AngleInRange(float Angle, float MinAngle, float MaxAngle, float Buffer, bool IncreaseBuffer);

	UFUNCTION(BlueprintCallable)
	static EALSMovementDirection CalculateQuadrant(EALSMovementDirection Current, float FRThreshold, float FLThreshold, float BRThreshold,
	                                        float BLThreshold, float Buffer, float Angle);
};
