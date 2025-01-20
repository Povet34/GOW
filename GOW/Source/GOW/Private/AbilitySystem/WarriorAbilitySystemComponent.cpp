// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/WarriorAbilitySystemComponent.h"

void UWarriorAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& Spec : GetActivatableAbilities()) 
	{
		if (!Spec.DynamicAbilityTags.HasTagExact(InInputTag))
			continue;

		TryActivateAbility(Spec.Handle, true);
	}
}

void UWarriorAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag InInputTag)
{
}
