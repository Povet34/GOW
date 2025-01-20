// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/Abilities/WarriorGameplayAbility.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
    return InputTag.IsValid() && AbilityToGrant;
}

void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UWarriorAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FWarriorHeroAbilitySet& Ability : HeroStartUpAbilitySets)
	{
		if (!Ability.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("Invalid ability set in hero start up data"));
			continue;
		}

		FGameplayAbilitySpec Spec(Ability.AbilityToGrant, ApplyLevel);
		Spec.SourceObject = InASCToGive->GetAvatarActor();
		Spec.DynamicAbilityTags.AddTag(Ability.InputTag);

		InASCToGive->GiveAbility(Spec);
	}
}
