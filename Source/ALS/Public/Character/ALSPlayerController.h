// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2020 Netlex Studio
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/Netlex/AdvancedLocomotionSystem
// Original Author: Netlex Studio


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ALSPlayerController.generated.h"

class AALSBaseCharacter;

/**
 * Player controller class
 */
UCLASS(Blueprintable, BlueprintType)
class ALS_API AALSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void OnRestartPawn(APawn* NewPawn);

private:

	/** Main character reference */
	AALSBaseCharacter* PossessedCharacter = nullptr;
};
