// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"
#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/WarriorHeroController.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "WarriorGameplayTags.h"


AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
    if (!CachedWarriorHeroCharacter.IsValid())
    {
        CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(CurrentActorInfo->AvatarActor);
    }

	return CachedWarriorHeroCharacter.IsValid() ? CachedWarriorHeroCharacter.Get() : nullptr;
}

AWarriorHeroController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<AWarriorHeroController>(CurrentActorInfo->PlayerController);
	}
	return CachedWarriorHeroController.IsValid() ? CachedWarriorHeroController.Get() : nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

FGameplayEffectSpecHandle UWarriorHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float WeaponBaseDamage, FGameplayTag InCurrentAttackTpyeTag, int32 InUsedComboCount)
{
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetWarriorAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle handle = GetWarriorAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(
		EffectClass,
		GetAbilityLevel(),
		ContextHandle
	);

	handle.Data->SetSetByCallerMagnitude(
		WarriorGameplayTags::Shared_SetByCaller_BaseDamage,
		WeaponBaseDamage 
	);

	if (InCurrentAttackTpyeTag.IsValid())
	{
		handle.Data->SetSetByCallerMagnitude(InCurrentAttackTpyeTag, InUsedComboCount);
	}

	return handle;
}
