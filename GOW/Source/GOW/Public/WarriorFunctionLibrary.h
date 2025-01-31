// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "WarriorTypes/WarriorEnumTypes.h"
#include "WarriorFunctionLibrary.generated.h"

class UWarriorAbilitySystemComponent;
class UPawnCombatComponent;


/**
 * 
 */
UCLASS()
class GOW_API UWarriorFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UWarriorAbilitySystemComponent* NativeGetWarriorASCFromActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* Actor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* Actor, FGameplayTag TagToRemove);

	static bool NetiveDoesActorHaveTag(AActor* Actor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* Actor, FGameplayTag TagToCheck, EWarriorConfirmType& OutConfirmType);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* Actor);

	UFUNCTION(BlueprintCallable, Category = "Warrior|FunctionLibrary", meta = (DisplayName = "Get Pawn Combat Component From Actor", ExpandEnumAsExecs = "OutVaildType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* Actor, EWarriorValidType& OutVaildType);
};
