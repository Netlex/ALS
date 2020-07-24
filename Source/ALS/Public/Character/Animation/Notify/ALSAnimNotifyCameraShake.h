// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2020 Netlex Studio
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/Netlex/AdvancedLocomotionSystem
// Original Author: Netlex Studio
    


#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Camera/CameraShake.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ALSAnimNotifyCameraShake.generated.h"

/**
 * Generic camera shake animation notify for pawns with controller enabled
 */
UCLASS()
class ALS_API UALSAnimNotifyCameraShake : public UAnimNotify
{
	GENERATED_BODY()

	void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	TSubclassOf<UCameraShake> ShakeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AnimNotify)
	float Scale = 1.0f;
};
