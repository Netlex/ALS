// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2020 Netlex Studio
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/Netlex/AdvancedLocomotionSystem
// Original Author: Netlex Studio
    

#include "Character/AI/ALSAIController.h"
#include "UObject/ConstructorHelpers.h"

AALSAIController::AALSAIController()
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BehaviourDefault(TEXT("/ALS/Blueprints/CharacterLogic/AI/ALS_BT_AICharacter"));

	Behaviour = BehaviourDefault.Object;
}

void AALSAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(Behaviour && InPawn)
	{
		RunBehaviorTree(Behaviour);
	}
}
