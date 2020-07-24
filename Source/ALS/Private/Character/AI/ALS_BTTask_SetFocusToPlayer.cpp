// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2020 Netlex Studio
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/Netlex/AdvancedLocomotionSystem
// Original Author: Netlex Studio
    

#include "Character/AI/ALS_BTTask_SetFocusToPlayer.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AIController.h"

UALS_BTTask_SetFocusToPlayer::UALS_BTTask_SetFocusToPlayer()
{
	NodeName = "Focus On Player";
}

EBTNodeResult::Type UALS_BTTask_SetFocusToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (Pawn)
	{
		OwnerComp.GetAIOwner()->SetFocus(Pawn);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

FString UALS_BTTask_SetFocusToPlayer::GetStaticDescription() const
{
	return "Set Focus to player's pawn";
}