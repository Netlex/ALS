// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2020 Netlex Studio
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/Netlex/ALS
// Original Author: Netlex Studio
    


#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "ALSPlayerCameraManager.generated.h"

class AALSBaseCharacter;

/**
 * Player camera manager class
 */
UCLASS(Blueprintable, BlueprintType)
class ALS_API AALSPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

	AALSPlayerCameraManager();

public:
	UFUNCTION(BlueprintCallable)
	void OnPossess(AALSBaseCharacter* NewCharacter);

	UFUNCTION(BlueprintCallable)
	float GetCameraBehaviorParam(FName CurveName) const;

	/** Implement debug logic in BP */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void DrawDebugTargets(FVector PivotTargetLocation);

protected:
	virtual void UpdateViewTargetInternal(FTViewTarget& OutVT, float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	FVector CalculateAxisIndependentLag(
		FVector CurrentLocation, FVector TargetLocation, FRotator CameraRotation, FVector LagSpeeds, float DeltaTime);

	UFUNCTION(BlueprintCallable)
	bool CustomCameraBehavior(float DeltaTime, FVector& Location, FRotator& Rotation, float& FOV);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AALSBaseCharacter* ControlledCharacter = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* CameraBehavior = nullptr;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FName CustomTag = FName(TEXT("ALS_Character"));

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector RootLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FTransform SmoothedPivotTarget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector PivotLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector TargetCameraLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FRotator TargetCameraRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FRotator DebugViewRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector DebugViewOffset;
};
