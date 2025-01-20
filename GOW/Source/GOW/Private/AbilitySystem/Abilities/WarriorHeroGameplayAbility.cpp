// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"

AHeroCharacter* UWarriorHeroGameplayAbility::GetHeroActorFromActorInfo() const
{
    Cast<AHeroCharacter>(CurrentActorInfo->AvatarActor);
}
