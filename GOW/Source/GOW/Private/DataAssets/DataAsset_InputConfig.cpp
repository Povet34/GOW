// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/DataAsset_InputConfig.h"

UInputAction* UDataAsset_InputConfig::FindNavtiveInputAction(const FGameplayTag& InInputTag)
{
	for (const FWarriorInputActionConfig& Config : NativeInputActions)
	{
		if (Config.InputTag == InInputTag && Config.InputAction)
		{
			return Config.InputAction;
		}
	}
	return nullptr;
}
