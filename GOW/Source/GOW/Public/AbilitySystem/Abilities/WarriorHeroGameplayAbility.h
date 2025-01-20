// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "WarriorHeroGameplayAbility.generated.h"

class AHeroCharacter;
/**
 * 
 */
UCLASS()
class GOW_API UWarriorHeroGameplayAbility : public UWarriorGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	AHeroCharacter* GetHeroActorFromActorInfo() const;

private:
	TWeakObjectPtr<AHeroCharacter> CachedHeroCharacter;
};
