// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/WarriorBaseCharacter.h"
#include "WarriorEnemyCharacter.generated.h"

class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class GOW_API AWarriorEnemyCharacter : public AWarriorBaseCharacter
{
	GENERATED_BODY()
public:
	AWarriorEnemyCharacter();

	//~ Begin IPawnCombatInterface Interface
	virtual UPawnCombatComponent* GetCombatComponent() const override;
	//~ End IPawnCombatInterface Interface
protected:

	//~ Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* EnemyCombatComponent;
private:
	void InitEnemyStartUpData();

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }
};
