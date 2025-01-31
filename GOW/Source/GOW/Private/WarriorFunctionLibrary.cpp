// Fill out your copyright notice in the Description page of Project Settings.


#include "WarriorFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/WarriorAbilitySystemComponent.h"
#include "Interfaces/PawnCombatInterface.h"

UWarriorAbilitySystemComponent* UWarriorFunctionLibrary::NativeGetWarriorASCFromActor(AActor* Actor)
{
	check(Actor);

	return CastChecked<UWarriorAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Actor));
}

void UWarriorFunctionLibrary::AddGameplayTagToActorIfNone(AActor* Actor, FGameplayTag TagToAdd)
{
	UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(Actor);
	if (!ASC)
	{
		return;
	}

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UWarriorFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* Actor, FGameplayTag TagToRemove)
{
	UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(Actor);
	if (!ASC)
	{
		return;
	}

	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UWarriorFunctionLibrary::NetiveDoesActorHaveTag(AActor* Actor, FGameplayTag TagToCheck)
{
	UWarriorAbilitySystemComponent* ASC = NativeGetWarriorASCFromActor(Actor);

	return ASC ? ASC->HasMatchingGameplayTag(TagToCheck) : false;
}

void UWarriorFunctionLibrary::BP_DoesActorHaveTag(AActor* Actor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType)
{
	OutConfirmType = NetiveDoesActorHaveTag(Actor, TagToCheck) ? EWarriorConfirmType::Yes : EWarriorConfirmType::No;
}

UPawnCombatComponent* UWarriorFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* Actor)
{
	check(Actor);

	if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(Actor))
	{
		return PawnCombatInterface->GetCombatComponent();
	}

	return nullptr;
}

UPawnCombatComponent* UWarriorFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* Actor, EWarriorValidType& OutVaildType)
{
	UPawnCombatComponent* CombatComp = NativeGetPawnCombatComponentFromActor(Actor);

	OutVaildType = NativeGetPawnCombatComponentFromActor(Actor) ? EWarriorValidType::Valid : EWarriorValidType::Invalid;
	return CombatComp;
}
