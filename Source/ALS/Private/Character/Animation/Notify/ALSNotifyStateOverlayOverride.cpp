// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2020 Netlex Studio
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/Netlex/ALS
// Original Author: Netlex Studio
    


#include "Character/Animation/Notify/ALSNotifyStateOverlayOverride.h"

#include "Character/Animation/ALSCharacterAnimInstance.h"

void UALSNotifyStateOverlayOverride::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	UALSCharacterAnimInstance* AnimInst = Cast<UALSCharacterAnimInstance>(MeshComp->GetAnimInstance());
	if (AnimInst)
	{
		AnimInst->SetOverlayOverrideState(OverlayOverrideState);
	}
}

void UALSNotifyStateOverlayOverride::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UALSCharacterAnimInstance* AnimInst = Cast<UALSCharacterAnimInstance>(MeshComp->GetAnimInstance());
	if (AnimInst)
	{
		AnimInst->SetOverlayOverrideState(0);
	}
}

FString UALSNotifyStateOverlayOverride::GetNotifyName_Implementation() const
{
	FString Name(TEXT("Overlay Override State: "));
	Name.Append(GetEnumerationToString(EALSOverlayState(OverlayOverrideState)));
	return Name;
}
