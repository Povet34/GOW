// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Itmes/Weapons/WarriorWeaponBase.h"
#include "Components/BoxComponent.h"

#include "WarriorDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorWeaponBase* InWeaponToRegister, bool bResgisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("Weapon with tag %s already registered"), *InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);
	if (bResgisterAsEquippedWeapon)
	{
		CurrnetEquippedWeaponTag = InWeaponTagToRegister;
	}
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if (AWarriorWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}

	return nullptr;
}

AWarriorWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrnetEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}

	return GetCharacterCarriedWeaponByTag(CurrnetEquippedWeaponTag);
}

void UPawnCombatComponent::ToggleWeaponCollision(bool bEnable, EToggleDamageType ToggleDamageType)
{
	if (ToggleDamageType == EToggleDamageType::CurrnetEquippedWeapon)
	{
		AWarriorWeaponBase* WeaponToToggle = GetCharacterCurrentEquippedWeapon();
		check(WeaponToToggle);
		WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(bEnable ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
		Debug::Print(FString::Printf(TEXT("Weapon collision toggled to %s"), bEnable ? TEXT("Enabled") : TEXT("Disabled")), bEnable ? FColor::Green : FColor::Red);

	}
}
