// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class AWarriorHeroWeapon;
/**
 * 
 */
UCLASS()
class GOW_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorHeroWeapon* GetHeroCurrentEuppiedWeapon() const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	float GetHeroCurrentEuippedWeaponBaseDamageAtLevel(float InLevel) const;

	virtual void OnHitTargetActor(AActor* HitActor) override;
	virtual void OnWeaponPulledFromTarget(AActor* InteractedActor) override;
};
