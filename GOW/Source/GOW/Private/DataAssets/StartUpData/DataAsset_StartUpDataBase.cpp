// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);	
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);	

	if (!StartGameplayEffects.IsEmpty())
	{
		for (const auto& GameplayEffect : StartGameplayEffects)
		{
			if (!GameplayEffect)
			{
				continue;
			}

			UGameplayEffect* EffectCDO = GameplayEffect.GetDefaultObject();
			InASCToGive->ApplyGameplayEffectToSelf(
				EffectCDO, 
				ApplyLevel, 
				InASCToGive->MakeEffectContext()
			);
		}
	}
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UWarriorGameplayAbility>>& Abilities, UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (Abilities.IsEmpty()) 
	{
		return;
	}

	for (const TSubclassOf<UWarriorGameplayAbility>& Ability : Abilities)
	{
		if (!Ability)
		{
			continue;
		}

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}
